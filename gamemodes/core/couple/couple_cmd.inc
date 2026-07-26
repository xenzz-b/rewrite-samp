// couple_cmd.inc
#if defined _couple_cmd_included
    #endinput
#endif
#define _couple_cmd_included

// ================ COMMANDS ================

YCMD:propose(playerid, params[], help)
{
    if(AccountData[playerid][pKnockdown])
        return Error(playerid, "Anda tidak dapat melakukannya saat ini!");
    
    new targetid;
    if(sscanf(params, "u", targetid))
        return SUM(playerid,"/propose [playerid/PartOfName]");
    
    if(!IsPlayerConnected(targetid))
        return Error(playerid, "Player tidak online.");
    
    if(playerid == targetid)
        return Error(playerid, "Tidak bisa propose diri sendiri.");
    
    if(CoupleData[playerid][cActive])
        return Error(playerid, "Anda sudah memiliki pasangan.");
    
    if(CoupleData[targetid][cActive])
        return Error(playerid, "Target sudah memiliki pasangan.");
    
    if(!Couple_CheckGender(playerid, targetid))
        return Error(playerid, "Couple harus berbeda jenis kelamin.");
    
    if(gettime() < CoupleData[playerid][cBreakupCooldown])
    {
        new remaining = CoupleData[playerid][cBreakupCooldown] - gettime();
        new hours = remaining / 3600;
        new days = hours / 24;
        
        if(days > 0)
            Error(playerid, "Cooldown: %d hari %d jam setelah putus.", days, hours % 24);
        else
            Error(playerid, "Cooldown: %d jam setelah putus.", hours);
        return 1;
    }
    
    // Cek apakah target sedang dalam cooldown
    if(gettime() < CoupleData[targetid][cBreakupCooldown])
    {
        Error(playerid, "Target masih dalam masa cooldown putus.");
        return 1;
    }
    
    new targetName[MAX_PLAYER_NAME];
    GetPlayerName(targetid, targetName, sizeof(targetName));
    
    // Kirim proposal ke target
    new message[512];
    format(message, sizeof(message), "{FFFFFF}%s {FF69B4}melamar anda.\n\n{FFFFFF}Terima lamaran ini?", targetName);
    
    Dialog_Show(targetid, "DIALOG_COUPLE_PROPOSE", DIALOG_STYLE_MSGBOX, "{FF69B4} COUPLE PROPOSAL ", message, "Terima", "Tolak");
    
    // Simpan data proposal di memory
    CoupleData[targetid][cProposeFrom] = playerid;
    CoupleData[targetid][cProposeTime] = gettime();
    
    Info(playerid, "%s melamar anda. Gunakan /acceptcouple atau /decline couple.", targetName);
    Info(playerid, "Lamaran Masuk!");
    
    Info(playerid, "Lamaran ke %s terkirim.", targetName);
    Info(playerid, "Lamaran Terkirim");
    
    return 1;
}

YCMD:acceptcouple(playerid, params[], help)
{
    #pragma unused params  // Tambahkan ini untuk menghilangkan warning
    
    // HAPUS baris if(isnull(params)) return 0; karena tidak diperlukan
    
    new proposer = CoupleData[playerid][cProposeFrom];
    
    if(proposer == INVALID_PLAYER_ID)  // Tambahkan validasi
        return Error(playerid, "Tidak ada lamaran yang masuk.");
    
    if(!IsPlayerConnected(proposer))
        return Error(playerid, "Player yang melamar anda sudah offline.");
    
    if(CoupleData[playerid][cActive] || CoupleData[proposer][cActive])
        return Error(playerid, "Salah satu sudah memiliki pasangan.");
    
    // Insert ke database
    new query[512];
    new currentTime = gettime();
    
    mysql_format(g_SQL, query, sizeof(query),
        "INSERT INTO couple (player1_id, player2_id, start_date, status, created_at, updated_at) \
        VALUES (%d, %d, %d, 1, %d, %d)",
        AccountData[proposer][pID], AccountData[playerid][pID], 
        currentTime, currentTime, currentTime);
    mysql_tquery(g_SQL, query, "OnCoupleCreated", "ii", proposer, playerid);
    
    return 1;
}

