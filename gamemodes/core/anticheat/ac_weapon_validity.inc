#include <YSI_Coding\y_hooks>

// ---------------------------------------------------------------------------
//  AC_WEAPON_VALIDITY — Full weapon slot scan untuk deteksi weapon hack
//  Adaptasi dari ac-hytam-legam, disesuaikan dengan framework Vertex
//  Melengkapi existing pre-spawn weapon check di timers_ptask_anticheat.inc
//  Dijalankan via ptask 1 detik (bukan OnPlayerUpdate) untuk performa
//
//  v2 fix: ResetPlayerWeapons removed (player being kicked anyway, GunData
//  tracks legitimate weapons independently → SetWeapons restores on reconnect).
//  Minigun (38) added back to forbidden — existing IsProhibitedWeapon only
//  checks GetPlayerWeapon (current weapon), slot scan catches non-current slots.
// ---------------------------------------------------------------------------

// Weapon IDs yang SAH (0 = fist, 1-9 = melee, 22-46 = firearms/items)
static stock bool:AC_IsWeaponIDValid(weaponid)
{
    return (weaponid == 0) || (1 <= weaponid <= 9) || (22 <= weaponid <= 46);
}

// Weapon IDs yang DILARANG KERAS (crasher / abuse tools)
// 40 (detonator) sudah ditangani oleh existing IsProhibitedWeapon + timers_ptask
// 38 (minigun) ditambahkan KEMBALI karena IsProhibitedWeapon hanya cek
//   GetPlayerWeapon (current weapon) — minigun di slot lain tidak ketangkap.
//   Slot scan ini melengkapi dengan cek semua 13 slot.
// 44, 45 (NV/thermal goggles) tidak ada di IsProhibitedWeapon, ditambahkan.
static stock bool:AC_IsWeaponForbidden(weaponid)
{
    switch(weaponid)
    {
        case 38:     return true;   // minigun (hanya admin/event boleh, slot scan melengkapi existing)
        case 44, 45: return true;   // night vision goggles / thermal goggles (abuse)
        default:     return false;
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
            return 1; // kick sudah dijadwalkan, stop scanning
        }

        // Forbidden weapon — minigun / NV goggles / thermal goggles
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
