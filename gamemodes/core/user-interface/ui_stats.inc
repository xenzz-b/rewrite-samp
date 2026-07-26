#include <YSI_Coding\y_hooks>
new PlayerText: StaticVRP[MAX_PLAYERS][34];
new OnlinePlayerAll;

CreatePStatsTD(playerid)
{
    StaticVRP[playerid][0] = CreatePlayerTextDraw(playerid, 615.000, 132.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][0], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][0], -12255082);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][0], 1);

    StaticVRP[playerid][1] = CreatePlayerTextDraw(playerid, 615.000, 156.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][1], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][1], -12255082);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][1], 1);

    StaticVRP[playerid][2] = CreatePlayerTextDraw(playerid, 615.000, 180.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][2], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][2], -12255082);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][2], 1);

    StaticVRP[playerid][3] = CreatePlayerTextDraw(playerid, 615.000, 204.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][3], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][3], -12255082);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][3], 1);

    StaticVRP[playerid][4] = CreatePlayerTextDraw(playerid, 615.000, 228.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][4], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][4], -12255082);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][4], 1);

    StaticVRP[playerid][5] = CreatePlayerTextDraw(playerid, 615.000, 252.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][5], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][5], -12255082);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][5], 1);

    StaticVRP[playerid][6] = CreatePlayerTextDraw(playerid, 617.000, 135.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][6], 15.500, 14.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][6], -12254977);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][6], 1);

    StaticVRP[playerid][7] = CreatePlayerTextDraw(playerid, 624.000, 136.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][7], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][7], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][7], 9109647);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][7], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][7], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][7], 1);

    StaticVRP[playerid][8] = CreatePlayerTextDraw(playerid, 622.000, 140.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][8], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][8], 10.500, 6.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][8], 9109647);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][8], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][8], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][8], 1);

    StaticVRP[playerid][9] = CreatePlayerTextDraw(playerid, 620.000, 137.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][9], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][9], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][9], 9109709);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][9], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][9], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][9], 1);

    StaticVRP[playerid][10] = CreatePlayerTextDraw(playerid, 618.000, 141.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][10], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][10], 10.500, 6.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][10], 9109679);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][10], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][10], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][10], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][10], 1);

    StaticVRP[playerid][11] = CreatePlayerTextDraw(playerid, 617.000, 159.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][11], 15.500, 14.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][11], -12254977);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][11], 1);

    StaticVRP[playerid][12] = CreatePlayerTextDraw(playerid, 623.000, 160.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][12], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][12], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][12], -1);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][12], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][12], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][12], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][12], 1);

    StaticVRP[playerid][13] = CreatePlayerTextDraw(playerid, 621.000, 165.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][13], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][13], 10.000, 6.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][13], -1);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][13], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][13], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][13], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][13], 1);

    StaticVRP[playerid][14] = CreatePlayerTextDraw(playerid, 623.000, 184.000, "$");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][14], 0.195, 1.049);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][14], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][14], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][14], 1);

    StaticVRP[playerid][15] = CreatePlayerTextDraw(playerid, 617.000, 207.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][15], 15.500, 14.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][15], -12254977);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][15], 1);

    StaticVRP[playerid][16] = CreatePlayerTextDraw(playerid, 622.000, 211.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][16], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][16], 7.500, 5.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][16], -1);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][16], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][16], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][16], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][16], 1);

    StaticVRP[playerid][17] = CreatePlayerTextDraw(playerid, 627.000, 212.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][17], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][17], 3.000, 2.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][17], 1687547391);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][17], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][17], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][17], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][17], 1);

    StaticVRP[playerid][18] = CreatePlayerTextDraw(playerid, 617.000, 231.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][18], 15.500, 14.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][18], -12254977);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][18], 1);

    StaticVRP[playerid][19] = CreatePlayerTextDraw(playerid, 622.000, 236.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][19], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][19], 7.500, 5.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][19], -1);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][19], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][19], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][19], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][19], 1);

    StaticVRP[playerid][20] = CreatePlayerTextDraw(playerid, 623.000, 233.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][20], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][20], 5.500, 5.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][20], -1);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][20], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][20], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][20], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][20], 1);

    StaticVRP[playerid][21] = CreatePlayerTextDraw(playerid, 624.000, 234.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][21], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][21], 3.500, 2.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][21], 1687547391);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][21], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][21], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][21], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][21], 1);

    StaticVRP[playerid][22] = CreatePlayerTextDraw(playerid, 617.000, 255.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][22], 15.500, 14.500);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][22], -12254977);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][22], 1);

    StaticVRP[playerid][23] = CreatePlayerTextDraw(playerid, 623.000, 255.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][23], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][23], 6.000, 6.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][23], -16776961);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][23], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][23], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][23], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][23], 1);

    StaticVRP[playerid][24] = CreatePlayerTextDraw(playerid, 620.000, 257.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][24], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][24], 4.500, 5.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][24], -16776961);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][24], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][24], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][24], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][24], 1);

    StaticVRP[playerid][25] = CreatePlayerTextDraw(playerid, 627.000, 257.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][25], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][25], 4.500, 5.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][25], -16776961);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][25], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][25], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][25], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][25], 1);

    StaticVRP[playerid][26] = CreatePlayerTextDraw(playerid, 620.000, 261.000, "ld_beat:chit");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][26], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][26], 12.500, 5.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][26], -16776961);
    PlayerTextDrawUseBox(playerid, StaticVRP[playerid][26], 1);
    PlayerTextDrawBoxColor(playerid, StaticVRP[playerid][26], 50);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][26], 1);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][26], 1);

    StaticVRP[playerid][27] = CreatePlayerTextDraw(playerid, 614.000, 137.000, "100/800");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][27], 0.170, 0.750);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][27], 637.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][27], 3);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][27], 9109759);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][27], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][27], 1);

    StaticVRP[playerid][28] = CreatePlayerTextDraw(playerid, 614.000, 161.000, "#50");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][28], 0.170, 0.750);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][28], 637.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][28], 3);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][28], -1);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][28], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][28], 1);

    StaticVRP[playerid][29] = CreatePlayerTextDraw(playerid, 614.000, 185.000, "$10,000.000 Cash");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][29], 0.170, 0.750);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][29], 637.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][29], 3);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][29], -1);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][29], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][29], 1);

    StaticVRP[playerid][30] = CreatePlayerTextDraw(playerid, 614.000, 209.000, "$90,000.000 Bank");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][30], 0.170, 0.750);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][30], 637.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][30], 3);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][30], 1);

    StaticVRP[playerid][31] = CreatePlayerTextDraw(playerid, 614.000, 232.000, "Medis - Tukang Minyak");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][31], 0.170, 0.750);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][31], 637.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][31], 3);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][31], 1);

    StaticVRP[playerid][32] = CreatePlayerTextDraw(playerid, 614.000, 256.000, "Los Cosa Notra Family");
    PlayerTextDrawLetterSize(playerid, StaticVRP[playerid][32], 0.170, 0.750);
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][32], 637.000, 17.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][32], 3);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][32], -16776961);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][32], 1);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][32], 1);

    StaticVRP[playerid][33] = CreatePlayerTextDraw(playerid, 617.000, 183.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, StaticVRP[playerid][33], 15.500, 14.000);
    PlayerTextDrawAlignment(playerid, StaticVRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, StaticVRP[playerid][33], -12254977);
    PlayerTextDrawSetShadow(playerid, StaticVRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, StaticVRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, StaticVRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, StaticVRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, StaticVRP[playerid][33], 1);
}
//ShowStatsTD(playerid)
// {
//     for(new i = 0; i < 34; i++)
//     {
//         PlayerTextDrawShow(playerid, StaticVRP[playerid][i]);
//     }
//     return 1;
// }

