#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if((newkeys & KEY_SECONDARY_ATTACK))
    {
        if(!AccountData[playerid][pKnockdown])
        {
            foreach(new did : Doors)
            {
                if(IsPlayerInRangeOfPoint(playerid, 2.0, DoorData[did][dExtposX], DoorData[did][dExtposY], DoorData[did][dExtposZ]) && GetPlayerVirtualWorld(playerid) == DoorData[did][dExtvw] && GetPlayerInterior(playerid) == DoorData[did][dExtint])
                {
                    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
                    {
                        if(DoorData[did][dIntposX] == 0.0 && DoorData[did][dIntposY] == 0.0 && DoorData[did][dIntposZ] == 0.0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pintu ini belum memiliki interior!");

                        if(DoorData[did][dLocked]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pintu ini sedang terkunci!");
                            
                        if(DoorData[did][dFaction] != 0)
                        {
                            if(DoorData[did][dFaction] != AccountData[playerid][pFaction]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pintu ini hanya untuk faction tertentu!");
                        }
                        if(DoorData[did][dFamily] != -1)
                        {
                            if(DoorData[did][dFamily] != AccountData[playerid][pFamily]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pintu ini hanya untuk family official tertentu!");
                        }
						if(DoorData[did][dJdm] != -1)
                        {
                            if(DoorData[did][dJdm] != AccountData[playerid][pFamily]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pintu ini hanya untuk JDM official tertentu!");
                        }
                        
                        if(DoorData[did][dVip] > AccountData[playerid][pVIP]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Status donasi VIP anda tidak cukup untuk masuk ke pintu ini!");
                        
                        if(DoorData[did][dAdmin] > AccountData[playerid][pAdmin]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki level admin yang cukup untuk masuk ke pintu ini!");

                        if(!isnull(DoorData[did][dPass]))
                        {
                            static params[256];
                            if(sscanf(params, "s[256]", params)) return SUM(playerid, "/enter [password]");
                            if(strcmp(params, DoorData[did][dPass])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kata sandi pintu salah!");
                            
                            SetPlayerPositionEx(playerid, DoorData[did][dIntposX], DoorData[did][dIntposY], DoorData[did][dIntposZ], DoorData[did][dIntposA], 6500);
                            AccountData[playerid][pInDoor] = did;
							AccountData[playerid][pIsFallFromInterior] = false;
							PlayerPlaySound(playerid, 1, 0.0, 0.0, 0.0);
                            SetPlayerInteriorEx(playerid, DoorData[did][dIntint]);
                            SetPlayerVirtualWorldEx(playerid, DoorData[did][dIntvw]);
                            SetCameraBehindPlayer(playerid);
                            SetPlayerWeather(playerid, 0);
                            GameTextForPlayer(playerid, "Loading Object...", 6500, 3);
							FadeIn(playerid);
                        }
                        else
                        {
                            SetPlayerPositionEx(playerid, DoorData[did][dIntposX], DoorData[did][dIntposY], DoorData[did][dIntposZ], DoorData[did][dIntposA], 6500);
                            AccountData[playerid][pInDoor] = did;
							AccountData[playerid][pIsFallFromInterior] = false;
							PlayerPlaySound(playerid, 1, 0.0, 0.0, 0.0);
                            SetPlayerInteriorEx(playerid, DoorData[did][dIntint]);
                            SetPlayerVirtualWorldEx(playerid, DoorData[did][dIntvw]);
                            SetCameraBehindPlayer(playerid);
                            SetPlayerWeather(playerid, 0);
                            GameTextForPlayer(playerid, "Loading Object...", 6500, 3);
							FadeIn(playerid);
                        }
                    }
                }
                else if(IsPlayerInRangeOfPoint(playerid, 2.0, DoorData[did][dIntposX], DoorData[did][dIntposY], DoorData[did][dIntposZ]) && GetPlayerVirtualWorld(playerid) == DoorData[did][dIntvw] && GetPlayerInterior(playerid) == DoorData[did][dIntint])
                {
                    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
                    {
                        SetPlayerPositionEx(playerid, DoorData[did][dExtposX], DoorData[did][dExtposY], DoorData[did][dExtposZ], DoorData[did][dExtposA], 6500);
                        AccountData[playerid][pInDoor] = -1;
						PlayerPlaySound(playerid, 0, 0.0, 0.0, 0.0);
                        SetPlayerInteriorEx(playerid, DoorData[did][dExtint]);
                        SetPlayerVirtualWorldEx(playerid, DoorData[did][dExtvw]);
                        SetCameraBehindPlayer(playerid);
                        SetPlayerWeather(playerid, WorldWeather);
                        GameTextForPlayer(playerid, "Loading Object...", 6500, 3);
						FadeIn(playerid);
					}
                }
            }

			//basement
			foreach(new bmid : Basement)
			{
				if(IsPlayerInRangeOfPoint(playerid, 2.8, BasementData[bmid][bmExtposX], BasementData[bmid][bmExtposY], BasementData[bmid][bmExtposZ]) && GetPlayerVirtualWorld(playerid) == BasementData[bmid][bmExtvw] && GetPlayerInterior(playerid) == BasementData[bmid][bmExtint])
				{
					if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
					{
						if(BasementData[bmid][bmIntposX] == 0.0 && BasementData[bmid][bmIntposY] == 0.0 && BasementData[bmid][bmIntposZ] == 0.0)
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini belum memiliki interior!");

						if(BasementData[bmid][bmLocked])
							return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini sedang terkunci!");
							
						if(BasementData[bmid][bmFaction] != 0)
						{
							if(BasementData[bmid][bmFaction] != AccountData[playerid][pFaction])
								return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini hanya untuk faction tertentu!");
						}
						if(BasementData[bmid][bmFamily] != 0)
						{
							if(BasementData[bmid][bmFamily] != AccountData[playerid][pFamily])
								return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini hanya untuk family official tertentu!");
						}
						
						if(BasementData[bmid][bmVip] > AccountData[playerid][pVIP])
							return ShowTDN(playerid, NOTIFICATION_ERROR, "Status donasi VIP anda tidak cukup untuk masuk ke pintu ini!");
						
						if(BasementData[bmid][bmAdmin] > AccountData[playerid][pAdmin])
							return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki level admin yang cukup untuk masuk ke pintu ini!");

						if(strlen(BasementData[bmid][bmPass]))
						{
							new params[256];
							if(sscanf(params, "s[256]", params)) return SUM(playerid, "/enter [password]");
							if(strcmp(params, BasementData[bmid][bmPass])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kata sandi basement salah!");
							
							SetPlayerPositionEx(playerid, BasementData[bmid][bmIntposX], BasementData[bmid][bmIntposY], BasementData[bmid][bmIntposZ], BasementData[bmid][bmIntposA]);
							
							SetPlayerInterior(playerid, BasementData[bmid][bmIntint]);
							SetPlayerVirtualWorld(playerid, BasementData[bmid][bmIntvw]);
							SetCameraBehindPlayer(playerid);
							SetPlayerWeather(playerid, 0);
							FadeIn(playerid);
						}
						else
						{
							SetPlayerPositionEx(playerid, BasementData[bmid][bmIntposX], BasementData[bmid][bmIntposY], BasementData[bmid][bmIntposZ], BasementData[bmid][bmIntposA]);
						
							SetPlayerInterior(playerid, BasementData[bmid][bmIntint]);
							SetPlayerVirtualWorld(playerid, BasementData[bmid][bmIntvw]);
							SetCameraBehindPlayer(playerid);
							SetPlayerWeather(playerid, 0);
							FadeIn(playerid);
						}
					}
				}
				else if(IsPlayerInRangeOfPoint(playerid, 2.8, BasementData[bmid][bmInexitX], BasementData[bmid][bmInexitY], BasementData[bmid][bmInexitZ]) && GetPlayerVirtualWorld(playerid) == BasementData[bmid][bmIntvw] && GetPlayerInterior(playerid) == BasementData[bmid][bmIntint])
				{
					if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
					{
						if(BasementData[bmid][bmOutexitX] == 0.0 && BasementData[bmid][bmOutexitY] == 0.0 && BasementData[bmid][bmOutexitZ] == 0.0)
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini belum memiliki exterior!");

						SetPlayerPositionEx(playerid, BasementData[bmid][bmOutexitX], BasementData[bmid][bmOutexitY], BasementData[bmid][bmOutexitZ], BasementData[bmid][bmOutexitA]);
						
						SetPlayerInterior(playerid, BasementData[bmid][bmExtint]);
						SetPlayerVirtualWorld(playerid, BasementData[bmid][bmExtvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);
						FadeIn(playerid);
					}
				}
			}

            foreach(new bizid : Bizes)
            {
                if(IsPlayerInRangeOfPoint(playerid, 1.0, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]) && GetPlayerVirtualWorld(playerid) == BizData[bizid][bizExtVw] && GetPlayerInterior(playerid) == BizData[bizid][bizExtInt])
                {
					if(BizData[bizid][bizType] == 6)
						return 1;

                    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
                    {
                        if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID])
                        {
                            if(BizData[bizid][bizLocked]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini sedang terkunci!");
                        }

                        if(AccountData[playerid][pMoney] < BizData[bizid][bizEnteranceFee]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki cukup uang untuk masuk ke bisnis ini!");

                        SetPlayerPositionEx(playerid, BizData[bizid][bizIntPos][0], BizData[bizid][bizIntPos][1], BizData[bizid][bizIntPos][2] + 0.35, BizData[bizid][bizIntPos][3]);
                        AccountData[playerid][pInBiz] = bizid;
                        SetPlayerInteriorEx(playerid, BizData[bizid][bizIntInt]);
                        SetPlayerVirtualWorldEx(playerid, BizData[bizid][bizIntVw]);
                        SetCameraBehindPlayer(playerid);
                        SetPlayerWeather(playerid, 0);
                        
                        TakePlayerMoneyEx(playerid, BizData[bizid][bizEnteranceFee]);
                        SendClientMessageEx(playerid, X11_LIGHTBLUE, "INFO: "WHITE"Anda membayar "RED"$%s "WHITE" sebagai biaya masuk ke bisnis ini.", FormatMoney(BizData[bizid][bizEnteranceFee]));
                        SendClientMessageEx(playerid, X11_LIGHTBLUE, "INFO: "WHITE"Selamat datang di "AQUAMARINE"%s. "WHITE"Untuk membeli, gunakan "YELLOW"'/buy'.", BizData[bizid][bizName]);
						FadeIn(playerid);
					}
                }
                else if(IsPlayerInRangeOfPoint(playerid, 1.0, BizData[bizid][bizIntPos][0], BizData[bizid][bizIntPos][1], BizData[bizid][bizIntPos][2]) && GetPlayerVirtualWorld(playerid) == BizData[bizid][bizIntVw] && GetPlayerInterior(playerid) == BizData[bizid][bizIntInt])
                {
					if(BizData[bizid][bizType] == 6)
						return 1;

                    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
                    {
                        SetPlayerPositionEx(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtPos][3]);
                        AccountData[playerid][pInBiz] = -1;
                        SetPlayerInteriorEx(playerid, BizData[bizid][bizExtInt]);
                        SetPlayerVirtualWorldEx(playerid, BizData[bizid][bizExtVw]);
                        SetCameraBehindPlayer(playerid);
                        SetPlayerWeather(playerid, WorldWeather);
						FadeIn(playerid);
                    }
                }
            }
        }
    }
	else if((newkeys & KEY_CROUCH))
    {
		//basement
		foreach(new bmid : Basement)
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.8, BasementData[bmid][bmExtposX], BasementData[bmid][bmExtposY], BasementData[bmid][bmExtposZ]) && GetPlayerVirtualWorld(playerid) == BasementData[bmid][bmExtvw] && GetPlayerInterior(playerid) == BasementData[bmid][bmExtint])
			{
				if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
				{
					if(BasementData[bmid][bmIntposX] == 0.0 && BasementData[bmid][bmIntposY] == 0.0 && BasementData[bmid][bmIntposZ] == 0.0)
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini belum memiliki interior!");

					if(BasementData[bmid][bmLocked])
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini sedang terkunci!");
						
					if(BasementData[bmid][bmFaction] != 0)
					{
						if(BasementData[bmid][bmFaction] != AccountData[playerid][pFaction])
							return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini hanya untuk faction tertentu!");
					}
					if(BasementData[bmid][bmFamily] != 0)
					{
						if(BasementData[bmid][bmFamily] != AccountData[playerid][pFamily])
							return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini hanya untuk family official tertentu!");
					}
					
					if(BasementData[bmid][bmVip] > AccountData[playerid][pVIP])
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Status donasi VIP anda tidak cukup untuk masuk ke pintu ini!");
					
					if(BasementData[bmid][bmAdmin] > AccountData[playerid][pAdmin])
						return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki level admin yang cukup untuk masuk ke pintu ini!");

					if(strlen(BasementData[bmid][bmPass]))
					{
						new params[256];
						if(sscanf(params, "s[256]", params)) return SUM(playerid, "/enter [password]");
						if(strcmp(params, BasementData[bmid][bmPass])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kata sandi basement salah!");
						
						SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), BasementData[bmid][bmIntposX], BasementData[bmid][bmIntposY], BasementData[bmid][bmIntposZ], BasementData[bmid][bmIntposA]);
						LinkVehicleToInterior(GetPlayerVehicleID(playerid), BasementData[bmid][bmIntint]);
						SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), BasementData[bmid][bmIntvw]);

						SetPlayerInteriorEx(playerid, BasementData[bmid][bmIntint]);
						SetPlayerVirtualWorldEx(playerid, BasementData[bmid][bmIntvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);

						foreach(new passid : VehicleOccupant(SavingVehID[playerid], true))
						{
							SetPlayerInteriorEx(passid, BasementData[bmid][bmIntint]);
							SetPlayerVirtualWorldEx(passid, BasementData[bmid][bmIntvw]);
							SetCameraBehindPlayer(passid);
							SetPlayerWeather(passid, 0);
							FadeIn(passid);
						}
						FadeIn(playerid);
					}
					else
					{
						SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), BasementData[bmid][bmIntposX], BasementData[bmid][bmIntposY], BasementData[bmid][bmIntposZ], BasementData[bmid][bmIntposA]);
						LinkVehicleToInterior(GetPlayerVehicleID(playerid), BasementData[bmid][bmIntint]);
						SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), BasementData[bmid][bmIntvw]);
					
						SetPlayerInteriorEx(playerid, BasementData[bmid][bmIntint]);
						SetPlayerVirtualWorldEx(playerid, BasementData[bmid][bmIntvw]);
						SetCameraBehindPlayer(playerid);
						SetPlayerWeather(playerid, 0);

						foreach(new passid : VehicleOccupant(SavingVehID[playerid], true))
						{
							SetPlayerInteriorEx(passid, BasementData[bmid][bmIntint]);
							SetPlayerVirtualWorldEx(passid, BasementData[bmid][bmIntvw]);
							SetCameraBehindPlayer(passid);
							SetPlayerWeather(passid, 0);
							FadeIn(passid);
						}
						FadeIn(playerid);
					}
				}
			}
			else if(IsPlayerInRangeOfPoint(playerid, 2.8, BasementData[bmid][bmInexitX], BasementData[bmid][bmInexitY], BasementData[bmid][bmInexitZ]) && GetPlayerVirtualWorld(playerid) == BasementData[bmid][bmIntvw] && GetPlayerInterior(playerid) == BasementData[bmid][bmIntint])
			{
				if(BasementData[bmid][bmOutexitX] == 0.0 && BasementData[bmid][bmOutexitY] == 0.0 && BasementData[bmid][bmOutexitZ] == 0.0)
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Basement ini belum memiliki exterior!");
				
				if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsPlayerInAnyVehicle(playerid))
				{
					SetVehiclePositionEx(playerid, GetPlayerVehicleID(playerid), BasementData[bmid][bmOutexitX], BasementData[bmid][bmOutexitY], BasementData[bmid][bmOutexitZ], BasementData[bmid][bmOutexitA]);
					LinkVehicleToInterior(GetPlayerVehicleID(playerid), BasementData[bmid][bmExtint]);
					SetVehicleVirtualWorld(GetPlayerVehicleID(playerid), BasementData[bmid][bmExtvw]);

					SetPlayerInteriorEx(playerid, BasementData[bmid][bmExtint]);
					SetPlayerVirtualWorldEx(playerid, BasementData[bmid][bmExtvw]);
					SetCameraBehindPlayer(playerid);
					SetPlayerWeather(playerid, WorldWeather);

					foreach(new passid : VehicleOccupant(SavingVehID[playerid], true))
					{
						SetPlayerInteriorEx(passid, BasementData[bmid][bmExtint]);
						SetPlayerVirtualWorldEx(passid, BasementData[bmid][bmExtvw]);
						SetCameraBehindPlayer(passid);
						SetPlayerWeather(passid, WorldWeather);
						FadeIn(passid);
					}
					FadeIn(playerid);
				}
			}
        }
    }
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 3.5, -2033.0695,-117.5283,1035.1719))
    {
        if(!AccountData[playerid][pKnockdown])
        {
			Dialog_Show(playerid, "DMVCatalog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Department of Motor Vehicles", "Service\tRegulation\n\
            Apply Driving License\t-\n\
            "GRAY"General Vehicle License [GVL-1] Renewal\t"GRAY"$135.00\n\
            Large Vehicle License [GVL-2] Renewal\t$275.00\n\
            "GRAY"Motorbike License [MB] Renewal\t"GRAY"$75.00\n\
            Boat License [B] Renewal\t$750.00\n\
            "GRAY"Helicopter License [A1] Renewal\t"GRAY"$6,250.00\n\
            Plane License [A2] Renewal\t$12,500.00\n\
            "GRAY"Vehicle Plate Installation\t"GRAY"$200.00", "Pilih", "Batal");
        }
    }
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 2.0, 614.3849,-1879.2244,6.2220))
    {
		if(!AccountData[playerid][pKnockdown])
		{
			ShowMenuRestoPringSewuTD(playerid);
		}
	}
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 2.0, -313.9656,1298.4697,54.3655))
    {
		if(!AccountData[playerid][pKnockdown])
		{
			ShowMenuRestoSriMersingTD(playerid);
		}
	}
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 2.0, 2480.7302,43.3903,1069.6959))
    {
		if(!AccountData[playerid][pKnockdown])
		{
			if(!AccountData[playerid][pHasKTP]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Kartu Tanda Penduduk/sudah expired!");
			Dialog_Show(playerid, "GudangRental", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Penyewaan Gudang", 
			"Katalog/Nama Gudang\tHarga Penyewaan\n\
			Mulai sewa gudang\t"GREEN"$20,000\n\
			"GRAY"Berhenti sewa gudang\t"GRAY"-", "Pilih", "Batal");
		}
	}
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 2.0, 1809.3967,-1423.4990,13.7644))
    {
		if(!AccountData[playerid][pKnockdown])
		{
			if(!AccountData[playerid][pHasKTP]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Kartu Tanda Penduduk/sudah expired!");

			ShowJobCenterTD(playerid);
			SelectTextDraw(playerid, Y_Nexston);
		}
	}
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 2.0, 2478.1804,48.2690,1069.6959))
    {
		if(!AccountData[playerid][pKnockdown])
		{
			if(!AccountData[playerid][pHasKTP]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Kartu Tanda Penduduk/sudah expired!");

			static string[555];
			format(string, sizeof(string), ""WHITE"Selamat datang di Balai Kota Pemerintah Kota Nexston!\n\
			Anda saat ini sudah memiliki total slip gaji senilai "GREEN"$%s\n\
			"YELLOW"( Apakah anda ingin mencairkannya sekarang? )", FormatMoney(AccountData[playerid][pSlipSalary]));
			Dialog_Show(playerid, "MySlipSalary", DIALOG_STYLE_MSGBOX, ""Nexston"Nexston Roleplay "WHITE"- Slip Gaji", string, "Yes", "No");
		}
	}
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && IsPlayerInRangeOfPoint(playerid, 2.0, 2487.0767,43.3927,1069.6959))
    {
		if(!AccountData[playerid][pKnockdown])
		{
			if(Iter_Count(PemerDuty) > 2) return ShowTDN(playerid, NOTIFICATION_ERROR, "Sedang ada Pemerintah yang sedang on duty!");
			if(AccountData[playerid][pHasKTP]) return ShowTDN(playerid, NOTIFICATION_ERROR, "kamu sudah memiliki KTP!");
			if(AccountData[playerid][pMoney] < 1500) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memuliki cukup uang untuk membuat KTP! ($2,500)");

			AccountData[playerid][pHasKTP] = true;
			AccountData[playerid][pKTPTime] = gettime() + (7 * 86400);
			ShowTDN(playerid, NOTIFICATION_SUCCESS, "kamu berhasil membuat KTP dengan masa aktip 7 hari.");
			TakePlayerMoneyEx(playerid, 1500);
		}
	}
	else if((newkeys & KEY_FIRE) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER && IsEngineVehicle(SavingVehID[playerid]))
    {
		if(!GetEngineStatus(SavingVehID[playerid]) && !AccountData[playerid][pTurningEngine])
		{
			AccountData[playerid][pTurningEngine] = true;
			SetTimerEx("EngineStatus", 2000, false, "id", playerid, SavingVehID[playerid]);
		}
	}
	else if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
		if(IsValidDynamicCP(AsuransiCP) && IsPlayerInDynamicCP(playerid, AsuransiCP))
		{
			//if(!AccountData[playerid][pHasKTP]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Kartu Tanda Penduduk/sudah expired!");
			if(CountPlayerVehicleInsuranced(playerid) < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki kendaraan apapun di asuransi!");
			static vid, countinsued, string[550];
			countinsued = CountPlayerVehicleInsuranced(playerid);
			format(string,sizeof(string),"No\tModel Kendaraan\tPlat Kendaraan\tBiaya Asuransi\n");
			for(new listed; listed < countinsued; listed++)
			{
				vid = ReturnVehicleIDInsuranced(playerid, listed);
				if(listed == countinsued)
				{
					format(string,sizeof(string), "%s%d\t%s\t%s\t"GREEN"$1,500", string, listed+1, GetVehicleModelName(PlayerVehicle[vid][pVehModelID]), PlayerVehicle[vid][pVehPlate]);
				}
				else format(string,sizeof(string), "%s%d\t%s\t%s\t"GREEN"$1,500\n", string, listed+1, GetVehicleModelName(PlayerVehicle[vid][pVehModelID]), PlayerVehicle[vid][pVehPlate]);
			}
			Dialog_Show(playerid, "VehicleInsurance", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Asuransi", string, "Pilih", "Batal");
		}

		if(AccountData[playerid][pHoldFlashlight])
		{
			if(AccountData[playerid][pFlashlightOn])
			{
				AccountData[playerid][pFlashlightOn] = false;
				RemovePlayerAttachedObject(playerid, 1);

				if(pToys[playerid][1][toy_model] != 0)
				{
					SetPlayerAttachedObject(playerid,
					1,
					pToys[playerid][1][toy_model],
					pToys[playerid][1][toy_bone],
					pToys[playerid][1][toy_x],
					pToys[playerid][1][toy_y],
					pToys[playerid][1][toy_z],
					pToys[playerid][1][toy_rx],
					pToys[playerid][1][toy_ry],
					pToys[playerid][1][toy_rz],
					pToys[playerid][1][toy_sx],
					pToys[playerid][1][toy_sy],
					pToys[playerid][1][toy_sz],
					pToys[playerid][1][matcolor1][4],
					pToys[playerid][1][matcolor2][4]);
				}

				ShowTDN(playerid, NOTIFICATION_INFO, "Flashlight ~r~dimatikan!");
			}
			else
			{
				AccountData[playerid][pFlashlightOn] = true;
				SetPlayerAttachedObject(playerid, 1, 19295, 1, -0.054999, 2.060999, -0.017000, 89.999992, 88.799987, 82.899993, 1.000000, 1.000000, 1.000000);
				ShowTDN(playerid, NOTIFICATION_INFO, "Flashlight ~g~dihidupkan!");
			}
		}
	}
    return 1;
}

