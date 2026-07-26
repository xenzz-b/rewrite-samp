//#include "core/anticheat/ddos"
#include "core/anticheat/cbug"
#include <YSI_Coding\y_hooks>

// Dideklarasikan di core/systems/systems_natives.inc yang di-include SETELAH
// file ini. Tanpa forward, compiler kena warning 208 (forcing reparse).
forward Float:GetPlayerPacketLoss(playerid);

#define MAX_ANTICHEAT_WARNINGS 3

static const Float:modShopLocations[][] =
{
    {10.0,  -1936.0861, 237.4443,   34.3125},
	{10.0,  -2714.6309, 217.3955,   4.2965},
	{10.0,  2386.7686,  1042.1649,  10.8203},
	{10.0,  2644.9480,  -2037.6088, 13.5500},
	{10.0,  1041.2783,  -1027.8124, 32.1016},
	{50.0,  616.0253,   -8.0157,    1000.9219},
	{50.0,  615.2108,   -75.3288,   997.9922},
	{50.0,  612.9303,   -124.1615,  997.9922}
};

IsPlayerNearModShop(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		for(new i; i < sizeof(modShopLocations); i ++)
		{
		    if(IsPlayerInRangeOfPoint(playerid, modShopLocations[i][0], modShopLocations[i][1], modShopLocations[i][2], modShopLocations[i][3]))
		    {
		        return 1;
			}
		}
	}
	
	return 0;
}

AC_RangeCheck(Float:x1, Float:y1, Float:z1, Float:radius, Float:x2, Float:y2, Float:z2)
{
	x1 -= x2;
	y1 -= y2;
	z1 -= z2;

	return ((x1 * x1) + (y1 * y1) + (z1 * z1)) < (radius * radius);
}

Float:AC_GetSpeed(playerid)
{
	new
		Float:vx,
		Float:vy,
		Float:vz;

	if(IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), vx, vy, vz);
	}
	else
	{
	    GetPlayerVelocity(playerid, vx, vy, vz);
	}

	return floatsqroot((vx * vx) + (vy * vy) + (vz * vz));
}

enum e_Anticheat
{
    Float:acPos[3],
    Float:acSpawn[3],
    acImmunity,
    acAirbreakTime,
    acArmorTime,
    acHealthTime,
    Float:acHealth,
    Float:acArmour,
    acHealthWarns,
    acArmorWarns,
    acVehHealthWarns
};
new Anticheat[MAX_PLAYERS][e_Anticheat];

/*
	=====================================================================
	  ANTICHEAT v3 - GRANT BASED DETECTION (by Claps)
	=====================================================================

	MASALAH v2:
	  Deteksi lama membandingkan nilai sekarang dengan "nilai terakhir yang
	  terlihat" (acHealth/acArmour). Cheater tinggal set armor 0 -> 100 lalu
	  turunkan sedikit, atau bermain di bawah threshold +15, dan lolos.
	  Baseline juga ikut ternodai karena selalu di-update tiap detik.

	SOLUSI v3 - GRANT/LEDGER:
	  Server adalah SATU-SATUNYA sumber kebenaran. Setiap kali script resmi
	  memberi health/armour/veh-health, ia WAJIB memanggil AC_GrantHealth()
	  / AC_GrantArmour() / AC_GrantVehHealth(). Nilai itu disimpan sebagai
	  "ledger" (acLedgerHP / acLedgerArmour / vehLedgerHP).

	  Aturannya sederhana dan mutlak:
		 nilai_client  >  ledger + toleransi   =>  CHEAT (pasti)
		 nilai_client  <= ledger               =>  SAH   (turun itu wajar,
													ledger ikut turun)

	  Karena health/armour TIDAK PERNAH bisa naik sendiri di GTA:SA tanpa
	  aksi server, kenaikan apa pun di luar grant = 100% cheat. Tidak ada
	  threshold besar, tidak ada tebak-tebakan.

	KEUNGGULAN:
	  1. Naik 0->100 maupun 0->5 sama-sama kedetect (toleransi cuma 1.5 utk desync).
	  2. Bandage / kevlar / medic / bengkel otomatis aman selama lewat grant.
	  3. Cheater turunkan lagi ke semula (100->0) TIDAK di-kick ulang,
		 karena ledger sudah disinkron & pelanggaran hanya dihitung sekali.
	  4. Ledger hanya turun mengikuti damage, jadi tidak bisa "dinaikkan pelan-pelan".
*/

