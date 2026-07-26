// ============================================================
// MARGA SYSTEM - Clan/Family System (Minimalis)
// ============================================================

#define MAX_MARGA 100

// ============================================================
// ENUMS
// ============================================================

enum e_marga
{
    margaID,
    margaLeaderID,
    margaLeaderName[32],
    margaName[32],
    margaMoney,
    margaRankCount[7],
    
    // not save
    bool:margaLoaded
};
new MargaData[MAX_MARGA][e_marga],
    Iterator:Margas<MAX_MARGA>;

// Marga Rank
static const MargaRank[7][] = 
{
    "N/A",       // 0
    "Warga",     // 1
    "Keluarga",  // 2
    "Sesepuh",   // 3
    "Penghulu",  // 4
    "Wakil",     // 5
    "Ketua"      // 6
};

// ============================================================
// HELPER FUNCTIONS
// ============================================================

GetMargaName(marga)
{
    new name[32];
    if(marga != -1)
    {
        if(!isnull(MargaData[marga][margaName]))
            format(name, sizeof(name), "%s", MargaData[marga][margaName]);
        else
            format(name, sizeof(name), "Kosong");
    }
    else
        format(name, sizeof(name), "N/A");
    return name;
}

GetMargaLeaderName(marga)
{
    new name[32];
    if(marga != -1)
    {
        if(!isnull(MargaData[marga][margaLeaderName]))
            format(name, sizeof(name), "%s", MargaData[marga][margaLeaderName]);
        else
            format(name, sizeof(name), "Tidak Ada");
    }
    return name;
}

GetMargaRankName(playerid)
{
    new rank = AccountData[playerid][pMargaRank];
    if(rank < 0 || rank > 6) rank = 0;
    
    new rankName[32];
    switch(rank)
    {
        case 0: rankName = "N/A";
        case 1: rankName = "Warga";
        case 2: rankName = "Keluarga";
        case 3: rankName = "Sesepuh";
        case 4: rankName = "Penghulu";
        case 5: rankName = "Wakil";
        case 6: rankName = "Ketua";
        default: rankName = "N/A";
    }
    return rankName;
}

CountMargaOnline(marga)
{
    new jumlah;
    if(marga != -1)
    {
        foreach(new i : Player)
        {
            if(AccountData[i][pMarga] == marga)
                jumlah++;
        }
    }
    return jumlah;
}

Player_MargaCount(playerid)
{
    new counting;
    foreach(new mid : Margas)
    {
        if(MargaData[mid][margaLeaderID] == AccountData[playerid][pID])
            counting++;
    }
    return counting;
}

// ============================================================
// MARGA SAVE & LOAD
// ============================================================

Marga_Save(mid)
{
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), 
        "UPDATE `marga` SET \
        `LeaderID`=%d, `LeaderName`='%e', `Name`='%e', `Money`=%d \
        WHERE `ID`=%d",
        MargaData[mid][margaLeaderID],
        MargaData[mid][margaLeaderName],
        MargaData[mid][margaName],
        MargaData[mid][margaMoney],
        mid);
    mysql_pquery(g_SQL, query);
    return 1;
}

// Marga_Rebuild(mid)
// {
//     if(mid != -1)
//     {
//         // Marga tidak memiliki object fisik, hanya data
//         MargaData[mid][margaLoaded] = true;
//     }
//     return 1;
// }

forward LoadMargas();
public LoadMargas()
{
    new rows = cache_num_rows();
    if(rows)
    {
        new mid;
        for(new i; i < rows; i++)
        {
            cache_get_value_name_int(i, "ID", mid);
            cache_get_value_name_int(i, "LeaderID", MargaData[mid][margaLeaderID]);
            cache_get_value_name(i, "LeaderName", MargaData[mid][margaLeaderName]);
            cache_get_value_name(i, "Name", MargaData[mid][margaName]);
            cache_get_value_name_int(i, "Money", MargaData[mid][margaMoney]);

            MargaData[mid][margaLoaded] = true;
            Iter_Add(Margas, mid);
        }
        printf("[Dynamic Marga] Total number of loaded Marga: %d.", rows);
    }
    return 1;
}

// ============================================================
// MARGA MEMBERS FUNCTIONS
// ============================================================