Dialog:PlayerHelp(playerid, response, listitem, inputtext[])
{
	if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

	switch(listitem)
	{
		case 0: //perintah dasar
		{
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Perintah Dasar", 
			"Daftar Perintah\tKeterangan\n\
			/cc\tuntuk membersihkan chatlog di layar\n\
			"GRAY"/togchatanim\t"GRAY"untuk toggle animasi ketika berbicara\n\
			/id\tuntuk melihat detail dari player lain\n\
			"GRAY"/admins\t"GRAY"melihat daftar admin di server\n\
			/help\tmelihat bantuan seputar CMD\n\
			"GRAY"/qa\t"GRAY"jawab quiz dari admin\n\
			/cursor\tmengembalikan cursor yang hilang\n\
			"GRAY"/setrender\t"GRAY"atur render object mappingan sesuai spek device\n\
			/stopsong\tmatikan musik yang sedang terdengar\n\
			"GRAY"/elist\t"GRAY"lihat daftar nama animasi\n\
			/flist\tlihat jumlah anggota faction on duty\n\
			"GRAY"/fams\t"GRAY"melihat badside official Nexston\n\
			/hidektd\tsembunyikan textdraw KTP\n\
			"GRAY"/report\t"GRAY"lapor sesuatu kepada admin lapangan\n\
			/pay\tberi uang\n\
			"GRAY"/accept\t"GRAY"menerima sesuatu/transaksi\n\
			/ask\tajukan pertanyaan kepada admin lapangan\n\
			"GRAY"/toggle\t"GRAY"buka pengaturan toggle\n\
			/carry\tgendong orang lain\n\
			"GRAY"/fixme\t"GRAY"auto fix bug yang sedang terjadi\n\
			/dlog\tbuka damagelog karaktermu\n\
			"GRAY"/stats\t"GRAY"melihat statistik akun/karakter\n\
			/stopsmoke\tberhenti merokok\n\
			"GRAY"/stopeating\t"GRAY"berhenti makan\n\
			/stopdrinking\tberhenti minum\n\
			"GRAY"/sid\t"GRAY"melihat ID dan Nama UCP pemain lain", "Tutup", "");
		}
		case 1: //perintah kendaraan
		{
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Perintah Kendaraan", 
			"Daftar Perintah\tKeterangan\n\
			/en\tuntuk hidupkan/matikan mesin\n\
			"GRAY"/myv\t"GRAY"lihat list kendaraan yang dimiliki\n\
			/sellveh\tjual kendaraan pada orang lain\n\
			"GRAY"/sl\t"GRAY"tetapkan speed limit/matikan speed limit\n\
			/eject\tkeluarkan paksa orang lain dari kendaraan", "Tutup", "");
		}
		case 2: //perintah roleplay
		{
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Perintah Roleplay", 
			"Daftar Perintah\tKeterangan\n\
			/ado\tmenerangkan situasi dengan label teks\n\
			"GRAY"/me\t"GRAY"menerangkan aktivitas rp dengan memunculkannya di atas kepala\n\
			/do\tmenjelaskan suasana rp dengan memunculkannya di atas kepala\n\
			"GRAY"/w\t"GRAY"berbisik kepada karakter lain\n\
			/b\tlokal chat OOC\n\
			"GRAY"/o\t"GRAY"global chat OOC", "Tutup", "");
		}
		case 3: //petunjuk dasar
		{
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Petunjuk Dasar", 
			"Daftar Perintah\tKeterangan\n\
			/sv\tuntuk mengganti mode suara\n\
			"GRAY"/e (nama animasi)\t"GRAY"untuk memainkan animasi\n\
			/eprop (nama animasi)\tuntuk memainkan animasi property", "Tutup", "");
		}
		case 4: //petunjuk lapar haus
		{
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Nexston"Nexston Roleplay "WHITE"- Petunjuk Lapar Haus", 
			""WHITE"Dikarenakan Nexston merupakan server dengan mode Roleplay, tentu saja karakter anda\n\
			dapat merasakan lapar dan haus hingga stress.\n\
			Bagaimana cara membedakannya dan menemukannya di layar monitor anda?\n\n\
			Secara umum ketiganya terletak di bawah layar kiri monitor anda,\n\
			Lapar -> Ditandai dengan progress bar berwarna "YELLOW"kuning "WHITE"yang terdapat icon makanan.\n\
			Haus -> Ditandai dengan progress bar berwarna {009dc4}biru.\n\
			"WHITE"Stress -> Ditandai dengan progress bar berwarna "RED"merah.\n\n\
			"WHITE"Anda harus menggunakan item makanan & minuman untuk mengisi kebutuhan lapar & haus,\n\
			apabila "ORANGE"kosong "WHITE"sama sekali maka karakter akan pingsan otomatis. Progress bar stress\n\
			sendiri dirancang cukup unik dimana anda justru mencegahnya untuk penuh, apabila stress mencapai\n\
			kategori tinggi maka karakter akan mengalami "ORANGE"pusing "WHITE"dan layar anda kebiru-biruan.\n\
			Untuk menuruni stress anda dapat pergi ke "ORANGE"GYM "WHITE"atau mengonsumsi marijuana jika\n\
			anda memilikinya ataupun mengonsumsi pil stress.", "Tutup", "");
		}
		case 5: //racing system
		{
			//Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Nexston"Nexston Roleplay "WHITE"- Perintah Racing", 
			//"Fitur ini dinonaktifkan sementara.", "Tutup", "");
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Perintah Racing", 
			"Daftar Perintah\tKeterangan\n\
			/race create\tuntuk membuat balapan\n\
			/race reset\tmenghapus balapan yang sedang dibuat\n\
			/race start\tmembuka balapan agar dapat dimasuki player lain\n\
			/race join\tbergabung ke dalam balapan\n\
			/race leave\tkeluar dari balapan", "Tutup", "");
		}
		case 6: //hotkeys
		{
			Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Hotkeys", 
			"Daftar Perintah\tKeterangan\n\
			Tombol P\tuntuk membuka smartphone\n\
			"GRAY"Tombol I\t"GRAY"untuk membuka tas/inventory\n\
			Tombol Z\tuntuk mengubah jarak voice chat\n\
			"GRAY"Tombol U\t"GRAY"untuk buka/kunci kendaraan\n\
			Tombol 1\tuntuk menggunakan item yang berada di slot 1\n\
			"GRAY"Tombol 2\t"GRAY"untuk menggunakan item yang berada di slot 2\n\
			Tombol 3\tuntuk menggunakan item yang berada di slot 3\n\
			"GRAY"Tombol 4\t"GRAY"untuk menggunakan item yang berada di slot 4\n\
			Tombol R\tuntuk membuka radio\n\
			"GRAY"Tombol X\t"GRAY"untuk menghentikan animasi\n\
			Tombol N\tuntuk membuka radial menu\n\
			"GRAY"Jongkok + ALT\t"GRAY"untuk mengambil item di atas tanah\n\
			Tombol F\tkeluar-masuk interior", "Tutup", "");
		}
	}
	return 1;
}

