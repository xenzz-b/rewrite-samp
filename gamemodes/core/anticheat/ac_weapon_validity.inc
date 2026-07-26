#include <YSI_Coding\y_hooks>

// Cara kerja:
//   ptask 1 detik: scan 13 weapon slots. Invalid weapon ID (di luar 0,1-9,22-46) = kick.
//   Forbidden weapon: minigun(38), NV goggles(44), thermal goggles(45) = kick.
//   38 melengkapi existing IsProhibitedWeapon yang hanya cek current weapon (GetPlayerWeapon),
//   slot scan ini cek semua slot. 44/45 tidak ada di existing check.
//   GunData tracks weapons independently → SetWeapons restores on reconnect (no ResetPlayerWeapons).

static stock bool:AC_IsWeaponIDValid(weaponid)
{
    return (weaponid == 0) || (1 <= weaponid <= 9) || (22 <= weaponid <= 46);
}

static stock bool:AC_IsWeaponForbidden(weaponid)
{
    switch(weaponid)
    {
        case 38:     return true;   // minigun
        case 44, 45: return true;   // NV/thermal goggles
        default:     return false;
    }
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

        // AC_IsWeaponIDValid(0)=true, jadi !AC_IsWeaponIDValid(wep) sudah implies wep≠0
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
