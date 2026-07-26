new PlayerText: CctvNSRP[MAX_PLAYERS][40];

CreateCctvTD(playerid)
{
    CctvNSRP[playerid][0] = CreatePlayerTextDraw(playerid, -1.000, 0.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][0], 641.000, 56.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][0], 218959359);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][0], 1);

    CctvNSRP[playerid][1] = CreatePlayerTextDraw(playerid, -1.000, 393.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][1], 641.000, 56.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][1], 218959359);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][1], 1);

    CctvNSRP[playerid][2] = CreatePlayerTextDraw(playerid, 19.000, 22.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][2], 9.000, 11.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][2], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][2], 1);

    CctvNSRP[playerid][3] = CreatePlayerTextDraw(playerid, 30.000, 21.000, "REC");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][3], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][3], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][3], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][3], 1);

    CctvNSRP[playerid][4] = CreatePlayerTextDraw(playerid, 320.000, 24.000, "CCTV");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][4], 0.230, 1.098);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][4], 2);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][4], -2004317953);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][4], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][4], 1);

    CctvNSRP[playerid][5] = CreatePlayerTextDraw(playerid, 631.000, 24.000, "09:22:22");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][5], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][5], 3);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][5], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][5], 1);

    CctvNSRP[playerid][6] = CreatePlayerTextDraw(playerid, 6.000, 411.000, "CORDINATES");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][6], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][6], 1431655935);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][6], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][6], 1);

    CctvNSRP[playerid][7] = CreatePlayerTextDraw(playerid, 6.000, 421.000, "X: 123.44 Y: 232.242 Z: 234.555");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][7], 0.140, 0.898);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][7], -858993409);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][7], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][7], 1);

    CctvNSRP[playerid][8] = CreatePlayerTextDraw(playerid, 632.000, 411.000, "MODE");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][8], 0.150, 0.799);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][8], 3);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][8], 1431655935);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][8], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][8], 1);

    CctvNSRP[playerid][9] = CreatePlayerTextDraw(playerid, 634.000, 420.000, "CCTV");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][9], 0.180, 0.999);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][9], 3);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][9], 2143944703);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][9], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][9], 1);

    CctvNSRP[playerid][10] = CreatePlayerTextDraw(playerid, 281.000, 366.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][10], 110.000, 20.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][10], 774778623);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][10], 1);

    CctvNSRP[playerid][11] = CreatePlayerTextDraw(playerid, 257.000, 366.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][11], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][11], 774778623);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][11], 1);

    CctvNSRP[playerid][12] = CreatePlayerTextDraw(playerid, 396.000, 366.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][12], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][12], 774778623);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][12], 1);

    CctvNSRP[playerid][13] = CreatePlayerTextDraw(playerid, 282.000, 367.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][13], 108.000, 18.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][13], 218959359);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][13], 1);

    CctvNSRP[playerid][14] = CreatePlayerTextDraw(playerid, 258.000, 367.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][14], 17.298, 18.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][14], 218959359);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][14], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][14], 1);

    CctvNSRP[playerid][15] = CreatePlayerTextDraw(playerid, 397.000, 367.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][15], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][15], 218959359);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][15], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][15], 1);

    CctvNSRP[playerid][16] = CreatePlayerTextDraw(playerid, 267.000, 371.000, "<-");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][16], 0.219, 1.098);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][16], 2);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][16], -1);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][16], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][16], 2);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][16], 1);

    CctvNSRP[playerid][17] = CreatePlayerTextDraw(playerid, 406.000, 371.000, "->");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][17], 0.219, 1.098);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][17], 2);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][17], -1);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][17], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][17], 2);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][17], 1);

    CctvNSRP[playerid][18] = CreatePlayerTextDraw(playerid, 338.000, 371.000, "Chief of Police Room");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][18], 0.200, 0.999);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][18], 2);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][18], 1717987071);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][18], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][18], 1);

    CctvNSRP[playerid][19] = CreatePlayerTextDraw(playerid, 619.000, 163.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][19], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][19], 774778623);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][19], 1);

    CctvNSRP[playerid][20] = CreatePlayerTextDraw(playerid, 619.000, 273.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][20], 19.000, 20.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][20], 774778623);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][20], 1);

    CctvNSRP[playerid][21] = CreatePlayerTextDraw(playerid, 620.000, 164.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][21], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][21], 437918463);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][21], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][21], 1);

    CctvNSRP[playerid][22] = CreatePlayerTextDraw(playerid, 620.000, 274.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][22], 17.000, 18.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][22], 437918463);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][22], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][22], 1);

    CctvNSRP[playerid][23] = CreatePlayerTextDraw(playerid, 628.000, 186.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][23], 2.000, 83.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][23], 774778623);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][23], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][23], 1);

    CctvNSRP[playerid][24] = CreatePlayerTextDraw(playerid, 628.000, 269.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][24], 2.000, -41.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][24], 1717987071);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][24], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][24], 1);

    CctvNSRP[playerid][25] = CreatePlayerTextDraw(playerid, 628.500, 166.000, "+");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][25], 0.280, 1.399);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][25], 2);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][25], -1);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][25], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][25], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][25], 1);

    CctvNSRP[playerid][26] = CreatePlayerTextDraw(playerid, 628.500, 278.000, "-");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][26], 0.319, 0.799);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][26], 2);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][26], -1);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][26], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][26], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][26], 1);

    CctvNSRP[playerid][27] = CreatePlayerTextDraw(playerid, 3.000, 57.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][27], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][27], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][27], 1);

    CctvNSRP[playerid][28] = CreatePlayerTextDraw(playerid, 3.000, 66.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][28], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][28], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][28], 1);

    CctvNSRP[playerid][29] = CreatePlayerTextDraw(playerid, 34.000, 66.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][29], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][29], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][29], 1);

    CctvNSRP[playerid][30] = CreatePlayerTextDraw(playerid, 34.000, 57.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][30], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][30], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][30], 1);

    CctvNSRP[playerid][31] = CreatePlayerTextDraw(playerid, 9.000, 59.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][31], 32.000, 19.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][31], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][31], 1);

    CctvNSRP[playerid][32] = CreatePlayerTextDraw(playerid, 5.000, 63.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][32], 39.000, 12.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][32], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][32], 1);

    CctvNSRP[playerid][33] = CreatePlayerTextDraw(playerid, 4.000, 58.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][33], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][33], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][33], 1);

    CctvNSRP[playerid][34] = CreatePlayerTextDraw(playerid, 4.000, 65.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][34], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][34], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][34], 1);

    CctvNSRP[playerid][35] = CreatePlayerTextDraw(playerid, 33.000, 65.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][35], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][35], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][35], 1);

    CctvNSRP[playerid][36] = CreatePlayerTextDraw(playerid, 33.000, 58.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][36], 12.000, 14.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][36], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][36], 1);

    CctvNSRP[playerid][37] = CreatePlayerTextDraw(playerid, 6.000, 65.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][37], 37.000, 9.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][37], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][37], 1);

    CctvNSRP[playerid][38] = CreatePlayerTextDraw(playerid, 10.000, 60.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, CctvNSRP[playerid][38], 28.000, 16.000);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][38], -13421569);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][38], 1);
    PlayerTextDrawSetSelectable(playerid, CctvNSRP[playerid][38], 1);

    CctvNSRP[playerid][39] = CreatePlayerTextDraw(playerid, 18.000, 64.000, "Exit");
    PlayerTextDrawLetterSize(playerid, CctvNSRP[playerid][39], 0.200, 0.999);
    PlayerTextDrawAlignment(playerid, CctvNSRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, CctvNSRP[playerid][39], -9408257);
    PlayerTextDrawSetShadow(playerid, CctvNSRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, CctvNSRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, CctvNSRP[playerid][39], 150);
    PlayerTextDrawFont(playerid, CctvNSRP[playerid][39], 1);
    PlayerTextDrawSetProportional(playerid, CctvNSRP[playerid][39], 1);
}

ShowCctv(playerid, bool:status)
{
    if(status)
    {
        for(new i = 0; i < 40; i++)
        {
            PlayerTextDrawShow(playerid, CctvNSRP[playerid][i]);
        }
        SelectTextDraw(playerid, Y_SERVER);
    }
    else 
    {
        for(new i = 0; i < 40; i++)
        {
            PlayerTextDrawHide(playerid, CctvNSRP[playerid][i]);
        }
        CancelSelectTextDraw(playerid);
    }
    return 1;
}