YCMD:areviveall(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    static frmtsql[215];

    foreach (new i : Player)
    {
        if (AccountData[playerid][pSpawned])
        {
            if (AccountData[i][pKnockdown])
            {
                HideKnockTD(i);
                SetPlayerHealthEx(i, 100.0);
                AccountData[i][pKnockdown] = false;
                AccountData[i][pKnockdownTime] = 0;
                AccountData[i][pHunger] = 50;
                AccountData[i][pThirst] = 50;
                AccountData[i][pStress] = 0;

                DeathCause[i][Bruised] = false;
                DeathCause[i][Shoted] = false;
                DeathCause[i][Burns] = false;
                DeathCause[i][Drown] = false;
                DeathCause[i][Fallen] = false;

                mysql_format(g_SQL, frmtsql, sizeof(frmtsql), "UPDATE `player_characters` SET `Char_Knockdown` = 0, `Char_KnockdownTime` = 0, `Char_Hunger` = 50, `Char_Thirst` = 50 WHERE `pID` = %d", AccountData[i][pID]);
                mysql_pquery(g_SQL, frmtsql);

                StopRunningAnimation(i);
            }
            format(frmtsql, sizeof(frmtsql), "AdmCmd: %s has revived all players.", AccountData[playerid][pAdminname]);
            SendClientMessage(i, Y_LIGHTRED, frmtsql);
        }
    }

    return 1;
}

YCMD:sethpall(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new Float:amount;
    if (sscanf(params, "f", amount))
        return SUM(playerid, "/sethpall [amount]");

    static frmtsql[215];
    foreach (new i : Player)
    {
        if (IsPlayerConnected(i))
        {
            if (AccountData[i][pSpawned])
            {
                AccountData[i][pHealth] = amount;

                mysql_format(g_SQL, frmtsql, sizeof(frmtsql), "UPDATE `player_characters` SET `Char_Health` = '%.3f' WHERE `pID` = %d", amount, AccountData[i][pID]);
                mysql_pquery(g_SQL, frmtsql);

                SetPlayerHealthEx(i, amount);

                format(frmtsql, sizeof(frmtsql), "AdmCmd: %s has set the health of all characters to %.2f.", AccountData[playerid][pAdminname], amount);
                SendClientMessage(i, Y_LIGHTRED, frmtsql);
            }
        }
    }

    return 1;
}

YCMD:unban(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new tmp[24];
    if (sscanf(params, "s[24]", tmp))
        return SUM(playerid, "/unban [ban name]");

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `name`,`ip` FROM `player_bans` WHERE `name` = '%e'", tmp);
    mysql_pquery(g_SQL, query, "OnUnbanQueryData", "is", playerid, tmp);
    return 1;
}

