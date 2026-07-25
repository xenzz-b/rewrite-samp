new Text:ATMTD[69],
    PlayerText:ATMPTD[MAX_PLAYERS][4];

CreateATMTD()
{
    ATMTD[0] = TextDrawCreate(169.199, 129.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[0], 10.000, 12.000);
	TextDrawAlignment(ATMTD[0], 1);
	TextDrawColor(ATMTD[0], 387984895);
	TextDrawSetShadow(ATMTD[0], 0);
	TextDrawSetOutline(ATMTD[0], 0);
	TextDrawBackgroundColor(ATMTD[0], 255);
	TextDrawFont(ATMTD[0], 4);
	TextDrawSetProportional(ATMTD[0], 1);

	ATMTD[1] = TextDrawCreate(174.500, 131.000, "ld_bum:blkdot");
	TextDrawTextSize(ATMTD[1], 294.000, 264.000);
	TextDrawAlignment(ATMTD[1], 1);
	TextDrawColor(ATMTD[1], 387984895);
	TextDrawSetShadow(ATMTD[1], 0);
	TextDrawSetOutline(ATMTD[1], 0);
	TextDrawBackgroundColor(ATMTD[1], 255);
	TextDrawFont(ATMTD[1], 4);
	TextDrawSetProportional(ATMTD[1], 1);

	ATMTD[2] = TextDrawCreate(462.199, 129.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[2], 10.000, 12.000);
	TextDrawAlignment(ATMTD[2], 1);
	TextDrawColor(ATMTD[2], 387984895);
	TextDrawSetShadow(ATMTD[2], 0);
	TextDrawSetOutline(ATMTD[2], 0);
	TextDrawBackgroundColor(ATMTD[2], 255);
	TextDrawFont(ATMTD[2], 4);
	TextDrawSetProportional(ATMTD[2], 1);

	ATMTD[3] = TextDrawCreate(169.199, 385.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[3], 10.000, 12.000);
	TextDrawAlignment(ATMTD[3], 1);
	TextDrawColor(ATMTD[3], 387984895);
	TextDrawSetShadow(ATMTD[3], 0);
	TextDrawSetOutline(ATMTD[3], 0);
	TextDrawBackgroundColor(ATMTD[3], 255);
	TextDrawFont(ATMTD[3], 4);
	TextDrawSetProportional(ATMTD[3], 1);

	ATMTD[4] = TextDrawCreate(462.199, 385.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[4], 10.000, 12.000);
	TextDrawAlignment(ATMTD[4], 1);
	TextDrawColor(ATMTD[4], 387984895);
	TextDrawSetShadow(ATMTD[4], 0);
	TextDrawSetOutline(ATMTD[4], 0);
	TextDrawBackgroundColor(ATMTD[4], 255);
	TextDrawFont(ATMTD[4], 4);
	TextDrawSetProportional(ATMTD[4], 1);

	ATMTD[5] = TextDrawCreate(171.000, 135.000, "ld_bum:blkdot");
	TextDrawTextSize(ATMTD[5], 299.500, 256.000);
	TextDrawAlignment(ATMTD[5], 1);
	TextDrawColor(ATMTD[5], 387984895);
	TextDrawSetShadow(ATMTD[5], 0);
	TextDrawSetOutline(ATMTD[5], 0);
	TextDrawBackgroundColor(ATMTD[5], 255);
	TextDrawFont(ATMTD[5], 4);
	TextDrawSetProportional(ATMTD[5], 1);

	ATMTD[6] = TextDrawCreate(175.000, 165.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[6], 292.000, 1.500);
	TextDrawAlignment(ATMTD[6], 1);
	TextDrawColor(ATMTD[6], 539638015);
	TextDrawSetShadow(ATMTD[6], 0);
	TextDrawSetOutline(ATMTD[6], 0);
	TextDrawBackgroundColor(ATMTD[6], 255);
	TextDrawFont(ATMTD[6], 4);
	TextDrawSetProportional(ATMTD[6], 1);

	ATMTD[7] = TextDrawCreate(175.000, 144.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[7], 1.000, 15.500);
	TextDrawAlignment(ATMTD[7], 1);
	TextDrawColor(ATMTD[7], -1);
	TextDrawSetShadow(ATMTD[7], 0);
	TextDrawSetOutline(ATMTD[7], 0);
	TextDrawBackgroundColor(ATMTD[7], 255);
	TextDrawFont(ATMTD[7], 4);
	TextDrawSetProportional(ATMTD[7], 1);

	ATMTD[8] = TextDrawCreate(175.000, 159.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[8], 21.000, 1.000);
	TextDrawAlignment(ATMTD[8], 1);
	TextDrawColor(ATMTD[8], -1);
	TextDrawSetShadow(ATMTD[8], 0);
	TextDrawSetOutline(ATMTD[8], 0);
	TextDrawBackgroundColor(ATMTD[8], 255);
	TextDrawFont(ATMTD[8], 4);
	TextDrawSetProportional(ATMTD[8], 1);

	ATMTD[9] = TextDrawCreate(173.000, 145.000, "/");
	TextDrawLetterSize(ATMTD[9], 0.819, 1.900);
	TextDrawAlignment(ATMTD[9], 1);
	TextDrawColor(ATMTD[9], -1);
	TextDrawSetShadow(ATMTD[9], 1);
	TextDrawSetOutline(ATMTD[9], 1);
	TextDrawBackgroundColor(ATMTD[9], 0);
	TextDrawFont(ATMTD[9], 2);
	TextDrawSetProportional(ATMTD[9], 1);

	ATMTD[10] = TextDrawCreate(192.000, 147.000, "/");
	TextDrawLetterSize(ATMTD[10], -0.590, 1.099);
	TextDrawAlignment(ATMTD[10], 1);
	TextDrawColor(ATMTD[10], -1);
	TextDrawSetShadow(ATMTD[10], 1);
	TextDrawSetOutline(ATMTD[10], 1);
	TextDrawBackgroundColor(ATMTD[10], 0);
	TextDrawFont(ATMTD[10], 2);
	TextDrawSetProportional(ATMTD[10], 1);

	ATMTD[11] = TextDrawCreate(188.000, 142.000, "/");
	TextDrawLetterSize(ATMTD[11], 0.459, 1.700);
	TextDrawAlignment(ATMTD[11], 1);
	TextDrawColor(ATMTD[11], -1);
	TextDrawSetShadow(ATMTD[11], 1);
	TextDrawSetOutline(ATMTD[11], 1);
	TextDrawBackgroundColor(ATMTD[11], 0);
	TextDrawFont(ATMTD[11], 2);
	TextDrawSetProportional(ATMTD[11], 1);

	ATMTD[12] = TextDrawCreate(446.500, 138.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[12], 24.000, 11.500);
	TextDrawAlignment(ATMTD[12], 1);
	TextDrawColor(ATMTD[12], 539638015);
	TextDrawSetShadow(ATMTD[12], 0);
	TextDrawSetOutline(ATMTD[12], 0);
	TextDrawBackgroundColor(ATMTD[12], 255);
	TextDrawFont(ATMTD[12], 4);
	TextDrawSetProportional(ATMTD[12], 1);
	TextDrawSetSelectable(ATMTD[12], 1);

	ATMTD[13] = TextDrawCreate(464.000, 138.500, "Exit");
	TextDrawLetterSize(ATMTD[13], 0.190, 0.999);
	TextDrawAlignment(ATMTD[13], 3);
	TextDrawColor(ATMTD[13], -926365441);
	TextDrawSetShadow(ATMTD[13], 1);
	TextDrawSetOutline(ATMTD[13], 1);
	TextDrawBackgroundColor(ATMTD[13], 0);
	TextDrawFont(ATMTD[13], 1);
	TextDrawSetProportional(ATMTD[13], 1);

	ATMTD[14] = TextDrawCreate(190.000, 184.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[14], 261.000, 59.500);
	TextDrawAlignment(ATMTD[14], 1);
	TextDrawColor(ATMTD[14], 539638015);
	TextDrawSetShadow(ATMTD[14], 0);
	TextDrawSetOutline(ATMTD[14], 0);
	TextDrawBackgroundColor(ATMTD[14], 255);
	TextDrawFont(ATMTD[14], 4);
	TextDrawSetProportional(ATMTD[14], 1);

	ATMTD[15] = TextDrawCreate(282.000, 184.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[15], 3.000, 59.500);
	TextDrawAlignment(ATMTD[15], 1);
	TextDrawColor(ATMTD[15], 387984895);
	TextDrawSetShadow(ATMTD[15], 0);
	TextDrawSetOutline(ATMTD[15], 0);
	TextDrawBackgroundColor(ATMTD[15], 255);
	TextDrawFont(ATMTD[15], 4);
	TextDrawSetProportional(ATMTD[15], 1);

	ATMTD[16] = TextDrawCreate(355.000, 184.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[16], 3.000, 59.500);
	TextDrawAlignment(ATMTD[16], 1);
	TextDrawColor(ATMTD[16], 387984895);
	TextDrawSetShadow(ATMTD[16], 0);
	TextDrawSetOutline(ATMTD[16], 0);
	TextDrawBackgroundColor(ATMTD[16], 255);
	TextDrawFont(ATMTD[16], 4);
	TextDrawSetProportional(ATMTD[16], 1);

	ATMTD[17] = TextDrawCreate(236.000, 189.000, "Current Bank Balance");
	TextDrawLetterSize(ATMTD[17], 0.160, 0.899);
	TextDrawAlignment(ATMTD[17], 2);
	TextDrawColor(ATMTD[17], -926365441);
	TextDrawSetShadow(ATMTD[17], 1);
	TextDrawSetOutline(ATMTD[17], 1);
	TextDrawBackgroundColor(ATMTD[17], 0);
	TextDrawFont(ATMTD[17], 1);
	TextDrawSetProportional(ATMTD[17], 1);

	ATMTD[18] = TextDrawCreate(320.000, 189.000, "Bank Account Number");
	TextDrawLetterSize(ATMTD[18], 0.160, 0.899);
	TextDrawAlignment(ATMTD[18], 2);
	TextDrawColor(ATMTD[18], -926365441);
	TextDrawSetShadow(ATMTD[18], 1);
	TextDrawSetOutline(ATMTD[18], 1);
	TextDrawBackgroundColor(ATMTD[18], 0);
	TextDrawFont(ATMTD[18], 1);
	TextDrawSetProportional(ATMTD[18], 1);

	ATMTD[19] = TextDrawCreate(405.000, 189.000, "Current Cash Balance");
	TextDrawLetterSize(ATMTD[19], 0.160, 0.899);
	TextDrawAlignment(ATMTD[19], 2);
	TextDrawColor(ATMTD[19], -926365441);
	TextDrawSetShadow(ATMTD[19], 1);
	TextDrawSetOutline(ATMTD[19], 1);
	TextDrawBackgroundColor(ATMTD[19], 0);
	TextDrawFont(ATMTD[19], 1);
	TextDrawSetProportional(ATMTD[19], 1);

	ATMTD[20] = TextDrawCreate(320.000, 236.000, "LIMIT TRANSFER : $50.000.000");
	TextDrawLetterSize(ATMTD[20], 0.109, 0.599);
	TextDrawAlignment(ATMTD[20], 2);
	TextDrawColor(ATMTD[20], 1483110399);
	TextDrawSetShadow(ATMTD[20], 1);
	TextDrawSetOutline(ATMTD[20], 1);
	TextDrawBackgroundColor(ATMTD[20], 0);
	TextDrawFont(ATMTD[20], 1);
	TextDrawSetProportional(ATMTD[20], 1);

	ATMTD[21] = TextDrawCreate(189.000, 260.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[21], 77.000, 31.500);
	TextDrawAlignment(ATMTD[21], 1);
	TextDrawColor(ATMTD[21], 539638015);
	TextDrawSetShadow(ATMTD[21], 0);
	TextDrawSetOutline(ATMTD[21], 0);
	TextDrawBackgroundColor(ATMTD[21], 255);
	TextDrawFont(ATMTD[21], 4);
	TextDrawSetProportional(ATMTD[21], 1);

	ATMTD[22] = TextDrawCreate(373.000, 260.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[22], 77.000, 31.500);
	TextDrawAlignment(ATMTD[22], 1);
	TextDrawColor(ATMTD[22], 539638015);
	TextDrawSetShadow(ATMTD[22], 0);
	TextDrawSetOutline(ATMTD[22], 0);
	TextDrawBackgroundColor(ATMTD[22], 255);
	TextDrawFont(ATMTD[22], 4);
	TextDrawSetProportional(ATMTD[22], 1);

	ATMTD[23] = TextDrawCreate(281.500, 260.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[23], 77.000, 31.500);
	TextDrawAlignment(ATMTD[23], 1);
	TextDrawColor(ATMTD[23], 539638015);
	TextDrawSetShadow(ATMTD[23], 0);
	TextDrawSetOutline(ATMTD[23], 0);
	TextDrawBackgroundColor(ATMTD[23], 255);
	TextDrawFont(ATMTD[23], 4);
	TextDrawSetProportional(ATMTD[23], 1);

	ATMTD[24] = TextDrawCreate(192.000, 262.000, "Withdraw");
	TextDrawLetterSize(ATMTD[24], 0.160, 0.899);
	TextDrawAlignment(ATMTD[24], 1);
	TextDrawColor(ATMTD[24], -926365441);
	TextDrawSetShadow(ATMTD[24], 1);
	TextDrawSetOutline(ATMTD[24], 1);
	TextDrawBackgroundColor(ATMTD[24], 0);
	TextDrawFont(ATMTD[24], 1);
	TextDrawSetProportional(ATMTD[24], 1);

	ATMTD[25] = TextDrawCreate(285.000, 262.000, "Deposit");
	TextDrawLetterSize(ATMTD[25], 0.160, 0.899);
	TextDrawAlignment(ATMTD[25], 1);
	TextDrawColor(ATMTD[25], -926365441);
	TextDrawSetShadow(ATMTD[25], 1);
	TextDrawSetOutline(ATMTD[25], 1);
	TextDrawBackgroundColor(ATMTD[25], 0);
	TextDrawFont(ATMTD[25], 1);
	TextDrawSetProportional(ATMTD[25], 1);

	ATMTD[26] = TextDrawCreate(376.000, 262.000, "Transfer");
	TextDrawLetterSize(ATMTD[26], 0.160, 0.899);
	TextDrawAlignment(ATMTD[26], 1);
	TextDrawColor(ATMTD[26], -926365441);
	TextDrawSetShadow(ATMTD[26], 1);
	TextDrawSetOutline(ATMTD[26], 1);
	TextDrawBackgroundColor(ATMTD[26], 0);
	TextDrawFont(ATMTD[26], 1);
	TextDrawSetProportional(ATMTD[26], 1);

	ATMTD[27] = TextDrawCreate(239.000, 260.000, "LD_BEAT:chit");
	TextDrawTextSize(ATMTD[27], 24.000, 29.000);
	TextDrawAlignment(ATMTD[27], 1);
	TextDrawColor(ATMTD[27], 1651607807);
	TextDrawSetShadow(ATMTD[27], 0);
	TextDrawSetOutline(ATMTD[27], 0);
	TextDrawBackgroundColor(ATMTD[27], 255);
	TextDrawFont(ATMTD[27], 4);
	TextDrawSetProportional(ATMTD[27], 1);
	TextDrawSetSelectable(ATMTD[27], 1);

	ATMTD[28] = TextDrawCreate(247.500, 274.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[28], 6.000, 1.000);
	TextDrawAlignment(ATMTD[28], 1);
	TextDrawColor(ATMTD[28], 539638015);
	TextDrawSetShadow(ATMTD[28], 0);
	TextDrawSetOutline(ATMTD[28], 0);
	TextDrawBackgroundColor(ATMTD[28], 255);
	TextDrawFont(ATMTD[28], 4);
	TextDrawSetProportional(ATMTD[28], 1);

	ATMTD[29] = TextDrawCreate(251.500, 267.299, ">");
	TextDrawLetterSize(ATMTD[29], 0.139, 1.500);
	TextDrawAlignment(ATMTD[29], 1);
	TextDrawColor(ATMTD[29], 539638015);
	TextDrawSetShadow(ATMTD[29], 1);
	TextDrawSetOutline(ATMTD[29], 1);
	TextDrawBackgroundColor(ATMTD[29], 0);
	TextDrawFont(ATMTD[29], 1);
	TextDrawSetProportional(ATMTD[29], 1);

	ATMTD[30] = TextDrawCreate(331.000, 260.000, "LD_BEAT:chit");
	TextDrawTextSize(ATMTD[30], 24.000, 29.000);
	TextDrawAlignment(ATMTD[30], 1);
	TextDrawColor(ATMTD[30], 1651607807);
	TextDrawSetShadow(ATMTD[30], 0);
	TextDrawSetOutline(ATMTD[30], 0);
	TextDrawBackgroundColor(ATMTD[30], 255);
	TextDrawFont(ATMTD[30], 4);
	TextDrawSetProportional(ATMTD[30], 1);
	TextDrawSetSelectable(ATMTD[30], 1);

	ATMTD[31] = TextDrawCreate(339.500, 274.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[31], 6.000, 1.000);
	TextDrawAlignment(ATMTD[31], 1);
	TextDrawColor(ATMTD[31], 539638015);
	TextDrawSetShadow(ATMTD[31], 0);
	TextDrawSetOutline(ATMTD[31], 0);
	TextDrawBackgroundColor(ATMTD[31], 255);
	TextDrawFont(ATMTD[31], 4);
	TextDrawSetProportional(ATMTD[31], 1);

	ATMTD[32] = TextDrawCreate(343.500, 267.299, ">");
	TextDrawLetterSize(ATMTD[32], 0.139, 1.500);
	TextDrawAlignment(ATMTD[32], 1);
	TextDrawColor(ATMTD[32], 539638015);
	TextDrawSetShadow(ATMTD[32], 1);
	TextDrawSetOutline(ATMTD[32], 1);
	TextDrawBackgroundColor(ATMTD[32], 0);
	TextDrawFont(ATMTD[32], 1);
	TextDrawSetProportional(ATMTD[32], 1);

	ATMTD[33] = TextDrawCreate(423.000, 260.000, "LD_BEAT:chit");
	TextDrawTextSize(ATMTD[33], 24.000, 29.000);
	TextDrawAlignment(ATMTD[33], 1);
	TextDrawColor(ATMTD[33], 1651607807);
	TextDrawSetShadow(ATMTD[33], 0);
	TextDrawSetOutline(ATMTD[33], 0);
	TextDrawBackgroundColor(ATMTD[33], 255);
	TextDrawFont(ATMTD[33], 4);
	TextDrawSetProportional(ATMTD[33], 1);
	TextDrawSetSelectable(ATMTD[33], 1);

	ATMTD[34] = TextDrawCreate(431.500, 274.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[34], 6.000, 1.000);
	TextDrawAlignment(ATMTD[34], 1);
	TextDrawColor(ATMTD[34], 539638015);
	TextDrawSetShadow(ATMTD[34], 0);
	TextDrawSetOutline(ATMTD[34], 0);
	TextDrawBackgroundColor(ATMTD[34], 255);
	TextDrawFont(ATMTD[34], 4);
	TextDrawSetProportional(ATMTD[34], 1);

	ATMTD[35] = TextDrawCreate(435.500, 267.299, ">");
	TextDrawLetterSize(ATMTD[35], 0.139, 1.500);
	TextDrawAlignment(ATMTD[35], 1);
	TextDrawColor(ATMTD[35], 539638015);
	TextDrawSetShadow(ATMTD[35], 1);
	TextDrawSetOutline(ATMTD[35], 1);
	TextDrawBackgroundColor(ATMTD[35], 0);
	TextDrawFont(ATMTD[35], 1);
	TextDrawSetProportional(ATMTD[35], 1);

	ATMTD[36] = TextDrawCreate(192.000, 275.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[36], 14.000, 11.000);
	TextDrawAlignment(ATMTD[36], 1);
	TextDrawColor(ATMTD[36], 1651607807);
	TextDrawSetShadow(ATMTD[36], 0);
	TextDrawSetOutline(ATMTD[36], 0);
	TextDrawBackgroundColor(ATMTD[36], 255);
	TextDrawFont(ATMTD[36], 4);
	TextDrawSetProportional(ATMTD[36], 1);

	ATMTD[37] = TextDrawCreate(197.000, 277.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[37], 14.000, 1.000);
	TextDrawAlignment(ATMTD[37], 1);
	TextDrawColor(ATMTD[37], 539638015);
	TextDrawSetShadow(ATMTD[37], 0);
	TextDrawSetOutline(ATMTD[37], 0);
	TextDrawBackgroundColor(ATMTD[37], 255);
	TextDrawFont(ATMTD[37], 4);
	TextDrawSetProportional(ATMTD[37], 1);

	ATMTD[38] = TextDrawCreate(202.000, 279.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[38], 3.000, 3.500);
	TextDrawAlignment(ATMTD[38], 1);
	TextDrawColor(ATMTD[38], 539638015);
	TextDrawSetShadow(ATMTD[38], 0);
	TextDrawSetOutline(ATMTD[38], 0);
	TextDrawBackgroundColor(ATMTD[38], 255);
	TextDrawFont(ATMTD[38], 4);
	TextDrawSetProportional(ATMTD[38], 1);

	ATMTD[39] = TextDrawCreate(285.000, 275.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[39], 14.000, 11.000);
	TextDrawAlignment(ATMTD[39], 1);
	TextDrawColor(ATMTD[39], 1651607807);
	TextDrawSetShadow(ATMTD[39], 0);
	TextDrawSetOutline(ATMTD[39], 0);
	TextDrawBackgroundColor(ATMTD[39], 255);
	TextDrawFont(ATMTD[39], 4);
	TextDrawSetProportional(ATMTD[39], 1);

	ATMTD[40] = TextDrawCreate(286.000, 276.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[40], 2.000, 1.500);
	TextDrawAlignment(ATMTD[40], 1);
	TextDrawColor(ATMTD[40], 539638015);
	TextDrawSetShadow(ATMTD[40], 0);
	TextDrawSetOutline(ATMTD[40], 0);
	TextDrawBackgroundColor(ATMTD[40], 255);
	TextDrawFont(ATMTD[40], 4);
	TextDrawSetProportional(ATMTD[40], 1);

	ATMTD[41] = TextDrawCreate(286.000, 283.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[41], 2.000, 1.500);
	TextDrawAlignment(ATMTD[41], 1);
	TextDrawColor(ATMTD[41], 539638015);
	TextDrawSetShadow(ATMTD[41], 0);
	TextDrawSetOutline(ATMTD[41], 0);
	TextDrawBackgroundColor(ATMTD[41], 255);
	TextDrawFont(ATMTD[41], 4);
	TextDrawSetProportional(ATMTD[41], 1);

	ATMTD[42] = TextDrawCreate(296.200, 276.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[42], 2.000, 1.500);
	TextDrawAlignment(ATMTD[42], 1);
	TextDrawColor(ATMTD[42], 539638015);
	TextDrawSetShadow(ATMTD[42], 0);
	TextDrawSetOutline(ATMTD[42], 0);
	TextDrawBackgroundColor(ATMTD[42], 255);
	TextDrawFont(ATMTD[42], 4);
	TextDrawSetProportional(ATMTD[42], 1);

	ATMTD[43] = TextDrawCreate(287.500, 274.500, "LD_BEAT:chit");
	TextDrawTextSize(ATMTD[43], 10.000, 12.000);
	TextDrawAlignment(ATMTD[43], 1);
	TextDrawColor(ATMTD[43], 387984895);
	TextDrawSetShadow(ATMTD[43], 0);
	TextDrawSetOutline(ATMTD[43], 0);
	TextDrawBackgroundColor(ATMTD[43], 255);
	TextDrawFont(ATMTD[43], 4);
	TextDrawSetProportional(ATMTD[43], 1);

	ATMTD[44] = TextDrawCreate(296.200, 283.000, "ld_beat:chit");
	TextDrawTextSize(ATMTD[44], 2.000, 1.500);
	TextDrawAlignment(ATMTD[44], 1);
	TextDrawColor(ATMTD[44], 539638015);
	TextDrawSetShadow(ATMTD[44], 0);
	TextDrawSetOutline(ATMTD[44], 0);
	TextDrawBackgroundColor(ATMTD[44], 255);
	TextDrawFont(ATMTD[44], 4);
	TextDrawSetProportional(ATMTD[44], 1);

	ATMTD[45] = TextDrawCreate(292.500, 277.000, "$");
	TextDrawLetterSize(ATMTD[45], 0.129, 0.699);
	TextDrawAlignment(ATMTD[45], 2);
	TextDrawColor(ATMTD[45], -926365441);
	TextDrawSetShadow(ATMTD[45], 1);
	TextDrawSetOutline(ATMTD[45], 1);
	TextDrawBackgroundColor(ATMTD[45], 0);
	TextDrawFont(ATMTD[45], 1);
	TextDrawSetProportional(ATMTD[45], 1);

	ATMTD[46] = TextDrawCreate(386.000, 271.000, ">");
	TextDrawLetterSize(ATMTD[46], 0.189, 1.500);
	TextDrawAlignment(ATMTD[46], 1);
	TextDrawColor(ATMTD[46], 1651607807);
	TextDrawSetShadow(ATMTD[46], 1);
	TextDrawSetOutline(ATMTD[46], 1);
	TextDrawBackgroundColor(ATMTD[46], 0);
	TextDrawFont(ATMTD[46], 1);
	TextDrawSetProportional(ATMTD[46], 1);

	ATMTD[47] = TextDrawCreate(377.500, 277.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[47], 11.000, 2.000);
	TextDrawAlignment(ATMTD[47], 1);
	TextDrawColor(ATMTD[47], 1651607807);
	TextDrawSetShadow(ATMTD[47], 0);
	TextDrawSetOutline(ATMTD[47], 0);
	TextDrawBackgroundColor(ATMTD[47], 255);
	TextDrawFont(ATMTD[47], 4);
	TextDrawSetProportional(ATMTD[47], 1);

	ATMTD[48] = TextDrawCreate(377.500, 284.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[48], 12.500, 2.000);
	TextDrawAlignment(ATMTD[48], 1);
	TextDrawColor(ATMTD[48], 1651607807);
	TextDrawSetShadow(ATMTD[48], 0);
	TextDrawSetOutline(ATMTD[48], 0);
	TextDrawBackgroundColor(ATMTD[48], 255);
	TextDrawFont(ATMTD[48], 4);
	TextDrawSetProportional(ATMTD[48], 1);

	ATMTD[49] = TextDrawCreate(381.000, 277.500, ">");
	TextDrawLetterSize(ATMTD[49], -0.180, 1.500);
	TextDrawAlignment(ATMTD[49], 1);
	TextDrawColor(ATMTD[49], 1651607807);
	TextDrawSetShadow(ATMTD[49], 1);
	TextDrawSetOutline(ATMTD[49], 1);
	TextDrawBackgroundColor(ATMTD[49], 0);
	TextDrawFont(ATMTD[49], 1);
	TextDrawSetProportional(ATMTD[49], 1);

	ATMTD[50] = TextDrawCreate(320.000, 311.000, "Quick Withdraw");
	TextDrawLetterSize(ATMTD[50], 0.160, 0.899);
	TextDrawAlignment(ATMTD[50], 2);
	TextDrawColor(ATMTD[50], -1);
	TextDrawSetShadow(ATMTD[50], 1);
	TextDrawSetOutline(ATMTD[50], 1);
	TextDrawBackgroundColor(ATMTD[50], 0);
	TextDrawFont(ATMTD[50], 1);
	TextDrawSetProportional(ATMTD[50], 1);

	ATMTD[51] = TextDrawCreate(175.000, 298.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[51], 292.000, 1.500);
	TextDrawAlignment(ATMTD[51], 1);
	TextDrawColor(ATMTD[51], 539638015);
	TextDrawSetShadow(ATMTD[51], 0);
	TextDrawSetOutline(ATMTD[51], 0);
	TextDrawBackgroundColor(ATMTD[51], 255);
	TextDrawFont(ATMTD[51], 4);
	TextDrawSetProportional(ATMTD[51], 1);

	ATMTD[52] = TextDrawCreate(320.000, 345.000, "Quick Deposit");
	TextDrawLetterSize(ATMTD[52], 0.160, 0.899);
	TextDrawAlignment(ATMTD[52], 2);
	TextDrawColor(ATMTD[52], -1);
	TextDrawSetShadow(ATMTD[52], 1);
	TextDrawSetOutline(ATMTD[52], 1);
	TextDrawBackgroundColor(ATMTD[52], 0);
	TextDrawFont(ATMTD[52], 1);
	TextDrawSetProportional(ATMTD[52], 1);

	ATMTD[53] = TextDrawCreate(194.000, 324.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[53], 47.000, 17.000);
	TextDrawAlignment(ATMTD[53], 1);
	TextDrawColor(ATMTD[53], 539638015);
	TextDrawSetShadow(ATMTD[53], 0);
	TextDrawSetOutline(ATMTD[53], 0);
	TextDrawBackgroundColor(ATMTD[53], 255);
	TextDrawFont(ATMTD[53], 4);
	TextDrawSetProportional(ATMTD[53], 1);
	TextDrawSetSelectable(ATMTD[53], 1);

	ATMTD[54] = TextDrawCreate(218.000, 327.000, "$10,000");
	TextDrawLetterSize(ATMTD[54], 0.190, 1.099);
	TextDrawAlignment(ATMTD[54], 2);
	TextDrawColor(ATMTD[54], 1483110399);
	TextDrawSetShadow(ATMTD[54], 1);
	TextDrawSetOutline(ATMTD[54], 1);
	TextDrawBackgroundColor(ATMTD[54], 0);
	TextDrawFont(ATMTD[54], 1);
	TextDrawSetProportional(ATMTD[54], 1);

	ATMTD[55] = TextDrawCreate(262.000, 324.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[55], 47.000, 17.000);
	TextDrawAlignment(ATMTD[55], 1);
	TextDrawColor(ATMTD[55], 539638015);
	TextDrawSetShadow(ATMTD[55], 0);
	TextDrawSetOutline(ATMTD[55], 0);
	TextDrawBackgroundColor(ATMTD[55], 255);
	TextDrawFont(ATMTD[55], 4);
	TextDrawSetProportional(ATMTD[55], 1);
	TextDrawSetSelectable(ATMTD[55], 1);

	ATMTD[56] = TextDrawCreate(286.000, 327.000, "$50,000");
	TextDrawLetterSize(ATMTD[56], 0.190, 1.099);
	TextDrawAlignment(ATMTD[56], 2);
	TextDrawColor(ATMTD[56], 1483110399);
	TextDrawSetShadow(ATMTD[56], 1);
	TextDrawSetOutline(ATMTD[56], 1);
	TextDrawBackgroundColor(ATMTD[56], 0);
	TextDrawFont(ATMTD[56], 1);
	TextDrawSetProportional(ATMTD[56], 1);

	ATMTD[57] = TextDrawCreate(330.000, 324.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[57], 47.000, 17.000);
	TextDrawAlignment(ATMTD[57], 1);
	TextDrawColor(ATMTD[57], 539638015);
	TextDrawSetShadow(ATMTD[57], 0);
	TextDrawSetOutline(ATMTD[57], 0);
	TextDrawBackgroundColor(ATMTD[57], 255);
	TextDrawFont(ATMTD[57], 4);
	TextDrawSetProportional(ATMTD[57], 1);
	TextDrawSetSelectable(ATMTD[57], 1);

	ATMTD[58] = TextDrawCreate(354.000, 327.000, "$250,000");
	TextDrawLetterSize(ATMTD[58], 0.190, 1.099);
	TextDrawAlignment(ATMTD[58], 2);
	TextDrawColor(ATMTD[58], 1483110399);
	TextDrawSetShadow(ATMTD[58], 1);
	TextDrawSetOutline(ATMTD[58], 1);
	TextDrawBackgroundColor(ATMTD[58], 0);
	TextDrawFont(ATMTD[58], 1);
	TextDrawSetProportional(ATMTD[58], 1);

	ATMTD[59] = TextDrawCreate(398.000, 324.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[59], 47.000, 17.000);
	TextDrawAlignment(ATMTD[59], 1);
	TextDrawColor(ATMTD[59], 539638015);
	TextDrawSetShadow(ATMTD[59], 0);
	TextDrawSetOutline(ATMTD[59], 0);
	TextDrawBackgroundColor(ATMTD[59], 255);
	TextDrawFont(ATMTD[59], 4);
	TextDrawSetProportional(ATMTD[59], 1);
	TextDrawSetSelectable(ATMTD[59], 1);

	ATMTD[60] = TextDrawCreate(422.000, 327.000, "$500,000");
	TextDrawLetterSize(ATMTD[60], 0.190, 1.099);
	TextDrawAlignment(ATMTD[60], 2);
	TextDrawColor(ATMTD[60], 1483110399);
	TextDrawSetShadow(ATMTD[60], 1);
	TextDrawSetOutline(ATMTD[60], 1);
	TextDrawBackgroundColor(ATMTD[60], 0);
	TextDrawFont(ATMTD[60], 1);
	TextDrawSetProportional(ATMTD[60], 1);

	ATMTD[61] = TextDrawCreate(194.000, 359.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[61], 47.000, 17.000);
	TextDrawAlignment(ATMTD[61], 1);
	TextDrawColor(ATMTD[61], 539638015);
	TextDrawSetShadow(ATMTD[61], 0);
	TextDrawSetOutline(ATMTD[61], 0);
	TextDrawBackgroundColor(ATMTD[61], 255);
	TextDrawFont(ATMTD[61], 4);
	TextDrawSetProportional(ATMTD[61], 1);
	TextDrawSetSelectable(ATMTD[61], 1);

	ATMTD[62] = TextDrawCreate(218.000, 362.000, "$10,000");
	TextDrawLetterSize(ATMTD[62], 0.190, 1.099);
	TextDrawAlignment(ATMTD[62], 2);
	TextDrawColor(ATMTD[62], 1483110399);
	TextDrawSetShadow(ATMTD[62], 1);
	TextDrawSetOutline(ATMTD[62], 1);
	TextDrawBackgroundColor(ATMTD[62], 0);
	TextDrawFont(ATMTD[62], 1);
	TextDrawSetProportional(ATMTD[62], 1);

	ATMTD[63] = TextDrawCreate(262.000, 359.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[63], 47.000, 17.000);
	TextDrawAlignment(ATMTD[63], 1);
	TextDrawColor(ATMTD[63], 539638015);
	TextDrawSetShadow(ATMTD[63], 0);
	TextDrawSetOutline(ATMTD[63], 0);
	TextDrawBackgroundColor(ATMTD[63], 255);
	TextDrawFont(ATMTD[63], 4);
	TextDrawSetProportional(ATMTD[63], 1);
	TextDrawSetSelectable(ATMTD[63], 1);

	ATMTD[64] = TextDrawCreate(286.000, 362.000, "$50,000");
	TextDrawLetterSize(ATMTD[64], 0.190, 1.099);
	TextDrawAlignment(ATMTD[64], 2);
	TextDrawColor(ATMTD[64], 1483110399);
	TextDrawSetShadow(ATMTD[64], 1);
	TextDrawSetOutline(ATMTD[64], 1);
	TextDrawBackgroundColor(ATMTD[64], 0);
	TextDrawFont(ATMTD[64], 1);
	TextDrawSetProportional(ATMTD[64], 1);

	ATMTD[65] = TextDrawCreate(330.000, 359.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[65], 47.000, 17.000);
	TextDrawAlignment(ATMTD[65], 1);
	TextDrawColor(ATMTD[65], 539638015);
	TextDrawSetShadow(ATMTD[65], 0);
	TextDrawSetOutline(ATMTD[65], 0);
	TextDrawBackgroundColor(ATMTD[65], 255);
	TextDrawFont(ATMTD[65], 4);
	TextDrawSetProportional(ATMTD[65], 1);
	TextDrawSetSelectable(ATMTD[65], 1);

	ATMTD[66] = TextDrawCreate(354.000, 362.000, "$250,000");
	TextDrawLetterSize(ATMTD[66], 0.190, 1.099);
	TextDrawAlignment(ATMTD[66], 2);
	TextDrawColor(ATMTD[66], 1483110399);
	TextDrawSetShadow(ATMTD[66], 1);
	TextDrawSetOutline(ATMTD[66], 1);
	TextDrawBackgroundColor(ATMTD[66], 0);
	TextDrawFont(ATMTD[66], 1);
	TextDrawSetProportional(ATMTD[66], 1);

	ATMTD[67] = TextDrawCreate(398.000, 359.000, "LD_BUM:blkdot");
	TextDrawTextSize(ATMTD[67], 47.000, 17.000);
	TextDrawAlignment(ATMTD[67], 1);
	TextDrawColor(ATMTD[67], 539638015);
	TextDrawSetShadow(ATMTD[67], 0);
	TextDrawSetOutline(ATMTD[67], 0);
	TextDrawBackgroundColor(ATMTD[67], 255);
	TextDrawFont(ATMTD[67], 4);
	TextDrawSetProportional(ATMTD[67], 1);
	TextDrawSetSelectable(ATMTD[67], 1);

	ATMTD[68] = TextDrawCreate(422.000, 362.000, "$500,000");
	TextDrawLetterSize(ATMTD[68], 0.190, 1.099);
	TextDrawAlignment(ATMTD[68], 2);
	TextDrawColor(ATMTD[68], 1483110399);
	TextDrawSetShadow(ATMTD[68], 1);
	TextDrawSetOutline(ATMTD[68], 1);
	TextDrawBackgroundColor(ATMTD[68], 0);
	TextDrawFont(ATMTD[68], 1);
	TextDrawSetProportional(ATMTD[68], 1);
}

