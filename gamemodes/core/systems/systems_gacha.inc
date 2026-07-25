#include <YSI_Coding\y_hooks>

new PlayerText: GachaVRP[MAX_PLAYERS][32];

enum e_GachaItem
{
    gItemName[32],
    gItemType, 
    gItemValue,   
    gItemAmounts2, 
    gItemRarity,  
    gPreviewModel  
}
enum e_PlayerGacha
{
    bool:pGachaSpinning,
    pGachaTimer,
    pGachaSpinCount,
    pGachaResultIndex,
    pGachaSlowdownFrame,
    pGachaCurrentDelay,
    pGachaLastIndex,
    pGachaSpinCounter
}

new PlayerGachaData[MAX_PLAYERS][e_PlayerGacha];
new const g_GachaItems[][e_GachaItem] = 
{
    {"Kayu 5", 1, 0, 5, 1, 19793},
    {"Batu 5", 1, 0, 5, 1, 3930},
    {"Chicken BBQ 10x", 1, 0, 10, 1, 2355},
    {"Coconut Water 10x", 1, 0, 10, 1, 19564},

    {"Uang Random", 4, 0, 0, 2, 1212},
    {"Ticket Gacha", 1, 0, 1, 2, 19792},

    {"VIP 1 3 Day", 3, 3, 0, 3, 18873},
    {"VIP 1 5 Day", 3, 5, 0, 3, 18873},
    {"VIP 1 7 Day", 3, 7, 0, 3, 18873},

    {"Infernus", 2, 411, 0, 4, 411},
    {"NRG-500", 2, 522, 0, 4, 522},
    {"Turismo", 2, 451, 0, 4, 451},
    {"Cheetah", 2, 415, 0, 4, 415},
    {"Super GT", 2, 506, 0, 4, 506},
    {"Bullet", 2, 426, 0, 4, 426}
};

#define GACHA_COLOR_COMMON      0xFFFFFFFF
#define GACHA_COLOR_UNCOMMON    0x33FF33FF
#define GACHA_COLOR_RARE        0x3399FFFF
#define GACHA_COLOR_EPIC        0xCC33FFFF

forward Gacha_Spin(playerid);
forward Gacha_SpinAnimation(playerid);
forward Gacha_GetRandomItem(playerid);
forward Gacha_GiveReward(playerid, itemIndex);

YCMD:gacha(playerid, params[], help)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        return 1;

    if(!PlayerHasItem(playerid, "Ticket Gacha"))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "You don't have any Gacha Ticket!");

    HideServerNameTD(playerid);
	//HideStatsTD(playerid);
	HideSpeedoTD(playerid);
	HideHBETD(playerid);
	HideRadioVoiceInfoTD(playerid);
    for(new i = 0; i < 32; i++)
    {
        PlayerTextDrawShow(playerid, GachaVRP[playerid][i]);
    }
    PlayerTextDrawSetPreviewModel(playerid, GachaVRP[playerid][21], 411);

    new ticketCount = Inventory_Count(playerid, "Ticket Gacha");
    new ticketText[64];
    format(ticketText, sizeof(ticketText), "Ticket Gacha: %dx", ticketCount);
    PlayerTextDrawSetString(playerid, GachaVRP[playerid][20], ticketText);
    PlayerTextDrawShow(playerid, GachaVRP[playerid][20]);
    SelectTextDraw(playerid, 0xFF0000FF);
    
    return 1;
}

