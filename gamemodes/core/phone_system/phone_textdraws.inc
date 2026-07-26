#define MAX_CONTACTS 100
new PlayerText: PhoneVRP[MAX_PLAYERS][73];
new PlayerText: LoginTwittVRP[MAX_PLAYERS][26];
new PlayerText: HomeTwittVRP[MAX_PLAYERS][29];
new PlayerText: PhoneBankVRP[MAX_PLAYERS][68];
new PlayerText: VehicleList[MAX_PLAYERS][45];
new PlayerText: MusicVRP[MAX_PLAYERS][107];
new PlayerText: UberVRP[MAX_PLAYERS][93];
new PlayerText: KalkulatorVRP[MAX_PLAYERS][59];
new PlayerText: CameraVRP[MAX_PLAYERS][60];
new PlayerText: KontakVRP[MAX_PLAYERS][70];
new 

    //appstore
    Text:AppStoreTD[26],
    Text:InstallWAButtonPhone,
    Text:InstallSpotifyButtonPhone,
    Text:InstallTwitterButtonPhone,
    Text:InstallUberButtonPhone,
    Text:InstallYellowButtonPhone,

    //settings
    Text:SettingsTD[3];

new PlayerText:ContactNameTD[MAX_PLAYERS],
    PlayerText:StatusDialingTD[MAX_PLAYERS],
    PlayerText:PhoneRebootBar[MAX_PLAYERS];

CreateHandphoneVRP(playerid)
{
    PhoneVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][0], 1);

    PhoneVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][1], 1);

    PhoneVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][2], 1);

    PhoneVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][3], 1);

    PhoneVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][4], 1);

    PhoneVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][5], 1);

    PhoneVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][6], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][6], 1);

    PhoneVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][7], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][7], 1);

    PhoneVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][8], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][8], 1);

    PhoneVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][9], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][9], 1);

    PhoneVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][10], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][10], 1);

    PhoneVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][11], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][11], 1);

    PhoneVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][12], 1);

    PhoneVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][13], 1);

    PhoneVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][14], 1);

    PhoneVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][15], 1);

    PhoneVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][16], 1);

    PhoneVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][17], 1);

    PhoneVRP[playerid][18] = CreatePlayerTextDraw(playerid, 565.000, 170.000, "12:13");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][18], 0.379, 1.999);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][18], 2);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][18], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][18], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][18], 1);

    PhoneVRP[playerid][19] = CreatePlayerTextDraw(playerid, 565.000, 187.000, "14 April 2026");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][19], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][19], 2);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][19], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][19], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][19], 1);

    PhoneVRP[playerid][20] = CreatePlayerTextDraw(playerid, 517.000, 208.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][20], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][20], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][20], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][20], 1);

    PhoneVRP[playerid][21] = CreatePlayerTextDraw(playerid, 541.000, 208.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][21], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][21], -5963521);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][21], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][21], 1);

    PhoneVRP[playerid][22] = CreatePlayerTextDraw(playerid, 565.000, 208.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][22], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][22], -1962934017);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][22], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][22], 1);

    PhoneVRP[playerid][23] = CreatePlayerTextDraw(playerid, 588.500, 208.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][23], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][23], 9145343);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][23], 1);

    PhoneVRP[playerid][24] = CreatePlayerTextDraw(playerid, 517.000, 241.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][24], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][24], 852308735);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][24], 1);

    PhoneVRP[playerid][25] = CreatePlayerTextDraw(playerid, 541.000, 241.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][25], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][25], -65281);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][25], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][25], 1);

    PhoneVRP[playerid][26] = CreatePlayerTextDraw(playerid, 565.000, 241.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][26], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][26], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][26], 1);

    PhoneVRP[playerid][27] = CreatePlayerTextDraw(playerid, 588.500, 241.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][27], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][27], -16776961);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][27], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][27], 1);

    PhoneVRP[playerid][28] = CreatePlayerTextDraw(playerid, 526.500, 339.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][28], 75.000, 27.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][28], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][28], 1);

    PhoneVRP[playerid][29] = CreatePlayerTextDraw(playerid, 509.000, 332.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][29], 37.000, 40.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][29], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][29], 1);

    PhoneVRP[playerid][30] = CreatePlayerTextDraw(playerid, 582.000, 332.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][30], 37.000, 40.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][30], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][30], 1);

    PhoneVRP[playerid][31] = CreatePlayerTextDraw(playerid, 526.500, 344.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][31], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][31], 16711935);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][31], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][31], 1);

    PhoneVRP[playerid][32] = CreatePlayerTextDraw(playerid, 545.500, 344.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][32], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][32], 1768516095);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][32], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][32], 1);

    PhoneVRP[playerid][33] = CreatePlayerTextDraw(playerid, 564.500, 344.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][33], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][33], 9145343);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][33], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][33], 1);

    PhoneVRP[playerid][34] = CreatePlayerTextDraw(playerid, 583.500, 344.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][34], 17.000, 17.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][34], 852308735);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][34], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][34], 1);

    PhoneVRP[playerid][35] = CreatePlayerTextDraw(playerid, 522.000, 210.000, "X");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][35], 0.339, 1.700);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][35], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][35], 1);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][35], -1);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][35], 1);

    PhoneVRP[playerid][36] = CreatePlayerTextDraw(playerid, 547.000, 214.000, "HUD:radar_gangY");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][36], 9.000, 8.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][36], 1);

    PhoneVRP[playerid][37] = CreatePlayerTextDraw(playerid, 573.000, 211.000, "V");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][37], 0.180, 1.899);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][37], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][37], 2);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][37], 1);

    PhoneVRP[playerid][38] = CreatePlayerTextDraw(playerid, 572.000, 212.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][38], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][38], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][38], 1);

    PhoneVRP[playerid][39] = CreatePlayerTextDraw(playerid, 574.000, 214.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][39], 3.000, 10.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][39], 1);

    PhoneVRP[playerid][40] = CreatePlayerTextDraw(playerid, 573.500, 213.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][40], 4.000, 6.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][40], -1962934017);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][40], 1);

    PhoneVRP[playerid][41] = CreatePlayerTextDraw(playerid, 596.000, 214.000, "HUD:radar_impound");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][41], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][41], 1);

    PhoneVRP[playerid][42] = CreatePlayerTextDraw(playerid, 519.000, 244.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][42], 19.000, 10.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][42], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][42], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][42], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][42], 1);

    PhoneVRP[playerid][43] = CreatePlayerTextDraw(playerid, 518.000, 246.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][43], 21.000, 9.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][43], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][43], 852308735);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][43], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][43], 1);

    PhoneVRP[playerid][44] = CreatePlayerTextDraw(playerid, 521.000, 247.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][44], 15.000, 9.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][44], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][44], 1);

    PhoneVRP[playerid][45] = CreatePlayerTextDraw(playerid, 520.000, 249.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][45], 17.000, 9.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][45], 852308735);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][45], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][45], 1);

    PhoneVRP[playerid][46] = CreatePlayerTextDraw(playerid, 523.000, 250.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][46], 11.000, 6.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][46], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][46], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][46], 1);

    PhoneVRP[playerid][47] = CreatePlayerTextDraw(playerid, 544.000, 244.000, "T");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][47], 0.329, 1.600);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][47], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][47], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][47], 2);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][47], 1);

    PhoneVRP[playerid][48] = CreatePlayerTextDraw(playerid, 550.000, 250.000, "rans");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][48], 0.129, 0.599);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][48], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][48], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][48], 1);

    PhoneVRP[playerid][49] = CreatePlayerTextDraw(playerid, 557.000, 239.000, "/");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][49], 0.329, 0.899);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][49], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][49], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][49], 2);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][49], 1);

    PhoneVRP[playerid][50] = CreatePlayerTextDraw(playerid, 540.000, 257.000, "/");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][50], 0.339, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][50], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][50], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][50], 2);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][50], 1);

    PhoneVRP[playerid][51] = CreatePlayerTextDraw(playerid, 577.000, 248.000, "=");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][51], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][51], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][51], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][51], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][51], 1);

    PhoneVRP[playerid][52] = CreatePlayerTextDraw(playerid, 577.000, 240.000, "-");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][52], 0.589, 1.500);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][52], -12254977);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][52], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][52], 2);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][52], 1);

    PhoneVRP[playerid][53] = CreatePlayerTextDraw(playerid, 568.000, 241.000, "+");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][53], 0.300, 1.399);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][53], 1768516095);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][53], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][53], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][53], 1);

    PhoneVRP[playerid][54] = CreatePlayerTextDraw(playerid, 568.500, 251.000, "X");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][54], 0.250, 0.999);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][54], 1768516095);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][54], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][54], 1);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][54], 1);

    PhoneVRP[playerid][55] = CreatePlayerTextDraw(playerid, 596.000, 248.000, "HUD:radar_ammugun");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][55], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][55], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][55], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][55], 1);

    PhoneVRP[playerid][56] = CreatePlayerTextDraw(playerid, 537.000, 344.000, "/");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][56], -0.229, 1.499);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][56], 2);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][56], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][56], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][56], 3);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][56], 1);

    PhoneVRP[playerid][57] = CreatePlayerTextDraw(playerid, 532.000, 346.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][57], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][57], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][57], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][57], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][57], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][57], 1);

    PhoneVRP[playerid][58] = CreatePlayerTextDraw(playerid, 533.000, 353.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][58], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][58], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][58], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][58], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][58], 1);

    PhoneVRP[playerid][59] = CreatePlayerTextDraw(playerid, 535.000, 356.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][59], 3.000, 2.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][59], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][59], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][59], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][59], 1);

    PhoneVRP[playerid][60] = CreatePlayerTextDraw(playerid, 533.000, 347.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][60], 3.000, 2.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][60], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][60], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][60], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][60], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][60], 1);

    PhoneVRP[playerid][61] = CreatePlayerTextDraw(playerid, 548.000, 345.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][61], 13.000, 14.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][61], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][61], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][61], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][61], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][61], 1);

    PhoneVRP[playerid][62] = CreatePlayerTextDraw(playerid, 550.000, 347.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][62], 9.000, 10.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][62], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][62], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][62], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][62], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][62], 1);

    PhoneVRP[playerid][63] = CreatePlayerTextDraw(playerid, 553.000, 350.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][63], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][63], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][63], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][63], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][63], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][63], 1);

    PhoneVRP[playerid][64] = CreatePlayerTextDraw(playerid, 554.000, 351.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][64], 1.000, 2.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][64], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][64], 255);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][64], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][64], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][64], 1);

    PhoneVRP[playerid][65] = CreatePlayerTextDraw(playerid, 552.000, 347.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][65], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][65], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][65], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][65], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][65], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][65], 1);

    PhoneVRP[playerid][66] = CreatePlayerTextDraw(playerid, 569.000, 345.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][66], 8.000, 9.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][66], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][66], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][66], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][66], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][66], 1);

    PhoneVRP[playerid][67] = CreatePlayerTextDraw(playerid, 566.500, 352.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][67], 13.000, 8.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][67], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][67], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][67], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][67], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][67], 1);

    PhoneVRP[playerid][68] = CreatePlayerTextDraw(playerid, 585.500, 347.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][68], 15.000, 11.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][68], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][68], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][68], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][68], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][68], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][68], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][68], 1);

    PhoneVRP[playerid][69] = CreatePlayerTextDraw(playerid, 592.000, 350.000, "/");
    PlayerTextDrawLetterSize(playerid, PhoneVRP[playerid][69], 0.610, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][69], 2);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][69], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][69], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][69], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][69], 150);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][69], 3);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][69], 1);

    PhoneVRP[playerid][70] = CreatePlayerTextDraw(playerid, 517.000, 274.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][70], 21.000, 22.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][70], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][70], -2016478465);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][70], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][70], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][70], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][70], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][70], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][70], 1);

    PhoneVRP[playerid][71] = CreatePlayerTextDraw(playerid, 521.000, 279.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][71], 14.000, 10.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][71], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][71], -1);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][71], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][71], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][71], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][71], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][71], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneVRP[playerid][71], 1);

    PhoneVRP[playerid][72] = CreatePlayerTextDraw(playerid, 523.000, 281.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneVRP[playerid][72], 12.000, 2.000);
    PlayerTextDrawAlignment(playerid, PhoneVRP[playerid][72], 1);
    PlayerTextDrawColor(playerid, PhoneVRP[playerid][72], -2016478465);
    PlayerTextDrawSetShadow(playerid, PhoneVRP[playerid][72], 0);
    PlayerTextDrawSetOutline(playerid, PhoneVRP[playerid][72], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneVRP[playerid][72], 255);
    PlayerTextDrawFont(playerid, PhoneVRP[playerid][72], 4);
    PlayerTextDrawSetProportional(playerid, PhoneVRP[playerid][72], 1);
}

