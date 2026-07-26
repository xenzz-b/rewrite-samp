YCMD:setlevel(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new amount, otherid;
	if(sscanf(params, "dd", otherid, amount))
        return SUM(playerid, "/setlevel [playerid] [level]");
	
	if(amount < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 1!");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
		
	AccountData[otherid][pLevel] = amount;
	AccountData[otherid][pHours] = (AccountData[otherid][pLevel] - 1)*5;
	AccountData[otherid][pMinutes] = 0;
	AccountData[otherid][pSeconds] = 0;
	
    static string[215];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Level` = %d WHERE `pID` = %d", amount, AccountData[otherid][pID]);
    mysql_pquery(g_SQL, string);

	SetPlayerScore(otherid, amount);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the level of %s to %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], amount);
	format(string, sizeof(string), "AdmCmd: %s has set your character's level to %d.", AccountData[playerid][pAdminname], amount);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	if(amount >= 3)
	{
		AccountData[otherid][pWBTime] = 0;
		HideWargaBaruTD(otherid);
	}
	if(amount <= 3)
	{
		AccountData[otherid][pWBTime] = 21600;
		ShowWargaBaruTD(otherid);
	}

	return 1;
}

YCMD:gethereall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
     	return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	static string[144];
	foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
				if(!OJailData[i][jailed])
				{
					if(!AccountData[i][pArrested])
					{
						SendPlayerToPlayer(i, playerid);
						format(string, sizeof(string), "AdmCmd: %s has teleported all characters to their positions.", AccountData[playerid][pAdminname]);
						SendClientMessage(i, Y_LIGHTRED, string);
					}
				}
            }
        }
    }
	return 1;
}

YCMD:setstressall(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount;
	if(sscanf(params, "d", amount))
        return SUM(playerid, "/setstressall [amount]");
    
	static string[215];
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
				SetPlayerDrunkLevel(i, 0);
                AccountData[i][pStress] = amount;

	            mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Stress` = %d WHERE `pID` = %d", amount, AccountData[i][pID]);
                mysql_pquery(g_SQL, string);

                format(string, sizeof(string), "AdmCmd: %s has set the stress for all characters to %d.", AccountData[playerid][pAdminname], amount);
				SendClientMessage(i, Y_LIGHTRED, string);
            }
        }
    }
    return 1;
}

YCMD:setarmorall(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new Float:amount;
	if(sscanf(params, "f", amount))
        return SUM(playerid, "/setarmorall [amount]");
    
	static string[215];
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
                AccountData[i][pArmor] = amount;

                if(amount > 100)
                {
                    SetPlayerArmourEx(i, 100);
	                mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Armor` = '98' WHERE `pID` = %d", amount, AccountData[i][pID]);
                    mysql_pquery(g_SQL, string);
                }
                else
                {
                    SetPlayerArmourEx(i, amount);
	                mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Armor` = '%.3f' WHERE `pID` = %d", amount, AccountData[i][pID]);
                    mysql_pquery(g_SQL, string);
                }

                format(string, sizeof(string), "AdmCmd: %s has set the armor for all characters to %.2f.", AccountData[playerid][pAdminname], amount);
				SendClientMessage(i, Y_LIGHTRED, string);
            }
        }
    }
    return 1;
}

