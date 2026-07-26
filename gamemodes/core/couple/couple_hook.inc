#include <YSI_Coding\y_hooks>

task CoupleBothOnlineUpdate[60000]()
{
    foreach(new i : CoupleOnline)
    {
        if(CoupleData[i][cActive])
        {
            // Cek apakah kedua online
            new partnerID = Couple_GetPartnerID(i);
            if(partnerID != INVALID_PLAYER_ID)
            {
                // Update durasi untuk kedua player
                Couple_UpdateBothOnlineDuration(i);
                
                // Cek milestone setelah update durasi
                Couple_CheckMilestone(i);
            }
        }
    }
    return 1;
}

// Timer setiap 1 jam untuk cek reward (tetap ada)
task CoupleRewardCheck[3600000]()
{
    foreach(new i : CoupleOnline)
    {
        if(CoupleData[i][cActive])
        {
            Couple_CheckMilestone(i);
        }
    }
    return 1;
}
hook OnGameModeInit()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        CoupleData[i][cActive] = 0;
        CoupleData[i][cProposeFrom] = INVALID_PLAYER_ID;
        CoupleData[i][cProposeTime] = 0;
        CoupleData[i][cDialogTick] = 0;
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    CoupleData[playerid][cActive] = 0;
    CoupleData[playerid][cID] = 0;
    CoupleData[playerid][cPartnerID] = 0;
    CoupleData[playerid][cPartnerName][0] = EOS;
    CoupleData[playerid][cStartDate] = 0;
    CoupleData[playerid][cBreakupCooldown] = 0;
    CoupleData[playerid][cCoupleDays] = 0;
    CoupleData[playerid][cLastRewardCheck] = 0;
    CoupleData[playerid][cReward30] = 0;
    CoupleData[playerid][cReward60] = 0;
    CoupleData[playerid][cReward90] = 0;
    CoupleData[playerid][cRewardVehicle] = 0;
    CoupleData[playerid][cProposeFrom] = INVALID_PLAYER_ID;
    CoupleData[playerid][cProposeTime] = 0;
    CoupleData[playerid][cDialogTick] = 0;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(CoupleData[playerid][cActive])
    {
        new partnerID = Couple_GetPartnerID(playerid);
        
        // Update last update untuk yang masih online
        if(partnerID != INVALID_PLAYER_ID)
        {
            CoupleData[partnerID][cLastUpdate] = gettime();
            
            // Notifikasi partner bahwa pasangan offline
            SendCustomMessage(partnerID, "COUPLE", "Pasangan anda %s telah offline.", ReturnName(playerid));
        }
        
        Iter_Remove(CoupleOnline, playerid);
    }
    
    // Clean up
    CoupleData[playerid][cProposeFrom] = INVALID_PLAYER_ID;
    CoupleData[playerid][cProposeTime] = 0;
    CoupleData[playerid][cDialogTick] = 0;
    return 1;
}


hook OnPlayerBan(playerid, const ip[], const reason[], const admin[])
{
    if(CoupleData[playerid][cActive])
        Couple_Breakup(playerid, true);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    if(CoupleData[playerid][cActive])
    {
        Couple_UpdateDays(playerid);
        Couple_CheckMilestone(playerid);
    }
    return 1;
}