CreateLoginTwitt(playerid)
{
    LoginTwittVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][0], 1);

    LoginTwittVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][1], 1);

    LoginTwittVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][2], 1);

    LoginTwittVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][3], 1);

    LoginTwittVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][4], 1);

    LoginTwittVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][5], 1);

    LoginTwittVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][6], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][6], 1);

    LoginTwittVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][7], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][7], 1);

    LoginTwittVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][8], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][8], 1);

    LoginTwittVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][9], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][9], 1);

    LoginTwittVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][10], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][10], 1);

    LoginTwittVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][11], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][11], 1);

    LoginTwittVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][12], 1);

    LoginTwittVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][13], 1);

    LoginTwittVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][14], 1);

    LoginTwittVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, LoginTwittVRP[playerid][15], 1);

    LoginTwittVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][16], 1);

    LoginTwittVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][17], 1);

    LoginTwittVRP[playerid][18] = CreatePlayerTextDraw(playerid, 563.000, 171.000, "X");
    PlayerTextDrawLetterSize(playerid, LoginTwittVRP[playerid][18], 0.569, 3.199);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][18], 2);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][18], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][18], 1);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][18], -1);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][18], 1);

    LoginTwittVRP[playerid][19] = CreatePlayerTextDraw(playerid, 564.000, 212.000, "Welcome to Twitt");
    PlayerTextDrawLetterSize(playerid, LoginTwittVRP[playerid][19], 0.159, 1.199);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][19], 2);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][19], -1);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][19], 1);

    LoginTwittVRP[playerid][20] = CreatePlayerTextDraw(playerid, 535.000, 265.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][20], 60.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][20], 1);

    LoginTwittVRP[playerid][21] = CreatePlayerTextDraw(playerid, 535.000, 286.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][21], 60.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][21], 1);

    LoginTwittVRP[playerid][22] = CreatePlayerTextDraw(playerid, 535.500, 266.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][22], 59.000, 11.500);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][22], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][22], 1);
    PlayerTextDrawSetSelectable(playerid, LoginTwittVRP[playerid][22], 1);

    LoginTwittVRP[playerid][23] = CreatePlayerTextDraw(playerid, 535.500, 287.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginTwittVRP[playerid][23], 59.000, 11.500);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][23], 252975615);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, LoginTwittVRP[playerid][23], 1);

    LoginTwittVRP[playerid][24] = CreatePlayerTextDraw(playerid, 565.000, 267.000, "Login");
    PlayerTextDrawLetterSize(playerid, LoginTwittVRP[playerid][24], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][24], 2);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][24], -1);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][24], 1);

    LoginTwittVRP[playerid][25] = CreatePlayerTextDraw(playerid, 565.000, 288.000, "Register");
    PlayerTextDrawLetterSize(playerid, LoginTwittVRP[playerid][25], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, LoginTwittVRP[playerid][25], 2);
    PlayerTextDrawColor(playerid, LoginTwittVRP[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, LoginTwittVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, LoginTwittVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginTwittVRP[playerid][25], -1);
    PlayerTextDrawFont(playerid, LoginTwittVRP[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, LoginTwittVRP[playerid][25], 1);
}

CreateHomeTwitter(playerid)
{
    HomeTwittVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][0], 1);

    HomeTwittVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][1], 1);

    HomeTwittVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][2], 1);

    HomeTwittVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][3], 1);

    HomeTwittVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][4], 1);

    HomeTwittVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][5], 1);

    HomeTwittVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][6], 252975615);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][6], 1);

    HomeTwittVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][7], 252975615);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][7], 1);

    HomeTwittVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][8], 252975615);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][8], 1);

    HomeTwittVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][9], 252975615);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][9], 1);

    HomeTwittVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][10], 252975615);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][10], 1);

    HomeTwittVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][11], 252975615);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][11], 1);

    HomeTwittVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][12], 1);

    HomeTwittVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][13], 1);

    HomeTwittVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][14], 1);

    HomeTwittVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, HomeTwittVRP[playerid][15], 1);

    HomeTwittVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][16], 1);

    HomeTwittVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][17], 1);

    HomeTwittVRP[playerid][18] = CreatePlayerTextDraw(playerid, 588.500, 346.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][18], 18.000, 16.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][18], 445438207);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][18], 1);

    HomeTwittVRP[playerid][19] = CreatePlayerTextDraw(playerid, 587.000, 341.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][19], 9.000, 11.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][19], 445438207);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][19], 1);

    HomeTwittVRP[playerid][20] = CreatePlayerTextDraw(playerid, 599.000, 341.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][20], 9.000, 11.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][20], 445438207);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][20], 1);

    HomeTwittVRP[playerid][21] = CreatePlayerTextDraw(playerid, 587.000, 356.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][21], 9.000, 11.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][21], 445438207);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][21], 1);

    HomeTwittVRP[playerid][22] = CreatePlayerTextDraw(playerid, 599.000, 356.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][22], 9.000, 11.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][22], 445438207);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][22], 1);

    HomeTwittVRP[playerid][23] = CreatePlayerTextDraw(playerid, 590.500, 342.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][23], 13.000, 23.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][23], 445438207);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, HomeTwittVRP[playerid][23], 1);

    HomeTwittVRP[playerid][24] = CreatePlayerTextDraw(playerid, 594.000, 347.000, "+");
    PlayerTextDrawLetterSize(playerid, HomeTwittVRP[playerid][24], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][24], 150);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][24], 1);

    HomeTwittVRP[playerid][25] = CreatePlayerTextDraw(playerid, 510.500, 146.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][25], 107.000, 1.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][25], 539305471);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][25], 1);

    HomeTwittVRP[playerid][26] = CreatePlayerTextDraw(playerid, 515.000, 130.000, "Home");
    PlayerTextDrawLetterSize(playerid, HomeTwittVRP[playerid][26], 0.250, 1.399);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][26], 150);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][26], 1);

    HomeTwittVRP[playerid][27] = CreatePlayerTextDraw(playerid, 596.000, 124.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][27], 20.000, 22.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][27], 539305471);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][27], 1);
    PlayerTextDrawSetSelectable(playerid, HomeTwittVRP[playerid][27], 1);

    HomeTwittVRP[playerid][28] = CreatePlayerTextDraw(playerid, 601.500, 131.000, "HUD:radar_gangB");
    PlayerTextDrawTextSize(playerid, HomeTwittVRP[playerid][28], 8.000, 9.000);
    PlayerTextDrawAlignment(playerid, HomeTwittVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, HomeTwittVRP[playerid][28], 255);
    PlayerTextDrawSetShadow(playerid, HomeTwittVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, HomeTwittVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, HomeTwittVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, HomeTwittVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, HomeTwittVRP[playerid][28], 1);
}

