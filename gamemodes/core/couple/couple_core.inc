// Load couple data dari database
stock Couple_LoadPlayer(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), 
        "SELECT * FROM couple WHERE (player1_id = %d OR player2_id = %d) AND status = 1 LIMIT 1",
        AccountData[playerid][pID], AccountData[playerid][pID]);
    mysql_tquery(g_SQL, query, "OnCoupleDataLoaded", "i", playerid);
    return 1;
}

// Cek gender compatibility
stock Couple_CheckGender(playerid, targetid)
{
    if(AccountData[playerid][pGender] == AccountData[targetid][pGender])
        return 0;
    return 1;
}

// Cek apakah player punya pasangan aktif
stock Couple_HasPartner(playerid)
{
    return CoupleData[playerid][cActive];
}

// Get partner playerid (online)
stock Couple_GetPartnerID(playerid)
{
    if(!CoupleData[playerid][cActive]) return INVALID_PLAYER_ID;
    
    foreach(new i : Player)
    {
        if(AccountData[i][pID] == CoupleData[playerid][cPartnerID] && CoupleData[i][cActive])
            return i;
    }
    return INVALID_PLAYER_ID;
}

// Get partner name (dari memory atau database)
stock Couple_GetPartnerName(playerid, name[], len)
{
    if(!CoupleData[playerid][cActive])
    {
        format(name, len, "None");
        return 0;
    }
    
    new partnerID = Couple_GetPartnerID(playerid);
    if(partnerID != INVALID_PLAYER_ID)
    {
        GetPlayerName(partnerID, name, len);
    }
    else
    {
        format(name, len, "%s", CoupleData[playerid][cPartnerName]);
    }
    return 1;
}

// Update cached days
stock Couple_UpdateDays(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    new duration = Couple_GetDuration(playerid);
    CoupleData[playerid][cCoupleDays] = duration / 86400;
    return CoupleData[playerid][cCoupleDays];
}

// Format duration ke string "X hari Y jam"
stock Couple_FormatDuration(duration, output[], len)
{
    new days = duration / 86400;
    new hours = (duration % 86400) / 3600;
    
    if(days > 0)
        format(output, len, "%d hari %d jam", days, hours);
    else
        format(output, len, "%d jam", hours);
}
// ================ UPDATE DURASI KETIKA KEDUA ONLINE ================

// Fungsi untuk cek apakah kedua pasangan online
stock Couple_BothOnline(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    
    new partnerID = Couple_GetPartnerID(playerid);
    if(partnerID == INVALID_PLAYER_ID) return 0;
    
    return 1; // Kedua online
}

// Update akumulasi durasi
stock Couple_UpdateBothOnlineDuration(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    
    new partnerID = Couple_GetPartnerID(playerid);
    if(partnerID == INVALID_PLAYER_ID) return 0;
    
    new currentTime = gettime();
    
    // Jika pertama kali update setelah couple
    if(CoupleData[playerid][cLastUpdate] == 0)
    {
        CoupleData[playerid][cLastUpdate] = currentTime;
        CoupleData[partnerID][cLastUpdate] = currentTime;
        return 0;
    }
    
    // Hitung selisih waktu dari last update
    new elapsed = currentTime - CoupleData[playerid][cLastUpdate];
    
    if(elapsed > 0)
    {
        // Tambahkan ke total duration kedua player
        CoupleData[playerid][cTotalDuration] += elapsed;
        CoupleData[partnerID][cTotalDuration] += elapsed;
        
        // Update last update
        CoupleData[playerid][cLastUpdate] = currentTime;
        CoupleData[partnerID][cLastUpdate] = currentTime;
        
        // Update cached days
        CoupleData[playerid][cCoupleDays] = CoupleData[playerid][cTotalDuration] / 86400;
        CoupleData[partnerID][cCoupleDays] = CoupleData[partnerID][cTotalDuration] / 86400;
        
        // Save ke database (async)
        new query[256];
        mysql_format(g_SQL, query, sizeof(query),
            "UPDATE couple SET total_duration = %d, last_update = %d WHERE id = %d",
            CoupleData[playerid][cTotalDuration], currentTime, CoupleData[playerid][cID]);
        mysql_tquery(g_SQL, query);
    }
    
    return elapsed;
}