#define AC_SPAWN_GRACE_TIME     (8)     // detik sejak spawn sebelum deteksi aktif
#define AC_CONNECT_GRACE_TIME   (12)    // detik sejak connect sebelum deteksi aktif
#define AC_PAUSE_THRESHOLD      (3000)  // ms tanpa OnPlayerUpdate = paused/lag

#define AC_HP_TOLERANCE         (1.50)  // toleransi desync health  (HP)
#define AC_ARMOUR_TOLERANCE     (1.50)  // toleransi desync armour  (AP)
#define AC_VEH_TOLERANCE        (20.0)  // toleransi desync vehicle health

#define AC_GRANT_WINDOW         (3)     // detik jendela sah setelah grant

new
	AC_LastUpdate[MAX_PLAYERS],
	AC_SpawnTick[MAX_PLAYERS],
	AC_ConnectTick[MAX_PLAYERS],
	bool:AC_Kicked[MAX_PLAYERS],

	// --- ledger pemain ---
	Float:AC_LedgerHP[MAX_PLAYERS],
	Float:AC_LedgerArmour[MAX_PLAYERS],
	AC_GrantHPTime[MAX_PLAYERS],
	AC_GrantArmourTime[MAX_PLAYERS],
	bool:AC_HPFlagged[MAX_PLAYERS],			// sudah dihukum, tunggu normal lagi
	bool:AC_ArmourFlagged[MAX_PLAYERS],

	// --- ledger kendaraan ---
	Float:AC_LedgerVehHP[MAX_VEHICLES],
	AC_GrantVehTime[MAX_VEHICLES],
	bool:AC_VehFlagged[MAX_VEHICLES];

// ---------------------------------------------------------------------
//  EXEMPT & GUARD
// ---------------------------------------------------------------------

// Staff/immune: jangan pernah auto-kick
AC_IsExempt(playerid)
{
	if(!IsPlayerConnected(playerid) || IsPlayerNPC(playerid))
		return 1;

	if(AccountData[playerid][pAdmin] > 0 || AccountData[playerid][pWitch] || AccountData[playerid][pApprentice])
		return 1;

	if(AccountData[playerid][pAdminHelper] > 0 || AccountData[playerid][pAdminVlounter] > 0)
		return 1;

	if(AccountData[playerid][pAdminDuty])
		return 1;

	return 0;
}

// Player sedang paused / freeze / lag berat -> data tidak bisa dipercaya
AC_IsPlayerDesynced(playerid)
{
	if(AC_LastUpdate[playerid] && (GetTickCount() - AC_LastUpdate[playerid]) > AC_PAUSE_THRESHOLD)
		return 1;

	if(GetPlayerPing(playerid) >= 900)
		return 1;

	if(GetPlayerPacketLoss(playerid) >= 15.0)
		return 1;

	return 0;
}

// Gate utama sebelum menghukum. Return 1 = boleh diproses.
AC_CanPunish(playerid)
{
	if(!IsPlayerConnected(playerid) || IsPlayerNPC(playerid))
		return 0;

	if(AC_Kicked[playerid]) // kick sudah dijadwalkan, jangan spam
		return 0;

	if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
		return 0;

	if(AC_IsExempt(playerid))
		return 0;

	if(gettime() < Anticheat[playerid][acImmunity]) // immunity (teleport admin, event, dll)
		return 0;

	if(AC_ConnectTick[playerid] && (gettime() - AC_ConnectTick[playerid]) < AC_CONNECT_GRACE_TIME)
		return 0;

	if(AC_SpawnTick[playerid] && (gettime() - AC_SpawnTick[playerid]) < AC_SPAWN_GRACE_TIME)
		return 0;

	if(AC_IsPlayerDesynced(playerid))
		return 0;

	return 1;
}

