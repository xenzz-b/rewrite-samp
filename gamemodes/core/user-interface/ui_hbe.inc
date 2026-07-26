new Text:HBE[20],
    PlayerText:PHBE[MAX_PLAYERS][10],
    Text:StressTD;

new PlayerText: SpeedoNSRP[MAX_PLAYERS][42];

CreateHBETextdraw()
{
	//V1
	HBE[0] = TextDrawCreate(5.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[0], 1.000, 14.000);
	TextDrawAlignment(HBE[0], 1);
	TextDrawColor(HBE[0], -12582657);
	TextDrawSetShadow(HBE[0], 0);
	TextDrawSetOutline(HBE[0], 0);
	TextDrawBackgroundColor(HBE[0], 255);
	TextDrawFont(HBE[0], 4);
	TextDrawSetProportional(HBE[0], 1);

	HBE[1] = TextDrawCreate(5.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[1], 35.000, 1.000);
	TextDrawAlignment(HBE[1], 1);
	TextDrawColor(HBE[1], -12582657);
	TextDrawSetShadow(HBE[1], 0);
	TextDrawSetOutline(HBE[1], 0);
	TextDrawBackgroundColor(HBE[1], 255);
	TextDrawFont(HBE[1], 4);
	TextDrawSetProportional(HBE[1], 1);

	HBE[2] = TextDrawCreate(5.000, 445.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[2], 35.000, 1.000);
	TextDrawAlignment(HBE[2], 1);
	TextDrawColor(HBE[2], -12582657);
	TextDrawSetShadow(HBE[2], 0);
	TextDrawSetOutline(HBE[2], 0);
	TextDrawBackgroundColor(HBE[2], 255);
	TextDrawFont(HBE[2], 4);
	TextDrawSetProportional(HBE[2], 1);

	HBE[3] = TextDrawCreate(39.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[3], 1.000, 14.000);
	TextDrawAlignment(HBE[3], 1);
	TextDrawColor(HBE[3], -12582657);
	TextDrawSetShadow(HBE[3], 0);
	TextDrawSetOutline(HBE[3], 0);
	TextDrawBackgroundColor(HBE[3], 255);
	TextDrawFont(HBE[3], 4);
	TextDrawSetProportional(HBE[3], 1);

	HBE[4] = TextDrawCreate(41.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[4], 1.000, 14.000);
	TextDrawAlignment(HBE[4], 1);
	TextDrawColor(HBE[4], -12582657);
	TextDrawSetShadow(HBE[4], 0);
	TextDrawSetOutline(HBE[4], 0);
	TextDrawBackgroundColor(HBE[4], 255);
	TextDrawFont(HBE[4], 4);
	TextDrawSetProportional(HBE[4], 1);

	HBE[5] = TextDrawCreate(41.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[5], 35.000, 1.000);
	TextDrawAlignment(HBE[5], 1);
	TextDrawColor(HBE[5], -12582657);
	TextDrawSetShadow(HBE[5], 0);
	TextDrawSetOutline(HBE[5], 0);
	TextDrawBackgroundColor(HBE[5], 255);
	TextDrawFont(HBE[5], 4);
	TextDrawSetProportional(HBE[5], 1);

	HBE[6] = TextDrawCreate(41.000, 445.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[6], 35.000, 1.000);
	TextDrawAlignment(HBE[6], 1);
	TextDrawColor(HBE[6], -12582657);
	TextDrawSetShadow(HBE[6], 0);
	TextDrawSetOutline(HBE[6], 0);
	TextDrawBackgroundColor(HBE[6], 255);
	TextDrawFont(HBE[6], 4);
	TextDrawSetProportional(HBE[6], 1);

	HBE[7] = TextDrawCreate(75.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[7], 1.000, 14.000);
	TextDrawAlignment(HBE[7], 1);
	TextDrawColor(HBE[7], -12582657);
	TextDrawSetShadow(HBE[7], 0);
	TextDrawSetOutline(HBE[7], 0);
	TextDrawBackgroundColor(HBE[7], 255);
	TextDrawFont(HBE[7], 4);
	TextDrawSetProportional(HBE[7], 1);

	HBE[8] = TextDrawCreate(77.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[8], 1.000, 14.000);
	TextDrawAlignment(HBE[8], 1);
	TextDrawColor(HBE[8], -12582657);
	TextDrawSetShadow(HBE[8], 0);
	TextDrawSetOutline(HBE[8], 0);
	TextDrawBackgroundColor(HBE[8], 255);
	TextDrawFont(HBE[8], 4);
	TextDrawSetProportional(HBE[8], 1);

	HBE[9] = TextDrawCreate(77.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[9], 15.000, 1.000);
	TextDrawAlignment(HBE[9], 1);
	TextDrawColor(HBE[9], -12582657);
	TextDrawSetShadow(HBE[9], 0);
	TextDrawSetOutline(HBE[9], 0);
	TextDrawBackgroundColor(HBE[9], 255);
	TextDrawFont(HBE[9], 4);
	TextDrawSetProportional(HBE[9], 1);

	HBE[10] = TextDrawCreate(77.000, 445.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[10], 15.000, 1.000);
	TextDrawAlignment(HBE[10], 1);
	TextDrawColor(HBE[10], -12582657);
	TextDrawSetShadow(HBE[10], 0);
	TextDrawSetOutline(HBE[10], 0);
	TextDrawBackgroundColor(HBE[10], 255);
	TextDrawFont(HBE[10], 4);
	TextDrawSetProportional(HBE[10], 1);

	HBE[11] = TextDrawCreate(91.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[11], 1.000, 14.000);
	TextDrawAlignment(HBE[11], 1);
	TextDrawColor(HBE[11], -12582657);
	TextDrawSetShadow(HBE[11], 0);
	TextDrawSetOutline(HBE[11], 0);
	TextDrawBackgroundColor(HBE[11], 255);
	TextDrawFont(HBE[11], 4);
	TextDrawSetProportional(HBE[11], 1);

	HBE[12] = TextDrawCreate(93.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[12], 1.000, 14.000);
	TextDrawAlignment(HBE[12], 1);
	TextDrawColor(HBE[12], -12582657);
	TextDrawSetShadow(HBE[12], 0);
	TextDrawSetOutline(HBE[12], 0);
	TextDrawBackgroundColor(HBE[12], 255);
	TextDrawFont(HBE[12], 4);
	TextDrawSetProportional(HBE[12], 1);

	HBE[13] = TextDrawCreate(93.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[13], 15.000, 1.000);
	TextDrawAlignment(HBE[13], 1);
	TextDrawColor(HBE[13], -12582657);
	TextDrawSetShadow(HBE[13], 0);
	TextDrawSetOutline(HBE[13], 0);
	TextDrawBackgroundColor(HBE[13], 255);
	TextDrawFont(HBE[13], 4);
	TextDrawSetProportional(HBE[13], 1);

	HBE[14] = TextDrawCreate(93.000, 445.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[14], 15.000, 1.000);
	TextDrawAlignment(HBE[14], 1);
	TextDrawColor(HBE[14], -12582657);
	TextDrawSetShadow(HBE[14], 0);
	TextDrawSetOutline(HBE[14], 0);
	TextDrawBackgroundColor(HBE[14], 255);
	TextDrawFont(HBE[14], 4);
	TextDrawSetProportional(HBE[14], 1);

	HBE[15] = TextDrawCreate(107.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[15], 1.000, 14.000);
	TextDrawAlignment(HBE[15], 1);
	TextDrawColor(HBE[15], -12582657);
	TextDrawSetShadow(HBE[15], 0);
	TextDrawSetOutline(HBE[15], 0);
	TextDrawBackgroundColor(HBE[15], 255);
	TextDrawFont(HBE[15], 4);
	TextDrawSetProportional(HBE[15], 1);

	HBE[16] = TextDrawCreate(109.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[16], 1.000, 14.000);
	TextDrawAlignment(HBE[16], 1);
	TextDrawColor(HBE[16], -12582657);
	TextDrawSetShadow(HBE[16], 0);
	TextDrawSetOutline(HBE[16], 0);
	TextDrawBackgroundColor(HBE[16], 255);
	TextDrawFont(HBE[16], 4);
	TextDrawSetProportional(HBE[16], 1);

	HBE[17] = TextDrawCreate(109.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[17], 15.000, 1.000);
	TextDrawAlignment(HBE[17], 1);
	TextDrawColor(HBE[17], -12582657);
	TextDrawSetShadow(HBE[17], 0);
	TextDrawSetOutline(HBE[17], 0);
	TextDrawBackgroundColor(HBE[17], 255);
	TextDrawFont(HBE[17], 4);
	TextDrawSetProportional(HBE[17], 1);

	HBE[18] = TextDrawCreate(109.000, 445.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[18], 15.000, 1.000);
	TextDrawAlignment(HBE[18], 1);
	TextDrawColor(HBE[18], -12582657);
	TextDrawSetShadow(HBE[18], 0);
	TextDrawSetOutline(HBE[18], 0);
	TextDrawBackgroundColor(HBE[18], 255);
	TextDrawFont(HBE[18], 4);
	TextDrawSetProportional(HBE[18], 1);

	HBE[19] = TextDrawCreate(123.000, 431.000, "LD_SPAC:white");
	TextDrawTextSize(HBE[19], 1.000, 14.000);
	TextDrawAlignment(HBE[19], 1);
	TextDrawColor(HBE[19], -12582657);
	TextDrawSetShadow(HBE[19], 0);
	TextDrawSetOutline(HBE[19], 0);
	TextDrawBackgroundColor(HBE[19], 255);
	TextDrawFont(HBE[19], 4);
	TextDrawSetProportional(HBE[19], 1);
}