// Get couple duration (SEKARANG PAKAI TOTAL DURATION)
stock Couple_GetDuration(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    return CoupleData[playerid][cTotalDuration];
}

// Update fungsi CheckMilestone (gunakan total duration)
stock Couple_CheckMilestone(playerid)
{
    if(!CoupleData[playerid][cActive]) return 0;
    
    new totalSeconds = Couple_GetDuration(playerid);
    new days = totalSeconds / 86400;
    CoupleData[playerid][cCoupleDays] = days;
    
    new milestoneDelivered = 0;
    
    // Cek 30 days
    if(days >= MILESTONE_30_DAYS && !CoupleData[playerid][cReward30])
    {
        if(!Couple_IsRewardDelivered(playerid, 30))
        {
            Couple_InsertPendingReward(playerid, 30, REWARD_TYPE_VIP, "7");
            Couple_DeliverReward(playerid, 30, REWARD_TYPE_VIP, "7");
            milestoneDelivered++;
        }
    }
    
    // Cek 60 days
    if(days >= MILESTONE_60_DAYS && !CoupleData[playerid][cReward60])
    {
        if(!Couple_IsRewardDelivered(playerid, 60))
        {
            Couple_InsertPendingReward(playerid, 60, REWARD_TYPE_VIP, "14");
            Couple_DeliverReward(playerid, 60, REWARD_TYPE_VIP, "14");
            milestoneDelivered++;
        }
    }
    
    // Cek 90 days
    if(days >= MILESTONE_90_DAYS)
    {
        // VIP
        if(!CoupleData[playerid][cReward90])
        {
            if(!Couple_IsRewardDelivered(playerid, 90))
            {
                Couple_InsertPendingReward(playerid, 90, REWARD_TYPE_VIP, "30");
                Couple_DeliverReward(playerid, 90, REWARD_TYPE_VIP, "30");
                milestoneDelivered++;
            }
        }
        
        // Vehicle
        if(!CoupleData[playerid][cRewardVehicle])
        {
            if(!Couple_IsRewardDelivered(playerid, 90))
            {
                Couple_InsertPendingReward(playerid, 90, REWARD_TYPE_VEHICLE, "541");
                Couple_DeliverReward(playerid, 90, REWARD_TYPE_VEHICLE, "541");
                milestoneDelivered++;
            }
        }
    }
    
    return milestoneDelivered;
}

// Insert pending reward ke database
stock Couple_InsertPendingReward(playerid, milestone, const rewardType[], const rewardValue[])
{
    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "INSERT INTO couple_rewards (couple_id, player_id, milestone, reward_type, reward_value, delivered, created_at) \
        VALUES (%d, %d, %d, '%e', '%e', 0, %d)",
        CoupleData[playerid][cID],
        AccountData[playerid][pID],
        milestone,
        rewardType,
        rewardValue,
        gettime());
    mysql_tquery(g_SQL, query);
}