//HideStatsTD(playerid)
// {
//     for(new i = 0; i < 34; i++)
//     {
//         PlayerTextDrawHide(playerid, StaticVRP[playerid][i]);
//     }
//     return 1;
// }

enum e_HUDCache {
    cache_Money,
    cache_Bank,
    cache_Family,
    cache_Job,
    cache_Faction,
    cache_Online
};
new HUDCache[MAX_PLAYERS][e_HUDCache];

// stock InitPlayerHUD(playerid)
// {
//     new str[128];
    
//     // Online Players - index 27
//     format(str, sizeof(str), "%d/%d", OnlinePlayerAll, MAX_PLAYERS);
//     PlayerTextDrawSetString(playerid, StaticVRP[playerid][27], str);
//     HUDCache[playerid][cache_Online] = OnlinePlayerAll;
    
//     // Player ID - index 28
//     format(str, sizeof(str), "#%d", playerid);
//     PlayerTextDrawSetString(playerid, StaticVRP[playerid][28], str);
    
//     // Money - index 29
//     format(str, sizeof(str), "%s Cash", FormatMoney(AccountData[playerid][pMoney]));
//     PlayerTextDrawSetString(playerid, StaticVRP[playerid][29], str);
//     HUDCache[playerid][cache_Money] = AccountData[playerid][pMoney];
    