CreateATMPTD(playerid)
{
    ATMPTD[playerid][0] = CreatePlayerTextDraw(playerid, 236.000, 208.000, "$STRING1");
	PlayerTextDrawLetterSize(playerid, ATMPTD[playerid][0], 0.240, 1.499);
	PlayerTextDrawAlignment(playerid, ATMPTD[playerid][0], 2);
	PlayerTextDrawColor(playerid, ATMPTD[playerid][0], -1);
	PlayerTextDrawSetShadow(playerid, ATMPTD[playerid][0], 1);
	PlayerTextDrawSetOutline(playerid, ATMPTD[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, ATMPTD[playerid][0], 0);
	PlayerTextDrawFont(playerid, ATMPTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, ATMPTD[playerid][0], 1);

	ATMPTD[playerid][1] = CreatePlayerTextDraw(playerid, 320.000, 208.000, "$STRING2");
	PlayerTextDrawLetterSize(playerid, ATMPTD[playerid][1], 0.240, 1.499);
	PlayerTextDrawAlignment(playerid, ATMPTD[playerid][1], 2);
	PlayerTextDrawColor(playerid, ATMPTD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, ATMPTD[playerid][1], 1);
	PlayerTextDrawSetOutline(playerid, ATMPTD[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, ATMPTD[playerid][1], 0);
	PlayerTextDrawFont(playerid, ATMPTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, ATMPTD[playerid][1], 1);

	ATMPTD[playerid][2] = CreatePlayerTextDraw(playerid, 405.000, 208.000, "$STRING3");
	PlayerTextDrawLetterSize(playerid, ATMPTD[playerid][2], 0.240, 1.499);
	PlayerTextDrawAlignment(playerid, ATMPTD[playerid][2], 2);
	PlayerTextDrawColor(playerid, ATMPTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, ATMPTD[playerid][2], 1);
	PlayerTextDrawSetOutline(playerid, ATMPTD[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, ATMPTD[playerid][2], 0);
	PlayerTextDrawFont(playerid, ATMPTD[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, ATMPTD[playerid][2], 1);

	ATMPTD[playerid][3] = CreatePlayerTextDraw(playerid, 467.000, 153.500, "Welcome Back Ditzy Seruni");
	PlayerTextDrawLetterSize(playerid, ATMPTD[playerid][3], 0.150, 0.899);
	PlayerTextDrawAlignment(playerid, ATMPTD[playerid][3], 3);
	PlayerTextDrawColor(playerid, ATMPTD[playerid][3], -926365441);
	PlayerTextDrawSetShadow(playerid, ATMPTD[playerid][3], 1);
	PlayerTextDrawSetOutline(playerid, ATMPTD[playerid][3], 1);
	PlayerTextDrawBackgroundColor(playerid, ATMPTD[playerid][3], 0);
	PlayerTextDrawFont(playerid, ATMPTD[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, ATMPTD[playerid][3], 1);
}

ShowATMTD(playerid)
{
	HideHBETD(playerid);
	HideRadioVoiceInfoTD(playerid);
	HideServerNameTD(playerid);
	//HideStatsTD(playerid);

    for(new x; x < 69; x++)
    {
        TextDrawShowForPlayer(playerid, ATMTD[x]);
    }

    PlayerTextDrawSetString(playerid, ATMPTD[playerid][0], sprintf("$%s", FormatMoney(AccountData[playerid][pBankMoney])));
    PlayerTextDrawSetString(playerid, ATMPTD[playerid][1], sprintf("%d", AccountData[playerid][pBankNumber]));
	PlayerTextDrawSetString(playerid, ATMPTD[playerid][2], sprintf("$%s", FormatMoney(AccountData[playerid][pMoney])));
    PlayerTextDrawSetString(playerid, ATMPTD[playerid][3], sprintf("Welcome Back %s", AccountData[playerid][pName]));

    PlayerTextDrawShow(playerid, ATMPTD[playerid][0]);
    PlayerTextDrawShow(playerid, ATMPTD[playerid][1]);
    PlayerTextDrawShow(playerid, ATMPTD[playerid][2]);
    PlayerTextDrawShow(playerid, ATMPTD[playerid][3]);

    SelectTextDraw(playerid, Y_Vertex);
    return 1;
}

HideATMTD(playerid)
{
    for(new x; x < 69; x++)
    {
        TextDrawHideForPlayer(playerid, ATMTD[x]);
    }

    PlayerTextDrawHide(playerid, ATMPTD[playerid][0]);
    PlayerTextDrawHide(playerid, ATMPTD[playerid][1]);
    PlayerTextDrawHide(playerid, ATMPTD[playerid][2]);
    PlayerTextDrawHide(playerid, ATMPTD[playerid][3]);

	ShowHBETD(playerid);
	ShowRadioVoiceInfoTD(playerid);
	ShowServerNameTD(playerid);
	//ShowStatsTD(playerid);

    CancelSelectTextDraw(playerid);
    return 1;
}