// Deliver reward langsung - PRODUCTION VERSION (tanpa printf)
stock Couple_DeliverReward(playerid, milestone, const rewardType[], const rewardValue[])
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    if(strcmp(rewardType, REWARD_TYPE_VIP) == 0)
    {
        new days = strval(rewardValue);
        new expireTime = gettime() + (days * 86400);
        
        // Set VIP
        AccountData[playerid][pVIP] = 1;
        if(AccountData[playerid][pVIPTime] < expireTime)
            AccountData[playerid][pVIPTime] = expireTime;
        
        // Save ke database
        new query[256];
        mysql_format(g_SQL, query, sizeof(query),
            "UPDATE accounts SET VipLevel = 1, VipTime = %d WHERE PlayerID = %d",
            AccountData[playerid][pVIPTime], AccountData[playerid][pID]);
        mysql_tquery(g_SQL, query);
        
        // Notifikasi
        Info(playerid, "+VIP 1 (%d Hari)", days);
        SendCustomMessage(playerid, "COUPLE", "Reward %d hari: VIP Level 1 selama %d hari!", milestone, days);
        
        // Set flag di memory
        switch(milestone)
        {
            case 30: CoupleData[playerid][cReward30] = 1;
            case 60: CoupleData[playerid][cReward60] = 1;
            case 90: CoupleData[playerid][cReward90] = 1;
        }
        
        // Update delivered di database
        new updateQuery[128];
        mysql_format(g_SQL, updateQuery, sizeof(updateQuery),
            "UPDATE couple_rewards SET delivered = 1, delivered_at = %d WHERE player_id = %d AND milestone = %d AND reward_type = '%e'",
            gettime(), AccountData[playerid][pID], milestone, rewardType);
        mysql_tquery(g_SQL, updateQuery);
    }
    else if(strcmp(rewardType, REWARD_TYPE_VEHICLE) == 0 && milestone == 90)
    {
        // Cek limit kendaraan
        if(GetPlayerVehicleLimit(playerid) <= 0)
        {
            Couple_InsertPendingReward(playerid, milestone, rewardType, rewardValue);
            Warning(playerid, "Limit kendaraan penuh, reward akan diberikan saat ada slot kosong.");
            return 0;
        }
        
        // Create Bullet (model 541)
        new modelid = strval(rewardValue);
        new pvwid, pvintid;
        new Float:x, Float:y, Float:z, Float:a;
        GetPlayerPos(playerid, x, y, z);
        GetPlayerFacingAngle(playerid, a);
        pvwid = GetPlayerVirtualWorld(playerid);
        pvintid = GetPlayerInterior(playerid);
        
        new vehID = Vehicle_Create(AccountData[playerid][pID], modelid, x + 3.0, y + 3.0, z, a, RandomEx(1, 100), RandomEx(1, 100), pvwid, pvintid);
        
        if(vehID != -1)
        {
            CoupleData[playerid][cRewardVehicle] = 1;
            
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "+Kendaraan Bullet");
            SendCustomMessage(playerid, "COUPLE", "Reward 90 hari: Kendaraan Bullet!");
            
            new updateQuery[128];
            mysql_format(g_SQL, updateQuery, sizeof(updateQuery),"UPDATE couple_rewards SET delivered = 1, delivered_at = %d WHERE player_id = %d AND milestone = %d AND reward_type = '%e'",gettime(), AccountData[playerid][pID], milestone, rewardType);
            mysql_tquery(g_SQL, updateQuery);
        }
    }
    
    return 1;
}

// Cek apakah reward sudah pernah diberikan
stock Couple_IsRewardDelivered(playerid, milestone)
{
    switch(milestone)
    {
        case 30: return CoupleData[playerid][cReward30];
        case 60: return CoupleData[playerid][cReward60];
        case 90: return (CoupleData[playerid][cReward90] || CoupleData[playerid][cRewardVehicle]);
    }
    return 0;
}

