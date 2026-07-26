new 
	Text:NotifBoxTD[3],
	Text:GlobalFooterTD,
 	PlayerText:pNotifBoxTD[MAX_PLAYERS],
	PlayerText:FooterTD[MAX_PLAYERS],
	PlayerText:SpecVRP[MAX_PLAYERS][11],
	PlayerText:pJobMixTD[MAX_PLAYERS][10],
	PlayerText:pAnnounceTD[MAX_PLAYERS],
	Text:InsuVRP[19],
	Text:JobCenterTD[69],
	Text:AnnounceTD[19],
	Text:JobMixTD[11],
	Text:AreaSantaiTD[4],
	PlayerBar:pSlumpMeter[MAX_PLAYERS];

CreateInfoTextdraw()
{
	//------------------------
	AreaSantaiTD[0] = TextDrawCreate(520.000000, 100.000000, "ld_dual:white");
	TextDrawFont(AreaSantaiTD[0], 4);
	TextDrawLetterSize(AreaSantaiTD[0], 0.600000, 2.000000);
	TextDrawTextSize(AreaSantaiTD[0], 67.500000, 23.000000);
	TextDrawSetOutline(AreaSantaiTD[0], 1);
	TextDrawSetShadow(AreaSantaiTD[0], 0);
	TextDrawAlignment(AreaSantaiTD[0], 1);
	TextDrawColor(AreaSantaiTD[0], -12582657);
	TextDrawBackgroundColor(AreaSantaiTD[0], 255);
	TextDrawBoxColor(AreaSantaiTD[0], 50);
	TextDrawUseBox(AreaSantaiTD[0], 1);
	TextDrawSetProportional(AreaSantaiTD[0], 1);
	TextDrawSetSelectable(AreaSantaiTD[0], 0);

	AreaSantaiTD[1] = TextDrawCreate(563.000000, 105.000000, "Area Santai");
	TextDrawFont(AreaSantaiTD[1], 1);
	TextDrawLetterSize(AreaSantaiTD[1], 0.200000, 1.149999);
	TextDrawTextSize(AreaSantaiTD[1], 400.000000, 77.000000);
	TextDrawSetOutline(AreaSantaiTD[1], 0);
	TextDrawSetShadow(AreaSantaiTD[1], 0);
	TextDrawAlignment(AreaSantaiTD[1], 2);
	TextDrawColor(AreaSantaiTD[1], 9145343);
	TextDrawBackgroundColor(AreaSantaiTD[1], 255);
	TextDrawBoxColor(AreaSantaiTD[1], 50);
	TextDrawUseBox(AreaSantaiTD[1], 0);
	TextDrawSetProportional(AreaSantaiTD[1], 1);
	TextDrawSetSelectable(AreaSantaiTD[1], 0);

	AreaSantaiTD[2] = TextDrawCreate(526.000000, 103.000000, "HUD:radar_gangn");
	TextDrawFont(AreaSantaiTD[2], 4);
	TextDrawLetterSize(AreaSantaiTD[2], 0.600000, 2.000000);
	TextDrawTextSize(AreaSantaiTD[2], 15.000000, 15.000000);
	TextDrawSetOutline(AreaSantaiTD[2], 1);
	TextDrawSetShadow(AreaSantaiTD[2], 0);
	TextDrawAlignment(AreaSantaiTD[2], 1);
	TextDrawColor(AreaSantaiTD[2], -1);
	TextDrawBackgroundColor(AreaSantaiTD[2], 255);
	TextDrawBoxColor(AreaSantaiTD[2], 50);
	TextDrawUseBox(AreaSantaiTD[2], 1);
	TextDrawSetProportional(AreaSantaiTD[2], 1);
	TextDrawSetSelectable(AreaSantaiTD[2], 0);

	AreaSantaiTD[3] = TextDrawCreate(520.000000, 100.000000, "ld_dual:white");
	TextDrawFont(AreaSantaiTD[3], 4);
	TextDrawLetterSize(AreaSantaiTD[3], 0.600000, 2.000000);
	TextDrawTextSize(AreaSantaiTD[3], 3.000000, 23.000000);
	TextDrawSetOutline(AreaSantaiTD[3], 1);
	TextDrawSetShadow(AreaSantaiTD[3], 0);
	TextDrawAlignment(AreaSantaiTD[3], 1);
	TextDrawColor(AreaSantaiTD[3], 9145343);
	TextDrawBackgroundColor(AreaSantaiTD[3], 255);
	TextDrawBoxColor(AreaSantaiTD[3], 50);
	TextDrawUseBox(AreaSantaiTD[3], 1);
	TextDrawSetProportional(AreaSantaiTD[3], 1);
	TextDrawSetSelectable(AreaSantaiTD[3], 0);

	//------------------------
	NotifBoxTD[0] = TextDrawCreate(7.000000, 211.000000, "ld_dual:white");
	TextDrawFont(NotifBoxTD[0], 4);
	TextDrawLetterSize(NotifBoxTD[0], 0.600000, 2.000000);
	TextDrawTextSize(NotifBoxTD[0], 113.000000, 20.000000);
	TextDrawSetOutline(NotifBoxTD[0], 1);
	TextDrawSetShadow(NotifBoxTD[0], 0);
	TextDrawAlignment(NotifBoxTD[0], 1);
	TextDrawColor(NotifBoxTD[0], 0x000000ff);
	TextDrawBackgroundColor(NotifBoxTD[0], 255);
	TextDrawBoxColor(NotifBoxTD[0], 50);
	TextDrawUseBox(NotifBoxTD[0], 1);
	TextDrawSetProportional(NotifBoxTD[0], 1);
	TextDrawSetSelectable(NotifBoxTD[0], 0);

	NotifBoxTD[1] = TextDrawCreate(10.000000, 215.000000, "ld_dual:white");
	TextDrawFont(NotifBoxTD[1], 4);
	TextDrawLetterSize(NotifBoxTD[1], 0.600000, 2.000000);
	TextDrawTextSize(NotifBoxTD[1], 113.000000, 20.000000);
	TextDrawSetOutline(NotifBoxTD[1], 1);
	TextDrawSetShadow(NotifBoxTD[1], 0);
	TextDrawAlignment(NotifBoxTD[1], 1);
	TextDrawColor(NotifBoxTD[1], -12582657);
	TextDrawBackgroundColor(NotifBoxTD[1], 255);
	TextDrawBoxColor(NotifBoxTD[1], 50);
	TextDrawUseBox(NotifBoxTD[1], 1);
	TextDrawSetProportional(NotifBoxTD[1], 1);
	TextDrawSetSelectable(NotifBoxTD[1], 0);

	NotifBoxTD[2] = TextDrawCreate(15.000000, 217.000000, "ld_chat:badchat");
	TextDrawFont(NotifBoxTD[2], 4);
	TextDrawLetterSize(NotifBoxTD[2], 0.600000, 2.000000);
	TextDrawTextSize(NotifBoxTD[2], 11.500000, 14.000000);
	TextDrawSetOutline(NotifBoxTD[2], 1);
	TextDrawSetShadow(NotifBoxTD[2], 0);
	TextDrawAlignment(NotifBoxTD[2], 1);
	TextDrawColor(NotifBoxTD[2], 0xffffffcc);
	TextDrawBackgroundColor(NotifBoxTD[2], 255);
	TextDrawBoxColor(NotifBoxTD[2], 50);
	TextDrawUseBox(NotifBoxTD[2], 1);
	TextDrawSetProportional(NotifBoxTD[2], 1);
	TextDrawSetSelectable(NotifBoxTD[2], 0);

	GlobalFooterTD = TextDrawCreate(320.000000, 352.000000, "~r~ID: 100~n~~r~Type: ~w~Medium House~n~~r~Owner: ~y~Aaaaaaaaaa_Bbbbbbbbbbbbb~n~~r~Loc: ~w~Tierra Robada");
	TextDrawFont(GlobalFooterTD, 1);
	TextDrawLetterSize(GlobalFooterTD, 0.225000, 1.599999);
	TextDrawTextSize(GlobalFooterTD, 398.000000, 164.000000);
	TextDrawSetOutline(GlobalFooterTD, true);
	TextDrawSetShadow(GlobalFooterTD, false);
	TextDrawAlignment(GlobalFooterTD, 2);
	TextDrawColor(GlobalFooterTD, -1);
	TextDrawBackgroundColor(GlobalFooterTD, 255);
	TextDrawBoxColor(GlobalFooterTD, 179);
	TextDrawUseBox(GlobalFooterTD, false);
	TextDrawSetProportional(GlobalFooterTD, true);
	TextDrawSetSelectable(GlobalFooterTD, false);

	InsuVRP[0] = TextDrawCreate(247.000, 64.000, "LD_SPAC:white");
    TextDrawTextSize(InsuVRP[0], 140.000, 54.000);
    TextDrawAlignment(InsuVRP[0], 1);
    TextDrawColor(InsuVRP[0], -1);
    TextDrawSetShadow(InsuVRP[0], 0);
    TextDrawSetOutline(InsuVRP[0], 0);
    TextDrawBackgroundColor(InsuVRP[0], 255);
    TextDrawFont(InsuVRP[0], 4);
    TextDrawSetProportional(InsuVRP[0], 1);

    InsuVRP[1] = TextDrawCreate(244.000, 56.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[1], 19.000, 20.000);
    TextDrawAlignment(InsuVRP[1], 1);
    TextDrawColor(InsuVRP[1], -1);
    TextDrawSetShadow(InsuVRP[1], 0);
    TextDrawSetOutline(InsuVRP[1], 0);
    TextDrawBackgroundColor(InsuVRP[1], 255);
    TextDrawFont(InsuVRP[1], 4);
    TextDrawSetProportional(InsuVRP[1], 1);

    InsuVRP[2] = TextDrawCreate(371.000, 56.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[2], 19.500, 20.000);
    TextDrawAlignment(InsuVRP[2], 1);
    TextDrawColor(InsuVRP[2], -1);
    TextDrawSetShadow(InsuVRP[2], 0);
    TextDrawSetOutline(InsuVRP[2], 0);
    TextDrawBackgroundColor(InsuVRP[2], 255);
    TextDrawFont(InsuVRP[2], 4);
    TextDrawSetProportional(InsuVRP[2], 1);

    InsuVRP[3] = TextDrawCreate(371.000, 107.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[3], 19.500, 20.000);
    TextDrawAlignment(InsuVRP[3], 1);
    TextDrawColor(InsuVRP[3], -1);
    TextDrawSetShadow(InsuVRP[3], 0);
    TextDrawSetOutline(InsuVRP[3], 0);
    TextDrawBackgroundColor(InsuVRP[3], 255);
    TextDrawFont(InsuVRP[3], 4);
    TextDrawSetProportional(InsuVRP[3], 1);

    InsuVRP[4] = TextDrawCreate(244.000, 107.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[4], 19.000, 20.000);
    TextDrawAlignment(InsuVRP[4], 1);
    TextDrawColor(InsuVRP[4], -1);
    TextDrawSetShadow(InsuVRP[4], 0);
    TextDrawSetOutline(InsuVRP[4], 0);
    TextDrawBackgroundColor(InsuVRP[4], 255);
    TextDrawFont(InsuVRP[4], 4);
    TextDrawSetProportional(InsuVRP[4], 1);

    InsuVRP[5] = TextDrawCreate(254.000, 59.000, "LD_SPAC:white");
    TextDrawTextSize(InsuVRP[5], 126.000, 65.000);
    TextDrawAlignment(InsuVRP[5], 1);
    TextDrawColor(InsuVRP[5], -1);
    TextDrawSetShadow(InsuVRP[5], 0);
    TextDrawSetOutline(InsuVRP[5], 0);
    TextDrawBackgroundColor(InsuVRP[5], 255);
    TextDrawFont(InsuVRP[5], 4);
    TextDrawSetProportional(InsuVRP[5], 1);

    InsuVRP[6] = TextDrawCreate(246.000, 58.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[6], 19.000, 20.000);
    TextDrawAlignment(InsuVRP[6], 1);
    TextDrawColor(InsuVRP[6], -12254977);
    TextDrawSetShadow(InsuVRP[6], 0);
    TextDrawSetOutline(InsuVRP[6], 0);
    TextDrawBackgroundColor(InsuVRP[6], 255);
    TextDrawFont(InsuVRP[6], 4);
    TextDrawSetProportional(InsuVRP[6], 1);

    InsuVRP[7] = TextDrawCreate(369.000, 58.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[7], 19.000, 20.000);
    TextDrawAlignment(InsuVRP[7], 1);
    TextDrawColor(InsuVRP[7], -10878721);
    TextDrawSetShadow(InsuVRP[7], 0);
    TextDrawSetOutline(InsuVRP[7], 0);
    TextDrawBackgroundColor(InsuVRP[7], 255);
    TextDrawFont(InsuVRP[7], 4);
    TextDrawSetProportional(InsuVRP[7], 1);

    InsuVRP[8] = TextDrawCreate(369.000, 105.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[8], 19.000, 20.000);
    TextDrawAlignment(InsuVRP[8], 1);
    TextDrawColor(InsuVRP[8], -10878721);
    TextDrawSetShadow(InsuVRP[8], 0);
    TextDrawSetOutline(InsuVRP[8], 0);
    TextDrawBackgroundColor(InsuVRP[8], 255);
    TextDrawFont(InsuVRP[8], 4);
    TextDrawSetProportional(InsuVRP[8], 1);

    InsuVRP[9] = TextDrawCreate(246.000, 105.000, "LD_BEAT:chit");
    TextDrawTextSize(InsuVRP[9], 19.000, 20.000);
    TextDrawAlignment(InsuVRP[9], 1);
    TextDrawColor(InsuVRP[9], -10878721);
    TextDrawSetShadow(InsuVRP[9], 0);
    TextDrawSetOutline(InsuVRP[9], 0);
    TextDrawBackgroundColor(InsuVRP[9], 255);
    TextDrawFont(InsuVRP[9], 4);
    TextDrawSetProportional(InsuVRP[9], 1);

    InsuVRP[10] = TextDrawCreate(249.000, 67.000, "LD_SPAC:white");
    TextDrawTextSize(InsuVRP[10], 136.000, 48.000);
    TextDrawAlignment(InsuVRP[10], 1);
    TextDrawColor(InsuVRP[10], -12254977);
    TextDrawSetShadow(InsuVRP[10], 0);
    TextDrawSetOutline(InsuVRP[10], 0);
    TextDrawBackgroundColor(InsuVRP[10], 255);
    TextDrawFont(InsuVRP[10], 4);
    TextDrawSetProportional(InsuVRP[10], 1);

    InsuVRP[11] = TextDrawCreate(256.000, 61.000, "LD_SPAC:white");
    TextDrawTextSize(InsuVRP[11], 122.000, 60.500);
    TextDrawAlignment(InsuVRP[11], 1);
    TextDrawColor(InsuVRP[11], -12254977);
    TextDrawSetShadow(InsuVRP[11], 0);
    TextDrawSetOutline(InsuVRP[11], 0);
    TextDrawBackgroundColor(InsuVRP[11], 255);
    TextDrawFont(InsuVRP[11], 4);
    TextDrawSetProportional(InsuVRP[11], 1);

    InsuVRP[12] = TextDrawCreate(282.000, 64.000, "[INSURANCE KELILING]");
    TextDrawLetterSize(InsuVRP[12], 0.200, 1.199);
    TextDrawAlignment(InsuVRP[12], 1);
    TextDrawColor(InsuVRP[12], -1);
    TextDrawSetShadow(InsuVRP[12], 0);
    TextDrawSetOutline(InsuVRP[12], 0);
    TextDrawBackgroundColor(InsuVRP[12], 150);
    TextDrawFont(InsuVRP[12], 1);
    TextDrawSetProportional(InsuVRP[12], 1);

    InsuVRP[13] = TextDrawCreate(317.000, 107.000, "12 menit 12 detik");
    TextDrawLetterSize(InsuVRP[13], 0.140, 1.199);
    TextDrawAlignment(InsuVRP[13], 2);
    TextDrawColor(InsuVRP[13], -2147483393);
    TextDrawSetShadow(InsuVRP[13], 0);
    TextDrawSetOutline(InsuVRP[13], 0);
    TextDrawBackgroundColor(InsuVRP[13], 150);
    TextDrawFont(InsuVRP[13], 1);
    TextDrawSetProportional(InsuVRP[13], 1);

    InsuVRP[14] = TextDrawCreate(317.000, 86.000, "Kendaraan yang tidak ditempati akan diproses oleh sistem");
    TextDrawLetterSize(InsuVRP[14], 0.129, 1.099);
    TextDrawAlignment(InsuVRP[14], 2);
    TextDrawColor(InsuVRP[14], -1);
    TextDrawSetShadow(InsuVRP[14], 0);
    TextDrawSetOutline(InsuVRP[14], 0);
    TextDrawBackgroundColor(InsuVRP[14], 150);
    TextDrawFont(InsuVRP[14], 1);
    TextDrawSetProportional(InsuVRP[14], 1);

    InsuVRP[15] = TextDrawCreate(317.000, 95.000, "Segera naik ke kendaraan Anda sebelum waktu habis.");
    TextDrawLetterSize(InsuVRP[15], 0.129, 1.099);
    TextDrawAlignment(InsuVRP[15], 2);
    TextDrawColor(InsuVRP[15], -1);
    TextDrawSetShadow(InsuVRP[15], 0);
    TextDrawSetOutline(InsuVRP[15], 0);
    TextDrawBackgroundColor(InsuVRP[15], 150);
    TextDrawFont(InsuVRP[15], 1);
    TextDrawSetProportional(InsuVRP[15], 1);

    InsuVRP[16] = TextDrawCreate(317.000, 77.000, "Layanan asuransi keliling telah dimulai");
    TextDrawLetterSize(InsuVRP[16], 0.129, 1.099);
    TextDrawAlignment(InsuVRP[16], 2);
    TextDrawColor(InsuVRP[16], -1);
    TextDrawSetShadow(InsuVRP[16], 0);
    TextDrawSetOutline(InsuVRP[16], 0);
    TextDrawBackgroundColor(InsuVRP[16], 150);
    TextDrawFont(InsuVRP[16], 1);
    TextDrawSetProportional(InsuVRP[16], 1);

    InsuVRP[17] = TextDrawCreate(254.000, 62.000, "HUD:radar_impound");
    TextDrawTextSize(InsuVRP[17], 12.000, 14.000);
    TextDrawAlignment(InsuVRP[17], 1);
    TextDrawColor(InsuVRP[17], -12254977);
    TextDrawSetShadow(InsuVRP[17], 0);
    TextDrawSetOutline(InsuVRP[17], 0);
    TextDrawBackgroundColor(InsuVRP[17], 255);
    TextDrawFont(InsuVRP[17], 4);
    TextDrawSetProportional(InsuVRP[17], 1);

    InsuVRP[18] = TextDrawCreate(381.000, 62.000, "HUD:radar_impound");
    TextDrawTextSize(InsuVRP[18], -13.000, 14.000);
    TextDrawAlignment(InsuVRP[18], 1);
    TextDrawColor(InsuVRP[18], -12254977);
    TextDrawSetShadow(InsuVRP[18], 0);
    TextDrawSetOutline(InsuVRP[18], 0);
    TextDrawBackgroundColor(InsuVRP[18], 255);
    TextDrawFont(InsuVRP[18], 4);
    TextDrawSetProportional(InsuVRP[18], 1);
}