//     // Bank - index 30
//     format(str, sizeof(str), "%s Bank", FormatMoney(AccountData[playerid][pBankMoney]));
//     PlayerTextDrawSetString(playerid, StaticVRP[playerid][30], str);
//     HUDCache[playerid][cache_Bank] = AccountData[playerid][pBankMoney];
    
//     // Job & Faction - index 31
//     format(str, sizeof(str), "%s - %s", GetFactionName(playerid), GetJobName(playerid));
//     PlayerTextDrawSetString(playerid, StaticVRP[playerid][31], str);
//     HUDCache[playerid][cache_Job] = AccountData[playerid][pJob];
//     HUDCache[playerid][cache_Faction] = AccountData[playerid][pFaction];
    
//     // Family - index 32
//     new fid = AccountData[playerid][pFamily];
//     if(fid != -1)
//         format(str, sizeof(str), "%s Family", FamilyData[fid][famName]);
//     else
//         format(str, sizeof(str), "N/A Family");
//     PlayerTextDrawSetString(playerid, StaticVRP[playerid][32], str);
//     HUDCache[playerid][cache_Family] = fid;

//     //ShowStatsTD(playerid);
// }

// hook OnPlayerSpawn(playerid)
// {
//     InitPlayerHUD(playerid);
//     return 1;
// }

// ptask StaticUpdateVRP[1000](playerid)
// {
//     if(IsPlayerConnected(playerid) && AccountData[playerid][IsLoggedIn] && AccountData[playerid][pSpawned])
//     {
//         new str[128];
//         new bool:updated = false;

//         if(HUDCache[playerid][cache_Online] != OnlinePlayerAll)
//         {
//             HUDCache[playerid][cache_Online] = OnlinePlayerAll;
//             format(str, sizeof(str), "%d/%d", OnlinePlayerAll, MAX_PLAYERS);
//             PlayerTextDrawSetString(playerid, StaticVRP[playerid][27], str);
//             updated = true;
//         }
//         new currentMoney = AccountData[playerid][pMoney];
//         if(HUDCache[playerid][cache_Money] != currentMoney)
//         {
//             HUDCache[playerid][cache_Money] = currentMoney;
//             format(str, sizeof(str), "%s Cash", FormatMoney(currentMoney));
//             PlayerTextDrawSetString(playerid, StaticVRP[playerid][29], str);
//             updated = true;
//         }
//         new currentBank = AccountData[playerid][pBankMoney];
//         if(HUDCache[playerid][cache_Bank] != currentBank)
//         {
//             HUDCache[playerid][cache_Bank] = currentBank;
//             format(str, sizeof(str), "%s Bank", FormatMoney(currentBank));
//             PlayerTextDrawSetString(playerid, StaticVRP[playerid][30], str);
//             updated = true;
//         }

//         new currentJob = AccountData[playerid][pJob];
//         new currentFaction = AccountData[playerid][pFaction];
//         if(HUDCache[playerid][cache_Job] != currentJob || HUDCache[playerid][cache_Faction] != currentFaction)
//         {
//             HUDCache[playerid][cache_Job] = currentJob;
//             HUDCache[playerid][cache_Faction] = currentFaction;
//             format(str, sizeof(str), "%s - %s", GetFactionName(playerid), GetJobName(playerid));
//             PlayerTextDrawSetString(playerid, StaticVRP[playerid][31], str);
//             updated = true;
//         }

//         new currentFamily = AccountData[playerid][pFamily];
//         if(HUDCache[playerid][cache_Family] != currentFamily)
//         {
//             HUDCache[playerid][cache_Family] = currentFamily;
//             if(currentFamily != -1)
//                 format(str, sizeof(str), "%s Family", FamilyData[currentFamily][famName]);
//             else
//                 format(str, sizeof(str), "N/A Family");
//             PlayerTextDrawSetString(playerid, StaticVRP[playerid][32], str);
//             updated = true;
//         }
//         if(updated)
//         {
//             // //ShowStatsTD(playerid);
//         }
//     }
//     return 1;
// }

// hook OnPlayerConnect(playerid)
// {
//     OnlinePlayerAll++;
//     for(new i = 0; i < _:e_HUDCache; i++)
//     {
//         HUDCache[playerid][e_HUDCache:i] = -1;
//     }
//     return 1;
// }

// hook OnPlayerDisconnect(playerid)
// {
//     OnlinePlayerAll--;
//     return 1;
// }