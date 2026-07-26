YCMD:kickall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	foreach(new id : FarmPlants) if(id != INVALID_ITERATOR_SLOT)
	{
		FarmPlant_Save(id);
	}
	
	foreach(new pid : Player)
	{
		if(pid != playerid)
		{
			if(AccountData[pid][pKnockdown])
			{
				SetPlayerHealthEx(pid, 100.0);
				AccountData[pid][pKnockdown] = false;
				AccountData[pid][pHunger] = 50;
				AccountData[pid][pThirst] = 50;
				AccountData[pid][pStress] = 0;
			}
			UpdateWeapons(pid);
			UpdateAccountData(pid);
			SendClientMessage(pid, Y_LIGHTRED, "AdmCmd: Maaf, server akan maintenance dan seluruh data telah tersimpan.");
			KickEx(pid);
		}
	}
	
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s used the '/kickall' command.", AccountData[playerid][pAdminname]);
	return 1;
}
YCMD:setmoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new money, otherid;
	if(sscanf(params, "dd", otherid, money))
	    return SUM(playerid, "/setmoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	
	ResetPlayerMoneyEx(otherid);
	GivePlayerMoneyEx(otherid, money);

	static string[144];
	format(string, sizeof(string), "AdmCmd: %s has set your character's money to $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the money of %s to $%s!",  AccountData[playerid][pAdminname], AccountData[otherid][pName], FormatMoney(money));

	return 1;
}

YCMD:setdirtymoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new money, otherid;
	if(sscanf(params, "dd", otherid, money))
	    return SUM(playerid, "/setdirtymoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	
	GivePlayerDirtyMoney(playerid, money);

	static string[144];
	format(string, sizeof(string), "AdmCmd: %s has set your character's dirty money to $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the dirty money of %s to $%s!",  AccountData[playerid][pAdminname], AccountData[otherid][pName], FormatMoney(money));

	return 1;
}

YCMD:givemoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	    return SUM(playerid, "/givemoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	static string[522];
	GivePlayerMoneyEx(otherid, money);

	format(string, sizeof(string), "AdmCmd: %s has given you money in the amount of $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has given money to %s(%d) in the amount of $%s.",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, FormatMoney(money));
	
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'givemoney', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}

YCMD:setbankmoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	    return SUM(playerid, "/setbankmoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	AccountData[otherid][pBankMoney] = money;

	static string[522];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_BankMoney` = %d WHERE `pID` = %d", AccountData[otherid][pBankMoney], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);
	
	format(string, sizeof(string), "AdmCmd: %s has set your character's bank balance to $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the bank balance of %s(%d) to $%s.",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, FormatMoney(money));
	
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'setbankmoney', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}

YCMD:givebankmoney(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new money, otherid;
	if(sscanf(params, "ud", otherid, money))
	    return SUM(playerid, "/givebankmoney [ID/Name] [money]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	AccountData[otherid][pBankMoney] += money;

	static string[522];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_BankMoney` = %d WHERE `pID` = %d", AccountData[otherid][pBankMoney], AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);
	
	format(string, sizeof(string), "AdmCmd: %s has added to your character's bank balance in the amount of $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s added to the bank balance of %s(%d) in the amount of $%s.",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, FormatMoney(money));
	
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'givebankmoney', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}

YCMD:osetbank(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
	    return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new player[24], value, PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "ds[24]", value, player))
		return SUM(playerid, "/osetbank [amount] [name]");

	foreach(new ii : Player)
	{
		GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

	    if(strfind(PlayerName, player, true) != -1)
			return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/setbankmoney' terhadapnya!");
	}

	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "OSetBankMoney", "isd", playerid, player, value);
	return 1;
}