YCMD:unblockucp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new ucpname[22];
    if (sscanf(params, "s[22]", ucpname))
        return SUM(playerid, "/unblockucp [UCP name]");

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_ucp` WHERE `UCP` = '%e'", ucpname);
    mysql_pquery(g_SQL, query, "OnUnblockUCP", "is", playerid, ucpname);
    return 1;
}

YCMD:unbanip(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if (isnull(params))
        return SUM(playerid, "/unbanip [IP Address]");

    new mstr[128];
    format(mstr, sizeof(mstr), "unbanip %s", params);
    SendRconCommand(mstr);
    format(mstr, sizeof(mstr), "reloadbans");
    SendRconCommand(mstr);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has unbanned the IP %s.", AccountData[playerid][pAdminname], params);

    return 1;
}

YCMD:setgender(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new targetid, gender;
    if (sscanf(params, "dd", targetid, gender))
        return SUM(playerid, "/setgender [playerid] [1. Male | 2. Female]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    
    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[targetid][pGender] = gender;
    SendClientMessageEx(targetid, Y_LIGHTRED, "AdmCmd: %s has set your character gender.", AccountData[playerid][pAdminname]);
    SendAdm(playerid, "You have set %s(%d) gender to %d", AccountData[targetid][pName], targetid, gender);
    return 1;
}

YCMD:setfaction(playerid, params[], help)
{
	new fid, rank, otherid;
    if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleGoodside] < 1)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(sscanf(params, "udd", otherid, fid, rank))
    {
		SUM(playerid, "/setfaction [playerid] [faction id] [rank] faction ID 0 untuk Kick");
        SUM(playerid, "1.Polisi, 2.Paramedis, 3.Pring Sewu(Resto), 4.Pemerintah, 5.Benny Automotive(Bengkel), 6.Uber, 7.Pinky Tiger Club");
        SUM(playerid, "8.Pewarta Berita, 9.DriftKing(Bengkel), 10.Jaya Abadi(Bengkel), 11.Sri Mersing(Resto)");
        return 1;
    }

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(fid < 0 || fid > MAX_FACTIONS - 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid faction ID!");

	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleGoodside] >= 1)
	{
		if(fid != 0 && fid != 1 && fid != 2 && fid != 4 && fid != 5 && fid != 8)
		{
			return ShowTDN(playerid, NOTIFICATION_ERROR, "Handle Goodside hanya bisa set faction: Pemerintah, Polisi, Medic, SANews, Bennys!");
		}
		
		// Handle Goodside hanya bisa set rank 1-3
		if(fid != 0 && (rank < 1 || rank > 3))
		{
			return ShowTDN(playerid, NOTIFICATION_ERROR, "Handle Goodside hanya bisa set rank 1-3!");
		}
	}
	switch(fid)
	{
		case 0:
		{
			if(rank != 0)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Set rank 0 untuk mengeluarkan player dari faction!");
		}
		case 1: //polda
		{
			if(rank < 1 || rank > 20)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Polisi valid rank is 1- 20.");
		}
		case 2: //LSFD
		{
			if(rank < 1 || rank > 8)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Paramedis valid rank is 1 - 8!");
		}
		case 3: //Burgershot
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pring Sewu valid rank is 1 - 10!");
		}
		case 4: //government
		{
			if(rank < 1 || rank > 7)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemerintah valid rank is 1- 7.");
		}
		case 5: //bennys
		{
			if(rank < 1 || rank > 6)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Bennys valid rank is 1 - 6!");
		}
		case 6: //Uber
		{
			if(rank < 1 || rank > 5)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Uber valid rank is 1 - 5!");
		}
		case 7: //dinarbucks
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pinky Tiger valid rank is 1 - 10!");
		}
		case 8: //fox 11
		{
			if(rank < 1 || rank > 8)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pewarta valid rank is 1 - 8!");
		}
        case 9: //DriftKing
		{
			if(rank < 1 || rank > 6)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "DriftKing valid rank is 1 - 6!");
		}
        case 10: //jaya abadi
		{
			if(rank < 1 || rank > 6)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Jaya Abadi valid rank is 1 - 6!");
		}
        case 11: //sri mersing
		{
			if(rank < 1 || rank > 10)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Sri Mersing valid rank is 1 - 10!");
		}
	}

	static string[158];
	if(fid == 0)
	{
		AccountData[otherid][pFaction] = 0;
		AccountData[otherid][pFactionRank] = 0;
		AccountData[otherid][pBadge] = 0;
		format(string, sizeof(string), "AdmCmd: %s has removed you from the faction.", AccountData[playerid][pAdminname]);
		SendClientMessage(otherid, Y_LIGHTRED, string);
	}
	else
	{
		AccountData[otherid][pFaction] = fid;
		AccountData[otherid][pFactionRank] = rank;
	}
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Faction` = %d, `Char_FactionRank` = %d WHERE `pID` = %d", AccountData[otherid][pFaction], AccountData[otherid][pFactionRank], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has assigned you to the faction %s with rank %s.", AccountData[playerid][pAdminname], GetFactionName(otherid), GetRankName(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have assigned %s(%d) to the %s faction with rank %s.", AccountData[otherid][pName], otherid, GetFactionName(otherid), GetRankName(otherid));
    
	return 1;
}