// Breakup couple
stock Couple_Breakup(playerid, bool:fromBanned = false)
{
    if(!CoupleData[playerid][cActive] && !fromBanned) return 0;
    
    new partnerID = Couple_GetPartnerID(playerid);
    new coupleID = CoupleData[playerid][cID];
    new currentTime = gettime();
    new partnerName[MAX_PLAYER_NAME];
    
    if(partnerID != INVALID_PLAYER_ID)
        GetPlayerName(partnerID, partnerName, sizeof(partnerName));
    else
        format(partnerName, sizeof(partnerName), "%s", CoupleData[playerid][cPartnerName]);
    
    // Update database
    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "UPDATE couple SET status = 0, last_breakup = %d, updated_at = %d WHERE id = %d",
        currentTime, currentTime, coupleID);
    mysql_tquery(g_SQL, query);
    
    // Reset data player 1
    if(IsPlayerConnected(playerid))
    {
        CoupleData[playerid][cActive] = 0;
        CoupleData[playerid][cPartnerID] = 0;
        CoupleData[playerid][cPartnerName][0] = EOS;
        CoupleData[playerid][cStartDate] = 0;
        CoupleData[playerid][cBreakupCooldown] = currentTime + COUPLE_BREAKUP_COOLDOWN;
        CoupleData[playerid][cCoupleDays] = 0;
        
        Iter_Remove(CoupleOnline, playerid);
        
        if(!fromBanned)
        {
            Warning(playerid, "Anda putus dengan %s. Cooldown 7 hari.", partnerName);
            ShowTDN(playerid, NOTIFICATION_WARNING, "Couple ENDED - 7 days cooldown");
        }
    }
    
    // Reset data player 2
    if(partnerID != INVALID_PLAYER_ID && IsPlayerConnected(partnerID))
    {
        CoupleData[partnerID][cActive] = 0;
        CoupleData[partnerID][cPartnerID] = 0;
        CoupleData[partnerID][cPartnerName][0] = EOS;
        CoupleData[partnerID][cStartDate] = 0;
        CoupleData[partnerID][cBreakupCooldown] = currentTime + COUPLE_BREAKUP_COOLDOWN;
        CoupleData[partnerID][cCoupleDays] = 0;
        
        Iter_Remove(CoupleOnline, partnerID);
        
        if(fromBanned)
            Warning(partnerID, "Pasangan anda kena BAN, couple dibatalkan.");
        else
            Warning(partnerID, "%s memutuskan hubungan.", ReturnName(playerid));
            
        ShowTDN(partnerID, NOTIFICATION_WARNING, "Couple ENDED");
    }
    
    return 1;
}

// OnCoupleDataLoaded
public OnCoupleDataLoaded(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new rows = cache_num_rows();
    if(rows)
    {
        new coupleID, player1_id, player2_id, start_date, last_breakup, total_duration, last_update;
        
        cache_get_value_name_int(0, "id", coupleID);
        cache_get_value_name_int(0, "player1_id", player1_id);
        cache_get_value_name_int(0, "player2_id", player2_id);
        cache_get_value_name_int(0, "start_date", start_date);
        cache_get_value_name_int(0, "last_breakup", last_breakup);
        cache_get_value_name_int(0, "total_duration", total_duration);
        cache_get_value_name_int(0, "last_update", last_update);
        
        CoupleData[playerid][cID] = coupleID;
        CoupleData[playerid][cStartDate] = start_date;
        CoupleData[playerid][cTotalDuration] = total_duration;
        CoupleData[playerid][cLastUpdate] = gettime();  // SET KE WAKTU SEKARANG SAAT LOGIN
        CoupleData[playerid][cBreakupCooldown] = last_breakup;
        CoupleData[playerid][cActive] = 1;
        CoupleData[playerid][cCoupleDays] = total_duration / 86400;
        
        // Tentukan partner ID
        if(player1_id == AccountData[playerid][pID])
        {
            CoupleData[playerid][cPartnerID] = player2_id;
            
            new query[128];
            mysql_format(g_SQL, query, sizeof(query), "SELECT Char_Name FROM player_characters WHERE pID = %d", player2_id);
            mysql_tquery(g_SQL, query, "OnLoadPartnerName", "ii", playerid, player2_id);
        }
        else
        {
            CoupleData[playerid][cPartnerID] = player1_id;
            
            new query[128];
            mysql_format(g_SQL, query, sizeof(query), "SELECT Char_Name FROM player_characters WHERE pID = %d", player1_id);
            mysql_tquery(g_SQL, query, "OnLoadPartnerName", "ii", playerid, player1_id);
        }
        
        Couple_LoadRewardFlags(playerid);
        Iter_Add(CoupleOnline, playerid);
        
        // CEK APAKAH PARTNER JUGA ONLINE
        new partnerID = Couple_GetPartnerID(playerid);
        if(partnerID != INVALID_PLAYER_ID)
        {
            // Set last update partner juga
            CoupleData[partnerID][cLastUpdate] = gettime();
            
            // Notifikasi
            SendCustomMessage(playerid, "COUPLE", "Pasangan anda %s sedang online!", ReturnName(partnerID));
            SendCustomMessage(partnerID, "COUPLE", "Pasangan anda %s telah online!", ReturnName(playerid));
        }
    }
    else
    {
        CoupleData[playerid][cActive] = 0;
    }
    
    Couple_LoadPendingRewards(playerid);
    return 1;
}

