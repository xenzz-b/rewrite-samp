YCMD:sanmode(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 8)
        return PermissionError(playerid);
	
	switch(AccountData[playerid][pAdminDuty])
    {
		case false:
		{
			AccountData[playerid][pAdminDuty] = true;

        }
        case true:
        {
            AccountData[playerid][pAdminDuty] = false;
        }
    }
	return 1;
}

YCMD:sansethp(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 8)
        return PermissionError(playerid);

    new Float:amount, otherid;
    if(sscanf(params, "uf", otherid, amount))
        return SUM(playerid, "/sethp [playerid id/name] <amount>");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    SetPlayerHealthEx(otherid, amount);
    return 1;
}

YCMD:sansetarmor(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 8)
        return PermissionError(playerid);

    new Float:amount, otherid;
    if (sscanf(params, "uf", otherid, amount))
        return SUM(playerid, "/setam [playerid id/name] <amount>");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (amount > 100.0)
    {
        SetPlayerArmourEx(otherid, 100.0);
    }
    else
    {
        SetPlayerArmourEx(otherid, amount);
    }
    return 1;
}

YCMD:sansetitem(playerid, params[], help)
{
	new
		targetid,
		item[32],
		amount;

	if(AccountData[playerid][pAdmin] < 8) return PermissionError(playerid);

	if(sscanf(params, "ids[32]", targetid, amount, item))
	    return SUM(playerid, "/asetitem [playerid] [amount] [item name]");

	if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

	for(new i = 0; i < sizeof(g_aInventoryItems); i++) if(!strcmp(g_aInventoryItems[i][e_InventoryItem], item, true))
	{
		new Float:countingtotalweight;
		countingtotalweight = GetTotalWeightFloat(targetid) + float(amount * GetItemWeight(g_aInventoryItems[i][e_InventoryItem]))/1000;
		if(countingtotalweight > GetPlayerInventoryWeight(playerid)) return ShowTDN(playerid, NOTIFICATION_WARNING, "Inventory pemain tersebut telah penuh");

		Inventory_Set(targetid, g_aInventoryItems[i][e_InventoryItem], g_aInventoryItems[i][e_InventoryModel], amount);

		SendClientMessageEx(playerid, 0xFF00FFAA, "[Server] You have set %d %s to %s", amount, g_aInventoryItems[i][e_InventoryItem], AccountData[targetid][pName]);
		
		return 1;
	}
	ShowTDN(playerid, NOTIFICATION_WARNING, "Nama item tidak valid!");
	return 1;
}

YCMD:sanweap(playerid, params[], help)
{
    static
        wgunid,
        typo,
        ammo;

    new otherid;
    if (AccountData[playerid][pAdmin] < 8)
        return PermissionError(playerid);

    if (sscanf(params, "uddI(250)", otherid, wgunid, typo, ammo))
        return SUM(playerid, "/givewep [playerid/name] [wgunid] [type: 1. admin, 2. faction, 3. player] [ammo]");

    if (otherid == INVALID_PLAYER_ID)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (wgunid <= 0 || wgunid > 46 || (wgunid >= 19 && wgunid <= 21))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");

    if(wgunid == 40 || wgunid == 39) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid weapon ID!");
    
    if(typo < 1 || typo > 3) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid type (1 - 3).");
    
    if (ammo < 1 || ammo > 500)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid ammo (1 - 500).");

    if(IsAFireArm(wgunid) && AccountData[otherid][pLevel] < 5)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut harus mencapai level 5!");

    GivePlayerWeaponEx(otherid, wgunid, ammo, typo);

    static string[522];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `admin_logs` SET `Prefix` = 'giveweap', `Admin` = '%e', `AdminUCP` = '%e', `UCPTarget` = '%e'", AccountData[playerid][pAdminname], AccountData[playerid][pUCP], AccountData[otherid][pName]);
	mysql_pquery(g_SQL, string);
    return 1;
}

YCMD:modesan(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);

	SetPlayerAttachedObject(playerid, 0, 3524, 2, -0.6118, -0.1457, 0.0049, 88.3999, 104.4999, 91.9000, 0.2619, 0.3898, 0.3030, 0xFFF8F8FF, 0x00FFEBCD); // skull
	SetPlayerAttachedObject(playerid, 1, 3065, 2, -0.0178, 0.0178, 0.0000, 0.0000, 0.0000, 0.0000, 1.2318, 0.9448, 0.7649, 0xFF000000, 0xFFFFFFFF); // hide head
	SetPlayerAttachedObject(playerid, 2, 2680, 1, 0.0908, 0.0370, -0.2398, 99.1997, 76.1996, -4.3000, 1.1940, 1.3848, 1.7238, 0x00FF0000, 0x00FFEBCD); // chain
	SetPlayerAttachedObject(playerid, 3, 2899, 1, 0.2890, -0.0139, -0.0090, 91.4999, 91.9000, -0.3999, 0.1049, 0.0920, 0.5699, 0xFF2F4F4F, 0xFFFFFFFF); // jacket spikes
	SetPlayerAttachedObject(playerid, 8, 18693, 2, -1.6398, 0.1248, 0.0159, 0.0000, 90.5998, 0.0000, 1.0000, 1.0000, 1.0000, 0xFFFFFFFF, 0xFFFFFFFF); // skull flame
	return 1;
}

YCMD:akudj(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
		return PermissionError(playerid);

    AccountData[playerid][pDj] = 1;
	return 1;
}