ShowMargaMembers(playerid, mid)
{
    new string[2048], query[256];
    strcat(string, "Nama\tRank\tLast Online\n");
    
    mysql_format(g_SQL, query, sizeof(query), 
        "SELECT `Char_Name`, `Char_MargaRank`, `Char_LastLogin` FROM `player_characters` \
        WHERE `Char_Marga` = %d ORDER BY `Char_MargaRank` DESC", mid);
    mysql_query(g_SQL, query);
    
    new rows = cache_num_rows();
    if(rows)
    {
        for(new i; i < rows; i++)
        {
            new memberName[64], lastLogin[30], rank;
            cache_get_value_name(i, "Char_Name", memberName);
            cache_get_value_name_int(i, "Char_MargaRank", rank);
            cache_get_value_name(i, "Char_LastLogin", lastLogin);
            
            if(i % 2 == 0)
                format(string, sizeof(string), "%s"WHITE"%s\t"WHITE"%s\t"WHITE"%s\n", string, memberName, MargaRank[rank], lastLogin);
            else
                format(string, sizeof(string), "%s"GRAY"%s\t"GRAY"%s\t"GRAY"%s\n", string, memberName, MargaRank[rank], lastLogin);
        }
        
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, 
            sprintf("Anggota Marga: %s", MargaData[mid][margaName]), string, "Tutup", "");
    }
    else
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Marga ini tidak memiliki anggota!");
    }
    return 1;
}