CreatePhoneBank(playerid)
{
    PhoneBankVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][0], 1);

    PhoneBankVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][1], 1);

    PhoneBankVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][2], 1);

    PhoneBankVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][3], 1);

    PhoneBankVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][4], 1);

    PhoneBankVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][5], 1);

    PhoneBankVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][6], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][6], 1);

    PhoneBankVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][7], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][7], 1);

    PhoneBankVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][8], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][8], 1);

    PhoneBankVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][9], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][9], 1);

    PhoneBankVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][10], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][10], 1);

    PhoneBankVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][11], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][11], 1);

    PhoneBankVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][12], 1);

    PhoneBankVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][13], 1);

    PhoneBankVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][14], 1);

    PhoneBankVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneBankVRP[playerid][15], 1);

    PhoneBankVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][16], 1);

    PhoneBankVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][17], 1);

    PhoneBankVRP[playerid][18] = CreatePlayerTextDraw(playerid, 511.000, 142.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][18], 106.000, 36.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][18], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][18], 1);

    PhoneBankVRP[playerid][19] = CreatePlayerTextDraw(playerid, 511.000, 143.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][19], 106.000, 34.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][19], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][19], 1);

    PhoneBankVRP[playerid][20] = CreatePlayerTextDraw(playerid, 518.500, 187.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][20], 90.000, 60.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][20], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][20], 1);

    PhoneBankVRP[playerid][21] = CreatePlayerTextDraw(playerid, 510.000, 183.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][21], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][21], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][21], 1);

    PhoneBankVRP[playerid][22] = CreatePlayerTextDraw(playerid, 510.000, 230.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][22], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][22], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][22], 1);

    PhoneBankVRP[playerid][23] = CreatePlayerTextDraw(playerid, 599.000, 230.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][23], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][23], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][23], 1);

    PhoneBankVRP[playerid][24] = CreatePlayerTextDraw(playerid, 599.000, 183.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][24], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][24], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][24], 1);

    PhoneBankVRP[playerid][25] = CreatePlayerTextDraw(playerid, 513.500, 194.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][25], 101.000, 48.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][25], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][25], 1);

    PhoneBankVRP[playerid][26] = CreatePlayerTextDraw(playerid, 511.000, 184.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][26], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][26], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][26], 1);

    PhoneBankVRP[playerid][27] = CreatePlayerTextDraw(playerid, 511.000, 229.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][27], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][27], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][27], 1);

    PhoneBankVRP[playerid][28] = CreatePlayerTextDraw(playerid, 598.000, 229.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][28], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][28], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][28], 1);

    PhoneBankVRP[playerid][29] = CreatePlayerTextDraw(playerid, 598.000, 184.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][29], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][29], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][29], 1);

    PhoneBankVRP[playerid][30] = CreatePlayerTextDraw(playerid, 518.500, 188.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][30], 90.000, 58.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][30], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][30], 1);

    PhoneBankVRP[playerid][31] = CreatePlayerTextDraw(playerid, 514.000, 195.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][31], 99.500, 45.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][31], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][31], 1);

    PhoneBankVRP[playerid][32] = CreatePlayerTextDraw(playerid, 519.000, 265.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][32], 90.000, 33.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][32], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][32], 1);

    PhoneBankVRP[playerid][33] = CreatePlayerTextDraw(playerid, 512.000, 262.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][33], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][33], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][33], 1);

    PhoneBankVRP[playerid][34] = CreatePlayerTextDraw(playerid, 512.000, 283.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][34], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][34], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][34], 1);

    PhoneBankVRP[playerid][35] = CreatePlayerTextDraw(playerid, 600.000, 283.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][35], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][35], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][35], 1);

    PhoneBankVRP[playerid][36] = CreatePlayerTextDraw(playerid, 600.000, 262.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][36], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][36], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][36], 1);

    PhoneBankVRP[playerid][37] = CreatePlayerTextDraw(playerid, 514.500, 270.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][37], 99.000, 22.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][37], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][37], 1);

    PhoneBankVRP[playerid][38] = CreatePlayerTextDraw(playerid, 513.000, 263.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][38], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][38], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][38], 1);

    PhoneBankVRP[playerid][39] = CreatePlayerTextDraw(playerid, 513.000, 282.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][39], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][39], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][39], 1);

    PhoneBankVRP[playerid][40] = CreatePlayerTextDraw(playerid, 599.000, 282.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][40], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][40], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][40], 1);

    PhoneBankVRP[playerid][41] = CreatePlayerTextDraw(playerid, 599.000, 263.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][41], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][41], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][41], 1);

    PhoneBankVRP[playerid][42] = CreatePlayerTextDraw(playerid, 515.500, 270.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][42], 97.000, 22.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][42], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][42], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][42], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][42], 1);

    PhoneBankVRP[playerid][43] = CreatePlayerTextDraw(playerid, 520.500, 266.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][43], 88.000, 30.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][43], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][43], 220149247);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][43], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][43], 1);

    PhoneBankVRP[playerid][44] = CreatePlayerTextDraw(playerid, 521.500, 227.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][44], 14.500, 11.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][44], 254231807);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][44], 1);

    PhoneBankVRP[playerid][45] = CreatePlayerTextDraw(playerid, 526.500, 231.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][45], 5.500, 3.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][45], 1338243071);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][45], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][45], 1);

    PhoneBankVRP[playerid][46] = CreatePlayerTextDraw(playerid, 600.000, 274.000, ">");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][46], 0.150, 1.299);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][46], 1517984511);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][46], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][46], 2);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][46], 1);

    PhoneBankVRP[playerid][47] = CreatePlayerTextDraw(playerid, 516.000, 147.000, "Selamat datang.");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][47], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][47], -2003195137);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][47], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][47], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][47], 1);

    PhoneBankVRP[playerid][48] = CreatePlayerTextDraw(playerid, 516.000, 155.000, "Ronnie Varquez");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][48], 0.200, 1.199);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][48], -521472513);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][48], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][48], 1);

    PhoneBankVRP[playerid][49] = CreatePlayerTextDraw(playerid, 523.000, 194.000, "SALDO REKENING");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][49], 0.129, 0.899);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][49], -2003195137);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][49], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][49], 2);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][49], 1);

    PhoneBankVRP[playerid][50] = CreatePlayerTextDraw(playerid, 522.000, 207.000, "$200.000");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][50], 0.339, 1.700);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][50], 1338243071);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][50], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][50], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][50], 1);

    PhoneBankVRP[playerid][51] = CreatePlayerTextDraw(playerid, 516.000, 253.000, "LAYANAN");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][51], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][51], -2003195137);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][51], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][51], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][51], 1);

    PhoneBankVRP[playerid][52] = CreatePlayerTextDraw(playerid, 539.000, 229.000, "12212121212");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][52], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][52], 1517984511);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][52], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][52], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][52], 1);

    PhoneBankVRP[playerid][53] = CreatePlayerTextDraw(playerid, 521.500, 273.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][53], 17.500, 17.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][53], 254231807);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][53], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][53], 1);
    PlayerTextDrawSetSelectable(playerid, PhoneBankVRP[playerid][53], 1);

    PhoneBankVRP[playerid][54] = CreatePlayerTextDraw(playerid, 526.500, 280.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][54], 8.500, 1.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][54], 1338243071);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][54], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][54], 1);

    PhoneBankVRP[playerid][55] = CreatePlayerTextDraw(playerid, 530.000, 273.000, ">");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][55], 0.280, 1.700);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][55], 1338243071);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][55], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][55], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][55], 1);

    PhoneBankVRP[playerid][56] = CreatePlayerTextDraw(playerid, 543.000, 272.000, "Transfer");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][56], 0.170, 0.999);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][56], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][56], -1);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][56], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][56], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][56], 1);

    PhoneBankVRP[playerid][57] = CreatePlayerTextDraw(playerid, 543.000, 281.000, "Kirim ke rekening lain");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][57], 0.129, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][57], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][57], 1517984511);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][57], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][57], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][57], 1);

    PhoneBankVRP[playerid][58] = CreatePlayerTextDraw(playerid, 516.000, 306.000, "TRANSAKSI TERAKHIR");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][58], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][58], -2003195137);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][58], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][58], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][58], 1);

    PhoneBankVRP[playerid][59] = CreatePlayerTextDraw(playerid, 516.000, 318.000, "Transfer masuk");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][59], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][59], -1);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][59], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][59], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][59], 1);

    PhoneBankVRP[playerid][60] = CreatePlayerTextDraw(playerid, 516.000, 327.000, "16 Apr 2026");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][60], 0.108, 0.699);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][60], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][60], 1517984511);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][60], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][60], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][60], 1);

    PhoneBankVRP[playerid][61] = CreatePlayerTextDraw(playerid, 586.000, 324.000, "+$500.000");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][61], 0.129, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][61], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][61], 1286557951);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][61], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][61], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][61], 1);

    PhoneBankVRP[playerid][62] = CreatePlayerTextDraw(playerid, 516.500, 338.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][62], 93.500, 0.500);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][62], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][62], 507140863);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][62], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][62], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][62], 1);

    PhoneBankVRP[playerid][63] = CreatePlayerTextDraw(playerid, 516.000, 344.000, "Transfer Keluar");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][63], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][63], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][63], -1);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][63], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][63], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][63], 1);

    PhoneBankVRP[playerid][64] = CreatePlayerTextDraw(playerid, 516.000, 353.000, "15 Apr 2026");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][64], 0.109, 0.699);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][64], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][64], 1517984511);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][64], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][64], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][64], 1);

    PhoneBankVRP[playerid][65] = CreatePlayerTextDraw(playerid, 586.000, 349.000, "-$200.000");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][65], 0.129, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][65], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][65], -279752449);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][65], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][65], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][65], 1);

    PhoneBankVRP[playerid][66] = CreatePlayerTextDraw(playerid, 516.000, 127.000, "9:14");
    PlayerTextDrawLetterSize(playerid, PhoneBankVRP[playerid][66], 0.138, 0.799);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][66], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][66], 1517984511);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][66], 150);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][66], 1);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][66], 1);

    PhoneBankVRP[playerid][67] = CreatePlayerTextDraw(playerid, 605.000, 133.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, PhoneBankVRP[playerid][67], 3.500, 4.000);
    PlayerTextDrawAlignment(playerid, PhoneBankVRP[playerid][67], 1);
    PlayerTextDrawColor(playerid, PhoneBankVRP[playerid][67], 169224447);
    PlayerTextDrawSetShadow(playerid, PhoneBankVRP[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, PhoneBankVRP[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, PhoneBankVRP[playerid][67], 255);
    PlayerTextDrawFont(playerid, PhoneBankVRP[playerid][67], 4);
    PlayerTextDrawSetProportional(playerid, PhoneBankVRP[playerid][67], 1);
}

CreatePhoneIncomingTD(playerid)
{
    ContactNameTD[playerid] = CreatePlayerTextDraw(playerid, 574.000000, 250.000000, "Mang Ucok Penjual Roti");
    PlayerTextDrawFont(playerid, ContactNameTD[playerid], true);
    PlayerTextDrawLetterSize(playerid, ContactNameTD[playerid], 0.220833, 1.250000);
    PlayerTextDrawTextSize(playerid, ContactNameTD[playerid], 400.000000, 90.500000);
    PlayerTextDrawSetOutline(playerid, ContactNameTD[playerid], false);
    PlayerTextDrawSetShadow(playerid, ContactNameTD[playerid], false);
    PlayerTextDrawAlignment(playerid, ContactNameTD[playerid], 2);
    PlayerTextDrawColor(playerid, ContactNameTD[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, ContactNameTD[playerid], 255);
    PlayerTextDrawBoxColor(playerid, ContactNameTD[playerid], 50);
    PlayerTextDrawUseBox(playerid, ContactNameTD[playerid], false);
    PlayerTextDrawSetProportional(playerid, ContactNameTD[playerid], true);
    PlayerTextDrawSetSelectable(playerid, ContactNameTD[playerid], false);

    StatusDialingTD[playerid] = CreatePlayerTextDraw(playerid, 574.000000, 264.000000, "Panggilan Masuk...");
    PlayerTextDrawFont(playerid, StatusDialingTD[playerid], true);
    PlayerTextDrawLetterSize(playerid, StatusDialingTD[playerid], 0.220833, 1.250000);
    PlayerTextDrawTextSize(playerid, StatusDialingTD[playerid], 400.000000, 90.500000);
    PlayerTextDrawSetOutline(playerid, StatusDialingTD[playerid], false);
    PlayerTextDrawSetShadow(playerid, StatusDialingTD[playerid], false);
    PlayerTextDrawAlignment(playerid, StatusDialingTD[playerid], 2);
    PlayerTextDrawColor(playerid, StatusDialingTD[playerid], -1);
    PlayerTextDrawBackgroundColor(playerid, StatusDialingTD[playerid], 255);
    PlayerTextDrawBoxColor(playerid, StatusDialingTD[playerid], 50);
    PlayerTextDrawUseBox(playerid, StatusDialingTD[playerid], false);
    PlayerTextDrawSetProportional(playerid, StatusDialingTD[playerid], true);
    PlayerTextDrawSetSelectable(playerid, StatusDialingTD[playerid], false);
}

CreateVehicleListTD(playerid)
{
    VehicleList[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][0], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][0], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][0], 1);

    VehicleList[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][1], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][1], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][1], 1);

    VehicleList[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][2], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][2], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][2], 1);

    VehicleList[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][3], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][3], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][3], 1);

    VehicleList[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][4], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][4], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][4], 1);

    VehicleList[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][5], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][5], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][5], 1);

    VehicleList[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][6], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][6], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][6], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][6], 1);

    VehicleList[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][7], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][7], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][7], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][7], 1);

    VehicleList[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][8], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][8], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][8], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][8], 1);

    VehicleList[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][9], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][9], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][9], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][9], 1);

    VehicleList[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][10], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][10], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][10], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][10], 1);

    VehicleList[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][11], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][11], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][11], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][11], 1);

    VehicleList[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][12], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][12], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][12], 1);

    VehicleList[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][13], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][13], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][13], 1);

    VehicleList[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][14], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][14], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][14], 1);

    VehicleList[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][15], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][15], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, VehicleList[playerid][15], 1);

    VehicleList[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][16], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][16], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][16], 1);

    VehicleList[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][17], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][17], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][17], 1);

    VehicleList[playerid][18] = CreatePlayerTextDraw(playerid, 515.500, 150.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][18], 96.000, 0.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][18], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][18], 506282751);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][18], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][18], 1);

    VehicleList[playerid][19] = CreatePlayerTextDraw(playerid, 517.500, 134.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][19], 11.000, 7.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][19], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][19], 981194239);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][19], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][19], 1);

    VehicleList[playerid][20] = CreatePlayerTextDraw(playerid, 520.500, 132.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][20], 5.000, 2.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][20], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][20], 981194239);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][20], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][20], 1);

    VehicleList[playerid][21] = CreatePlayerTextDraw(playerid, 524.000, 136.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][21], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][21], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][21], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][21], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][21], 1);

    VehicleList[playerid][22] = CreatePlayerTextDraw(playerid, 518.500, 136.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][22], 4.000, 5.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][22], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][22], 169224447);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][22], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][22], 1);

    VehicleList[playerid][23] = CreatePlayerTextDraw(playerid, 533.000, 128.000, "MY~n~VEHICLE");
    PlayerTextDrawLetterSize(playerid, VehicleList[playerid][23], 0.220, 0.899);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][23], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][23], -1968321281);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][23], 150);
    PlayerTextDrawFont(playerid, VehicleList[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][23], 1);

    VehicleList[playerid][24] = CreatePlayerTextDraw(playerid, 587.500, 127.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][24], 20.000, 18.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][24], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][24], 507139583);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][24], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][24], 1);

    VehicleList[playerid][25] = CreatePlayerTextDraw(playerid, 581.000, 124.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][25], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][25], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][25], 507139583);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][25], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][25], 1);

    VehicleList[playerid][26] = CreatePlayerTextDraw(playerid, 581.000, 134.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][26], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][26], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][26], 507139583);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][26], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][26], 1);

    VehicleList[playerid][27] = CreatePlayerTextDraw(playerid, 601.000, 134.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][27], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][27], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][27], 507139583);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][27], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][27], 1);

    VehicleList[playerid][28] = CreatePlayerTextDraw(playerid, 601.000, 124.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][28], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][28], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][28], 507139583);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][28], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][28], 1);

    VehicleList[playerid][29] = CreatePlayerTextDraw(playerid, 582.500, 131.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][29], 28.500, 9.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][29], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][29], 507139583);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][29], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][29], 1);

    VehicleList[playerid][30] = CreatePlayerTextDraw(playerid, 581.500, 125.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][30], 11.000, 12.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][30], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][30], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][30], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][30], 1);

    VehicleList[playerid][31] = CreatePlayerTextDraw(playerid, 581.500, 134.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][31], 11.000, 12.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][31], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][31], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][31], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][31], 1);

    VehicleList[playerid][32] = CreatePlayerTextDraw(playerid, 601.500, 134.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][32], 11.000, 12.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][32], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][32], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][32], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][32], 1);

    VehicleList[playerid][33] = CreatePlayerTextDraw(playerid, 601.500, 125.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][33], 11.000, 12.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][33], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][33], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][33], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][33], 1);

    VehicleList[playerid][34] = CreatePlayerTextDraw(playerid, 587.500, 127.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][34], 20.000, 17.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][34], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][34], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][34], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][34], 1);

    VehicleList[playerid][35] = CreatePlayerTextDraw(playerid, 583.000, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][35], 27.500, 9.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][35], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][35], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][35], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][35], 1);

    VehicleList[playerid][36] = CreatePlayerTextDraw(playerid, 586.000, 128.500, "Page");
    PlayerTextDrawLetterSize(playerid, VehicleList[playerid][36], 0.160, 0.799);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][36], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][36], 981194239);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][36], 150);
    PlayerTextDrawFont(playerid, VehicleList[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][36], 1);

    VehicleList[playerid][37] = CreatePlayerTextDraw(playerid, 586.000, 136.000, "1/2");
    PlayerTextDrawLetterSize(playerid, VehicleList[playerid][37], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][37], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][37], 981194239);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][37], 150);
    PlayerTextDrawFont(playerid, VehicleList[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][37], 1);

    VehicleList[playerid][38] = CreatePlayerTextDraw(playerid, 515.500, 353.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][38], 96.000, 0.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][38], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][38], 506282751);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][38], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][38], 1);

    VehicleList[playerid][39] = CreatePlayerTextDraw(playerid, 592.500, 360.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][39], 19.000, 11.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][39], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][39], 439374079);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][39], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, VehicleList[playerid][39], 1);

    VehicleList[playerid][40] = CreatePlayerTextDraw(playerid, 515.500, 360.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][40], 19.000, 11.500);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][40], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][40], 438646271);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][40], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][40], 1);
    PlayerTextDrawSetSelectable(playerid, VehicleList[playerid][40], 1);

    VehicleList[playerid][41] = CreatePlayerTextDraw(playerid, 601.000, 361.000, ">");
    PlayerTextDrawLetterSize(playerid, VehicleList[playerid][41], 0.119, 0.999);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][41], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][41], 709193983);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][41], 150);
    PlayerTextDrawFont(playerid, VehicleList[playerid][41], 2);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][41], 1);

    VehicleList[playerid][42] = CreatePlayerTextDraw(playerid, 526.000, 361.000, ">");
    PlayerTextDrawLetterSize(playerid, VehicleList[playerid][42], -0.119, 0.999);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][42], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][42], 607473919);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][42], 150);
    PlayerTextDrawFont(playerid, VehicleList[playerid][42], 2);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][42], 1);

    VehicleList[playerid][43] = CreatePlayerTextDraw(playerid, 556.000, 361.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][43], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][43], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][43], 981194239);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][43], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][43], 1);

    VehicleList[playerid][44] = CreatePlayerTextDraw(playerid, 564.000, 361.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, VehicleList[playerid][44], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, VehicleList[playerid][44], 1);
    PlayerTextDrawColor(playerid, VehicleList[playerid][44], 253636863);
    PlayerTextDrawSetShadow(playerid, VehicleList[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, VehicleList[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, VehicleList[playerid][44], 255);
    PlayerTextDrawFont(playerid, VehicleList[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, VehicleList[playerid][44], 1);
}

CreateMusicTD(playerid)
{
    MusicVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][0], 1);

    MusicVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][1], 1);

    MusicVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][2], 1);

    MusicVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][3], 1);

    MusicVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][4], 1);

    MusicVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][5], 1);

    MusicVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][6], 169480447);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][6], 1);

    MusicVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][7], 169480447);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][7], 1);

    MusicVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][8], 169480447);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][8], 1);

    MusicVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][9], 169480447);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][9], 1);

    MusicVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][10], 169480447);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][10], 1);

    MusicVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][11], 169480447);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][11], 1);

    MusicVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][12], 1);

    MusicVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][13], 1);

    MusicVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][14], 1);

    MusicVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, MusicVRP[playerid][15], 1);

    MusicVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][16], 1);

    MusicVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][17], 1);

    MusicVRP[playerid][18] = CreatePlayerTextDraw(playerid, 515.500, 150.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][18], 96.000, 0.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][18], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][18], 1);

    MusicVRP[playerid][19] = CreatePlayerTextDraw(playerid, 511.000, 123.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][19], 25.000, 26.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][19], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][19], 1);

    MusicVRP[playerid][20] = CreatePlayerTextDraw(playerid, 517.000, 129.000, "LD_GRAV:beea");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][20], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][20], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][20], 1);

    MusicVRP[playerid][21] = CreatePlayerTextDraw(playerid, 534.000, 132.000, "MUSIC");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][21], 0.230, 1.099);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][21], 1521318655);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][21], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][21], 1);

    MusicVRP[playerid][22] = CreatePlayerTextDraw(playerid, 590.000, 131.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][22], 16.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][22], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][22], 1);

    MusicVRP[playerid][23] = CreatePlayerTextDraw(playerid, 599.000, 128.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][23], 16.000, 19.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][23], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][23], 1);

    MusicVRP[playerid][24] = CreatePlayerTextDraw(playerid, 582.000, 128.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][24], 16.000, 19.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][24], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][24], 1);

    MusicVRP[playerid][25] = CreatePlayerTextDraw(playerid, 583.000, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][25], 16.000, 17.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][25], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][25], 1);

    MusicVRP[playerid][26] = CreatePlayerTextDraw(playerid, 598.000, 129.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][26], 16.000, 17.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][26], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][26], 1);

    MusicVRP[playerid][27] = CreatePlayerTextDraw(playerid, 590.000, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][27], 16.000, 11.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][27], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][27], 1);

    MusicVRP[playerid][28] = CreatePlayerTextDraw(playerid, 599.000, 133.000, "Audio");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][28], 0.170, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][28], 2);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][28], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][28], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][28], 1);

    MusicVRP[playerid][29] = CreatePlayerTextDraw(playerid, 517.000, 154.000, "Pilih mode audio");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][29], 0.150, 0.899);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][29], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][29], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][29], 1);

    MusicVRP[playerid][30] = CreatePlayerTextDraw(playerid, 593.000, 163.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][30], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][30], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][30], 1);

    MusicVRP[playerid][31] = CreatePlayerTextDraw(playerid, 523.000, 167.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][31], 80.000, 72.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][31], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][31], 1);

    MusicVRP[playerid][32] = CreatePlayerTextDraw(playerid, 512.000, 163.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][32], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][32], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][32], 1);

    MusicVRP[playerid][33] = CreatePlayerTextDraw(playerid, 512.000, 220.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][33], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][33], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][33], 1);

    MusicVRP[playerid][34] = CreatePlayerTextDraw(playerid, 593.000, 220.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][34], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][34], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][34], 1);

    MusicVRP[playerid][35] = CreatePlayerTextDraw(playerid, 515.500, 174.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][35], 95.500, 58.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][35], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][35], 1);

    MusicVRP[playerid][36] = CreatePlayerTextDraw(playerid, 592.000, 164.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][36], 22.000, 24.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][36], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][36], 1);

    MusicVRP[playerid][37] = CreatePlayerTextDraw(playerid, 513.000, 164.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][37], 22.000, 25.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][37], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][37], 1);

    MusicVRP[playerid][38] = CreatePlayerTextDraw(playerid, 592.000, 219.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][38], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][38], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][38], 1);

    MusicVRP[playerid][39] = CreatePlayerTextDraw(playerid, 513.000, 219.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][39], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][39], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][39], 1);

    MusicVRP[playerid][40] = CreatePlayerTextDraw(playerid, 516.500, 177.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][40], 93.800, 54.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][40], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][40], 1);

    MusicVRP[playerid][41] = CreatePlayerTextDraw(playerid, 523.500, 168.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][41], 81.800, 69.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][41], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][41], 1);

    MusicVRP[playerid][42] = CreatePlayerTextDraw(playerid, 520.000, 172.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][42], 87.000, 61.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][42], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][42], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][42], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][42], 1);
    PlayerTextDrawSetSelectable(playerid, MusicVRP[playerid][42], 1);

    MusicVRP[playerid][43] = CreatePlayerTextDraw(playerid, 522.000, 175.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][43], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][43], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][43], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][43], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][43], 1);

    MusicVRP[playerid][44] = CreatePlayerTextDraw(playerid, 523.000, 176.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][44], 17.000, 18.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][44], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][44], 1);

    MusicVRP[playerid][45] = CreatePlayerTextDraw(playerid, 545.000, 173.000, "Boombox");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][45], 0.170, 1.099);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][45], -923739905);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][45], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][45], 1);

    MusicVRP[playerid][46] = CreatePlayerTextDraw(playerid, 545.000, 173.000, "Boombox");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][46], 0.170, 1.099);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][46], -923739905);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][46], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][46], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][46], 1);

    MusicVRP[playerid][47] = CreatePlayerTextDraw(playerid, 545.000, 183.000, "Speaker public");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][47], 0.109, 0.699);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][47], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][47], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][47], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][47], 1);

    MusicVRP[playerid][48] = CreatePlayerTextDraw(playerid, 545.000, 188.500, "area");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][48], 0.109, 0.699);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][48], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][48], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][48], 1);

    MusicVRP[playerid][49] = CreatePlayerTextDraw(playerid, 520.000, 198.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][49], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][49], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][49], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][49], 1);

    MusicVRP[playerid][50] = CreatePlayerTextDraw(playerid, 520.000, 221.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][50], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][50], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][50], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][50], 1);

    MusicVRP[playerid][51] = CreatePlayerTextDraw(playerid, 522.000, 205.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][51], 84.000, 22.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][51], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][51], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][51], 1);

    MusicVRP[playerid][52] = CreatePlayerTextDraw(playerid, 596.000, 198.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][52], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][52], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][52], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][52], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][52], 1);

    MusicVRP[playerid][53] = CreatePlayerTextDraw(playerid, 596.000, 221.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][53], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][53], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][53], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][53], 1);

    MusicVRP[playerid][54] = CreatePlayerTextDraw(playerid, 526.000, 200.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][54], 76.000, 31.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][54], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][54], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][54], 1);

    MusicVRP[playerid][55] = CreatePlayerTextDraw(playerid, 521.000, 199.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][55], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][55], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][55], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][55], 1);

    MusicVRP[playerid][56] = CreatePlayerTextDraw(playerid, 595.000, 199.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][56], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][56], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][56], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][56], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][56], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][56], 1);

    MusicVRP[playerid][57] = CreatePlayerTextDraw(playerid, 595.000, 220.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][57], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][57], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][57], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][57], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][57], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][57], 1);

    MusicVRP[playerid][58] = CreatePlayerTextDraw(playerid, 521.000, 220.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][58], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][58], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][58], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][58], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][58], 1);

    MusicVRP[playerid][59] = CreatePlayerTextDraw(playerid, 526.000, 201.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][59], 76.000, 29.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][59], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][59], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][59], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][59], 1);

    MusicVRP[playerid][60] = CreatePlayerTextDraw(playerid, 523.000, 204.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][60], 82.000, 23.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][60], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][60], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][60], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][60], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][60], 1);

    MusicVRP[playerid][61] = CreatePlayerTextDraw(playerid, 526.000, 205.000, "Music diputar via speaker");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][61], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][61], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][61], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][61], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][61], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][61], 1);

    MusicVRP[playerid][62] = CreatePlayerTextDraw(playerid, 526.000, 212.000, "boombox. semua player di");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][62], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][62], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][62], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][62], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][62], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][62], 1);

    MusicVRP[playerid][63] = CreatePlayerTextDraw(playerid, 526.000, 219.000, "sekitar dapat mendengar.");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][63], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][63], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][63], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][63], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][63], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][63], 1);

    MusicVRP[playerid][64] = CreatePlayerTextDraw(playerid, 593.000, 176.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][64], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][64], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][64], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][64], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][64], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][64], 1);

    MusicVRP[playerid][65] = CreatePlayerTextDraw(playerid, 594.000, 177.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][65], 14.000, 16.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][65], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][65], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][65], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][65], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][65], 1);

    MusicVRP[playerid][66] = CreatePlayerTextDraw(playerid, 597.000, 180.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][66], 8.000, 10.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][66], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][66], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][66], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][66], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][66], 1);

    MusicVRP[playerid][67] = CreatePlayerTextDraw(playerid, 523.000, 174.000, "_");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][67], 17.000, 21.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][67], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][67], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][67], 0);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][67], 5);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][67], 0);
    PlayerTextDrawSetPreviewModel(playerid, MusicVRP[playerid][67], 2103);
    PlayerTextDrawSetPreviewRot(playerid, MusicVRP[playerid][67], 0.000, -1.000, 13.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MusicVRP[playerid][67], 0, 0);

    MusicVRP[playerid][68] = CreatePlayerTextDraw(playerid, 512.000, 240.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][68], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][68], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][68], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][68], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][68], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][68], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][68], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][68], 1);

    MusicVRP[playerid][69] = CreatePlayerTextDraw(playerid, 593.000, 240.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][69], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][69], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][69], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][69], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][69], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][69], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][69], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][69], 1);

    MusicVRP[playerid][70] = CreatePlayerTextDraw(playerid, 523.000, 244.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][70], 80.000, 72.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][70], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][70], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][70], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][70], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][70], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][70], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][70], 1);

    MusicVRP[playerid][71] = CreatePlayerTextDraw(playerid, 512.000, 297.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][71], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][71], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][71], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][71], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][71], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][71], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][71], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][71], 1);

    MusicVRP[playerid][72] = CreatePlayerTextDraw(playerid, 593.000, 297.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][72], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][72], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][72], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][72], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][72], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][72], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][72], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][72], 1);

    MusicVRP[playerid][73] = CreatePlayerTextDraw(playerid, 515.500, 253.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][73], 95.500, 56.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][73], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][73], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][73], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][73], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][73], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][73], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][73], 1);

    MusicVRP[playerid][74] = CreatePlayerTextDraw(playerid, 513.000, 241.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][74], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][74], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][74], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][74], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][74], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][74], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][74], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][74], 1);

    MusicVRP[playerid][75] = CreatePlayerTextDraw(playerid, 592.000, 241.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][75], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][75], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][75], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][75], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][75], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][75], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][75], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][75], 1);

    MusicVRP[playerid][76] = CreatePlayerTextDraw(playerid, 513.000, 296.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][76], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][76], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][76], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][76], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][76], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][76], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][76], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][76], 1);

    MusicVRP[playerid][77] = CreatePlayerTextDraw(playerid, 592.000, 296.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][77], 22.000, 23.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][77], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][77], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][77], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][77], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][77], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][77], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][77], 1);

    MusicVRP[playerid][78] = CreatePlayerTextDraw(playerid, 516.500, 253.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][78], 93.800, 56.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][78], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][78], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][78], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][78], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][78], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][78], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][78], 1);

    MusicVRP[playerid][79] = CreatePlayerTextDraw(playerid, 520.500, 245.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][79], 84.800, 69.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][79], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][79], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][79], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][79], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][79], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][79], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][79], 1);

    MusicVRP[playerid][80] = CreatePlayerTextDraw(playerid, 520.000, 250.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][80], 87.000, 62.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][80], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][80], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][80], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][80], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][80], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][80], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][80], 1);
    PlayerTextDrawSetSelectable(playerid, MusicVRP[playerid][80], 1);

    MusicVRP[playerid][81] = CreatePlayerTextDraw(playerid, 522.000, 253.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][81], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][81], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][81], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][81], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][81], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][81], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][81], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][81], 1);

    MusicVRP[playerid][82] = CreatePlayerTextDraw(playerid, 523.000, 254.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][82], 17.000, 18.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][82], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][82], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][82], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][82], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][82], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][82], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][82], 1);

    MusicVRP[playerid][83] = CreatePlayerTextDraw(playerid, 545.000, 251.000, "Earphone");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][83], 0.170, 1.099);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][83], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][83], 1521318655);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][83], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][83], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][83], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][83], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][83], 1);

    MusicVRP[playerid][84] = CreatePlayerTextDraw(playerid, 545.000, 261.000, "Audio pribadi");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][84], 0.109, 0.699);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][84], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][84], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][84], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][84], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][84], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][84], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][84], 1);

    MusicVRP[playerid][85] = CreatePlayerTextDraw(playerid, 545.000, 266.000, "player");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][85], 0.109, 0.699);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][85], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][85], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][85], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][85], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][85], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][85], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][85], 1);

    MusicVRP[playerid][86] = CreatePlayerTextDraw(playerid, 520.000, 276.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][86], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][86], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][86], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][86], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][86], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][86], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][86], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][86], 1);

    MusicVRP[playerid][87] = CreatePlayerTextDraw(playerid, 520.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][87], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][87], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][87], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][87], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][87], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][87], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][87], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][87], 1);

    MusicVRP[playerid][88] = CreatePlayerTextDraw(playerid, 522.000, 283.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][88], 84.000, 22.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][88], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][88], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][88], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][88], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][88], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][88], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][88], 1);

    MusicVRP[playerid][89] = CreatePlayerTextDraw(playerid, 596.000, 276.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][89], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][89], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][89], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][89], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][89], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][89], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][89], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][89], 1);

    MusicVRP[playerid][90] = CreatePlayerTextDraw(playerid, 596.000, 300.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][90], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][90], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][90], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][90], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][90], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][90], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][90], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][90], 1);

    MusicVRP[playerid][91] = CreatePlayerTextDraw(playerid, 526.000, 278.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][91], 76.000, 32.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][91], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][91], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][91], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][91], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][91], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][91], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][91], 1);

    MusicVRP[playerid][92] = CreatePlayerTextDraw(playerid, 521.000, 277.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][92], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][92], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][92], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][92], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][92], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][92], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][92], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][92], 1);

    MusicVRP[playerid][93] = CreatePlayerTextDraw(playerid, 595.000, 277.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][93], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][93], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][93], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][93], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][93], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][93], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][93], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][93], 1);

    MusicVRP[playerid][94] = CreatePlayerTextDraw(playerid, 595.000, 299.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][94], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][94], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][94], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][94], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][94], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][94], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][94], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][94], 1);

    MusicVRP[playerid][95] = CreatePlayerTextDraw(playerid, 521.000, 299.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][95], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][95], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][95], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][95], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][95], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][95], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][95], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][95], 1);

    MusicVRP[playerid][96] = CreatePlayerTextDraw(playerid, 526.000, 279.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][96], 76.000, 30.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][96], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][96], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][96], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][96], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][96], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][96], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][96], 1);

    MusicVRP[playerid][97] = CreatePlayerTextDraw(playerid, 523.000, 284.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][97], 82.000, 21.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][97], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][97], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][97], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][97], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][97], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][97], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][97], 1);

    MusicVRP[playerid][98] = CreatePlayerTextDraw(playerid, 526.000, 283.000, "Musik hanya terdengar oleh");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][98], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][98], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][98], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][98], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][98], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][98], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][98], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][98], 1);

    MusicVRP[playerid][99] = CreatePlayerTextDraw(playerid, 526.000, 290.000, "player sendiri. tidak");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][99], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][99], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][99], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][99], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][99], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][99], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][99], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][99], 1);

    MusicVRP[playerid][100] = CreatePlayerTextDraw(playerid, 526.000, 297.000, "menganggu player lain");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][100], 0.140, 0.799);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][100], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][100], 778454271);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][100], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][100], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][100], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][100], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][100], 1);

    MusicVRP[playerid][101] = CreatePlayerTextDraw(playerid, 593.000, 252.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][101], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][101], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][101], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][101], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][101], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][101], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][101], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][101], 1);

    MusicVRP[playerid][102] = CreatePlayerTextDraw(playerid, 594.000, 253.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][102], 14.000, 16.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][102], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][102], 135598335);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][102], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][102], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][102], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][102], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][102], 1);

    MusicVRP[playerid][103] = CreatePlayerTextDraw(playerid, 597.000, 256.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][103], 8.000, 10.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][103], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][103], 254613759);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][103], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][103], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][103], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][103], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][103], 1);

    MusicVRP[playerid][104] = CreatePlayerTextDraw(playerid, 507.000, 215.000, "_");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][104], 53.000, 59.000);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][104], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][104], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][104], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][104], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][104], 0);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][104], 5);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][104], 0);
    PlayerTextDrawSetPreviewModel(playerid, MusicVRP[playerid][104], 19421);
    PlayerTextDrawSetPreviewRot(playerid, MusicVRP[playerid][104], 94.000, 0.000, 1.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, MusicVRP[playerid][104], 0, 0);

    MusicVRP[playerid][105] = CreatePlayerTextDraw(playerid, 542.000, 326.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, MusicVRP[playerid][105], 41.000, 18.500);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][105], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][105], 498685183);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][105], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][105], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][105], 255);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][105], 4);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][105], 1);
    PlayerTextDrawSetSelectable(playerid, MusicVRP[playerid][105], 1);

    MusicVRP[playerid][106] = CreatePlayerTextDraw(playerid, 556.000, 330.000, "Pilih");
    PlayerTextDrawLetterSize(playerid, MusicVRP[playerid][106], 0.180, 0.899);
    PlayerTextDrawAlignment(playerid, MusicVRP[playerid][106], 1);
    PlayerTextDrawColor(playerid, MusicVRP[playerid][106], 85593343);
    PlayerTextDrawSetShadow(playerid, MusicVRP[playerid][106], 0);
    PlayerTextDrawSetOutline(playerid, MusicVRP[playerid][106], 0);
    PlayerTextDrawBackgroundColor(playerid, MusicVRP[playerid][106], 150);
    PlayerTextDrawFont(playerid, MusicVRP[playerid][106], 1);
    PlayerTextDrawSetProportional(playerid, MusicVRP[playerid][106], 1);
}