CreateHBEProgressBarTD(playerid)
{
	//v1
	PHBE[playerid][0] = CreatePlayerTextDraw(playerid, 6.000, 432.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][0], 33.000, 13.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][0], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][0], -16776961);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][0], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][0], 1);

	PHBE[playerid][1] = CreatePlayerTextDraw(playerid, 42.000, 432.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][1], 33.000, 13.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][1], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][1], 16777215);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][1], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][1], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][1], 1);

	PHBE[playerid][2] = CreatePlayerTextDraw(playerid, 78.000, 445.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][2], 13.000, -13.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][2], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][2], -626712321);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][2], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][2], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][2], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][2], 1);

	PHBE[playerid][3] = CreatePlayerTextDraw(playerid, 94.000, 445.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][3], 13.000, -13.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][3], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][3], 1097458175);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][3], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][3], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][3], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][3], 1);

	PHBE[playerid][4] = CreatePlayerTextDraw(playerid, 110.000, 445.000, "LD_SPAC:white");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][4], 13.000, -13.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][4], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][4], -1962898433);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][4], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][4], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][4], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][4], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][4], 1);

	PHBE[playerid][5] = CreatePlayerTextDraw(playerid, 10.000, 435.000, "HUD:radar_girlfriend");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][5], 6.000, 6.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][5], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][5], -1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][5], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][5], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][5], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][5], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][5], 1);

	PHBE[playerid][6] = CreatePlayerTextDraw(playerid, 45.000, 435.000, "HUD:radar_tshirt");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][6], 6.000, 6.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][6], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][6], -1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][6], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][6], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][6], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][6], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][6], 1);

	PHBE[playerid][7] = CreatePlayerTextDraw(playerid, 81.000, 435.000, "HUD:radar_burgerShot");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][7], 6.000, 6.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][7], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][7], -1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][7], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][7], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][7], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][7], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][7], 1);

	PHBE[playerid][8] = CreatePlayerTextDraw(playerid, 97.000, 435.000, "HUD:radar_diner");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][8], 6.000, 6.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][8], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][8], -1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][8], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][8], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][8], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][8], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][8], 1);

	PHBE[playerid][9] = CreatePlayerTextDraw(playerid, 113.000, 435.000, "HUD:radar_waypoint");
	PlayerTextDrawTextSize(playerid, PHBE[playerid][9], 6.000, 6.000);
	PlayerTextDrawAlignment(playerid, PHBE[playerid][9], 1);
	PlayerTextDrawColor(playerid, PHBE[playerid][9], -1);
	PlayerTextDrawSetShadow(playerid, PHBE[playerid][9], 0);
	PlayerTextDrawSetOutline(playerid, PHBE[playerid][9], 0);
	PlayerTextDrawBackgroundColor(playerid, PHBE[playerid][9], 255);
	PlayerTextDrawFont(playerid, PHBE[playerid][9], 4);
	PlayerTextDrawSetProportional(playerid, PHBE[playerid][9], 1);

}