// ---------------------------------------------------------------------
//  NOTIFIKASI STAFF  (tanpa database, sesuai permintaan)
// ---------------------------------------------------------------------

AC_Notify(playerid, const reason[], const detail[], bool:kicked)
{
	if(kicked)
	{
		SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) "RED"DITENDANG "YELLOW"%s {DBD7D2}| %s", GetName(playerid), playerid, reason, detail);
	}
	else
	{
		SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}terdeteksi "YELLOW"%s {DBD7D2}| %s "GRAY"(dikoreksi)", GetName(playerid), playerid, reason, detail);
	}
	printf("[AntiCheat] %s(%d) | %s | %s | %s", GetName(playerid), playerid, reason, detail, (kicked) ? ("KICK") : ("KOREKSI"));
	return 1;
}

// Deteksi tanpa kick (nilai sudah dikoreksi server)
stock AC_Warn(playerid, const reason[], const detail[] = "-")
{
	if(!AC_CanPunish(playerid))
		return 0;

	AC_Notify(playerid, reason, detail, false);
	return 1;
}

/*  Kick terpandu:
    - dicek ulang oleh AC_CanPunish (anti false positive)
    - hanya sekali per sesi (anti double kick / spam timer)
    - selalu memberi tahu staff + console
    Return 1 kalau benar-benar dikick, 0 kalau diabaikan oleh guard. */
AC_Kick(playerid, const reason[], const detail[] = "-")
{
	if(!AC_CanPunish(playerid))
		return 0;

	AC_Kicked[playerid] = true;

	AC_Notify(playerid, reason, detail, true);
	SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda ditendang dari server karena diduga "YELLOW"%s{DBD7D2}.", reason);

	KickEx(playerid);
	return 1;
}

// Kick untuk kondisi pra-spawn (fake connect, weapon hack sebelum login).
AC_KickRaw(playerid, const reason[], const detail[] = "-")
{
	if(!IsPlayerConnected(playerid) || AC_Kicked[playerid])
		return 0;

	if(AC_IsExempt(playerid))
		return 0;

	if(AC_ConnectTick[playerid] && (gettime() - AC_ConnectTick[playerid]) < 5)
		return 0;

	AC_Kicked[playerid] = true;

	AC_Notify(playerid, reason, detail, true);
	SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda ditendang dari server karena diduga "YELLOW"%s{DBD7D2}.", reason);

	KickEx(playerid);
	return 1;
}

// ---------------------------------------------------------------------
//  GRANT API  -  WAJIB dipanggil setiap script resmi menaikkan nilai
// ---------------------------------------------------------------------

/* Catat bahwa server SAH memberi health sebesar `value` ke player.
   Dipanggil otomatis oleh SetPlayerHealthEx(). Untuk sumber lain
   (bandage, medic, makan, event) panggil manual sebelum SetPlayerHealth(). */
AC_GrantHealth(playerid, Float:value)
{
	if(!(0 <= playerid < MAX_PLAYERS))
		return 0;

	if(value > AC_LedgerHP[playerid])
		AC_LedgerHP[playerid] = value;

	AC_GrantHPTime[playerid] = gettime() + AC_GRANT_WINDOW;
	AC_HPFlagged[playerid]   = false;

	Anticheat[playerid][acHealth]     = value;
	Anticheat[playerid][acHealthTime] = AC_GrantHPTime[playerid];
	return 1;
}

// Catat pemberian armour yang SAH (kevlar, event, dll)
AC_GrantArmour(playerid, Float:value)
{
	if(!(0 <= playerid < MAX_PLAYERS))
		return 0;

	if(value > AC_LedgerArmour[playerid])
		AC_LedgerArmour[playerid] = value;

	AC_GrantArmourTime[playerid] = gettime() + AC_GRANT_WINDOW;
	AC_ArmourFlagged[playerid]   = false;

	Anticheat[playerid][acArmour]    = value;
	Anticheat[playerid][acArmorTime] = AC_GrantArmourTime[playerid];
	return 1;
}

