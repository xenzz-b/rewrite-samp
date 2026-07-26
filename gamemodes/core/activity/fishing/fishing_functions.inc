#include <YSI_Coding\y_hooks>

new bool:IsFishUsing[MAX_PLAYERS];

new FishingFailStreak[MAX_PLAYERS];
new Float:__g_FishingLoc[][3] =
{
    {403.8386,-2088.7981,7.9359},
    {398.7301,-2088.7908,7.9359},
    {396.1581,-2088.7903,7.9359},
    {391.0529,-2088.7981,7.9359},
    {383.4729,-2088.7910,7.9359},
    {374.9562,-2088.7976,7.9359},
    {369.8450,-2088.7976,7.9359},
    {367.2522,-2088.7920,7.9359},
    {362.1185,-2088.7979,7.9359},
    {354.5533,-2088.7915,7.9359},
    {349.9594,-2072.5090,7.9359},
    {349.9337,-2067.2839,7.9359},
    {349.9271,-2064.7588,7.9359},
    {349.9040,-2059.6938,7.9359},
    {349.8698,-2052.0752,7.9359}
};

enum
{
    BUTTON_NONE,
    BUTTON_ALT,
    BUTTON_F,
    BUTTON_H,
    BUTTON_Y,
    BUTTON_N
}

new bool:IsPlayerFishing[MAX_PLAYERS],
    FishingButton[MAX_PLAYERS],
    FishingMinigameActive[MAX_PLAYERS],
    FishingProgress[MAX_PLAYERS],
    FishingTimer[MAX_PLAYERS];

new PlayerText: Fishit[MAX_PLAYERS][14];
new PlayerText: NotifFishit[MAX_PLAYERS][4];

new HideNotifTimer[MAX_PLAYERS];
// Forward deklarasi
forward FishingStrike(playerid);
forward FishingMinigameTimer(playerid);
forward FishingHideUI(playerid);

// ============================================================
// UI TEXTDRAW
// ============================================================

