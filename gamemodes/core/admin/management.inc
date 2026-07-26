YCMD:dutyhide(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
		
	if(AccountData[playerid][pHiddenAdmin])
	{
		AccountData[playerid][pHiddenAdmin] = false;
		SendClientMessage(playerid, X11_LIGHTBLUE, "INFO: "WHITE"Status hidden anda telah dicabut.");
	}
	else
	{
		AccountData[playerid][pHiddenAdmin] = true;
		SendClientMessage(playerid, X11_LIGHTBLUE, "INFO: "WHITE"Status hidden anda telah diaktifkan.");
	}
	return 1;
}

YCMD:sann(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	new otherid, msg[64];
	if(sscanf(params, "is[64]", otherid, msg)) return SUM(playerid, "/sann [otherid] [message]");

	if(!IsPlayerConnected(otherid) && !AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Player belum spawn/tidak terkoneksi ke server!");

	GameTextForPlayer(otherid, msg, 5000, 4);
	ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah mengirimkan pesan kepada Pemain tersebut.");
	return 1;
}

YCMD:settime(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	new time;
	if(sscanf(params, "d", time))
		return SUM(playerid, "/time [time ID]");

	static string[144];
	format(string, sizeof(string), "(Server) "WHITE"Pengurus "RED"%s "WHITE"telah mengganti waktu server.", AccountData[playerid][pAdminname]);

	SetWorldTime(time);
	WorldTime = time;
	foreach(new ii : Player)
	{
		SetPlayerTime(ii, time, 0);
		SendClientMessage(ii, Y_SERVER, string);
	}
	return 1;
}

YCMD:setweather(playerid, params[], help)
{
    new weatherid;

    if(AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(sscanf(params, "d", weatherid))
        return SUM(playerid, "/setweather [weather ID]");

    SetWeather(weatherid);
	WorldWeather = weatherid;
	static string[144];
	format(string, sizeof(string), "(Server) "WHITE"Pengurus "RED"%s "WHITE"telah mengganti cuaca server.", AccountData[playerid][pAdminname]);
	foreach(new ii : Player)
	{
		SetPlayerWeather(ii, weatherid);
    	SendClientMessage(ii, Y_SERVER, string);
	}

    return 1;
}

YCMD:setadminname(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
	new aname[128], otherid, query[128];
	if(sscanf(params, "us[128]", otherid, aname))
	   	return SUM(playerid, "/setadminname [ID/Name] [admin name]");
	
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_AdminName`='%e' AND `Char_UCP` != '%e'", aname, AccountData[otherid][pUCP]);
	mysql_pquery(g_SQL, query, "CNAdmName", "iis", otherid, playerid, aname);
	return 1;
}
YCMD:setaname(playerid, params[], help) = setadminname;

YCMD:resetcd(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	new otherid;
	if(sscanf(params, "d", otherid)) return SUM(playerid, "/resetcd [playerid]");

	if(!IsPlayerConnected(otherid) && !AccountData[otherid][pSpawned]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut belum spawn/tidak terkoneksi ke server!");

	AccountData[otherid][pMowingSidejobDelay] = 0;
	AccountData[otherid][pSweeperSidejobDelay] = 0;
	AccountData[otherid][pForkliftSidejobDelay] = 0;
	AccountData[otherid][pPizzaSidejobDelay] = 0;
	AccountData[otherid][pJobKargoBisnisTime] = 0;

	static string[144];
	format(string, sizeof(string), "AdmCmd: %s has reset your character's side job cooldowns.", AccountData[playerid][pAdminname]);
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendAdm(playerid, "You reset the side job cooldowns for %s(%d).", AccountData[otherid][pName], otherid);
	return 1;
}

YCMD:resetcdcarsteal(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	if(g_CarstealCooldown == 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Carsteal tidak dalam masa cooldown!");
	g_CarstealCooldown = 0;

	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset the carsteal cooldown.", AccountData[playerid][pAdminname]);
	return 1;
}

YCMD:resetcdrobbery(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	GM[ShopRobberyCooldown] = 0;

	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset the shop robbery cooldown.", AccountData[playerid][pAdminname]);
	//format(sclstr, sizeof(sclstr), "%s(%d) [%s] used CMD '/resetcdrobbery'", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
	//CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
	return 1;
}

YCMD:setstock(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	new type[24], somt[128];
	if(sscanf(params, "s[24]S()[128]", type, somt))
        return SUM(playerid, "/setstock [name] (komponen)");

	if(!strcmp(type, "komponen", true))
    {
		new value;
		if(sscanf(somt, "d", value))
			return SUM(playerid, "/setstock component [ammount]");

		GM[g_ComponentStock] = value;

		SendAdm(playerid, "You have set Komponen stock to %d.", value);
	}
	return 1;
}

YCMD:backup(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	foreach(new id : FarmPlants) if(id != INVALID_ITERATOR_SLOT)
	{
		FarmPlant_Save(id);
	}
	
	static string[144];
	format(string, sizeof(string), "AdmCmd: %s telah menyimpan semua data server (backup).", AccountData[playerid][pAdminname]);
	
	foreach(new i : Player) if(AccountData[i][pSpawned])
	{
		Anticheat[i][acImmunity] = gettime() + 5;
		UpdateAccountData(i);
		SendClientMessage(i, Y_LIGHTRED, string);
	}
	return 1;
}

YCMD:giveweap(playerid, params[], help)
{
    static
        wgunid,
        typo,
        ammo;

    new otherid;
    
    if(AccountData[playerid][pAdmin] < 5 && AccountData[playerid][pHandleBadside] < 1)
        return PermissionError(playerid);
    
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if (sscanf(params, "uddI(250)", otherid, wgunid, typo, ammo))
        return SUM(playerid, "/givewep [playerid/name] [wgunid] [type: 1. admin, 2. faction, 3. player] [ammo]");

    if (otherid == INVALID_PLAYER_ID)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (wgunid <= 0 || wgunid > 46 || (wgunid >= 19 && wgunid <= 21))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

    if(wgunid == 40 || wgunid == 39) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");
    
    if(typo < 1 || typo > 3) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid type (1 - 3).");
    
    if (ammo < 1 || ammo > 500)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid ammo (1 - 500).");

    if(AccountData[playerid][pAdmin] < 5 && AccountData[playerid][pHandleBadside] >= 1)
    {
        switch(wgunid)
        {
            case 23, 24, 25, 26, 30, 31, 34: {} // allowed
            default: return ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu hanya bisa memberikan senjata: Desert Eagle, Silenced Pistol, Shotgun, AK47, M4, SoS, atau Sniper!");
        }
    }

    if(IsAFireArm(wgunid) && AccountData[otherid][pLevel] < 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut harus mencapai level 5!");

    GivePlayerWeaponEx(otherid, wgunid, ammo, typo);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has given %s a %s with %d rounds.", AccountData[playerid][pAdminname], AccountData[otherid][pName], ReturnWeaponName(wgunid), ammo);

    static string[522];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'giveweap', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
    mysql_pquery(g_SQL, string);
    return 1;
}

YCMD:setvip(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new alevel, dayz, otherid;
    if(sscanf(params, "udd", otherid, alevel, dayz))
        return SUM(playerid, "/setvip [ID/Name] [level 0 - 3] [duration (days) 0 for permanent]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(alevel > 3)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat lebih dari 3!");

    if(alevel < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Level tidak dapat kurang dari 0!");

    if(dayz < 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Durasi tidak dapat kurang dari 0!");

    if(dayz > 60)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Durasi tidak dapat lebih dari 60!");

    if(!AccountData[otherid][IsLoggedIn])
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Player %s(%i) tidak terkoneksi ke server!", AccountData[otherid][pName], otherid));

    AccountData[otherid][pVIP] = alevel;

    static string[144];
	AccountData[otherid][pVIPTime] = gettime() + (dayz * 86400);
	format(string, sizeof(string), "AdmCmd: %s has set your VIP status [ (%s) - %d days ].", AccountData[playerid][pAdminname], GetVIPLevel(otherid), dayz);
	SendClientMessage(otherid, Y_LIGHTRED, string);
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set VIP for %s(%d) for %d days with level %s!", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, dayz, GetVIPLevel(otherid));
    return 1;
}

YCMD:apoint(playerid, params[], help)
{
	static location[2080], lstr[256];
    if (AccountData[playerid][pAdmin] < 5)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	location[0] = EOS;
	strcat(location, "ID\tAdmin Name\tRank\tAdmin Point\n", sizeof(location));

    foreach (new i : Player) if (AccountData[i][pAdmin] >= 1)
	{
		format(lstr,sizeof(lstr), "%d\t%s\t%s\t%d Admin Point\n", i, AccountData[i][pAdminname], GetAdminLevel(i), AccountData[i][pApoint]);
		strcat(location,lstr,sizeof(location));
	}
	Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Admin Point", location, "Tutup", "");
	return 1;
}

YCMD:setkevlar(playerid, params[], help)
{
	new userid, amount;

	if(AccountData[playerid][pAdmin] < 5 && AccountData[playerid][pHandleBadside] < 1)
		return PermissionError(playerid);
	
	if(sscanf(params, "ii", userid, amount))
        return SUM(playerid, "/setkevlar [playerid/Name] [jumlah]");
	
	if(amount < 1 || amount > 25)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah kevlar yang valid 1 - 25!");
	
	if(!IsPlayerConnected(userid))  
	    return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak ada di kota");
	
	Inventory_Add(userid, "Kevlar", 19515, amount);
	ShowItemBox(playerid, "Kevlar", sprintf("Received %dx", amount), 19515, 5);

	SendClientMessageEx(userid, Y_SERVER, "[AdmCmd]"RED" %s"WHITE" memberikan anda Kevlar sejumlah %d", AccountData[playerid][pAdminname], amount);
    SendStaffMessage(Y_SERVER, ""RED"%s"WHITE" memberikan "YELLOW"%s(%d)"WHITE" Kevlar sejumlah %d", AccountData[playerid][pAdminname], AccountData[userid][pName], userid, amount);
	return 1;
}	