YCMD:engine(playerid, params[], help)
{
    if(IsPlayerInAnyVehicle(playerid) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        if(!IsEngineVehicle(SavingVehID[playerid]))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di dalam kendaraan bermesin!");

        if(AccountData[playerid][pTurningEngine])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda saat ini masih mencoba menghidupkan mesin, mohon tunggu!");

        // Cek akses kendaraan (owner atau pemegang kunci)
        new vehicleDBID = GetVehicleDBIDFromPhysic(SavingVehID[playerid]);
        if(vehicleDBID != -1 && !IsHaveVehicleAccess(playerid, SavingVehID[playerid]))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki akses untuk kendaraan ini!");

        switch(GetEngineStatus(SavingVehID[playerid]))
        {
            case true: // dimatikan
            {
                SendRPMeAboveHead(playerid, "Mematikan mesin kendaraannya.");
                SwitchVehicleLight(SavingVehID[playerid], false);
                SwitchVehicleEngine(SavingVehID[playerid], false);
                AccountData[playerid][pTurningEngine] = false;
            }
            case false: // dihidupkan
            {
                AccountData[playerid][pTurningEngine] = true;
                SendRPMeAboveHead(playerid, "Mencoba menghidupkan mesin kendaraannya.");
                SetTimerEx("EngineStatus", 2000, false, "id", playerid, SavingVehID[playerid]);
            }
        }
    }
    else return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus mengendarai kendaraan!");
    return 1;
}
YCMD:en(playerid, params[], help) = engine;

YCMD:sl(playerid, params[], help)
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus menyetir kendaraan!");
	
	new Float:speed, vid = GetPlayerVehicleID(playerid), Float:fHealth;
	GetVehicleHealth(vid, fHealth);
	if(fHealth <= 600.0)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Mesin kendaraan ini tidak dalam kondisi prima!");

	if(IsASweeperSidejobVeh(vid) || IsAMowingSidejobVeh(vid))
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini tidak dapat diberi speed limit!");

	switch(VehicleCore[vid][vUsedSL])
	{
		case false:
		{
			if(sscanf(params, "f", speed))
				return SUM(playerid, "/sl [speed]~n~Gunakan '/sl' kembali untuk menonaktifkan!");

			if(speed < 10 || speed > 70)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat 10 - 70!");
			
			VehicleCore[vid][vUsedSL] = true;
			SetVehicleSpeedCap(vid, speed);
			ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil menetapkan speed limit %.0f.", speed));
		}
		case true:
		{
			VehicleCore[vid][vUsedSL] = false;
			DisableVehicleSpeedCap(vid);
			ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah menonaktifkan speed limit.");
		}
	}
	return 1;
}

// Command /sharekey - Berikan kunci ke player lain
YCMD:sharekey(playerid, params[], help)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        return 1;
    
    new targetid, hours;
    if(sscanf(params, "uD(0)", targetid, hours))
    {
        ShowTDN(playerid, NOTIFICATION_SYNTAX, "Usage: /sharekey [player] [hours (0 = permanent)]");
        return 1;
    }
    
    if(!IsPlayerConnected(targetid))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Player not found!");
        return 1;
    }
    
    if(targetid == playerid)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "You cannot share a key with yourself!");
        return 1;
    }
    
    // Cek pemilik dekat kendaraan
    new vehicleid = GetNearestVehicleToPlayer(playerid, 4.0, false);
    if(vehicleid == INVALID_VEHICLE_ID)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "You must be near a vehicle!");
        return 1;
    }
    
    new vehicleDBID = GetVehicleDBIDFromPhysic(vehicleid);
    if(vehicleDBID == -1)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "This is not a private vehicle!");
        return 1;
    }
    
    // Cek apakah player adalah pemilik
    new bool:isOwner = false;
    foreach(new pv : PvtVehicles)
    {
        if(PlayerVehicle[pv][pVehID] == vehicleDBID && PlayerVehicle[pv][pVehOwnerID] == AccountData[playerid][pID])
        {
            isOwner = true;
            break;
        }
    }
    
    if(!isOwner)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Only the vehicle owner can share keys!");
        return 1;
    }
    
    // Cek target harus dekat kendaraan juga (radius 4.0)
    new Float:vx, Float:vy, Float:vz;
    GetVehiclePos(vehicleid, vx, vy, vz);
    if(GetPlayerDistanceFromPoint(targetid, vx, vy, vz) > 4.0)
    {
        new string[128];
        format(string, sizeof(string), "%s must be near the vehicle to receive the key!", GetName(targetid));
        ShowTDN(playerid, NOTIFICATION_ERROR, string);
        return 1;
    }
    
    if(hours < 0 || hours > 168)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Hours must be between 0-168 (0 = permanent)!");
        return 1;
    }
    GiveVehicleKey(playerid, targetid, vehicleDBID, hours);
    return 1;
}