Dialog:SetMapRender(playerid, response, listitem, inputtext[])
{
	if(!response)
	{
		return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
	}

	switch(listitem)
	{
		case 0: //soft
		{
			AccountData[playerid][pRenderSetting] = 0.3;
			Streamer_SetRadiusMultiplier(STREAMER_TYPE_OBJECT, 0.3, playerid);
			ShowTDN(playerid, NOTIFICATION_INFO, "The render has been changed to ~r~soft!");
		}
		case 1: //medium
		{
			AccountData[playerid][pRenderSetting] = 0.6;
			Streamer_SetRadiusMultiplier(STREAMER_TYPE_OBJECT, 0.6, playerid);
			ShowTDN(playerid, NOTIFICATION_INFO, "The render has been changed to ~y~medium!");
		}
		case 2: //hard
		{
			AccountData[playerid][pRenderSetting] = 1.0;
			Streamer_SetRadiusMultiplier(STREAMER_TYPE_OBJECT, 1.0, playerid);
			ShowTDN(playerid, NOTIFICATION_INFO, "The render has been changed to ~g~hard!");
		}
	}
	return 1;
}

Dialog:VehicleHoslter(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		AccountData[playerid][pMenuShowed] = false;
		NearestVehicleID[playerid] = INVALID_VEHICLE_ID;

		if(AccountData[playerid][pTempVehIterID] != -1)
			SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);

		AccountData[playerid][pTempVehIterID] = -1;
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
		return 1;
	}

	if(AccountData[playerid][pTempVehIterID] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan kendaraan apapun!");
	if (IsPlayerHunting[playerid]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus keluar dari mode hunting sebelum akses holster!");
	if (AccountData[playerid][pTaser]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat akses holster sambil menggunakan taser!");
	if (AccountData[playerid][pUseBeanbag]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat akses holster sambil menggunakan beanbag!");

	switch (listitem)
	{
		case 0: // Save
		{
			static wpid[MAX_PLAYERS];
			wpid[playerid] = GetPlayerWeaponEx(playerid);
			if (wpid[playerid] < 1 || wpid[playerid] > 45)
			{
				SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
				AccountData[playerid][pTempVehIterID] = -1;
				AccountData[playerid][pMenuShowed] = false;
				return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memegang senjata apapun!");
			}

			if(GunData[playerid][g_aWeaponSlots[wpid[playerid]]][WeaponType] != WEAPON_TYPE_PLAYER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menyimpan senjata jenis faction atau admin!");

			if (wpid[playerid] != 40)
			{
				if(GunData[playerid][g_aWeaponSlots[wpid[playerid]]][WeaponType] == WEAPON_TYPE_NONE)
				{
					SendClientMessageEx(playerid, Y_RED, "[AntiCheat] {DBD7D2}You are kicked from the server due to suspected Weapon Hack. "YELLOW"[Holster] [%s]", ReturnWeaponName(wpid[playerid]));
					SetWeapons(playerid); // Reload old weapons
					return KickEx(playerid);
				}

				if (IsValidVehicle(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic]))
				{
					for (new id; id < 3; ++id)
					{
						if (!VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterTaken][id])
						{
							VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterTaken][id] = true;
							GetPlayerWeaponData(playerid, g_aWeaponSlots[wpid[playerid]], VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][id], VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponAmmo][id]);
							SendRPMeAboveHead(playerid, sprintf("Menyimpan %s ke dalam holster %s.", ReturnWeaponName(wpid[playerid]), GetVehicleModelName(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehModelID])));

							ResetWeapon(playerid, wpid[playerid]);
							SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);

							static string[512];
							mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `vehicle_holster` (`Veh_DBID`, `WeaponID`, `WeaponAmmo`) VALUES (%d, %d, %d)", PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehID], VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][id], VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponAmmo][id]);
							mysql_pquery(g_SQL, string, "OnWeaponVStored", "id", AccountData[playerid][pTempVehIterID], id);

							AccountData[playerid][pTempVehIterID] = -1;
							AccountData[playerid][pMenuShowed] = false;
							break;
						}

						if (id == (3 - 1))
						{
							ShowTDN(playerid, NOTIFICATION_ERROR, "Holster kendaraan ini sudah penuh!");
						}
					}
				}
				AccountData[playerid][pTempVehIterID] = -1;
				AccountData[playerid][pMenuShowed] = false;
				return 1;
			}
		}
		case 1: // Retrieve
		{
			static string[512], count;
			format(string, sizeof(string), "#\tWeapon\tAmmo\n");
			for (new id; id < 3; ++id)
			{
				if (VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterTaken][id])
				{
					format(string, sizeof(string), "%s%d\t%s\t%d\n", string, id + 1, ReturnWeaponName(VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][id]), VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponAmmo][id]);
					count++;
				}
				else
				{
					format(string, sizeof(string), "%s"GREEN"%d\t"GREEN"Kosong\t"GREEN"0\n", string, id + 1);
				}
			}

			if (count == 0)
			{
				SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
				ShowTDN(playerid, NOTIFICATION_ERROR, "Holster kendaraan ini kosong!");
			}
			else
			{
				Dialog_Show(playerid, "VehicleHoslterWithdraw", DIALOG_STYLE_TABLIST_HEADERS, sprintf("%s Holster - Ambil Senjata", PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPlate]), string, "Pilih", "Batal");
			}
		}
	}
	return 1;
}

