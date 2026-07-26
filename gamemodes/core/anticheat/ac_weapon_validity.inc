#include <YSI_Coding\y_hooks>

// ---------------------------------------------------------------------------
//  AC_WEAPON_VALIDITY — Full weapon slot scan untuk deteksi weapon hack
//  Adaptasi dari ac-hytam-legam, disesuaikan dengan framework Vertex
//  Melengkapi existing pre-spawn weapon check di timers_ptask_anticheat.inc
//  Dijalankan via ptask 1 detik (bukan OnPlayerUpdate) untuk performa
// ---------------------------------------------------------------------------

// Weapon IDs yang SAH (0 = fist, 1-9 = melee, 22-46 = firearms/items)
static stock bool:AC_IsWeaponIDValid(weaponid)
{
    return (weaponid == 0) || (1 <= weaponid <= 9) || (22 <= weaponid <= 46);
}

// Weapon IDs yang DILARANG KERAS (crasher / abuse tools)
// 40 (detonator) sudah ditangani oleh existing IsProhibitedWeapon + timers_ptask
// 38 (minigun) juga sudah di IsProhibitedWeapon
// Di sini hanya tambah 44/45 (NV/thermal goggles) yang belum ada di existing
static stock bool:AC_IsWeaponForbidden(weaponid)
{
    switch(weaponid)
    {
        case 44, 45: return true;  // night vision goggles / thermal goggles (abuse)
        default: return false;
    }
}

// ---------------------------------------------------------------------------
//  ptask — scan 1 detik sekali (sama seperti AntiCheatWeapon yang sudah ada)
// ---------------------------------------------------------------------------

ptask AntiCheatWeaponValidity[1000](playerid)
{
    if(!AC_CanPunish(playerid))
        return 1;

    // Scan semua 13 weapon slots
    for(new slot; slot < 13; slot++)
    {
        new wep, ammo;
        GetPlayerWeaponData(playerid, slot, wep, ammo);

        // Skip slot kosong
        if(wep == 0 && ammo == 0)
            continue;

        // Invalid weapon ID — bukan weapon yang ada di GTA
        if(!AC_IsWeaponIDValid(wep) && wep != 0)
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "invalid weapon %d in slot %d (ammo: %d)", wep, slot, ammo);
            AC_Kick(playerid, "Weapon Hack", acdetail);
            ResetPlayerWeapons(playerid);
            return 1;
        }

        // Forbidden weapon — NV goggles / thermal goggles (abuse)
        if(AC_IsWeaponForbidden(wep))
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "forbidden weapon %s (%d) in slot %d", ReturnWeaponName(wep), wep, slot);
            AC_Kick(playerid, "Weapon Hack", acdetail);
            ResetPlayerWeapons(playerid);
            return 1;
        }
    }

    return 1;
}