// FIX: /keylist hanya untuk pemilik kendaraan
YCMD:keylist(playerid, params[], help)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        return 1;

    // Harus dekat kendaraan
    new vehicleid = GetNearestVehicleToPlayer(playerid, 4.0, false);
    if(vehicleid == INVALID_VEHICLE_ID)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "You must be near a vehicle!");
        return 1;
    }

    new vehicleDBID = GetVehicleDBIDFromPhysic(vehicleid);
    if(vehicleDBID == -1)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "This is not a private vehicle!");
        return 1;
    }

    // Cek apakah player adalah pemilik kendaraan
    new bool:isOwner = false;
    new vehicleModel = 0;
    foreach(new pv : PvtVehicles)
    {
        if(PlayerVehicle[pv][pVehID] == vehicleDBID && PlayerVehicle[pv][pVehOwnerID] == AccountData[playerid][pID])
        {
            isOwner = true;
            vehicleModel = PlayerVehicle[pv][pVehModelID];
            break;
        }
    }

    if(!isOwner)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Only the vehicle owner can view the key list!");
        return 1;
    }

    // Kumpulkan semua pemegang kunci untuk kendaraan ini dari semua player online
    new dialogString[2048];
    new keyCount = 0;
    strcat(dialogString, "Holder\tExpires\n");

    for(new p = 0; p < MAX_PLAYERS; p++)
    {
        if(!IsPlayerConnected(p)) continue;

        foreach(new i : VehicleKeyIndex[p])
        {
            if(VehicleKeys[p][i][vKeyVehicleDBID] == vehicleDBID)
            {
                new expireTime = VehicleKeys[p][i][vKeyExpireTime];
                new expireText[32];

                if(expireTime == 0)
                    strcat(expireText, "Permanent");
                else
                {
                    new remaining = expireTime - gettime();
                    if(remaining > 0)
                        format(expireText, sizeof(expireText), "%dh %dm", remaining / 3600, (remaining % 3600) / 60);
                    else
                        strcat(expireText, "Expired");
                }

                strcat(dialogString, sprintf("%s\t%s\n", VehicleKeys[p][i][vKeyHolderName], expireText), sizeof(dialogString));
                keyCount++;
                break;
            }
        }
    }

    if(keyCount == 0)
    {
        ShowTDN(playerid, NOTIFICATION_INFO, "No one has a key for this vehicle!");
        return 1;
    }

    new title[64];
    format(title, sizeof(title), "Key List - %s", GetVehicleModelName(vehicleModel));
    Dialog_Show(playerid, "KeyList", DIALOG_STYLE_TABLIST_HEADERS, title, dialogString, "Close", "");
    return 1;
}

// FIX: /removekey - bug fix pakai foreach iterator
YCMD:removekey(playerid, params[], help)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        return 1;
    
    new targetid;
    if(sscanf(params, "u", targetid))
    {
        ShowTDN(playerid, NOTIFICATION_SYNTAX, "Usage: /removekey [player]");
        return 1;
    }
    
    if(!IsPlayerConnected(targetid))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Player not found!");
        return 1;
    }

    if(targetid == playerid)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "You cannot remove your own key!");
        return 1;
    }
    
    // FIX: Harus dekat kendaraan, tidak perlu di dalam
    new vehicleid = GetNearestVehicleToPlayer(playerid, 4.0, false);
    if(vehicleid == INVALID_VEHICLE_ID)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "You must be near a vehicle!");
        return 1;
    }
    
    new vehicleDBID = GetVehicleDBIDFromPhysic(vehicleid);
    if(vehicleDBID == -1)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "This is not a private vehicle!");
        return 1;
    }
    
    // Cek apakah player adalah pemilik
    new bool:isOwner = false;
    new vehicleModel = 0;
    foreach(new pv : PvtVehicles)
    {
        if(PlayerVehicle[pv][pVehID] == vehicleDBID && PlayerVehicle[pv][pVehOwnerID] == AccountData[playerid][pID])
        {
            isOwner = true;
            vehicleModel = PlayerVehicle[pv][pVehModelID];
            break;
        }
    }
    
    if(!isOwner)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Only the vehicle owner can remove keys!");
        return 1;
    }
    
    // FIX: Pakai foreach iterator, bukan PlayerKeyCount (ini root cause bug-nya)
    new bool:hasKey = false;
    foreach(new i : VehicleKeyIndex[targetid])
    {
        if(VehicleKeys[targetid][i][vKeyVehicleDBID] == vehicleDBID)
        {
            hasKey = true;
            break;
        }
    }
    
    if(!hasKey)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Target player does not have a key for this vehicle!");
        return 1;
    }
    
    RemoveVehicleKey(targetid, vehicleDBID, true);
    
    new string[128];
    format(string, sizeof(string), "You have removed %s's key for %s!", GetName(targetid), GetVehicleModelName(vehicleModel));
    ShowTDN(playerid, NOTIFICATION_SUCCESS, string);
    
    format(string, sizeof(string), "Your key for %s has been removed by the owner!", GetVehicleModelName(vehicleModel));
    ShowTDN(targetid, NOTIFICATION_ERROR, string);
    
    return 1;
}