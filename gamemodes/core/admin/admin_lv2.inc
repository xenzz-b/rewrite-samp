YCMD:togooc(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    switch(TogOOC)
    {
        case false:
        {
            SendClientMessageToAllEx(Y_SERVER, "(Server) "WHITE"Pengurus "RED"%s "WHITE"telah membuka chat global OOC.", AccountData[playerid][pAdminname]);
            TogOOC = true;

            //format(sclstr, sizeof(sclstr), "%s(%d) [%s] used the '/togooc' command\n\
            //> opened global OOC chat", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
            //CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
        }
        case true:
        {
            SendClientMessageToAllEx(Y_SERVER, "(Server) "WHITE"Pengurus "RED"%s "WHITE"telah menutup chat global OOC.", AccountData[playerid][pAdminname]);
            TogOOC = false;

            //format(sclstr, sizeof(sclstr), "%s(%d) [%s] used the '/togooc' command\n\
            //> closed global OOC chat", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
            //CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
        }
    }
    return 1;
}

YCMD:veh(playerid, params[], help)
{
    static
        model[32],
        color1,
        color2;

    if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(sscanf(params, "s[32]I(0)I(0)", model, color1, color2))
        return SUM(playerid, "/veh [model id/name] [color 1] [color 2]");

    if((model[0] = GetVehicleModelByName(model)) == 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Model ID!");

    static
        Float:x,
        Float:y,
        Float:z,
        Float:a;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    for(new i; i < MAX_ADMIN_VEHICLES; i++)
    {
        if(GM[adminV][i] == INVALID_VEHICLE_ID)
        {
            GM[adminV][i] = CreateVehicle(model[0], x, y, z, a, color1, color2, 60000, false);
            VehicleCore[GM[adminV][i]][vCoreFuel] = 100;
            SetValidVehicleHealth(GM[adminV][i], 1000.0);
            VehicleCore[GM[adminV][i]][vCoreLocked] = false;
            VehicleCore[GM[adminV][i]][vMaxHealth] = 1000.0;
            VehicleCore[GM[adminV][i]][vIsBodyUpgraded] = false;
            VehicleCore[GM[adminV][i]][vIsBodyBroken] = false;
            SwitchVehicleEngine(GM[adminV][i], true);
            SwitchVehicleDoors(GM[adminV][i], false);

            if(GetPlayerInterior(playerid) != 0)
                LinkVehicleToInteriorEx(GM[adminV][i], GetPlayerInterior(playerid));

            if(GetPlayerVirtualWorld(playerid) != 0)
                SetVehicleVirtualWorldEx(GM[adminV][i], GetPlayerVirtualWorld(playerid));

            PutPlayerInVehicleEx(playerid, GM[adminV][i], 0);
            SetCameraBehindPlayer(playerid);
            SetVehicleParamsEx(GM[adminV][i], 1, 1, 0, 0, 0, 0, 0);
            SetVehicleNumberPlate(GM[adminV][i], ""RED"ADMIN");
            break;
        }

        if(i == (MAX_ADMIN_VEHICLES - 1))
        {
            ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan admin sudah mencapai (100). Mohon gunakan /adveh!");
        }
    }
    return 1;
}

YCMD:setfuel(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2) return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new vehid, ammount;
    if(sscanf(params, "dd", vehid, ammount))
        return SUM(playerid, "/setfuel [vehicle id] [amount]");

    if(!IsValidVehicle(vehid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");

    VehicleCore[vehid][vCoreFuel] = ammount;
    SendAdm(playerid, "You have set the fuel for %s(%d) to %d.", GetVehicleModelName(GetVehicleModel(vehid)), vehid, ammount);
    return 1;
}

YCMD:adveh(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2) return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    for(new i; i < MAX_ADMIN_VEHICLES; i++)
    {
        DestroyVehicle(GM[adminV][i]);
        GM[adminV][i] = INVALID_VEHICLE_ID;
    }
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has destroyed all admin vehicles!", AccountData[playerid][pAdminname]);
    return 1;
}

YCMD:unjail(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new otherid;
    if(sscanf(params, "d", otherid))
        return SUM(playerid, "/unjail [playerid]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(!OJailData[otherid][jailed])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak sedang di jail admin!");

    OJailData[otherid][jailed] = false;
    OJailData[otherid][jailCell] = -1;
    OJailData[otherid][jailAdmin][0] = EOS;
    OJailData[otherid][jailTime] = 0;
    OJailData[otherid][jailDur] = 0;
    OJailData[otherid][jailReason][0] = EOS;
    OJailData[otherid][jailFine] = 0;
    SetPlayerInteriorEx(otherid, 0);
    SetPlayerVirtualWorldEx(otherid, 0);

    SetPlayerPositionEx(otherid, 1479.7563,-1709.2994,14.0469,178.8976);
    SetPlayerSpecialAction(otherid, SPECIAL_ACTION_NONE);
    ClearAnimations(otherid, true);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has released %s from admin jail.", AccountData[playerid][pAdminname], AccountData[otherid][pName]);
    return 1;
}

YCMD:sethp(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new Float:amount, otherid;
    if(sscanf(params, "uf", otherid, amount))
        return SUM(playerid, "/sethp [playerid id/name] <amount>");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    SetPlayerHealthEx(otherid, amount);

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has set your character's health to %.2f.",AccountData[playerid][pAdminname], amount);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set %s (%d) health to %.2f.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, amount);
    return 1;
}

YCMD:setstatus(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount, otherid;
    if(sscanf(params, "ui", otherid, amount))
        return SUM(playerid, "/setstatus [playerid id/name] <status>\n0. Lajang 1. Menikah 2. Cerai");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(amount < 0 || amount > 2)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Status hanya boleh 0 (Lajang), 1 (Menikah), atau 2 (Cerai)!");

    AccountData[otherid][pStatus] = amount;

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has set your character's Status to %s.", AccountData[playerid][pAdminname], GetStatus(otherid));
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set %s (%d) Status to %s.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, GetStatus(otherid));

    return 1;
}


