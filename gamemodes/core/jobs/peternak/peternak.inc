#include <YSI_Coding\y_hooks>

enum E_SUSUSTUFF
{
    STREAMER_TAG_AREA:MilkerTakeArea,
    STREAMER_TAG_OBJECT:CowObject,
    MilkTaken
};
new PlayerMilkerVars[MAX_PLAYERS][E_SUSUSTUFF];

new Float: CowSpawn[][6] = {
    {261.215270, 1151.502197, 10.078562, 0.000000, 0.000000, 90.000000},
    {252.415344, 1148.472045, 10.368563, 0.000000, 0.000000, 47.900020},
    {244.933212, 1148.022705, 10.788566, 0.000000, 0.000000, 47.900020},
    {241.809951, 1134.065673, 10.308563, 0.000000, 0.000000, -97.199958},
    {237.921478, 1139.840332, 10.738560, 0.000000, 0.000000, 91.100044},
    {238.131301, 1128.912475, 10.218559, 0.000000, 0.000000, 34.100036},
    {251.585723, 1128.927612, 9.508566, 0.000000, 0.000000, 91.500007},
    {258.634582, 1124.100585, 9.568570, 0.000000, 0.000000, 91.500007}
};

IsPlayerInMilkerProcess(playerid)
{
    for(new x; x < sizeof(__g_MilkProcessPos); x++)
    {
        if(IsPlayerInDynamicArea(playerid, MilkerProcessArea[x]))
        {
            return 1;
        }
    }
    return 0;
}

CheckMilkerTimer(playerid)
{
    if(pTakingSusuTimer[playerid]) return 1;
    else if(pProcessSusuTimer[playerid]) return 1;
    return 0;
}

Dialog:StartPeternak(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    switch(listitem)
    {
        case 0:
        {
            new rand = random(sizeof(CowSpawn));
            if(DestroyDynamicObject(PlayerMilkerVars[playerid][CowObject]))
                PlayerMilkerVars[playerid][CowObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
            if(DestroyDynamicArea(PlayerMilkerVars[playerid][MilkerTakeArea]))
                PlayerMilkerVars[playerid][MilkerTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
            PlayerMilkerVars[playerid][MilkTaken] = 0;
            PlayerMilkerVars[playerid][CowObject] = CreateDynamicObject(19833, CowSpawn[rand][0], CowSpawn[rand][1], CowSpawn[rand][2], CowSpawn[rand][3], CowSpawn[rand][4], CowSpawn[rand][5], 0, 0, playerid, 300.00, 300.00); 
            PlayerMilkerVars[playerid][MilkerTakeArea] = CreateDynamicSphere(CowSpawn[rand][0], CowSpawn[rand][1], CowSpawn[rand][2], 2.2, 0, 0, playerid);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil memulai pekerjaan");

            if(AccountData[playerid][pGender] == 1)
            {
                AccountData[playerid][pUniform] = 161;
            }
            else
            {
                AccountData[playerid][pUniform] = 198;
            }
            SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
        }
        case 1:
        {
            if(DestroyDynamicObject(PlayerMilkerVars[playerid][CowObject]))
                PlayerMilkerVars[playerid][CowObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
            if(DestroyDynamicArea(PlayerMilkerVars[playerid][MilkerTakeArea]))
                PlayerMilkerVars[playerid][MilkerTakeArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
            PlayerMilkerVars[playerid][MilkTaken] = 0;
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil menyelesaikan pekerjaan");

            AccountData[playerid][pIsUsingUniform] = false;
		    SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
        }
    }
    return 1;
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(AccountData[playerid][pJob] == JOB_MILKER && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
        if(areaid == PlayerMilkerVars[playerid][MilkerTakeArea])
        {
            ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk perah Susu");
        }

        for(new x; x < sizeof(__g_MilkProcessPos); x++)
        {
            if(areaid == MilkerProcessArea[x])
            {
                ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk olah Susu");
            }
        }
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(areaid == PlayerMilkerVars[playerid][MilkerTakeArea])
    {
        HideNotifBox(playerid);
        PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
    }

    for(new x; x < sizeof(__g_MilkProcessPos); x++)
    {
        if(areaid == MilkerProcessArea[x])
        {
            HideNotifBox(playerid);
            PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
        }
    }
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.5, 303.0617,1138.4205,8.5859))
        {
            if(AccountData[playerid][pJob] != JOB_MILKER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan seorang Peternak!");

            HideNotifBox(playerid);
            Dialog_Show(playerid, "StartPeternak", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Peternak", 
            "Mulai perah susu\n\
            "GRAY"Selesaikan pekerjaan", "Pilih", "Batal");
        }

        if(IsPlayerInDynamicArea(playerid, PlayerMilkerVars[playerid][MilkerTakeArea]))
        {
            if(AccountData[playerid][pJob] != JOB_MILKER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan seorang Peternak!");
            if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!");
            
            new Float:countingtotalweight;
            countingtotalweight = GetTotalWeightFloat(playerid) + float(5 * GetItemWeight("Susu"))/1000;
            if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda telah penuh!");

            AccountData[playerid][pActivityTime] = 1;
            pTakingSusuTimer[playerid] = true;
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMERAH SUSU");
            ShowProgressBar(playerid);
            ApplyAnimation(playerid,"BOMBER","BOM_Plant",4.0, 1, 0, 0, 0, 0, 1);

            HideNotifBox(playerid);
        }

        if(IsPlayerInMilkerProcess(playerid))
        {
            if(AccountData[playerid][pJob] != JOB_MILKER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan seorang Peternak!");
            if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!");
            
            if(Inventory_Count(playerid, "Susu") < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda perlu 5x Susu!");
            
            new Float:countingtotalweight;
            countingtotalweight = GetTotalWeightFloat(playerid) + float(10 * GetItemWeight("Susu Fermentasi"))/1000;
            if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda telah penuh!");

            AccountData[playerid][pActivityTime] = 1;
            pProcessSusuTimer[playerid] = true;
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENGOLAH");
            ShowProgressBar(playerid);
            ApplyAnimation(playerid,"BD_FIRE","wash_up",4.1, true, false, false, false, 0, true);

            HideNotifBox(playerid);
        }
    }
    return 1;
}