CreateFishingUI(playerid)
{
    for(new i = 0; i < 14; i++)
    {
        if(PlayerText:Fishit[playerid][i] != PlayerText:INVALID_TEXT_DRAW)
            PlayerTextDrawDestroy(playerid, Fishit[playerid][i]);
    }

    Fishit[playerid][0] = CreatePlayerTextDraw(playerid, 295.000, 350.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][0], 45.000, 25.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][0], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][0], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, Fishit[playerid][0], 1);

    Fishit[playerid][1] = CreatePlayerTextDraw(playerid, 297.000, 338.000, "_");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][1], 40.000, 50.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][1], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][1], 0);
    PlayerTextDrawFont(playerid, Fishit[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, Fishit[playerid][1], 19630);
    PlayerTextDrawSetPreviewRot(playerid, Fishit[playerid][1], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, Fishit[playerid][1], 0, 0);

    Fishit[playerid][2] = CreatePlayerTextDraw(playerid, 319.000, 357.000, "?");
    PlayerTextDrawLetterSize(playerid, Fishit[playerid][2], 0.259, 1.098);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][2], 2);
    PlayerTextDrawColor(playerid, Fishit[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][2], 150);
    PlayerTextDrawFont(playerid, Fishit[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][2], 1);

    Fishit[playerid][3] = CreatePlayerTextDraw(playerid, 185.000, 351.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][3], 110.000, 1.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][3], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][3], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][3], 1);

    Fishit[playerid][4] = CreatePlayerTextDraw(playerid, 185.000, 373.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][4], 110.000, 1.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][4], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][4], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][4], 1);

    Fishit[playerid][5] = CreatePlayerTextDraw(playerid, 340.000, 351.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][5], 110.000, 1.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][5], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][5], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][5], 1);

    Fishit[playerid][6] = CreatePlayerTextDraw(playerid, 340.000, 373.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][6], 110.000, 1.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][6], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][6], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][6], 1);

    Fishit[playerid][7] = CreatePlayerTextDraw(playerid, 185.000, 373.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][7], 1.000, -21.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][7], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][7], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][7], 1);

    Fishit[playerid][8] = CreatePlayerTextDraw(playerid, 295.000, 352.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][8], -109.000, 21.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][8], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][8], -12254977);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][8], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][8], 1);

    Fishit[playerid][9] = CreatePlayerTextDraw(playerid, 340.000, 352.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][9], 109.000, 21.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][9], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][9], -12254977);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][9], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][9], 1);

    Fishit[playerid][10] = CreatePlayerTextDraw(playerid, 449.000, 373.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][10], 1.000, -21.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][10], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][10], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][10], 1);

    Fishit[playerid][11] = CreatePlayerTextDraw(playerid, 308.000, 335.000, "Click Fast!");
    PlayerTextDrawLetterSize(playerid, Fishit[playerid][11], 0.209, 1.299);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][11], 2);
    PlayerTextDrawColor(playerid, Fishit[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][11], 150);
    PlayerTextDrawFont(playerid, Fishit[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][11], 1);

    Fishit[playerid][12] = CreatePlayerTextDraw(playerid, 276.000, 331.000, "LD_BEAT:downr");
    PlayerTextDrawTextSize(playerid, Fishit[playerid][12], 13.000, 14.000);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][12], 1);
    PlayerTextDrawColor(playerid, Fishit[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][12], 255);
    PlayerTextDrawFont(playerid, Fishit[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][12], 1);

    Fishit[playerid][13] = CreatePlayerTextDraw(playerid, 336.000, 336.000, "(0.05)");
    PlayerTextDrawLetterSize(playerid, Fishit[playerid][13], 0.167, 1.098);
    PlayerTextDrawAlignment(playerid, Fishit[playerid][13], 2);
    PlayerTextDrawColor(playerid, Fishit[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, Fishit[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, Fishit[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, Fishit[playerid][13], 150);
    PlayerTextDrawFont(playerid, Fishit[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, Fishit[playerid][13], 1);
    
    NotifFishit[playerid][0] = CreatePlayerTextDraw(playerid, 238.000, 55.000, "_");
    PlayerTextDrawTextSize(playerid, NotifFishit[playerid][0], 155.000, 158.000);
    PlayerTextDrawAlignment(playerid, NotifFishit[playerid][0], 1);
    PlayerTextDrawColor(playerid, NotifFishit[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, NotifFishit[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, NotifFishit[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, NotifFishit[playerid][0], 0);
    PlayerTextDrawFont(playerid, NotifFishit[playerid][0], 5);
    PlayerTextDrawSetProportional(playerid, NotifFishit[playerid][0], 0);
    PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][0], 675);
    PlayerTextDrawSetPreviewRot(playerid, NotifFishit[playerid][0], 0.000, 0.000, 0.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, NotifFishit[playerid][0], 0, 0);

    NotifFishit[playerid][1] = CreatePlayerTextDraw(playerid, 285.000, 98.000, "_");
    PlayerTextDrawTextSize(playerid, NotifFishit[playerid][1], 62.000, 66.000);
    PlayerTextDrawAlignment(playerid, NotifFishit[playerid][1], 1);
    PlayerTextDrawColor(playerid, NotifFishit[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, NotifFishit[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, NotifFishit[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, NotifFishit[playerid][1], 0);
    PlayerTextDrawFont(playerid, NotifFishit[playerid][1], 5);
    PlayerTextDrawSetProportional(playerid, NotifFishit[playerid][1], 0);
    PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1604);
    PlayerTextDrawSetPreviewRot(playerid, NotifFishit[playerid][1], 0.000, 0.000, 82.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, NotifFishit[playerid][1], 0, 0);

    NotifFishit[playerid][2] = CreatePlayerTextDraw(playerid, 295.000, 168.000, "LEGENDARY");
    PlayerTextDrawLetterSize(playerid, NotifFishit[playerid][2], 0.239, 1.299);
    PlayerTextDrawAlignment(playerid, NotifFishit[playerid][2], 1);
    PlayerTextDrawColor(playerid, NotifFishit[playerid][2], -2686721);
    PlayerTextDrawSetShadow(playerid, NotifFishit[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, NotifFishit[playerid][2], 1);
    PlayerTextDrawBackgroundColor(playerid, NotifFishit[playerid][2], 150);
    PlayerTextDrawFont(playerid, NotifFishit[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, NotifFishit[playerid][2], 1);

    NotifFishit[playerid][3] = CreatePlayerTextDraw(playerid, 279.000, 181.000, "MEGALODON (20.0Kg)");
    PlayerTextDrawLetterSize(playerid, NotifFishit[playerid][3], 0.209, 1.098);
    PlayerTextDrawAlignment(playerid, NotifFishit[playerid][3], 1);
    PlayerTextDrawColor(playerid, NotifFishit[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, NotifFishit[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, NotifFishit[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, NotifFishit[playerid][3], 150);
    PlayerTextDrawFont(playerid, NotifFishit[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, NotifFishit[playerid][3], 1);
}

ShowFishingUI(playerid)
{
    for(new i = 0; i < 14; i++)
    {
        PlayerTextDrawShow(playerid, Fishit[playerid][i]);
    }
    SelectTextDraw(playerid, 0xFFFFFFFF);
}

HideFishingUI(playerid)
{
    for(new i = 0; i < 14; i++)
    {
        PlayerTextDrawHide(playerid, Fishit[playerid][i]);
    }
    CancelSelectTextDraw(playerid);
}

HideFishingNotifUI(playerid)
{
    for(new i = 0; i < 4; i++)
        PlayerTextDrawHide(playerid, NotifFishit[playerid][i]);
}

UpdateFishingBar(playerid)
{
    new progress = FishingProgress[playerid];
    
    // Update bar kiri (negatif)
    new Float:leftSize = -float(progress) * 1.09;
    PlayerTextDrawTextSize(playerid, Fishit[playerid][8], leftSize, 21.0);
    PlayerTextDrawShow(playerid, Fishit[playerid][8]);
    
    // Update bar kanan (positif)
    new Float:rightSize = float(progress) * 1.09;
    PlayerTextDrawTextSize(playerid, Fishit[playerid][9], rightSize, 21.0);
    PlayerTextDrawShow(playerid, Fishit[playerid][9]);
    
    // Update persentase
    new pctStr[16];
    format(pctStr, sizeof(pctStr), "(%d%%)", progress);
    PlayerTextDrawSetString(playerid, Fishit[playerid][13], pctStr);
    PlayerTextDrawShow(playerid, Fishit[playerid][13]);
}

StartFishingMinigame(playerid)
{
    if(FishingMinigameActive[playerid]) return 1;
    
    FishingMinigameActive[playerid] = true;
    FishingProgress[playerid] = 30;  // Mulai dari 30%
    
    ShowFishingUI(playerid);
    UpdateFishingBar(playerid);
    
    FishingTimer[playerid] = SetTimerEx("FishingMinigameTimer", 500, true, "i", playerid);
    SendClientMessageEx(playerid, 0x00FF00FF, "[FISHING] Ikan menyambar! Klik tombol ikan dengan cepat!");
    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
    return 1;
}

StopFishingMinigame(playerid, bool:success)
{
    if(!FishingMinigameActive[playerid]) return 1;
    
    FishingMinigameActive[playerid] = false;
    
    if(FishingTimer[playerid] != -1)
    {
        KillTimer(FishingTimer[playerid]);
        FishingTimer[playerid] = -1;
    }
    
    HideFishingUI(playerid);
    
    if(success)
    {
        // Reset streak gagal
        FishingFailStreak[playerid] = 0;
        
        // Chance based on streak (makin tinggi streak, makin gede chance dapet langka)
        new randresult = Random(100);
        new itemName[32];
        new itemModel;
        new bonusChance = (FishingFailStreak[playerid] > 5) ? (FishingFailStreak[playerid] - 5) : 0; // Bonus kalo streak gagal tinggi
        
        // Kurangi randresult biar lebih susah
        new adjustedRand = randresult - bonusChance;
        if(adjustedRand < 0) adjustedRand = 0;
        
        switch(adjustedRand)
        {
            case 0..9: // Zonk 10%
            {
                SendClientMessage(playerid, -1, "[i] Zonk, anda mendapatkan "AQUAMARINE"sampah!");
            }
            case 10..49: // Ikan biasa 40%
            {
                itemName = "Ikan";
                itemModel = 1604;
                
                AccountData[playerid][pStress] -= 5;
                ShowItemBox(playerid, itemName, "Received 1x", itemModel, 5);
                Inventory_Add(playerid, itemName, itemModel, 1);
                SendClientMessage(playerid, -1, sprintf("[i] Anda mendapatkan seekor %s.", itemName));
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

                if(HideNotifTimer[playerid] != -1)
                {
                    KillTimer(HideNotifTimer[playerid]);
                    HideNotifTimer[playerid] = -1;
                }

                PlayerTextDrawShow(playerid, NotifFishit[playerid][0]);

                PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1604);
                PlayerTextDrawColor(playerid, NotifFishit[playerid][1], 0xA0A0A0FF); 
                PlayerTextDrawHide(playerid, NotifFishit[playerid][1]);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][1]);

                PlayerTextDrawSetString(playerid, NotifFishit[playerid][2], "Common");
                PlayerTextDrawColor(playerid, NotifFishit[playerid][2], 0xA0A0A0FF);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][2]);
                
                PlayerTextDrawSetString(playerid, NotifFishit[playerid][3], "Ikan (1.5 Kg)");
                PlayerTextDrawShow(playerid, NotifFishit[playerid][3]);

                HideNotifTimer[playerid] = SetTimerEx("HideFishingNotifTimer", 5000, false, "i", playerid);
            }
            case 50..79: // Penyu 30%
            {
                itemName = "Penyu";
                itemModel = 1609;
                
                AccountData[playerid][pStress] -= 5;
                ShowItemBox(playerid, itemName, "Received 1x", itemModel, 5);
                Inventory_Add(playerid, itemName, itemModel, 1);
                SendClientMessage(playerid, -1, sprintf("[i] Anda mendapatkan seekor %s.", itemName));
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

                if(HideNotifTimer[playerid] != -1)
                {
                    KillTimer(HideNotifTimer[playerid]);
                    HideNotifTimer[playerid] = -1;
                }

                PlayerTextDrawShow(playerid, NotifFishit[playerid][0]);

                PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1609);
                PlayerTextDrawColor(playerid, NotifFishit[playerid][1], 0x00C800FF); 
                PlayerTextDrawHide(playerid, NotifFishit[playerid][1]);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][1]);

                PlayerTextDrawSetString(playerid, NotifFishit[playerid][2], "Uncomon");
                PlayerTextDrawColor(playerid, NotifFishit[playerid][2], 0x00C800FF);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][2]);
                
                PlayerTextDrawSetString(playerid, NotifFishit[playerid][3], "Penyu (2.5 Kg)");
                PlayerTextDrawShow(playerid, NotifFishit[playerid][3]);

                HideNotifTimer[playerid] = SetTimerEx("HideFishingNotifTimer", 5000, false, "i", playerid);
            }
            case 80..92: // Hiu biasa 13%
            {
                itemName = "Hiu";
                itemModel = 1608;
                
                AccountData[playerid][pStress] -= 5;
                ShowItemBox(playerid, itemName, "Received 1x", itemModel, 5);
                Inventory_Add(playerid, itemName, itemModel, 1);
                SendClientMessage(playerid, -1, sprintf("[i] Anda mendapatkan seekor %s.", itemName));
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);

                if(HideNotifTimer[playerid] != -1)
                {
                    KillTimer(HideNotifTimer[playerid]);
                    HideNotifTimer[playerid] = -1;
                }

                PlayerTextDrawShow(playerid, NotifFishit[playerid][0]);

                PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1608);
                PlayerTextDrawColor(playerid, NotifFishit[playerid][1], 0x6666FFFF); 
                PlayerTextDrawHide(playerid, NotifFishit[playerid][1]);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][1]);

                PlayerTextDrawSetString(playerid, NotifFishit[playerid][2], "Rare");
                PlayerTextDrawColor(playerid, NotifFishit[playerid][2], 0x6666FFFF);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][2]);
                
                PlayerTextDrawSetString(playerid, NotifFishit[playerid][3], "Hiu (5.5 Kg)");
                PlayerTextDrawShow(playerid, NotifFishit[playerid][3]);

                HideNotifTimer[playerid] = SetTimerEx("HideFishingNotifTimer", 5000, false, "i", playerid);
            }
            case 93..96: // Lumba-lumba 4% - SUSAH
            {
                itemName = "Lumba Lumba";
                itemModel = 1607;
                
                AccountData[playerid][pStress] -= 5;
                ShowItemBox(playerid, itemName, "Received 1x", itemModel, 5);
                Inventory_Add(playerid, itemName, itemModel, 1);
                SendClientMessage(playerid, -1, sprintf("[i] Anda mendapatkan seekor %s.", itemName));
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
                SendClientMessage(playerid, X11_GREEN, "[Epic] Wah! Anda mendapatkan Lumba-lumba yang langka!");

                if(HideNotifTimer[playerid] != -1)
                {
                    KillTimer(HideNotifTimer[playerid]);
                    HideNotifTimer[playerid] = -1;
                }

                PlayerTextDrawShow(playerid, NotifFishit[playerid][0]);

                PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1607);
                PlayerTextDrawColor(playerid, NotifFishit[playerid][1], 0xAA00FFFF); 
                PlayerTextDrawHide(playerid, NotifFishit[playerid][1]);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][1]);

                PlayerTextDrawSetString(playerid, NotifFishit[playerid][2], "Epic");
                PlayerTextDrawColor(playerid, NotifFishit[playerid][2], 0xAA00FFFF);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][2]);
                
                PlayerTextDrawSetString(playerid, NotifFishit[playerid][3], "Lumba Lumba (5.5 Kg)");
                PlayerTextDrawShow(playerid, NotifFishit[playerid][3]);

                HideNotifTimer[playerid] = SetTimerEx("HideFishingNotifTimer", 5000, false, "i", playerid);
            }
            case 97..99: // Ubur-ubur 3% - SUSAH
            {
                itemName = "Ubur Ubur";
                itemModel = 1603;
                
                AccountData[playerid][pStress] -= 5;
                ShowItemBox(playerid, itemName, "Received 1x", itemModel, 5);
                Inventory_Add(playerid, itemName, itemModel, 1);
                SendClientMessage(playerid, -1, sprintf("[i] Anda mendapatkan seekor %s.", itemName));
                PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
                SendClientMessage(playerid, X11_GREEN, "[Epic] Wah! Anda mendapatkan Ubur-ubur yang langka!");

                if(HideNotifTimer[playerid] != -1)
                {
                    KillTimer(HideNotifTimer[playerid]);
                    HideNotifTimer[playerid] = -1;
                }

                PlayerTextDrawShow(playerid, NotifFishit[playerid][0]);

                PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1603);
                PlayerTextDrawColor(playerid, NotifFishit[playerid][1], 0xAA00FFFF); 
                PlayerTextDrawHide(playerid, NotifFishit[playerid][1]);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][1]);

                PlayerTextDrawSetString(playerid, NotifFishit[playerid][2], "Epic");
                PlayerTextDrawColor(playerid, NotifFishit[playerid][2], 0xAA00FFFF);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][2]);
                
                PlayerTextDrawSetString(playerid, NotifFishit[playerid][3], "Ubur Ubur (4.5 Kg)");
                PlayerTextDrawShow(playerid, NotifFishit[playerid][3]);

                HideNotifTimer[playerid] = SetTimerEx("HideFishingNotifTimer", 5000, false, "i", playerid);
            }
            case 100: // Hiu Megalodon 1% - PALING SUSAH
            {
                itemName = "Hiu Megalodon";
                itemModel = 1608;
                
                AccountData[playerid][pStress] -= 5;
                ShowItemBox(playerid, itemName, "Received 1x", itemModel, 5);
                Inventory_Add(playerid, itemName, itemModel, 1);
                SendClientMessage(playerid, -1, sprintf("[i] Anda mendapatkan seekor %s.", itemName));
                PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);
                SendClientMessage(playerid, X11_RED, "!!! SELAMAT! Anda mendapatkan HIU MEGALODON LANGKA !!!");
                SendClientMessage(playerid, X11_YELLOW, "[Legendary] Hiu Megalodon adalah ikan paling langka di lautan!");

                if(HideNotifTimer[playerid] != -1)
                {
                    KillTimer(HideNotifTimer[playerid]);
                    HideNotifTimer[playerid] = -1;
                }

                PlayerTextDrawShow(playerid, NotifFishit[playerid][0]);

                PlayerTextDrawSetPreviewModel(playerid, NotifFishit[playerid][1], 1608);
                PlayerTextDrawColor(playerid, NotifFishit[playerid][1], 0xFFAA00FF); 
                PlayerTextDrawHide(playerid, NotifFishit[playerid][1]);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][1]);

                PlayerTextDrawSetString(playerid, NotifFishit[playerid][2], "Legendary");
                PlayerTextDrawColor(playerid, NotifFishit[playerid][2], 0xFFAA00FF);
                PlayerTextDrawShow(playerid, NotifFishit[playerid][2]);
                
                PlayerTextDrawSetString(playerid, NotifFishit[playerid][3], "Hiu Megalodon (10.5 Kg)");
                PlayerTextDrawShow(playerid, NotifFishit[playerid][3]);

                HideNotifTimer[playerid] = SetTimerEx("HideFishingNotifTimer", 5000, false, "i", playerid);
            }
        }
    }
    else
    {
        FishingFailStreak[playerid]++;
        SendClientMessage(playerid, X11_YELLOW, "[FISHING] Anda gagal menarik ikan! Ikan lepas.");
        SendClientMessage(playerid, X11_ORANGE, sprintf("[FISHING] Streak gagal: "YELLOW"%d/10"WHITE" (semakin tinggi streak, semakin besar chance dapet ikan langka)", FishingFailStreak[playerid]));
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
    }
    
    IsPlayerFishing[playerid] = false;
    ClearAnimations(playerid, true);
    StopLoopingAnim(playerid);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    RemovePlayerAttachedObject(playerid, 9);
    FishingButton[playerid] = BUTTON_NONE;
    
    return 1;
}