CreateAnnounceTD()
{
	AnnounceTD[0] = TextDrawCreate(227.000, 4.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[0], 17.000, 18.000);
	TextDrawAlignment(AnnounceTD[0], 1);
	TextDrawColor(AnnounceTD[0], 255);
	TextDrawSetShadow(AnnounceTD[0], 0);
	TextDrawSetOutline(AnnounceTD[0], 0);
	TextDrawBackgroundColor(AnnounceTD[0], 255);
	TextDrawFont(AnnounceTD[0], 4);
	TextDrawSetProportional(AnnounceTD[0], 1);

	AnnounceTD[1] = TextDrawCreate(236.000, 7.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[1], 173.000, 42.000);
	TextDrawAlignment(AnnounceTD[1], 1);
	TextDrawColor(AnnounceTD[1], 255);
	TextDrawSetShadow(AnnounceTD[1], 0);
	TextDrawSetOutline(AnnounceTD[1], 0);
	TextDrawBackgroundColor(AnnounceTD[1], 255);
	TextDrawFont(AnnounceTD[1], 4);
	TextDrawSetProportional(AnnounceTD[1], 1);

	AnnounceTD[2] = TextDrawCreate(227.000, 34.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[2], 17.000, 18.000);
	TextDrawAlignment(AnnounceTD[2], 1);
	TextDrawColor(AnnounceTD[2], 255);
	TextDrawSetShadow(AnnounceTD[2], 0);
	TextDrawSetOutline(AnnounceTD[2], 0);
	TextDrawBackgroundColor(AnnounceTD[2], 255);
	TextDrawFont(AnnounceTD[2], 4);
	TextDrawSetProportional(AnnounceTD[2], 1);

	AnnounceTD[3] = TextDrawCreate(400.000, 34.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[3], 17.000, 18.000);
	TextDrawAlignment(AnnounceTD[3], 1);
	TextDrawColor(AnnounceTD[3], 255);
	TextDrawSetShadow(AnnounceTD[3], 0);
	TextDrawSetOutline(AnnounceTD[3], 0);
	TextDrawBackgroundColor(AnnounceTD[3], 255);
	TextDrawFont(AnnounceTD[3], 4);
	TextDrawSetProportional(AnnounceTD[3], 1);

	AnnounceTD[4] = TextDrawCreate(400.000, 4.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[4], 17.000, 18.000);
	TextDrawAlignment(AnnounceTD[4], 1);
	TextDrawColor(AnnounceTD[4], 255);
	TextDrawSetShadow(AnnounceTD[4], 0);
	TextDrawSetOutline(AnnounceTD[4], 0);
	TextDrawBackgroundColor(AnnounceTD[4], 255);
	TextDrawFont(AnnounceTD[4], 4);
	TextDrawSetProportional(AnnounceTD[4], 1);

	AnnounceTD[5] = TextDrawCreate(230.000, 13.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[5], 184.000, 32.000);
	TextDrawAlignment(AnnounceTD[5], 1);
	TextDrawColor(AnnounceTD[5], 255);
	TextDrawSetShadow(AnnounceTD[5], 0);
	TextDrawSetOutline(AnnounceTD[5], 0);
	TextDrawBackgroundColor(AnnounceTD[5], 255);
	TextDrawFont(AnnounceTD[5], 4);
	TextDrawSetProportional(AnnounceTD[5], 1);

	AnnounceTD[6] = TextDrawCreate(230.000, 12.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[6], 1.000, 33.000);
	TextDrawAlignment(AnnounceTD[6], 1);
	TextDrawColor(AnnounceTD[6], -12582657);
	TextDrawSetShadow(AnnounceTD[6], 0);
	TextDrawSetOutline(AnnounceTD[6], 0);
	TextDrawBackgroundColor(AnnounceTD[6], 255);
	TextDrawFont(AnnounceTD[6], 4);
	TextDrawSetProportional(AnnounceTD[6], 1);

	AnnounceTD[7] = TextDrawCreate(414.000, 12.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[7], 1.000, 33.000);
	TextDrawAlignment(AnnounceTD[7], 1);
	TextDrawColor(AnnounceTD[7], -12582657);
	TextDrawSetShadow(AnnounceTD[7], 0);
	TextDrawSetOutline(AnnounceTD[7], 0);
	TextDrawBackgroundColor(AnnounceTD[7], 255);
	TextDrawFont(AnnounceTD[7], 4);
	TextDrawSetProportional(AnnounceTD[7], 1);

	AnnounceTD[8] = TextDrawCreate(289.000, 9.000, "ANNOUNCEMENT");
	TextDrawLetterSize(AnnounceTD[8], 0.259, 0.999);
	TextDrawAlignment(AnnounceTD[8], 1);
	TextDrawColor(AnnounceTD[8], -1);
	TextDrawSetShadow(AnnounceTD[8], 0);
	TextDrawSetOutline(AnnounceTD[8], 0);
	TextDrawBackgroundColor(AnnounceTD[8], 150);
	TextDrawFont(AnnounceTD[8], 1);
	TextDrawSetProportional(AnnounceTD[8], 1);

	AnnounceTD[9] = TextDrawCreate(235.000, 20.000, "awdakdksadjwkl kwjdajwdjawjdwkjd ]wdwdw");
	TextDrawLetterSize(AnnounceTD[9], 0.200, 0.898);
	TextDrawAlignment(AnnounceTD[9], 1);
	TextDrawColor(AnnounceTD[9], -1);
	TextDrawSetShadow(AnnounceTD[9], 0);
	TextDrawSetOutline(AnnounceTD[9], 0);
	TextDrawBackgroundColor(AnnounceTD[9], 150);
	TextDrawFont(AnnounceTD[9], 1);
	TextDrawSetProportional(AnnounceTD[9], 1);

	AnnounceTD[10] = TextDrawCreate(275.000, 51.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[10], 17.000, 14.000);
	TextDrawAlignment(AnnounceTD[10], 1);
	TextDrawColor(AnnounceTD[10], 255);
	TextDrawSetShadow(AnnounceTD[10], 0);
	TextDrawSetOutline(AnnounceTD[10], 0);
	TextDrawBackgroundColor(AnnounceTD[10], 255);
	TextDrawFont(AnnounceTD[10], 4);
	TextDrawSetProportional(AnnounceTD[10], 1);

	AnnounceTD[11] = TextDrawCreate(284.000, 53.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[11], 74.000, 25.000);
	TextDrawAlignment(AnnounceTD[11], 1);
	TextDrawColor(AnnounceTD[11], 255);
	TextDrawSetShadow(AnnounceTD[11], 0);
	TextDrawSetOutline(AnnounceTD[11], 0);
	TextDrawBackgroundColor(AnnounceTD[11], 255);
	TextDrawFont(AnnounceTD[11], 4);
	TextDrawSetProportional(AnnounceTD[11], 1);

	AnnounceTD[12] = TextDrawCreate(275.000, 66.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[12], 17.000, 14.000);
	TextDrawAlignment(AnnounceTD[12], 1);
	TextDrawColor(AnnounceTD[12], 255);
	TextDrawSetShadow(AnnounceTD[12], 0);
	TextDrawSetOutline(AnnounceTD[12], 0);
	TextDrawBackgroundColor(AnnounceTD[12], 255);
	TextDrawFont(AnnounceTD[12], 4);
	TextDrawSetProportional(AnnounceTD[12], 1);

	AnnounceTD[13] = TextDrawCreate(350.000, 66.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[13], 17.000, 14.000);
	TextDrawAlignment(AnnounceTD[13], 1);
	TextDrawColor(AnnounceTD[13], 255);
	TextDrawSetShadow(AnnounceTD[13], 0);
	TextDrawSetOutline(AnnounceTD[13], 0);
	TextDrawBackgroundColor(AnnounceTD[13], 255);
	TextDrawFont(AnnounceTD[13], 4);
	TextDrawSetProportional(AnnounceTD[13], 1);

	AnnounceTD[14] = TextDrawCreate(350.000, 51.000, "LD_BEAT:chit");
	TextDrawTextSize(AnnounceTD[14], 17.000, 14.000);
	TextDrawAlignment(AnnounceTD[14], 1);
	TextDrawColor(AnnounceTD[14], 255);
	TextDrawSetShadow(AnnounceTD[14], 0);
	TextDrawSetOutline(AnnounceTD[14], 0);
	TextDrawBackgroundColor(AnnounceTD[14], 255);
	TextDrawFont(AnnounceTD[14], 4);
	TextDrawSetProportional(AnnounceTD[14], 1);

	AnnounceTD[15] = TextDrawCreate(278.000, 58.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[15], 86.000, 16.000);
	TextDrawAlignment(AnnounceTD[15], 1);
	TextDrawColor(AnnounceTD[15], 255);
	TextDrawSetShadow(AnnounceTD[15], 0);
	TextDrawSetOutline(AnnounceTD[15], 0);
	TextDrawBackgroundColor(AnnounceTD[15], 255);
	TextDrawFont(AnnounceTD[15], 4);
	TextDrawSetProportional(AnnounceTD[15], 1);

	AnnounceTD[16] = TextDrawCreate(280.000, 58.000, "From :");
	TextDrawLetterSize(AnnounceTD[16], 0.209, 1.399);
	TextDrawAlignment(AnnounceTD[16], 1);
	TextDrawColor(AnnounceTD[16], -1);
	TextDrawSetShadow(AnnounceTD[16], 0);
	TextDrawSetOutline(AnnounceTD[16], 0);
	TextDrawBackgroundColor(AnnounceTD[16], 150);
	TextDrawFont(AnnounceTD[16], 1);
	TextDrawSetProportional(AnnounceTD[16], 1);

	AnnounceTD[17] = TextDrawCreate(278.000, 58.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[17], 1.000, 16.000);
	TextDrawAlignment(AnnounceTD[17], 1);
	TextDrawColor(AnnounceTD[17], -12582657);
	TextDrawSetShadow(AnnounceTD[17], 0);
	TextDrawSetOutline(AnnounceTD[17], 0);
	TextDrawBackgroundColor(AnnounceTD[17], 255);
	TextDrawFont(AnnounceTD[17], 4);
	TextDrawSetProportional(AnnounceTD[17], 1);

	AnnounceTD[18] = TextDrawCreate(364.000, 58.000, "LD_SPAC:white");
	TextDrawTextSize(AnnounceTD[18], 1.000, 16.000);
	TextDrawAlignment(AnnounceTD[18], 1);
	TextDrawColor(AnnounceTD[18], -12582657);
	TextDrawSetShadow(AnnounceTD[18], 0);
	TextDrawSetOutline(AnnounceTD[18], 0);
	TextDrawBackgroundColor(AnnounceTD[18], 255);
	TextDrawFont(AnnounceTD[18], 4);
	TextDrawSetProportional(AnnounceTD[18], 1);
}