forward OnCoupleCreated(proposer, acceptor);
public OnCoupleCreated(proposer, acceptor)
{
    new coupleID = cache_insert_id();
    
    if(!IsPlayerConnected(proposer) || !IsPlayerConnected(acceptor))
        return 0;
    
    new propName[MAX_PLAYER_NAME], accName[MAX_PLAYER_NAME];
    GetPlayerName(proposer, propName, sizeof(propName));
    GetPlayerName(acceptor, accName, sizeof(accName));
    
    new currentTime = gettime();
    
    // Set data proposer
    CoupleData[proposer][cID] = coupleID;
    CoupleData[proposer][cPartnerID] = AccountData[acceptor][pID];
    format(CoupleData[proposer][cPartnerName], MAX_PLAYER_NAME, "%s", accName);
    CoupleData[proposer][cStartDate] = currentTime;
    CoupleData[proposer][cTotalDuration] = 0;
    CoupleData[proposer][cLastUpdate] = currentTime;  // Set last update ke waktu sekarang
    CoupleData[proposer][cActive] = 1;
    CoupleData[proposer][cBreakupCooldown] = 0;
    CoupleData[proposer][cCoupleDays] = 0;
    Iter_Add(CoupleOnline, proposer);
    
    // Set data acceptor
    CoupleData[acceptor][cID] = coupleID;
    CoupleData[acceptor][cPartnerID] = AccountData[proposer][pID];
    format(CoupleData[acceptor][cPartnerName], MAX_PLAYER_NAME, "%s", propName);
    CoupleData[acceptor][cStartDate] = currentTime;
    CoupleData[acceptor][cTotalDuration] = 0;
    CoupleData[acceptor][cLastUpdate] = currentTime;  // Set last update ke waktu sekarang
    CoupleData[acceptor][cActive] = 1;
    CoupleData[acceptor][cBreakupCooldown] = 0;
    CoupleData[acceptor][cCoupleDays] = 0;
    Iter_Add(CoupleOnline, acceptor);
    
    // Clear proposal
    CoupleData[acceptor][cProposeFrom] = INVALID_PLAYER_ID;
    CoupleData[acceptor][cProposeTime] = 0;
    
    // Notifikasi
    Success(proposer, "Anda sekarang berpasangan dengan %s!", accName);
    Success(acceptor, "Anda sekarang berpasangan dengan %s!", propName);
    
    Success(proposer, "Couple ACTIVE!");
    Success(acceptor, "Couple ACTIVE!");
    
    SendCustomMessage(proposer, "COUPLE", "Mulai hitung hari untuk dapat reward spesial! (Hitung saat bersama online)");
    SendCustomMessage(acceptor, "COUPLE", "Mulai hitung hari untuk dapat reward spesial! (Hitung saat bersama online)");
    
    return 1;
}

YCMD:decline(playerid, params[], help)
{
    if(isnull(params)) return 0;
    
    if(strcmp(params, "couple", true) != 0)
        return 0;
    
    new proposer = CoupleData[playerid][cProposeFrom];
    
    if(!IsPlayerConnected(proposer))
        return Error(playerid, "Player yang melamar anda sudah offline.");
    
    Warning(proposer, "%s menolak lamaran anda.", ReturnName(playerid));
    ShowTDN(proposer, NOTIFICATION_WARNING, "Lamaran Ditolak");
    
    Info(playerid, "Anda menolak lamaran tersebut.");
    Info(playerid, "Lamaran Ditolak");
    
    CoupleData[playerid][cProposeFrom] = INVALID_PLAYER_ID;
    CoupleData[playerid][cProposeTime] = 0;
    
    return 1;
}

YCMD:breakup(playerid, params[], help)
{
    #pragma unused params
    
    if(!CoupleData[playerid][cActive])
        return Error(playerid, "Anda tidak memiliki pasangan.");
    
    new partner = Couple_GetPartnerID(playerid);
    new partnerName[MAX_PLAYER_NAME];
    
    if(partner != INVALID_PLAYER_ID)
        GetPlayerName(partner, partnerName, sizeof(partnerName));
    else
        format(partnerName, sizeof(partnerName), "%s", CoupleData[playerid][cPartnerName]);
    
    new message[512];
    format(message, sizeof(message), 
        "{FF4444}PERHATIAN!{FFFFFF}\n\n\
        Anda akan PUTUS dengan {FF69B4}%s{FFFFFF}.\n\
        {FFFF00}KONSEKUENSI:{FFFFFF}\n\
        - Progress couple RESET\n\
        - Cooldown 7 HARI\n\
        - Reward tetap ADA\n\n\
        YAKIN?",
        partnerName);
    
    Dialog_Show(playerid, "DIALOG_COUPLE_BREAKUP", DIALOG_STYLE_MSGBOX, "{FF69B4} PUTUSKAN HUBUNGAN ", message, "YA PUTUS", "BATAL");
    
    return 1;
}

YCMD:coupleInfo(playerid, params[], help)
{
    #pragma unused params
    
    if(!CoupleData[playerid][cActive])
    {
        // Tampilkan cooldown jika ada
        if(gettime() < CoupleData[playerid][cBreakupCooldown])
        {
            new remaining = CoupleData[playerid][cBreakupCooldown] - gettime();
            new days = remaining / 86400;
            new hours = (remaining % 86400) / 3600;
            
            new info[512];
            format(info, sizeof(info),
                "{FF69B4}[ COOLDOWN INFO ]{FFFFFF}\n\n\
                Status: {FFFF00}COOLDOWN{FFFFFF}\n\
                Sisa waktu: {FFFF00}%d hari %d jam{FFFFFF}\n\n\
                Anda bisa melamar lagi setelah cooldown selesai.",
                days, hours);
            
            Dialog_Show(playerid, "DIALOG_COUPLE_INFO", DIALOG_STYLE_MSGBOX, "{FF69B4} COUPLE INFO ", info, "Tutup", "");
        }
        else
        {
            Info(playerid, "Anda belum memiliki pasangan. Gunakan /propose untuk melamar.");
        }
        return 1;
    }
    
    // Tampilkan dialog coupleinfo dengan 3 tab
    ShowCoupleInfoDialog(playerid);
    return 1;
}

