new 
    Text:ProgBarTD[1],
    PlayerText:ProgressBar[MAX_PLAYERS][2];

CreateProgbarTD()
{
    ProgBarTD[0] = TextDrawCreate(217.000, 368.000, "ld_dual:white");
    TextDrawLetterSize(ProgBarTD[0], 0.600, 2.000);
    TextDrawTextSize(ProgBarTD[0], 102.000, 20.000);
    TextDrawAlignment(ProgBarTD[0], 1);
    TextDrawColor(ProgBarTD[0], 102);
    TextDrawUseBox(ProgBarTD[0], 1);
    TextDrawBoxColor(ProgBarTD[0], 50);
    TextDrawSetShadow(ProgBarTD[0], 0);
    TextDrawSetOutline(ProgBarTD[0], 0);
    TextDrawBackgroundColor(ProgBarTD[0], 102);
    TextDrawFont(ProgBarTD[0], 4);
    TextDrawSetProportional(ProgBarTD[0], 1);
}

CreateProgressBarTD(playerid)
{
    ProgressBar[playerid][0] = CreatePlayerTextDraw(playerid, 217.000, 368.000, "ld_dual:white");
    PlayerTextDrawLetterSize(playerid, ProgressBar[playerid][0], 0.600, 2.000);
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], 102.000, 20.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][0], 1);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][0], -12582657);
    PlayerTextDrawUseBox(playerid, ProgressBar[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, ProgressBar[playerid][0], 50);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][0], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][0], 1);

    ProgressBar[playerid][1] = CreatePlayerTextDraw(playerid, 268.000, 371.500, "MEMOTONG PAPAN");
    PlayerTextDrawLetterSize(playerid, ProgressBar[playerid][1], 0.212, 1.399);
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][1], 400.000, 104.000);
    PlayerTextDrawAlignment(playerid, ProgressBar[playerid][1], 2);
    PlayerTextDrawColor(playerid, ProgressBar[playerid][1], -26);
    PlayerTextDrawSetShadow(playerid, ProgressBar[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ProgressBar[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ProgressBar[playerid][1], 255);
    PlayerTextDrawFont(playerid, ProgressBar[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ProgressBar[playerid][1], 1);
}

ShowProgressBar(playerid)
{
    TextDrawShowForPlayer(playerid, ProgBarTD[0]);
    static Float:progressvalue;
    progressvalue = AccountData[playerid][pActivityTime] * 102.0/100;
    PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], progressvalue, 20.0);
    PlayerTextDrawShow(playerid, ProgressBar[playerid][0]);
    PlayerTextDrawShow(playerid, ProgressBar[playerid][1]);
}

HideProgressBar(playerid)
{
    TextDrawHideForPlayer(playerid, ProgBarTD[0]);
    PlayerTextDrawHide(playerid, ProgressBar[playerid][0]);
    PlayerTextDrawHide(playerid, ProgressBar[playerid][1]);
}