CreatePAnnounceTD(playerid)
{
	pAnnounceTD[playerid] = CreatePlayerTextDraw(playerid, 306.000, 58.000, "Shan");
	PlayerTextDrawLetterSize(playerid, pAnnounceTD[playerid], 0.209, 1.399);
	PlayerTextDrawAlignment(playerid, pAnnounceTD[playerid], 1);
	PlayerTextDrawColor(playerid, pAnnounceTD[playerid], -1);
	PlayerTextDrawSetShadow(playerid, pAnnounceTD[playerid], 0);
	PlayerTextDrawSetOutline(playerid, pAnnounceTD[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, pAnnounceTD[playerid], 150);
	PlayerTextDrawFont(playerid, pAnnounceTD[playerid], 1);
	PlayerTextDrawSetProportional(playerid, pAnnounceTD[playerid], 1);
}

CreateInfoTextDrawPlayer(playerid)
{
	pNotifBoxTD[playerid] = CreatePlayerTextDraw(playerid, 30.000000, 220.000000, "Tekan 'Y' Akses Garasi Kota");
	PlayerTextDrawFont(playerid, pNotifBoxTD[playerid], 1);
	PlayerTextDrawLetterSize(playerid, pNotifBoxTD[playerid], 0.187500, 0.950000);
	PlayerTextDrawTextSize(playerid, pNotifBoxTD[playerid], 117.500000, 17.000000);
	PlayerTextDrawSetOutline(playerid, pNotifBoxTD[playerid], false);
	PlayerTextDrawSetShadow(playerid, pNotifBoxTD[playerid], false);
	PlayerTextDrawAlignment(playerid, pNotifBoxTD[playerid], true);
	PlayerTextDrawColor(playerid, pNotifBoxTD[playerid], 0xffffffff);
	PlayerTextDrawBackgroundColor(playerid, pNotifBoxTD[playerid], 255);
	PlayerTextDrawBoxColor(playerid, pNotifBoxTD[playerid], 50);
	PlayerTextDrawUseBox(playerid, pNotifBoxTD[playerid], false);
	PlayerTextDrawSetProportional(playerid, pNotifBoxTD[playerid], true);
	PlayerTextDrawSetSelectable(playerid, pNotifBoxTD[playerid], false);

	SpecVRP[playerid][0] = CreatePlayerTextDraw(playerid, 250.000, 364.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][0], 139.500, 47.298);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][0], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][0], 471602431);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][0], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][0], 1);

    SpecVRP[playerid][1] = CreatePlayerTextDraw(playerid, 320.000, 373.000, "Raiden Sinaga (1)");
    PlayerTextDrawLetterSize(playerid, SpecVRP[playerid][1], 0.270, 1.399);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][1], 2);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][1], 150);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][1], 1);

    SpecVRP[playerid][2] = CreatePlayerTextDraw(playerid, 320.000, 386.000, "Health : 100 - Armour : 100");
    PlayerTextDrawLetterSize(playerid, SpecVRP[playerid][2], 0.200, 1.399);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][2], 2);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][2], 150);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][2], 1);

    SpecVRP[playerid][3] = CreatePlayerTextDraw(playerid, 254.000, 408.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][3], 129.000, 3.799);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][3], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][3], -12254977);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][3], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][3], 1);

    SpecVRP[playerid][4] = CreatePlayerTextDraw(playerid, 383.000, 364.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][4], 28.000, 47.798);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][4], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][4], 471602431);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][4], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][4], 1);
    PlayerTextDrawSetSelectable(playerid, SpecVRP[playerid][4], 1);

    SpecVRP[playerid][5] = CreatePlayerTextDraw(playerid, 227.000, 364.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][5], 28.000, 47.798);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][5], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][5], 471602431);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][5], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][5], 1);
    PlayerTextDrawSetSelectable(playerid, SpecVRP[playerid][5], 1);

    SpecVRP[playerid][6] = CreatePlayerTextDraw(playerid, 224.000, 364.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][6], 3.000, 47.798);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][6], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][6], -12254977);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][6], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][6], 1);

    SpecVRP[playerid][7] = CreatePlayerTextDraw(playerid, 255.000, 364.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][7], 128.000, 3.799);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][7], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][7], -12254977);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][7], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][7], 1);

    SpecVRP[playerid][8] = CreatePlayerTextDraw(playerid, 411.000, 364.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, SpecVRP[playerid][8], 3.000, 47.798);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][8], 1);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][8], -12254977);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][8], 255);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][8], 1);

    SpecVRP[playerid][9] = CreatePlayerTextDraw(playerid, 240.000, 380.000, "<");
    PlayerTextDrawLetterSize(playerid, SpecVRP[playerid][9], 0.270, 1.399);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][9], 2);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][9], 150);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][9], 1);

    SpecVRP[playerid][10] = CreatePlayerTextDraw(playerid, 399.000, 380.000, ">");
    PlayerTextDrawLetterSize(playerid, SpecVRP[playerid][10], 0.270, 1.399);
    PlayerTextDrawAlignment(playerid, SpecVRP[playerid][10], 2);
    PlayerTextDrawColor(playerid, SpecVRP[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, SpecVRP[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, SpecVRP[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, SpecVRP[playerid][10], 150);
    PlayerTextDrawFont(playerid, SpecVRP[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, SpecVRP[playerid][10], 1);
}

CreateFooterTD(playerid)
{
	FooterTD[playerid] = CreatePlayerTextDraw(playerid, 325.666625, 400.5, "_");
    PlayerTextDrawLetterSize(playerid, FooterTD[playerid], 0.400000, 1.600000);
    PlayerTextDrawAlignment(playerid, FooterTD[playerid], 2);
    PlayerTextDrawColor(playerid, FooterTD[playerid], 0xe8e8e8ff);
    PlayerTextDrawSetShadow(playerid, FooterTD[playerid], 2);
    PlayerTextDrawSetOutline(playerid, FooterTD[playerid], 0);
    PlayerTextDrawBackgroundColor(playerid, FooterTD[playerid], 255);
    PlayerTextDrawFont(playerid, FooterTD[playerid], 1);
    PlayerTextDrawSetProportional(playerid, FooterTD[playerid], 1);
    PlayerTextDrawSetShadow(playerid, FooterTD[playerid], 1);
    PlayerTextDrawShow(playerid, FooterTD[playerid]);
}

CreateJobCenterTD()
{
	JobCenterTD[0] = TextDrawCreate(386.000, 107.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[0], 84.000, 17.000);
    TextDrawAlignment(JobCenterTD[0], 1);
    TextDrawColor(JobCenterTD[0], 623658239);
    TextDrawSetShadow(JobCenterTD[0], 0);
    TextDrawSetOutline(JobCenterTD[0], 0);
    TextDrawBackgroundColor(JobCenterTD[0], 255);
    TextDrawFont(JobCenterTD[0], 4);
    TextDrawSetProportional(JobCenterTD[0], 1);

    JobCenterTD[1] = TextDrawCreate(380.398, 104.696, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[1], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[1], 1);
    TextDrawColor(JobCenterTD[1], 623658239);
    TextDrawSetShadow(JobCenterTD[1], 0);
    TextDrawSetOutline(JobCenterTD[1], 0);
    TextDrawBackgroundColor(JobCenterTD[1], 255);
    TextDrawFont(JobCenterTD[1], 4);
    TextDrawSetProportional(JobCenterTD[1], 1);

    JobCenterTD[2] = TextDrawCreate(464.600, 104.696, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[2], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[2], 1);
    TextDrawColor(JobCenterTD[2], 623658239);
    TextDrawSetShadow(JobCenterTD[2], 0);
    TextDrawSetOutline(JobCenterTD[2], 0);
    TextDrawBackgroundColor(JobCenterTD[2], 255);
    TextDrawFont(JobCenterTD[2], 4);
    TextDrawSetProportional(JobCenterTD[2], 1);

    JobCenterTD[3] = TextDrawCreate(380.398, 112.097, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[3], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[3], 1);
    TextDrawColor(JobCenterTD[3], 623658239);
    TextDrawSetShadow(JobCenterTD[3], 0);
    TextDrawSetOutline(JobCenterTD[3], 0);
    TextDrawBackgroundColor(JobCenterTD[3], 255);
    TextDrawFont(JobCenterTD[3], 4);
    TextDrawSetProportional(JobCenterTD[3], 1);

    JobCenterTD[4] = TextDrawCreate(464.898, 112.086, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[4], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[4], 1);
    TextDrawColor(JobCenterTD[4], 623658239);
    TextDrawSetShadow(JobCenterTD[4], 0);
    TextDrawSetOutline(JobCenterTD[4], 0);
    TextDrawBackgroundColor(JobCenterTD[4], 255);
    TextDrawFont(JobCenterTD[4], 4);
    TextDrawSetProportional(JobCenterTD[4], 1);

    JobCenterTD[5] = TextDrawCreate(382.000, 112.500, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[5], 92.000, 7.000);
    TextDrawAlignment(JobCenterTD[5], 1);
    TextDrawColor(JobCenterTD[5], 623658239);
    TextDrawSetShadow(JobCenterTD[5], 0);
    TextDrawSetOutline(JobCenterTD[5], 0);
    TextDrawBackgroundColor(JobCenterTD[5], 255);
    TextDrawFont(JobCenterTD[5], 4);
    TextDrawSetProportional(JobCenterTD[5], 1);

    JobCenterTD[6] = TextDrawCreate(473.898, 104.696, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[6], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[6], 1);
    TextDrawColor(JobCenterTD[6], 623658239);
    TextDrawSetShadow(JobCenterTD[6], 0);
    TextDrawSetOutline(JobCenterTD[6], 0);
    TextDrawBackgroundColor(JobCenterTD[6], 255);
    TextDrawFont(JobCenterTD[6], 4);
    TextDrawSetProportional(JobCenterTD[6], 1);

    JobCenterTD[7] = TextDrawCreate(473.898, 112.295, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[7], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[7], 1);
    TextDrawColor(JobCenterTD[7], 623658239);
    TextDrawSetShadow(JobCenterTD[7], 0);
    TextDrawSetOutline(JobCenterTD[7], 0);
    TextDrawBackgroundColor(JobCenterTD[7], 255);
    TextDrawFont(JobCenterTD[7], 4);
    TextDrawSetProportional(JobCenterTD[7], 1);

    JobCenterTD[8] = TextDrawCreate(481.500, 104.696, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[8], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[8], 1);
    TextDrawColor(JobCenterTD[8], 623658239);
    TextDrawSetShadow(JobCenterTD[8], 0);
    TextDrawSetOutline(JobCenterTD[8], 0);
    TextDrawBackgroundColor(JobCenterTD[8], 255);
    TextDrawFont(JobCenterTD[8], 4);
    TextDrawSetProportional(JobCenterTD[8], 1);

    JobCenterTD[9] = TextDrawCreate(481.500, 112.295, "LD_beat:chit");
    TextDrawTextSize(JobCenterTD[9], 11.000, 14.000);
    TextDrawAlignment(JobCenterTD[9], 1);
    TextDrawColor(JobCenterTD[9], 623658239);
    TextDrawSetShadow(JobCenterTD[9], 0);
    TextDrawSetOutline(JobCenterTD[9], 0);
    TextDrawBackgroundColor(JobCenterTD[9], 255);
    TextDrawFont(JobCenterTD[9], 4);
    TextDrawSetProportional(JobCenterTD[9], 1);

    JobCenterTD[10] = TextDrawCreate(479.000, 107.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[10], 8.000, 17.000);
    TextDrawAlignment(JobCenterTD[10], 1);
    TextDrawColor(JobCenterTD[10], 623658239);
    TextDrawSetShadow(JobCenterTD[10], 0);
    TextDrawSetOutline(JobCenterTD[10], 0);
    TextDrawBackgroundColor(JobCenterTD[10], 255);
    TextDrawFont(JobCenterTD[10], 4);
    TextDrawSetProportional(JobCenterTD[10], 1);
    TextDrawSetSelectable(JobCenterTD[10], 1);

    JobCenterTD[11] = TextDrawCreate(476.000, 111.500, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[11], 15.000, 7.000);
    TextDrawAlignment(JobCenterTD[11], 1);
    TextDrawColor(JobCenterTD[11], 623658239);
    TextDrawSetShadow(JobCenterTD[11], 0);
    TextDrawSetOutline(JobCenterTD[11], 0);
    TextDrawBackgroundColor(JobCenterTD[11], 255);
    TextDrawFont(JobCenterTD[11], 4);
    TextDrawSetProportional(JobCenterTD[11], 1);

    JobCenterTD[12] = TextDrawCreate(428.000, 110.500, "DISNAKER Vertex");
    TextDrawLetterSize(JobCenterTD[12], 0.187, 0.999);
    TextDrawAlignment(JobCenterTD[12], 2);
    TextDrawColor(JobCenterTD[12], -1);
    TextDrawSetShadow(JobCenterTD[12], 1);
    TextDrawSetOutline(JobCenterTD[12], 0);
    TextDrawBackgroundColor(JobCenterTD[12], 0);
    TextDrawFont(JobCenterTD[12], 1);
    TextDrawSetProportional(JobCenterTD[12], 1);

    JobCenterTD[13] = TextDrawCreate(483.500, 110.500, "X");
    TextDrawLetterSize(JobCenterTD[13], 0.238, 0.999);
    TextDrawAlignment(JobCenterTD[13], 2);
    TextDrawColor(JobCenterTD[13], -1);
    TextDrawSetShadow(JobCenterTD[13], 1);
    TextDrawSetOutline(JobCenterTD[13], 0);
    TextDrawBackgroundColor(JobCenterTD[13], 0);
    TextDrawFont(JobCenterTD[13], 1);
    TextDrawSetProportional(JobCenterTD[13], 1);

    JobCenterTD[14] = TextDrawCreate(382.000, 127.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[14], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[14], 1);
    TextDrawColor(JobCenterTD[14], 623658239);
    TextDrawSetShadow(JobCenterTD[14], 0);
    TextDrawSetOutline(JobCenterTD[14], 0);
    TextDrawBackgroundColor(JobCenterTD[14], 255);
    TextDrawFont(JobCenterTD[14], 4);
    TextDrawSetProportional(JobCenterTD[14], 1);
    TextDrawSetSelectable(JobCenterTD[14], 1);

    JobCenterTD[15] = TextDrawCreate(399.000, 132.000, "Petani");
    TextDrawLetterSize(JobCenterTD[15], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[15], 1);
    TextDrawColor(JobCenterTD[15], -1);
    TextDrawSetShadow(JobCenterTD[15], 1);
    TextDrawSetOutline(JobCenterTD[15], 0);
    TextDrawBackgroundColor(JobCenterTD[15], 0);
    TextDrawFont(JobCenterTD[15], 1);
    TextDrawSetProportional(JobCenterTD[15], 1);

    JobCenterTD[16] = TextDrawCreate(386.000, 143.000, "Beli bibit dan tanam untuk mendapat uang");
    TextDrawLetterSize(JobCenterTD[16], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[16], 494.000, 30.000);
    TextDrawAlignment(JobCenterTD[16], 1);
    TextDrawColor(JobCenterTD[16], -1);
    TextDrawSetShadow(JobCenterTD[16], 1);
    TextDrawSetOutline(JobCenterTD[16], 0);
    TextDrawBackgroundColor(JobCenterTD[16], 0);
    TextDrawFont(JobCenterTD[16], 1);
    TextDrawSetProportional(JobCenterTD[16], 1);

    JobCenterTD[17] = TextDrawCreate(386.000, 129.000, "LD_SLOT:grapes");
    TextDrawTextSize(JobCenterTD[17], 9.000, 11.000);
    TextDrawAlignment(JobCenterTD[17], 1);
    TextDrawColor(JobCenterTD[17], -1);
    TextDrawSetShadow(JobCenterTD[17], 0);
    TextDrawSetOutline(JobCenterTD[17], 0);
    TextDrawBackgroundColor(JobCenterTD[17], 255);
    TextDrawFont(JobCenterTD[17], 4);
    TextDrawSetProportional(JobCenterTD[17], 1);

    JobCenterTD[18] = TextDrawCreate(382.000, 160.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[18], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[18], 1);
    TextDrawColor(JobCenterTD[18], 623658239);
    TextDrawSetShadow(JobCenterTD[18], 0);
    TextDrawSetOutline(JobCenterTD[18], 0);
    TextDrawBackgroundColor(JobCenterTD[18], 255);
    TextDrawFont(JobCenterTD[18], 4);
    TextDrawSetProportional(JobCenterTD[18], 1);
    TextDrawSetSelectable(JobCenterTD[18], 1);

    JobCenterTD[19] = TextDrawCreate(399.000, 165.000, "Penambang");
    TextDrawLetterSize(JobCenterTD[19], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[19], 1);
    TextDrawColor(JobCenterTD[19], -1);
    TextDrawSetShadow(JobCenterTD[19], 1);
    TextDrawSetOutline(JobCenterTD[19], 0);
    TextDrawBackgroundColor(JobCenterTD[19], 0);
    TextDrawFont(JobCenterTD[19], 1);
    TextDrawSetProportional(JobCenterTD[19], 1);

    JobCenterTD[20] = TextDrawCreate(386.000, 176.000, "Banyak sumber daya alam di pekerjaan ini");
    TextDrawLetterSize(JobCenterTD[20], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[20], 532.000, 30.000);
    TextDrawAlignment(JobCenterTD[20], 1);
    TextDrawColor(JobCenterTD[20], -1);
    TextDrawSetShadow(JobCenterTD[20], 1);
    TextDrawSetOutline(JobCenterTD[20], 0);
    TextDrawBackgroundColor(JobCenterTD[20], 0);
    TextDrawFont(JobCenterTD[20], 1);
    TextDrawSetProportional(JobCenterTD[20], 1);

    JobCenterTD[21] = TextDrawCreate(386.000, 164.000, "HUD:radar_bulldozer");
    TextDrawTextSize(JobCenterTD[21], 10.000, 11.000);
    TextDrawAlignment(JobCenterTD[21], 1);
    TextDrawColor(JobCenterTD[21], -1);
    TextDrawSetShadow(JobCenterTD[21], 0);
    TextDrawSetOutline(JobCenterTD[21], 0);
    TextDrawBackgroundColor(JobCenterTD[21], 255);
    TextDrawFont(JobCenterTD[21], 4);
    TextDrawSetProportional(JobCenterTD[21], 1);

    JobCenterTD[22] = TextDrawCreate(382.000, 193.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[22], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[22], 1);
    TextDrawColor(JobCenterTD[22], 623658239);
    TextDrawSetShadow(JobCenterTD[22], 0);
    TextDrawSetOutline(JobCenterTD[22], 0);
    TextDrawBackgroundColor(JobCenterTD[22], 255);
    TextDrawFont(JobCenterTD[22], 4);
    TextDrawSetProportional(JobCenterTD[22], 1);
    TextDrawSetSelectable(JobCenterTD[22], 1);

    JobCenterTD[23] = TextDrawCreate(399.000, 198.000, "Tukang Ayam");
    TextDrawLetterSize(JobCenterTD[23], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[23], 1);
    TextDrawColor(JobCenterTD[23], -1);
    TextDrawSetShadow(JobCenterTD[23], 1);
    TextDrawSetOutline(JobCenterTD[23], 0);
    TextDrawBackgroundColor(JobCenterTD[23], 0);
    TextDrawFont(JobCenterTD[23], 1);
    TextDrawSetProportional(JobCenterTD[23], 1);

    JobCenterTD[24] = TextDrawCreate(386.000, 209.000, "Bekerja di rumah potong dan jual ayam kemasan");
    TextDrawLetterSize(JobCenterTD[24], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[24], 529.000, 30.000);
    TextDrawAlignment(JobCenterTD[24], 1);
    TextDrawColor(JobCenterTD[24], -1);
    TextDrawSetShadow(JobCenterTD[24], 1);
    TextDrawSetOutline(JobCenterTD[24], 0);
    TextDrawBackgroundColor(JobCenterTD[24], 0);
    TextDrawFont(JobCenterTD[24], 1);
    TextDrawSetProportional(JobCenterTD[24], 1);

    JobCenterTD[25] = TextDrawCreate(387.000, 199.000, "HUD:radar_chicken");
    TextDrawTextSize(JobCenterTD[25], 8.000, 10.000);
    TextDrawAlignment(JobCenterTD[25], 1);
    TextDrawColor(JobCenterTD[25], -12254977);
    TextDrawSetShadow(JobCenterTD[25], 0);
    TextDrawSetOutline(JobCenterTD[25], 0);
    TextDrawBackgroundColor(JobCenterTD[25], 255);
    TextDrawFont(JobCenterTD[25], 4);
    TextDrawSetProportional(JobCenterTD[25], 1);

    JobCenterTD[26] = TextDrawCreate(382.000, 226.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[26], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[26], 1);
    TextDrawColor(JobCenterTD[26], 623658239);
    TextDrawSetShadow(JobCenterTD[26], 0);
    TextDrawSetOutline(JobCenterTD[26], 0);
    TextDrawBackgroundColor(JobCenterTD[26], 255);
    TextDrawFont(JobCenterTD[26], 4);
    TextDrawSetProportional(JobCenterTD[26], 1);
    TextDrawSetSelectable(JobCenterTD[26], 1);

    JobCenterTD[27] = TextDrawCreate(399.000, 231.000, "Tukang Minyak");
    TextDrawLetterSize(JobCenterTD[27], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[27], 1);
    TextDrawColor(JobCenterTD[27], -1);
    TextDrawSetShadow(JobCenterTD[27], 1);
    TextDrawSetOutline(JobCenterTD[27], 0);
    TextDrawBackgroundColor(JobCenterTD[27], 0);
    TextDrawFont(JobCenterTD[27], 1);
    TextDrawSetProportional(JobCenterTD[27], 1);

    JobCenterTD[28] = TextDrawCreate(386.000, 242.000, "Ambil minyak di kilang untuk dapat uang!");
    TextDrawLetterSize(JobCenterTD[28], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[28], 529.000, 30.000);
    TextDrawAlignment(JobCenterTD[28], 1);
    TextDrawColor(JobCenterTD[28], -1);
    TextDrawSetShadow(JobCenterTD[28], 1);
    TextDrawSetOutline(JobCenterTD[28], 0);
    TextDrawBackgroundColor(JobCenterTD[28], 0);
    TextDrawFont(JobCenterTD[28], 1);
    TextDrawSetProportional(JobCenterTD[28], 1);

    JobCenterTD[29] = TextDrawCreate(387.000, 232.000, "HUD:radar_TorenoRanch");
    TextDrawTextSize(JobCenterTD[29], 8.000, 10.000);
    TextDrawAlignment(JobCenterTD[29], 1);
    TextDrawColor(JobCenterTD[29], -1);
    TextDrawSetShadow(JobCenterTD[29], 0);
    TextDrawSetOutline(JobCenterTD[29], 0);
    TextDrawBackgroundColor(JobCenterTD[29], 255);
    TextDrawFont(JobCenterTD[29], 4);
    TextDrawSetProportional(JobCenterTD[29], 1);

    JobCenterTD[30] = TextDrawCreate(382.000, 259.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[30], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[30], 1);
    TextDrawColor(JobCenterTD[30], 623658239);
    TextDrawSetShadow(JobCenterTD[30], 0);
    TextDrawSetOutline(JobCenterTD[30], 0);
    TextDrawBackgroundColor(JobCenterTD[30], 255);
    TextDrawFont(JobCenterTD[30], 4);
    TextDrawSetProportional(JobCenterTD[30], 1);
    TextDrawSetSelectable(JobCenterTD[30], 1);

    JobCenterTD[31] = TextDrawCreate(399.000, 264.000, "Supir Angkot");
    TextDrawLetterSize(JobCenterTD[31], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[31], 1);
    TextDrawColor(JobCenterTD[31], -1);
    TextDrawSetShadow(JobCenterTD[31], 1);
    TextDrawSetOutline(JobCenterTD[31], 0);
    TextDrawBackgroundColor(JobCenterTD[31], 0);
    TextDrawFont(JobCenterTD[31], 1);
    TextDrawSetProportional(JobCenterTD[31], 1);

    JobCenterTD[32] = TextDrawCreate(386.000, 275.000, "Nyetirin angkot dan dapatkan uang!");
    TextDrawLetterSize(JobCenterTD[32], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[32], 527.000, 30.000);
    TextDrawAlignment(JobCenterTD[32], 1);
    TextDrawColor(JobCenterTD[32], -1);
    TextDrawSetShadow(JobCenterTD[32], 1);
    TextDrawSetOutline(JobCenterTD[32], 0);
    TextDrawBackgroundColor(JobCenterTD[32], 0);
    TextDrawFont(JobCenterTD[32], 1);
    TextDrawSetProportional(JobCenterTD[32], 1);

    JobCenterTD[33] = TextDrawCreate(387.000, 265.000, "HUD:radar_gangN");
    TextDrawTextSize(JobCenterTD[33], 8.000, 9.000);
    TextDrawAlignment(JobCenterTD[33], 1);
    TextDrawColor(JobCenterTD[33], -1);
    TextDrawSetShadow(JobCenterTD[33], 0);
    TextDrawSetOutline(JobCenterTD[33], 0);
    TextDrawBackgroundColor(JobCenterTD[33], 255);
    TextDrawFont(JobCenterTD[33], 4);
    TextDrawSetProportional(JobCenterTD[33], 1);

    JobCenterTD[34] = TextDrawCreate(382.000, 292.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[34], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[34], 1);
    TextDrawColor(JobCenterTD[34], 623658239);
    TextDrawSetShadow(JobCenterTD[34], 0);
    TextDrawSetOutline(JobCenterTD[34], 0);
    TextDrawBackgroundColor(JobCenterTD[34], 255);
    TextDrawFont(JobCenterTD[34], 4);
    TextDrawSetProportional(JobCenterTD[34], 1);
    TextDrawSetSelectable(JobCenterTD[34], 1);

    JobCenterTD[35] = TextDrawCreate(399.000, 297.000, "Nelayan");
    TextDrawLetterSize(JobCenterTD[35], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[35], 1);
    TextDrawColor(JobCenterTD[35], -1);
    TextDrawSetShadow(JobCenterTD[35], 1);
    TextDrawSetOutline(JobCenterTD[35], 0);
    TextDrawBackgroundColor(JobCenterTD[35], 0);
    TextDrawFont(JobCenterTD[35], 1);
    TextDrawSetProportional(JobCenterTD[35], 1);

    JobCenterTD[36] = TextDrawCreate(386.000, 308.000, "Ambil kapal dan jala ikan di tengah laut!");
    TextDrawLetterSize(JobCenterTD[36], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[36], 527.000, 30.000);
    TextDrawAlignment(JobCenterTD[36], 1);
    TextDrawColor(JobCenterTD[36], -1);
    TextDrawSetShadow(JobCenterTD[36], 1);
    TextDrawSetOutline(JobCenterTD[36], 0);
    TextDrawBackgroundColor(JobCenterTD[36], 0);
    TextDrawFont(JobCenterTD[36], 1);
    TextDrawSetProportional(JobCenterTD[36], 1);

    JobCenterTD[37] = TextDrawCreate(387.000, 298.000, "HUD:radar_runway");
    TextDrawTextSize(JobCenterTD[37], 8.000, 9.000);
    TextDrawAlignment(JobCenterTD[37], 1);
    TextDrawColor(JobCenterTD[37], -1);
    TextDrawSetShadow(JobCenterTD[37], 0);
    TextDrawSetOutline(JobCenterTD[37], 0);
    TextDrawBackgroundColor(JobCenterTD[37], 255);
    TextDrawFont(JobCenterTD[37], 4);
    TextDrawSetProportional(JobCenterTD[37], 1);

    JobCenterTD[38] = TextDrawCreate(382.000, 325.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[38], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[38], 1);
    TextDrawColor(JobCenterTD[38], 623658239);
    TextDrawSetShadow(JobCenterTD[38], 0);
    TextDrawSetOutline(JobCenterTD[38], 0);
    TextDrawBackgroundColor(JobCenterTD[38], 255);
    TextDrawFont(JobCenterTD[38], 4);
    TextDrawSetProportional(JobCenterTD[38], 1);
    TextDrawSetSelectable(JobCenterTD[38], 1);

    JobCenterTD[39] = TextDrawCreate(399.000, 330.000, "Hauling");
    TextDrawLetterSize(JobCenterTD[39], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[39], 1);
    TextDrawColor(JobCenterTD[39], -1);
    TextDrawSetShadow(JobCenterTD[39], 1);
    TextDrawSetOutline(JobCenterTD[39], 0);
    TextDrawBackgroundColor(JobCenterTD[39], 0);
    TextDrawFont(JobCenterTD[39], 1);
    TextDrawSetProportional(JobCenterTD[39], 1);

    JobCenterTD[40] = TextDrawCreate(386.000, 341.000, "Antar barang dengan truk trailer!");
    TextDrawLetterSize(JobCenterTD[40], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[40], 527.000, 30.000);
    TextDrawAlignment(JobCenterTD[40], 1);
    TextDrawColor(JobCenterTD[40], -1);
    TextDrawSetShadow(JobCenterTD[40], 1);
    TextDrawSetOutline(JobCenterTD[40], 0);
    TextDrawBackgroundColor(JobCenterTD[40], 0);
    TextDrawFont(JobCenterTD[40], 1);
    TextDrawSetProportional(JobCenterTD[40], 1);

    JobCenterTD[41] = TextDrawCreate(387.000, 331.000, "HUD:radar_truck");
    TextDrawTextSize(JobCenterTD[41], 8.000, 9.000);
    TextDrawAlignment(JobCenterTD[41], 1);
    TextDrawColor(JobCenterTD[41], -1);
    TextDrawSetShadow(JobCenterTD[41], 0);
    TextDrawSetOutline(JobCenterTD[41], 0);
    TextDrawBackgroundColor(JobCenterTD[41], 255);
    TextDrawFont(JobCenterTD[41], 4);
    TextDrawSetProportional(JobCenterTD[41], 1);

    JobCenterTD[42] = TextDrawCreate(502.000, 127.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[42], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[42], 1);
    TextDrawColor(JobCenterTD[42], 623658239);
    TextDrawSetShadow(JobCenterTD[42], 0);
    TextDrawSetOutline(JobCenterTD[42], 0);
    TextDrawBackgroundColor(JobCenterTD[42], 255);
    TextDrawFont(JobCenterTD[42], 4);
    TextDrawSetProportional(JobCenterTD[42], 1);
    TextDrawSetSelectable(JobCenterTD[42], 1);

    JobCenterTD[43] = TextDrawCreate(519.000, 132.000, "Porter");
    TextDrawLetterSize(JobCenterTD[43], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[43], 1);
    TextDrawColor(JobCenterTD[43], -1);
    TextDrawSetShadow(JobCenterTD[43], 1);
    TextDrawSetOutline(JobCenterTD[43], 0);
    TextDrawBackgroundColor(JobCenterTD[43], 0);
    TextDrawFont(JobCenterTD[43], 1);
    TextDrawSetProportional(JobCenterTD[43], 1);

    JobCenterTD[44] = TextDrawCreate(506.000, 143.000, "Angkut dan pindahkan barang di dermaga untuk dapatkan uang");
    TextDrawLetterSize(JobCenterTD[44], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[44], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[44], 1);
    TextDrawColor(JobCenterTD[44], -1);
    TextDrawSetShadow(JobCenterTD[44], 1);
    TextDrawSetOutline(JobCenterTD[44], 0);
    TextDrawBackgroundColor(JobCenterTD[44], 0);
    TextDrawFont(JobCenterTD[44], 1);
    TextDrawSetProportional(JobCenterTD[44], 1);

    JobCenterTD[45] = TextDrawCreate(506.000, 129.000, "HUD:radar_MADDOG");
    TextDrawTextSize(JobCenterTD[45], 9.000, 11.000);
    TextDrawAlignment(JobCenterTD[45], 1);
    TextDrawColor(JobCenterTD[45], -1);
    TextDrawSetShadow(JobCenterTD[45], 0);
    TextDrawSetOutline(JobCenterTD[45], 0);
    TextDrawBackgroundColor(JobCenterTD[45], 255);
    TextDrawFont(JobCenterTD[45], 4);
    TextDrawSetProportional(JobCenterTD[45], 1);

    JobCenterTD[46] = TextDrawCreate(502.000, 160.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[46], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[46], 1);
    TextDrawColor(JobCenterTD[46], 623658239);
    TextDrawSetShadow(JobCenterTD[46], 0);
    TextDrawSetOutline(JobCenterTD[46], 0);
    TextDrawBackgroundColor(JobCenterTD[46], 255);
    TextDrawFont(JobCenterTD[46], 4);
    TextDrawSetProportional(JobCenterTD[46], 1);
    TextDrawSetSelectable(JobCenterTD[46], 1);

    JobCenterTD[47] = TextDrawCreate(519.000, 165.000, "Supir Mixer");
    TextDrawLetterSize(JobCenterTD[47], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[47], 1);
    TextDrawColor(JobCenterTD[47], -1);
    TextDrawSetShadow(JobCenterTD[47], 1);
    TextDrawSetOutline(JobCenterTD[47], 0);
    TextDrawBackgroundColor(JobCenterTD[47], 0);
    TextDrawFont(JobCenterTD[47], 1);
    TextDrawSetProportional(JobCenterTD[47], 1);

    JobCenterTD[48] = TextDrawCreate(506.000, 177.000, "Aduk beton dan jaga kualitas slump sampai tujuan!");
    TextDrawLetterSize(JobCenterTD[48], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[48], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[48], 1);
    TextDrawColor(JobCenterTD[48], -1);
    TextDrawSetShadow(JobCenterTD[48], 1);
    TextDrawSetOutline(JobCenterTD[48], 0);
    TextDrawBackgroundColor(JobCenterTD[48], 0);
    TextDrawFont(JobCenterTD[48], 1);
    TextDrawSetProportional(JobCenterTD[48], 1);

    JobCenterTD[49] = TextDrawCreate(506.000, 164.000, "HUD:radar_MCSTRAP");
    TextDrawTextSize(JobCenterTD[49], 8.000, 9.000);
    TextDrawAlignment(JobCenterTD[49], 1);
    TextDrawColor(JobCenterTD[49], -1);
    TextDrawSetShadow(JobCenterTD[49], 0);
    TextDrawSetOutline(JobCenterTD[49], 0);
    TextDrawBackgroundColor(JobCenterTD[49], 255);
    TextDrawFont(JobCenterTD[49], 4);
    TextDrawSetProportional(JobCenterTD[49], 1);

    JobCenterTD[50] = TextDrawCreate(502.000, 193.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[50], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[50], 1);
    TextDrawColor(JobCenterTD[50], 623658239);
    TextDrawSetShadow(JobCenterTD[50], 0);
    TextDrawSetOutline(JobCenterTD[50], 0);
    TextDrawBackgroundColor(JobCenterTD[50], 255);
    TextDrawFont(JobCenterTD[50], 4);
    TextDrawSetProportional(JobCenterTD[50], 1);
    TextDrawSetSelectable(JobCenterTD[50], 1);

    JobCenterTD[51] = TextDrawCreate(519.000, 198.000, "Tukang Kayu");
    TextDrawLetterSize(JobCenterTD[51], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[51], 1);
    TextDrawColor(JobCenterTD[51], -1);
    TextDrawSetShadow(JobCenterTD[51], 1);
    TextDrawSetOutline(JobCenterTD[51], 0);
    TextDrawBackgroundColor(JobCenterTD[51], 0);
    TextDrawFont(JobCenterTD[51], 1);
    TextDrawSetProportional(JobCenterTD[51], 1);

    JobCenterTD[52] = TextDrawCreate(506.000, 209.000, "Ambil kayu dan buatlah papan untuk mendapatkan uang!");
    TextDrawLetterSize(JobCenterTD[52], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[52], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[52], 1);
    TextDrawColor(JobCenterTD[52], -1);
    TextDrawSetShadow(JobCenterTD[52], 1);
    TextDrawSetOutline(JobCenterTD[52], 0);
    TextDrawBackgroundColor(JobCenterTD[52], 0);
    TextDrawFont(JobCenterTD[52], 1);
    TextDrawSetProportional(JobCenterTD[52], 1);

    JobCenterTD[53] = TextDrawCreate(502.000, 226.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[53], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[53], 1);
    TextDrawColor(JobCenterTD[53], 623658239);
    TextDrawSetShadow(JobCenterTD[53], 0);
    TextDrawSetOutline(JobCenterTD[53], 0);
    TextDrawBackgroundColor(JobCenterTD[53], 255);
    TextDrawFont(JobCenterTD[53], 4);
    TextDrawSetProportional(JobCenterTD[53], 1);
    TextDrawSetSelectable(JobCenterTD[53], 1);

    JobCenterTD[54] = TextDrawCreate(519.000, 231.000, "Pelaut");
    TextDrawLetterSize(JobCenterTD[54], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[54], 1);
    TextDrawColor(JobCenterTD[54], -1);
    TextDrawSetShadow(JobCenterTD[54], 1);
    TextDrawSetOutline(JobCenterTD[54], 0);
    TextDrawBackgroundColor(JobCenterTD[54], 0);
    TextDrawFont(JobCenterTD[54], 1);
    TextDrawSetProportional(JobCenterTD[54], 1);

    JobCenterTD[55] = TextDrawCreate(506.000, 242.000, "Bawalah kapal mengarungi laut untuk mendapat uang!");
    TextDrawLetterSize(JobCenterTD[55], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[55], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[55], 1);
    TextDrawColor(JobCenterTD[55], -1);
    TextDrawSetShadow(JobCenterTD[55], 1);
    TextDrawSetOutline(JobCenterTD[55], 0);
    TextDrawBackgroundColor(JobCenterTD[55], 0);
    TextDrawFont(JobCenterTD[55], 1);
    TextDrawSetProportional(JobCenterTD[55], 1);

    JobCenterTD[56] = TextDrawCreate(502.000, 259.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[56], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[56], 1);
    TextDrawColor(JobCenterTD[56], 623658239);
    TextDrawSetShadow(JobCenterTD[56], 0);
    TextDrawSetOutline(JobCenterTD[56], 0);
    TextDrawBackgroundColor(JobCenterTD[56], 255);
    TextDrawFont(JobCenterTD[56], 4);
    TextDrawSetProportional(JobCenterTD[56], 1);
    TextDrawSetSelectable(JobCenterTD[56], 1);

    JobCenterTD[57] = TextDrawCreate(519.000, 264.000, "Peternak");
    TextDrawLetterSize(JobCenterTD[57], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[57], 1);
    TextDrawColor(JobCenterTD[57], -1);
    TextDrawSetShadow(JobCenterTD[57], 1);
    TextDrawSetOutline(JobCenterTD[57], 0);
    TextDrawBackgroundColor(JobCenterTD[57], 0);
    TextDrawFont(JobCenterTD[57], 1);
    TextDrawSetProportional(JobCenterTD[57], 1);

    JobCenterTD[58] = TextDrawCreate(506.000, 275.000, "Peras susu dan jual susu fermentasi!");
    TextDrawLetterSize(JobCenterTD[58], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[58], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[58], 1);
    TextDrawColor(JobCenterTD[58], -1);
    TextDrawSetShadow(JobCenterTD[58], 1);
    TextDrawSetOutline(JobCenterTD[58], 0);
    TextDrawBackgroundColor(JobCenterTD[58], 0);
    TextDrawFont(JobCenterTD[58], 1);
    TextDrawSetProportional(JobCenterTD[58], 1);

    JobCenterTD[59] = TextDrawCreate(502.000, 292.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[59], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[59], 1);
    TextDrawColor(JobCenterTD[59], 623658239);
    TextDrawSetShadow(JobCenterTD[59], 0);
    TextDrawSetOutline(JobCenterTD[59], 0);
    TextDrawBackgroundColor(JobCenterTD[59], 255);
    TextDrawFont(JobCenterTD[59], 4);
    TextDrawSetProportional(JobCenterTD[59], 1);
    TextDrawSetSelectable(JobCenterTD[59], 1);

    JobCenterTD[60] = TextDrawCreate(519.000, 297.000, "Penjahit");
    TextDrawLetterSize(JobCenterTD[60], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[60], 1);
    TextDrawColor(JobCenterTD[60], -1);
    TextDrawSetShadow(JobCenterTD[60], 1);
    TextDrawSetOutline(JobCenterTD[60], 0);
    TextDrawBackgroundColor(JobCenterTD[60], 0);
    TextDrawFont(JobCenterTD[60], 1);
    TextDrawSetProportional(JobCenterTD[60], 1);

    JobCenterTD[61] = TextDrawCreate(506.000, 308.000, "Buat pakaian lalu jual untuk dapat uang!");
    TextDrawLetterSize(JobCenterTD[61], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[61], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[61], 1);
    TextDrawColor(JobCenterTD[61], -1);
    TextDrawSetShadow(JobCenterTD[61], 1);
    TextDrawSetOutline(JobCenterTD[61], 0);
    TextDrawBackgroundColor(JobCenterTD[61], 0);
    TextDrawFont(JobCenterTD[61], 1);
    TextDrawSetProportional(JobCenterTD[61], 1);

    JobCenterTD[62] = TextDrawCreate(502.000, 325.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[62], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[62], 1);
    TextDrawColor(JobCenterTD[62], 623658239);
    TextDrawSetShadow(JobCenterTD[62], 0);
    TextDrawSetOutline(JobCenterTD[62], 0);
    TextDrawBackgroundColor(JobCenterTD[62], 255);
    TextDrawFont(JobCenterTD[62], 4);
    TextDrawSetProportional(JobCenterTD[62], 1);
    TextDrawSetSelectable(JobCenterTD[62], 1);

    JobCenterTD[63] = TextDrawCreate(519.000, 330.000, "Tukang Sawit");
    TextDrawLetterSize(JobCenterTD[63], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[63], 1);
    TextDrawColor(JobCenterTD[63], -1);
    TextDrawSetShadow(JobCenterTD[63], 1);
    TextDrawSetOutline(JobCenterTD[63], 0);
    TextDrawBackgroundColor(JobCenterTD[63], 0);
    TextDrawFont(JobCenterTD[63], 1);
    TextDrawSetProportional(JobCenterTD[63], 1);

    JobCenterTD[64] = TextDrawCreate(506.000, 341.000, "mengambil sawit lalu mengelolah dan jual");
    TextDrawLetterSize(JobCenterTD[64], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[64], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[64], 1);
    TextDrawColor(JobCenterTD[64], -1);
    TextDrawSetShadow(JobCenterTD[64], 1);
    TextDrawSetOutline(JobCenterTD[64], 0);
    TextDrawBackgroundColor(JobCenterTD[64], 0);
    TextDrawFont(JobCenterTD[64], 1);
    TextDrawSetProportional(JobCenterTD[64], 1);

    JobCenterTD[65] = TextDrawCreate(502.000, 359.000, "LD_BUM:blkdot");
    TextDrawTextSize(JobCenterTD[65], 109.000, 30.000);
    TextDrawAlignment(JobCenterTD[65], 1);
    TextDrawColor(JobCenterTD[65], 623658239);
    TextDrawSetShadow(JobCenterTD[65], 0);
    TextDrawSetOutline(JobCenterTD[65], 0);
    TextDrawBackgroundColor(JobCenterTD[65], 255);
    TextDrawFont(JobCenterTD[65], 4);
    TextDrawSetProportional(JobCenterTD[65], 1);
    TextDrawSetSelectable(JobCenterTD[65], 1);

    JobCenterTD[66] = TextDrawCreate(506.000, 364.000, "HUD:radar_propertyR");
    TextDrawTextSize(JobCenterTD[66], 9.000, 9.000);
    TextDrawAlignment(JobCenterTD[66], 1);
    TextDrawColor(JobCenterTD[66], -1);
    TextDrawSetShadow(JobCenterTD[66], 0);
    TextDrawSetOutline(JobCenterTD[66], 0);
    TextDrawBackgroundColor(JobCenterTD[66], 255);
    TextDrawFont(JobCenterTD[66], 4);
    TextDrawSetProportional(JobCenterTD[66], 1);

    JobCenterTD[67] = TextDrawCreate(519.000, 364.000, "Pengangguran");
    TextDrawLetterSize(JobCenterTD[67], 0.187, 0.898);
    TextDrawAlignment(JobCenterTD[67], 1);
    TextDrawColor(JobCenterTD[67], -1);
    TextDrawSetShadow(JobCenterTD[67], 1);
    TextDrawSetOutline(JobCenterTD[67], 0);
    TextDrawBackgroundColor(JobCenterTD[67], 0);
    TextDrawFont(JobCenterTD[67], 1);
    TextDrawSetProportional(JobCenterTD[67], 1);

    JobCenterTD[68] = TextDrawCreate(506.000, 376.000, "Inilah anda di dunia nyata!");
    TextDrawLetterSize(JobCenterTD[68], 0.119, 0.597);
    TextDrawTextSize(JobCenterTD[68], 614.000, 30.000);
    TextDrawAlignment(JobCenterTD[68], 1);
    TextDrawColor(JobCenterTD[68], -1);
    TextDrawSetShadow(JobCenterTD[68], 1);
    TextDrawSetOutline(JobCenterTD[68], 0);
    TextDrawBackgroundColor(JobCenterTD[68], 0);
    TextDrawFont(JobCenterTD[68], 1);
    TextDrawSetProportional(JobCenterTD[68], 1);
}

CreateJobMixTD()
{
	JobMixTD[0] = TextDrawCreate(212.000000, 168.000000, "ld_dual:white");
	TextDrawFont(JobMixTD[0], 4);
	TextDrawLetterSize(JobMixTD[0], 0.600000, 2.000000);
	TextDrawTextSize(JobMixTD[0], 204.000000, 77.000000);
	TextDrawSetOutline(JobMixTD[0], 1);
	TextDrawSetShadow(JobMixTD[0], 0);
	TextDrawAlignment(JobMixTD[0], 1);
	TextDrawColor(JobMixTD[0], 255);
	TextDrawBackgroundColor(JobMixTD[0], 255);
	TextDrawBoxColor(JobMixTD[0], 50);
	TextDrawUseBox(JobMixTD[0], 1);
	TextDrawSetProportional(JobMixTD[0], 1);
	TextDrawSetSelectable(JobMixTD[0], 0);

	JobMixTD[1] = TextDrawCreate(242.000000, 186.000000, "SEMEN");
	TextDrawFont(JobMixTD[1], 1);
	TextDrawLetterSize(JobMixTD[1], 0.261999, 1.350000);
	TextDrawTextSize(JobMixTD[1], 400.000000, 72.000000);
	TextDrawSetOutline(JobMixTD[1], 1);
	TextDrawSetShadow(JobMixTD[1], 0);
	TextDrawAlignment(JobMixTD[1], 2);
	TextDrawColor(JobMixTD[1], -1);
	TextDrawBackgroundColor(JobMixTD[1], 255);
	TextDrawBoxColor(JobMixTD[1], 50);
	TextDrawUseBox(JobMixTD[1], 0);
	TextDrawSetProportional(JobMixTD[1], 1);
	TextDrawSetSelectable(JobMixTD[1], 0);

	JobMixTD[2] = TextDrawCreate(321.000000, 159.000000, "Job Mix");
	TextDrawFont(JobMixTD[2], 0);
	TextDrawLetterSize(JobMixTD[2], 0.425000, 2.249999);
	TextDrawTextSize(JobMixTD[2], 400.000000, 67.000000);
	TextDrawSetOutline(JobMixTD[2], 1);
	TextDrawSetShadow(JobMixTD[2], 0);
	TextDrawAlignment(JobMixTD[2], 2);
	TextDrawColor(JobMixTD[2], -1);
	TextDrawBackgroundColor(JobMixTD[2], 255);
	TextDrawBoxColor(JobMixTD[2], 50);
	TextDrawUseBox(JobMixTD[2], 0);
	TextDrawSetProportional(JobMixTD[2], 1);
	TextDrawSetSelectable(JobMixTD[2], 0);

	JobMixTD[3] = TextDrawCreate(280.000000, 186.000000, "PASIR");
	TextDrawFont(JobMixTD[3], 1);
	TextDrawLetterSize(JobMixTD[3], 0.261999, 1.350000);
	TextDrawTextSize(JobMixTD[3], 400.000000, 72.000000);
	TextDrawSetOutline(JobMixTD[3], 1);
	TextDrawSetShadow(JobMixTD[3], 0);
	TextDrawAlignment(JobMixTD[3], 2);
	TextDrawColor(JobMixTD[3], -1);
	TextDrawBackgroundColor(JobMixTD[3], 255);
	TextDrawBoxColor(JobMixTD[3], 50);
	TextDrawUseBox(JobMixTD[3], 0);
	TextDrawSetProportional(JobMixTD[3], 1);
	TextDrawSetSelectable(JobMixTD[3], 0);

	JobMixTD[4] = TextDrawCreate(317.000000, 186.000000, "KRIKIL~n~1-2");
	TextDrawFont(JobMixTD[4], 1);
	TextDrawLetterSize(JobMixTD[4], 0.261999, 1.350000);
	TextDrawTextSize(JobMixTD[4], 400.000000, 72.000000);
	TextDrawSetOutline(JobMixTD[4], 1);
	TextDrawSetShadow(JobMixTD[4], 0);
	TextDrawAlignment(JobMixTD[4], 2);
	TextDrawColor(JobMixTD[4], -1);
	TextDrawBackgroundColor(JobMixTD[4], 255);
	TextDrawBoxColor(JobMixTD[4], 50);
	TextDrawUseBox(JobMixTD[4], 0);
	TextDrawSetProportional(JobMixTD[4], 1);
	TextDrawSetSelectable(JobMixTD[4], 0);

	JobMixTD[5] = TextDrawCreate(357.000000, 186.000000, "KRIKIL~n~2-3");
	TextDrawFont(JobMixTD[5], 1);
	TextDrawLetterSize(JobMixTD[5], 0.262499, 1.350000);
	TextDrawTextSize(JobMixTD[5], 400.000000, 72.000000);
	TextDrawSetOutline(JobMixTD[5], 1);
	TextDrawSetShadow(JobMixTD[5], 0);
	TextDrawAlignment(JobMixTD[5], 2);
	TextDrawColor(JobMixTD[5], -1);
	TextDrawBackgroundColor(JobMixTD[5], 255);
	TextDrawBoxColor(JobMixTD[5], 50);
	TextDrawUseBox(JobMixTD[5], 0);
	TextDrawSetProportional(JobMixTD[5], 1);
	TextDrawSetSelectable(JobMixTD[5], 0);

	JobMixTD[6] = TextDrawCreate(390.000000, 186.000000, "AIR");
	TextDrawFont(JobMixTD[6], 1);
	TextDrawLetterSize(JobMixTD[6], 0.262499, 1.350000);
	TextDrawTextSize(JobMixTD[6], 400.000000, 72.000000);
	TextDrawSetOutline(JobMixTD[6], 1);
	TextDrawSetShadow(JobMixTD[6], 0);
	TextDrawAlignment(JobMixTD[6], 2);
	TextDrawColor(JobMixTD[6], -1);
	TextDrawBackgroundColor(JobMixTD[6], 255);
	TextDrawBoxColor(JobMixTD[6], 50);
	TextDrawUseBox(JobMixTD[6], 0);
	TextDrawSetProportional(JobMixTD[6], 1);
	TextDrawSetSelectable(JobMixTD[6], 0);

	JobMixTD[7] = TextDrawCreate(212.000000, 251.000000, "ld_dual:white");
	TextDrawFont(JobMixTD[7], 4);
	TextDrawLetterSize(JobMixTD[7], 0.600000, 2.000000);
	TextDrawTextSize(JobMixTD[7], 204.000000, 45.000000);
	TextDrawSetOutline(JobMixTD[7], 1);
	TextDrawSetShadow(JobMixTD[7], 0);
	TextDrawAlignment(JobMixTD[7], 1);
	TextDrawColor(JobMixTD[7], 255);
	TextDrawBackgroundColor(JobMixTD[7], 255);
	TextDrawBoxColor(JobMixTD[7], 50);
	TextDrawUseBox(JobMixTD[7], 1);
	TextDrawSetProportional(JobMixTD[7], 1);
	TextDrawSetSelectable(JobMixTD[7], 0);

	JobMixTD[8] = TextDrawCreate(321.000000, 246.000000, "Batching");
	TextDrawFont(JobMixTD[8], 0);
	TextDrawLetterSize(JobMixTD[8], 0.425000, 2.250000);
	TextDrawTextSize(JobMixTD[8], 69.500000, 52.000000);
	TextDrawSetOutline(JobMixTD[8], 1);
	TextDrawSetShadow(JobMixTD[8], 0);
	TextDrawAlignment(JobMixTD[8], 2);
	TextDrawColor(JobMixTD[8], -1);
	TextDrawBackgroundColor(JobMixTD[8], 255);
	TextDrawBoxColor(JobMixTD[8], 50);
	TextDrawUseBox(JobMixTD[8], 0);
	TextDrawSetProportional(JobMixTD[8], 1);
	TextDrawSetSelectable(JobMixTD[8], 0);

	JobMixTD[9] = TextDrawCreate(294.000000, 309.000000, "KONFIRMASI");
	TextDrawFont(JobMixTD[9], 1);
	TextDrawLetterSize(JobMixTD[9], 0.261999, 1.350000);
	TextDrawTextSize(JobMixTD[9], 351.500000, 13.000000);
	TextDrawSetOutline(JobMixTD[9], 1);
	TextDrawSetShadow(JobMixTD[9], 0);
	TextDrawAlignment(JobMixTD[9], 1);
	TextDrawColor(JobMixTD[9], -1);
	TextDrawBackgroundColor(JobMixTD[9], 255);
	TextDrawBoxColor(JobMixTD[9], -12582657);
	TextDrawUseBox(JobMixTD[9], 1);
	TextDrawSetProportional(JobMixTD[9], 1);
	TextDrawSetSelectable(JobMixTD[9], 1);

	JobMixTD[10] = TextDrawCreate(442.000000, 222.000000, "Slump");
	TextDrawFont(JobMixTD[10], 2);
	TextDrawLetterSize(JobMixTD[10], 0.358333, 2.000000);
	TextDrawTextSize(JobMixTD[10], 486.500000, 17.000000);
	TextDrawSetOutline(JobMixTD[10], 1);
	TextDrawSetShadow(JobMixTD[10], 0);
	TextDrawAlignment(JobMixTD[10], 1);
	TextDrawColor(JobMixTD[10], -1);
	TextDrawBackgroundColor(JobMixTD[10], 255);
	TextDrawBoxColor(JobMixTD[10], 50);
	TextDrawUseBox(JobMixTD[10], 0);
	TextDrawSetProportional(JobMixTD[10], 1);
	TextDrawSetSelectable(JobMixTD[10], 0);
}

CreatePlayerJMixTD(playerid)
{
	pJobMixTD[playerid][0] = CreatePlayerTextDraw(playerid, 242.000000, 218.000000, "1100");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][0], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][0], 400.000000, 72.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][0], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][0], 2);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][0], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][0], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][0], 50);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][0], 0);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][0], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][0], 0);

	pJobMixTD[playerid][1] = CreatePlayerTextDraw(playerid, 280.000000, 218.000000, "234");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][1], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][1], 400.000000, 72.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][1], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][1], 2);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][1], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][1], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][1], 50);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][1], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][1], 0);

	pJobMixTD[playerid][2] = CreatePlayerTextDraw(playerid, 317.000000, 218.000000, "400");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][2], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][2], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][2], 400.000000, 72.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][2], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][2], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][2], 2);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][2], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][2], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][2], 50);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][2], 0);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][2], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][2], 0);

	pJobMixTD[playerid][3] = CreatePlayerTextDraw(playerid, 357.000000, 218.000000, "332");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][3], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][3], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][3], 400.000000, 72.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][3], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][3], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][3], 2);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][3], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][3], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][3], 50);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][3], 0);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][3], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][3], 0);

	pJobMixTD[playerid][4] = CreatePlayerTextDraw(playerid, 390.000000, 218.000000, "762");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][4], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][4], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][4], 400.000000, 72.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][4], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][4], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][4], 2);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][4], -1962934017);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][4], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][4], 50);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][4], 0);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][4], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][4], 0);

	pJobMixTD[playerid][5] = CreatePlayerTextDraw(playerid, 223.000000, 273.000000, "TS");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][5], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][5], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][5], 250.500000, 13.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][5], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][5], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][5], 1);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][5], -1);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][5], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][5], 9109759);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][5], 1);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][5], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][5], 1);

	pJobMixTD[playerid][6] = CreatePlayerTextDraw(playerid, 261.000000, 273.000000, "TP");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][6], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][6], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][6], 288.500000, 13.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][6], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][6], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][6], 1);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][6], -1);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][6], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][6], 9109759);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][6], 1);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][6], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][6], 1);

	pJobMixTD[playerid][7] = CreatePlayerTextDraw(playerid, 299.000000, 273.000000, "TK");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][7], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][7], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][7], 327.000000, 13.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][7], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][7], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][7], 1);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][7], -1);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][7], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][7], 9109759);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][7], 1);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][7], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][7], 1);

	pJobMixTD[playerid][8] = CreatePlayerTextDraw(playerid, 337.000000, 273.000000, "TK2");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][8], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][8], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][8], 365.000000, 13.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][8], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][8], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][8], 1);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][8], -1);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][8], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][8], 9109759);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][8], 1);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][8], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][8], 1);

	pJobMixTD[playerid][9] = CreatePlayerTextDraw(playerid, 376.000000, 273.000000, "TA");
	PlayerTextDrawFont(playerid, pJobMixTD[playerid][9], 1);
	PlayerTextDrawLetterSize(playerid, pJobMixTD[playerid][9], 0.261999, 1.350000);
	PlayerTextDrawTextSize(playerid, pJobMixTD[playerid][9], 404.500000, 13.000000);
	PlayerTextDrawSetOutline(playerid, pJobMixTD[playerid][9], 1);
	PlayerTextDrawSetShadow(playerid, pJobMixTD[playerid][9], 0);
	PlayerTextDrawAlignment(playerid, pJobMixTD[playerid][9], 1);
	PlayerTextDrawColor(playerid, pJobMixTD[playerid][9], -1);
	PlayerTextDrawBackgroundColor(playerid, pJobMixTD[playerid][9], 255);
	PlayerTextDrawBoxColor(playerid, pJobMixTD[playerid][9], 9109759);
	PlayerTextDrawUseBox(playerid, pJobMixTD[playerid][9], 1);
	PlayerTextDrawSetProportional(playerid, pJobMixTD[playerid][9], 1);
	PlayerTextDrawSetSelectable(playerid, pJobMixTD[playerid][9], 1);

	pSlumpMeter[playerid] = CreatePlayerProgressBar(playerid, 432.000000, 243.000000, 72.500000, 6.500000, -1, 100.000000, BAR_DIRECTION_RIGHT);
}