public Gacha_Spin(playerid)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        return 0;

    if(PlayerGachaData[playerid][pGachaSpinning])
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Please wait, still spinning!");
        return 0;
    }
    if(Inventory_Count(playerid, "Ticket Gacha") < 1)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "You don't have enough Gacha Ticket!");
        for(new i = 0; i < 32; i++)
        {
            PlayerTextDrawHide(playerid, GachaVRP[playerid][i]);
        }
        CancelSelectTextDraw(playerid);
        return 0;
    }
    
    Inventory_Remove(playerid, "Ticket Gacha", 1);

    new ticketCount = Inventory_Count(playerid, "Ticket Gacha");
    new ticketText[64];
    format(ticketText, sizeof(ticketText), "Ticket Gacha: %dx", ticketCount);
    PlayerTextDrawSetString(playerid, GachaVRP[playerid][20], ticketText);
    PlayerTextDrawShow(playerid, GachaVRP[playerid][20]);

    PlayerGachaData[playerid][pGachaSpinning] = true;
    PlayerGachaData[playerid][pGachaSpinCount] = 0;
    PlayerGachaData[playerid][pGachaSlowdownFrame] = 0;
    PlayerGachaData[playerid][pGachaCurrentDelay] = 80; // Mulai dengan delay 80ms (cepat)
    PlayerGachaData[playerid][pGachaLastIndex] = -1;
    
    PlayerGachaData[playerid][pGachaResultIndex] = Gacha_GetRandomItem(playerid);
    PlayerGachaData[playerid][pGachaTimer] = SetTimerEx("Gacha_SpinAnimation", 80, true, "i", playerid);
    
    return 1;
}

public Gacha_SpinAnimation(playerid)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
    {
        if(PlayerGachaData[playerid][pGachaTimer] != -1)
        {
            KillTimer(PlayerGachaData[playerid][pGachaTimer]);
            PlayerGachaData[playerid][pGachaTimer] = -1;
        }
        PlayerGachaData[playerid][pGachaSpinning] = false;
        return 0;
    }
    
    PlayerGachaData[playerid][pGachaSpinCount]++;
    new randomIndex = random(sizeof(g_GachaItems));

    if(randomIndex == PlayerGachaData[playerid][pGachaLastIndex])
    {
        randomIndex = (randomIndex + 1) % sizeof(g_GachaItems);
    }
    PlayerGachaData[playerid][pGachaLastIndex] = randomIndex;
    
    PlayerTextDrawSetPreviewModel(playerid, GachaVRP[playerid][21], g_GachaItems[randomIndex][gPreviewModel]);
    PlayerTextDrawShow(playerid, GachaVRP[playerid][21]);

    new tempText[32];
    new dotCount = (PlayerGachaData[playerid][pGachaSpinCount] % 3) + 1;
    format(tempText, sizeof(tempText), "Spinning%.*s", dotCount, "...");
    PlayerTextDrawSetString(playerid, GachaVRP[playerid][19], tempText);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][19], 0xFFFFFFFF);
    PlayerTextDrawShow(playerid, GachaVRP[playerid][19]);

    new totalFrames = 45; 
    new slowDownStart = 30;
    
    if(PlayerGachaData[playerid][pGachaSpinCount] >= totalFrames)
    {
        if(PlayerGachaData[playerid][pGachaTimer] != -1)
        {
            KillTimer(PlayerGachaData[playerid][pGachaTimer]);
            PlayerGachaData[playerid][pGachaTimer] = -1;
        }
        
        PlayerGachaData[playerid][pGachaSpinning] = false;
        Gacha_GiveReward(playerid, PlayerGachaData[playerid][pGachaResultIndex]);
    }
    else if(PlayerGachaData[playerid][pGachaSpinCount] >= slowDownStart)
    {
        new slowdownProgress = PlayerGachaData[playerid][pGachaSpinCount] - slowDownStart;
        new newDelay;
        switch(slowdownProgress)
        {
            case 0..1: newDelay = 120;
            case 2..3: newDelay = 160;
            case 4..5: newDelay = 200;
            case 6..7: newDelay = 250;
            case 8..9: newDelay = 300;
            case 10..11: newDelay = 350;
            case 12..13: newDelay = 400;
            default: newDelay = 450;
        }
        if(newDelay != PlayerGachaData[playerid][pGachaCurrentDelay])
        {
            PlayerGachaData[playerid][pGachaCurrentDelay] = newDelay;
            if(PlayerGachaData[playerid][pGachaTimer] != -1)
            {
                KillTimer(PlayerGachaData[playerid][pGachaTimer]);
            }
            PlayerGachaData[playerid][pGachaTimer] = SetTimerEx("Gacha_SpinAnimation", newDelay, true, "i", playerid);
        }
        if(slowdownProgress == 0)
        {
            PlayerTextDrawSetString(playerid, GachaVRP[playerid][19], "Slowing down...");
            PlayerTextDrawShow(playerid, GachaVRP[playerid][19]);
        }
    }
    
    return 1;
}

