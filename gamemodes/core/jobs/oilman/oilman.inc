#include <YSI_Coding\y_hooks>

IsPlayerInTakeOilArea(playerid)
{
    for(new x; x < sizeof(__g_OilTakePos); x++)
    {
        if(IsPlayerInDynamicArea(playerid, Oilman_TakeOilArea[x]))
        {
            return 1;
        }
    }
    return 0;
}

CheckOilmanTimer(playerid)
{
    if(pTakingOilTimer[playerid]) return 1;
    else if(pRefiningOilTimer[playerid]) return 1;
    else if(pMixingOilTimer[playerid]) return 1;

    return 0;
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(AccountData[playerid][pJob] == JOB_OILMAN && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        for(new x; x < sizeof(__g_OilTakePos); x++)
        {
            if(areaid == Oilman_TakeOilArea[x])
            {
                ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk ambil Minyak");
            }
        }
        if(areaid == Oilman_RefineArea)
        {
            ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk saring Minyak");
        }
        if(areaid == Oilman_MixArea)
        {
            ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk olah Minyak");
        }
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    for(new x; x < sizeof(__g_OilTakePos); x++)
    {
        if(areaid == Oilman_TakeOilArea[x])
        {
            PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
            HideNotifBox(playerid);
        }
    }
    if(areaid == Oilman_RefineArea)
    {
        PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
        HideNotifBox(playerid);
    }
    if(areaid == Oilman_MixArea)
    {
        PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
        HideNotifBox(playerid);
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        for(new x; x < sizeof(__g_OilTakePos); x++)
        {
            if(IsPlayerInDynamicArea(playerid, Oilman_TakeOilArea[x]))
            {
                if(AccountData[playerid][pJob] != JOB_OILMAN) return 1;
                if(AccountData[playerid][pKnockdown]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat ini!");
                if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!");

                new Float:countingtotalweight;
                countingtotalweight = GetTotalWeightFloat(playerid) + float(2 * GetItemWeight("Minyak Bumi"))/1000;
                if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda telah penuh!");

                AccountData[playerid][pActivityTime] = 1;
                pTakingOilTimer[playerid] = true;
                PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENGAMBIL");
                ShowProgressBar(playerid);

                ApplyAnimation(playerid,"BD_FIRE","wash_up",4.1, true, false, false, false, 0, true);

                HideNotifBox(playerid);
            }
        }

        if(IsPlayerInDynamicArea(playerid, Oilman_RefineArea))
        {
            if(AccountData[playerid][pJob] != JOB_OILMAN) return 1;
            if(AccountData[playerid][pKnockdown]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat ini!");
            if(Inventory_Count(playerid, "Minyak Bumi") < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki cukup Minyak Bumi! (Min: 5)");
            if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!");

            new Float:countingtotalweight;
			countingtotalweight = GetTotalWeightFloat(playerid) + float(5 * GetItemWeight("Minyak Saringan"))/1000;
			if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");

            AccountData[playerid][pActivityTime] = 1;
            pRefiningOilTimer[playerid] = true;
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENYARING");
            ShowProgressBar(playerid);

            ApplyAnimation(playerid,"BD_FIRE","wash_up",4.1, true, false, false, false, 0, true);

            HideNotifBox(playerid);
        }

        if(IsPlayerInDynamicArea(playerid, Oilman_MixArea))
        {
            if(AccountData[playerid][pJob] != JOB_OILMAN) return 1;
            if(AccountData[playerid][pKnockdown]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat ini!");
            if(Inventory_Count(playerid, "Minyak Saringan") < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki cukup Minyak Saringan! (Min: 5)");
            if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!");
            if(GetTotalWeightFloat(playerid) > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");

            AccountData[playerid][pActivityTime] = 1;
            pMixingOilTimer[playerid] = true;
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENGOLAH");
            ShowProgressBar(playerid);

            ApplyAnimation(playerid,"BD_FIRE","wash_up",4.1, true, false, false, false, 0, true);

            HideNotifBox(playerid);
        }
    }
    return 1;
}