CreateUberPhoneTD(playerid)
{
    UberVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][0], 1);

    UberVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][1], 1);

    UberVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][2], 1);

    UberVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][3], 1);

    UberVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][4], 1);

    UberVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][5], 1);

    UberVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][6], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][6], 1);

    UberVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][7], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][7], 1);

    UberVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][8], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][8], 1);

    UberVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][9], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][9], 1);

    UberVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][10], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][10], 1);

    UberVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][11], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][11], 1);

    UberVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][12], 1);

    UberVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][13], 1);

    UberVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][14], 1);

    UberVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, UberVRP[playerid][15], 1);

    UberVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][16], 1);

    UberVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][17], 1);

    UberVRP[playerid][18] = CreatePlayerTextDraw(playerid, 510.500, 138.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][18], 107.000, 37.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][18], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][18], 1);

    UberVRP[playerid][19] = CreatePlayerTextDraw(playerid, 508.000, 168.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][19], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][19], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][19], 1);

    UberVRP[playerid][20] = CreatePlayerTextDraw(playerid, 516.500, 171.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][20], 95.000, 199.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][20], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][20], 1);

    UberVRP[playerid][21] = CreatePlayerTextDraw(playerid, 603.000, 168.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][21], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][21], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][21], 1);

    UberVRP[playerid][22] = CreatePlayerTextDraw(playerid, 518.000, 127.000, "9:41");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][22], 0.140, 0.699);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][22], 437918463);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][22], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][22], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][22], 1);

    UberVRP[playerid][23] = CreatePlayerTextDraw(playerid, 564.000, 143.000, "Pilih Layanan");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][23], 0.190, 1.099);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][23], 2);
    PlayerTextDrawColor(playerid, UberVRP[playerid][23], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][23], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][23], 1);

    UberVRP[playerid][24] = CreatePlayerTextDraw(playerid, 565.000, 154.000, "Perjalanan atau pesan makanan?");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][24], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][24], 2);
    PlayerTextDrawColor(playerid, UberVRP[playerid][24], -923410177);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][24], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][24], 1);

    UberVRP[playerid][25] = CreatePlayerTextDraw(playerid, 515.000, 141.000, "<");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][25], 0.129, 0.700);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][25], 2);
    PlayerTextDrawColor(playerid, UberVRP[playerid][25], -923410177);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][25], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][25], 2);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][25], 1);

    UberVRP[playerid][26] = CreatePlayerTextDraw(playerid, 516.000, 144.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][26], 4.000, 0.500);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][26], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][26], 1);

    UberVRP[playerid][27] = CreatePlayerTextDraw(playerid, 512.000, 179.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][27], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][27], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][27], 1);

    UberVRP[playerid][28] = CreatePlayerTextDraw(playerid, 521.000, 182.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][28], 86.000, 68.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][28], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][28], 1);

    UberVRP[playerid][29] = CreatePlayerTextDraw(playerid, 597.000, 179.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][29], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][29], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][29], 1);

    UberVRP[playerid][30] = CreatePlayerTextDraw(playerid, 512.000, 233.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][30], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][30], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][30], 1);

    UberVRP[playerid][31] = CreatePlayerTextDraw(playerid, 597.000, 233.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][31], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][31], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][31], 1);

    UberVRP[playerid][32] = CreatePlayerTextDraw(playerid, 515.000, 190.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][32], 97.500, 52.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][32], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][32], 1);

    UberVRP[playerid][33] = CreatePlayerTextDraw(playerid, 513.000, 180.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][33], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][33], 1);

    UberVRP[playerid][34] = CreatePlayerTextDraw(playerid, 596.000, 180.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][34], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][34], 1);

    UberVRP[playerid][35] = CreatePlayerTextDraw(playerid, 513.000, 232.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][35], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][35], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][35], 1);

    UberVRP[playerid][36] = CreatePlayerTextDraw(playerid, 596.000, 232.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][36], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][36], 1);

    UberVRP[playerid][37] = CreatePlayerTextDraw(playerid, 516.000, 190.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][37], 95.500, 52.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][37], 1);

    UberVRP[playerid][38] = CreatePlayerTextDraw(playerid, 522.000, 183.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][38], 82.500, 66.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][38], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][38], 1);

    UberVRP[playerid][39] = CreatePlayerTextDraw(playerid, 520.000, 185.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][39], 89.500, 61.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, UberVRP[playerid][39], 1);

    UberVRP[playerid][40] = CreatePlayerTextDraw(playerid, 521.000, 191.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][40], 23.500, 23.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][40], -386338561);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][40], 1);

    UberVRP[playerid][41] = CreatePlayerTextDraw(playerid, 514.000, 184.000, "_");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][41], 34.000, 38.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][41], 0);
    PlayerTextDrawFont(playerid, UberVRP[playerid][41], 5);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][41], 0);
    PlayerTextDrawSetPreviewModel(playerid, UberVRP[playerid][41], 420);
    PlayerTextDrawSetPreviewRot(playerid, UberVRP[playerid][41], 0.000, 0.000, 23.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, UberVRP[playerid][41], 86, 0);

    UberVRP[playerid][42] = CreatePlayerTextDraw(playerid, 548.000, 189.000, "GoCar");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][42], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][42], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][42], 437918463);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][42], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][42], 1);

    UberVRP[playerid][43] = CreatePlayerTextDraw(playerid, 548.000, 199.000, "Nyaman untuk perjalanan");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][43], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][43], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][43], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][43], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][43], 1);

    UberVRP[playerid][44] = CreatePlayerTextDraw(playerid, 546.500, 209.000, "HUD:radar_gangY");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][44], 7.000, 7.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][44], 255);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][44], 1);

    UberVRP[playerid][45] = CreatePlayerTextDraw(playerid, 554.000, 209.000, "1-4 penumpang");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][45], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][45], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][45], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][45], 1);

    UberVRP[playerid][46] = CreatePlayerTextDraw(playerid, 547.000, 218.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][46], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][46], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][46], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][46], 1);

    UberVRP[playerid][47] = CreatePlayerTextDraw(playerid, 548.000, 219.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][47], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][47], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][47], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][47], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][47], 1);

    UberVRP[playerid][48] = CreatePlayerTextDraw(playerid, 550.000, 219.000, "L");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][48], 0.119, 0.499);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][48], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][48], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][48], 1);

    UberVRP[playerid][49] = CreatePlayerTextDraw(playerid, 554.000, 218.500, "Estimasi tiba 3 mnt");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][49], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][49], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][49], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][49], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][49], 1);

    UberVRP[playerid][50] = CreatePlayerTextDraw(playerid, 588.000, 226.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][50], 18.000, 20.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][50], -2004317953);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][50], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][50], 1);

    UberVRP[playerid][51] = CreatePlayerTextDraw(playerid, 589.000, 227.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][51], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][51], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][51], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][51], 1);

    UberVRP[playerid][52] = CreatePlayerTextDraw(playerid, 592.000, 230.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][52], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][52], -2004317953);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][52], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][52], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][52], 1);

    UberVRP[playerid][53] = CreatePlayerTextDraw(playerid, 512.000, 256.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][53], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][53], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][53], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][53], 1);

    UberVRP[playerid][54] = CreatePlayerTextDraw(playerid, 521.000, 259.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][54], 86.000, 68.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][54], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][54], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][54], 1);

    UberVRP[playerid][55] = CreatePlayerTextDraw(playerid, 597.000, 256.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][55], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][55], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][55], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][55], 1);

    UberVRP[playerid][56] = CreatePlayerTextDraw(playerid, 597.000, 310.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][56], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][56], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][56], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][56], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][56], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][56], 1);

    UberVRP[playerid][57] = CreatePlayerTextDraw(playerid, 512.000, 310.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][57], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][57], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][57], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][57], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][57], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][57], 1);

    UberVRP[playerid][58] = CreatePlayerTextDraw(playerid, 515.000, 266.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][58], 97.500, 53.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][58], -387389185);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][58], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][58], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][58], 1);

    UberVRP[playerid][59] = CreatePlayerTextDraw(playerid, 513.000, 257.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][59], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][59], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][59], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][59], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][59], 1);

    UberVRP[playerid][60] = CreatePlayerTextDraw(playerid, 596.000, 257.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][60], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][60], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][60], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][60], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][60], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][60], 1);

    UberVRP[playerid][61] = CreatePlayerTextDraw(playerid, 596.000, 309.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][61], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][61], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][61], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][61], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][61], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][61], 1);

    UberVRP[playerid][62] = CreatePlayerTextDraw(playerid, 513.000, 309.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][62], 19.000, 21.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][62], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][62], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][62], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][62], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][62], 1);

    UberVRP[playerid][63] = CreatePlayerTextDraw(playerid, 516.000, 266.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][63], 95.500, 53.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][63], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][63], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][63], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][63], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][63], 1);

    UberVRP[playerid][64] = CreatePlayerTextDraw(playerid, 523.000, 260.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][64], 81.500, 66.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][64], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][64], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][64], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][64], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][64], 1);

    UberVRP[playerid][65] = CreatePlayerTextDraw(playerid, 520.000, 262.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][65], 89.500, 61.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][65], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][65], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][65], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][65], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][65], 1);
    PlayerTextDrawSetSelectable(playerid, UberVRP[playerid][65], 1);

    UberVRP[playerid][66] = CreatePlayerTextDraw(playerid, 521.000, 268.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][66], 23.500, 23.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][66], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][66], -794369);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][66], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][66], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][66], 1);

    UberVRP[playerid][67] = CreatePlayerTextDraw(playerid, 548.000, 267.000, "GoFood");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][67], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][67], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][67], 437918463);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][67], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][67], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][67], 1);

    UberVRP[playerid][68] = CreatePlayerTextDraw(playerid, 520.000, 264.000, "_");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][68], 24.000, 28.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][68], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][68], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][68], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][68], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][68], 0);
    PlayerTextDrawFont(playerid, UberVRP[playerid][68], 5);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][68], 0);
    PlayerTextDrawSetPreviewModel(playerid, UberVRP[playerid][68], 2222);
    PlayerTextDrawSetPreviewRot(playerid, UberVRP[playerid][68], -42.000, 0.000, 238.000, 1.000);
    PlayerTextDrawSetPreviewVehCol(playerid, UberVRP[playerid][68], 6, 6);

    UberVRP[playerid][69] = CreatePlayerTextDraw(playerid, 548.000, 277.000, "Pesan makanan favoritmu");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][69], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][69], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][69], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][69], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][69], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][69], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][69], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][69], 1);

    UberVRP[playerid][70] = CreatePlayerTextDraw(playerid, 548.000, 288.000, "HUD:radar_burgerShot");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][70], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][70], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][70], -12254977);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][70], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][70], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][70], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][70], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][70], 1);

    UberVRP[playerid][71] = CreatePlayerTextDraw(playerid, 554.000, 287.000, "Berbagai pilihan restoran");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][71], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][71], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][71], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][71], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][71], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][71], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][71], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][71], 1);

    UberVRP[playerid][72] = CreatePlayerTextDraw(playerid, 547.000, 295.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][72], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][72], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][72], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][72], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][72], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][72], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][72], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][72], 1);

    UberVRP[playerid][73] = CreatePlayerTextDraw(playerid, 548.000, 296.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][73], 5.000, 6.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][73], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][73], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][73], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][73], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][73], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][73], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][73], 1);

    UberVRP[playerid][74] = CreatePlayerTextDraw(playerid, 550.000, 296.000, "L");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][74], 0.119, 0.499);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][74], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][74], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][74], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][74], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][74], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][74], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][74], 1);

    UberVRP[playerid][75] = CreatePlayerTextDraw(playerid, 554.000, 295.500, "Estimasi tiba 15-30 mnt");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][75], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][75], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][75], 2004318207);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][75], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][75], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][75], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][75], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][75], 1);

    UberVRP[playerid][76] = CreatePlayerTextDraw(playerid, 588.000, 301.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][76], 18.000, 20.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][76], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][76], -2004317953);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][76], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][76], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][76], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][76], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][76], 1);

    UberVRP[playerid][77] = CreatePlayerTextDraw(playerid, 589.000, 302.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][77], 16.000, 18.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][77], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][77], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][77], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][77], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][77], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][77], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][77], 1);

    UberVRP[playerid][78] = CreatePlayerTextDraw(playerid, 592.000, 305.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][78], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][78], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][78], -2004317953);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][78], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][78], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][78], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][78], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][78], 1);

    UberVRP[playerid][79] = CreatePlayerTextDraw(playerid, 516.000, 186.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][79], 2.500, 61.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][79], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][79], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][79], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][79], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][79], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][79], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][79], 1);

    UberVRP[playerid][80] = CreatePlayerTextDraw(playerid, 515.000, 263.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][80], 2.500, 61.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][80], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][80], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][80], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][80], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][80], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][80], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][80], 1);

    UberVRP[playerid][81] = CreatePlayerTextDraw(playerid, 588.000, 185.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][81], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][81], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][81], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][81], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][81], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][81], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][81], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][81], 1);

    UberVRP[playerid][82] = CreatePlayerTextDraw(playerid, 599.000, 185.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][82], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][82], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][82], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][82], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][82], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][82], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][82], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][82], 1);

    UberVRP[playerid][83] = CreatePlayerTextDraw(playerid, 594.000, 187.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][83], 11.500, 9.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][83], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][83], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][83], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][83], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][83], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][83], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][83], 1);

    UberVRP[playerid][84] = CreatePlayerTextDraw(playerid, 600.000, 189.000, "Dipilih");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][84], 0.100, 0.500);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][84], 2);
    PlayerTextDrawColor(playerid, UberVRP[playerid][84], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][84], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][84], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][84], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][84], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][84], 1);

    UberVRP[playerid][85] = CreatePlayerTextDraw(playerid, 588.000, 262.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][85], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][85], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][85], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][85], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][85], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][85], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][85], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][85], 1);

    UberVRP[playerid][86] = CreatePlayerTextDraw(playerid, 599.000, 262.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][86], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][86], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][86], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][86], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][86], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][86], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][86], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][86], 1);

    UberVRP[playerid][87] = CreatePlayerTextDraw(playerid, 594.000, 264.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][87], 11.500, 9.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][87], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][87], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][87], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][87], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][87], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][87], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][87], 1);

    UberVRP[playerid][88] = CreatePlayerTextDraw(playerid, 600.000, 266.000, "Dipilih");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][88], 0.100, 0.500);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][88], 2);
    PlayerTextDrawColor(playerid, UberVRP[playerid][88], -168363265);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][88], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][88], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][88], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][88], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][88], 1);

    UberVRP[playerid][89] = CreatePlayerTextDraw(playerid, 538.000, 331.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][89], 20.000, 22.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][89], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][89], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][89], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][89], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][89], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][89], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][89], 1);

    UberVRP[playerid][90] = CreatePlayerTextDraw(playerid, 572.000, 331.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][90], 20.000, 22.000);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][90], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][90], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][90], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][90], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][90], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][90], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][90], 1);

    UberVRP[playerid][91] = CreatePlayerTextDraw(playerid, 548.000, 334.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UberVRP[playerid][91], 34.500, 14.500);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][91], 1);
    PlayerTextDrawColor(playerid, UberVRP[playerid][91], 11164671);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][91], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][91], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][91], 255);
    PlayerTextDrawFont(playerid, UberVRP[playerid][91], 4);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][91], 1);
    PlayerTextDrawSetSelectable(playerid, UberVRP[playerid][91], 1);

    UberVRP[playerid][92] = CreatePlayerTextDraw(playerid, 566.000, 337.000, "Pesan Sekarang");
    PlayerTextDrawLetterSize(playerid, UberVRP[playerid][92], 0.119, 0.800);
    PlayerTextDrawAlignment(playerid, UberVRP[playerid][92], 2);
    PlayerTextDrawColor(playerid, UberVRP[playerid][92], -1);
    PlayerTextDrawSetShadow(playerid, UberVRP[playerid][92], 0);
    PlayerTextDrawSetOutline(playerid, UberVRP[playerid][92], 0);
    PlayerTextDrawBackgroundColor(playerid, UberVRP[playerid][92], 150);
    PlayerTextDrawFont(playerid, UberVRP[playerid][92], 1);
    PlayerTextDrawSetProportional(playerid, UberVRP[playerid][92], 1);
}