public Gacha_GetRandomItem(playerid)
{
    if(PlayerGachaData[playerid][pGachaSpinCounter] >= 50)
    {
        PlayerGachaData[playerid][pGachaSpinCounter] = 0;
        new vehicleIndex = 9 + random(6);
        return vehicleIndex;
    }
    
    new randomNum = random(10000);
    new itemIndex;
    
    if(randomNum < 9200)
    {
        itemIndex = random(4);
    }
    else if(randomNum < 9900)
    {
        itemIndex = 4 + random(2);
    }
    else if(randomNum < 9990)
    {
        itemIndex = 6 + random(3);
    }
    else
    {
        itemIndex = 9 + random(6);
    }
    
    new itemType = g_GachaItems[itemIndex][gItemType];
    if(itemType == 2)
    {
        PlayerGachaData[playerid][pGachaSpinCounter] = 0;
    }
    else
    {
        PlayerGachaData[playerid][pGachaSpinCounter]++;
    }
    
    return itemIndex;
}

public Gacha_GiveReward(playerid, itemIndex)
{
    new itemName[32];
    strcat(itemName, g_GachaItems[itemIndex][gItemName], 32);
    
    new rarity = g_GachaItems[itemIndex][gItemRarity];
    new itemType = g_GachaItems[itemIndex][gItemType];
    new itemValue = g_GachaItems[itemIndex][gItemValue];
    new itemAmount = g_GachaItems[itemIndex][gItemAmounts2];
    new color;

    switch(rarity)
    {
        case 1: color = GACHA_COLOR_COMMON;
        case 2: color = GACHA_COLOR_UNCOMMON;
        case 3: color = GACHA_COLOR_RARE;
        case 4: color = GACHA_COLOR_EPIC;
        default: color = 0xFFFFFFFF;
    }

    PlayerTextDrawSetPreviewModel(playerid, GachaVRP[playerid][21], g_GachaItems[itemIndex][gPreviewModel]);
    PlayerTextDrawShow(playerid, GachaVRP[playerid][21]);

    PlayerTextDrawSetString(playerid, GachaVRP[playerid][19], itemName);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][19], color);
    PlayerTextDrawShow(playerid, GachaVRP[playerid][19]);
    
    switch(itemType)
    {
        case 1: // Item
        {
            if(strfind(itemName, "Kayu") != -1)
            {
                Inventory_Add(playerid, "Kayu", 19793, itemAmount);
            }
            else if(strfind(itemName, "Batu") != -1)
            {
                Inventory_Add(playerid, "Batu", 3930, itemAmount);
            }
            else if(strfind(itemName, "Chicken BBQ") != -1)
            {
                Inventory_Add(playerid, "Chicken BBQ", 2355, itemAmount);
            }
            else if(strfind(itemName, "Coconut Water") != -1)
            {
                Inventory_Add(playerid, "Coconut Water", 19564, itemAmount);
            }
            else if(strcmp(itemName, "Ticket Gacha") == 0)
            {
                Inventory_Add(playerid, "Ticket Gacha", 19792, itemAmount);
            }
            
            new string[128];
            format(string, sizeof(string), "Congratulations! You got %s x%d from Gacha!", itemName, itemAmount);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
        }
        
        case 2: // Vehicle
        {
            new Float:pos[4];
            GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
            GetPlayerFacingAngle(playerid, pos[3]);
            pos[2] += 2.0;
            
            new pvwid = GetPlayerVirtualWorld(playerid);
            new pvintid = GetPlayerInterior(playerid);
            new counting = 0;

            foreach(new v : PvtVehicles)
            {
                if(PlayerVehicle[v][pVehOwnerID] == AccountData[playerid][pID])
                    counting++;
            }
            
            if(counting >= GetPlayerVehicleLimit(playerid))
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, "Your vehicle limit is full! Reward saved to database.");
                return 1;
            }
            
            Vehicle_Create(playerid, itemValue, pos[0], pos[1], pos[2], pos[3], random(126), random(126), pvwid, pvintid);
            
            new string[128];
            format(string, sizeof(string), "Congratulations! You got %s from Gacha!", itemName);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
        }
        
        case 3: // VIP
        {
            new currentVIP = AccountData[playerid][pVIP];
            new currentVIPTime = AccountData[playerid][pVIPTime];
            new addDays = itemValue;
            new currentTime = gettime();
            new rewardVIPLevel = 1;
            new rewardDays = addDays;
            new rewardSeconds = rewardDays * 86400;

            if(currentVIP >= rewardVIPLevel)
            {
                AccountData[playerid][pVIPTime] = currentVIPTime + rewardSeconds;
                
                new string[128];
                format(string, sizeof(string), "Congratulations! You got VIP %d for %d days! (Extended by %d days)", rewardVIPLevel, rewardDays, rewardDays);
                ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
            }
            else if(currentVIP == 0)
            {
                AccountData[playerid][pVIP] = rewardVIPLevel;
                AccountData[playerid][pVIPTime] = currentTime + rewardSeconds;
                
                new string[128];
                format(string, sizeof(string), "Congratulations! You got VIP %d for %d days!", rewardVIPLevel, rewardDays);
                ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
            }
            else if(currentVIP < rewardVIPLevel)
            {
                new remainingSeconds = (currentVIPTime > currentTime) ? (currentVIPTime - currentTime) : 0;
                new bonusPercent = 50;
                new bonusSeconds = (remainingSeconds * bonusPercent) / 100;
                new totalSeconds = rewardSeconds + bonusSeconds;

                AccountData[playerid][pVIP] = rewardVIPLevel;
                AccountData[playerid][pVIPTime] = currentTime + totalSeconds;
                
                new remainingDays = remainingSeconds / 86400;
                new totalDays = totalSeconds / 86400;
                
                new string[256];
                format(string, sizeof(string), "Congratulations! You got VIP %d for %d days!\n{FFFFFF}Your old VIP %d (%d days left) has been upgraded with %d%% bonus time!\n{33FF33}Total: VIP %d for %d days!",rewardVIPLevel, rewardDays,currentVIP, remainingDays, bonusPercent,rewardVIPLevel, totalDays);
                ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
            }
        }
        
        case 4: // Money
        {
            new moneyAmount = 1000 + random(9000); 
            AccountData[playerid][pMoney] += moneyAmount;
            
            new string[128];
            format(string, sizeof(string), "Congratulations! You got $%d from Gacha!", moneyAmount);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
        }
    }
    new logQuery[256];
    mysql_format(g_SQL, logQuery, sizeof(logQuery), "INSERT INTO `gacha_logs` SET `PlayerID` = %d, `PlayerName` = '%e', `Reward` = '%e', `Rarity` = %d, `Time` = NOW()", AccountData[playerid][pID], AccountData[playerid][pName], itemName, rarity);
    mysql_pquery(g_SQL, logQuery);
    
    return 1;
}

hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(playertextid == GachaVRP[playerid][5])
    {
        Gacha_Spin(playerid);
        return 0;
    }
    if(playertextid == GachaVRP[playerid][16])
    {
        for(new i = 0; i < 32; i++)
        {
            PlayerTextDrawHide(playerid, GachaVRP[playerid][i]);
        }
        ShowServerNameTD(playerid);
		//ShowStatsTD(playerid);

		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
			ShowSpeedoTD(playerid);
			
		ShowHBETD(playerid);
		ShowRadioVoiceInfoTD(playerid);
        CancelSelectTextDraw(playerid);
        if(PlayerGachaData[playerid][pGachaTimer] != -1)
        {
            KillTimer(PlayerGachaData[playerid][pGachaTimer]);
            PlayerGachaData[playerid][pGachaTimer] = -1;
            PlayerGachaData[playerid][pGachaSpinning] = false;
        }
        return 0;
    }
    
    return 0;
}

CreateUiGacha(playerid)
{
    GachaVRP[playerid][0] = CreatePlayerTextDraw(playerid, 157.000, 116.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][0], 323.000, 256.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][0], -7601921);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][0], 1);

    GachaVRP[playerid][1] = CreatePlayerTextDraw(playerid, 162.000, 121.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][1], 313.000, 245.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][1], -12254977);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][1], 1);

    GachaVRP[playerid][2] = CreatePlayerTextDraw(playerid, 157.000, 141.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][2], 323.000, 2.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][2], -7601921);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][2], 1);

    GachaVRP[playerid][3] = CreatePlayerTextDraw(playerid, 157.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][3], 323.000, 2.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][3], -7601921);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][3], 1);

    GachaVRP[playerid][4] = CreatePlayerTextDraw(playerid, 287.000, 147.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][4], 64.000, 14.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][4], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][4], 1);

    GachaVRP[playerid][5] = CreatePlayerTextDraw(playerid, 287.000, 265.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][5], 64.000, 14.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][5], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, GachaVRP[playerid][5], 1);

    GachaVRP[playerid][6] = CreatePlayerTextDraw(playerid, 180.000, 293.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][6], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][6], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][6], 1);

    GachaVRP[playerid][7] = CreatePlayerTextDraw(playerid, 236.000, 293.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][7], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][7], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][7], 1);

    GachaVRP[playerid][8] = CreatePlayerTextDraw(playerid, 292.000, 293.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][8], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][8], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][8], 1);

    GachaVRP[playerid][9] = CreatePlayerTextDraw(playerid, 348.000, 293.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][9], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][9], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][9], 1);

    GachaVRP[playerid][10] = CreatePlayerTextDraw(playerid, 404.000, 293.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][10], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][10], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][10], 1);

    GachaVRP[playerid][11] = CreatePlayerTextDraw(playerid, 404.000, 327.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][11], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][11], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][11], 1);

    GachaVRP[playerid][12] = CreatePlayerTextDraw(playerid, 348.000, 327.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][12], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][12], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][12], 1);

    GachaVRP[playerid][13] = CreatePlayerTextDraw(playerid, 292.000, 327.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][13], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][13], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][13], 1);

    GachaVRP[playerid][14] = CreatePlayerTextDraw(playerid, 236.000, 327.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][14], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][14], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][14], 1);

    GachaVRP[playerid][15] = CreatePlayerTextDraw(playerid, 180.000, 327.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][15], 50.000, 20.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][15], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][15], 1);

    GachaVRP[playerid][16] = CreatePlayerTextDraw(playerid, 459.000, 124.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][16], 14.000, 14.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][16], -759919361);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][16], 1);
    PlayerTextDrawSetSelectable(playerid, GachaVRP[playerid][16], 1);

    GachaVRP[playerid][17] = CreatePlayerTextDraw(playerid, 463.000, 123.000, "X");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][17], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][17], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][17], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][17], 1);

    GachaVRP[playerid][18] = CreatePlayerTextDraw(playerid, 322.000, 125.000, "VERTEX GACHA");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][18], 0.219, 1.299);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][18], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][18], 1);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][18], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][18], 1);

    GachaVRP[playerid][19] = CreatePlayerTextDraw(playerid, 320.000, 147.000, "Patriot");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][19], 0.200, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][19], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][19], -1962934017);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][19], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][19], 1);

    GachaVRP[playerid][20] = CreatePlayerTextDraw(playerid, 320.000, 266.000, "Ticket Gacha: 1x");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][20], 0.170, 1.098);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][20], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][20], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][20], 1);

    GachaVRP[playerid][21] = CreatePlayerTextDraw(playerid, 245.000, 144.000, "_");
    PlayerTextDrawTextSize(playerid, GachaVRP[playerid][21], 139.000, 144.000);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][21], 0);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][21], 5);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][21], 0);
    PlayerTextDrawSetPreviewModel(playerid, GachaVRP[playerid][21], 470);
    PlayerTextDrawSetPreviewRot(playerid, GachaVRP[playerid][21], 0.000, 0.000, 22.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, GachaVRP[playerid][21], 0, 0);

    GachaVRP[playerid][22] = CreatePlayerTextDraw(playerid, 205.000, 296.000, "Infernus");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][22], 0.210, 1.299);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][22], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][22], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][22], 1);

    GachaVRP[playerid][23] = CreatePlayerTextDraw(playerid, 261.000, 297.000, "Vip 1 7 Day");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][23], 0.180, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][23], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][23], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][23], 1);

    GachaVRP[playerid][24] = CreatePlayerTextDraw(playerid, 317.000, 297.000, "Nrg");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][24], 0.180, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][24], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][24], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][24], 1);

    GachaVRP[playerid][25] = CreatePlayerTextDraw(playerid, 374.000, 297.000, "Uang Random");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][25], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][25], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][25], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][25], 1);

    GachaVRP[playerid][26] = CreatePlayerTextDraw(playerid, 430.000, 297.000, "Kayu 5x");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][26], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][26], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][26], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][26], 1);

    GachaVRP[playerid][27] = CreatePlayerTextDraw(playerid, 205.000, 331.000, "Bullet");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][27], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][27], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][27], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][27], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][27], 1);

    GachaVRP[playerid][28] = CreatePlayerTextDraw(playerid, 262.000, 331.000, "VIP 1 14 Day");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][28], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][28], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][28], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][28], 1);

    GachaVRP[playerid][29] = CreatePlayerTextDraw(playerid, 317.000, 331.000, "Turismo");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][29], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][29], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][29], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][29], 1);

    GachaVRP[playerid][30] = CreatePlayerTextDraw(playerid, 373.000, 331.000, "Ticket Gachax");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][30], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][30], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][30], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][30], 1);

    GachaVRP[playerid][31] = CreatePlayerTextDraw(playerid, 430.000, 331.000, "Batu 5x");
    PlayerTextDrawLetterSize(playerid, GachaVRP[playerid][31], 0.170, 1.199);
    PlayerTextDrawAlignment(playerid, GachaVRP[playerid][31], 2);
    PlayerTextDrawColor(playerid, GachaVRP[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, GachaVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, GachaVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, GachaVRP[playerid][31], 150);
    PlayerTextDrawFont(playerid, GachaVRP[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, GachaVRP[playerid][31], 1);

}

hook OnPlayerConnect(playerid)
{
    PlayerGachaData[playerid][pGachaSpinning] = false;
    PlayerGachaData[playerid][pGachaTimer] = -1;
    PlayerGachaData[playerid][pGachaSpinCount] = 0;
    PlayerGachaData[playerid][pGachaResultIndex] = 0;
    PlayerGachaData[playerid][pGachaSlowdownFrame] = 0;
    PlayerGachaData[playerid][pGachaCurrentDelay] = 80;
    PlayerGachaData[playerid][pGachaLastIndex] = -1;
    PlayerGachaData[playerid][pGachaSpinCounter] = 0;
    CreateUiGacha(playerid);
    
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(PlayerGachaData[playerid][pGachaTimer] != -1)
    {
        KillTimer(PlayerGachaData[playerid][pGachaTimer]);
        PlayerGachaData[playerid][pGachaTimer] = -1;
    }
    return 1;
}