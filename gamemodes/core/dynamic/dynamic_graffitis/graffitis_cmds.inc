YCMD:gototag(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new tgid;
    if(sscanf(params, "d", tgid)) return SUM(playerid, "/gototag [tgid]");

    if(!Iter_Contains(ServerTags, tgid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Graffiti Tag ID tersebut tidak valid!");
    SetPlayerPositionEx(playerid, GraffitiInfo[tgid][gfPos][0] - 5.5, GraffitiInfo[tgid][gfPos][1], GraffitiInfo[tgid][gfPos][2], -90);
    SetPlayerInteriorEx(playerid, GraffitiInfo[tgid][gfInt]);
    SetPlayerVirtualWorldEx(playerid, GraffitiInfo[tgid][gfVW]);

    AccountData[playerid][pInDoor] = -1;
    AccountData[playerid][pInHouse] = -1;
    AccountData[playerid][pInBiz] = -1;
    AccountData[playerid][pInRusun] = -1;
    AccountData[playerid][pInGudang] = -1;
    return 1;
}

YCMD:edittag(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new tgid;
    if(sscanf(params, "d", tgid)) return SUM(playerid, "/gototag [tgid]");

    if(!Iter_Contains(ServerTags, tgid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Graffiti Tag ID tersebut tidak valid!");
    if(!IsPlayerInRangeOfPoint(playerid, 30.0, GraffitiInfo[tgid][gfPos][0], GraffitiInfo[tgid][gfPos][1], GraffitiInfo[tgid][gfPos][2])) 
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan Graffiti Tag ID tersebut!");
    if(Graffiti_BeingEdited(tgid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "That Graffiti Tag ID sedang diedit oleh admin lain!");

    if(!PlayerHasItem(playerid, "Pilox")) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki pilox!");
    AccountData[playerid][pTempValue] = tgid;

    Dialog_Show(playerid, "GraffitiEdit", DIALOG_STYLE_INPUT, ""Nexston"Nexston Roleplay "WHITE"- Edit Graffiti", 
    "Mohon masukkan tulisan graffiti yang ingin dibuat:\n\
    (n) = text akan berada di bawah/baris baru.\n\
    (r) = warna text merah.\n\
    (b) = warna text hitam.\n\
    (y) = warna text kuning.\n\
    (bl) = warna text biru.\n\
    (g) = warna text hijau.\n\
    (o) = warna text orange.\n\
    (w) = warna text putih.", "Input", "Batal");
    return 1;
}

YCMD:checktag(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new tgid;
    if(sscanf(params, "d", tgid)) return SUM(playerid, "/checktag [tgid]");
    if(!Iter_Contains(ServerTags, tgid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Graffiti Tag ID tersebut tidak valid!");

    static strgbg[144];
    format(strgbg, sizeof(strgbg), "[Tag] "WHITE"%s", GraffitiInfo[tgid][gfText]);
    SendClientMessage(playerid, X11_PALEGREEN4, strgbg);
    format(strgbg, sizeof(strgbg), "[Tag] "WHITE"Created by: "YELLOW"%s", GraffitiInfo[tgid][gfCreator]);
    SendClientMessage(playerid, X11_PALEGREEN4, strgbg);
    return 1;
}

YCMD:removetag(playerid, params[], help)
{
    new tgid, strgbg[128];
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    if (sscanf(params, "d", tgid))
        return SUM(playerid, "/removetag [id]");

    if (!Iter_Contains(ServerTags, tgid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid TAG ID!");
    if (Atm_BeingEdited(tgid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID TAG sedang diedit oleh admin lain!");
    
    if(DestroyDynamicObject(GraffitiInfo[tgid][gfObjid]))
        GraffitiInfo[tgid][gfObjid] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;

    GraffitiInfo[tgid][gfModel] = 0;
    GraffitiInfo[tgid][gfVW] = 0;
    GraffitiInfo[tgid][gfInt] = 0;
    GraffitiInfo[tgid][gfText][0] = EOS;
    GraffitiInfo[tgid][gfCreatorID] = 0;
    GraffitiInfo[tgid][gfCreator][0] = EOS;
    GraffitiInfo[tgid][gfPos][0] = 0.0;
    GraffitiInfo[tgid][gfPos][1] = 0.0;
    GraffitiInfo[tgid][gfPos][2] = 0.0;
    GraffitiInfo[tgid][gfPos][3] = 0.0;
    GraffitiInfo[tgid][gfPos][4] = 0.0;
    GraffitiInfo[tgid][gfPos][5] = 0.0;
    GraffitiInfo[tgid][gfExpiredTime] = 0;
    
    Iter_Remove(ServerTags, tgid);

    mysql_format(g_SQL, strgbg, sizeof(strgbg), "DELETE FROM `server_tags` WHERE `id` = %d", tgid);
    mysql_pquery(g_SQL, strgbg);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s removed TAG with ID: %d.", AccountData[playerid][pAdminname], tgid);
    return 1;
}