Show_MargaInfo(playerid)
{
    new mid = AccountData[playerid][pMarga];
    if(mid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam Marga manapun!");

    new info[512];
    format(info, sizeof(info),"Nama Marga: "YELLOW"%s\n"WHITE"Ketua: "YELLOW"%s\n"WHITE"Uang Marga: "GREEN"%s\n"WHITE"Anggota Online: "YELLOW"%d\n"WHITE"Rank Anda: "YELLOW"%s",MargaData[mid][margaName],GetMargaLeaderName(mid),FormatMoney(MargaData[mid][margaMoney]),CountMargaOnline(mid),GetMargaRankName(playerid));
    Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Informasi Marga", info, "Tutup", "");
    return 1;
}

Show_MargaRankManage(playerid)
{
    new 
        string[1012],
        member_name[MAX_MEMBER_ROWS][64],
        member_pID[MAX_MEMBER_ROWS],
        member_rank[MAX_MEMBER_ROWS],
        member_lastlog[MAX_MEMBER_ROWS][30],
        curr_page = index_pagination[playerid],
        curr_index;

    curr_index = curr_page * MAX_MEMBER_ROWS;

    for(new i = 0; i < MAX_MEMBER_ROWS; i++) {
        member_pID[i] = 0;
    }

    new real_i = 0;
    
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_Marga` = %d ORDER BY `Char_MargaRank` DESC", AccountData[playerid][pMarga]);
    mysql_query(g_SQL, query);

    new rows = cache_num_rows(),
        count = 0;

    if(rows)
    {
        for(new i = curr_index; i < rows; i++) if(i <= rows)
        {
            if(real_i < sizeof(member_pID)) {
                cache_get_value_name(i, "Char_Name", member_name[real_i]);
                cache_get_value_name_int(i, "Char_MargaRank", member_rank[real_i]);
                cache_get_value_name(i, "Char_LastLogin", member_lastlog[real_i]);
                cache_get_value_name_int(i, "pID", member_pID[real_i]); 
                real_i++;
            }
            else {
                break;
            }
        }

        strcat(string, "Nama\tRank\tLast Online\n");

        for(new i = 0; i < real_i; ++i) if(member_pID[i] != 0)
        {
            strcat(string, sprintf("%s\t%s\t%s\n", member_name[i], MargaRank[member_rank[i]], member_lastlog[i]));
            ListedMember[playerid][count++] = member_pID[i];
        }

        new 
            total_pages = (rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS;
        new 
            max_page = total_pages - 1; 

        TempRows[playerid] = rows;

        if(curr_page > 0) {
            strcat(string, ""RED"<< Sebelumnya");
            strcat(string, "\n");
        }
        if(curr_page < max_page) {
            strcat(string, ""GREEN">> Selanjutnya"); 
            strcat(string, "\n");
        }

        Dialog_Show(playerid, "MargaSetRank", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Manage Rank Marga", string, "Pilih", "Batal");
    }
    else
    {
        PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Nexston"Nexston Roleplay "WHITE"- Manage Rank Marga", "Anda tidak memiliki member di Marga ini!", "Tutup", "");
    }
    return 1;
}

Show_MargaKick(playerid) 
{
    new 
        string[1012],
        member_name[MAX_MEMBER_ROWS][64],
        member_pID[MAX_MEMBER_ROWS],
        member_rank[MAX_MEMBER_ROWS],
        member_lastlog[MAX_MEMBER_ROWS][30],
        curr_page = index_pagination[playerid],
        curr_index;

    curr_index = curr_page * MAX_MEMBER_ROWS;

    for(new i = 0; i < MAX_MEMBER_ROWS; i++) {
        member_pID[i] = 0;
    }

    new real_i = 0;
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_Marga` = %d ORDER BY `Char_MargaRank` DESC", AccountData[playerid][pMarga]);
    mysql_query(g_SQL, query);

    new rows = cache_num_rows(),
        count = 0;

    if(rows)
    {
        for(new i = curr_index; i < rows && real_i < MAX_MEMBER_ROWS; i++)
        {
            cache_get_value_name(i, "Char_Name", member_name[real_i]);
            cache_get_value_name_int(i, "Char_MargaRank", member_rank[real_i]);
            cache_get_value_name(i, "Char_LastLogin", member_lastlog[real_i]);
            cache_get_value_name_int(i, "pID", member_pID[real_i]); 
            real_i++;
        }

        strcat(string, "Nama\tRank\tLast Online\n");

        for(new i = 0; i < real_i; ++i)
        {
            strcat(string, sprintf("%s\t%s\t%s\n", member_name[i], MargaRank[member_rank[i]], member_lastlog[i]));
            ListedMember[playerid][count++] = member_pID[i];
        }

        new total_pages = (rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS;
        new max_page = total_pages - 1;

        if(curr_page > 0) {
            strcat(string, ""RED"<< Sebelumnya");
            strcat(string, "\n");
        }
        if(curr_page < max_page) {
            strcat(string, ""GREEN">> Selanjutnya");
            strcat(string, "\n");
        }

        Dialog_Show(playerid, "MargaKickMember", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Kick Marga", string, "Pilih", "Batal");
    }
    else
    {
        PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Nexston"Nexston Roleplay "WHITE"- Kick Marga", "Anda tidak memiliki member di Marga ini!", "Tutup", "");
    }
    return 1;
}

// ============================================================
// CALLBACKS
// ============================================================

forward OnMargaAdded(playerid, mid);
public OnMargaAdded(playerid, mid)
{
    Marga_Save(mid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s membuat Marga dengan ID: %d.", AccountData[playerid][pAdminname], mid);
    return 1;
}


// Dialog untuk list marga (bisa klik lihat anggota)
Dialog:MargaList(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    // Ambil ID marga dari listitem
    new mid, count;
    foreach(new m : Margas)
    {
        if(count == listitem)
        {
            mid = m;
            break;
        }
        count++;
    }
    
    if(!Iter_Contains(Margas, mid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Marga tidak ditemukan!");
    
    ShowMargaMembers(playerid, mid);
    return 1;
}

// Marga Set Rank Dialog
Dialog:MargaSetRank(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(listitem == -1) return 1;
    
    if(!strcmp(inputtext, ">> Selanjutnya", true)) 
    {
        index_pagination[playerid]++;
        new rows = TempRows[playerid];
        new max_page = ((rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS) - 1;
        if(index_pagination[playerid] >= max_page) index_pagination[playerid] = max_page;
        Show_MargaRankManage(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true)) 
    {
        index_pagination[playerid]--;
        if(index_pagination[playerid] <= 0) index_pagination[playerid] = 0;
        Show_MargaRankManage(playerid);
    }
    else
    {
        if(AccountData[playerid][pMarga] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari Marga manapun!");
        if(AccountData[playerid][pMargaRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga!");

        mysql_query(g_SQL, sprintf("SELECT * FROM `player_characters` WHERE `pID` = '%d'", ListedMember[playerid][listitem]));
        new rows = cache_num_rows();
        if(rows)
        {
            cache_get_value_name_int(0, "pID", AccountData[playerid][pTempSQLFactMemberID]);
            cache_get_value_name_int(0, "Char_MargaRank", AccountData[playerid][pTempSQLFactRank]);
            
            if(AccountData[playerid][pID] == AccountData[playerid][pTempSQLFactMemberID]) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menetapkan rank anda sendiri!");
            if(AccountData[playerid][pTempSQLFactRank] >= AccountData[playerid][pMargaRank]) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menetapkan rank rekan yang sejajar/lebih tinggi dari anda!");
            
            Dialog_Show(playerid, "MargaSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank Marga", 
                "Silahkan pilih jabatan untuk ditetapkan (masukkan angka saja):\n\
                1. Warga\n\
                2. Keluarga\n\
                3. Sesepuh\n\
                4. Penghulu\n\
                5. Wakil\n\
                6. Ketua", "Set", "Batal");
        }
    }
    return 1;
}

// Marga Set Rank Confirm
Dialog:MargaSetRankConfirm(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (AccountData[playerid][pMarga] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari Marga manapun!");
    if (AccountData[playerid][pMargaRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari Marga ini!");

    if (isnull(inputtext)) 
        return Dialog_Show(playerid, "MargaSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank Marga",
        "Error: Tidak dapat dikosongkan!\nSilahkan pilih jabatan (1-6):", "Set", "Batal");

    if (!IsNumericEx(inputtext)) 
        return Dialog_Show(playerid, "MargaSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank Marga",
        "Error: Masukkan hanya angka!\nSilahkan pilih jabatan (1-6):", "Set", "Batal");

    new rank = strval(inputtext);
    if (rank < 1 || rank > 6) 
        return Dialog_Show(playerid, "MargaSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank Marga",
        "Error: Pilihan tidak valid! (1-6)\nSilahkan pilih jabatan (1-6):", "Set", "Batal");
    
    if(rank >= AccountData[playerid][pMargaRank]) 
        return Dialog_Show(playerid, "MargaSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank Marga",
        "Error: Tidak dapat memberikan rank yang sama atau lebih tinggi dari anda!\nSilahkan pilih jabatan (1-6):", "Set", "Batal");

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_MargaRank`=%d WHERE `pID`=%d", 
        rank, AccountData[playerid][pTempSQLFactMemberID]);
    mysql_pquery(g_SQL, query);

    foreach (new i : Player)
    {
        if (AccountData[i][IsLoggedIn] && AccountData[i][pSpawned] && AccountData[playerid][pTempSQLFactMemberID] == AccountData[i][pID])
        {
            AccountData[i][pMargaRank] = rank;
            ShowTDN(i, NOTIFICATION_INFO, sprintf("Jabatan baru anda di Marga telah diubah menjadi %s", MargaRank[rank]));
        }
    }

    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengubah jabatan Marga Pemain tersebut");
    return 1;
}

// Marga Kick Member
Dialog:MargaKickMember(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if (!strcmp(inputtext, ">> Selanjutnya", true)) 
    {
        index_pagination[playerid]++;
        Show_MargaKick(playerid);
    }
    else if (!strcmp(inputtext, "<< Sebelumnya", true)) 
    {
        index_pagination[playerid]--;
        if (index_pagination[playerid] < 0) index_pagination[playerid] = 0;
        Show_MargaKick(playerid);
    }
    else 
    {
        new member_pid = ListedMember[playerid][listitem];

        if(AccountData[playerid][pMarga] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari Marga manapun!");
        if(AccountData[playerid][pMargaRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga!");

        mysql_query(g_SQL, sprintf("SELECT * FROM `player_characters` WHERE `pID` = %d", member_pid));
        new rows = cache_num_rows();
        if (rows) 
        {
            new member_name[64], member_rank, member_lastlogin[30], kickstr[225], query[128];
            cache_get_value_name(0, "Char_Name", member_name);
            cache_get_value_name_int(0, "Char_MargaRank", member_rank);
            cache_get_value_name(0, "Char_LastLogin", member_lastlogin);

            if(AccountData[playerid][pID] == member_pid) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap diri sendiri!");
            if(member_rank >= AccountData[playerid][pMargaRank]) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat kick player yang ranknya lebih tinggi atau sama dengan anda!");

            foreach(new i : Player)
            {
                if(member_pid == AccountData[i][pID])
                {
                    AccountData[i][pMarga] = -1;
                    AccountData[i][pMargaRank] = 0;
                    SendClientMessageEx(i, Y_SERVER, "(Server) "WHITE"Anda telah dikeluarkan dari Marga!");
                }
            }

            mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_Marga` = -1, `Char_MargaRank` = 0 WHERE `pID` = %d", member_pid);
            mysql_pquery(g_SQL, query);

            format(kickstr, sizeof(kickstr), "Anda berhasil mengeluarkan:\nNama: %s\nRank: %s\nLast Online: %s", 
                member_name, MargaRank[member_rank], member_lastlogin);
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Kick Marga", kickstr, "Tutup", "");
        }
    }
    return 1;
}

Dialog:MargaBosDesk(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    switch(listitem)
    {
        case 0: // Invite Member
        {
            new str[522], count = 0;
            foreach(new i : Player) if(i != playerid) if(IsPlayerNearPlayer(playerid, i, 2.5)) 
            {
                if(AccountData[i][pMarga] == -1)
                {
                    format(str, sizeof(str), "%sPlayer ID - (%d) - %s\n", str, i, ReturnName(i));
                    NearestUser[playerid][count++] = i;
                }
            }
            
            if(count == 0)
            {
                PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
                return Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Invite Marga", 
                    "Tidak ada pemain terdekat yang belum memiliki Marga!", "Tutup", "");
            }
            Dialog_Show(playerid, "MargaInviteConfirm", DIALOG_STYLE_TABLIST, "Undang ke Marga", str, "Pilih", "Batal");
        }
        case 1: // Kelola Jabatan
        {
            index_pagination[playerid] = 0;
            Show_MargaRankManage(playerid);
        }
        case 2: // Kick Member
        {
            index_pagination[playerid] = 0;
            Show_MargaKick(playerid);
        }
        case 3: // Lihat Info Marga
        {
            Show_MargaInfo(playerid);
        }
        case 4: // Deposit Uang Marga
        {
            Dialog_Show(playerid, "MargaDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang Marga", 
                "Masukkan nominal uang yang ingin disimpan ke kas Marga:", "Deposit", "Batal");
        }
        case 5: // Withdraw Uang Marga
        {
            Dialog_Show(playerid, "MargaWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang Marga", 
                "Masukkan nominal uang yang ingin diambil dari kas Marga:", "Withdraw", "Batal");
        }
    }
    return 1;
}

// Dialog Deposit Uang ke Marga
Dialog:MargaDepositMoney(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda membatalkan deposit!");
    
    new mid = AccountData[playerid][pMarga];
    if(mid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam Marga manapun!");
    if(AccountData[playerid][pMargaRank] < 5) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga!");
    
    if(isnull(inputtext)) 
        return Dialog_Show(playerid, "MargaDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang Marga", 
            "Error: Tidak boleh kosong!\nMasukkan nominal uang yang ingin disimpan ke kas Marga:", "Deposit", "Batal");
    
    if(!IsNumericEx(inputtext)) 
        return Dialog_Show(playerid, "MargaDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang Marga", 
            "Error: Masukkan angka saja!\nMasukkan nominal uang yang ingin disimpan ke kas Marga:", "Deposit", "Batal");
    
    new amount = strval(inputtext);
    if(amount < 1) 
        return Dialog_Show(playerid, "MargaDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang Marga", 
            "Error: Jumlah minimal $1!\nMasukkan nominal uang yang ingin disimpan ke kas Marga:", "Deposit", "Batal");
    
    if(amount > AccountData[playerid][pMoney]) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
    
    // Proses deposit
    TakePlayerMoneyEx(playerid, amount);
    MargaData[mid][margaMoney] += amount;
    Marga_Save(mid);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil deposit "GREEN"$%s "WHITE"ke kas Marga!", FormatMoney(amount)));
    
    // Notifikasi ke semua anggota online
    foreach(new i : Player)
    {
        if(AccountData[i][pMarga] == mid && i != playerid)
        {
            SendClientMessageEx(i, Y_SERVER, "[MARGA] %s mendeposit $%s ke kas Marga", ReturnName(playerid), FormatMoney(amount));
        }
    }
    return 1;
}

// Dialog Withdraw Uang dari Marga
Dialog:MargaWithdrawMoney(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda membatalkan withdraw!");
    
    new mid = AccountData[playerid][pMarga];
    if(mid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam Marga manapun!");
    if(AccountData[playerid][pMargaRank] < 5) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi Marga! (Minimal Wakil)");
    
    if(isnull(inputtext)) 
        return Dialog_Show(playerid, "MargaWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang Marga", 
            "Error: Tidak boleh kosong!\nMasukkan nominal uang yang ingin diambil dari kas Marga:", "Withdraw", "Batal");
    
    if(!IsNumericEx(inputtext)) 
        return Dialog_Show(playerid, "MargaWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang Marga", 
            "Error: Masukkan angka saja!\nMasukkan nominal uang yang ingin diambil dari kas Marga:", "Withdraw", "Batal");
    
    new amount = strval(inputtext);
    if(amount < 1) 
        return Dialog_Show(playerid, "MargaWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang Marga", 
            "Error: Jumlah minimal $1!\nMasukkan nominal uang yang ingin diambil dari kas Marga:", "Withdraw", "Batal");
    
    if(amount > MargaData[mid][margaMoney]) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang kas Marga tidak cukup!");
    
    // Proses withdraw
    MargaData[mid][margaMoney] -= amount;
    GivePlayerMoneyEx(playerid, amount);
    Marga_Save(mid);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil withdraw "GREEN"$%s "WHITE"dari kas Marga!", FormatMoney(amount)));
    
    // Notifikasi ke semua anggota online
    foreach(new i : Player)
    {
        if(AccountData[i][pMarga] == mid && i != playerid)
        {
            SendClientMessageEx(i, Y_SERVER, "[MARGA] %s menarik $%s dari kas Marga", ReturnName(playerid), FormatMoney(amount));
        }
    }
    return 1;
}