forward HideFishingNotifTimer(playerid);
public HideFishingNotifTimer(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    
    HideFishingNotifUI(playerid);
    HideNotifTimer[playerid] = -1;
    
    return 1;
}

AttachFishToPlayer(playerid, modelid)
{
    RemovePlayerAttachedObject(playerid, 9);
    if(IsFishUsing[playerid])
    {
        RemovePlayerAttachedObject(playerid, 8);
        RemovePlayerAttachedObject(playerid, 7);
    }
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_CARRY);
    switch(modelid)
    {
        case 1603: // Ubur-ubur
            SetPlayerAttachedObject(playerid, 9, modelid, 6, 0.10, 0.20, 0.00, 0.00, 90.00, 0.00, 1.0, 1.0, 1.0);
        case 1607: // Lumba-lumba
        {
            SetPlayerAttachedObject(playerid, 9, modelid, 1, 0.838000, 0.711999, 0.000000, -0.399999, 95.400016, 76.599937, 1.000000, 0.929000, 0.986000, 0x0, 0x0); //dolphins
            SetPlayerAttachedObject(playerid, 8, 19197, 1, 1.724001, 1.515998, 3.118001, 0.000000, 93.100173, 0.000000, 1.437001, 1.560000, 0.000000, 0x0, 0x0); //mahkota
        }
        case 1608: // Hiu
        {
            SetPlayerAttachedObject(playerid, 9, modelid, 1, 0.593000, 0.906000, -0.794999, 1.600000, 99.700035, 101.099998, 0.553000, 0.580999, 0.628000, 0xFF00B0E0, 0xFFFFFFFF); //hiu
            SetPlayerAttachedObject(playerid, 8, 1316, 1, 0.763998, 0.348000, 1.549000, 13.100009, 0.200000, 0.799999, 0.599000, 0.596999, 1.000000, 0xFFFFFF00, 0x0); //cincin
            SetPlayerAttachedObject(playerid, 7, 1316, 1, 0.385998, 1.072000, -1.512999, 13.100009, 0.200000, 0.799999, 0.404000, 0.380999, 1.000000, 0xFFFFFF00, 0x0); //cincin2
        }
        case 1609: // Penyu
        {
            SetPlayerAttachedObject(playerid, 9, modelid, 1, 0.363999, 0.926000, 0.000000, 0.000000, 85.100021, 84.799987, 1.000000, 1.000000, 1.000000, 0xFFFF0000, 0xFFFF0000); //penyu
            SetPlayerAttachedObject(playerid, 8, 1254, 1, 0.226999, 1.142000, 1.232999, -4.699998, 90.900016, 89.500068, 2.084999, 2.409000, 1.429999, 0xFFFF0000, 0x0); //tengkorak
        }
        default: // Ikan biasa (1604)
            SetPlayerAttachedObject(playerid, 9, modelid, 6, 0.10, 0.20, 0.00, 0.00, 90.00, 0.00, 1.0, 1.0, 1.0);
    }
    SendClientMessage(playerid, Y_SERVER, "[INFO] Anda sekarang memegang ikan.");
}