YCMD:afuel(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(!IsPlayerInAnyVehicle(playerid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di dalam kendaraan apapun!");

    VehicleCore[GetPlayerVehicleID(playerid)][vCoreFuel] = 100;
    ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah mengisi ulang bahan bakar kendaraan ini!");

    //format(sclstr, sizeof(sclstr), "%s(%d) [%s] used the '/afuel' command", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
    //CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
    return 1;
}

YCMD:afix(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(!IsPlayerInAnyVehicle(playerid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di dalam kendaraan apapun!");

    new vid = GetPlayerVehicleID(playerid);
    foreach(new pv : PvtVehicles)
    {
        if(vid == PlayerVehicle[pv][pVehPhysic])
        {
            SetValidVehicleHealth(vid, VehicleCore[vid][vMaxHealth]);
            PlayerVehicle[pv][pVehHealth] = VehicleCore[vid][vMaxHealth];
            VehicleCore[vid][vIsBodyBroken] = false;
            UpdateVehicleDamageStatus(vid, 0, 0, 0, 0);
            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah memperbaiki kendaraan ini!");
            return 1;
        }
    }
    SetValidVehicleHealth(vid, VehicleCore[vid][vMaxHealth]);
    VehicleCore[vid][vCoreHealth] = VehicleCore[vid][vMaxHealth];
    VehicleCore[vid][vIsBodyBroken] = false;
    UpdateVehicleDamageStatus(vid, 0, 0, 0, 0);
    ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah memperbaiki kendaraan ini!");

    //format(sclstr, sizeof(sclstr), "%s(%d) [%s] used the '/afix' command", AccountData[playerid][pAdminname], playerid, AccountData[playerid][pUCP]);
    //CallLocalFunction("StaffCommandLog", "is", playerid, sclstr);
    return 1;
}

YCMD:setskin(playerid, params[], help)
{
    new
        skinid,
        otherid;

    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(sscanf(params, "ud", otherid, skinid))
        return SUM(playerid, "/setskin [playerid/Part Of Name] [skin id]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(skinid < 0 || skinid > 311)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid skin ID (0 - 311)");

    SetPlayerSkin(otherid, skinid);
    AccountData[otherid][pSkin] = skinid;

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has set your character's skin to %d.",AccountData[playerid][pAdminname], skinid);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    SendAdm(playerid, "You have set the skin for %s(%d) to %d.", AccountData[otherid][pName], otherid, skinid);
    return 1;
}

YCMD:setskinex(playerid, params[], help)
{
    new
        skinid,
        otherid;

    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(sscanf(params, "ud", otherid, skinid))
        return SUM(playerid, "/setskinex [playerid/Part Of Name] [skin id]");

    if(!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if(skinid < 0 || skinid > 200000)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid skin ID (1 - 200000)");

    SetPlayerSkin(otherid, skinid);
    AccountData[otherid][pSkin] = skinid;

    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has set your character's skin to %d.",AccountData[playerid][pAdminname], skinid);
    SendClientMessage(otherid, Y_LIGHTRED, string);
    SendAdm(playerid, "You have set the skin for %s(%d) to %d.", AccountData[otherid][pName], otherid, skinid);
    return 1;
}

YCMD:cd(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    if(Count != -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Countdown sedang dimulai!");

    Count = 6;
    countTimer = SetTimer("pCountDown", 1000, true);

    foreach(new ii : Player)
    {
        showCD[ii] = 1;
    }
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has started the global countdown.", AccountData[playerid][pAdminname]);
    return 1;
}

YCMD:setarmor(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

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
    static string[144];
    format(string, sizeof(string), "AdmCmd: %s has set your character's armor to %.2f.", AccountData[playerid][pAdminname], amount);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set %s (%d) armor to %.2f.", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid, amount);
    return 1;
}
YCMD:setam(playerid, params[], help) = setarmor;

YCMD:adjveh(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 2)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    SetTimer("OnJobVehicleDestroyed", 30000, false);
    SendClientMessageToAllEx(Y_LIGHTRED, "AdmCmd: %s akan menghancurkan kendaraan Job & Sidejob yang tidak dinaiki selama 30 detik.", AccountData[playerid][pAdminname]);
    return 1;
}