CreateKalkulatorTD(playerid)
{
    KalkulatorVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][0], 1);

    KalkulatorVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][1], 1);

    KalkulatorVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][2], 1);

    KalkulatorVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][3], 1);

    KalkulatorVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][4], 1);

    KalkulatorVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][5], 1);

    KalkulatorVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][6], 471604991);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][6], 1);

    KalkulatorVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][7], 471604991);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][7], 1);

    KalkulatorVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][8], 471604991);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][8], 1);

    KalkulatorVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][9], 471604991);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][9], 1);

    KalkulatorVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][10], 471604991);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][10], 1);

    KalkulatorVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][11], 471604991);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][11], 1);

    KalkulatorVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][12], 1);

    KalkulatorVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][13], 1);

    KalkulatorVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][14], 1);

    KalkulatorVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][15], 1);

    KalkulatorVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][16], 1);

    KalkulatorVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][17], 1);

    KalkulatorVRP[playerid][18] = CreatePlayerTextDraw(playerid, 510.000, 195.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][18], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][18], -1515870721);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][18], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][18], 1);

    KalkulatorVRP[playerid][19] = CreatePlayerTextDraw(playerid, 535.000, 195.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][19], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][19], -1515870721);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][19], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][19], 1);

    KalkulatorVRP[playerid][20] = CreatePlayerTextDraw(playerid, 560.000, 195.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][20], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][20], -6354177);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][20], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][20], 1);

    KalkulatorVRP[playerid][21] = CreatePlayerTextDraw(playerid, 585.000, 195.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][21], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][21], -6354177);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][21], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][21], 1);

    KalkulatorVRP[playerid][22] = CreatePlayerTextDraw(playerid, 585.000, 226.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][22], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][22], -6354177);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][22], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][22], 1);

    KalkulatorVRP[playerid][23] = CreatePlayerTextDraw(playerid, 585.000, 257.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][23], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][23], -6354177);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][23], 1);

    KalkulatorVRP[playerid][24] = CreatePlayerTextDraw(playerid, 585.000, 289.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][24], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][24], -6354177);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][24], 1);

    KalkulatorVRP[playerid][25] = CreatePlayerTextDraw(playerid, 585.000, 320.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][25], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][25], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][25], 1);

    KalkulatorVRP[playerid][26] = CreatePlayerTextDraw(playerid, 510.000, 320.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][26], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][26], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][26], 1);

    KalkulatorVRP[playerid][27] = CreatePlayerTextDraw(playerid, 526.000, 326.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][27], 74.000, 25.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][27], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][27], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][27], 1);

    KalkulatorVRP[playerid][28] = CreatePlayerTextDraw(playerid, 510.000, 289.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][28], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][28], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][28], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][28], 1);

    KalkulatorVRP[playerid][29] = CreatePlayerTextDraw(playerid, 535.000, 289.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][29], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][29], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][29], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][29], 1);

    KalkulatorVRP[playerid][30] = CreatePlayerTextDraw(playerid, 560.000, 289.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][30], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][30], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][30], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][30], 1);

    KalkulatorVRP[playerid][31] = CreatePlayerTextDraw(playerid, 510.000, 257.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][31], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][31], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][31], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][31], 1);

    KalkulatorVRP[playerid][32] = CreatePlayerTextDraw(playerid, 535.000, 257.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][32], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][32], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][32], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][32], 1);

    KalkulatorVRP[playerid][33] = CreatePlayerTextDraw(playerid, 560.000, 257.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][33], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][33], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][33], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][33], 1);

    KalkulatorVRP[playerid][34] = CreatePlayerTextDraw(playerid, 510.000, 226.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][34], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][34], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][34], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][34], 1);

    KalkulatorVRP[playerid][35] = CreatePlayerTextDraw(playerid, 535.000, 226.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][35], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][35], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][35], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][35], 1);

    KalkulatorVRP[playerid][36] = CreatePlayerTextDraw(playerid, 560.000, 226.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][36], 33.000, 38.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][36], 858993663);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][36], 1);
    PlayerTextDrawSetSelectable(playerid, KalkulatorVRP[playerid][36], 1);

    KalkulatorVRP[playerid][37] = CreatePlayerTextDraw(playerid, 526.000, 207.000, "AC");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][37], 0.220, 1.299);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][37], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][37], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][37], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][37], 1);

    KalkulatorVRP[playerid][38] = CreatePlayerTextDraw(playerid, 552.000, 207.000, "DEL");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][38], 0.220, 1.299);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][38], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][38], 255);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][38], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][38], 1);

    KalkulatorVRP[playerid][39] = CreatePlayerTextDraw(playerid, 571.500, 214.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][39], 10.000, 1.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][39], 1);

    KalkulatorVRP[playerid][40] = CreatePlayerTextDraw(playerid, 574.000, 209.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][40], 3.500, 4.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][40], 1);

    KalkulatorVRP[playerid][41] = CreatePlayerTextDraw(playerid, 574.000, 215.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KalkulatorVRP[playerid][41], 3.500, 4.000);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][41], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][41], 1);

    KalkulatorVRP[playerid][42] = CreatePlayerTextDraw(playerid, 601.000, 207.000, "X");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][42], 0.220, 1.299);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][42], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][42], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][42], 1);

    KalkulatorVRP[playerid][43] = CreatePlayerTextDraw(playerid, 601.000, 240.000, "-");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][43], 0.409, 0.899);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][43], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][43], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][43], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][43], 1);

    KalkulatorVRP[playerid][44] = CreatePlayerTextDraw(playerid, 601.000, 268.000, "+");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][44], 0.349, 1.600);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][44], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][44], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][44], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][44], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][44], 1);

    KalkulatorVRP[playerid][45] = CreatePlayerTextDraw(playerid, 601.000, 300.000, "=");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][45], 0.349, 1.600);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][45], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][45], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][45], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][45], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][45], 1);

    KalkulatorVRP[playerid][46] = CreatePlayerTextDraw(playerid, 565.000, 332.000, "0");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][46], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][46], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][46], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][46], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][46], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][46], 1);

    KalkulatorVRP[playerid][47] = CreatePlayerTextDraw(playerid, 526.000, 301.000, "1");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][47], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][47], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][47], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][47], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][47], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][47], 1);

    KalkulatorVRP[playerid][48] = CreatePlayerTextDraw(playerid, 551.000, 301.000, "2");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][48], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][48], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][48], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][48], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][48], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][48], 1);

    KalkulatorVRP[playerid][49] = CreatePlayerTextDraw(playerid, 577.000, 301.000, "3");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][49], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][49], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][49], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][49], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][49], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][49], 1);

    KalkulatorVRP[playerid][50] = CreatePlayerTextDraw(playerid, 526.500, 268.000, "4");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][50], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][50], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][50], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][50], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][50], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][50], 1);

    KalkulatorVRP[playerid][51] = CreatePlayerTextDraw(playerid, 551.500, 268.000, "5");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][51], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][51], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][51], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][51], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][51], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][51], 1);

    KalkulatorVRP[playerid][52] = CreatePlayerTextDraw(playerid, 576.500, 268.000, "6");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][52], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][52], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][52], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][52], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][52], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][52], 1);

    KalkulatorVRP[playerid][53] = CreatePlayerTextDraw(playerid, 526.500, 237.000, "7");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][53], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][53], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][53], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][53], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][53], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][53], 1);

    KalkulatorVRP[playerid][54] = CreatePlayerTextDraw(playerid, 551.500, 237.000, "8");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][54], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][54], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][54], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][54], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][54], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][54], 1);

    KalkulatorVRP[playerid][55] = CreatePlayerTextDraw(playerid, 576.500, 237.000, "9");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][55], 0.260, 1.500);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][55], 2);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][55], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][55], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][55], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][55], 1);

    KalkulatorVRP[playerid][56] = CreatePlayerTextDraw(playerid, 612.500, 160.000, "120");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][56], 0.479, 2.499);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][56], 3);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][56], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][56], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][56], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][56], 1);

    KalkulatorVRP[playerid][57] = CreatePlayerTextDraw(playerid, 612.500, 150.000, "60 + 60");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][57], 0.129, 0.699);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][57], 3);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][57], -2004317953);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][57], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][57], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][57], 1);

    KalkulatorVRP[playerid][58] = CreatePlayerTextDraw(playerid, 516.500, 127.000, "9:41");
    PlayerTextDrawLetterSize(playerid, KalkulatorVRP[playerid][58], 0.150, 0.799);
    PlayerTextDrawAlignment(playerid, KalkulatorVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, KalkulatorVRP[playerid][58], -1);
    PlayerTextDrawSetShadow(playerid, KalkulatorVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, KalkulatorVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, KalkulatorVRP[playerid][58], 150);
    PlayerTextDrawFont(playerid, KalkulatorVRP[playerid][58], 1);
    PlayerTextDrawSetProportional(playerid, KalkulatorVRP[playerid][58], 1);
}