RemoveFishFromPlayer(playerid)
{
    RemovePlayerAttachedObject(playerid, 9);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    SendClientMessage(playerid, Y_SERVER, "[INFO] Anda melepaskan ikan.");
    if(IsFishUsing[playerid])
    {
        RemovePlayerAttachedObject(playerid, 8);
        RemovePlayerAttachedObject(playerid, 7);
    }
    IsFishUsing[playerid] = false;
}
// ============================================================
// TIMER
// ============================================================

forward FishingMinigameTimer(playerid);
public FishingMinigameTimer(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(!FishingMinigameActive[playerid]) return 0;
    
    // Turunkan progress 2% setiap 0.5 detik
    FishingProgress[playerid] -= 2;
    
    if(FishingProgress[playerid] <= 0)
    {
        FishingProgress[playerid] = 0;
        UpdateFishingBar(playerid);
        StopFishingMinigame(playerid, false);
        return 0;
    }
    
    UpdateFishingBar(playerid);
    return 1;
}

forward FishingStrike(playerid);
public FishingStrike(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(FishingMinigameActive[playerid]) return 0;
    
    StartFishingMinigame(playerid);
    return 1;
}

// ============================================================
// FUNGSI UTAMA FISHING
// ============================================================

IsPlayerInFishingArea(playerid)
{
    for(new x; x < sizeof(__g_FishingLoc); x++)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, __g_FishingLoc[x][0], __g_FishingLoc[x][1], __g_FishingLoc[x][2]) && GetPlayerVirtualWorld(playerid) == 0 && GetPlayerInterior(playerid) == 0)
        {
            return 1;
        }
    }
    return 0;
}

