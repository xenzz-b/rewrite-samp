new Text: NrpUI[11],
	Text:ServerClockTD[2];

CreateServerNameTD()
{	
	NrpUI[0] = TextDrawCreate(297.000, 10.000, "LD_SPAC:white");
    TextDrawTextSize(NrpUI[0], 1.500, 16.000);
    TextDrawAlignment(NrpUI[0], 1);
    TextDrawColor(NrpUI[0], -12254977);
    TextDrawSetShadow(NrpUI[0], 0);
    TextDrawSetOutline(NrpUI[0], 0);
    TextDrawBackgroundColor(NrpUI[0], 255);
    TextDrawFont(NrpUI[0], 4);
    TextDrawSetProportional(NrpUI[0], 1);

    NrpUI[1] = TextDrawCreate(310.000, 4.000, "/");
    TextDrawLetterSize(NrpUI[1], -0.898, 2.598);
    TextDrawAlignment(NrpUI[1], 1);
    TextDrawColor(NrpUI[1], -12254977);
    TextDrawSetShadow(NrpUI[1], 0);
    TextDrawSetOutline(NrpUI[1], 0);
    TextDrawBackgroundColor(NrpUI[1], 150);
    TextDrawFont(NrpUI[1], 2);
    TextDrawSetProportional(NrpUI[1], 1);

    NrpUI[2] = TextDrawCreate(305.000, 14.000, "/");
    TextDrawLetterSize(NrpUI[2], 0.479, 1.299);
    TextDrawAlignment(NrpUI[2], 1);
    TextDrawColor(NrpUI[2], -12254977);
    TextDrawSetShadow(NrpUI[2], 0);
    TextDrawSetOutline(NrpUI[2], 0);
    TextDrawBackgroundColor(NrpUI[2], 150);
    TextDrawFont(NrpUI[2], 2);
    TextDrawSetProportional(NrpUI[2], 1);

    NrpUI[3] = TextDrawCreate(306.000, 14.000, "/");
    TextDrawLetterSize(NrpUI[3], 0.479, 1.299);
    TextDrawAlignment(NrpUI[3], 1);
    TextDrawColor(NrpUI[3], -12254977);
    TextDrawSetShadow(NrpUI[3], 0);
    TextDrawSetOutline(NrpUI[3], 0);
    TextDrawBackgroundColor(NrpUI[3], 150);
    TextDrawFont(NrpUI[3], 2);
    TextDrawSetProportional(NrpUI[3], 1);

    NrpUI[4] = TextDrawCreate(314.000, 4.000, "/");
    TextDrawLetterSize(NrpUI[4], -0.680, 1.699);
    TextDrawAlignment(NrpUI[4], 1);
    TextDrawColor(NrpUI[4], -12254977);
    TextDrawSetShadow(NrpUI[4], 0);
    TextDrawSetOutline(NrpUI[4], 0);
    TextDrawBackgroundColor(NrpUI[4], 150);
    TextDrawFont(NrpUI[4], 2);
    TextDrawSetProportional(NrpUI[4], 1);

    NrpUI[5] = TextDrawCreate(312.000, 6.000, "/");
    TextDrawLetterSize(NrpUI[5], 0.419, 1.098);
    TextDrawAlignment(NrpUI[5], 1);
    TextDrawColor(NrpUI[5], -1);
    TextDrawSetShadow(NrpUI[5], 0);
    TextDrawSetOutline(NrpUI[5], 0);
    TextDrawBackgroundColor(NrpUI[5], 150);
    TextDrawFont(NrpUI[5], 2);
    TextDrawSetProportional(NrpUI[5], 1);

    NrpUI[6] = TextDrawCreate(320.000, 16.000, "/");
    TextDrawLetterSize(NrpUI[6], -0.458, 1.098);
    TextDrawAlignment(NrpUI[6], 1);
    TextDrawColor(NrpUI[6], -1);
    TextDrawSetShadow(NrpUI[6], 0);
    TextDrawSetOutline(NrpUI[6], 0);
    TextDrawBackgroundColor(NrpUI[6], 150);
    TextDrawFont(NrpUI[6], 2);
    TextDrawSetProportional(NrpUI[6], 1);

    NrpUI[7] = TextDrawCreate(306.000, 27.000, "LD_SPAC:white");
    TextDrawTextSize(NrpUI[7], 15.500, 1.000);
    TextDrawAlignment(NrpUI[7], 1);
    TextDrawColor(NrpUI[7], -12254977);
    TextDrawSetShadow(NrpUI[7], 0);
    TextDrawSetOutline(NrpUI[7], 0);
    TextDrawBackgroundColor(NrpUI[7], 255);
    TextDrawFont(NrpUI[7], 4);
    TextDrawSetProportional(NrpUI[7], 1);

    NrpUI[8] = TextDrawCreate(296.000, 27.000, "VERTEX");
    TextDrawLetterSize(NrpUI[8], 0.189, 0.898);
    TextDrawAlignment(NrpUI[8], 1);
    TextDrawColor(NrpUI[8], -1);
    TextDrawSetShadow(NrpUI[8], 0);
    TextDrawSetOutline(NrpUI[8], 0);
    TextDrawBackgroundColor(NrpUI[8], 150);
    TextDrawFont(NrpUI[8], 1);
    TextDrawSetProportional(NrpUI[8], 1);

    NrpUI[9] = TextDrawCreate(294.000, 36.000, "LD_SPAC:white");
    TextDrawTextSize(NrpUI[9], 10.000, 0.500);
    TextDrawAlignment(NrpUI[9], 1);
    TextDrawColor(NrpUI[9], -12254977);
    TextDrawSetShadow(NrpUI[9], 0);
    TextDrawSetOutline(NrpUI[9], 0);
    TextDrawBackgroundColor(NrpUI[9], 255);
    TextDrawFont(NrpUI[9], 4);
    TextDrawSetProportional(NrpUI[9], 1);

    NrpUI[10] = TextDrawCreate(305.000, 34.000, "ROLEPLAY");
    TextDrawLetterSize(NrpUI[10], 0.119, 0.699);
    TextDrawAlignment(NrpUI[10], 1);
    TextDrawColor(NrpUI[10], -1);
    TextDrawSetShadow(NrpUI[10], 0);
    TextDrawSetOutline(NrpUI[10], 0);
    TextDrawBackgroundColor(NrpUI[10], 150);
    TextDrawFont(NrpUI[10], 1);
    TextDrawSetProportional(NrpUI[10], 1);

	ServerClockTD[0] = TextDrawCreate(577.000000, 8.000000, "30 Desember 2025");
	TextDrawFont(ServerClockTD[0], 1);
	TextDrawLetterSize(ServerClockTD[0], 0.266665, 1.299998);
	TextDrawTextSize(ServerClockTD[0], 400.000000, 102.000000);
	TextDrawSetOutline(ServerClockTD[0], 1);
	TextDrawSetShadow(ServerClockTD[0], 0);
	TextDrawAlignment(ServerClockTD[0], 2);
	TextDrawColor(ServerClockTD[0], -1);
	TextDrawBackgroundColor(ServerClockTD[0], 255);
	TextDrawBoxColor(ServerClockTD[0], 50);
	TextDrawUseBox(ServerClockTD[0], 0);
	TextDrawSetProportional(ServerClockTD[0], 1);
	TextDrawSetSelectable(ServerClockTD[0], 0);

	ServerClockTD[1] = TextDrawCreate(579.000000, 20.000000, "23:59:54");
	TextDrawFont(ServerClockTD[1], 1);
	TextDrawLetterSize(ServerClockTD[1], 0.354166, 1.799998);
	TextDrawTextSize(ServerClockTD[1], 400.000000, 72.000000);
	TextDrawSetOutline(ServerClockTD[1], 1);
	TextDrawSetShadow(ServerClockTD[1], 0);
	TextDrawAlignment(ServerClockTD[1], 2);
	TextDrawColor(ServerClockTD[1], -1);
	TextDrawBackgroundColor(ServerClockTD[1], 255);
	TextDrawBoxColor(ServerClockTD[1], 50);
	TextDrawUseBox(ServerClockTD[1], 0);
	TextDrawSetProportional(ServerClockTD[1], 1);
	TextDrawSetSelectable(ServerClockTD[1], 0);
}

ShowServerNameTD(playerid)
{
	for(new x; x < 11; x++)
    {
    	TextDrawShowForPlayer(playerid, NrpUI[x]);
	}
}

HideServerNameTD(playerid)
{
    for(new x; x < 11; x++)
    {
        TextDrawHideForPlayer(playerid, NrpUI[x]);
    }
}

ShowClockTD(playerid)
{
	TextDrawShowForPlayer(playerid, ServerClockTD[0]);
	TextDrawShowForPlayer(playerid, ServerClockTD[1]);
}