// couple_cmd.inc - Tambahkan command untuk cek status
YCMD:coupletest(playerid, params[], help)
{
    #pragma unused params
    
    if(!CoupleData[playerid][cActive])
        return Error(playerid, "Anda tidak memiliki pasangan.");
    
    new duration = Couple_GetDuration(playerid);
    new minutes = duration / 60;
    new detik = duration;
    
    SendClientMessage(playerid, -1, "=== COUPLE DEBUG INFO ===");
    SendClientMessage(playerid, -1, sprintf("Durasi: %d detik (%d menit)", detik, minutes));
    SendClientMessage(playerid, -1, sprintf("Target 30: %d menit", MILESTONE_30_DAYS));
    SendClientMessage(playerid, -1, sprintf("Target 60: %d menit", MILESTONE_60_DAYS));
    SendClientMessage(playerid, -1, sprintf("Target 90: %d menit", MILESTONE_90_DAYS));
    SendClientMessage(playerid, -1, sprintf("Reward30: %s", CoupleData[playerid][cReward30] ? "CLAIMED" : "BELUM"));
    SendClientMessage(playerid, -1, sprintf("Reward60: %s", CoupleData[playerid][cReward60] ? "CLAIMED" : "BELUM"));
    SendClientMessage(playerid, -1, sprintf("Reward90VIP: %s", CoupleData[playerid][cReward90] ? "CLAIMED" : "BELUM"));
    SendClientMessage(playerid, -1, sprintf("RewardCar: %s", CoupleData[playerid][cRewardVehicle] ? "CLAIMED" : "BELUM"));
    
    return 1;
}

// couple_cmd.inc - Tambahkan command /chelp

YCMD:chelp(playerid, params[], help)
{
    #pragma unused params
    
    new info[2048];
    
    // Header
    strcat(info, "{FF69B4}=== COUPLE SYSTEM HELP ===\n\n");
    
    // Command List
    strcat(info, "{FFFF00}Command List:\n");
    strcat(info, "{FFFFFF}/propose [playerid] {FF69B4}- Melamar pemain lain\n");
    strcat(info, "{FFFFFF}/acceptcouple {FF69B4}- Menerima lamaran\n");
    strcat(info, "{FFFFFF}/decline couple {FF69B4}- Menolak lamaran\n");
    strcat(info, "{FFFFFF}/breakup {FF69B4}- Memutuskan hubungan (konfirmasi)\n");
    strcat(info, "{FFFFFF}/coupleinfo {FF69B4}- Informasi couple dan milestone\n");
    strcat(info, "{FFFFFF}/chelp {FF69B4}- Menampilkan help ini\n\n");
    
    // Info Penting
    strcat(info, "{FFFF00}Info Penting:\n");
    strcat(info, "{FFFFFF}- {FF69B4}Gender{FFFFFF}: Couple harus berbeda jenis kelamin\n");
    strcat(info, "{FFFFFF}- {FF69B4}Cooldown{FFFFFF}: 7 hari setelah putus\n");
    strcat(info, "{FFFFFF}- {FF69B4}Durasi{FFFFFF}: Dihitung hanya saat kedua online\n");
    strcat(info, "{FFFFFF}- {FF69B4}Reward{FFFFFF}: Diberikan otomatis ke kedua pasangan\n\n");
    
    // Milestone Rewards
    strcat(info, "{FFFF00}Milestone Rewards:\n");
    strcat(info, "{FFFFFF}30 hari{FFFFFF} bersama : {00FF7F}VIP Level 1 (7 hari)\n");
    strcat(info, "{FFFFFF}60 hari{FFFFFF} bersama : {00FF7F}VIP Level 1 (14 hari)\n");
    strcat(info, "{FFFFFF}90 hari{FFFFFF} bersama : {00FF7F}VIP Level 1 (30 hari) + {FFFF00}Kendaraan Bullet\n\n");
    
    // Status Warna
    strcat(info, "{FFFF00}Status Warna di /coupleinfo:\n");
    strcat(info, "{00FF7F}CLAIMED{FFFFFF} - Reward sudah diambil\n");
    strcat(info, "{FFFF00}READY{FFFFFF} - Reward siap diambil (mencapai milestone)\n");
    strcat(info, "{FF4444}LOCKED{FFFFFF} - Belum mencapai milestone\n");
    Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "{FF69B4} [ COUPLE HELP ] ", info, "Tutup", "");
    
    return 1;
}