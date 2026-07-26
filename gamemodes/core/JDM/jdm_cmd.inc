YCMD:createjdm(playerid, params[], help)
{
    new leaderid, jname[32], jid = Iter_Free(JDMs);
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);
    if(jid == -1) return SEM(playerid, "Jumlah JDM sudah mencapai maksimum!");
    if(sscanf(params, "is[32]", leaderid, jname)) 
        return SUM(playerid, "/createjdm [playerid] [nama]");
    if(!IsPlayerConnected(leaderid)) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(strlen(jname) > 32) 
        return SEM(playerid, "Panjang nama JDM maksimal 32 karakter!");
    
    if(Player_JDMCount(leaderid) > 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah memimpin JDM lain!");
    
    JDMData[jid][jdmLeaderID] = AccountData[leaderid][pID];
    strcopy(JDMData[jid][jdmLeaderName], AccountData[leaderid][pName]);
    strcopy(JDMData[jid][jdmName], jname);
    JDMData[jid][jdmMoney] = 0;
    JDMData[jid][jdmPoints] = 0;
    AccountData[leaderid][pJDM] = jid;
    AccountData[leaderid][pJDMRank] = 6;

    Iter_Add(JDMs, jid);

    new query[512];
    mysql_format(g_SQL, query, sizeof(query), 
        "INSERT INTO `jdm` SET `ID`=%d, `LeaderID`=%d, `LeaderName`='%e', `Name`='%e', `Money`=%d, `Points`=%d",
        jid, JDMData[jid][jdmLeaderID], JDMData[jid][jdmLeaderName], JDMData[jid][jdmName], 
        JDMData[jid][jdmMoney], JDMData[jid][jdmPoints]);
    mysql_pquery(g_SQL, query, "OnJDMAdded", "ii", playerid, jid);
    return 1;
}