Dialog:VehicleHoslterWithdraw(playerid, response, listitem, inputtext[])
{
	if (!response)
	{
		AccountData[playerid][pMenuShowed] = false;
		SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
		NearestVehicleID[playerid] = INVALID_VEHICLE_ID;
		AccountData[playerid][pTempVehIterID] = -1;
		ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
		return 1;
	}

	if (listitem == -1 || listitem > 2)
	{
		AccountData[playerid][pMenuShowed] = false;
		SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
		NearestVehicleID[playerid] = INVALID_VEHICLE_ID;
		AccountData[playerid][pTempVehIterID] = -1;
		return 1;
	}

	if (!VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterTaken][listitem])
	{
		AccountData[playerid][pMenuShowed] = false;
		SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
		NearestVehicleID[playerid] = INVALID_VEHICLE_ID;
		AccountData[playerid][pTempVehIterID] = -1;

		ShowTDN(playerid, NOTIFICATION_ERROR, "Slot penyimpanan tersebut kosong!");
		return 1;
	}

	if(IsAFireArm(VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][listitem]) && AccountData[playerid][pLevel] < 5)
	{
		AccountData[playerid][pMenuShowed] = false;
		SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
		NearestVehicleID[playerid] = INVALID_VEHICLE_ID;
		AccountData[playerid][pTempVehIterID] = -1;

		ShowTDN(playerid, NOTIFICATION_ERROR, "Anda dapat memegang senjata jika sudah mencapai level 5 karakter!");
		return 1;
	}
	
	static string[512];
	mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `vehicle_holster` WHERE `Veh_DBID` = %d AND `ID` = %d", PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehID], VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterID][listitem]);
	mysql_pquery(g_SQL, string);

	SwitchVehicleBoot(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehPhysic], false);
	SendRPMeAboveHead(playerid, sprintf("Mengeluarkan %s dari holster %s.", ReturnWeaponName(VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][listitem]), GetVehicleModelName(PlayerVehicle[AccountData[playerid][pTempVehIterID]][pVehModelID])));
	GivePlayerWeaponEx(playerid, VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][listitem], VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponAmmo][listitem], WEAPON_TYPE_PLAYER);
	VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterTaken][listitem] = false;
	VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponID][listitem] = 0;
	VehicleHolster[AccountData[playerid][pTempVehIterID]][vHolsterWeaponAmmo][listitem] = 0;
	NearestVehicleID[playerid] = INVALID_VEHICLE_ID;
	AccountData[playerid][pTempVehIterID] = -1;
	AccountData[playerid][pMenuShowed] = false;
	return 1;
}