// Catat perbaikan kendaraan yang SAH (bengkel, admin, respawn)
stock AC_GrantVehHealth(vehicleid, Float:value)
{
	if(!(0 <= vehicleid < MAX_VEHICLES))
		return 0;

	if(value > AC_LedgerVehHP[vehicleid])
		AC_LedgerVehHP[vehicleid] = value;

	AC_GrantVehTime[vehicleid] = gettime() + AC_GRANT_WINDOW;
	AC_VehFlagged[vehicleid]   = false;

	VehicleHealthSecurityData[vehicleid] = value;
	return 1;
}

// Reset penuh (spawn, respawn, disconnect)
AC_ResetHealthLedger(playerid, Float:hp = 0.0, Float:armour = 0.0)
{
	AC_LedgerHP[playerid]        = hp;
	AC_LedgerArmour[playerid]    = armour;
	AC_GrantHPTime[playerid]     = gettime() + AC_GRANT_WINDOW;
	AC_GrantArmourTime[playerid] = gettime() + AC_GRANT_WINDOW;
	AC_HPFlagged[playerid]       = false;
	AC_ArmourFlagged[playerid]   = false;

	Anticheat[playerid][acHealth] = hp;
	Anticheat[playerid][acArmour] = armour;
	return 1;
}

stock AC_ResetVehLedger(vehicleid, Float:hp)
{
	if(!(0 <= vehicleid < MAX_VEHICLES))
		return 0;

	AC_LedgerVehHP[vehicleid]  = hp;
	AC_GrantVehTime[vehicleid] = gettime() + AC_GRANT_WINDOW;
	AC_VehFlagged[vehicleid]   = false;
	VehicleHealthSecurityData[vehicleid] = hp;
	return 1;
}

// Apakah ada aktivitas heal/repair sah yang sedang berjalan?
// (bandage, medic lokal, makan/minum, knockdown revive)
AC_HasLegitHealSource(playerid)
{
	if(gettime() <= AC_GrantHPTime[playerid])
		return 1;

	if(pMedisLokalTimer[playerid] || pUsingPerbanTimer[playerid] || pEatingBarTimer[playerid])
		return 1;

	if(AccountData[playerid][pDuringUseLocalMedic])
		return 1;

	if(AccountData[playerid][pKnockdown] || AccountData[playerid][pComma])
		return 1;

	return 0;
}

stock AC_HasLegitRepairSource(playerid)
{
	if(playerid == INVALID_PLAYER_ID)
		return 0;

	if(pMechRepairEngineTimer[playerid] || pMechRepairBodyTimer[playerid] || pMechRepairTiresTimer[playerid])
		return 1;

	if(IsPlayerNearModShop(playerid))
		return 1;

	return 0;
}

// ---------------------------------------------------------------------
//  HOOKS
// ---------------------------------------------------------------------

hook OnPlayerConnect(playerid)
{
	AC_LastUpdate[playerid]  = GetTickCount();
	AC_ConnectTick[playerid] = gettime();
	AC_SpawnTick[playerid]   = 0;
	AC_Kicked[playerid]      = false;

	AC_ResetHealthLedger(playerid, 0.0, 0.0);

	Anticheat[playerid][acHealthWarns]    = 0;
	Anticheat[playerid][acArmorWarns]     = 0;
	Anticheat[playerid][acVehHealthWarns] = 0;
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	AC_LastUpdate[playerid]  = 0;
	AC_ConnectTick[playerid] = 0;
	AC_SpawnTick[playerid]   = 0;
	AC_Kicked[playerid]      = false;
	AC_ResetHealthLedger(playerid, 0.0, 0.0);
	return 1;
}

