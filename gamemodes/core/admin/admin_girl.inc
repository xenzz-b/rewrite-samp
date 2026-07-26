/*YCMD:setbenefitgirl(playerid, params[], help)
{

    if (AccountData[playerid][pAdmin] < 5 && AccountData[playerid][pAdminGirl] < 1)
        return PermissionError(playerid);

    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
    new Float:pos[4], otherid, pvwid, pvintid;
    if(sscanf(params, "d", otherid))
        return SUM(playerid, "/setbenefitgirl [playerid]");
	
    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(AccountData[otherid][pGender] == 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut bukan perempuan!");

    if(AccountData[otherid][pClaimGirl] == 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah pernah claim benefit girl!");
		
    AccountData[otherid][pLevel] += 3;
    AccountData[otherid][pHours] = (AccountData[otherid][pLevel] - 1) * 3;
    AccountData[otherid][pMinutes] = 0;
    AccountData[otherid][pSeconds] = 0;
    SetPlayerScore(otherid, 3);

    GetPlayerPos(otherid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(otherid, pos[3]);
    pvwid = GetPlayerVirtualWorld(otherid);
    pvintid = GetPlayerInterior(otherid);
    Vehicle_Create(otherid, 500, pos[0], pos[1], pos[2], pos[3], 1, 1, pvwid, pvintid);

    AccountData[otherid][pVIP] = 2;
    AccountData[otherid][pVIPTime] = gettime() + (7 * 86400);

    AccountData[otherid][pClaimGirl] = 1;

    new string[215];
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set benefit girl to %s.", AccountData[playerid][pAdminname], AccountData[otherid][pName]);
    format(string, sizeof(string), "AdmCmd: %s has set your benefit girl you.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    return 1;
}
*/

YCMD:setbenefitgirl(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 5 && AccountData[playerid][pAdminGirl] < 1)
        return PermissionError(playerid);
        
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
    new Float:pos[4], otherid, pvwid, pvintid, type;
    if(sscanf(params, "dd", otherid, type))
        return SUM(playerid, "/setbenefitgirl [playerid] [type 1-2]");
	
    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    
    if(type < 1 || type > 2)
        return SUM(playerid, "/setbenefitgirl [playerid] [type 1-2]");

    if(AccountData[otherid][pGender] == 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut bukan perempuan!");

    if(AccountData[otherid][pClaimGirl] == 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah pernah claim benefit girl!");

    GetPlayerPos(otherid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(otherid, pos[3]);
    pvwid = GetPlayerVirtualWorld(otherid);
    pvintid = GetPlayerInterior(otherid);
    
    if(type == 1)
    {
        GivePlayerMoneyEx(otherid, 25000);
        AccountData[otherid][pVIP] = 1;
        AccountData[otherid][pVIPTime] = gettime() + (3 * 86400);
        Inventory_Add(otherid, "Ticket Gacha", 962, 5);
        ShowItemBox(otherid, "Ticket Gacha", "Received 5x", 962, 5);
        Vehicle_Create(otherid, 429, pos[0], pos[1], pos[2], pos[3], 126, 126, pvwid, pvintid); // Banshee
        SendClientMessageEx(otherid, Y_SERVER, "Anda menerima benefit girl type 1, dan mendapatkan uang sebesar "GREEN"$25.000, "YELLOW"Vip 1 3 day");
        SendClientMessageEx(otherid, Y_SERVER, "Ticket Gacha "YELLOW"5x, "WHITE"kendaraan "YELLOW"Banshee");
    }
    else if(type == 2)
    {
        GivePlayerMoneyEx(otherid, 25000);
        AccountData[otherid][pVIP] = 1;
        AccountData[otherid][pVIPTime] = gettime() + (3 * 86400);
        Inventory_Add(otherid, "Ticket Gacha", 962, 5);
        ShowItemBox(otherid, "Ticket Gacha", "Received 5x", 962, 5);
        Vehicle_Create(otherid, 480, pos[0], pos[1], pos[2], pos[3], 126, 126, pvwid, pvintid); // Comet
        SendClientMessageEx(otherid, Y_SERVER, "Anda menerima benefit girl type 2, dan mendapatkan uang sebesar "GREEN"$25.000, "YELLOW"Vip 1 3 day");
        SendClientMessageEx(otherid, Y_SERVER, "Ticket Gacha "YELLOW"5x, "WHITE"kendaraan "YELLOW"Comet");
    }

    AccountData[otherid][pClaimGirl] = 1;
    SendStaffMessage(Y_SERVER, "AdmCmd: %s has set benefit girl type %d to %s.", AccountData[playerid][pAdminname], type, AccountData[otherid][pName]);
    return 1;
}

YCMD:setbenefitgoodside(playerid, params[], help)
{

    if (AccountData[playerid][pAdmin] < 5 && AccountData[playerid][pHandleGoodside] < 1)
        return PermissionError(playerid);

    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
	
    new Float:pos[4], otherid, pvwid, pvintid;
    if(sscanf(params, "d", otherid))
        return SUM(playerid, "/setbenefitgoodside [playerid]");
	
    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(AccountData[otherid][pClaimGoodside] == 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sudah pernah claim benefit goodside!");
		
    AccountData[otherid][pLevel] += 3;
    AccountData[otherid][pHours] = (AccountData[otherid][pLevel] - 1) * 3;
    AccountData[otherid][pMinutes] = 0;
    AccountData[otherid][pSeconds] = 0;
    SetPlayerScore(otherid, 3);
    GivePlayerMoneyEx(playerid, 5000);

    GetPlayerPos(otherid, pos[0], pos[1], pos[2]);
    GetPlayerFacingAngle(otherid, pos[3]);
    pvwid = GetPlayerVirtualWorld(otherid);
    pvintid = GetPlayerInterior(otherid);
    Vehicle_Create(otherid, 560, pos[0], pos[1], pos[2], pos[3], 3, 3, pvwid, pvintid);

    AccountData[otherid][pClaimGoodside] = 1;

    new string[215];
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has set goodside girl to %s.", AccountData[playerid][pAdminname], AccountData[otherid][pName]);
    format(string, sizeof(string), "AdmCmd: %s has set your goodside girl you.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    return 1;
}