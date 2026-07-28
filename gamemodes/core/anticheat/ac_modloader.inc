#include <YSI_Coding\y_hooks>

// GetPlayerVersion check for moonloader/monetloader. No exempt — block all.
// AC_Kicked=true prevents duplicate notifications from other hooks.

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