YCMD:setwitch(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new days, targetid;
    if (sscanf(params, "dd", targetid, days))
        return SUM(playerid, "/setwitch [ID/Name] [duration (days) 0 to remove]");

    if (!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (days < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Duration cannot be less than 0!");

    if (!AccountData[targetid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) tidak terkoneksi ke server!", AccountData[targetid][pName], targetid));

    static string[144];
    if (days == 0)
    {
        AccountData[targetid][pWitch] = false;
        AccountData[targetid][pWitchTime] = 0;
        format(string, sizeof(string), "AdmCmd: %s has removed your Witch status.", AccountData[playerid][pAdminname]);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s removed Witch status for %s(%d).", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid);
    }
    else
    {
        AccountData[targetid][pWitch] = true;
        AccountData[targetid][pWitchTime] = gettime() + (days * 86400);
        format(string, sizeof(string), "AdmCmd: %s has appointed you as a Witch for %d days.", AccountData[playerid][pAdminname], days);
        SendClientMessage(targetid, Y_LIGHTRED, string);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s appointed %s(%d) as a Witch for %d days!", AccountData[playerid][pAdminname], AccountData[targetid][pName], targetid, days);
    }

    return 1;
}

YCMD:changephnumber(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid, newphnumb[22], query[158];
    if(sscanf(params, "us[22]", otherid, newphnumb))
        return SUM(playerid, "/changephnumber [playerid] [number]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!AccountData[otherid][pSpawned])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");
    if(!IsNumericEx(newphnumb))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat memuat angka!");
    if(strlen(newphnumb) < 4 || strlen(newphnumb) > 10)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor hanya dapat berjumlah 4 - 10!");

    mysql_format(g_SQL, query, sizeof(query), "SELECT `phoneNumber` FROM `player_phones` WHERE `phoneNumber`='%e'", newphnumb);
    mysql_pquery(g_SQL, query, "ChangeVIPPHNumber", "iis", playerid, otherid, newphnumb);
    return 1;
}

YCMD:changebanknumber(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	new otherid, newbrek[7], query[158];
	if(sscanf(params, "us[7]", otherid, newbrek))
        return SUM(playerid, "/changebanknumber [playerid] [number]");

	if(!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if(!AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn!");
    if(strlen(newbrek) < 4 || strlen(newbrek) > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nomor rekening harus berjumlah 4 - 6 digit!");
	mysql_format(g_SQL, query, sizeof(query), "SELECT `Char_BankNumber` FROM `player_characters` WHERE `Char_BankNumber`=%d", strval(newbrek));
    mysql_pquery(g_SQL, query, "ChangeVIPBankNumber", "iid", playerid, otherid, strval(newbrek));
	return 1;
}

YCMD:givemoneyall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new money;
	if(sscanf(params, "d", money))
	    return SUM(playerid, "/givemoneyall [money]");
	
	static string[144];
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			if(AccountData[i][pSpawned])
			{
				GivePlayerMoneyEx(i, money);
				format(string, sizeof(string), "AdmCmd: %s has given money to all characters in the amount of $%s.", AccountData[playerid][pAdminname], FormatMoney(money));
				SendClientMessage(i, Y_LIGHTRED, string);
			}
		}
	}
	return 1;
}

YCMD:giveweapall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
		
	new weaponid;
	if(sscanf(params, "d", weaponid))
	    return SUM(playerid, "/giveweapall [weapon id]");
	
	if (weaponid <= 0 || weaponid > 46 || (weaponid >= 19 && weaponid <= 21))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

    if(weaponid == 40 || weaponid == 39) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

	static string[144];
	foreach(new i : Player)
	{
		if(IsPlayerConnected(i))
		{
			if(AccountData[i][pSpawned] && AccountData[i][pLevel] >= 5)
			{
				GivePlayerWeaponEx(i, weaponid, 255, WEAPON_TYPE_PLAYER);
			}
			format(string, sizeof(string), "AdmCmd: %s has given %s to all player.", AccountData[playerid][pAdminname], ReturnWeaponName(weaponid));
			SendClientMessage(i, Y_LIGHTRED, string);
		}
	}
	return 1;
}

YCMD:setagirl(playerid, params[], help) = setadmingirl;

YCMD:setadmingirl(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new alevel, otherid;
	if(sscanf(params, "ud", otherid, alevel)) return SUM(playerid, "/setadmingirl [ID/Name] [level 0 - 1]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(alevel > 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 1!");

	if(alevel < 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

	if(!AccountData[otherid][IsLoggedIn])
		return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) belum login ke server!", AccountData[otherid][pName], otherid));

	AccountData[otherid][pAdminGirl] = alevel;
	static string[144];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_AdminGirl` = %d WHERE `pID` = %d", alevel, AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has set your admin girl.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the admin girl of %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:setadmhelper(playerid, params[], help) = sethelper;

YCMD:sethelper(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new alevel, otherid;
	if(sscanf(params, "ud", otherid, alevel)) return SUM(playerid, "/sethelper [ID/Name] [level 0 - 1]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(alevel > 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 1!");

	if(alevel < 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

	if(!AccountData[otherid][IsLoggedIn])
		return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) belum login ke server!", AccountData[otherid][pName], otherid));

	AccountData[otherid][pAdminHelper] = alevel;
	static string[144];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_AdminHelper` = %d WHERE `pID` = %d", alevel, AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has set your admin helper.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the admin helper of %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:setadmvl(playerid, params[], help) = setvlounter;

YCMD:setvlounter(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new alevel, otherid;
	if(sscanf(params, "ud", otherid, alevel)) return SUM(playerid, "/setvlounter [ID/Name] [level 0 - 1]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(alevel > 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 1!");

	if(alevel < 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

	if(!AccountData[otherid][IsLoggedIn])
		return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Pemain %s(%i) belum login ke server!", AccountData[otherid][pName], otherid));

	AccountData[otherid][pAdminVlounter] = alevel;
	static string[144];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_AdminVlounter` = %d WHERE `pID` = %d", alevel, AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	format(string, sizeof(string), "AdmCmd: %s has set your admin vlounter.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the admin vlounter of %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:setapoint(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new amount, otherid;
	if(sscanf(params, "dd", otherid, amount))
        return SUM(playerid, "/setapoint [playerid] [apoint]");

	if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
		
	AccountData[otherid][pApoint] = amount;

	new string[215];
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set the admin point of %s to %d.", AccountData[playerid][pAdminname], AccountData[otherid][pName], amount);
	format(string, sizeof(string), "AdmCmd: %s has set your admin point to %d.", AccountData[playerid][pAdminname], amount);
	SendClientMessage(otherid, Y_LIGHTRED, string);

	return 1;
}

YCMD:schedulemt(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7) return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	static string[144];
	if(!GM[Maintenance])
	{
		new minutes;
		if(sscanf(params, "d", minutes)) return SUM(playerid, "/schedulemt [menit]");

		if(minutes < 2) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal 2 menit!");

		GM[Maintenance] = true;
		GM[MTTime] = gettime() + (minutes * 60);

		format(string, sizeof(string), "[Maintenance] %s telah menjadwalkan maintenance pada %s", AccountData[playerid][pAdminname], ReturnDate(GM[MTTime]));
		SendClientMessageToAll(Y_LIGHTRED, string);
	}
	else
	{
		GM[Maintenance] = false;
		GM[MTTime] = 0;

		format(string, sizeof(string), "[Maintenance] %s telah membatalkan jadwal maintenance, happy roleplay.", AccountData[playerid][pAdminname]);
		SendClientMessageToAll(Y_LIGHTRED, string);
	}
	return 1;
}

YCMD:changemprice(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	ChangeMPrice();
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s used the '/changemprice' command.", AccountData[playerid][pAdminname]);
	return 1;
}

YCMD:okickadmin(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 6)
	    return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new player[24], PlayerName[MAX_PLAYER_NAME];
	if(sscanf(params, "s[24]", player))
		return SUM(playerid, "/okickadmin [nama]");

	foreach(new ii : Player)
	{
		if(AccountData[ii][IsLoggedIn] && AccountData[ii][pSpawned])
		{
			GetPlayerName(ii, PlayerName, MAX_PLAYER_NAME);

			if(strfind(PlayerName, player, true) != -1)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang online, gunakan '/setalevel' terhadapnya!");
		}
	}
	new query[512];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `pID` FROM `player_characters` WHERE `Char_Name`='%e'", player);
	mysql_pquery(g_SQL, query, "oKickAdmin", "is", playerid, player);
	return 1;
}

new bool:g_MappingLoaded = true;
YCMD:reloadmapping(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    SendRconCommand("unloadfs mapping");
    SendRconCommand("loadfs mapping");
    g_MappingLoaded = true;

    SendStaffMessage(Y_SERVER, "(Server) %s telah mereload mapping server.", AccountData[playerid][pAdminname]);
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Mapping berhasil direload!");
    return 1;
}

YCMD:unloadmapping(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(!g_MappingLoaded)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Mapping sudah dalam keadaan unloaded!");

    SendRconCommand("unloadfs mapping");
    g_MappingLoaded = false;

    SendStaffMessage(Y_SERVER, "(Server) %s telah meng-unload mapping server.", AccountData[playerid][pAdminname]);
    return 1;
}

YCMD:loadmapping(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(g_MappingLoaded)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Mapping sudah dalam keadaan loaded!");

    SendRconCommand("loadfs mapping");
    g_MappingLoaded = true;

    SendStaffMessage(Y_SERVER, "(Server) %s telah meng-load mapping server.", AccountData[playerid][pAdminname]);
    return 1;
}

static const AdminLevel[9][] = 
{
	"Bukan Admin",
	"Admin I",
	"Admin II",
	"Admin III",
	"Admin IV",
	"Management",
	"Co Founder",
	"Founder",
	"Scripter"
};


YCMD:adminlist(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 1 && AccountData[playerid][pAdminHelper] < 1 && AccountData[playerid][pAdminVlounter] < 1)
        return PermissionError(playerid);
    
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `Char_Name`, `Char_Admin`, `Char_AdminHelper`, `Char_AdminVlounter`, `Char_AdminDutyHours`, `Char_AdminDutyMinutes`, `Char_LastLogin` FROM `player_characters` WHERE `Char_Admin` > 0 OR `Char_AdminHelper` > 0 OR `Char_AdminVlounter` > 0 ORDER BY `Char_Admin` DESC, `Char_AdminHelper` DESC, `Char_AdminVlounter` DESC");
    mysql_pquery(g_SQL, query, "OnAdminListLoaded", "i", playerid);
    return 1;
}

forward OnAdminListLoaded(playerid);
public OnAdminListLoaded(playerid)
{
    if(!cache_num_rows())
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada admin/staff yang terdaftar di database!");
        return 1;
    }
    
    static dialogString[4096]; // STATIC biar di heap, bukan stack
    static temp[256];
    
    dialogString[0] = EOS;
    strcat(dialogString, "Nama\tJabatan\tStatus\tJam Dinas\tLast Login\n");
    
    for(new i; i < cache_num_rows(); i++)
    {
        new playerName[64], lastLogin[50];
        new adminLevel, helperLevel, vlounterLevel;
        new dutyHours, dutyMinutes;
        
        cache_get_value_name(i, "Char_Name", playerName, 64);
        cache_get_value_name_int(i, "Char_Admin", adminLevel);
        cache_get_value_name_int(i, "Char_AdminHelper", helperLevel);
        cache_get_value_name_int(i, "Char_AdminVlounter", vlounterLevel);
        cache_get_value_name_int(i, "Char_AdminDutyHours", dutyHours);
        cache_get_value_name_int(i, "Char_AdminDutyMinutes", dutyMinutes);
        cache_get_value_name(i, "Char_LastLogin", lastLogin, 50);
        
        new jabatanText[32];
        new statusText[32];
        
        if(adminLevel > 0)
        {
            if(adminLevel >= 0 && adminLevel <= 8)
            {
                format(jabatanText, sizeof(jabatanText), "%s", AdminLevel[adminLevel]);
            }
            else
            {
                format(jabatanText, sizeof(jabatanText), "Admin Lv.%d", adminLevel);
            }
            statusText = "Admin";
        }
        else if(helperLevel > 0)
        {
            jabatanText = "Helper";
            statusText = "Helper";
        }
        else if(vlounterLevel > 0)
        {
            jabatanText = "Vlounter";
            statusText = "Vlounter";
        }
        else
        {
            jabatanText = "Unknown";
            statusText = "Unknown";
        }
        
        new dutyTimeStr[32];
        format(dutyTimeStr, sizeof(dutyTimeStr), "%d jam %d menit", dutyHours, dutyMinutes);
        
        format(temp, sizeof(temp), "%s\t%s\t%s\t%s\t%s\n", playerName, jabatanText, statusText, dutyTimeStr, lastLogin);
        strcat(dialogString, temp, sizeof(dialogString));
    }
    
    Dialog_Show(playerid, "AdminList", DIALOG_STYLE_TABLIST_HEADERS, "Staff List", dialogString, "Close", "");
    
    return 1;
}
YCMD:resetsp(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);
	if(AccountData[playerid][pAdminDuty] == false)
		return PermissionErrorDuty(playerid);

	new otherid;
	if(sscanf(params, "u", otherid))
		return SUM(playerid, "/resetsp [ID/Name]");

	if(!IsPlayerConnected(otherid))
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	if(!AccountData[otherid][IsLoggedIn])
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum login!");

	if(AccountData[otherid][pStarterPack] == 0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum pernah mengambil starterpack!");

	AccountData[otherid][pStarterPack] = 0;

	static string[522];
	mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_ClaimSP` = 0 WHERE `pID` = %d", AccountData[otherid][pID]);
	mysql_pquery(g_SQL, string);

	ShowTDN(otherid, NOTIFICATION_SUCCESS, "Starterpack anda telah direset, silakan ambil kembali!");
	SendClientMessage(otherid, Y_LIGHTRED, "AdmCmd: Starterpack anda telah direset oleh founder, anda dapat mengambilnya kembali.");
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset starterpack for %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);

	mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'resetsp', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
	return 1;
}
