#include <YSI_Coding\y_hooks>
new PlayerText: RaceTablet[MAX_PLAYERS][48];

CreateTablet(playerid)
{
    RaceTablet[playerid][0] = CreatePlayerTextDraw(playerid, 163.000, 103.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][0], 324.000, 264.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][0], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][0], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][0], 1);

    RaceTablet[playerid][1] = CreatePlayerTextDraw(playerid, 159.000, 92.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][1], 21.000, 21.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][1], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][1], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][1], 1);

    RaceTablet[playerid][2] = CreatePlayerTextDraw(playerid, 469.000, 92.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][2], 21.000, 21.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][2], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][2], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][2], 1);

    RaceTablet[playerid][3] = CreatePlayerTextDraw(playerid, 469.000, 357.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][3], 21.000, 21.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][3], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][3], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][3], 1);

    RaceTablet[playerid][4] = CreatePlayerTextDraw(playerid, 160.000, 357.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][4], 21.000, 21.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][4], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][4], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][4], 1);

    RaceTablet[playerid][5] = CreatePlayerTextDraw(playerid, 170.000, 95.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][5], 310.000, 280.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][5], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][5], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][5], 1);

    RaceTablet[playerid][6] = CreatePlayerTextDraw(playerid, 178.000, 114.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][6], 294.000, 11.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][6], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][6], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][6], 1);

    RaceTablet[playerid][7] = CreatePlayerTextDraw(playerid, 175.000, 106.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][7], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][7], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][7], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][7], 1);

    RaceTablet[playerid][8] = CreatePlayerTextDraw(playerid, 458.000, 106.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][8], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][8], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][8], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][8], 1);

    RaceTablet[playerid][9] = CreatePlayerTextDraw(playerid, 182.000, 109.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][9], 285.000, 14.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][9], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][9], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][9], 1);

    RaceTablet[playerid][10] = CreatePlayerTextDraw(playerid, 178.000, 125.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][10], 294.000, 236.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][10], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][10], 421078527);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][10], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][10], 1);

    RaceTablet[playerid][11] = CreatePlayerTextDraw(playerid, 175.000, 349.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][11], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][11], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][11], 1768516095);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][11], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][11], 1);

    RaceTablet[playerid][12] = CreatePlayerTextDraw(playerid, 458.000, 349.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][12], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][12], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][12], 421078527);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][12], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][12], 1);

    RaceTablet[playerid][13] = CreatePlayerTextDraw(playerid, 184.000, 346.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][13], 284.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][13], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][13], 421078527);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][13], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][13], 1);

    RaceTablet[playerid][14] = CreatePlayerTextDraw(playerid, 178.000, 126.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][14], 83.000, 234.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][14], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][14], 1768516095);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][14], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][14], 1);

    RaceTablet[playerid][15] = CreatePlayerTextDraw(playerid, 247.000, 349.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][15], 17.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][15], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][15], 1768516095);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][15], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][15], 1);

    RaceTablet[playerid][16] = CreatePlayerTextDraw(playerid, 182.000, 300.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][16], 73.000, 65.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][16], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][16], 1768516095);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][16], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][16], 1);

    RaceTablet[playerid][17] = CreatePlayerTextDraw(playerid, 190.000, 111.000, "05.34");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][17], 0.140, 1.199);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][17], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][17], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][17], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][17], 2);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][17], 1);

    RaceTablet[playerid][18] = CreatePlayerTextDraw(playerid, 441.000, 116.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][18], 10.000, 1.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][18], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][18], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][18], 1);

    RaceTablet[playerid][19] = CreatePlayerTextDraw(playerid, 441.000, 120.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][19], 10.000, 1.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][19], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][19], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][19], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][19], 1);

    RaceTablet[playerid][20] = CreatePlayerTextDraw(playerid, 441.000, 120.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][20], 1.000, -3.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][20], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][20], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][20], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][20], 1);

    RaceTablet[playerid][21] = CreatePlayerTextDraw(playerid, 444.000, 120.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][21], 1.000, -3.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][21], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][21], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][21], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][21], 1);

    RaceTablet[playerid][22] = CreatePlayerTextDraw(playerid, 448.000, 120.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][22], 1.000, -3.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][22], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][22], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][22], 1);

    RaceTablet[playerid][23] = CreatePlayerTextDraw(playerid, 450.000, 120.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][23], 1.000, -3.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][23], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][23], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][23], 1);

    RaceTablet[playerid][24] = CreatePlayerTextDraw(playerid, 450.000, 120.000, "LD_SPAC:black");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][24], 2.000, -3.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][24], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][24], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][24], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][24], 1);

    RaceTablet[playerid][25] = CreatePlayerTextDraw(playerid, 350.000, 128.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][25], 69.000, 17.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][25], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][25], 1211993087);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][25], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][25], 1);

    RaceTablet[playerid][26] = CreatePlayerTextDraw(playerid, 337.000, 124.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][26], 25.000, 25.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][26], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][26], 1211993087);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][26], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][26], 1);

    RaceTablet[playerid][27] = CreatePlayerTextDraw(playerid, 408.000, 124.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][27], 25.000, 25.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][27], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][27], 1211993087);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][27], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][27], 1);

    RaceTablet[playerid][28] = CreatePlayerTextDraw(playerid, 416.000, 131.000, "O");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][28], 0.190, 0.899);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][28], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][28], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][28], 1);

    RaceTablet[playerid][29] = CreatePlayerTextDraw(playerid, 418.000, 135.000, "/");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][29], -0.260, 0.599);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][29], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][29], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][29], 1);

    RaceTablet[playerid][30] = CreatePlayerTextDraw(playerid, 352.000, 130.000, "Search");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][30], 0.140, 1.199);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][30], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][30], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][30], 1);

    RaceTablet[playerid][31] = CreatePlayerTextDraw(playerid, 418.000, 150.000, "LD_RCE2:race07");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][31], 50.000, 208.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][31], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][31], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][31], 1);

    RaceTablet[playerid][32] = CreatePlayerTextDraw(playerid, 367.000, 150.000, "LD_RCE1:race02");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][32], 49.000, 208.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][32], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][32], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][32], 1);

    RaceTablet[playerid][33] = CreatePlayerTextDraw(playerid, 316.000, 150.000, "LD_RCE5:race24");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][33], 49.000, 208.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][33], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][33], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][33], 1);

    RaceTablet[playerid][34] = CreatePlayerTextDraw(playerid, 265.000, 150.000, "LD_RCE2:race11");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][34], 48.000, 209.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][34], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][34], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][34], 1);

    RaceTablet[playerid][35] = CreatePlayerTextDraw(playerid, 430.000, 123.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][35], 27.000, 27.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][35], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][35], -2147483393);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][35], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][35], 1);
    PlayerTextDrawSetSelectable(playerid, RaceTablet[playerid][35], 1);

    RaceTablet[playerid][36] = CreatePlayerTextDraw(playerid, 440.000, 130.000, "(");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][36], 0.300, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][36], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][36], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][36], 1);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][36], 1);

    RaceTablet[playerid][37] = CreatePlayerTextDraw(playerid, 445.000, 133.000, ">");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][37], 0.300, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][37], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][37], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][37], 1);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][37], 1);

    RaceTablet[playerid][38] = CreatePlayerTextDraw(playerid, 180.000, 320.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][38], 78.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][38], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][38], -1962934017);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][38], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, RaceTablet[playerid][38], 1);

    RaceTablet[playerid][39] = CreatePlayerTextDraw(playerid, 180.000, 298.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][39], 78.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][39], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][39], -1329275137);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][39], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][39], 1);
    PlayerTextDrawSetSelectable(playerid, RaceTablet[playerid][39], 1);

    RaceTablet[playerid][40] = CreatePlayerTextDraw(playerid, 180.000, 276.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][40], 78.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][40], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][40], -1329275137);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][40], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][40], 1);
    PlayerTextDrawSetSelectable(playerid, RaceTablet[playerid][40], 1);

    RaceTablet[playerid][41] = CreatePlayerTextDraw(playerid, 180.000, 255.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][41], 78.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][41], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][41], -1329275137);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][41], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][41], 1);
    PlayerTextDrawSetSelectable(playerid, RaceTablet[playerid][41], 1);

    RaceTablet[playerid][42] = CreatePlayerTextDraw(playerid, 180.000, 233.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, RaceTablet[playerid][42], 78.000, 19.000);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][42], 1);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][42], 579543807);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][42], 255);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][42], 1);
    PlayerTextDrawSetSelectable(playerid, RaceTablet[playerid][42], 1);

    RaceTablet[playerid][43] = CreatePlayerTextDraw(playerid, 219.000, 236.000, "PLAYER MENU");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][43], 0.129, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][43], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][43], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][43], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][43], 2);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][43], 1);

    RaceTablet[playerid][44] = CreatePlayerTextDraw(playerid, 219.000, 259.000, "END THE RACE");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][44], 0.129, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][44], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][44], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][44], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][44], 2);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][44], 1);

    RaceTablet[playerid][45] = CreatePlayerTextDraw(playerid, 219.000, 279.000, "TRACK LIST");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][45], 0.129, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][45], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][45], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][45], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][45], 2);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][45], 1);

    RaceTablet[playerid][46] = CreatePlayerTextDraw(playerid, 219.000, 302.000, "CREATE TRACK");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][46], 0.129, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][46], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][46], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][46], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][46], 2);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][46], 1);

    RaceTablet[playerid][47] = CreatePlayerTextDraw(playerid, 219.000, 323.000, "LEADERBOARD");
    PlayerTextDrawLetterSize(playerid, RaceTablet[playerid][47], 0.129, 1.099);
    PlayerTextDrawAlignment(playerid, RaceTablet[playerid][47], 2);
    PlayerTextDrawColor(playerid, RaceTablet[playerid][47], 255);
    PlayerTextDrawSetShadow(playerid, RaceTablet[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, RaceTablet[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, RaceTablet[playerid][47], 150);
    PlayerTextDrawFont(playerid, RaceTablet[playerid][47], 2);
    PlayerTextDrawSetProportional(playerid, RaceTablet[playerid][47], 1);

    return 1;
}

hook OnPlayerConnect(playerid)
{
    CreateTablet(playerid);
    CreateRacingTD(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    for(new i = 0; i < 48; i++) PlayerTextDrawDestroy(playerid, RaceTablet[playerid][i]);
    for(new i = 0; i < 11; i++) PlayerTextDrawDestroy(playerid, ui_racing[playerid][i]);
    return 1;
}

stock ShowUiTablet(playerid)
{
    for(new i = 0; i < 48; i++) 
        PlayerTextDrawShow(playerid, RaceTablet[playerid][i]);

    SelectTextDraw(playerid, COLOR_GREY);
    SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Gunakan perintah /race untuk mengatur balapan.");
    SendClientMessageEx(playerid, COLOR_YELLOW,   "[Race] {FFFFFF}/race save [id] - Simpan checkpoint secara manual di posisi kamu.");
    SendClientMessageEx(playerid, COLOR_YELLOW,   "[Race] {FFFFFF}/race reset - Hapus semua checkpoint.");
    SendClientMessageEx(playerid, COLOR_YELLOW,   "[Race] {FFFFFF}/race setcp [nama] - Simpan track ke list race dan juga untuk save posisi finish.");
    SendClientMessageEx(playerid, COLOR_YELLOW,   "[Race] {FFFFFF}/race start - Mulai balapan.");
    SendClientMessageEx(playerid, COLOR_YELLOW,   "[Race] {FFFFFF}/race leave - Keluar dari balapan.");
    return 1;
}

stock HideUiTablet(playerid)
{
    for(new i = 0; i < 48; i++) PlayerTextDrawHide(playerid, RaceTablet[playerid][i]);
    CancelSelectTextDraw(playerid);
    return 1;
}

hook ClickDynPlayerTextdraw(playerid, PlayerText: playertextid)
{
    if(playertextid == RaceTablet[playerid][35]) // Tutup
    {
        HideUiTablet(playerid);
        Toggle_AllTextdraws(playerid, true);
        RemovePlayerAttachedObject(playerid, 9);
		if(!IsPlayerInAnyVehicle(playerid)) {
			ClearAnimations(playerid, 1);
		}
    }
    if(playertextid == RaceTablet[playerid][38]) // Leaderboard
    {
        if(!InRace[playerid] && RaceFinishTime[playerid] == 0)
        return SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Kamu tidak sedang ikut race!");

        ShowRaceLeaderboard(playerid);
    }
    if(playertextid == RaceTablet[playerid][42]) // Player menu
    {
        new str[256];
        format(str, sizeof(str), "%s\n%s\n%s","Invite ke Balapan","Kick dari Balapan","List orang dalam Balapan");
        ShowPlayerDialog(playerid, DIALOG_RACE_MAIN, DIALOG_STYLE_LIST,"Race - Player Menu", str, "Select", "Close");
    }
    if(playertextid == RaceTablet[playerid][39]) // Create track
    {
        if (!SaveMode[playerid])
        {
            SaveMode[playerid] = true;
            SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Interactive Save ON. Tekan tombol Y untuk menyimpan checkpoint. Gunakan /race setcp untuk selesai.");
        }
        else
        {
            SaveMode[playerid] = false;
            SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Interactive Save OFF.");
        }
    }
    if(playertextid == RaceTablet[playerid][41]) // End track
    {
        if (!InRace[playerid] && RaceWith[playerid] == INVALID_PLAYER_ID)
            return Error(playerid, "Kamu tidak sedang mengadakan race.");

        new ownerid = playerid;

        if (RaceWith[playerid] != INVALID_PLAYER_ID && RaceWith[playerid] != playerid)
            return Error(playerid, "Hanya owner yang bisa mengakhiri race.");

        foreach (new p : Player)
        {
            if (RaceWith[p] == ownerid || p == ownerid)
            {
                InRace[p]    = false;
                RaceIndex[p] = -1;
                RaceWith[p]  = INVALID_PLAYER_ID;
                DisablePlayerRaceCheckpoint(p);
                RaceUI_Hide(p);
                Race_EnableGhost(p, false);

                if (p != ownerid)
                    SendClientMessageEx(p, COLOR_YELLOW, "[Race] {FFFFFF}Race dihentikan oleh owner.");
            }
        }

        if (RankingsTimer[ownerid] != -1)
        {
            KillTimer(RankingsTimer[ownerid]);
            RankingsTimer[ownerid] = -1;
        }

        SendClientMessageEx(ownerid, COLOR_YELLOW, "[Race] {FFFFFF}Kamu berhasil mengakhiri race.");
    }
    if(playertextid == RaceTablet[playerid][40]) // List track
    {
        mysql_tquery(g_SQL, "SELECT id, name, owner, created_at FROM race_tracks ORDER BY id DESC LIMIT 30", 
        "OnShowTrackList", "i", playerid);
    }
    return 1;
}