CreateStressTD()
{
    StressTD = TextDrawCreate(322.000000, -1.000000, "_");
    TextDrawFont(StressTD, true);
    TextDrawLetterSize(StressTD, 0.600000, 56.800003);
    TextDrawTextSize(StressTD, 298.500000, 675.000000);
    TextDrawSetOutline(StressTD, true);
    TextDrawSetShadow(StressTD, false);
    TextDrawAlignment(StressTD, 2);
    TextDrawColor(StressTD, -1);
    TextDrawBackgroundColor(StressTD,  155);
    TextDrawBoxColor(StressTD, 35634);
    TextDrawUseBox(StressTD, true);
    TextDrawSetProportional(StressTD, true);
    TextDrawSetSelectable(StressTD, false);
}

CreatePlayerSpeedoTD(playerid)
{
    SpeedoNSRP[playerid][0] = CreatePlayerTextDraw(playerid, 213.000, 348.000, "H");
    PlayerTextDrawLetterSize(playerid, SpeedoNSRP[playerid][0], 0.167, 1.098);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][0], 150);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][0], 1);

    SpeedoNSRP[playerid][1] = CreatePlayerTextDraw(playerid, 150.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][1], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][1], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][1], -12582657);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][1], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][1], 1);

    SpeedoNSRP[playerid][2] = CreatePlayerTextDraw(playerid, 152.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][2], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][2], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][2], -12582657);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][2], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][2], 1);

    SpeedoNSRP[playerid][3] = CreatePlayerTextDraw(playerid, 154.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][3], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][3], -12910337);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][3], 1);

    SpeedoNSRP[playerid][4] = CreatePlayerTextDraw(playerid, 156.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][4], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][4], -13696769);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][4], 1);

    SpeedoNSRP[playerid][5] = CreatePlayerTextDraw(playerid, 158.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][5], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][5], -13696769);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][5], 1);

    SpeedoNSRP[playerid][6] = CreatePlayerTextDraw(playerid, 160.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][6], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][6], -13238017);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][6], 1);

    SpeedoNSRP[playerid][7] = CreatePlayerTextDraw(playerid, 162.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][7], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][7], -12779265);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][7], 1);

    SpeedoNSRP[playerid][8] = CreatePlayerTextDraw(playerid, 164.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][8], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][8], -12320513);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][8], 1);

    SpeedoNSRP[playerid][9] = CreatePlayerTextDraw(playerid, 166.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][9], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][9], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][9], -11796225);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][9], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][9], 1);

    SpeedoNSRP[playerid][10] = CreatePlayerTextDraw(playerid, 168.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][10], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][10], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][10], -11271169);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][10], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][10], 1);

    SpeedoNSRP[playerid][11] = CreatePlayerTextDraw(playerid, 170.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][11], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][11], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][11], -10744321);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][11], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][11], 1);

    SpeedoNSRP[playerid][12] = CreatePlayerTextDraw(playerid, 172.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][12], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][12], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][12], -10217473);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][12], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][12], 1);

    SpeedoNSRP[playerid][13] = CreatePlayerTextDraw(playerid, 174.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][13], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][13], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][13], -9690625);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][13], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][13], 1);

    SpeedoNSRP[playerid][14] = CreatePlayerTextDraw(playerid, 176.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][14], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][14], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][14], -9163777);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][14], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][14], 1);

    SpeedoNSRP[playerid][15] = CreatePlayerTextDraw(playerid, 178.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][15], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][15], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][15], -8636929);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][15], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][15], 1);

    SpeedoNSRP[playerid][16] = CreatePlayerTextDraw(playerid, 180.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][16], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][16], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][16], -8110081);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][16], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][16], 1);

    SpeedoNSRP[playerid][17] = CreatePlayerTextDraw(playerid, 182.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][17], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][17], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][17], -7583233);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][17], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][17], 1);

    SpeedoNSRP[playerid][18] = CreatePlayerTextDraw(playerid, 184.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][18], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][18], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][18], -7056385);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][18], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][18], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][18], 1);

    SpeedoNSRP[playerid][19] = CreatePlayerTextDraw(playerid, 186.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][19], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][19], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][19], -6529537);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][19], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][19], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][19], 1);

    SpeedoNSRP[playerid][20] = CreatePlayerTextDraw(playerid, 188.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][20], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][20], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][20], -6002689);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][20], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][20], 1);

    SpeedoNSRP[playerid][21] = CreatePlayerTextDraw(playerid, 190.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][21], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][21], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][21], -5475841);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][21], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][21], 1);

    SpeedoNSRP[playerid][22] = CreatePlayerTextDraw(playerid, 192.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][22], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][22], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][22], -4948993);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][22], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][22], 1);

    SpeedoNSRP[playerid][23] = CreatePlayerTextDraw(playerid, 194.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][23], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][23], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][23], -4422145);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][23], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][23], 1);

    SpeedoNSRP[playerid][24] = CreatePlayerTextDraw(playerid, 196.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][24], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][24], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][24], -3895297);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][24], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][24], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][24], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][24], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][24], 1);

    SpeedoNSRP[playerid][25] = CreatePlayerTextDraw(playerid, 198.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][25], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][25], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][25], -3368449);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][25], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][25], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][25], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][25], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][25], 1);

    SpeedoNSRP[playerid][26] = CreatePlayerTextDraw(playerid, 200.000, 376.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][26], 2.000, 20.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][26], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][26], -2841601);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][26], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][26], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][26], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][26], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][26], 1);

    SpeedoNSRP[playerid][27] = CreatePlayerTextDraw(playerid, 205.000, 358.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][27], 3.000, 38.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][27], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][27], 572729343);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][27], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][27], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][27], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][27], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][27], 1);

    SpeedoNSRP[playerid][28] = CreatePlayerTextDraw(playerid, 206.000, 395.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][28], 1.000, -36.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][28], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][28], -12582657);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][28], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][28], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][28], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][28], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][28], 1);

    SpeedoNSRP[playerid][29] = CreatePlayerTextDraw(playerid, 150.000, 357.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][29], 12.000, 16.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][29], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][29], -12582657);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][29], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][29], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][29], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][29], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][29], 1);

    SpeedoNSRP[playerid][30] = CreatePlayerTextDraw(playerid, 154.000, 360.000, "N");
    PlayerTextDrawLetterSize(playerid, SpeedoNSRP[playerid][30], 0.187, 0.898);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][30], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][30], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][30], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][30], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][30], 150);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][30], 1);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][30], 1);

    SpeedoNSRP[playerid][31] = CreatePlayerTextDraw(playerid, 169.000, 357.000, "024");
    PlayerTextDrawLetterSize(playerid, SpeedoNSRP[playerid][31], 0.238, 1.500);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][31], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][31], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][31], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][31], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][31], 150);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][31], 1);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][31], 1);

    SpeedoNSRP[playerid][32] = CreatePlayerTextDraw(playerid, 186.000, 352.000, "MPH");
    PlayerTextDrawLetterSize(playerid, SpeedoNSRP[playerid][32], 0.119, 0.799);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][32], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][32], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][32], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][32], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][32], 150);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][32], 2);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][32], 1);

    SpeedoNSRP[playerid][33] = CreatePlayerTextDraw(playerid, 204.000, 353.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][33], 4.000, 4.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][33], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][33], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][33], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][33], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][33], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][33], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][33], 1);

    SpeedoNSRP[playerid][34] = CreatePlayerTextDraw(playerid, 204.000, 350.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][34], 1.000, 3.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][34], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][34], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][34], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][34], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][34], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][34], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][34], 1);

    SpeedoNSRP[playerid][35] = CreatePlayerTextDraw(playerid, 204.000, 349.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][35], 1.000, 4.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][35], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][35], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][35], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][35], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][35], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][35], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][35], 1);

    SpeedoNSRP[playerid][36] = CreatePlayerTextDraw(playerid, 207.000, 349.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][36], 1.000, 4.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][36], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][36], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][36], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][36], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][36], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][36], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][36], 1);

    SpeedoNSRP[playerid][37] = CreatePlayerTextDraw(playerid, 205.000, 349.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][37], 3.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][37], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][37], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][37], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][37], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][37], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][37], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][37], 1);

    SpeedoNSRP[playerid][38] = CreatePlayerTextDraw(playerid, 207.000, 348.000, "2");
    PlayerTextDrawLetterSize(playerid, SpeedoNSRP[playerid][38], 0.128, 0.799);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][38], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][38], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][38], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][38], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][38], 150);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][38], 1);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][38], 1);

    SpeedoNSRP[playerid][39] = CreatePlayerTextDraw(playerid, 205.000, 356.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][39], 4.000, 1.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][39], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][39], -1);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][39], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][39], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][39], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][39], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][39], 1);

    SpeedoNSRP[playerid][40] = CreatePlayerTextDraw(playerid, 213.800, 358.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][40], 3.000, 38.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][40], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][40], 572729343);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][40], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][40], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][40], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][40], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][40], 1);

    SpeedoNSRP[playerid][41] = CreatePlayerTextDraw(playerid, 215.000, 395.000, "LD_BUM:blkdot");
    PlayerTextDrawTextSize(playerid, SpeedoNSRP[playerid][41], 0.899, -36.000);
    PlayerTextDrawAlignment(playerid, SpeedoNSRP[playerid][41], 1);
    PlayerTextDrawColor(playerid, SpeedoNSRP[playerid][41], -12582657);
    PlayerTextDrawSetShadow(playerid, SpeedoNSRP[playerid][41], 0);
    PlayerTextDrawSetOutline(playerid, SpeedoNSRP[playerid][41], 0);
    PlayerTextDrawBackgroundColor(playerid, SpeedoNSRP[playerid][41], 255);
    PlayerTextDrawFont(playerid, SpeedoNSRP[playerid][41], 4);
    PlayerTextDrawSetProportional(playerid, SpeedoNSRP[playerid][41], 1);

}