forward FishingFunc(playerid);
public FishingFunc(playerid)
{
    if(!PlayerHasItem(playerid, "Pancingan"))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        IsPlayerFishing[playerid] = false;
        ClearAnimations(playerid, true);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(playerid, 9);
        FishingButton[playerid] = BUTTON_NONE;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Pancingan!");
    }

    if(!IsPlayerInFishingArea(playerid))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        IsPlayerFishing[playerid] = false;
        ClearAnimations(playerid, true);
        StopLoopingAnim(playerid);
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
        RemovePlayerAttachedObject(playerid, 9);
        FishingButton[playerid] = BUTTON_NONE;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di Fishing Point/Fishing Area!");
    }
    FishingButton[playerid] = BUTTON_ALT;
    SendClientMessage(playerid, -1, "[i] Umpan anda bergerak, gunakan "YELLOW"'ALT' "WHITE"untuk strike!");
    
    return 1;
}

// ============================================================
// HOOKS
// ============================================================

hook OnGameModeInit()
{
    for(new x; x < sizeof(__g_FishingLoc); x++)
    {
        CreateDynamic3DTextLabel("[Y] "WHITE"Mancing", Y_GREEN, __g_FishingLoc[x][0], __g_FishingLoc[x][1], __g_FishingLoc[x][2], 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 2.5, -1, 0);
    }

    // CreateDynamic3DTextLabel("[Y] "WHITE"Jual Penyu", Y_RED, 2161.5310,-103.1758,2.7500, 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 2.5, -1, 0);
    // CreateDynamic3DTextLabel("[Y] "WHITE"Jual Hiu", Y_RED, -489.2872,613.1413,1.7813, 2.5, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 2.5, -1, 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    IsPlayerFishing[playerid] = false;
    FishingButton[playerid] = BUTTON_NONE;
    FishingMinigameActive[playerid] = false;
    FishingProgress[playerid] = 0;
    FishingTimer[playerid] = -1;
    FishingFailStreak[playerid] = 0; 
    CreateFishingUI(playerid);
    HideNotifTimer[playerid] = -1;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(FishingTimer[playerid] != -1)
    {
        KillTimer(FishingTimer[playerid]);
        FishingTimer[playerid] = -1;
    }
    if(HideNotifTimer[playerid] != -1)
    {
        KillTimer(HideNotifTimer[playerid]);
        HideNotifTimer[playerid] = -1;
    }
    FishingFailStreak[playerid] = 0; 
    return 1;
}

