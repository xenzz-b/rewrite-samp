new Text:WARGABARU[9];
new PlayerText:PWARGABARU[MAX_PLAYERS];

CreateWargaBaruTD()
{
    WARGABARU[0] = TextDrawCreate(401.000, 413.000, "LD_BEAT:chit");
    TextDrawTextSize(WARGABARU[0], 12.000, 13.000);
    TextDrawAlignment(WARGABARU[0], 1);
    TextDrawColor(WARGABARU[0], -12582657);
    TextDrawSetShadow(WARGABARU[0], 0);
    TextDrawSetOutline(WARGABARU[0], 0);
    TextDrawBackgroundColor(WARGABARU[0], 255);
    TextDrawFont(WARGABARU[0], 4);
    TextDrawSetProportional(WARGABARU[0], 1);

    WARGABARU[1] = TextDrawCreate(582.000, 413.000, "LD_BEAT:chit");
    TextDrawTextSize(WARGABARU[1], 12.000, 13.000);
    TextDrawAlignment(WARGABARU[1], 1);
    TextDrawColor(WARGABARU[1], -12582657);
    TextDrawSetShadow(WARGABARU[1], 0);
    TextDrawSetOutline(WARGABARU[1], 0);
    TextDrawBackgroundColor(WARGABARU[1], 255);
    TextDrawFont(WARGABARU[1], 4);
    TextDrawSetProportional(WARGABARU[1], 1);

    WARGABARU[2] = TextDrawCreate(407.000, 415.000, "LD_SPAC:white");
    TextDrawTextSize(WARGABARU[2], 181.000, 33.000);
    TextDrawAlignment(WARGABARU[2], 1);
    TextDrawColor(WARGABARU[2], -12582657);
    TextDrawSetShadow(WARGABARU[2], 0);
    TextDrawSetOutline(WARGABARU[2], 0);
    TextDrawBackgroundColor(WARGABARU[2], 255);
    TextDrawFont(WARGABARU[2], 4);
    TextDrawSetProportional(WARGABARU[2], 1);

    WARGABARU[3] = TextDrawCreate(403.000, 420.000, "LD_SPAC:white");
    TextDrawTextSize(WARGABARU[3], 4.000, 28.000);
    TextDrawAlignment(WARGABARU[3], 1);
    TextDrawColor(WARGABARU[3], -12582657);
    TextDrawSetShadow(WARGABARU[3], 0);
    TextDrawSetOutline(WARGABARU[3], 0);
    TextDrawBackgroundColor(WARGABARU[3], 255);
    TextDrawFont(WARGABARU[3], 4);
    TextDrawSetProportional(WARGABARU[3], 1);

    WARGABARU[4] = TextDrawCreate(588.000, 420.000, "LD_SPAC:white");
    TextDrawTextSize(WARGABARU[4], 4.000, 28.000);
    TextDrawAlignment(WARGABARU[4], 1);
    TextDrawColor(WARGABARU[4], -12582657);
    TextDrawSetShadow(WARGABARU[4], 0);
    TextDrawSetOutline(WARGABARU[4], 0);
    TextDrawBackgroundColor(WARGABARU[4], 255);
    TextDrawFont(WARGABARU[4], 4);
    TextDrawSetProportional(WARGABARU[4], 1);

    WARGABARU[5] = TextDrawCreate(407.000, 416.000, "Warga baru Vertex");
    TextDrawLetterSize(WARGABARU[5], 0.209, 1.098);
    TextDrawAlignment(WARGABARU[5], 1);
    TextDrawColor(WARGABARU[5], -1);
    TextDrawSetShadow(WARGABARU[5], 0);
    TextDrawSetOutline(WARGABARU[5], 0);
    TextDrawBackgroundColor(WARGABARU[5], 150);
    TextDrawFont(WARGABARU[5], 1);
    TextDrawSetProportional(WARGABARU[5], 1);

    WARGABARU[6] = TextDrawCreate(408.000, 426.000, "Bermainlah dengan bijak");
    TextDrawLetterSize(WARGABARU[6], 0.140, 1.098);
    TextDrawAlignment(WARGABARU[6], 1);
    TextDrawColor(WARGABARU[6], -1);
    TextDrawSetShadow(WARGABARU[6], 0);
    TextDrawSetOutline(WARGABARU[6], 0);
    TextDrawBackgroundColor(WARGABARU[6], 150);
    TextDrawFont(WARGABARU[6], 1);
    TextDrawSetProportional(WARGABARU[6], 1);

    WARGABARU[7] = TextDrawCreate(408.000, 435.000, "Anda tidak dapat memukul dan menembak sampai waktu yang ditentukan..");
    TextDrawLetterSize(WARGABARU[7], 0.119, 1.199);
    TextDrawAlignment(WARGABARU[7], 1);
    TextDrawColor(WARGABARU[7], -1);
    TextDrawSetShadow(WARGABARU[7], 0);
    TextDrawSetOutline(WARGABARU[7], 0);
    TextDrawBackgroundColor(WARGABARU[7], 150);
    TextDrawFont(WARGABARU[7], 1);
    TextDrawSetProportional(WARGABARU[7], 1);

    WARGABARU[8] = TextDrawCreate(575.000, 427.000, "Min");
    TextDrawLetterSize(WARGABARU[8], 0.250, 0.998);
    TextDrawAlignment(WARGABARU[8], 1);
    TextDrawColor(WARGABARU[8], -1);
    TextDrawSetShadow(WARGABARU[8], 0);
    TextDrawSetOutline(WARGABARU[8], 0);
    TextDrawBackgroundColor(WARGABARU[8], 150);
    TextDrawFont(WARGABARU[8], 1);
    TextDrawSetProportional(WARGABARU[8], 1);

}

CreatePWargaBaruTD(playerid)
{
    PWARGABARU[playerid] = CreatePlayerTextDraw(playerid, 567.000, 423.000, "180");
    PlayerTextDrawLetterSize(playerid, PWARGABARU[playerid], 0.300, 1.500);
    PlayerTextDrawAlignment(playerid, PWARGABARU[playerid], 2);
    PlayerTextDrawColor(playerid, PWARGABARU[playerid], -1);
    PlayerTextDrawSetShadow(playerid, PWARGABARU[playerid], 0);
    PlayerTextDrawSetOutline(playerid, PWARGABARU[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, PWARGABARU[playerid], 150);
    PlayerTextDrawFont(playerid, PWARGABARU[playerid], 1);
    PlayerTextDrawSetProportional(playerid, PWARGABARU[playerid], 1);
}

ShowWargaBaruTD(playerid)
{
    for(new x; x < 9; x++)
    {
        TextDrawShowForPlayer(playerid, WARGABARU[x]);
    }
    PlayerTextDrawShow(playerid, PWARGABARU[playerid]);
}

HideWargaBaruTD(playerid)
{
    for(new x; x < 9; x++)
    {
        TextDrawHideForPlayer(playerid, WARGABARU[x]);
    }
    PlayerTextDrawHide(playerid, PWARGABARU[playerid]);
}