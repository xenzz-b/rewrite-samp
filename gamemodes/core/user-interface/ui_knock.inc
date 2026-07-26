new Text:PINGSANTD[20],
    PlayerText:HABISDARAHTD[MAX_PLAYERS][2];

CreateKnockTextdraw()    
{
    PINGSANTD[0] = TextDrawCreate(37.000, 1.000, "_");
    TextDrawLetterSize(PINGSANTD[0], 0.600, 50.250);
    TextDrawTextSize(PINGSANTD[0], 298.500, 1209.500);
    TextDrawAlignment(PINGSANTD[0], 2);
    TextDrawColor(PINGSANTD[0], -1);
    TextDrawUseBox(PINGSANTD[0], 1);
    TextDrawBoxColor(PINGSANTD[0], -16777088);
    TextDrawSetShadow(PINGSANTD[0], 0);
    TextDrawSetOutline(PINGSANTD[0], 1);
    TextDrawBackgroundColor(PINGSANTD[0], 255);
    TextDrawFont(PINGSANTD[0], 0);
    TextDrawSetProportional(PINGSANTD[0], 1);

    PINGSANTD[1] = TextDrawCreate(277.000, 334.000, "You Are");
    TextDrawLetterSize(PINGSANTD[1], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[1], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[1], 1);
    TextDrawColor(PINGSANTD[1], 16777215);
    TextDrawSetShadow(PINGSANTD[1], 0);
    TextDrawSetOutline(PINGSANTD[1], 0);
    TextDrawBackgroundColor(PINGSANTD[1], 255);
    TextDrawFont(PINGSANTD[1], 1);
    TextDrawSetProportional(PINGSANTD[1], 1);

    PINGSANTD[2] = TextDrawCreate(313.000, 333.000, "Incapacitated");
    TextDrawLetterSize(PINGSANTD[2], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[2], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[2], 1);
    TextDrawColor(PINGSANTD[2], 16777215);
    TextDrawSetShadow(PINGSANTD[2], 0);
    TextDrawSetOutline(PINGSANTD[2], 0);
    TextDrawBackgroundColor(PINGSANTD[2], 255);
    TextDrawFont(PINGSANTD[2], 1);
    TextDrawSetProportional(PINGSANTD[2], 1);

    PINGSANTD[3] = TextDrawCreate(285.000, 367.000, "N");
    TextDrawLetterSize(PINGSANTD[3], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[3], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[3], 1);
    TextDrawColor(PINGSANTD[3], -12582657);
    TextDrawSetShadow(PINGSANTD[3], 0);
    TextDrawSetOutline(PINGSANTD[3], 0);
    TextDrawBackgroundColor(PINGSANTD[3], 255);
    TextDrawFont(PINGSANTD[3], 1);
    TextDrawSetProportional(PINGSANTD[3], 1);

    PINGSANTD[4] = TextDrawCreate(277.000, 352.000, "Y");
    TextDrawLetterSize(PINGSANTD[4], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[4], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[4], 1);
    TextDrawColor(PINGSANTD[4], -12582657);
    TextDrawSetShadow(PINGSANTD[4], 0);
    TextDrawSetOutline(PINGSANTD[4], 0);
    TextDrawBackgroundColor(PINGSANTD[4], 255);
    TextDrawFont(PINGSANTD[4], 1);
    TextDrawSetProportional(PINGSANTD[4], 1);

    PINGSANTD[5] = TextDrawCreate(289.000, 352.000, "Untuk spawn di rumah");
    TextDrawLetterSize(PINGSANTD[5], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[5], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[5], 1);
    TextDrawColor(PINGSANTD[5], -1);
    TextDrawSetShadow(PINGSANTD[5], 0);
    TextDrawSetOutline(PINGSANTD[5], 0);
    TextDrawBackgroundColor(PINGSANTD[5], 255);
    TextDrawFont(PINGSANTD[5], 1);
    TextDrawSetProportional(PINGSANTD[5], 1);

    PINGSANTD[6] = TextDrawCreate(386.000, 352.000, "sakit");
    TextDrawLetterSize(PINGSANTD[6], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[6], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[6], 1);
    TextDrawColor(PINGSANTD[6], -1);
    TextDrawSetShadow(PINGSANTD[6], 0);
    TextDrawSetOutline(PINGSANTD[6], 0);
    TextDrawBackgroundColor(PINGSANTD[6], 255);
    TextDrawFont(PINGSANTD[6], 1);
    TextDrawSetProportional(PINGSANTD[6], 1);

    PINGSANTD[7] = TextDrawCreate(258.000, 367.000, "Tekan");
    TextDrawLetterSize(PINGSANTD[7], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[7], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[7], 1);
    TextDrawColor(PINGSANTD[7], -1);
    TextDrawSetShadow(PINGSANTD[7], 0);
    TextDrawSetOutline(PINGSANTD[7], 0);
    TextDrawBackgroundColor(PINGSANTD[7], 255);
    TextDrawFont(PINGSANTD[7], 1);
    TextDrawSetProportional(PINGSANTD[7], 1);

    PINGSANTD[8] = TextDrawCreate(295.000, 367.000, "Mengirim");
    TextDrawLetterSize(PINGSANTD[8], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[8], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[8], 1);
    TextDrawColor(PINGSANTD[8], -1);
    TextDrawSetShadow(PINGSANTD[8], 0);
    TextDrawSetOutline(PINGSANTD[8], 0);
    TextDrawBackgroundColor(PINGSANTD[8], 255);
    TextDrawFont(PINGSANTD[8], 1);
    TextDrawSetProportional(PINGSANTD[8], 1);

    PINGSANTD[9] = TextDrawCreate(338.000, 368.000, "Sinyal Ke EMS");
    TextDrawLetterSize(PINGSANTD[9], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[9], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[9], 1);
    TextDrawColor(PINGSANTD[9], -1);
    TextDrawSetShadow(PINGSANTD[9], 0);
    TextDrawSetOutline(PINGSANTD[9], 0);
    TextDrawBackgroundColor(PINGSANTD[9], 255);
    TextDrawFont(PINGSANTD[9], 1);
    TextDrawSetProportional(PINGSANTD[9], 1);

    PINGSANTD[10] = TextDrawCreate(265.000, 395.000, "Saat Ini Ada");
    TextDrawLetterSize(PINGSANTD[10], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[10], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[10], 1);
    TextDrawColor(PINGSANTD[10], -1);
    TextDrawSetShadow(PINGSANTD[10], 0);
    TextDrawSetOutline(PINGSANTD[10], 0);
    TextDrawBackgroundColor(PINGSANTD[10], 255);
    TextDrawFont(PINGSANTD[10], 1);
    TextDrawSetProportional(PINGSANTD[10], 1);

    PINGSANTD[11] = TextDrawCreate(321.000, 396.000, "6");
    TextDrawLetterSize(PINGSANTD[11], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[11], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[11], 1);
    TextDrawColor(PINGSANTD[11], -12582657);
    TextDrawSetShadow(PINGSANTD[11], 0);
    TextDrawSetOutline(PINGSANTD[11], 0);
    TextDrawBackgroundColor(PINGSANTD[11], 255);
    TextDrawFont(PINGSANTD[11], 1);
    TextDrawSetProportional(PINGSANTD[11], 1);

    PINGSANTD[12] = TextDrawCreate(330.000, 396.000, "EMS di kota");
    TextDrawLetterSize(PINGSANTD[12], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[12], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[12], 1);
    TextDrawColor(PINGSANTD[12], -1);
    TextDrawSetShadow(PINGSANTD[12], 0);
    TextDrawSetOutline(PINGSANTD[12], 0);
    TextDrawBackgroundColor(PINGSANTD[12], 255);
    TextDrawFont(PINGSANTD[12], 1);
    TextDrawSetProportional(PINGSANTD[12], 1);

    PINGSANTD[13] = TextDrawCreate(304.000, 416.000, "ld_dual:white");
    TextDrawLetterSize(PINGSANTD[13], 0.600, 2.000);
    TextDrawTextSize(PINGSANTD[13], 17.000, 17.000);
    TextDrawAlignment(PINGSANTD[13], 1);
    TextDrawColor(PINGSANTD[13], -1);
    TextDrawUseBox(PINGSANTD[13], 1);
    TextDrawBoxColor(PINGSANTD[13], 50);
    TextDrawSetShadow(PINGSANTD[13], 0);
    TextDrawSetOutline(PINGSANTD[13], 1);
    TextDrawBackgroundColor(PINGSANTD[13], 255);
    TextDrawFont(PINGSANTD[13], 4);
    TextDrawSetProportional(PINGSANTD[13], 1);

    PINGSANTD[14] = TextDrawCreate(324.000, 416.000, ":");
    TextDrawLetterSize(PINGSANTD[14], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[14], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[14], 1);
    TextDrawColor(PINGSANTD[14], -1);
    TextDrawSetShadow(PINGSANTD[14], 0);
    TextDrawSetOutline(PINGSANTD[14], 0);
    TextDrawBackgroundColor(PINGSANTD[14], 255);
    TextDrawFont(PINGSANTD[14], 1);
    TextDrawSetProportional(PINGSANTD[14], 1);

    PINGSANTD[15] = TextDrawCreate(330.000, 416.000, "ld_dual:white");
    TextDrawLetterSize(PINGSANTD[15], 0.600, 2.000);
    TextDrawTextSize(PINGSANTD[15], 17.000, 17.000);
    TextDrawAlignment(PINGSANTD[15], 1);
    TextDrawColor(PINGSANTD[15], -1);
    TextDrawUseBox(PINGSANTD[15], 1);
    TextDrawBoxColor(PINGSANTD[15], 50);
    TextDrawSetShadow(PINGSANTD[15], 0);
    TextDrawSetOutline(PINGSANTD[15], 1);
    TextDrawBackgroundColor(PINGSANTD[15], 255);
    TextDrawFont(PINGSANTD[15], 4);
    TextDrawSetProportional(PINGSANTD[15], 1);

    PINGSANTD[16] = TextDrawCreate(248.000, 352.000, "Tekan");
    TextDrawLetterSize(PINGSANTD[16], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[16], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[16], 1);
    TextDrawColor(PINGSANTD[16], -1);
    TextDrawSetShadow(PINGSANTD[16], 0);
    TextDrawSetOutline(PINGSANTD[16], 0);
    TextDrawBackgroundColor(PINGSANTD[16], 255);
    TextDrawFont(PINGSANTD[16], 1);
    TextDrawSetProportional(PINGSANTD[16], 1);

    PINGSANTD[17] = TextDrawCreate(265.000, 382.000, "Tekan");
    TextDrawLetterSize(PINGSANTD[17], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[17], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[17], 1);
    TextDrawColor(PINGSANTD[17], -1);
    TextDrawSetShadow(PINGSANTD[17], 0);
    TextDrawSetOutline(PINGSANTD[17], 0);
    TextDrawBackgroundColor(PINGSANTD[17], 255);
    TextDrawFont(PINGSANTD[17], 1);
    TextDrawSetProportional(PINGSANTD[17], 1);

    PINGSANTD[18] = TextDrawCreate(295.000, 382.000, "H");
    TextDrawLetterSize(PINGSANTD[18], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[18], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[18], 1);
    TextDrawColor(PINGSANTD[18], -12582657);
    TextDrawSetShadow(PINGSANTD[18], 0);
    TextDrawSetOutline(PINGSANTD[18], 0);
    TextDrawBackgroundColor(PINGSANTD[18], 255);
    TextDrawFont(PINGSANTD[18], 1);
    TextDrawSetProportional(PINGSANTD[18], 1);

    PINGSANTD[19] = TextDrawCreate(307.000, 382.000, "Jika tidak terlihat");
    TextDrawLetterSize(PINGSANTD[19], 0.261, 1.649);
    TextDrawTextSize(PINGSANTD[19], 400.000, 17.000);
    TextDrawAlignment(PINGSANTD[19], 1);
    TextDrawColor(PINGSANTD[19], -1);
    TextDrawSetShadow(PINGSANTD[19], 0);
    TextDrawSetOutline(PINGSANTD[19], 0);
    TextDrawBackgroundColor(PINGSANTD[19], 255);
    TextDrawFont(PINGSANTD[19], 1);
    TextDrawSetProportional(PINGSANTD[19], 1);
}

