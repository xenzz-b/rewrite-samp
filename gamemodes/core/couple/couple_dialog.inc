stock ShowCoupleInfoDialog(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    
    new partnerID = Couple_GetPartnerID(playerid);
    new partnerName[MAX_PLAYER_NAME];
    new partnerStatus[32];
    
    if(partnerID != INVALID_PLAYER_ID)
    {
        GetPlayerName(partnerID, partnerName, sizeof(partnerName));
        partnerStatus = "{00FF7F}ONLINE";
    }
    else
    {
        format(partnerName, sizeof(partnerName), "%s", CoupleData[playerid][cPartnerName]);
        partnerStatus = "{FF4444}OFFLINE";
    }
    
    new totalSeconds = Couple_GetDuration(playerid);
    new days = totalSeconds / 86400;
    new hours = (totalSeconds % 86400) / 3600;
    CoupleData[playerid][cCoupleDays] = days;
    
    // Format tanggal dan durasi
    new startDateStr[30];
    format(startDateStr, sizeof(startDateStr), "%s", ReturnDateNoTime(CoupleData[playerid][cStartDate]));
    
    new durationStr[32];
    if(days > 0)
        format(durationStr, sizeof(durationStr), "%d hari %d jam", days, hours);
    else if(hours > 0)
        format(durationStr, sizeof(durationStr), "%d jam", hours);
    else
        format(durationStr, sizeof(durationStr), "%d menit", totalSeconds / 60);
    
    // HEADER INFO
    new info[1024];
    strcat(info, "{FF69B4}=== COUPLE INFORMATION ===\n\n");
    strcat(info, sprintf("{FFFFFF}Partner\t: {FF69B4}%s %s\n", partnerName, partnerStatus));
    strcat(info, sprintf("{FFFFFF}Since\t: {FFFF00}%s\n", startDateStr));
    strcat(info, sprintf("{FFFFFF}Together\t: {FFFF00}%s\n", durationStr));
    strcat(info, sprintf("{FFFFFF}Status\t: {00FF7F}ACTIVE\n\n"));
    
    strcat(info, "{FF69B4}=== MILESTONE PROGRESS ===\n");
    strcat(info, "{FFFF00}(Hitung hanya saat bersama online)\n");
    
    // 30 Days
    new status30[50];
    if(CoupleData[playerid][cReward30])
        format(status30, sizeof(status30), "{00FF7F}CLAIMED");
    else if(days >= 30)
        format(status30, sizeof(status30), "{FFFF00}READY");
    else
        format(status30, sizeof(status30), "{FF4444}LOCKED");
    
    strcat(info, sprintf("{FFFFFF}30 Days \t: {FFFF00}%d/30\t%s\n", (days >= 30) ? 30 : days, status30));
    
    // 60 Days
    new status60[50];
    if(CoupleData[playerid][cReward60])
        format(status60, sizeof(status60), "{00FF7F}CLAIMED");
    else if(days >= 60)
        format(status60, sizeof(status60), "{FFFF00}READY");
    else
        format(status60, sizeof(status60), "{FF4444}LOCKED");
    
    strcat(info, sprintf("{FFFFFF}60 Days \t: {FFFF00}%d/60\t%s\n", (days >= 60) ? 60 : days, status60));
    
    // 90 Days VIP
    new status90vip[50];
    if(CoupleData[playerid][cReward90])
        format(status90vip, sizeof(status90vip), "{00FF7F}CLAIMED");
    else if(days >= 90)
        format(status90vip, sizeof(status90vip), "{FFFF00}READY");
    else
        format(status90vip, sizeof(status90vip), "{FF4444}LOCKED");
    
    strcat(info, sprintf("{FFFFFF}90 VIP \t: {FFFF00}%d/90\t%s\n", (days >= 90) ? 90 : days, status90vip));
    
    // 90 Days Vehicle
    new status90veh[50];
    if(CoupleData[playerid][cRewardVehicle])
        format(status90veh, sizeof(status90veh), "{00FF7F}CLAIMED");
    else if(days >= 90)
        format(status90veh, sizeof(status90veh), "{FFFF00}READY");
    else
        format(status90veh, sizeof(status90veh), "{FF4444}LOCKED");
    
    strcat(info, sprintf("{FFFFFF}90 Car \t: {FFFF00}%d/90\t%s\n\n", (days >= 90) ? 90 : days, status90veh));
    
    strcat(info, "{FF69B4}----------------------------\n");
    strcat(info, "{FFFF00}Klik 'Lihat History' untuk melihat reward yang sudah diterima\n");
    
    Dialog_Show(playerid, "DIALOG_COUPLE_INFO", DIALOG_STYLE_MSGBOX, 
        "{FF69B4} [ COUPLE INFO ] ", info, "Lihat History", "Tutup");
    
    return 1;
}