Dialog:ApplyFixme(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!"), 1;

    switch (listitem)
    {
        case 0: // Bug Visual (WWID)
        {
            if(AccountData[playerid][pInRusun] != -1)
            {
                SetPlayerVirtualWorldEx(playerid, AccountData[playerid][pInRusun]);
                SetPlayerInteriorEx(playerid, 1);
                SetPlayerPositionEx(playerid, 244.2521, 304.9150, 999.1484, 268.6741);
            }
            else if(AccountData[playerid][pInHouse] != -1)
            {
                SetPlayerVirtualWorldEx(playerid, HouseData[AccountData[playerid][pInHouse]][hIntWorld]);
                SetPlayerInteriorEx(playerid, HouseData[AccountData[playerid][pInHouse]][hIntInterior]);
                SetPlayerPositionEx(playerid, HouseData[AccountData[playerid][pInHouse]][hIntPos][0], HouseData[AccountData[playerid][pInHouse]][hIntPos][1], HouseData[AccountData[playerid][pInHouse]][hIntPos][2], HouseData[AccountData[playerid][pInHouse]][hIntPos][3]);
            }
            else if(AccountData[playerid][pInBiz] != -1)
            {
                SetPlayerVirtualWorldEx(playerid, BizData[AccountData[playerid][pInBiz]][bizIntVw]);
                SetPlayerInteriorEx(playerid, BizData[AccountData[playerid][pInBiz]][bizIntInt]);
                SetPlayerPositionEx(playerid, BizData[AccountData[playerid][pInBiz]][bizIntPos][0], BizData[AccountData[playerid][pInBiz]][bizIntPos][1], BizData[AccountData[playerid][pInBiz]][bizIntPos][2], BizData[AccountData[playerid][pInBiz]][bizIntPos][3]);
            }
            else if(AccountData[playerid][pInDoor] != -1)
            {
                SetPlayerVirtualWorldEx(playerid, DoorData[AccountData[playerid][pInDoor]][dIntvw]);
                SetPlayerInteriorEx(playerid, DoorData[AccountData[playerid][pInDoor]][dIntint]);
                SetPlayerPositionEx(playerid, DoorData[AccountData[playerid][pInDoor]][dIntposX], DoorData[AccountData[playerid][pInDoor]][dIntposY], DoorData[AccountData[playerid][pInDoor]][dIntposZ], DoorData[AccountData[playerid][pInDoor]][dIntposA]);
            }
            else
            {
                SetPlayerVirtualWorldEx(playerid, 0);
                SetPlayerInteriorEx(playerid, 0);
            }
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Visual bug telah diperbaiki!");
        }
        case 1: // Karakter Stuck
        {
            new Float:POS[3];
            GetPlayerPos(playerid, POS[0], POS[1], POS[2]);
            SetPlayerPos(playerid, POS[0], POS[1], POS[2] + 2.5);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Karakter anda telah dipindahkan!");
        }
        case 2: // Tidak Bisa Bergerak
        {
            if(IsPlayerStunned(playerid))
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat ini!"), 1;
            if(AccountData[playerid][pGetDraggedBy] != INVALID_PLAYER_ID)
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat sedang digendong/diseret!"), 1;

            TogglePlayerControllable(playerid, true);
            CancelSelectTextDraw(playerid);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Karakter anda sudah bisa bergerak kembali!");
        }
        case 3: // Bug Balai Kota
        {
            AccountData[playerid][pInDoor] = 27;
            AccountData[playerid][pInHouse] = -1;
            AccountData[playerid][pInBiz] = -1;
            AccountData[playerid][pInRusun] = -1;

            SetPlayerVirtualWorldEx(playerid, 99);
            SetPlayerInteriorEx(playerid, 3);
            SetPlayerPositionEx(playerid, DoorData[27][dIntposX], DoorData[27][dIntposY], DoorData[27][dIntposZ], DoorData[27][dIntposA]);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Bug balai kota telah diperbaiki!");
        }
    }
    return 1;
}