hook OnPlayerSpawn(playerid)
{
	new Float:hp, Float:ap;
	GetPlayerHealth(playerid, hp);
	GetPlayerArmour(playerid, ap);

	AC_SpawnTick[playerid]  = gettime();
	AC_LastUpdate[playerid] = GetTickCount();

	// baseline awal = kondisi resmi saat spawn
	AC_ResetHealthLedger(playerid, hp, ap);

	if(Anticheat[playerid][acImmunity] < gettime() + AC_SPAWN_GRACE_TIME)
		Anticheat[playerid][acImmunity] = gettime() + AC_SPAWN_GRACE_TIME;
	return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
	AC_ResetHealthLedger(playerid, 0.0, 0.0);
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	AC_LastUpdate[playerid] = GetTickCount();
	return 1;
}

hook OnVehicleSpawn(vehicleid)
{
	AC_ResetVehLedger(vehicleid, VehicleCore[vehicleid][vMaxHealth]);
	return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
	AC_ResetVehLedger(vehicleid, 0.0);
	return 1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	// sinkron ledger saat masuk, hindari false positive dari data basi
	new Float:vhp;
	if(IsValidVehicle(vehicleid) && GetVehicleHealth(vehicleid, vhp))
		AC_ResetVehLedger(vehicleid, vhp);
	return 1;
}

OnPlayerTeleport(playerid, Float:distance)
{
    if(AC_CanPunish(playerid))
    {
        if(!IsPlayerInRangeOfPoint(playerid, 4.0, AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2]))
        {
            AccountData[playerid][pACWarns]++;

            if(AccountData[playerid][pACWarns] >= MAX_ANTICHEAT_WARNINGS)
            {
                new acdetail[64];
                format(acdetail, sizeof(acdetail), "distance %.1f m (warn %d/%d)", distance, AccountData[playerid][pACWarns], MAX_ANTICHEAT_WARNINGS);
                if(!AC_Kick(playerid, "Teleport Hack", acdetail))
                    AccountData[playerid][pACWarns] = 0; // guard menolak -> reset warn
                return 1;
            }

            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
            {
                new vsID = GetVehicleModel(GetPlayerVehicleID(playerid));
                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Teleport Hack. "YELLOW"[D: %.1f m] [%s]", GetName(playerid), playerid, distance, GetVehicleModelName(vsID));
            }
            else
            {
                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Teleport Hack. "YELLOW"[D: %.1f m] [F]", GetName(playerid), playerid, distance);
            }
        }
    }
	return 1;
}

OnPlayerAirbreak(playerid)
{
	if(AC_CanPunish(playerid))
    {
		AccountData[playerid][pACWarns]++;

		if(AccountData[playerid][pACWarns] >= MAX_ANTICHEAT_WARNINGS)
		{
			new acdetail[64];
			format(acdetail, sizeof(acdetail), "warn %d/%d", AccountData[playerid][pACWarns], MAX_ANTICHEAT_WARNINGS);
			if(!AC_Kick(playerid, "Airbreak", acdetail))
				AccountData[playerid][pACWarns] = 0;
			return 1;
		}

        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Airbreak.", GetName(playerid), playerid);
	}
	return 1;
}