CreateCameraTD(playerid)
{
    CameraVRP[playerid][0] = CreatePlayerTextDraw(playerid, -1.000, 0.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][0], 641.000, 56.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][0], 218959359);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][0], 1);

    CameraVRP[playerid][1] = CreatePlayerTextDraw(playerid, -1.000, 393.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][1], 641.000, 56.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][1], 218959359);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][1], 1);

    CameraVRP[playerid][2] = CreatePlayerTextDraw(playerid, 19.000, 22.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][2], 9.000, 11.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][2], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][2], 1);

    CameraVRP[playerid][3] = CreatePlayerTextDraw(playerid, 30.000, 21.000, "REC");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][3], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][3], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][3], 1);

    CameraVRP[playerid][4] = CreatePlayerTextDraw(playerid, 320.000, 24.000, "CAMERA");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][4], 0.230, 1.099);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][4], 2);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][4], -2004317953);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][4], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][4], 1);

    CameraVRP[playerid][5] = CreatePlayerTextDraw(playerid, 631.000, 24.000, "09:22:22");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][5], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][5], 3);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][5], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][5], 1);

    CameraVRP[playerid][6] = CreatePlayerTextDraw(playerid, 6.000, 411.000, "CORDINATES");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][6], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][6], 1431655935);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][6], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][6], 1);

    CameraVRP[playerid][7] = CreatePlayerTextDraw(playerid, 6.000, 421.000, "X: 123.44 Y: 232.242 Z: 234.555");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][7], 0.140, 0.899);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][7], -858993409);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][7], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][7], 1);

    CameraVRP[playerid][8] = CreatePlayerTextDraw(playerid, 632.000, 411.000, "MODE");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][8], 0.150, 0.799);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][8], 3);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][8], 1431655935);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][8], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][8], 1);

    CameraVRP[playerid][9] = CreatePlayerTextDraw(playerid, 634.000, 420.000, "PHOTO");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][9], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][9], 3);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][9], 2143944703);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][9], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][9], 1);

    CameraVRP[playerid][10] = CreatePlayerTextDraw(playerid, -2.000, 137.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][10], 646.000, 1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][10], -1077952513);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][10], 1);

    CameraVRP[playerid][11] = CreatePlayerTextDraw(playerid, -2.000, 331.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][11], 646.000, 1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][11], -1077952513);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][11], 1);

    CameraVRP[playerid][12] = CreatePlayerTextDraw(playerid, 226.000, 393.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][12], 1.000, -337.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][12], -1077952513);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][12], 1);

    CameraVRP[playerid][13] = CreatePlayerTextDraw(playerid, 440.000, 393.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][13], 1.000, -337.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][13], -1077952513);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][13], 1);

    CameraVRP[playerid][14] = CreatePlayerTextDraw(playerid, 329.000, 308.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][14], 1.000, -144.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][14], -1077952513);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][14], 1);

    CameraVRP[playerid][15] = CreatePlayerTextDraw(playerid, 266.000, 228.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][15], 133.000, 1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][15], -1077952513);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][15], 1);

    CameraVRP[playerid][16] = CreatePlayerTextDraw(playerid, 266.000, 163.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][16], 16.000, 1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][16], 1);

    CameraVRP[playerid][17] = CreatePlayerTextDraw(playerid, 266.000, 182.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][17], 1.000, -19.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][17], 1);

    CameraVRP[playerid][18] = CreatePlayerTextDraw(playerid, 382.000, 163.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][18], 16.000, 1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][18], 1);

    CameraVRP[playerid][19] = CreatePlayerTextDraw(playerid, 397.000, 182.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][19], 1.000, -19.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][19], 1);

    CameraVRP[playerid][20] = CreatePlayerTextDraw(playerid, 266.000, 308.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][20], 1.000, -19.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][20], 1);

    CameraVRP[playerid][21] = CreatePlayerTextDraw(playerid, 267.000, 306.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][21], 16.000, 1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][21], 1);

    CameraVRP[playerid][22] = CreatePlayerTextDraw(playerid, 381.000, 306.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][22], 16.000, -1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][22], 1);

    CameraVRP[playerid][23] = CreatePlayerTextDraw(playerid, 397.000, 306.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][23], 1.000, -19.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][23], 1);

    CameraVRP[playerid][24] = CreatePlayerTextDraw(playerid, 329.000, 234.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][24], 1.000, -12.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][24], 1);

    CameraVRP[playerid][25] = CreatePlayerTextDraw(playerid, 325.000, 229.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][25], 9.000, -1.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][25], 1);

    CameraVRP[playerid][26] = CreatePlayerTextDraw(playerid, 281.000, 366.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][26], 110.000, 20.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][26], 774778623);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][26], 1);

    CameraVRP[playerid][27] = CreatePlayerTextDraw(playerid, 257.000, 366.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][27], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][27], 774778623);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][27], 1);

    CameraVRP[playerid][28] = CreatePlayerTextDraw(playerid, 396.000, 366.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][28], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][28], 774778623);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][28], 1);

    CameraVRP[playerid][29] = CreatePlayerTextDraw(playerid, 282.000, 367.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][29], 108.000, 18.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][29], 218959359);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][29], 1);

    CameraVRP[playerid][30] = CreatePlayerTextDraw(playerid, 258.000, 367.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][30], 17.299, 18.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][30], 218959359);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][30], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][30], 1);

    CameraVRP[playerid][31] = CreatePlayerTextDraw(playerid, 397.000, 367.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][31], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][31], 218959359);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][31], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][31], 1);

    CameraVRP[playerid][32] = CreatePlayerTextDraw(playerid, 267.000, 371.000, "<-");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][32], 0.220, 1.099);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][32], 2);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][32], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][32], 2);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][32], 1);

    CameraVRP[playerid][33] = CreatePlayerTextDraw(playerid, 406.000, 371.000, "->");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][33], 0.220, 1.099);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][33], 2);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][33], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][33], 2);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][33], 1);

    CameraVRP[playerid][34] = CreatePlayerTextDraw(playerid, 307.000, 371.000, "ANGLE");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][34], 0.200, 0.999);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][34], 1717987071);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][34], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][34], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][34], 1);

    CameraVRP[playerid][35] = CreatePlayerTextDraw(playerid, 344.000, 371.000, "0 deg");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][35], 0.170, 0.999);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][35], 2143944703);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][35], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][35], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][35], 1);

    CameraVRP[playerid][36] = CreatePlayerTextDraw(playerid, 619.000, 163.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][36], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][36], 774778623);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][36], 1);

    CameraVRP[playerid][37] = CreatePlayerTextDraw(playerid, 619.000, 273.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][37], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][37], 774778623);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][37], 1);

    CameraVRP[playerid][38] = CreatePlayerTextDraw(playerid, 620.000, 164.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][38], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][38], 437918463);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][38], 1);

    CameraVRP[playerid][39] = CreatePlayerTextDraw(playerid, 620.000, 274.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][39], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][39], 437918463);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][39], 1);

    CameraVRP[playerid][40] = CreatePlayerTextDraw(playerid, 628.000, 186.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][40], 2.000, 83.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][40], 774778623);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][40], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][40], 1);

    CameraVRP[playerid][41] = CreatePlayerTextDraw(playerid, 628.000, 269.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][41], 2.000, -83.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][41], 1717987071);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][41], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][41], 1);

    CameraVRP[playerid][42] = CreatePlayerTextDraw(playerid, 628.500, 166.000, "+");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][42], 0.280, 1.399);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][42], 2);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][42], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][42], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][42], 1);

    CameraVRP[playerid][43] = CreatePlayerTextDraw(playerid, 628.500, 278.000, "-");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][43], 0.320, 0.799);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][43], 2);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][43], -1);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][43], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][43], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][43], 1);

    CameraVRP[playerid][44] = CreatePlayerTextDraw(playerid, 3.000, 57.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][44], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][44], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][44], 1);

    CameraVRP[playerid][45] = CreatePlayerTextDraw(playerid, 3.000, 66.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][45], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][45], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][45], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][45], 1);

    CameraVRP[playerid][46] = CreatePlayerTextDraw(playerid, 34.000, 66.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][46], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][46], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][46], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][46], 1);

    CameraVRP[playerid][47] = CreatePlayerTextDraw(playerid, 34.000, 57.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][47], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][47], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][47], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][47], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][47], 1);

    CameraVRP[playerid][48] = CreatePlayerTextDraw(playerid, 9.000, 59.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][48], 32.000, 19.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][48], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][48], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][48], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][48], 1);

    CameraVRP[playerid][49] = CreatePlayerTextDraw(playerid, 5.000, 63.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][49], 39.000, 12.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][49], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][49], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][49], 1);

    CameraVRP[playerid][50] = CreatePlayerTextDraw(playerid, 4.000, 58.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][50], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][50], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][50], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][50], 1);

    CameraVRP[playerid][51] = CreatePlayerTextDraw(playerid, 4.000, 65.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][51], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][51], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][51], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][51], 1);

    CameraVRP[playerid][52] = CreatePlayerTextDraw(playerid, 33.000, 65.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][52], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][52], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][52], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][52], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][52], 1);

    CameraVRP[playerid][53] = CreatePlayerTextDraw(playerid, 33.000, 58.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][53], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][53], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][53], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][53], 1);

    CameraVRP[playerid][54] = CreatePlayerTextDraw(playerid, 6.000, 65.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][54], 37.000, 9.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][54], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][54], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][54], 1);

    CameraVRP[playerid][55] = CreatePlayerTextDraw(playerid, 10.000, 60.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][55], 28.000, 16.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][55], -13421569);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][55], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][55], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][55], 1);

    CameraVRP[playerid][56] = CreatePlayerTextDraw(playerid, 18.000, 64.000, "Exit");
    PlayerTextDrawLetterSize(playerid, CameraVRP[playerid][56], 0.200, 0.999);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][56], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][56], -9408257);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][56], 150);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][56], 1);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][56], 1);

    CameraVRP[playerid][57] = CreatePlayerTextDraw(playerid, 308.000, 398.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][57], 37.000, 38.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][57], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][57], -336860161);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][57], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][57], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][57], 1);

    CameraVRP[playerid][58] = CreatePlayerTextDraw(playerid, 311.000, 402.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][58], 31.000, 30.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][58], 218959359);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][58], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][58], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][58], 1);

    CameraVRP[playerid][59] = CreatePlayerTextDraw(playerid, 312.000, 403.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CameraVRP[playerid][59], 29.000, 28.000);
    PlayerTextDrawAlignment(playerid, CameraVRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, CameraVRP[playerid][59], -336860161);
    PlayerTextDrawSetShadow(playerid, CameraVRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, CameraVRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, CameraVRP[playerid][59], 255);
    PlayerTextDrawFont(playerid, CameraVRP[playerid][59], 4);
    PlayerTextDrawSetProportional(playerid, CameraVRP[playerid][59], 1);
    PlayerTextDrawSetSelectable(playerid, CameraVRP[playerid][59], 1);
}