YCMD:setmarga(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new otherid, fmid, frank;
	if(sscanf(params, "udd", otherid, fmid, frank)) return SUM(playerid, "/setmarga [playerid] [marga id] [rank 1 - 5]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!Iter_Contains(Margas, fmid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Marga ID!");
	if(frank < 1 || frank > 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Rank hanya dapat diisi 1 atau 5!");

	AccountData[otherid][pMarga] = fmid;
	AccountData[otherid][pMargaRank] = frank;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Marga` = %d, `Char_MargaRank` = %d WHERE `pID` = %d", AccountData[otherid][pMarga], AccountData[otherid][pMargaRank], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has assigned you to the Marga %s with rank %s.", AccountData[playerid][pAdminname], GetMargaName(fmid), GetMargaRankName(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have assigned %s(%d) to the %s Marga with rank %s.", AccountData[otherid][pName], otherid, GetMargaName(fmid), GetMargaRankName(otherid));
	return 1;
}

YCMD:akickmarga(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid)) return SUM(playerid, "/akickmarga [playerid]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(AccountData[otherid][pMarga] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut bukan anggota dari Marga manapun!");

	AccountData[otherid][pMarga] = -1;
	AccountData[otherid][pMargaRank] = 0;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Marga` = -1, `Char_MargaRank` = 0,  WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has removed you from the Marga.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have removed %s(%d) from the Marga.", AccountData[otherid][pName], otherid);
	return 1;
}


YCMD:setjdm(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new otherid, fmid, frank;
	if(sscanf(params, "udd", otherid, fmid, frank)) return SUM(playerid, "/setjdm [playerid] [jdm id] [rank 1 - 5]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!Iter_Contains(JDMs, fmid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid jdm ID!");
	if(frank < 1 || frank > 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Rank hanya dapat diisi 1 atau 5!");

	AccountData[otherid][pJDM] = fmid;
	AccountData[otherid][pJDMRank] = frank;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_JDM` = %d, `Char_JDMRank` = %d WHERE `pID` = %d", AccountData[otherid][pJDM], AccountData[otherid][pJDMRank], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has assigned you to the JDM %s with rank %s.", AccountData[playerid][pAdminname], GetJDMName(fmid), GetJdmRankName(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have assigned %s(%d) to the %s JDM with rank %s.", AccountData[otherid][pName], otherid, GetJDMName(fmid), GetJdmRankName(otherid));
	return 1;
}

YCMD:kickjdm(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid)) return SUM(playerid, "/kickjdm [playerid]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(AccountData[otherid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut bukan anggota dari JDM official manapun!");

	AccountData[otherid][pJDM] = -1;
	AccountData[otherid][pJDMRank] = 0;
    AccountData[playerid][pJDMPoints] = 0;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_JDM` = -1, `Char_JDMRank` = 0, `Char_JDMPoints` = 0 WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has removed you from the JDM.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have removed %s(%d) from the JDM.", AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:setfamily(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);

    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new otherid, fmid, frank;
	if(sscanf(params, "udd", otherid, fmid, frank)) return SUM(playerid, "/setfamily [playerid] [family id] [rank 1 - 4]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!Iter_Contains(Fams, fmid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid family ID!");
	if(frank < 1 || frank > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Rank hanya dapat diisi 1 atau 6!");

	AccountData[otherid][pFamily] = fmid;
	AccountData[otherid][pFamilyRank] = frank;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Family` = %d, `Char_FamilyRank` = %d WHERE `pID` = %d", AccountData[otherid][pFamily], AccountData[otherid][pFamilyRank], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has assigned you to the family %s with rank %s.", AccountData[playerid][pAdminname], GetFamilyName(fmid), GetFamilyRankName(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have assigned %s(%d) to the %s family with rank %s.", AccountData[otherid][pName], otherid, GetFamilyName(fmid), GetFamilyRankName(otherid));
	return 1;
}

YCMD:kickfamily(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 4 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new otherid;
	if(sscanf(params, "u", otherid)) return SUM(playerid, "/kickfamily [playerid]");
	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(AccountData[otherid][pFamily] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut bukan anggota dari family official manapun!");

	AccountData[otherid][pFamily] = -1;
	AccountData[otherid][pFamilyRank] = 0;

	static string[158];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Family` = -1, `Char_FamilyRank` = 0 WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has removed you from the family.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	SendAdm(playerid, "You have removed %s(%d) from the family.", AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:akill(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	new otherid;
	if(sscanf(params, "d", otherid))
	    return SUM(playerid, "/akill [ID]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	SetPlayerHealth(otherid, 0.0);

	SendAdm(playerid, "You have forcely killed %s(%d).", AccountData[otherid][pName], otherid);

	return 1;
}

YCMD:setname(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new targetid;
    if (sscanf(params, "d", targetid))
        return SUM(playerid, "/setname [ID/Name]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    
    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[playerid][pTempSQLFactMemberID] = targetid;
    Dialog_Show(playerid, "AdmSetName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Change Name", ""WHITE"Mohon masukkan nama baru karakter di bawah ini (Kultur Server ini adalah Indonesia)\n\
    Nama bisa apa saja asalkan tidak mengandung kata kotor, singkatan, atau nama publik figur/terkenal\n\n\
    Contoh nama yang baik: Asep_Sutanto, Christina_Agnes, Iskak_Syueb, Fadil_Siregar:", "Input", "Kembali");

    return 1;
}

YCMD:oban(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new player[24], datez, reason[64];
    if (sscanf(params, "s[24]D(0)s[64]", player, datez, reason))
        return SUM(playerid, "/oban [Char_Name] [days (0 for permanent ban)] [reason]");

    if (strlen(reason) > 32) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimum reason adalah 32 karakter!");

    foreach (new ii : Player)
    {
        new PlayerName[24];
        GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

        if (strfind(PlayerName, player, true) != -1)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/ban'.");
    }

    new query[128];

    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_Name`='%e'", player);
    mysql_pquery(g_SQL, query, "OnOBanQueryData", "issi", playerid, player, reason, datez);
    return true;
}

YCMD:banip(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new iptoban[17];

    if (sscanf(params, "s[17]", iptoban))
        return SUM(playerid, "/banip [IP Address]");

    if(strfind(iptoban, "*", true) != -1 && AccountData[playerid][pAdmin] != 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat ban range IP!");

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s banned IP Address %s.", AccountData[playerid][pAdminname], iptoban);

    new tstr[128];
    format(tstr, sizeof(tstr), "banip %s", iptoban);
    SendRconCommand(tstr);
    return 1;
}

YCMD:blockucp(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new nameucp[22], haridur, reasonblock[60], totalblockdur;
    if (sscanf(params, "s[22]ds[60]", nameucp, haridur, reasonblock))
        return SUM(playerid, "/blockucp [UCP name] [duration (days) 0 for permanent] [reason]");

    if (haridur < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan durasi yang valid!");

    if (strlen(reasonblock) > 60) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimum reason adalah 60 karakter!");

    if (haridur != 0)
    {
        totalblockdur = gettime() + (haridur * 86400);
    }
    else
    {
        totalblockdur = haridur;
    }

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_ucp` WHERE `UCP` = '%e'", nameucp);
    mysql_pquery(g_SQL, query, "OnBlockingUCP", "isdds", playerid, nameucp, totalblockdur, haridur, reasonblock);
    return 1;
}
YCMD:reloadweap(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid;
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/reloadweps [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    SetWeapons(otherid);

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has reloaded your weapons.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendAdm(playerid, "You have reloaded weapons for %s(%d).", AccountData[otherid][pName], otherid);

    return 1;
}

CMD:arelease(playerid, params[])
{
    if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);

    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid;
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/reloadweps [playerid]");

	if(AccountData[otherid][pArrested] == false)
	    return ShowTDN(playerid, NOTIFICATION_ERROR, "Player tersebut sedang tidak dalam penjara");

	AccountData[otherid][pArrested] = false;
	AccountData[otherid][pArrestTime] = 0;
	SetPlayerInterior(otherid, 0);
	SetPlayerVirtualWorld(otherid, 0);
	SetPlayerPositionEx(otherid, 635.2431,-569.8725,16.3359,275.3058);
	SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
    static string[144];
    format(string, sizeof(string), "AdmCmd: %s mengeluarkan anda dari penjara.",AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengeluarkan %s dari penjara.", AccountData[playerid][pAdminname], AccountData[otherid][pName]);
    return 1;
}

YCMD:p2p(playerid, params[], help)
{
	new otherid, toother;

	if (AccountData[playerid][pAdmin] < 4)
        return PermissionError(playerid);
	
	if(sscanf(params, "uu", otherid, toother)) return SUM(playerid, "/p2p [playerid/Name] to [playerid/name]");
	if(!IsPlayerConnected(otherid)) return ShowTDN (playerid, NOTIFICATION_ERROR, "Pemain yg ingin dikirim tidak terkoneksi kedalam server!");
	if(!IsPlayerConnected(toother)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain yg ingin dituju tidak terkoneksi kedalam server!");
	static Float:tX, Float:tY, Float:tZ;
	GetPlayerPos(toother, tX, tY, tZ);

	SetPlayerPositionEx(otherid, tX, tY, tZ, 1000);
	SendClientMessageEx(otherid, Y_SERVER, "AdmCmd: %s mengirimkan anda kepada %s(%d)", AccountData[playerid][pAdminname], AccountData[toother][pName], toother);
	SendStaffMessage(Y_LIGHTRED, "%s Mengirimkan %s(%d) kepada %s(%d)", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, AccountData[toother][pName], toother);
	return 1;
}