ptask CheckingACTeleport[1000](playerid) 
{
    if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && GetPlayerState(playerid) != PLAYER_STATE_NONE)
	{
        if(AccountData[playerid][IsLoggedIn])
        {
            if(gettime() > Anticheat[playerid][acImmunity])
            {
                if(!IsPlayerInRangeOfPoint(playerid, 200.0, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]) && !IsPlayerInRangeOfPoint(playerid, 5.0, Anticheat[playerid][acSpawn][0], Anticheat[playerid][acSpawn][1], Anticheat[playerid][acSpawn][2]))
                {
                    new
                        Float:x,
                        Float:y,
                        Float:z;

                    GetPlayerPos(playerid, x, y, z);

                    if(!AC_RangeCheck(Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2], 3.0, Anticheat[playerid][acSpawn][0], Anticheat[playerid][acSpawn][1], Anticheat[playerid][acSpawn][2]) && x != 0.0 && y != 0.0 && z != 0.0 && GetPlayerState(playerid) != PLAYER_STATE_PASSENGER && !IsPlayerNearModShop(playerid))
                    {
                        OnPlayerTeleport(playerid, GetPlayerDistanceFromPoint(playerid, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]));
                    }
                }
            }
            else if(gettime() > Anticheat[playerid][acAirbreakTime] && !IsPlayerInRangeOfPoint(playerid, 10.0, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]))
            {
                if((GetPlayerState(playerid) == PLAYER_STATE_ONFOOT || GetPlayerState(playerid) == PLAYER_STATE_DRIVER) && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID && GetPlayerSurfingObjectID(playerid) == INVALID_OBJECT_ID)
                {
                    // Player is 10.0 meters away from their position. Let's check their velocity!

                    new
                        Float:px,
                        Float:py,
                        Float:pz;

                    GetPlayerPos(playerid, px, py, pz);

                    px = floatabs(Anticheat[playerid][acPos][0] - px);
                    py = floatabs(Anticheat[playerid][acPos][1] - py);
                    pz = floatabs(Anticheat[playerid][acPos][2] - pz);

                    // Player seems to have moved a great distance. Let's do more checking.
                    if(((0.5 <= px < 13.9) && (0.5 <= py <= 13.9)) || (4.2 <= pz <= 19.2))
                    {
                        new
                            Float:speed = AC_GetSpeed(playerid);

                        if((0.082 <= speed <= 0.215 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) || (0.0009 <= speed <= 0.0013 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER))
                        {
                            // When airbreaking in the air, a player's velocity levels tend to stay at a regular speed, as they were moving onfoot.
                            OnPlayerAirbreak(playerid);
                            Anticheat[playerid][acAirbreakTime] = gettime() + 1;
                        }
                    }
                }
            }
            GetPlayerPos(playerid, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]);
        }
    }
    return 1;
}
// =====================================================================
//  AUTO-GRANT WRAPPER  (by Claps)
// =====================================================================
//  Di gamemode ini ada puluhan pemanggilan SetPlayerHealth() /
//  SetPlayerArmour() / SetVehicleHealth() langsung (bandage, makan,
//  event, faction, medic, dsb). Kalau tidak dicatat ke ledger, semuanya
//  akan dianggap cheat oleh detektor v3.
//
//  Daripada mengedit ~54 tempat satu per satu (rawan kelewat), semua
//  panggilan itu dialihkan otomatis ke wrapper di bawah lewat #define.
//  Logikanya: apa pun yang di-set OLEH SCRIPT SERVER adalah sah.
//  Cheat client tidak melewati jalur ini, jadi tetap tertangkap.
//
//  Definisi fungsi ada SEBELUM #define, jadi isinya tetap memanggil
//  native asli (tidak rekursif).
// =====================================================================

// Versi mentah untuk dipakai anticheat sendiri saat mengoreksi nilai
// (koreksi TIDAK boleh dicatat sebagai grant).
stock AC_RawSetHealth(playerid, Float:value)  return SetPlayerHealth(playerid, value);
stock AC_RawSetArmour(playerid, Float:value)  return SetPlayerArmour(playerid, value);
stock AC_RawSetVehHP(vehicleid, Float:value)  return SetVehicleHealth(vehicleid, value);

AC_HookSetPlayerHealth(playerid, Float:value)
{
	AC_GrantHealth(playerid, value);
	return SetPlayerHealth(playerid, value);
}

AC_HookSetPlayerArmour(playerid, Float:value)
{
	AC_GrantArmour(playerid, value);
	return SetPlayerArmour(playerid, value);
}

#define SetPlayerHealth  AC_HookSetPlayerHealth
#define SetPlayerArmour  AC_HookSetPlayerArmour

/*  CATATAN: SetVehicleHealth TIDAK di-#define.
    Ada include library yang sudah memakai nama itu sebagai macro, jadi
    menimpanya memicu warning 201 sekaligus berisiko mematikan fungsi
    library tersebut.

    Untungnya memang tidak perlu: satu-satunya jalur resmi yang menaikkan
    health kendaraan adalah SetValidVehicleHealth() di
    core/vehicles/vehicles_functions.inc, dan di sana AC_GrantVehHealth()
    sudah dipanggil eksplisit. Jadi cakupan anticheat tetap penuh.        */