// ================ REWARD HISTORY DIALOG ================

stock ShowCoupleRewardHistory(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    
    // Query reward history
    new query[256];
    mysql_format(g_SQL, query, sizeof(query),
        "SELECT * FROM couple_rewards WHERE player_id = %d AND delivered = 1 ORDER BY delivered_at DESC",
        AccountData[playerid][pID]);
    mysql_tquery(g_SQL, query, "OnShowRewardHistory", "i", playerid);
    
    return 1;
}

forward OnShowRewardHistory(playerid);
public OnShowRewardHistory(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new rows = cache_num_rows();
    new info[2048] = "{FF69B4}=== REWARD HISTORY ===\n\n";
    
    if(rows)
    {
        strcat(info, "{FFFF00}Reward\t\tTanggal\n");
        strcat(info, "{FF69B4}-----------------------------\n");
        
        for(new i = 0; i < rows && i < 10; i++)
        {
            new milestone, rewardType[50], deliveredAt, dateStr[30];
            
            cache_get_value_name_int(i, "milestone", milestone);
            cache_get_value_name(i, "reward_type", rewardType, sizeof(rewardType));
            cache_get_value_name_int(i, "delivered_at", deliveredAt);
            
            format(dateStr, sizeof(dateStr), "%s", ReturnDateNoTime(deliveredAt));
            
            if(strcmp(rewardType, REWARD_TYPE_VIP) == 0)
            {
                strcat(info, sprintf("{FFFFFF}VIP %d Hari\t{00FF7F}%s\n", milestone, dateStr));
            }
            else
            {
                strcat(info, sprintf("{FFFFFF}Bullet\t{00FF7F}%s\n", dateStr));
            }
        }
    }
    else
    {
        strcat(info, "{FFFFFF}Belum ada reward yang diterima.");
    }
    
    strcat(info, "\n{FF69B4}-----------------------------\n");
    strcat(info, "{FFFF00}Klik 'Kembali' untuk ke menu utama");
    
    Dialog_Show(playerid, "DIALOG_COUPLE_REWARDS", DIALOG_STYLE_MSGBOX,
        "{FF69B4} [ REWARD HISTORY ] ", info, "Kembali", "Tutup");
    
    return 1;
}

// ================ DIALOG RESPONSE HANDLER ================

// Dialog untuk proposal lamaran
Dialog:DIALOG_COUPLE_PROPOSE(playerid, response, listitem, inputtext[])
{
    new proposer = CoupleData[playerid][cProposeFrom];
    if(!response)
    {
        if(IsPlayerConnected(proposer))
        {
            Warning(proposer, "%s menolak lamaran anda.", ReturnName(playerid));
        }
        CoupleData[playerid][cProposeFrom] = INVALID_PLAYER_ID;
        CoupleData[playerid][cProposeTime] = 0;
        return 1;
    }
    return 1;
}

// Dialog untuk putus
Dialog:DIALOG_COUPLE_BREAKUP(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    if(!CoupleData[playerid][cActive])
        return Error(playerid, "Anda sudah tidak memiliki pasangan.");
    
    Couple_Breakup(playerid);
    return 1;
}

// Dialog info couple
Dialog:DIALOG_COUPLE_INFO(playerid, response, listitem, inputtext[])
{
    if(response) // Klik "Lihat History"
    {
        ShowCoupleRewardHistory(playerid);
    }
    return 1;
}

// Dialog reward history
Dialog:DIALOG_COUPLE_REWARDS(playerid, response, listitem, inputtext[])
{
    if(response) // Klik "Kembali"
    {
        ShowCoupleInfoDialog(playerid);
    }
    return 1;
}