Dialog:FixesRequests(playerid, response, listitem, inputtext[])
{
	if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

	if(listitem == -1) return 1;
	
	static otherid, string[144];
	otherid = PlayerListitem[playerid][listitem];

	if (!IsPlayerConnected(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
	if (AccountData[otherid][pStuckRequest] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak membutuhkan fix request!");
	//if(AccountData[otherid][pRPQuizQuestion] != 0) return SEM(playerid, "The player is currently in an RP Quiz!");
	if(AccountData[otherid][pInEvent]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang berada di dalam event!");

	switch (AccountData[otherid][pStuckRequest])
	{
		case 1:
		{
			if(AccountData[otherid][pInRusun] != -1)
			{
				SetPlayerVirtualWorldEx(otherid, AccountData[otherid][pInRusun]);
				SetPlayerInteriorEx(otherid, 1);
				SetPlayerPositionEx(otherid, 244.2521, 304.9150, 999.1484, 268.6741);
			}
			else if(AccountData[otherid][pInHouse] != -1)
			{
				SetPlayerVirtualWorldEx(otherid, HouseData[AccountData[otherid][pInHouse]][hIntWorld]);
				SetPlayerInteriorEx(otherid, HouseData[AccountData[otherid][pInHouse]][hIntInterior]);
				SetPlayerPositionEx(otherid, HouseData[AccountData[otherid][pInHouse]][hIntPos][0], HouseData[AccountData[otherid][pInHouse]][hIntPos][1], HouseData[AccountData[otherid][pInHouse]][hIntPos][2], HouseData[AccountData[otherid][pInHouse]][hIntPos][3]);
			}
			else if(AccountData[otherid][pInBiz] != -1)
			{
				SetPlayerVirtualWorldEx(otherid, BizData[AccountData[otherid][pInBiz]][bizIntVw]);
				SetPlayerInteriorEx(otherid, BizData[AccountData[otherid][pInBiz]][bizIntInt]);
				SetPlayerPositionEx(otherid, BizData[AccountData[otherid][pInBiz]][bizIntPos][0], BizData[AccountData[otherid][pInBiz]][bizIntPos][1], BizData[AccountData[otherid][pInBiz]][bizIntPos][2], BizData[AccountData[otherid][pInBiz]][bizIntPos][3]);
			}
			else if(AccountData[otherid][pInDoor] != -1)
			{
				SetPlayerVirtualWorldEx(otherid, DoorData[AccountData[otherid][pInDoor]][dIntvw]);
				SetPlayerInteriorEx(otherid, DoorData[AccountData[otherid][pInDoor]][dIntint]);
				SetPlayerPositionEx(otherid, DoorData[AccountData[otherid][pInDoor]][dIntposX], DoorData[AccountData[otherid][pInDoor]][dIntposY], DoorData[AccountData[otherid][pInDoor]][dIntposZ], DoorData[AccountData[otherid][pInDoor]][dIntposA]);
			}
			else
			{
				SetPlayerVirtualWorldEx(otherid, 0);
				SetPlayerInteriorEx(otherid, 0);
			}

			AccountData[otherid][pStuckRequest] = 0;
			AccountData[otherid][pStuckWaiting] = 0;
			AccountData[playerid][pApoint]++;
			format(string, sizeof(string), "AdmCmd: %s telah menanggapi fix request anda.", AccountData[playerid][pAdminname]);
			SendClientMessage(otherid, Y_LIGHTRED, string);

			SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s telah menanggapi fix request dari %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
		}
		case 2:
		{
			new Float:POS[3];
			GetPlayerPos(otherid, POS[0], POS[1], POS[2]);
			SetPlayerPos(otherid, POS[0], POS[1], POS[2] + 2.5);

			AccountData[otherid][pStuckRequest] = 0;
			AccountData[otherid][pStuckWaiting] = 0;
			AccountData[playerid][pApoint]++;
			format(string, sizeof(string), "AdmCmd: %s telah menanggapi fix request anda.", AccountData[playerid][pAdminname]);
			SendClientMessage(otherid, Y_LIGHTRED, string);

			SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s telah menanggapi fix request dari %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
		}
		case 3:
		{
			if(IsPlayerStunned(otherid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut terkena stunned!");
			if (AccountData[otherid][pGetDraggedBy] != INVALID_PLAYER_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang digendong/diseret!");

			TogglePlayerControllable(otherid, true);
			CancelSelectTextDraw(otherid);

			AccountData[otherid][pStuckRequest] = 0;
			AccountData[otherid][pStuckWaiting] = 0;
			AccountData[playerid][pApoint]++;
			format(string, sizeof(string), "AdmCmd: %s telah menanggapi fix request anda.", AccountData[playerid][pAdminname]);
			SendClientMessage(otherid, Y_LIGHTRED, string);

			SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s telah menanggapi fix request dari %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
		}
		case 4:
		{
			AccountData[otherid][pInDoor] = 27;
			AccountData[otherid][pInHouse] = -1;
			AccountData[otherid][pInBiz] = -1;
			AccountData[otherid][pInRusun] = -1;

			SetPlayerVirtualWorldEx(otherid, 99);
			SetPlayerInteriorEx(otherid, 3);
			
			SetPlayerPositionEx(otherid, DoorData[AccountData[otherid][pInDoor]][dIntposX], DoorData[AccountData[otherid][pInDoor]][dIntposY], DoorData[AccountData[otherid][pInDoor]][dIntposZ], DoorData[AccountData[otherid][pInDoor]][dIntposA]);

			AccountData[otherid][pStuckRequest] = 0;
			AccountData[otherid][pStuckWaiting] = 0;
			AccountData[playerid][pApoint]++;
			format(string, sizeof(string), "AdmCmd: %s telah menanggapi fix request anda.", AccountData[playerid][pAdminname]);
			SendClientMessage(otherid, Y_LIGHTRED, string);

			SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s telah menanggapi fix request dari %s(%d).", AccountData[playerid][pAdminname], AccountData[otherid][pName], otherid);
		}
	}
	return 1;
}

Show_BadsideOnMember(playerid)
{
	new 
        curr_page = index_pagination[playerid],
		count = 0,
        string[1012],
        real_i = 0,
        memberslot_exist[MAX_PAGINATION_PAGES],
        memberslot_pid[MAX_PAGINATION_PAGES],
        curr_idx;

    curr_idx = MAX_PAGINATION_PAGES * curr_page;

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++) 
    {
        memberslot_exist[i] = false;
    }

    strcat(string, "Nama\tRank\tDurasi Online\n");
    foreach(new i : Player)
    {
        if(AccountData[i][pSpawned] && AccountData[i][pFamily] == AccountData[playerid][pFamily])
        {
            if (real_i >= curr_idx && real_i < curr_idx + MAX_PAGINATION_PAGES)
            {
                memberslot_exist[real_i - curr_idx] = true;
                memberslot_pid[real_i - curr_idx] = i;
            }
            real_i++;
        }
    }

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++) 
    {
        if(memberslot_exist[i])
        {
			new x = memberslot_pid[i];
            if (i % 2 == 0)
            {
                strcat(string, sprintf(""WHITE"%s\t"WHITE"%s\t"WHITE"%s\n", AccountData[x][pName], GetFamilyRankName(x), GetFormatTime(NetStats_GetConnectedTime(x)/1000)));
            }
            else
            {
                strcat(string, sprintf(""GRAY"%s\t"GRAY"%s\t"GRAY"%s\n", AccountData[x][pName], GetFamilyRankName(x), GetFormatTime(NetStats_GetConnectedTime(x)/1000)));
            }
			count++;
        }
    }

	new max_pages = (real_i + MAX_PAGINATION_PAGES - 1) / MAX_PAGINATION_PAGES;

	if (curr_page > 0) {
		strcat(string, ""RED"<< Sebelumnya\n");
	}
	if (curr_page < max_pages - 1) {
		strcat(string, ""GREEN">> Selanjutnya\n");
	}

	Dialog_Show(playerid, "FamonDialogList", DIALOG_STYLE_TABLIST_HEADERS, sprintf(""Nexston"Nexston Roleplay "WHITE"- Badside Online Member "GREEN"(%d)", count),
	string, "Tutup", "");
	return 1;
}

Show_FactionOnMember(playerid)
{
	new 
        curr_page = index_pagination[playerid],
		count = 0,
        string[1012],
        real_i = 0,
        memberslot_exist[MAX_PAGINATION_PAGES],
        memberslot_pid[MAX_PAGINATION_PAGES],
        curr_idx;

    curr_idx = MAX_PAGINATION_PAGES * curr_page;

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++) 
    {
        memberslot_exist[i] = false;
    }

    strcat(string, "Nama\tRank\tDurasi Online\n");
    foreach(new i : Player)
    {
        if(AccountData[i][pSpawned] && AccountData[i][pFaction] == AccountData[playerid][pFaction])
        {
            if (real_i >= curr_idx && real_i < curr_idx + MAX_PAGINATION_PAGES)
            {
                memberslot_exist[real_i - curr_idx] = true;
                memberslot_pid[real_i - curr_idx] = i;
            }
            real_i++;
        }
    }

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++) 
    {
        if(memberslot_exist[i])
        {
			new x = memberslot_pid[i];
            if (i % 2 == 0)
            {
                strcat(string, sprintf(""WHITE"%s\t"WHITE"%s\t"WHITE"%s\n", AccountData[x][pName], GetRankName(x), GetFormatTime(NetStats_GetConnectedTime(x)/1000)));
            }
            else
            {
                strcat(string, sprintf(""GRAY"%s\t"GRAY"%s\t"GRAY"%s\n", AccountData[x][pName], GetRankName(x), GetFormatTime(NetStats_GetConnectedTime(x)/1000)));
            }
			count++;
        }
    }

	new max_pages = (real_i + MAX_PAGINATION_PAGES - 1) / MAX_PAGINATION_PAGES;

	if (curr_page > 0) {
		strcat(string, ""RED"<< Sebelumnya\n");
	}
	if (curr_page < max_pages - 1) {
		strcat(string, ""GREEN">> Selanjutnya\n");
	}

	Dialog_Show(playerid, "FonDialogList", DIALOG_STYLE_TABLIST_HEADERS, sprintf(""Nexston"Nexston Roleplay "WHITE"- Faction Online Member "GREEN"(%d)", count),
	string, "Tutup", "");
	return 1;
}