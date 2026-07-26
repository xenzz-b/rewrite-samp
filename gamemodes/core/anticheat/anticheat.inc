//#include "core/anticheat/ddos"
#include "core/anticheat/cbug"
#include <YSI_Coding\y_hooks>

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
	Anticheat v2 - Anti False Positive Guard & Kick Logging (by Claps)
	----------------------------------------------------------------
	Semua deteksi yang sebelumnya melakukan "direct kick" sekarang wajib
	melewati AC_CanPunish() dan menendang lewat AC_Kick() supaya:
	  1. Admin / witch / helper / apprentice tidak pernah kena kick otomatis.
	  2. Player yang baru connect / baru spawn / baru teleport (immunity)
	     tidak kena kick karena desync saat streaming.
	  3. Player yang lag berat (paused / packetloss / ping spike) tidak
	     kena kick karena data update basi.
	  4. Setiap kick tercatat (staff chat + console + tabel log_anticheat).
*/

#define AC_SPAWN_GRACE_TIME     (10)    // detik sejak spawn sebelum deteksi aktif
#define AC_CONNECT_GRACE_TIME   (15)    // detik sejak connect sebelum deteksi aktif
#define AC_PAUSE_THRESHOLD      (2500)  // ms tanpa OnPlayerUpdate = dianggap paused/lag

new
	AC_LastUpdate[MAX_PLAYERS],
	AC_SpawnTick[MAX_PLAYERS],
	AC_ConnectTick[MAX_PLAYERS],
	bool:AC_Kicked[MAX_PLAYERS];

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

	if(gettime() < Anticheat[playerid][acImmunity]) // immunity (teleport admin, spawn, event, dll)
		return 0;

	if(AC_ConnectTick[playerid] && (gettime() - AC_ConnectTick[playerid]) < AC_CONNECT_GRACE_TIME)
		return 0;

	if(AC_SpawnTick[playerid] && (gettime() - AC_SpawnTick[playerid]) < AC_SPAWN_GRACE_TIME)
		return 0;

	if(AC_IsPlayerDesynced(playerid))
		return 0;

	return 1;
}

AC_LogDetect(playerid, const reason[], const detail[], bool:kicked)
{
	static acqry[512];
	mysql_format(g_SQL, acqry, sizeof(acqry), "INSERT INTO `log_anticheat` SET `Nama`='%e', `UCP`='%e', `Reason`='%e', `Detail`='%e', `Action`='%e', `Ping`=%d, `Tanggal`=CURRENT_TIMESTAMP()",
		GetName(playerid), AccountData[playerid][pUCP], reason, detail, (kicked) ? ("KICK") : ("WARN"), GetPlayerPing(playerid));
	mysql_pquery(g_SQL, acqry);

	printf("[AntiCheat] %s(%d) %s | %s | %s", GetName(playerid), playerid, reason, detail, (kicked) ? ("KICK") : ("WARN"));
	return 1;
}

// Warning saja (tidak kick), tetap tercatat
AC_Warn(playerid, const reason[], const detail[] = "-")
{
	if(!AC_CanPunish(playerid))
		return 0;

	SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}terdeteksi "YELLOW"%s {DBD7D2}(%s)", GetName(playerid), playerid, reason, detail);
	AC_LogDetect(playerid, reason, detail, false);
	return 1;
}

/*  Kick terpandu:
    - dicek ulang oleh AC_CanPunish (anti false positive)
    - hanya sekali per sesi (anti double kick / spam timer)
    - selalu memberi tahu staff + log DB + console
    Return 1 kalau benar-benar dikick, 0 kalau diabaikan (false positive guard). */
AC_Kick(playerid, const reason[], const detail[] = "-")
{
	if(!AC_CanPunish(playerid))
		return 0;

	AC_Kicked[playerid] = true;

	SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}ditendang dari server karena "YELLOW"%s {DBD7D2}(%s)", GetName(playerid), playerid, reason, detail);
	SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda ditendang dari server karena diduga "YELLOW"%s{DBD7D2}.", reason);
	AC_LogDetect(playerid, reason, detail, true);

	KickEx(playerid);
	return 1;
}

// Kick untuk kondisi pra-spawn (fake connect, weapon hack sebelum login).
// Guard-nya lebih longgar: tidak butuh spawn/login, tapi tetap hormati staff & grace connect.
AC_KickRaw(playerid, const reason[], const detail[] = "-")
{
	if(!IsPlayerConnected(playerid) || AC_Kicked[playerid])
		return 0;

	if(AC_IsExempt(playerid))
		return 0;

	if(AC_ConnectTick[playerid] && (gettime() - AC_ConnectTick[playerid]) < 5)
		return 0;

	AC_Kicked[playerid] = true;

	SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}ditendang dari server karena "YELLOW"%s {DBD7D2}(%s)", GetName(playerid), playerid, reason, detail);
	SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda ditendang dari server karena diduga "YELLOW"%s{DBD7D2}.", reason);
	AC_LogDetect(playerid, reason, detail, true);

	KickEx(playerid);
	return 1;
}

hook OnPlayerConnect(playerid)
{
	AC_LastUpdate[playerid]  = GetTickCount();
	AC_ConnectTick[playerid] = gettime();
	AC_SpawnTick[playerid]   = 0;
	AC_Kicked[playerid]      = false;

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
	return 1;
}

hook OnPlayerSpawn(playerid)
{
	AC_SpawnTick[playerid] = gettime();
	AC_LastUpdate[playerid] = GetTickCount();

	// beri immunity singkat supaya streaming/teleport spawn tidak terdeteksi
	if(Anticheat[playerid][acImmunity] < gettime() + AC_SPAWN_GRACE_TIME)
		Anticheat[playerid][acImmunity] = gettime() + AC_SPAWN_GRACE_TIME;
	return 1;
}

hook OnPlayerUpdate(playerid)
{
	AC_LastUpdate[playerid] = GetTickCount();
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