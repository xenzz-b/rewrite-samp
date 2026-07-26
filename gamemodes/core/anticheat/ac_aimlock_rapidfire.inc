#include <YSI_Coding\y_hooks>

// ---------------------------------------------------------------------------
//  AC_AIMLOCK_RAPIDFIRE — Deteksi aimlock + rapid fire + fake kill
//  Adaptasi dari ac-hytam-legam (XenoX352), disesuaikan dengan framework
//  anticheat gamemode Vertex (AC_CanPunish, AC_Kick, AC_Warn, etc.)
//
//  Aimlock detection:
//    - Fast target switching: hit target berbeda dalam <150ms
//    - Distance snap: hit target dari >150m saat fast switch
//    Facing angle check DIHAPUS karena unreliable (GTA:SA coordinate
//    system quirks, network desync pada facing angle data).
//
//  v2 fix: first-hit false positive (acAimLockLastHitTick=0 → always <150ms),
//  rapid fire violations reset on weapon switch, fake kill uses reason param,
//  fake kill violations decay on spawn, unused acAimLockHits removed.
// ---------------------------------------------------------------------------

#define AC_AIMLOCK_MAX_DISTANCE   150.0   // max snap distance untuk aimbot
#define AC_AIMLOCK_HIT_INTERVAL   150     // ms: switching target dalam interval ini = suspicious
#define AC_FAKEKILL_MAX_DISTANCE   200.0  // max distance kill tanpa sniper

// Senjata sniper yang sah dari jarak jauh
static const AC_SniperWeapons[] = { 33, 34, 35, 36 };

static stock bool:IsSniperWeapon(weaponid)
{
    for(new i; i < sizeof(AC_SniperWeapons); i++)
        if(weaponid == AC_SniperWeapons[i])
            return true;
    return false;
}

// Rate of fire per senjata (ms minimum antara 2 shot)
static stock GetWeaponFireInterval(weaponid)
{
    switch(weaponid)
    {
        case 22, 23, 24:  return 200;   // pistol
        case 25, 27:      return 1000;   // shotgun
        case 28, 29, 32:  return 90;     // SMG
        case 30, 31:      return 110;    // rifle
        case 33, 34:      return 1000;   // sniper
        case 35:           return 1200;   // rocket launcher
        case 36:           return 800;    // heat seeker
        default:           return 300;
    }
}

// ---------------------------------------------------------------------------
//  DATA — acAimLockHits removed (never used, waste memory)
// ---------------------------------------------------------------------------

enum e_ACAimlock
{
    acAimLockLastHitID,         // ID target terakhir
    acAimLockLastHitTick,       // tick hit terakhir
    acRapidFireLastWeapon,      // senjata shot terakhir
    acRapidFireLastTick,        // tick shot terakhir (precise)
    acRapidFireViolations,      // jumlah violation rapid fire
    acFakeKillViolations        // jumlah violation fake kill
};

new AC_AimData[MAX_PLAYERS][e_ACAimlock];

// ---------------------------------------------------------------------------
//  HOOKS
// ---------------------------------------------------------------------------

hook OnPlayerConnect(playerid)
{
    AC_AimData[playerid][acAimLockLastHitID]       = INVALID_PLAYER_ID;
    AC_AimData[playerid][acAimLockLastHitTick]     = 0;
    AC_AimData[playerid][acRapidFireLastWeapon]    = 0;
    AC_AimData[playerid][acRapidFireLastTick]      = 0;
    AC_AimData[playerid][acRapidFireViolations]    = 0;
    AC_AimData[playerid][acFakeKillViolations]     = 0;
    return 1;
}

// Reset fake kill violations saat spawn — agar violation tidak accumulate forever
hook OnPlayerSpawn(playerid)
{
    AC_AimData[playerid][acFakeKillViolations]     = 0;
    // Reset rapid fire state saat spawn (fresh session)
    AC_AimData[playerid][acRapidFireViolations]    = 0;
    AC_AimData[playerid][acRapidFireLastWeapon]    = 0;
    AC_AimData[playerid][acRapidFireLastTick]      = 0;
    // Reset aimlock state saat spawn
    AC_AimData[playerid][acAimLockLastHitID]       = INVALID_PLAYER_ID;
    AC_AimData[playerid][acAimLockLastHitTick]     = 0;
    return 1;
}

hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    if(!AC_CanPunish(playerid))
        return 1;

    new tick = GetTickCount();

    // --- RAPID FIRE DETECTION ---
    // Cek: shot terlalu cepat untuk senjata yang dipakai
    if(weaponid == AC_AimData[playerid][acRapidFireLastWeapon] && 
       AC_AimData[playerid][acRapidFireLastTick] > 0)
    {
        new interval = tick - AC_AimData[playerid][acRapidFireLastTick];
        new expectedInterval = GetWeaponFireInterval(weaponid);

        // Beri toleransi 80ms untuk desync network
        if(interval < expectedInterval - 80 && interval > 0)
        {
            AC_AimData[playerid][acRapidFireViolations]++;
            
            if(AC_AimData[playerid][acRapidFireViolations] >= 3)
            {
                new acdetail[96];
                format(acdetail, sizeof(acdetail), "%s (%dms < expected %dms, violations: %d)", 
                    ReturnWeaponName(weaponid), interval, expectedInterval, AC_AimData[playerid][acRapidFireViolations]);
                AC_Kick(playerid, "Rapid Fire", acdetail);
                return 0;
            }
        }
        else
        {
            // Reset violations jika shot normal
            AC_AimData[playerid][acRapidFireViolations] = 0;
        }
    }
    else if(weaponid != AC_AimData[playerid][acRapidFireLastWeapon])
    {
        // FIX: Reset violations saat weapon berubah — violations dari
        // weapon sebelumnya tidak boleh carry over ke weapon baru
        AC_AimData[playerid][acRapidFireViolations] = 0;
    }

    AC_AimData[playerid][acRapidFireLastWeapon] = weaponid;
    AC_AimData[playerid][acRapidFireLastTick]    = tick;

    // --- AIMLOCK DETECTION ---
    // Hanya cek jika hit player
    if(hittype == BULLET_HIT_TYPE_PLAYER && hitid != INVALID_PLAYER_ID && IsPlayerConnected(hitid))
    {
        // FIX: Cek bahwa ada previous hit record (acAimLockLastHitTick > 0).
        // Tanpa cek ini, tick - 0 selalu < 150 → first hit selalu false positive.
        if(AC_AimData[playerid][acAimLockLastHitTick] > 0 &&
           hitid != AC_AimData[playerid][acAimLockLastHitID] && 
           tick - AC_AimData[playerid][acAimLockLastHitTick] < AC_AIMLOCK_HIT_INTERVAL)
        {
            new Float:px, Float:py, Float:pz;
            GetPlayerPos(playerid, px, py, pz);
            new Float:tx, Float:ty, Float:tz;
            GetPlayerPos(hitid, tx, ty, tz);

            // Hitung actual 3D distance
            new Float:dx = tx - px, Float:dy = ty - py, Float:dz = tz - pz;
            new Float:dist3d = floatsqroot(dx * dx + dy * dy + dz * dz);

            // Distance snap: hit target jauh (>150m) saat fast switch = aimbot
            if(dist3d > AC_AIMLOCK_MAX_DISTANCE)
            {
                AccountData[playerid][pACWarns]++;
                if(AccountData[playerid][pACWarns] >= MAX_ANTICHEAT_WARNINGS)
                {
                    new acdetail[96];
                    format(acdetail, sizeof(acdetail), "distance snap %.1fm > %.1fm (warn %d/%d)",
                        dist3d, AC_AIMLOCK_MAX_DISTANCE,
                        AccountData[playerid][pACWarns], MAX_ANTICHEAT_WARNINGS);
                    AC_Kick(playerid, "Aimlock", acdetail);
                    return 0;
                }

                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Aimlock. "YELLOW"[Distance Snap: %.1fm]", GetName(playerid), playerid, dist3d);
            }
            else
            {
                // Fast switch pada jarak dekat/sedang — masih suspicious
                // tapi karena jarak wajar, hanya log tanpa menambah pACWarns
                // (close combat switching bisa wajar untuk player skill tinggi)
                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}fast target switch detected. "YELLOW"[%.1fm, %dms]", GetName(playerid), playerid, dist3d, tick - AC_AimData[playerid][acAimLockLastHitTick]);
            }
        }

        AC_AimData[playerid][acAimLockLastHitID]   = hitid;
        AC_AimData[playerid][acAimLockLastHitTick]  = tick;
    }

    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(killerid == INVALID_PLAYER_ID || !AC_CanPunish(killerid))
        return 1;

    // --- FAKE KILL DETECTION ---
    // Kill dari jarak impossible (tanpa sniper)
    new Float:px, Float:py, Float:pz, Float:kx, Float:ky, Float:kz;
    GetPlayerPos(playerid, px, py, pz);
    GetPlayerPos(killerid, kx, ky, kz);

    new Float:dist = floatsqroot((px - kx) * (px - kx) + (py - ky) * (py - ky) + (pz - kz) * (pz - kz));

    // FIX: Gunakan reason (weapon dari kill notification) bukan GetPlayerWeapon
    // GetPlayerWeapon = weapon yang dipegang NOW, bisa sudah berbeda saat callback
    // reason = weapon ID yang dipakai untuk kill, lebih akurat
    // Filter: reason > 46 = special death type (255=drown, etc), bukan weapon ID
    // Weapon ID 0 (fist) DAN 1-9 (melee) dari >200m juga impossible → harus terdeteksi
    new wep = reason;
    if(wep > 46)
        return 1; // special death type (drown, fall, etc) — skip fake kill check

    // Sniper bisa kill dari jauh, senjata lain tidak
    if(dist > AC_FAKEKILL_MAX_DISTANCE && !IsSniperWeapon(wep))
    {
        AC_AimData[killerid][acFakeKillViolations]++;
        
        if(AC_AimData[killerid][acFakeKillViolations] >= 2)
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "kill dari %.1fm dengan %s (violations: %d)",
                dist, ReturnWeaponName(wep), AC_AimData[killerid][acFakeKillViolations]);
            AC_Kick(killerid, "Fake Kill", acdetail);
            return 1;
        }

        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Fake Kill. "YELLOW"[%.1fm / %s]", GetName(killerid), killerid, dist, ReturnWeaponName(wep));
    }

    return 1;
}
