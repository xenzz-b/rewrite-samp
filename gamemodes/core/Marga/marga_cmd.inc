// ============================================================
// MARGA COMMANDS - LENGKAP
// ============================================================

YCMD:createmarga(playerid, params[], help)
{
    new leaderid, mname[32], mid = Iter_Free(Margas);
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);
    if(mid == -1) return SEM(playerid, "Jumlah Marga sudah mencapai maksimum!");
    if(sscanf(params, "is[32]", leaderid, mname)) 
        return SUM(playerid, "/createmarga [playerid] [nama]");
    if(!IsPlayerConnected(leaderid)) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(strlen(mname) > 32) 
        return SEM(playerid, "Panjang nama Marga maksimal 32 karakter!");
    
    if(Player_MargaCount(leaderid) > 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah memimpin Marga lain!");
    
    MargaData[mid][margaLeaderID] = AccountData[leaderid][pID];
    strcopy(MargaData[mid][margaLeaderName], AccountData[leaderid][pName]);
    strcopy(MargaData[mid][margaName], mname);
    MargaData[mid][margaMoney] = 0;
    AccountData[leaderid][pMarga] = mid;
    AccountData[leaderid][pMargaRank] = 6;

    Iter_Add(Margas, mid);

    new query[512];
    mysql_format(g_SQL, query, sizeof(query), 
        "INSERT INTO `marga` SET `ID`=%d, `LeaderID`=%d, `LeaderName`='%e', `Name`='%e', `Money`=%d",
        mid, MargaData[mid][margaLeaderID], MargaData[mid][margaLeaderName], 
        MargaData[mid][margaName], MargaData[mid][margaMoney]);
    mysql_pquery(g_SQL, query, "OnMargaAdded", "ii", playerid, mid);
    return 1;
}