ShowAsuransiTD(const textual[])
{
	TextDrawSetString(InsuVRP[13], textual);

	for(new i = 0; i < 19; i++)
		TextDrawShowForAll(InsuVRP[i]);
}

ShowAnnounceTD(playerid, const descr[])
{
	for(new x; x < 19; x++)
	{
		TextDrawShowForPlayer(playerid, AnnounceTD[x]);
	}
	PlayerTextDrawShow(playerid, pAnnounceTD[playerid]);
	TextDrawSetString(AnnounceTD[9], descr);

	HideServerNameTD(playerid);
}

ShowJobCenterTD(playerid)
{
	HideHBETD(playerid);
	HideRadioVoiceInfoTD(playerid);
	HideServerNameTD(playerid);
	//HideStatsTD(playerid);
	for(new x; x < 69; x++)
	{
		TextDrawShowForPlayer(playerid, JobCenterTD[x]);
	}
}

HideJobCenterTD(playerid)
{
	for(new x; x < 69; x++)
	{
		TextDrawHideForPlayer(playerid, JobCenterTD[x]);
	}

	ShowHBETD(playerid);
	ShowRadioVoiceInfoTD(playerid);
	ShowServerNameTD(playerid);
	//ShowStatsTD(playerid);
	CancelSelectTextDraw(playerid);
}

ShowAreaSantaiTD(playerid)
{
	for(new x; x < 4; x++)
	{
		TextDrawShowForPlayer(playerid, AreaSantaiTD[x]);
	}
}

HideAreaSantaiTD(playerid)
{
	TextDrawHideForPlayer(playerid, AreaSantaiTD[0]);
	TextDrawHideForPlayer(playerid, AreaSantaiTD[1]);
	TextDrawHideForPlayer(playerid, AreaSantaiTD[2]);
	TextDrawHideForPlayer(playerid, AreaSantaiTD[3]);
}