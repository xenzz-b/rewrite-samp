#include <YSI_Coding\y_hooks>

// Rapid Fire: interval <60% expected = violation, 3 = kick. Proporsional.
// Aimlock: fast switch <150ms + jarak >150m = warning, 3 = kick.
// Fake Kill: kill >200m tanpa sniper = violation, 2 = kick.

#define AC_AIMLOCK_MAX_DISTANCE   150.0
#define AC_AIMLOCK_HIT_INTERVAL   150
#define AC_FAKEKILL_MAX_DISTANCE   200.0

static const AC_SniperWeapons[] = { 33, 34, 35, 36 };

static stock bool:IsSniperWeapon(weaponid)
{
    for(new i; i < sizeof(AC_SniperWeapons); i++)
        if(weaponid == AC_SniperWeapons[i])
            return true;
    return false;
}

static stock GetWeaponFireInterval(weaponid)
{
    switch(weaponid)
    {
        case 22, 23, 24:  return 200;
        case 25, 27:      return 1000;
        case 28, 29, 32:  return 90;
        case 30, 31:      return 110;
        case 33, 34:      return 1000;
        case 35:           return 1200;
        case 36:           return 800;
        default:           return 300;
    }
    return 300;
}

enum e_ACAimlock
{
    acAimLockLastHitID,
    acAimLockLastHitTick,
    acRapidFireLastWeapon,
    acRapidFireLastTick,
    acRapidFireViolations,
    acFakeKillViolations
};

new AC_AimData[MAX_PLAYERS][e_ACAimlock];

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

hook OnPlayerSpawn(playerid)
{
    AC_AimData[playerid][acFakeKillViolations]     = 0;
    AC_AimData[playerid][acRapidFireViolations]    = 0;
    AC_AimData[playerid][acRapidFireLastWeapon]    = 0;
    AC_AimData[playerid][acRapidFireLastTick]      = 0;
    AC_AimData[playerid][acAimLockLastHitID]       = INVALID_PLAYER_ID;
    AC_AimData[playerid][acAimLockLastHitTick]     = 0;
    return 1;
}

hook OnPlayerWeaponShot(playerid, weaponid, hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
    if(!AC_CanPunish(playerid))
        return 1;

    new tick = GetTickCount();

    // Rapid fire: interval <60% expected = violation
    if(weaponid == AC_AimData[playerid][acRapidFireLastWeapon] && 
       AC_AimData[playerid][acRapidFireLastTick] > 0)
    {
        new interval = tick - AC_AimData[playerid][acRapidFireLastTick];
        new expectedInterval = GetWeaponFireInterval(weaponid);

        if(interval < (expectedInterval * 6) / 10 && interval > 0)
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
            AC_AimData[playerid][acRapidFireViolations] = 0;
        }
    }
    else if(weaponid != AC_AimData[playerid][acRapidFireLastWeapon])
    {
        AC_AimData[playerid][acRapidFireViolations] = 0;
    }

    AC_AimData[playerid][acRapidFireLastWeapon] = weaponid;
    AC_AimData[playerid][acRapidFireLastTick]    = tick;

    // Aimlock: fast target switch <150ms + distance check
    if(hittype == BULLET_HIT_TYPE_PLAYER && hitid != INVALID_PLAYER_ID && IsPlayerConnected(hitid))
    {
        if(AC_AimData[playerid][acAimLockLastHitTick] > 0 &&
           hitid != AC_AimData[playerid][acAimLockLastHitID] && 
           tick - AC_AimData[playerid][acAimLockLastHitTick] < AC_AIMLOCK_HIT_INTERVAL)
        {
            new Float:px, Float:py, Float:pz;
            GetPlayerPos(playerid, px, py, pz);
            new Float:tx, Float:ty, Float:tz;
            GetPlayerPos(hitid, tx, ty, tz);

            new Float:dx = tx - px, Float:dy = ty - py, Float:dz = tz - pz;
            new Float:dist3d = floatsqroot(dx * dx + dy * dy + dz * dz);

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

    new Float:px, Float:py, Float:pz, Float:kx, Float:ky, Float:kz;
    GetPlayerPos(playerid, px, py, pz);
    GetPlayerPos(killerid, kx, ky, kz);

    new Float:dist = floatsqroot((px - kx) * (px - kx) + (py - ky) * (py - ky) + (pz - kz) * (pz - kz));

    new wep = reason;
    if(wep > 46)
        return 1;

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


// Magic Bullet detection via OnPlayerGiveDamage

static stock AC_GetWeaponMaxRange(weaponid)
{
    switch(weaponid)
    {
        case 22, 23:     return 35;
        case 24:         return 35;
        case 25:         return 40;
        case 26, 27:     return 50;
        case 28, 29:     return 45;
        case 30, 31:     return 70;
        case 32:         return 45;
        case 33:         return 50;
        case 34:         return 125;
        case 35:         return 160;
        case 36:         return 120;
        case 41:         return 40;
        default:         return 30;
    }
    return 30;
}

hook OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart)
{
    if(!AC_CanPunish(playerid))
        return 1;

    if(AccountData[playerid][pTaser] || AccountData[playerid][pUseBeanbag] || AccountData[playerid][pTackleEnable])
        return 1;

    if(weaponid < 22 || weaponid > 46)
        return 1;

    new Float:px, Float:py, Float:pz, Float:tx, Float:ty, Float:tz;
    GetPlayerPos(playerid, px, py, pz);
    GetPlayerPos(damagedid, tx, ty, tz);

    new Float:dx = tx - px, Float:dy = ty - py, Float:dz = tz - pz;
    new Float:dist = floatsqroot(dx*dx + dy*dy + dz*dz);
    new maxRange = AC_GetWeaponMaxRange(weaponid);

    // Damage >2x max range = cheat
    if(dist > maxRange * 2.0 && dist > 60.0)
    {
        AccountData[playerid][pACWarns]++;
        if(AccountData[playerid][pACWarns] >= MAX_ANTICHEAT_WARNINGS)
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "%s dari %.1fm (max: %dm, warn %d/%d)",
                ReturnWeaponName(weaponid), dist, maxRange,
                AccountData[playerid][pACWarns], MAX_ANTICHEAT_WARNINGS);
            AC_Kick(playerid, "Magic Bullet", acdetail);
            return 0;
        }

        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga Magic Bullet. "YELLOW"[%s: %.1fm / max %dm]",
            GetName(playerid), playerid, ReturnWeaponName(weaponid), dist, maxRange);
    }

    return 1;
}
