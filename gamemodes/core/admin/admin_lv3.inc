YCMD:playsong(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new songname[128], tmp[512];
    if (sscanf(params, "s[128]", songname))
        return SUM(playerid, "/playsong [link]");

    format(tmp, sizeof(tmp), "%s", songname);
    foreach(new ii : Player)
    {
        PlayAudioStreamForPlayer(ii, tmp);
        SendClientMessage(ii, Y_LIGHTRED, "AdmCmd: Gunakan '/stopsong' untuk memberhentikan musik admin.");
    }
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s used the '/playsong' command.", AccountData[playerid][pAdminname]);
    return 1;
}

YCMD:ann(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new desk[144];
    if (sscanf(params, "s[144]", desk))
        return SUM(playerid, "/announce [deskripsi]");

    if(strlen(desk) < 10) return ShowTDN(playerid, NOTIFICATION_ERROR, "Deskripsi minimal 10 huruf!");

    // Check for special trouble-making input
    if (strfind(params, "~x~", true) != -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Simbol '~x~' tidak dapat digunakan!");

    if (strfind(params, "#k~", true) != -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Constant Keys tidak dapat digunakan!");

    if (strfind(params, "/q", true) != -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menggunakan /q di announcement!");

    // Count tildes (uneven number = faulty input)
    new iTemp = 0;
    for (new i = (strlen(params) - 1); i != -1; i--)
    {
        if (params[i] == '~')
            iTemp++;
    }
    if (iTemp % 2 == 1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda membuat/menghilangkan extra ~ di announce!");
    
    foreach(new i : Player) if(AccountData[i][pSpawned])
    {
        ShowAnnounceTD(i, desk);
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
        SendClientMessage(i, X11_WHITE, "");
    }
	new string[144];
	format(string, sizeof(string), "%s", AccountData[playerid][pAdminname]);
	PlayerTextDrawSetString(playerid, pAnnounceTD[playerid], string);

    SetTimer("CloseAnnounceTD", 7500, false);
    return true;
}

YCMD:goodmood(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    SetPlayerHealthEx(playerid, 100.0);
    AccountData[playerid][pHunger] = 100;
    AccountData[playerid][pThirst] = 100;
    AccountData[playerid][pStress] = 0;

    SendClientMessage(playerid, Y_LIGHTRED, "AdmCmd: You used the '/goodmood' command.");
    return 1;
}

YCMD:explode(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new Float:POS[3], otherid, giveplayer[24];
    if (sscanf(params, "d", otherid))
        return SUM(playerid, "/explode [playerid]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (AccountData[playerid][pAdmin] < AccountData[otherid][pAdmin])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat explode admin yang lebih tinggi dari kamu!");

    GetPlayerName(otherid, giveplayer, sizeof(giveplayer));

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has exploded %s(%d).",  AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);

    GetPlayerPos(otherid, POS[0], POS[1], POS[2]);
    CreateExplosion(POS[0], POS[1], POS[2], 7, 5.0);
    return 1;
}

YCMD:playnearsong(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new songname[128], tmp[512], Float:x, Float:y, Float:z;
    if (sscanf(params, "s[128]", songname))
        return SUM(playerid, "/playnearsong [link]");

    GetPlayerPos(playerid, x, y, z);
    format(tmp, sizeof(tmp), "%s", songname);
    foreach(new ii : Player)
    {
        if (IsPlayerInRangeOfPoint(ii, 35.0, x, y, z))
        {
            PlayAudioStreamForPlayer(ii, tmp, x, y, z, 35.0, 1);
            SendClientMessage(ii, Y_LIGHTRED, "AdmCmd: Gunakan '/stopsong' untuk memberhentikan musik admin.");
        }
    }
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s used the '/playnearsong' command.", AccountData[playerid][pAdminname]);
    return 1;
}

YCMD:vote(playerid, params[], help)
{
    new type[24], string[128];
    if (sscanf(params, "s[24]S()[128]", type, string))
        return SUM(playerid, "/vote [name]~n~create, yes, no");

    if (!strcmp(type, "create", true))
    {
        if (AccountData[playerid][pAdmin] < 3)
            return PermissionError(playerid);

        if (VoteInfo[voteStarted])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Voting sudah dimulai!");

        new name[128];

        if (sscanf(string, "s[128]", name))
            return SUM(playerid, "/avote [create] [voting title]");

        VoteInfo[voteText][0] = EOS;
        VoteInfo[voteYes] = 0;
        VoteInfo[voteNo] = 0;

        VoteInfo[voteStarted] = true;
        VoteInfo[voteTime] = gettime() + 60;

        strcopy(VoteInfo[voteText], name);
        SendClientMessageToAllEx(Y_WHITE, "[Vote] "YELLOW"%s.", VoteInfo[voteText]);
        SendClientMessageToAllEx(Y_WHITE, "~> "RED"%s "WHITE"memulai voting, gunakan "YELLOW"'/avote yes' "WHITE"atau "YELLOW"'/avote no' "WHITE"untuk berpartisipasi.", AccountData[playerid][pAdminname]);
    }
    else if (!strcmp(type, "yes", true))
    {
        if (!VoteInfo[voteStarted])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada voting yang sedang berlangsung!");

        if (AccountData[playerid][pVoted])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda telah berpartisipasi dalam voting!");

        AccountData[playerid][pVoted] = true;
        VoteInfo[voteYes]++;

        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah melakukan vote.");
    }
    else if (!strcmp(type, "no", true))
    {
        if (!VoteInfo[voteStarted])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada voting yang sedang berlangsung!");

        if (AccountData[playerid][pVoted])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda telah berpartisipasi dalam voting!");

        AccountData[playerid][pVoted] = true;
        VoteInfo[voteNo]++;

        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah melakukan vote.");
    }
    return 1;
}

YCMD:sethbe(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount, otherid;
    if (sscanf(params, "ud", otherid, amount))
        return SUM(playerid, "/sethbe [playerid id/name] [amount]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    if (amount < 0 || amount > 100)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

    AccountData[otherid][pHunger] = amount;
    AccountData[otherid][pThirst] = amount;

    static string[215];
    mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Hunger` = %d, `Char_Thirst` = %d WHERE `pID` = %d", amount, amount, AccountData[otherid][pID]);
    mysql_pquery(g_SQL, string);

    SetPlayerDrunkLevel(otherid, 0);
    SendAdm(playerid, "You have set HBE for %s to %d.", AccountData[otherid][pName], amount);

    format(string, sizeof(string), "AdmCmd: %s has set your character's HBE to %d.", AccountData[playerid][pAdminname], amount);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    return 1;
}

YCMD:setstress(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount, otherid;
    if (sscanf(params, "ud", otherid, amount))
        return SUM(playerid, "/setstress [playerid id/name] [amount]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[otherid][pStress] = amount;

    static string[215];
    mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_characters` SET `Char_Stress` = %d WHERE `pID` = %d", amount, AccountData[otherid][pID]);
    mysql_pquery(g_SQL, string);

    SetPlayerDrunkLevel(otherid, 0);
    SendAdm(playerid, "You have set stress for %s to %d.", AccountData[otherid][pName], amount);
    
    format(string, sizeof(string), "AdmCmd: %s has set your character's stress to %d.", AccountData[playerid][pAdminname], amount);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    return 1;
}

YCMD:makequiz(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    static tmp[128], string[256], str[256], pr;

    if (sscanf(params, "s[128]S()[256]", tmp, string))
    {
        SUM(playerid, "/makequiz [name] (question, answer, price, end)");
        SendClientMessage(playerid, X11_GRAY, "NOTE: Please prepare your response first!");
        return 1;
    }

    if (!strcmp(tmp, "question", true))
    {
        if (sscanf(string, "s[256]", str))
            return SUM(playerid, "/makequiz question [question]");
        if (quiz)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Quiz telah dimulai, gunakan '/makequiz end' untuk mengakhiri!");
        if (!answermade)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon siapkan jawaban terlebih dahulu!");
        if (qprs == 0)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon siapkan hadiah terlebih dahulu!");

        SendClientMessageToAllEx(Y_SERVER, "(Quiz) "WHITE"Admin "RED"%s "WHITE"has started the quiz.", AccountData[playerid][pAdminname]);
        SendClientMessageToAllEx(-1, "~> Soal: %s", str);
        SendClientMessageToAllEx(-1, "~> Hadiah: "DARKGREEN"$%s.", FormatMoney(qprs));
        SendClientMessageToAll(-1, "Gunakan "CMDEA"'/qa' "WHITE"to answer!");
        quiz = true;
    }
    else if (!strcmp(tmp, "answer", true))
    {
        if (sscanf(string, "s[256]", str))
            return SUM(playerid, "/makequiz answer [answer]");
        if (quiz)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Quiz telah dimulai, gunakan '/makequiz end' untuk mengakhiri!");
        strcopy(answers, str);
        answermade = true;
        format(string, sizeof(string), "[Quiz] You have answered, "YELLOW"%s", str);
        SendClientMessage(playerid, -1, string);
    }
    else if (!strcmp(tmp, "price", true))
    {
        if (sscanf(string, "d", pr))
            return SUM(playerid, "/makequiz price [amount]");
        if (quiz)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Quiz telah dimulai, gunakan '/makequiz end' untuk mengakhiri!");
        if (!answermade)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon siapkan jawaban terlebih dahulu!");
        if (pr <= 0)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon siapkan hadiah terlebih dahulu!");
        qprs = pr;
        format(string, sizeof(string), "[Quiz] You have set the quiz prize to "DARKGREEN"$%s.", FormatMoney(pr));
        SendClientMessage(playerid, -1, string);
    }
    else if (!strcmp(tmp, "end", true))
    {
        if (!quiz)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada quiz yang sedang berjalan!");
        SendClientMessageToAllEx(-1, "[Quiz] Admin "RED"%s has closed the quiz!", AccountData[playerid][pAdminname]);
        answermade = false;
        quiz = false;
        qprs = 0;
        answers[0] = EOS;
    }
    return 1;
}

YCMD:removepv(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new vehid, query[512];
    if (sscanf(params, "d", vehid))
        return SUM(playerid, "/removepv [VID]~n~Use /avehlist to find another player's vehicle VID!");

    if (!IsValidVehicle(vehid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Vehicle ID!");

    foreach(new i : PvtVehicles)
    {
        if (vehid == PlayerVehicle[i][pVehPhysic])
        {
            SendAdm(playerid, "You have removed a private vehicle with VID: %d (DBID: %d).", vehid, PlayerVehicle[i][pVehID]);
            SetVehicleNeonLights(PlayerVehicle[i][pVehPhysic], false, PlayerVehicle[i][pVehNeon], 0);

            PlayerVehicle[i][pVehHandbraked] = false;

            DestroyVehicle(PlayerVehicle[i][pVehPhysic]);
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `vehicle_bagasi` WHERE `Veh_DBID`=%d", PlayerVehicle[i][pVehID]);
            mysql_pquery(g_SQL, query);
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `vehicle_holster` WHERE `Veh_DBID`=%d", PlayerVehicle[i][pVehID]);
            mysql_pquery(g_SQL, query);
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `player_vehicles` WHERE `id` = %d", PlayerVehicle[i][pVehID]);
            mysql_pquery(g_SQL, query);

            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `vtoys` WHERE `Veh_DBID`=%d", PlayerVehicle[i][pVehID]);
            mysql_pquery(g_SQL, query);

            for(new x; x < 6; x++)
            {
                vtData[i][x][vtoy_modelid] = 0;
                vtData[i][x][vtoy_text][0] = EOS;
                strcopy(vtData[i][x][vtoy_font], "Arial");
                vtData[i][x][vtoy_fontsize] = 11;
                vtData[i][x][vtoy_fontcolor][0] = 255;
                vtData[i][x][vtoy_fontcolor][1] = 0;
                vtData[i][x][vtoy_fontcolor][2] = 0;
                vtData[i][x][vtoy_fontcolor][3] = 0;
                vtData[i][x][vtoy_fontcolor][4] = 0;
                vtData[i][x][vtoy_objectcolor][0] = 255;
                vtData[i][x][vtoy_objectcolor][1] = 0;
                vtData[i][x][vtoy_objectcolor][2] = 0;
                vtData[i][x][vtoy_objectcolor][3] = 0;
                vtData[i][x][vtoy_objectcolor][4] = 0;
                vtData[i][x][vtoy_x] = 0.0;
                vtData[i][x][vtoy_y] = 0.0;
                vtData[i][x][vtoy_z] = 0.0;
                vtData[i][x][vtoy_rx] = 0.0;
                vtData[i][x][vtoy_ry] = 0.0;
                vtData[i][x][vtoy_rz] = 0.0;
            }

            for(new x; x < MAX_BAGASI_ITEMS; x++)
            {
                VehicleBagasi[i][x][vehicleBagasiExists] = false;
                VehicleBagasi[i][x][vehicleBagasiID] = 0;
                VehicleBagasi[i][x][vehicleBagasiVDBID] = 0;
                VehicleBagasi[i][x][vehicleBagasiTemp][0] = EOS;
                VehicleBagasi[i][x][vehicleBagasiModel] = 0;
                VehicleBagasi[i][x][vehicleBagasiQuant] = 0;
            }

            for(new z; z < 3; z++)
            {
                VehicleHolster[i][vHolsterTaken][z] = false;
                VehicleHolster[i][vHolsterID][z] = -1;
                VehicleHolster[i][vHolsterWeaponID][z] = 0;
                VehicleHolster[i][vHolsterWeaponAmmo][z] = 0;
            }
            Iter_Remove(PvtVehicles, i);
        }
    }
    return 1;
}

YCMD:ginsu(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);
        
    new countdown;
    if(sscanf(params, "d", countdown)) return SUM(playerid, "/ginsu [menit]");

    if(countdown < 2) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat kurang dari 2 menit!");
    if(countdown > 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat lebih dari 5 menit!");

    GM[GInsuTime] = countdown * 60;
    SendClientMessageToAllEx(Y_LIGHTRED, "AdmCmd: %s telah memulai %d menit asuransi keliling.", AccountData[playerid][pAdminname], GM[GInsuTime]/60);

    ShowAsuransiTD(sprintf("%d menit %d detik", GM[GInsuTime]/60%60, GM[GInsuTime]%3600%60));
    return 1;
}

YCMD:savemeall(playerid, params[], help)
{
	if(AccountData[playerid][pAdmin] < 3)
		return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

	foreach(new pid : Player)
	{
		if(pid != playerid)
		{
			UpdateWeapons(pid);
			UpdateAccountData(pid);
			SendClientMessage(pid, Y_LIGHTRED, "AdmCmd: Administrator Telah membackup database semua player online.");
		}
	}
	
	SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s used the '/savemeall' command.", AccountData[playerid][pAdminname]);
	return 1;
}

YCMD:resetuniform(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 3)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount, otherid;
    if (sscanf(params, "u", otherid, amount))
        return SUM(playerid, "/resetuniform [playerid id/name]");

    if (!IsPlayerConnected(otherid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");

    AccountData[otherid][pIsUsingUniform] = false;
    AccountData[otherid][pUniform] = 1;

    new string[215];
    format(string, sizeof(string), "AdmCmd: %s has remove skin uniform.", AccountData[playerid][pAdminname]);
    SendClientMessage(otherid, Y_LIGHTRED, string);

    return 1;
}