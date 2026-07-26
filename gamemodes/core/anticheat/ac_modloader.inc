#include <YSI_Coding\y_hooks>

// Cara kerja:
//   OnPlayerConnect: baca GetPlayerVersion, cari "moonloader"/"monetloader" di string.
//   Jika ditemukan: set AC_Kicked=true (prevent duplicate dari hook lain),
//   AC_Notify ke staff, KickEx 200ms. Tidak ada exempt — mod loader = blokir semua,
//   termasuk admin (belum login saat connect).

hook OnPlayerConnect(playerid)
{
    if(IsPlayerNPC(playerid))
        return 1;

    new version[64];
    GetPlayerVersion(playerid, version, sizeof(version));

    if(strfind(version, "moonloader", true) != -1)
    {
        AC_Kicked[playerid] = true;
        AC_Notify(playerid, "Moonloader", "Moonloader detected in client version", true);
        SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Moonloader terdeteksi di client anda. Server tidak mengizinkan mod loader.");
        KickEx(playerid, 200);
        return 0;
    }

    if(strfind(version, "monetloader", true) != -1)
    {
        AC_Kicked[playerid] = true;
        AC_Notify(playerid, "Monetloader", "Monetloader detected in client version", true);
        SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}Monetloader terdeteksi di client anda. Server tidak mengizinkan mod loader.");
        KickEx(playerid, 200);
        return 0;
    }

    return 1;
}