CreateKnockPlayerTD(playerid)
{
    HABISDARAHTD[playerid][0] = CreatePlayerTextDraw(playerid, 309.000, 416.000, "5");
    PlayerTextDrawLetterSize(playerid, HABISDARAHTD[playerid][0], 0.261, 1.649);
    PlayerTextDrawTextSize(playerid, HABISDARAHTD[playerid][0], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HABISDARAHTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, HABISDARAHTD[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, HABISDARAHTD[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, HABISDARAHTD[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, HABISDARAHTD[playerid][0], 255);
    PlayerTextDrawFont(playerid, HABISDARAHTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, HABISDARAHTD[playerid][0], 1);

    HABISDARAHTD[playerid][1] = CreatePlayerTextDraw(playerid, 335.000, 416.000, "9");
    PlayerTextDrawLetterSize(playerid, HABISDARAHTD[playerid][1], 0.261, 1.649);
    PlayerTextDrawTextSize(playerid, HABISDARAHTD[playerid][1], 400.000, 17.000);
    PlayerTextDrawAlignment(playerid, HABISDARAHTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, HABISDARAHTD[playerid][1], 255);
    PlayerTextDrawSetShadow(playerid, HABISDARAHTD[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, HABISDARAHTD[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, HABISDARAHTD[playerid][1], 255);
    PlayerTextDrawFont(playerid, HABISDARAHTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, HABISDARAHTD[playerid][1], 1);
}

ShowKnockTD(playerid)
{
    for(new x; x < 20; x++)
    {
        TextDrawShowForPlayer(playerid, PINGSANTD[x]);
    }
    PlayerTextDrawShow(playerid, HABISDARAHTD[playerid][0]);
    PlayerTextDrawShow(playerid, HABISDARAHTD[playerid][1]);
    HideHBETD(playerid);
	HideRadioVoiceInfoTD(playerid);
}

HideKnockTD(playerid)
{
    for(new x; x < 20; x++)
    {
        TextDrawHideForPlayer(playerid, PINGSANTD[x]);
    }
    PlayerTextDrawHide(playerid, HABISDARAHTD[playerid][0]);
    PlayerTextDrawHide(playerid, HABISDARAHTD[playerid][1]);
    ShowHBETD(playerid);
	ShowRadioVoiceInfoTD(playerid);
}