// OnLoadPartnerName
forward OnLoadPartnerName(playerid, partnerID);
public OnLoadPartnerName(playerid, partnerID)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new rows = cache_num_rows();
    if(rows)
    {
        cache_get_value_name(0, "Char_Name", CoupleData[playerid][cPartnerName], MAX_PLAYER_NAME);
    }
    else
    {
        format(CoupleData[playerid][cPartnerName], MAX_PLAYER_NAME, "Unknown_%d", partnerID);
    }
    
    return 1;
}

// Load reward flags
stock Couple_LoadRewardFlags(playerid)
{
    new query[256];
    mysql_format(g_SQL, query, sizeof(query),
        "SELECT milestone FROM couple_rewards WHERE player_id = %d AND delivered = 1",
        AccountData[playerid][pID]);
    mysql_tquery(g_SQL, query, "OnLoadRewardFlags", "i", playerid);
}

forward OnLoadRewardFlags(playerid);
public OnLoadRewardFlags(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new rows = cache_num_rows();
    for(new i = 0; i < rows; i++)
    {
        new milestone;
        cache_get_value_name_int(i, "milestone", milestone);
        
        switch(milestone)
        {
            case 30: CoupleData[playerid][cReward30] = 1;
            case 60: CoupleData[playerid][cReward60] = 1;
            case 90: CoupleData[playerid][cReward90] = 1;
        }
    }
    
    return 1;
}

// Load pending rewards
stock Couple_LoadPendingRewards(playerid)
{
    new query[256];
    mysql_format(g_SQL, query, sizeof(query),
        "SELECT * FROM couple_rewards WHERE player_id = %d AND delivered = 0",
        AccountData[playerid][pID]);
    mysql_tquery(g_SQL, query, "OnCouplePendingRewards", "i", playerid);
}

forward OnCouplePendingRewards(playerid);
public OnCouplePendingRewards(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    new rows = cache_num_rows();
    if(rows)
    {
        for(new i = 0; i < rows; i++)
        {
            new rewardID, milestone, rewardType[50], rewardValue[50];
            
            cache_get_value_name_int(i, "id", rewardID);
            cache_get_value_name_int(i, "milestone", milestone);
            cache_get_value_name(i, "reward_type", rewardType, sizeof(rewardType));
            cache_get_value_name(i, "reward_value", rewardValue, sizeof(rewardValue));
            
            Couple_DeliverReward(playerid, milestone, rewardType, rewardValue);
            
            new query[128];
            mysql_format(g_SQL, query, sizeof(query),
                "UPDATE couple_rewards SET delivered = 1, delivered_at = %d WHERE id = %d",
                gettime(), rewardID);
            mysql_tquery(g_SQL, query);
        }
        
        SendCustomMessage(playerid, "COUPLE", "Reward couple yang tertunda telah diberikan!");
    }
    
    return 1;
}