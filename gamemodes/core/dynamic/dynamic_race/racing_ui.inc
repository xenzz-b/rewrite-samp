new PlayerText: ui_racing[MAX_PLAYERS][11];

CreateRacingTD(playerid)
{
    ui_racing[playerid][0] = CreatePlayerTextDraw(playerid, 520.000, 198.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ui_racing[playerid][0], 123.000, 18.000);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][0], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_racing[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][0], 1);

    ui_racing[playerid][1] = CreatePlayerTextDraw(playerid, 520.000, 215.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ui_racing[playerid][1], 123.000, 18.000);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][1], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][1], -57);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_racing[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][1], 1);

    ui_racing[playerid][2] = CreatePlayerTextDraw(playerid, 520.000, 233.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ui_racing[playerid][2], 123.000, 18.000);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][2], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][2], -421070081);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_racing[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][2], 1);

    ui_racing[playerid][3] = CreatePlayerTextDraw(playerid, 520.000, 251.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, ui_racing[playerid][3], 123.000, 18.000);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][3], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][3], -57);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_racing[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][3], 1);

    ui_racing[playerid][4] = CreatePlayerTextDraw(playerid, 523.000, 218.000, "1#. Rayy bonelo");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][4], 0.170, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][4], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][4], 1);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][4], 1);

    ui_racing[playerid][5] = CreatePlayerTextDraw(playerid, 523.000, 236.000, "2#. Zhure Kontol");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][5], 0.170, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][5], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][5], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][5], 1);

    ui_racing[playerid][6] = CreatePlayerTextDraw(playerid, 523.000, 255.000, "3#. Zeex Kontol");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][6], 0.170, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][6], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][6], 255);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][6], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][6], 1);

    ui_racing[playerid][7] = CreatePlayerTextDraw(playerid, 631.000, 201.000, "1/10");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][7], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][7], 2);
    PlayerTextDrawColor(playerid, ui_racing[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][7], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][7], 1);

    ui_racing[playerid][8] = CreatePlayerTextDraw(playerid, 621.000, 201.000, "0");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][8], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][8], 2);
    PlayerTextDrawColor(playerid, ui_racing[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][8], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][8], 1);

    ui_racing[playerid][9] = CreatePlayerTextDraw(playerid, 621.000, 203.000, "V");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][9], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][9], 2);
    PlayerTextDrawColor(playerid, ui_racing[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][9], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][9], 1);

    ui_racing[playerid][10] = CreatePlayerTextDraw(playerid, 525.000, 201.000, "00:00:00");
    PlayerTextDrawLetterSize(playerid, ui_racing[playerid][10], 0.140, 0.999);
    PlayerTextDrawAlignment(playerid, ui_racing[playerid][10], 1);
    PlayerTextDrawColor(playerid, ui_racing[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ui_racing[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, ui_racing[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_racing[playerid][10], 150);
    PlayerTextDrawFont(playerid, ui_racing[playerid][10], 2);
    PlayerTextDrawSetProportional(playerid, ui_racing[playerid][10], 1);
    return 1;
}