forward OnJDMAdded(playerid, jid);
public OnJDMAdded(playerid, jid)
{
    JDM_Save(jid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s membuat JDM dengan ID: %d.", AccountData[playerid][pAdminname], jid);
    return 1;
}

YCMD:editjdm(playerid, params[], help)
{
    new jid, type[24], string[128];
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    if(sscanf(params, "ds[24]S()[128]", jid, type, string)) 
        return SUM(playerid, "/editjdm [id] [option]~n~name, leader, money, points, vault, desk, garage, garagespawn, remove");
    if(!Iter_Contains(JDMs, jid)) 
        return SEM(playerid, "ID JDM tersebut tidak valid!");

    if(!strcmp(type, "name", true))
    {
        new newname[32];
        if(sscanf(string, "s[32]", newname)) 
            return SUM(playerid, "/editjdm [id] name [nama baru]");
        strcopy(JDMData[jid][jdmName], newname);

        static strrs[144];
        format(strrs, sizeof(strrs), "[ "WHITE"(Garasi JDM): "YELLOW"%s "GREEN"]", JDMData[jid][jdmName]);
        UpdateDynamic3DTextLabelText(JDMData[jid][jdmGarageLabel], Y_GREEN, strrs);

        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah nama JDM ID: %d menjadi %s.", AccountData[playerid][pAdminname], jid, newname);
    }
    else if(!strcmp(type, "leader", true))
    {
        new newid;
        if(sscanf(string, "d", newid)) 
            return SUM(playerid, "/editjdm [id] leader [playerid]");
        if(!IsPlayerConnected(newid)) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
        
        foreach(new i : Player)
        {
            if(JDMData[jid][jdmLeaderID] == AccountData[i][pID])
            {
                AccountData[i][pJDM] = -1;
                AccountData[i][pJDMRank] = 0;
            }
        }
        
        JDMData[jid][jdmLeaderID] = AccountData[newid][pID];
        strcopy(JDMData[jid][jdmLeaderName], AccountData[newid][pName]);
        AccountData[newid][pJDM] = jid;
        AccountData[newid][pJDMRank] = 6;

        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah ketua JDM ID: %d menjadi %s(%d).", 
            AccountData[playerid][pAdminname], jid, AccountData[newid][pName], newid);
    }
    else if(!strcmp(type, "money", true))
    {
        new amount;
        if(sscanf(string, "d", amount)) 
            return SUM(playerid, "/editjdm [id] money [jumlah]");
        if(amount < 0) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

        JDMData[jid][jdmMoney] = amount;
        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah uang JDM ID: %d menjadi $%s.", 
            AccountData[playerid][pAdminname], jid, FormatMoney(amount));
    }
    else if(!strcmp(type, "points", true))
    {
        new amount;
        if(sscanf(string, "d", amount)) 
            return SUM(playerid, "/editjdm [id] points [jumlah]");
        if(amount < 0) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

        JDMData[jid][jdmPoints] = amount;
        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah poin JDM ID: %d menjadi %d.", 
            AccountData[playerid][pAdminname], jid, amount);
    }
    else if(!strcmp(type, "vault", true))
    {
        if(DestroyDynamic3DTextLabel(JDMData[jid][jdmVaultLabel]))
            JDMData[jid][jdmVaultLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

        JDMData[jid][jdmVaultWorld] = GetPlayerVirtualWorld(playerid);
        JDMData[jid][jdmVaultInt] = GetPlayerInterior(playerid);
        GetPlayerPos(playerid, JDMData[jid][jdmVaultPos][0], JDMData[jid][jdmVaultPos][1], JDMData[jid][jdmVaultPos][2]);
        JDMData[jid][jdmVaultLabel] = CreateDynamic3DTextLabel("[Y] "WHITE"untuk akses penyimpanan", 
            Y_YELLOW, JDMData[jid][jdmVaultPos][0], JDMData[jid][jdmVaultPos][1], JDMData[jid][jdmVaultPos][2] + 0.35, 
            10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, JDMData[jid][jdmVaultWorld], JDMData[jid][jdmVaultInt], -1, 10.00, -1, 0);

        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah posisi brankas JDM ID: %d.", AccountData[playerid][pAdminname], jid);
    }
    else if(!strcmp(type, "desk", true))
    {
        if(DestroyDynamic3DTextLabel(JDMData[jid][jdmDeskLabel]))
            JDMData[jid][jdmDeskLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

        JDMData[jid][jdmDeskWorld] = GetPlayerVirtualWorld(playerid);
        JDMData[jid][jdmDeskInt] = GetPlayerInterior(playerid);
        GetPlayerPos(playerid, JDMData[jid][jdmDeskPos][0], JDMData[jid][jdmDeskPos][1], JDMData[jid][jdmDeskPos][2]);
        JDMData[jid][jdmDeskLabel] = CreateDynamic3DTextLabel("[Y] "WHITE"untuk akses bos desk", 
            Y_YELLOW, JDMData[jid][jdmDeskPos][0], JDMData[jid][jdmDeskPos][1], JDMData[jid][jdmDeskPos][2] + 0.35, 
            10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, JDMData[jid][jdmDeskWorld], JDMData[jid][jdmDeskInt], -1, 10.00, -1, 0);

        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah posisi bos desk JDM ID: %d.", AccountData[playerid][pAdminname], jid);
    }
    else if(!strcmp(type, "garage", true))
    {
        if(DestroyDynamicObject(JDMData[jid][jdmGarageObjid]))
            JDMData[jid][jdmGarageObjid] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;
        if(DestroyDynamicPickup(JDMData[jid][jdmGaragePickup]))
            JDMData[jid][jdmGaragePickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
        if(DestroyDynamic3DTextLabel(JDMData[jid][jdmGarageLabel]))
            JDMData[jid][jdmGarageLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

        JDMData[jid][jdmGarageWorld] = GetPlayerVirtualWorld(playerid);
        JDMData[jid][jdmGarageInt] = GetPlayerInterior(playerid);
        GetPlayerPos(playerid, JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]);
        
        JDMData[jid][jdmGarageObjid] = CreateDynamicObject(1316, 
            JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2] - 0.9, 
            0.0, 0.0, 0.0, JDMData[jid][jdmGarageWorld], JDMData[jid][jdmGarageInt], -1, 100.00, 100.00, -1);
        SetDynamicObjectMaterial(JDMData[jid][jdmGarageObjid], 0, 18646, "matcolours", "white", 0x3399FF91);

        JDMData[jid][jdmGaragePickup] = CreateDynamicPickup(1313, 23, 
            JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]-0.05, 
            JDMData[jid][jdmGarageWorld], JDMData[jid][jdmGarageInt], -1, 30.00, -1, 0);
        
        static strrs[144];
        format(strrs, sizeof(strrs), "[ "WHITE"(Garasi JDM): "YELLOW"%s "GREEN"]", JDMData[jid][jdmName]);
        JDMData[jid][jdmGarageLabel] = CreateDynamic3DTextLabel(strrs, Y_GREEN, 
            JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]+0.45, 
            10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, JDMData[jid][jdmGarageWorld], JDMData[jid][jdmGarageInt], -1, 10.00, -1, 0);

        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah posisi garasi JDM ID: %d.", AccountData[playerid][pAdminname], jid);
    }
    else if(!strcmp(type, "garagespawn", true))
    {
        GetPlayerPos(playerid, JDMData[jid][jdmGarageSpPos][0], JDMData[jid][jdmGarageSpPos][1], JDMData[jid][jdmGarageSpPos][2]);
        GetPlayerFacingAngle(playerid, JDMData[jid][jdmGarageSpPos][3]);
        JDMData[jid][jdmGarageSpWorld] = GetPlayerVirtualWorld(playerid);
        JDMData[jid][jdmGarageSpInt] = GetPlayerInterior(playerid);

        JDM_Save(jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah posisi garage spawn JDM ID: %d.", AccountData[playerid][pAdminname], jid);
    }
    else if(!strcmp(type, "remove", true))
    {
        if(DestroyDynamic3DTextLabel(JDMData[jid][jdmVaultLabel]))
            JDMData[jid][jdmVaultLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        if(DestroyDynamic3DTextLabel(JDMData[jid][jdmDeskLabel]))
            JDMData[jid][jdmDeskLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        if(DestroyDynamicObject(JDMData[jid][jdmGarageObjid]))
            JDMData[jid][jdmGarageObjid] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;
        if(DestroyDynamicPickup(JDMData[jid][jdmGaragePickup]))
            JDMData[jid][jdmGaragePickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
        if(DestroyDynamic3DTextLabel(JDMData[jid][jdmGarageLabel]))
            JDMData[jid][jdmGarageLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

        JDMData[jid][jdmLeaderID] = 0;
        JDMData[jid][jdmLeaderName][0] = EOS;
        JDMData[jid][jdmName][0] = EOS;
        JDMData[jid][jdmMoney] = 0;
        JDMData[jid][jdmPoints] = 0;
        JDMData[jid][jdmVaultWorld] = 0;
        JDMData[jid][jdmVaultInt] = 0;
        JDMData[jid][jdmVaultPos][0] = 0;
        JDMData[jid][jdmVaultPos][1] = 0;
        JDMData[jid][jdmVaultPos][2] = 0;
        JDMData[jid][jdmDeskWorld] = 0;
        JDMData[jid][jdmDeskInt] = 0;
        JDMData[jid][jdmDeskPos][0] = 0;
        JDMData[jid][jdmDeskPos][1] = 0;
        JDMData[jid][jdmDeskPos][2] = 0;

        foreach(new i : Player)
        {
            if(AccountData[i][pJDM] == jid)
            {
                AccountData[i][pJDM] = -1;
                AccountData[i][pJDMRank] = 0;
            }
        }

        new query[128];
        mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `jdm` WHERE `ID` = %d", jid);
        mysql_pquery(g_SQL, query);

        Iter_Remove(JDMs, jid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s menghapus JDM ID: %d.", AccountData[playerid][pAdminname], jid);
    }
    return 1;
}
YCMD:listjdm(playerid, params[], help)
{
    new string[2048], count;
    strcat(string, "ID\tNama JDM\tKetua\tAnggota Online\tPoin\n");
    
    foreach(new jid : JDMs)
    {
        new memberCount = CountJDMOnline(jid);
        
        if(count % 2 == 0)
        {
            format(string, sizeof(string), "%s"WHITE"%d\t"WHITE"%s\t"WHITE"%s\t"YELLOW"%d\t"YELLOW"%d\n", 
                string, jid, JDMData[jid][jdmName], GetJDMLeaderName(jid), memberCount, JDMData[jid][jdmPoints]);
        }
        else
        {
            format(string, sizeof(string), "%s"GRAY"%d\t"GRAY"%s\t"GRAY"%s\t"YELLOW"%d\t"YELLOW"%d\n", 
                string, jid, JDMData[jid][jdmName], GetJDMLeaderName(jid), memberCount, JDMData[jid][jdmPoints]);
        }
        count++;
        
        if(count >= 50) break;
    }
    
    if(count == 0)
        strcat(string, "Belum ada JDM yang terdaftar!");
    
    Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Daftar JDM Kota", string, "Tutup", "");
    return 1;
}

YCMD:myjdm(playerid, params[], help)
{
    Show_JDMInfo(playerid);
    return 1;
}