// Tombol untuk memulai fishing (Y)
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(FishingButton[playerid] == BUTTON_NONE)
    {
        if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
        {
            foreach(new i : FishSellIterator)
            {
                if(IsPlayerInRangeOfPoint(playerid, 3.0, FishSellData[i][sellX], FishSellData[i][sellY], FishSellData[i][sellZ]))
                {
                    if(AccountData[playerid][pActivityTime] != 0) 
                        return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!");

                    new dialogStr[512];
                    format(dialogStr, sizeof(dialogStr),"Ikan\t$%s\nPenyu\t$%s\nHiu\t$%s\nLumba-lumba\t$%s\nUbur-ubur\t$%s\nHiu Megalodon\t$%s",
                        FormatMoney(FishSellData[i][sellPriceIkan]),
                        FormatMoney(FishSellData[i][sellPricePenyu]),
                        FormatMoney(FishSellData[i][sellPriceHiu]),
                        FormatMoney(FishSellData[i][sellPriceLumbaLumba]),
                        FormatMoney(FishSellData[i][sellPriceUburUbur]),
                        FormatMoney(FishSellData[i][sellPriceMegalodon]));
                    
                    Dialog_Show(playerid, "DialogSellFish", DIALOG_STYLE_LIST, "Pilih Ikan yang Dijual", dialogStr, "Jual", "Batal");
                    SetPVarInt(playerid, "TempFishSellID", i);
                    return 1;
                }
            }

            if(IsPlayerInFishingArea(playerid))
            {
                if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT)
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berjalan kaki!");

                if(!PlayerHasItem(playerid, "Pancingan"))
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki pancingan!");

                if(!PlayerHasItem(playerid, "Umpan"))
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki umpan!");

                if(IsPlayerFishing[playerid])
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang memancing!");

                if(AccountData[playerid][pKnockdown])
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak bisa melakukannya saat ini!");

                new randfishtime = RandomEx(3000, 5000);
                new randevent = Random(101);

                Inventory_Remove(playerid, "Umpan", 1);
                switch(randevent)
                {
                    case 0.. 95: //fishing berhasil
                    {
                        SetTimerEx("FishingFunc", randfishtime, false, "i", playerid);
                        IsPlayerFishing[playerid] = true;
                        ApplyAnimation(playerid, "SWORD", "sword_block", 4.1, 0, 1, 1, 1, 1, 1);
                        SetPlayerAttachedObject(playerid, 9, 18632, 6, 0.00000, 0.00000, 0.00000, 0.00000, 180.00000, 90.00000, 1, 1, 1);
                        SendClientMessage(playerid, -1, "[i] Anda mulai memancing.");
                    }

                    case 96.. 101: //pancingan kecebur
                    {
                        Inventory_Remove(playerid, "Pancingan", 1);
                        SendClientMessage(playerid, -1, "[i] Saat anda ingin melemparkan umpan, pancingan anda ikut terlempar ke air.");
                    }
                }
                return 1;
            }
        }
    }
    if(FishingButton[playerid] != BUTTON_NONE)
    {
        new bool:correctKey = false;
        
        // Cuma cek tombol Y aja, karena button random udah dihapus
        if(FishingButton[playerid] == BUTTON_ALT)
        {
            if(newkeys & KEY_WALK)
                correctKey = true;
        }
        
        if(correctKey)
        {
            // Player menekan Y dengan benar
            IsPlayerFishing[playerid] = false;
            ClearAnimations(playerid, true);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            RemovePlayerAttachedObject(playerid, 9);
            
            StartFishingMinigame(playerid);
        }
        else if(newkeys != 0) // Player menekan tombol lain selain Y
        {
            // Gagal, ikan lepas
            IsPlayerFishing[playerid] = false;
            ClearAnimations(playerid, true);
            StopLoopingAnim(playerid);
            SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
            RemovePlayerAttachedObject(playerid, 9);
            FishingButton[playerid] = BUTTON_NONE;
            SendClientMessage(playerid, X11_YELLOW, "[FISHING] Anda salah menekan tombol, ikan lepas!");
            PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        }
        return 1;
    }
    if(newkeys & KEY_CTRL_BACK) // Tombol H
    {
        if(IsFishUsing[playerid])
        {
            if(IsPlayerAttachedObjectSlotUsed(playerid, 9))
            {
                RemoveFishFromPlayer(playerid);
                return 1;
            }
        }
    }
    return 1;
}