YCMD:sethbeall(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount;
	if(sscanf(params, "d", amount))
        return SUM(playerid, "/sethbeall [amount]");
    
	static string[215];
    foreach(new i : Player)
    {
        if(IsPlayerConnected(i))
        {
            if(AccountData[i][pSpawned])
            {
                AccountData[i][pHunger] = amount;
	            AccountData[i][pThirst] = amount;
	            mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Hunger` = %d, `Char_Thirst` = %d WHERE `pID` = %d", amount, amount, AccountData[i][pID]);
                mysql_pquery(g_SQL, string);

	            SetPlayerDrunkLevel(i, 0);

                format(string, sizeof(string), "AdmCmd: %s has set the Hunger and Thirst for all characters to %d.", AccountData[playerid][pAdminname], amount);
				SendClientMessage(i, Y_LIGHTRED, string);
            }
        }
    }
    return 1;
}

YCMD:konser(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	Dialog_Show(playerid, "KonserList", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Konser",
	"Mulai Konser\nStop Konser\nSiti Nurbaya\nSeparuh Nafas\nSelir Hati\nSelimut Hati\nSedang Ingin Bercinta\nRoman Picisan\n\
	Risalah Hati\nPupus\nPerempuan Paling Cantik\nPangeran Cinta\nMunajat Cinta\nMadu Tiga\nLaskar Cinta\nKirana\nKangen\nKamulah Surgaku\nKamulah Satu\n\
	Elang\nDewi\nAngin\nAku Milikmu", "Pilih", "Batal");
	return 1;
}

Dialog:KonserList(playerid, response, listitem, inputtext[]) 
{
	if(!response) return 1;

	switch(listitem)
	{
		case 0:
		{
			GM[KonserStarted] = true;
			ShowTDN(playerid, NOTIFICATION_SUCCESS, "Konser dimulai!");
		}
		case 1:
		{
			GM[KonserStarted] = false;
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				StopAudioStreamForPlayer(i);
			}
			ShowTDN(playerid, NOTIFICATION_SUCCESS, "Konser dimulai!");
		}
		case 2:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/siti_nurbaya.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/siti_nurbaya.mp3");
			}
		}
		case 3:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/separuh_nafas.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/separuh_nafas.mp3");
			}
		}
		case 4:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/selir_hati.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/selir_hati.mp3");
			}
		}
		case 5:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/selimut_hati.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/selimut_hati.mp3");
			}
		}
		case 6:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/sedang_ingin.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/sedang_ingin.mp3");
			}
		}
		case 7:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/roman_picisan.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/roman_picisan.mp3");
			}
		}
		case 8:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/risalah_hati.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/risalah_hati.mp3");
			}
		}
		case 9:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/pupus.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/pupus.mp3");
			}
		}
		case 10:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/perempuan_pcdni.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/perempuan_pcdni.mp3");
			}
		}
		case 11:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/pangeran_cinta.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/pangeran_cinta.mp3");
			}
		}
		case 12:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/munajat_cinta.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/munajat_cinta.mp3");
			}
		}
		case 13:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/madu_tiga.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/madu_tiga.mp3");
			}
		}
		case 14:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/laskar_cinta.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/laskar_cinta.mp3");
			}
		}
		case 15:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kirana.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kirana.mp3");
			}
		}
		case 16:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kangen.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kangen.mp3");
			}
		}
		case 17:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kamulah_surgaku.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kamulah_surgaku.mp3");
			}
		}
		case 18:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/kamulah_satu.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/kamulah_satu.mp3");
			}
		}
		case 19:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/elang.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/elang.mp3");
			}
		}
		case 20:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/dewi.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/dewi.mp3");
			}
		}
		case 21:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/angin.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/angin.mp3");
			}
		}
		case 22:
		{
			GM[KonserStarted] = true;
			strcopy(GM[KonserMusicLink], "http://103.178.153.173/dewa/aku_milikmu.mp3");
			foreach(new i : Player) if(IsPlayerInDynamicArea(i, KonserMusicZone))
			{
				PlayAudioStreamForPlayer(i, "http://103.178.153.173/dewa/aku_milikmu.mp3");
			}
		}
	}
	return 1;
}

YCMD:setapprentice(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new app, targetid;
    if (sscanf(params, "dd", targetid, app))
        return SUM(playerid, "/setapprentice [ID/Name] [1 = apply | 0 = remove]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (app < 0 || app > 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya 0 atau 1 yang dapat digunakan!");

    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) tidak terkoneksi ke server!", AccountData[targetid][pName], targetid));

    static string[144];
    if (app == 0)
    {
        AccountData[targetid][pApprentice] = false;
        format(string, sizeof(string), "AdmCmd: %s has removed your apprentice status.", AccountData[playerid][pAdminname]);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s removed apprentice status for %s(%d).", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid);
    }
    else
    {
        AccountData[targetid][pApprentice] = true;
        format(string, sizeof(string), "AdmCmd: %s has appointed you as a apprentice.", AccountData[playerid][pAdminname]);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s appointed %s(%d) as a apprentice!", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid);
    }

    return 1;
}

YCMD:changeplate(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new vid, newplate[64], query[158];
    if(sscanf(params, "ds[64]", vid, newplate))
        return SUM(playerid, "/changeplate [vid] [plate]");

    if(!IsValidVehicle(vid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Vehicle tersebut tidak valid!");

    foreach(new i : PvtVehicles)
    {
        if(PlayerVehicle[i][pVehPhysic] == vid)
        {
            mysql_format(g_SQL, query, sizeof(query), "SELECT `PVeh_Plate` FROM `player_vehicles` WHERE `PVeh_Plate`='%e'", newplate);
            mysql_pquery(g_SQL, query, "ChangeVIPPlate", "ids", playerid, i, newplate);
            return 1;
        }
    }
    ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan tersebut bukan jenis kendaraan pribadi!");
    return 1;
}

YCMD:changeucp(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid, newucp[22], query[158];
    if(sscanf(params, "us[22]", otherid, newucp))
        return SUM(playerid, "/changeucp [playerid] [ucp]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!AccountData[otherid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");

    mysql_format(g_SQL, query, sizeof(query), "SELECT `ucp` FROM `whitelists` WHERE `ucp`='%e'", newucp);
    mysql_pquery(g_SQL, query, "ChangeVIPUCP", "iis", playerid, otherid, newucp);
    return 1;
}

YCMD:reco(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new otherid;
	if(sscanf(params, "i", otherid))
	    return SUM(playerid, "/reco [ID]");

    if(!IsPlayerConnected(otherid) && !AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	
	ResetPlayerMoneyEx(otherid);
	AccountData[otherid][pBankMoney] = 0;
	AccountData[otherid][pCasinoChip] = 0;

	new sqlsdwadkw[128];
	mysql_format(g_SQL, sqlsdwadkw, sizeof(sqlsdwadkw), "UPDATE `player_characters` SET `Char_Money` = 0, `Char_BankMoney` = 0, `Char_CasinoChip` = 0 WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, sqlsdwadkw);
	
	SendAdm(otherid, "%s has reset your character economy!", AccountData[playerid][pAdminname]);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset character economy %s(%d).",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);

	return 1;
}

YCMD:oreco(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
	    return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new player[24], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", player))
		return SUM(playerid, "/oreco [nama]");

	foreach(new ii : Player)
	{
		if(AccountData[ii][IsLoggedIn] && AccountData[ii][pSpawned])
		{
			GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

			if(strfind(PlayerName, player, true) != -1)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/reco' terhadapnya!");
		}
	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "OResetEconomy", "is", playerid, player);
	return 1;
}

YCMD:vcreate(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid, model, counting = 0, Float:pos[4], color1, color2, pvwid, pvintid;
    if (sscanf(params, "uddd", otherid, model, color1, color2))
        return SUM(playerid, "/vcreate [name/playerid] [model] [color1] [color2]");

    if (color1 < 0 || color1 > 255)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan warna kendaraan antara 0-255!");
    if (model < 400 || model > 611)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan model kendaraan antara 400-611!");
    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    foreach(new v : PvtVehicles)
    {
        if (PlayerVehicle[v][pVehOwnerID] == AccountData[otherid][pID])
            counting++;
    }

    if (counting >= GetPlayerVehicleLimit(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah kendaraan pribadi pemain tersebut telah mencapai batas maksimum!");

    GetPlayerPos(otherid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(otherid, pos[3]);
    pvwid = GetPlayerVirtualWorld(otherid);
    pvintid = GetPlayerInterior(otherid);
    Vehicle_Create(otherid, model, pos[0], pos[1], pos[2], pos[3], color1, color2, pvwid, pvintid);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s membuat kendaraan pribadi %s untuk %s.", AccountData[playerid][pAdminname], GetVehicleModelName(model), AccountData[otherid][pName]);

    static string[522];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'vcreate (%s)', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", GetVehicleModelName(model), AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
    return 1;
}

YCMD:osetadminlevel(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    
    if(AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
    
    new targetName[24], alevel;
    if(sscanf(params, "s[24]d", targetName, alevel))
        return SUM(playerid, "/osetadminlevel [Char_Name] [level 0 - 6]");
    
    if(alevel > 6)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 6!");
    
    if(alevel < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");
    
    foreach(new ii : Player)
    {
        if(strcmp(AccountData[ii][pName], targetName, true) == 0)
        {
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player '%s' sedang online! Gunakan /setadminlevel untuk player yang online.", targetName));
        }
    }
    new query[256];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `pID`, `Char_Admin`, `Char_Name`, `Char_AdminHelper`, `Char_AdminVlounter` FROM `player_characters` WHERE `Char_Name` = '%e'", targetName);
    mysql_pquery(g_SQL, query, "OnOSetAdminLevel", "isi", playerid, targetName, alevel);
    return 1;
}

forward OnOSetAdminLevel(adminid, const targetName[], alevel);
public OnOSetAdminLevel(adminid, const targetName[], alevel)
{
    if(!cache_num_rows())
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, sprintf("Pemain dengan nama '%s' tidak ditemukan di database!", targetName));
        return 1;
    }
    
    new targetID, targetAdmin, targetHelper, targetVlounter, targetRealName[24];
    
    cache_get_value_name_int(0, "pID", targetID);
    cache_get_value_name_int(0, "Char_Admin", targetAdmin);
    cache_get_value_name_int(0, "Char_AdminHelper", targetHelper);
    cache_get_value_name_int(0, "Char_AdminVlounter", targetVlounter);
    cache_get_value_name(0, "Char_Name", targetRealName, 24);
    
    if(AccountData[adminid][pAdmin] < targetAdmin && targetAdmin > 0)
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, "Anda tidak dapat set admin yang lebih tinggi dari kamu!");
        return 1;
    }
    
    if(targetHelper >= 1)
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, sprintf("Pemain %s masih berstatus Helper, gunakan /osethehelper terlebih dahulu!", targetRealName));
        return 1;
    }
    
    if(targetVlounter >= 1)
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, sprintf("Pemain %s masih berstatus Vlounter, gunakan /osetvlounter terlebih dahulu!", targetRealName));
        return 1;
    }
    
    new updateQuery[256];
    mysql_format(g_SQL, updateQuery, sizeof(updateQuery), "UPDATE `player_characters` SET `Char_Admin` = %d WHERE `pID` = %d", alevel, targetID);
    mysql_pquery(g_SQL, updateQuery);
    
	new string[256];
    format(string, sizeof(string), "You have set offline player %s's admin level to %d.", targetRealName, alevel);
    ShowTDN(adminid, NOTIFICATION_SUCCESS, string);
    
    new logQuery[256];
    mysql_format(g_SQL, logQuery, sizeof(logQuery), "INSERT INTO `admin_logs` SET `AdminName` = '%e', `Action` = 'osetadminlevel', `Target` = '%e', `Value` = %d, `Time` = NOW()", AccountData[adminid][pAdminname], targetRealName, alevel);
    mysql_pquery(g_SQL, logQuery);
    return 1;
}

YCMD:osethelper(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    
    if(AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
    
    new targetName[24], level;
    if(sscanf(params, "s[24]d", targetName, level))
        return SUM(playerid, "/osethelper [Char_Name] [level 0-1]");
    
    if(level < 0 || level > 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level helper hanya 0 atau 1!");
    
    foreach(new ii : Player)
    {
        if(strcmp(AccountData[ii][pName], targetName, true) == 0)
        {
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player '%s' sedang online! Gunakan /sethelper untuk player yang online.", targetName));
        }
    }
    
    new query[256];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `pID`, `Char_Admin` FROM `player_characters` WHERE `Char_Name` = '%e'", targetName);
    mysql_pquery(g_SQL, query, "OnOSetHelper", "isi", playerid, targetName, level);
    
    return 1;
}

forward OnOSetHelper(adminid, const targetName[], level);
public OnOSetHelper(adminid, const targetName[], level)
{
    if(!cache_num_rows())
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, sprintf("Pemain dengan nama '%s' tidak ditemukan di database!", targetName));
        return 1;
    }
    
    new targetID, targetAdmin;
    
    cache_get_value_name_int(0, "pID", targetID);
    cache_get_value_name_int(0, "Char_Admin", targetAdmin);
    
    if(AccountData[adminid][pAdmin] < targetAdmin && targetAdmin > 0)
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, "Anda tidak dapat set helper ke admin yang lebih tinggi dari kamu!");
        return 1;
    }
    
    new updateQuery[256];
    mysql_format(g_SQL, updateQuery, sizeof(updateQuery), "UPDATE `player_characters` SET `Char_AdminHelper` = %d WHERE `pID` = %d", level, targetID);
    mysql_pquery(g_SQL, updateQuery);
    ShowTDN(adminid, NOTIFICATION_SUCCESS, sprintf("You have set offline player %s's helper level to %d.", targetName, level));
    
    return 1;
}

YCMD:osetvlounter(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    
    if(AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
    
    new targetName[24], level;
    if(sscanf(params, "s[24]d", targetName, level))
        return SUM(playerid, "/osetvlounter [Char_Name] [level 0-1]");
    
    if(level < 0 || level > 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level vlounter hanya 0 atau 1!");
    
    foreach(new ii : Player)
    {
        if(strcmp(AccountData[ii][pName], targetName, true) == 0)
        {
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player '%s' sedang online! Gunakan /setvlounter untuk player yang online.", targetName));
        }
    }
    
    new query[256];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `pID`, `Char_Admin` FROM `player_characters` WHERE `Char_Name` = '%e'", targetName);
    mysql_pquery(g_SQL, query, "OnOSetVlounter", "isi", playerid, targetName, level);
    
    return 1;
}

forward OnOSetVlounter(adminid, const targetName[], level);
public OnOSetVlounter(adminid, const targetName[], level)
{
    if(!cache_num_rows())
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, sprintf("Pemain dengan nama '%s' tidak ditemukan di database!", targetName));
        return 1;
    }
    
    new targetID, targetAdmin;
    
    cache_get_value_name_int(0, "pID", targetID);
    cache_get_value_name_int(0, "Char_Admin", targetAdmin);
    
    if(AccountData[adminid][pAdmin] < targetAdmin && targetAdmin > 0)
    {
        ShowTDN(adminid, NOTIFICATION_ERROR, "Anda tidak dapat set vlounter ke admin yang lebih tinggi dari kamu!");
        return 1;
    }
    
    new updateQuery[256];
    mysql_format(g_SQL, updateQuery, sizeof(updateQuery), "UPDATE `player_characters` SET `Char_AdminVlounter` = %d WHERE `pID` = %d", level, targetID);
    mysql_pquery(g_SQL, updateQuery);
    ShowTDN(adminid, NOTIFICATION_SUCCESS, sprintf("You have set offline player %s's vlounter level to %d.", targetName, level));
    
    return 1;
}

YCMD:setalevel(playerid, params[], help) = setadminlevel;

YCMD:setadminlevel(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new alevel, otherid;
	if(sscanf(params, "ud", otherid, alevel)) return SUM(playerid, "/setadminlevel [ID/Name] [level 0 - 6]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(alevel > 6)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 6!");

	if(alevel < 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

    if (AccountData[playerid][pAdmin] < AccountData[otherid][pAdmin])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat set admin yang lebih tinggi dari kamu!");
	
	if(AccountData[otherid][pAdminHelper] >= 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) masih berstatus Helper, gunakan /sethelper untuk melepas terlebih dahulu!", AccountData[otherid][pName], otherid));

    if(AccountData[otherid][pAdminVlounter] >= 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) masih berstatus Vlounter, gunakan /setvlounter untuk melepas terlebih dahulu!", AccountData[otherid][pName], otherid));

	if(!AccountData[otherid][IsLoggedIn])
		return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) belum login ke server!", AccountData[otherid][pName], otherid));

	AccountData[otherid][pAdmin] = alevel;
	static string[144];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Admin` = %d WHERE `pID` = %d", alevel, AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has set your admin level to %s.", AccountData[playerid][pAdminname], GetAdminLevel(otherid));
	SendClientMessage(otherid, Y_LIGHTRED, string);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the admin level of %s(%d) to %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, alevel);
	return 1;
}

YCMD:sethandle(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) 
        return PermissionError(playerid);

    new otherid, status;
    new type[16], tss[256];

    if(sscanf(params, "us[16]d", otherid, type, status)) 
        return SUM(playerid, "/sethandle [name/playerid] [goodside/badside] [0/1]");

    if(!IsPlayerConnected(otherid)) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(status < 0 || status > 1) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Status hanya boleh 0 atau 1!");

    if(!strcmp(type, "goodside", true))
    {
        AccountData[otherid][pHandleGoodside] = status;

        SendClientMessageEx(otherid, Y_SERVER, "[i] Admin "RED"%s"WHITE" telah menetapkan Handle Goodside anda menjadi %d", AccountData[playerid][pAdminname], status);
        SendStaffMessage(Y_SERVER, ""RED"%s "WHITE"telah menetapkan Handle Goodside kepada "YELLOW"%s(%d) - %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, status);

        mysql_format(g_SQL, tss, sizeof(tss), "UPDATE player_characters SET Char_HandleGoodside=%d WHERE pID=%d", status, AccountData[otherid][pID]);
        mysql_tquery(g_SQL, tss);
    }
    else if(!strcmp(type, "badside", true))
    {
        AccountData[otherid][pHandleBadside] = status;

        SendClientMessageEx(otherid, Y_SERVER, "[i] Admin "RED"%s"WHITE" telah menetapkan Handle Badside anda menjadi %d", AccountData[playerid][pAdminname], status);
        SendStaffMessage(Y_SERVER, ""RED"%s "WHITE"telah menetapkan Handle Badside kepada "YELLOW"%s(%d) - %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, status);

        mysql_format(g_SQL, tss, sizeof(tss), "UPDATE player_characters SET Char_HandleBadside=%d WHERE pID=%d", status, AccountData[otherid][pID]);
        mysql_tquery(g_SQL, tss);
    }
    else
    {
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pilihan hanya 'goodside' atau 'badside'!");
    }
    return 1;
}

YCMD:resetapoint(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid;
    if(sscanf(params, "u", otherid))
        return SUM(playerid, "/resetapoint [playerid id/name]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	AccountData[otherid][pApoint] = 0;

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has reset your point admins.",AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s reset admin point %s (%d).", AccountData[playerid][pAdminname], AccountData[otherid][pAdminname]);
    return 1;
}

YCMD:oresetapoint(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
	    return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new player[24], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", player))
		return SUM(playerid, "/oresetapoint [nama]");

	foreach(new ii : Player)
	{
		if(AccountData[ii][IsLoggedIn] && AccountData[ii][pSpawned])
		{
			GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

			if(strfind(PlayerName, player, true) != -1)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/resetapoint' terhadapnya!");
		}
	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "OResetAdminPoint", "is", playerid, player);
	return 1;
}

YCMD:dynhelp(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
    
    Dialog_Show(playerid, "AdminDynamicHelp", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Dynamic Help", 
    "Dynamic Type\tDescription\n\
    Dynamic Actor\tContains commands related to dynamic actors\n\
    "GRAY"Dynamic Bike Rental\t"GRAY"Contains commands related to dynamic bicycle rentals\n\
    Dynamic Door\tContains commands related to dynamic doors/teleport doors\n\
    "GRAY"Dynamic Fivem Label\t"GRAY"Contains commands related to dynamic FiveM Label text\n\
    Dynamic Garage\tContains commands related to dynamic garages\n\
    "GRAY"Dynamic Garbage\t"GRAY"Contains commands related to dynamic garbage bins\n\
    Dynamic Icon\tContains commands related to dynamic icon\n\
    "GRAY"Dynamic Cannabis\t"GRAY"Contains commands related to dynamic cannabis plants\n\
    Dynamic Robbery\tContains commands related to dynamic shop robberies\n\
    "GRAY"Dynamic Shop\t"GRAY"Contains commands related to dynamic shops\n\
	Dynamic Button\tContains commands related to dynamic door buttons\n\
	"GRAY"Dynamic Rusun\t"GRAY"Contains commands related to dynamic rusun\n\
	Dynamic Gudang\tContains commands related to dynamic gudang", "Pilih", "Batal");
    return 1;
}