//V1
ShowHBETD(playerid)
{
    for(new x; x < 20; x++)
	{
        TextDrawShowForPlayer(playerid, HBE[x]);
    }
    for(new x; x < 10; x++)
    {
        PlayerTextDrawShow(playerid, PHBE[playerid][x]);
    }
	HBETDHidden[playerid] = false;
}

HideHBETD(playerid)
{
    for(new x; x < 20; x++)
	{
        TextDrawHideForPlayer(playerid, HBE[x]);
    }
    for(new x; x < 10; x++)
    {
        PlayerTextDrawHide(playerid, PHBE[playerid][x]);
    }
	HBETDHidden[playerid] = true;
}

ShowSpeedoTD(playerid)
{
    SetPVarInt(playerid, "SpeedoHiden", false);
    for(new x; x < 42; x++)
	{
        PlayerTextDrawShow(playerid, SpeedoNSRP[playerid][x]);
    }
}

HideSpeedoTD(playerid)
{
    SetPVarInt(playerid, "SpeedoHiden", true);
    for(new x; x < 42; x++)
	{
        PlayerTextDrawHide(playerid, SpeedoNSRP[playerid][x]);
    }
}

ShowStressEffectTD(playerid)
{
    TextDrawShowForPlayer(playerid, StressTD);
}

HideStressEffectTD(playerid)
{
    TextDrawHideForPlayer(playerid, StressTD);
}