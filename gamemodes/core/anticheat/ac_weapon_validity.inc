#include <YSI_Coding\y_hooks>

// ptask 1s: scan 13 slots. Invalid ID (outside 0,1-9,22-46) or forbidden (38,44,45) = kick.
// 38 melengkapi existing IsProhibitedWeapon (only checks current weapon).
// GunData independent → SetWeapons restores on reconnect.

static stock bool:AC_IsWeaponIDValid(weaponid)
{
    return (weaponid == 0) || (1 <= weaponid <= 9) || (22 <= weaponid <= 46);
}

static stock bool:AC_IsWeaponForbidden(weaponid)
{
    switch(weaponid)
    {
        case 38:     return true;
        case 44, 45: return true;
        default:     return false;
    }
    return false;
}

ptask AntiCheatWeaponValidity[1000](playerid)
{
    if(!AC_CanPunish(playerid))
        return 1;

    for(new slot; slot < 13; slot++)
    {
        new wep, ammo;
        GetPlayerWeaponData(playerid, slot, wep, ammo);

        if(wep == 0 && ammo == 0)
            continue;

        if(!AC_IsWeaponIDValid(wep))
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "invalid weapon %d in slot %d (ammo: %d)", wep, slot, ammo);
            AC_Kick(playerid, "Weapon Hack", acdetail);
            return 1;
        }

        if(AC_IsWeaponForbidden(wep))
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "forbidden weapon %s (%d) in slot %d", ReturnWeaponName(wep), wep, slot);
            AC_Kick(playerid, "Weapon Hack", acdetail);
            return 1;
        }
    }

    return 1;
}
