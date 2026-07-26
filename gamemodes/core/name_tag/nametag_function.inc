#include <YSI_Coding\y_hooks>

new STREAMER_TAG_3D_TEXT_LABEL: NameTag[MAX_PLAYERS][MAX_PLAYERS];
new STREAMER_TAG_3D_TEXT_LABEL: AdminNameTag[MAX_PLAYERS][MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    for (new i = 0; i < MAX_PLAYERS; i++)
    {
        if (IsValidDynamic3DTextLabel(NameTag[playerid][i]))
        {
            DestroyDynamic3DTextLabel(NameTag[playerid][i]);
            NameTag[playerid][i] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        }

        if (IsValidDynamic3DTextLabel(AdminNameTag[playerid][i]))
        {
            DestroyDynamic3DTextLabel(AdminNameTag[playerid][i]);
            AdminNameTag[playerid][i] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        }
    }
    return 1;
}

DisplayAdminNameTag(playerid)
{
    if (!AccountData[playerid][pToggleNameID])
    {
        new string[300];
        foreach (new i : Player)
        {
            if (AccountData[i][IsLoggedIn] && AccountData[i][pSpawned])
            {
                new Float:health, Float:armour;
                GetPlayerHealth(i, health);
                GetPlayerArmour(i, armour);

                format(string, sizeof(string), "%s | %s (PID: %d)\n"RED"%.2f"WHITE" | %.2f", AccountData[i][pName], AccountData[i][pUCP], i, health, armour);

                if (AdminNameTag[playerid][i] == STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID)
                {
                    AdminNameTag[playerid][i] = CreateDynamic3DTextLabel(string, -1, 0.0, 0.0, 0.30, 25.0, i, INVALID_VEHICLE_ID, 0, -1, -1, playerid, 25.0, -1, 0);
                }
            }
        }
        AccountData[playerid][pToggleNameID] = true;
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Name NTAG ID telah diaktifkan");
    }
    else
    {
        foreach (new i : Player)
        {
            if (AccountData[i][IsLoggedIn])
            {
                if (AdminNameTag[playerid][i] != STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID)
                {
                    DestroyDynamic3DTextLabel(AdminNameTag[playerid][i]);
                    AdminNameTag[playerid][i] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
                }
            }
        }
        AccountData[playerid][pToggleNameID] = false;
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Name NTAG ID telah dimatikan");
    }
    return true;
}

DisplayPlayerNameTag(playerid)
{
    if (!AccountData[playerid][pNameTagShown])
    {
        new string[300];
        foreach (new i : Player)
        {
            if (AccountData[i][IsLoggedIn] && AccountData[i][pSpawned])
            {
                format(string, sizeof(string), "%s (PID: %d)", AccountData[i][pUCP], i);

                if (NameTag[playerid][i] == STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID)
                {
                    NameTag[playerid][i] = CreateDynamic3DTextLabel(string, 0xFFFFFFFF, 0.0, 0.0, 0.30, 15.0, i, INVALID_VEHICLE_ID, 1, -1, -1, playerid, 15.0, -1, 0);
                }
            }
        }
        AccountData[playerid][pNameTagShown] = true;
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Name SID telah diaktifkan");
    }
    else
    {
        foreach (new i : Player)
        {
            if (AccountData[i][IsLoggedIn])
            {
                if (NameTag[playerid][i] != STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID)
                {
                    DestroyDynamic3DTextLabel(NameTag[playerid][i]);
                    NameTag[playerid][i] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
                }
            }
        }
        AccountData[playerid][pNameTagShown] = false;
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Name SID telah dimatikan");
    }
    return true;
}