YCMD:editmarga(playerid, params[], help)
{
    new mid, type[24], string[128];
    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    if(sscanf(params, "ds[24]S()[128]", mid, type, string)) 
        return SUM(playerid, "/editmarga [id] [option]~n~name, leader, money, remove");
    if(!Iter_Contains(Margas, mid)) 
        return SEM(playerid, "ID Marga tersebut tidak valid!");

    if(!strcmp(type, "name", true))
    {
        new newname[32];
        if(sscanf(string, "s[32]", newname)) 
            return SUM(playerid, "/editmarga [id] name [nama baru]");
        strcopy(MargaData[mid][margaName], newname);
        Marga_Save(mid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah nama Marga ID: %d menjadi %s.", 
            AccountData[playerid][pAdminname], mid, newname);
    }
    else if(!strcmp(type, "leader", true))
    {
        new newid;
        if(sscanf(string, "d", newid)) 
            return SUM(playerid, "/editmarga [id] leader [playerid]");
        if(!IsPlayerConnected(newid)) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
        
        if(Player_MargaCount(newid) > 0)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah memimpin Marga lain!");
        
        foreach(new i : Player)
        {
            if(MargaData[mid][margaLeaderID] == AccountData[i][pID])
            {
                AccountData[i][pMarga] = -1;
                AccountData[i][pMargaRank] = 0;
            }
        }
        
        MargaData[mid][margaLeaderID] = AccountData[newid][pID];
        strcopy(MargaData[mid][margaLeaderName], AccountData[newid][pName]);
        AccountData[newid][pMarga] = mid;
        AccountData[newid][pMargaRank] = 6;

        Marga_Save(mid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah ketua Marga ID: %d menjadi %s(%d).", 
            AccountData[playerid][pAdminname], mid, AccountData[newid][pName], newid);
    }
    else if(!strcmp(type, "money", true))
    {
        new amount;
        if(sscanf(string, "d", amount)) 
            return SUM(playerid, "/editmarga [id] money [jumlah]");
        if(amount < 0) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

        MargaData[mid][margaMoney] = amount;
        Marga_Save(mid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah uang Marga ID: %d menjadi $%s.", 
            AccountData[playerid][pAdminname], mid, FormatMoney(amount));
    }
    else if(!strcmp(type, "remove", true))
    {
        MargaData[mid][margaLeaderID] = 0;
        MargaData[mid][margaLeaderName][0] = EOS;
        MargaData[mid][margaName][0] = EOS;
        MargaData[mid][margaMoney] = 0;

        foreach(new i : Player)
        {
            if(AccountData[i][pMarga] == mid)
            {
                AccountData[i][pMarga] = -1;
                AccountData[i][pMargaRank] = 0;
            }
        }

        new query[128];
        mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `marga` WHERE `ID` = %d", mid);
        mysql_pquery(g_SQL, query);

        Iter_Remove(Margas, mid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s menghapus Marga ID: %d.", AccountData[playerid][pAdminname], mid);
    }
    return 1;
}

YCMD:listmarga(playerid, params[], help)
{
    new string[2048], count;
    strcat(string, "ID\tNama Marga\tLeader\tAnggota Online\n");
    
    foreach(new mid : Margas)
    {
        new memberCount = CountMargaOnline(mid);
        
        if(count % 2 == 0)
        {
            format(string, sizeof(string), "%s"WHITE"%d\t"WHITE"%s\t"WHITE"%s\t"YELLOW"%d\n", 
                string, mid, MargaData[mid][margaName], GetMargaLeaderName(mid), memberCount);
        }
        else
        {
            format(string, sizeof(string), "%s"GRAY"%d\t"GRAY"%s\t"GRAY"%s\t"YELLOW"%d\n", 
                string, mid, MargaData[mid][margaName], GetMargaLeaderName(mid), memberCount);
        }
        count++;
        
        if(count >= 50) break;
    }
    
    if(count == 0)
        strcat(string, "Belum ada Marga yang terdaftar!");
    
    Dialog_Show(playerid, "MargaList", DIALOG_STYLE_TABLIST_HEADERS, "List Marga", string, "Lihat Member", "Tutup");
    return 1;
}

YCMD:margainfo(playerid, params[], help)
{
    Show_MargaInfo(playerid);
    return 1;
}

YCMD:invitemarga(playerid, params[], help)
{
    new targetid;
    if(sscanf(params, "u", targetid))
        return SUM(playerid, "/invitemarga [playerid]");
    
    if(AccountData[playerid][pMarga] == -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam Marga manapun!");
    if(AccountData[playerid][pMargaRank] < 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga!");
    if(!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tidak ditemukan!");
    if(AccountData[targetid][pMarga] != -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah memiliki Marga!");
    if(!IsPlayerNearPlayer(playerid, targetid, 3.0))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak berada di dekat anda!");
    
    new mid = AccountData[playerid][pMarga];
    AccountData[targetid][pMarga] = mid;
    AccountData[targetid][pMargaRank] = 1;
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_Marga` = %d, `Char_MargaRank` = 1 WHERE `pID` = %d", 
        mid, AccountData[targetid][pID]);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(targetid, NOTIFICATION_SUCCESS, sprintf("Anda diundang bergabung ke Marga %s oleh %s!", MargaData[mid][margaName], ReturnName(playerid)));
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil mengundang %s ke Marga %s!", ReturnName(targetid), MargaData[mid][margaName]));
    return 1;
}

// ============================================================
// COMMAND KHUSUS PETINGGI: KICK MEMBER DARI MARGA
// ============================================================

YCMD:kickmarga(playerid, params[], help)
{
    new targetid;
    if(sscanf(params, "u", targetid))
        return SUM(playerid, "/kickmarga [playerid]");
    
    if(AccountData[playerid][pMarga] == -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam Marga manapun!");
    if(AccountData[playerid][pMargaRank] < 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga! (Minimal Wakil)");
    if(!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tidak ditemukan!");
    if(AccountData[targetid][pMarga] != AccountData[playerid][pMarga])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak satu Marga dengan anda!");
    if(AccountData[targetid][pMargaRank] >= AccountData[playerid][pMargaRank])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat mengeluarkan member yang ranknya sama atau lebih tinggi!");
    if(AccountData[playerid][pID] == AccountData[targetid][pID])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat mengeluarkan diri sendiri!");
    
    new mid = AccountData[playerid][pMarga];
    new targetName[MAX_PLAYER_NAME];
    GetPlayerName(targetid, targetName, sizeof(targetName));
    
    AccountData[targetid][pMarga] = -1;
    AccountData[targetid][pMargaRank] = 0;
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_Marga` = -1, `Char_MargaRank` = 0 WHERE `pID` = %d", 
        AccountData[targetid][pID]);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(targetid, NOTIFICATION_ERROR, sprintf("Anda telah dikeluarkan dari Marga %s oleh %s!", MargaData[mid][margaName], ReturnName(playerid)));
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil mengeluarkan %s dari Marga %s!", targetName, MargaData[mid][margaName]));
    
    // Kirim pesan ke semua anggota Marga yang online
    foreach(new i : Player)
    {
        if(AccountData[i][pMarga] == mid && i != playerid && i != targetid)
        {
            SendClientMessageEx(i, Y_SERVER, "[MARGA] %s telah dikeluarkan dari Marga oleh %s", targetName, ReturnName(playerid));
        }
    }
    return 1;
}

YCMD:margamenu(playerid, params[], help)
{
    new mid = AccountData[playerid][pMarga];
    if(mid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam Marga manapun!");
    if(AccountData[playerid][pMargaRank] < 5) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga! (Minimal Wakil)");

    Dialog_Show(playerid, "MargaBosDesk", DIALOG_STYLE_LIST, "Bos Desk Marga", 
        "Invite Member\n\
        "GRAY"Kelola Jabatan\n\
        Kick Member\n\
        "GRAY"Lihat Info Marga\n\
        Deposit Uang Marga\n\
        "GRAY"Withdraw Uang Marga", "Pilih", "Batal");
    return 1;
}
