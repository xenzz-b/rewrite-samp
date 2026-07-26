#include <YSI_Coding\y_hooks>

// ---------------------------------------------------------------------------
//  AC_MODLOADER — Blokir Moonloader & Monetloader saat connect
//  Menggunakan GetPlayerVersion (open.mp native) untuk cek client mod
//  Tidak ada exempt — mod loader tidak diizinkan untuk siapa pun,
//  termasuk admin (admin belum login saat OnPlayerConnect).
//
//  v2 fix: set AC_Kicked[playerid] = true agar hook lain tidak trigger
//  duplicate notifications sebelum kick terjadi.
// ---------------------------------------------------------------------------

hook OnPlayerConnect(playerid)
{
    // NPC server tidak punya mod loader
    if(IsPlayerNPC(playerid))
        return 1;

    // open.mp mendukung GetPlayerVersion untuk membaca mod loader dari client
    new version[64];
    GetPlayerVersion(playerid, version, sizeof(version));

    // Moonloader injects identifier ke client version string
    if(strfind(version, "moonloader", true) != -1)
    {
        AC_Kicked[playerid] = true; // FIX: set flag agar hook lain tidak duplicate
        AC_Notify(playerid, "Moonloader", "Moonloader detected in client version", true);
        SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Moonloader terdeteksi di client anda. Server tidak mengizinkan mod loader.");
        KickEx(playerid, 200);
        return 0;
    }

    // Monetloader injects identifier ke client version string
    if(strfind(version, "monetloader", true) != -1)
    {
        AC_Kicked[playerid] = true; // FIX: set flag agar hook lain tidak duplicate
        AC_Notify(playerid, "Monetloader", "Monetloader detected in client version", true);
        SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Monetloader terdeteksi di client anda. Server tidak mengizinkan mod loader.");
        KickEx(playerid, 200);
        return 0;
    }

    return 1;
}