CreateKontakTD(playerid)
{
    KontakVRP[playerid][0] = CreatePlayerTextDraw(playerid, 508.000, 129.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][0], 111.000, 262.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][0], 1);

    KontakVRP[playerid][1] = CreatePlayerTextDraw(playerid, 503.500, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][1], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][1], 1);

    KontakVRP[playerid][2] = CreatePlayerTextDraw(playerid, 595.000, 114.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][2], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][2], 1);

    KontakVRP[playerid][3] = CreatePlayerTextDraw(playerid, 595.000, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][3], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][3], 1);

    KontakVRP[playerid][4] = CreatePlayerTextDraw(playerid, 503.500, 373.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][4], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][4], 1);

    KontakVRP[playerid][5] = CreatePlayerTextDraw(playerid, 517.000, 119.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][5], 94.000, 281.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][5], 1);

    KontakVRP[playerid][6] = CreatePlayerTextDraw(playerid, 505.500, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][6], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][6], 858993663);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][6], 1);

    KontakVRP[playerid][7] = CreatePlayerTextDraw(playerid, 593.000, 116.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][7], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][7], 858993663);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][7], 1);

    KontakVRP[playerid][8] = CreatePlayerTextDraw(playerid, 593.000, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][8], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][8], 1);

    KontakVRP[playerid][9] = CreatePlayerTextDraw(playerid, 505.500, 371.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][9], 29.000, 32.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][9], 1);

    KontakVRP[playerid][10] = CreatePlayerTextDraw(playerid, 517.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][10], 94.000, 276.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][10], 1);

    KontakVRP[playerid][11] = CreatePlayerTextDraw(playerid, 510.500, 131.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][11], 107.000, 256.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][11], 1);

    KontakVRP[playerid][12] = CreatePlayerTextDraw(playerid, 507.500, 163.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][12], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][12], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][12], 1);

    KontakVRP[playerid][13] = CreatePlayerTextDraw(playerid, 507.500, 198.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][13], 2.000, 27.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][13], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][13], 1);

    KontakVRP[playerid][14] = CreatePlayerTextDraw(playerid, 617.500, 180.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][14], 2.000, 21.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][14], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][14], 1);

    KontakVRP[playerid][15] = CreatePlayerTextDraw(playerid, 541.500, 379.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][15], 49.000, 12.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][15], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, KontakVRP[playerid][15], 1);

    KontakVRP[playerid][16] = CreatePlayerTextDraw(playerid, 535.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][16], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][16], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][16], 1);

    KontakVRP[playerid][17] = CreatePlayerTextDraw(playerid, 581.000, 376.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][17], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][17], 1);

    KontakVRP[playerid][18] = CreatePlayerTextDraw(playerid, 510.000, 130.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][18], 108.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][18], 858993663);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][18], 1);

    KontakVRP[playerid][19] = CreatePlayerTextDraw(playerid, 516.000, 121.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][19], 95.000, 9.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][19], 858993663);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][19], 1);

    KontakVRP[playerid][20] = CreatePlayerTextDraw(playerid, 516.000, 126.000, "9:41");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][20], 0.129, 0.799);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][20], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][20], 1);

    KontakVRP[playerid][21] = CreatePlayerTextDraw(playerid, 516.000, 143.000, "Kontak");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][21], 0.260, 1.700);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][21], 539043071);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][21], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][21], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][21], 1);

    KontakVRP[playerid][22] = CreatePlayerTextDraw(playerid, 588.000, 145.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][22], 10.000, 12.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][22], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][22], 1);

    KontakVRP[playerid][23] = CreatePlayerTextDraw(playerid, 589.000, 146.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][23], 8.000, 10.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][23], 1);

    KontakVRP[playerid][24] = CreatePlayerTextDraw(playerid, 599.000, 151.000, "/");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][24], -0.359, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][24], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][24], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][24], 2);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][24], 1);

    KontakVRP[playerid][25] = CreatePlayerTextDraw(playerid, 596.000, 148.000, "/");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][25], -0.359, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][25], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][25], 2);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][25], 1);

    KontakVRP[playerid][26] = CreatePlayerTextDraw(playerid, 597.000, 141.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][26], 20.000, 22.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][26], -386859265);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][26], 1);

    KontakVRP[playerid][27] = CreatePlayerTextDraw(playerid, 604.000, 147.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][27], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][27], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][27], 1);

    KontakVRP[playerid][28] = CreatePlayerTextDraw(playerid, 605.400, 148.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][28], 3.199, 3.599);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][28], 1);

    KontakVRP[playerid][29] = CreatePlayerTextDraw(playerid, 603.000, 151.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][29], 8.000, 7.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][29], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][29], 1);

    KontakVRP[playerid][30] = CreatePlayerTextDraw(playerid, 603.000, 152.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][30], 8.000, 7.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][30], -386859265);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][30], 1);

    KontakVRP[playerid][31] = CreatePlayerTextDraw(playerid, 512.000, 161.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][31], 23.000, 25.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][31], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][31], 1);

    KontakVRP[playerid][32] = CreatePlayerTextDraw(playerid, 593.000, 161.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][32], 23.000, 25.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][32], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][32], 1);

    KontakVRP[playerid][33] = CreatePlayerTextDraw(playerid, 525.000, 165.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][33], 79.000, 16.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][33], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][33], 1);
    PlayerTextDrawSetSelectable(playerid, KontakVRP[playerid][33], 1);

    KontakVRP[playerid][34] = CreatePlayerTextDraw(playerid, 524.000, 168.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][34], 9.000, 10.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][34], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][34], 1);

    KontakVRP[playerid][35] = CreatePlayerTextDraw(playerid, 525.000, 169.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][35], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][35], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][35], 1);

    KontakVRP[playerid][36] = CreatePlayerTextDraw(playerid, 534.000, 172.000, "/");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][36], -0.359, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][36], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][36], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][36], 2);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][36], 1);

    KontakVRP[playerid][37] = CreatePlayerTextDraw(playerid, 531.000, 169.000, "o");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][37], -0.349, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][37], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][37], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][37], 0);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][37], 1);

    KontakVRP[playerid][38] = CreatePlayerTextDraw(playerid, 536.000, 169.000, "Cari nama atau nomor...");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][38], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][38], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][38], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][38], 1);

    KontakVRP[playerid][39] = CreatePlayerTextDraw(playerid, 525.000, 358.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][39], 7.000, 7.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][39], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][39], 1);

    KontakVRP[playerid][40] = CreatePlayerTextDraw(playerid, 527.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][40], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][40], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][40], 1);

    KontakVRP[playerid][41] = CreatePlayerTextDraw(playerid, 523.000, 363.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][41], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][41], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][41], 1);

    KontakVRP[playerid][42] = CreatePlayerTextDraw(playerid, 523.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][42], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][42], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][42], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][42], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][42], 1);

    KontakVRP[playerid][43] = CreatePlayerTextDraw(playerid, 568.000, 355.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][43], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][43], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][43], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][43], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][43], 1);

    KontakVRP[playerid][44] = CreatePlayerTextDraw(playerid, 598.000, 355.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][44], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][44], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][44], 1);

    KontakVRP[playerid][45] = CreatePlayerTextDraw(playerid, 576.000, 358.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][45], 31.000, 12.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][45], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][45], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][45], 1);
    PlayerTextDrawSetSelectable(playerid, KontakVRP[playerid][45], 1);

    KontakVRP[playerid][46] = CreatePlayerTextDraw(playerid, 579.000, 359.000, "+");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][46], 0.230, 0.999);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][46], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][46], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][46], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][46], 1);

    KontakVRP[playerid][47] = CreatePlayerTextDraw(playerid, 549.500, 358.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][47], 7.000, 7.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][47], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][47], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][47], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][47], 1);

    KontakVRP[playerid][48] = CreatePlayerTextDraw(playerid, 549.500, 358.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][48], 5.500, 7.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][48], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][48], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][48], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][48], 1);

    KontakVRP[playerid][49] = CreatePlayerTextDraw(playerid, 548.000, 363.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][49], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][49], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][49], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][49], 1);

    KontakVRP[playerid][50] = CreatePlayerTextDraw(playerid, 548.000, 363.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][50], 9.500, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][50], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][50], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][50], 1);

    KontakVRP[playerid][51] = CreatePlayerTextDraw(playerid, 547.000, 358.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][51], 7.000, 7.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][51], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][51], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][51], 1);

    KontakVRP[playerid][52] = CreatePlayerTextDraw(playerid, 549.000, 360.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][52], 3.000, 4.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][52], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][52], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][52], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][52], 1);

    KontakVRP[playerid][53] = CreatePlayerTextDraw(playerid, 545.000, 363.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][53], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][53], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][53], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][53], 1);

    KontakVRP[playerid][54] = CreatePlayerTextDraw(playerid, 545.000, 364.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][54], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][54], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][54], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][54], 1);

    KontakVRP[playerid][55] = CreatePlayerTextDraw(playerid, 550.000, 366.500, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][55], 11.000, 8.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][55], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][55], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][55], 1);

    KontakVRP[playerid][56] = CreatePlayerTextDraw(playerid, 587.000, 360.000, "Tambah");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][56], 0.150, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][56], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][56], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][56], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][56], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][56], 1);

    KontakVRP[playerid][57] = CreatePlayerTextDraw(playerid, 511.000, 349.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][57], 106.000, 1.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][57], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][57], -387256833);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][57], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][57], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][57], 1);

    KontakVRP[playerid][58] = CreatePlayerTextDraw(playerid, 511.000, 325.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][58], 106.000, 1.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][58], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][58], -387256833);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][58], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][58], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][58], 1);

    KontakVRP[playerid][59] = CreatePlayerTextDraw(playerid, 511.000, 329.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][59], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][59], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][59], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][59], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][59], 1);

    KontakVRP[playerid][60] = CreatePlayerTextDraw(playerid, 534.000, 329.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][60], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][60], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][60], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][60], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][60], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][60], 1);

    KontakVRP[playerid][61] = CreatePlayerTextDraw(playerid, 520.000, 332.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][61], 21.000, 12.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][61], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][61], -235670273);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][61], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][61], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][61], 1);
    PlayerTextDrawSetSelectable(playerid, KontakVRP[playerid][61], 1);

    KontakVRP[playerid][62] = CreatePlayerTextDraw(playerid, 598.000, 329.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][62], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][62], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][62], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][62], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][62], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][62], 1);

    KontakVRP[playerid][63] = CreatePlayerTextDraw(playerid, 574.000, 329.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][63], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][63], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][63], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][63], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][63], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][63], 1);

    KontakVRP[playerid][64] = CreatePlayerTextDraw(playerid, 584.000, 332.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, KontakVRP[playerid][64], 21.000, 12.000);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][64], 1);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][64], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][64], 255);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][64], 4);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][64], 1);
    PlayerTextDrawSetSelectable(playerid, KontakVRP[playerid][64], 1);

    KontakVRP[playerid][65] = CreatePlayerTextDraw(playerid, 562.000, 334.000, "Hal 1/3");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][65], 0.150, 0.799);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][65], 2);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][65], 1600350463);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][65], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][65], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][65], 1);

    KontakVRP[playerid][66] = CreatePlayerTextDraw(playerid, 531.000, 334.000, "< Prev");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][66], 0.129, 0.799);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][66], 2);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][66], 1600350463);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][66], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][66], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][66], 1);

    KontakVRP[playerid][67] = CreatePlayerTextDraw(playerid, 596.000, 334.000, "Next >");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][67], 0.129, 0.799);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][67], 2);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][67], -1);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][67], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][67], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][67], 1);

    KontakVRP[playerid][68] = CreatePlayerTextDraw(playerid, 529.000, 368.000, "Kontak");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][68], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][68], 2);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][68], 443803903);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][68], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][68], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][68], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][68], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][68], 1);

    KontakVRP[playerid][69] = CreatePlayerTextDraw(playerid, 552.000, 368.000, "Sharing");
    PlayerTextDrawLetterSize(playerid, KontakVRP[playerid][69], 0.119, 0.699);
    PlayerTextDrawAlignment(playerid, KontakVRP[playerid][69], 2);
    PlayerTextDrawColor(playerid, KontakVRP[playerid][69], -1700747521);
    PlayerTextDrawSetShadow(playerid, KontakVRP[playerid][69], 0);
    PlayerTextDrawSetOutline(playerid, KontakVRP[playerid][69], 0);
    PlayerTextDrawBackgroundColor(playerid, KontakVRP[playerid][69], 150);
    PlayerTextDrawFont(playerid, KontakVRP[playerid][69], 1);
    PlayerTextDrawSetProportional(playerid, KontakVRP[playerid][69], 1);
}

CreatePlayerRebootTD(playerid)
{
    PhoneRebootBar[playerid] = CreatePlayerTextDraw(playerid, 550.000000, 319.000000, "ld_dual:white");
	PlayerTextDrawFont(playerid, PhoneRebootBar[playerid], 4);
	PlayerTextDrawLetterSize(playerid, PhoneRebootBar[playerid], 0.600000, 2.000000);
	PlayerTextDrawTextSize(playerid, PhoneRebootBar[playerid], 29.500000, 3.000000);
	PlayerTextDrawSetOutline(playerid, PhoneRebootBar[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PhoneRebootBar[playerid], 0);
	PlayerTextDrawAlignment(playerid, PhoneRebootBar[playerid], 1);
	PlayerTextDrawColor(playerid, PhoneRebootBar[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, PhoneRebootBar[playerid], 255);
	PlayerTextDrawBoxColor(playerid, PhoneRebootBar[playerid], 50);
	PlayerTextDrawUseBox(playerid, PhoneRebootBar[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PhoneRebootBar[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, PhoneRebootBar[playerid], 0);
}