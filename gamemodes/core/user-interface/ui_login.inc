new PlayerText: LoginNSRP[MAX_PLAYERS][69];

CreateLoginNSRP(playerid)
{
	LoginNSRP[playerid][0] = CreatePlayerTextDraw(playerid, 0.000, -1.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][0], 643.000, 449.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][0], 235669759);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][0], 1);

    LoginNSRP[playerid][1] = CreatePlayerTextDraw(playerid, 239.000, 74.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][1], 174.000, 309.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][1], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][1], 1);

    LoginNSRP[playerid][2] = CreatePlayerTextDraw(playerid, 235.000, 62.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][2], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][2], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][2], 1);

    LoginNSRP[playerid][3] = CreatePlayerTextDraw(playerid, 393.000, 62.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][3], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][3], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][3], 1);

    LoginNSRP[playerid][4] = CreatePlayerTextDraw(playerid, 393.000, 369.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][4], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][4], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][4], 1);

    LoginNSRP[playerid][5] = CreatePlayerTextDraw(playerid, 235.000, 369.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][5], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][5], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][5], 1);

    LoginNSRP[playerid][6] = CreatePlayerTextDraw(playerid, 248.000, 66.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][6], 155.000, 324.500);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][6], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][6], 1);

    LoginNSRP[playerid][7] = CreatePlayerTextDraw(playerid, 236.000, 63.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][7], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][7], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][7], 1);

    LoginNSRP[playerid][8] = CreatePlayerTextDraw(playerid, 392.000, 63.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][8], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][8], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][8], 1);

    LoginNSRP[playerid][9] = CreatePlayerTextDraw(playerid, 392.000, 368.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][9], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][9], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][9], 1);

    LoginNSRP[playerid][10] = CreatePlayerTextDraw(playerid, 236.000, 368.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][10], 24.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][10], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][10], 1);

    LoginNSRP[playerid][11] = CreatePlayerTextDraw(playerid, 248.000, 67.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][11], 155.000, 322.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][11], 319817727);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][11], 1);

    LoginNSRP[playerid][12] = CreatePlayerTextDraw(playerid, 240.000, 76.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][12], 172.000, 301.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][12], 286331391);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][12], 1);

    LoginNSRP[playerid][13] = CreatePlayerTextDraw(playerid, 248.000, 67.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][13], 155.000, 25.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][13], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][13], 1);

    LoginNSRP[playerid][14] = CreatePlayerTextDraw(playerid, 240.000, 76.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][14], 172.000, 23.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][14], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][14], 1);

    LoginNSRP[playerid][15] = CreatePlayerTextDraw(playerid, 240.000, 99.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][15], 172.000, 1.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][15], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][15], 1);

    LoginNSRP[playerid][16] = CreatePlayerTextDraw(playerid, 248.000, 363.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][16], 155.000, 26.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][16], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][16], 1);

    LoginNSRP[playerid][17] = CreatePlayerTextDraw(playerid, 240.000, 363.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][17], 172.000, 20.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][17], 218959359);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][17], 1);

    LoginNSRP[playerid][18] = CreatePlayerTextDraw(playerid, 240.000, 362.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][18], 172.000, 1.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][18], 572662527);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][18], 1);

    LoginNSRP[playerid][19] = CreatePlayerTextDraw(playerid, 252.000, 79.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][19], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][19], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][19], 1);

    LoginNSRP[playerid][20] = CreatePlayerTextDraw(playerid, 261.000, 79.000, "NEXSTON ROLEPLAY");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][20], 0.189, 0.898);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][20], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][20], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][20], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][20], 1);

    LoginNSRP[playerid][21] = CreatePlayerTextDraw(playerid, 304.000, 111.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][21], 46.000, 54.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][21], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][21], 1);

    LoginNSRP[playerid][22] = CreatePlayerTextDraw(playerid, 304.000, 111.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][22], 46.000, 54.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][22], 286331391);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][22], 1);

    LoginNSRP[playerid][23] = CreatePlayerTextDraw(playerid, 295.000, 164.000, "Selamat Datang");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][23], 0.239, 1.399);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][23], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][23], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][23], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][23], 1);

    LoginNSRP[playerid][24] = CreatePlayerTextDraw(playerid, 327.000, 130.000, "NX");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][24], 0.300, 1.700);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][24], 2);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][24], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][24], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][24], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][24], 0);

    LoginNSRP[playerid][25] = CreatePlayerTextDraw(playerid, 256.000, 209.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][25], 140.000, 24.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][25], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][25], 1);

    LoginNSRP[playerid][26] = CreatePlayerTextDraw(playerid, 256.000, 257.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][26], 140.000, 24.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][26], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][26], 1);

    LoginNSRP[playerid][27] = CreatePlayerTextDraw(playerid, 249.000, 207.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][27], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][27], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][27], 1);

    LoginNSRP[playerid][28] = CreatePlayerTextDraw(playerid, 249.000, 222.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][28], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][28], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][28], 1);

    LoginNSRP[playerid][29] = CreatePlayerTextDraw(playerid, 390.000, 222.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][29], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][29], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][29], 1);

    LoginNSRP[playerid][30] = CreatePlayerTextDraw(playerid, 390.000, 207.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][30], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][30], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][30], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][30], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][30], 1);

    LoginNSRP[playerid][31] = CreatePlayerTextDraw(playerid, 251.000, 212.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][31], 150.000, 17.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][31], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][31], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][31], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][31], 1);

    LoginNSRP[playerid][32] = CreatePlayerTextDraw(playerid, 250.000, 208.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][32], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][32], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][32], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][32], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][32], 1);

    LoginNSRP[playerid][33] = CreatePlayerTextDraw(playerid, 250.000, 221.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][33], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][33], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][33], 1);

    LoginNSRP[playerid][34] = CreatePlayerTextDraw(playerid, 389.000, 221.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][34], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][34], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][34], 1);

    LoginNSRP[playerid][35] = CreatePlayerTextDraw(playerid, 389.000, 208.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][35], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][35], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][35], 1);

    LoginNSRP[playerid][36] = CreatePlayerTextDraw(playerid, 257.000, 210.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][36], 138.000, 21.500);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][36], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][36], 1);

    LoginNSRP[playerid][37] = CreatePlayerTextDraw(playerid, 252.000, 214.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][37], 148.000, 12.500);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][37], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][37], 1);

    LoginNSRP[playerid][38] = CreatePlayerTextDraw(playerid, 249.000, 255.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][38], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][38], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][38], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][38], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][38], 1);

    LoginNSRP[playerid][39] = CreatePlayerTextDraw(playerid, 249.000, 270.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][39], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][39], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][39], 1);

    LoginNSRP[playerid][40] = CreatePlayerTextDraw(playerid, 390.000, 255.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][40], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][40], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][40], 1);

    LoginNSRP[playerid][41] = CreatePlayerTextDraw(playerid, 390.000, 270.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][41], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][41], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][41], 1);

    LoginNSRP[playerid][42] = CreatePlayerTextDraw(playerid, 251.000, 260.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][42], 150.000, 17.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][42], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][42], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][42], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][42], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][42], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][42], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][42], 1);

    LoginNSRP[playerid][43] = CreatePlayerTextDraw(playerid, 250.000, 256.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][43], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][43], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][43], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][43], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][43], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][43], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][43], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][43], 1);

    LoginNSRP[playerid][44] = CreatePlayerTextDraw(playerid, 250.000, 269.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][44], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][44], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][44], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][44], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][44], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][44], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][44], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][44], 1);

    LoginNSRP[playerid][45] = CreatePlayerTextDraw(playerid, 389.000, 256.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][45], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][45], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][45], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][45], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][45], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][45], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][45], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][45], 1);

    LoginNSRP[playerid][46] = CreatePlayerTextDraw(playerid, 389.000, 269.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][46], 13.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][46], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][46], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][46], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][46], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][46], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][46], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][46], 1);

    LoginNSRP[playerid][47] = CreatePlayerTextDraw(playerid, 257.000, 258.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][47], 138.000, 21.500);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][47], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][47], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][47], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][47], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][47], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][47], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][47], 1);

    LoginNSRP[playerid][48] = CreatePlayerTextDraw(playerid, 252.000, 262.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][48], 148.000, 14.500);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][48], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][48], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][48], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][48], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][48], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][48], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][48], 1);

    LoginNSRP[playerid][49] = CreatePlayerTextDraw(playerid, 255.000, 261.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][49], 142.000, 16.500);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][49], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][49], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][49], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][49], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][49], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][49], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][49], 1);
    PlayerTextDrawSetSelectable(playerid, LoginNSRP[playerid][49], 1);

    LoginNSRP[playerid][50] = CreatePlayerTextDraw(playerid, 291.000, 295.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][50], 65.000, 24.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][50], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][50], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][50], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][50], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][50], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][50], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][50], 1);

    LoginNSRP[playerid][51] = CreatePlayerTextDraw(playerid, 285.000, 293.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][51], 13.000, 14.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][51], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][51], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][51], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][51], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][51], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][51], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][51], 1);

    LoginNSRP[playerid][52] = CreatePlayerTextDraw(playerid, 285.000, 308.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][52], 13.000, 14.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][52], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][52], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][52], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][52], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][52], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][52], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][52], 1);

    LoginNSRP[playerid][53] = CreatePlayerTextDraw(playerid, 349.000, 308.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][53], 13.000, 14.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][53], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][53], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][53], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][53], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][53], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][53], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][53], 1);

    LoginNSRP[playerid][54] = CreatePlayerTextDraw(playerid, 349.000, 293.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][54], 13.000, 14.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][54], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][54], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][54], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][54], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][54], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][54], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][54], 1);

    LoginNSRP[playerid][55] = CreatePlayerTextDraw(playerid, 287.000, 299.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][55], 73.000, 16.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][55], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][55], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][55], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][55], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][55], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][55], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][55], 1);

    LoginNSRP[playerid][56] = CreatePlayerTextDraw(playerid, 290.000, 297.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][56], 67.000, 20.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][56], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][56], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][56], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][56], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][56], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][56], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][56], 1);
    PlayerTextDrawSetSelectable(playerid, LoginNSRP[playerid][56], 1);

    LoginNSRP[playerid][57] = CreatePlayerTextDraw(playerid, 324.000, 302.000, "Login");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][57], 0.209, 0.999);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][57], 2);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][57], -1);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][57], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][57], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][57], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][57], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][57], 1);

    LoginNSRP[playerid][58] = CreatePlayerTextDraw(playerid, 326.000, 372.000, "samp.nexstonrp.id");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][58], 0.170, 0.799);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][58], 2);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][58], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][58], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][58], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][58], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][58], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][58], 1);

    LoginNSRP[playerid][59] = CreatePlayerTextDraw(playerid, 256.000, 214.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][59], 12.000, 13.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][59], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][59], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][59], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][59], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][59], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][59], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][59], 1);

    LoginNSRP[playerid][60] = CreatePlayerTextDraw(playerid, 257.000, 215.000, "LD_BEAT:chit");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][60], 10.000, 11.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][60], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][60], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][60], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][60], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][60], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][60], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][60], 1);

    LoginNSRP[playerid][61] = CreatePlayerTextDraw(playerid, 259.000, 264.500, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][61], 7.000, 8.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][61], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][61], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][61], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][61], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][61], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][61], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][61], 1);

    LoginNSRP[playerid][62] = CreatePlayerTextDraw(playerid, 259.500, 265.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, LoginNSRP[playerid][62], 6.000, 7.000);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][62], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][62], 471604479);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][62], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][62], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][62], 255);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][62], 4);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][62], 1);

    LoginNSRP[playerid][63] = CreatePlayerTextDraw(playerid, 251.000, 198.000, "USERNAME");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][63], 0.179, 0.797);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][63], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][63], -7851009);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][63], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][63], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][63], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][63], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][63], 1);

    LoginNSRP[playerid][64] = CreatePlayerTextDraw(playerid, 251.000, 246.000, "PASSWORD");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][64], 0.179, 0.797);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][64], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][64], -7851009);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][64], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][64], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][64], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][64], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][64], 1);

    LoginNSRP[playerid][65] = CreatePlayerTextDraw(playerid, 283.000, 341.000, "Lupa Password? Hubungi admin server");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][65], 0.149, 0.797);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][65], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][65], -10092289);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][65], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][65], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][65], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][65], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][65], 1);

    LoginNSRP[playerid][66] = CreatePlayerTextDraw(playerid, 325.000, 180.000, "Silakan login untuk bermain");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][66], 0.149, 0.898);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][66], 2);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][66], -2004317953);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][66], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][66], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][66], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][66], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][66], 1);

    LoginNSRP[playerid][67] = CreatePlayerTextDraw(playerid, 270.000, 217.000, "Chess7");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][67], 0.170, 0.799);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][67], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][67], -858993409);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][67], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][67], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][67], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][67], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][67], 1);

    LoginNSRP[playerid][68] = CreatePlayerTextDraw(playerid, 270.000, 264.000, "_");
    PlayerTextDrawLetterSize(playerid, LoginNSRP[playerid][68], 0.170, 0.799);
    PlayerTextDrawAlignment(playerid, LoginNSRP[playerid][68], 1);
    PlayerTextDrawColor(playerid, LoginNSRP[playerid][68], -858993409);
    PlayerTextDrawSetShadow(playerid, LoginNSRP[playerid][68], 0);
    PlayerTextDrawSetOutline(playerid, LoginNSRP[playerid][68], 0);
    PlayerTextDrawBackgroundColor(playerid, LoginNSRP[playerid][68], 150);
    PlayerTextDrawFont(playerid, LoginNSRP[playerid][68], 1);
    PlayerTextDrawSetProportional(playerid, LoginNSRP[playerid][68], 1);
}

ShowLoginNSRP(playerid, bool:status)
{
	if(status)
	{
		for(new i = 0; i < 69; i++)
		{
			PlayerTextDrawShow(playerid, LoginNSRP[playerid][i]);
		}
		SelectTextDraw(playerid, 0xFF6600FF);
	}
	else 
	{
		for(new i = 0; i < 69; i++)
		{
			PlayerTextDrawDestroy(playerid, LoginNSRP[playerid][i]);
            LoginNSRP[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
		}
		CancelSelectTextDraw(playerid);
	}
	return 1;
}