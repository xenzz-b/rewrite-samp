forward LoadCharacterData(playerid);
public LoadCharacterData(playerid)
{
	static aname[MAX_PLAYER_NAME], jadmn[MAX_PLAYER_NAME], jrson[60], age[128], dtag[41], 
	regdate[50], lastlogin[50], string[168], tempname[25], tmporigin[32], tmpucp[22];
	if(cache_num_rows() > 0)
	{
		AccountData[playerid][IsLoggedIn] = true;
		
		cache_get_value_name_int(0, "pID", AccountData[playerid][pID]);

		cache_get_value_name(0, "Char_RegisterDate", regdate);
		strcopy(AccountData[playerid][pRegisterDate], regdate);
		cache_get_value_name(0, "Char_LastLogin", lastlogin);
		strcopy(AccountData[playerid][pLastLogin], lastlogin);

		cache_get_value_name_int(0, "Char_SSN", AccountData[playerid][pSSN]);

		cache_get_value_name(0, "Char_Name", tempname);
		strcopy(AccountData[playerid][pName], tempname);

		cache_get_value_name(0, "Char_AdminName", aname);
		strcopy(AccountData[playerid][pAdminname], aname);
		cache_get_value_name(0, "Char_DonatorTag", dtag);
		strcopy(DonatorData[playerid][pDTag], dtag);
		cache_get_value_name_int(0, "Char_Admin", AccountData[playerid][pAdmin]);
		cache_get_value_name_int(0, "Char_AdminGirl", AccountData[playerid][pAdminGirl]);
		cache_get_value_name_int(0, "Char_AdminHelper", AccountData[playerid][pAdminHelper]);
		cache_get_value_name_int(0, "Char_AdminVlounter", AccountData[playerid][pAdminVlounter]);
		cache_get_value_name_int(0, "Char_Apprentice", AccountData[playerid][pApprentice]);
		cache_get_value_name_int(0, "Char_Witch", AccountData[playerid][pWitch]);
		cache_get_value_name_int(0, "Char_WitchTime", AccountData[playerid][pWitchTime]);
		cache_get_value_name_int(0, "Char_Apoint", AccountData[playerid][pApoint]);

		cache_get_value_name_int(0, "Char_VIP", AccountData[playerid][pVIP]);
		cache_get_value_name_int(0, "Char_VIPTime", AccountData[playerid][pVIPTime]);

		cache_get_value_name_int(0, "Char_DirtyMoney", AccountData[playerid][pDirtyMoney]);
		cache_get_value_name_int(0, "Char_Money", AccountData[playerid][pMoney]);
		cache_get_value_name_int(0, "Char_BankMoney", AccountData[playerid][pBankMoney]);
		cache_get_value_name_int(0, "Char_BankNumber", AccountData[playerid][pBankNumber]);
		cache_get_value_name_int(0, "Char_CasinoChip", AccountData[playerid][pCasinoChip]);

		cache_get_value_name_float(0, "Char_PosX", AccountData[playerid][pPos][0]);
		cache_get_value_name_float(0, "Char_PosY", AccountData[playerid][pPos][1]);
		cache_get_value_name_float(0, "Char_PosZ", AccountData[playerid][pPos][2]);

		cache_get_value_name_float(0, "Char_Health", AccountData[playerid][pHealth]);
		cache_get_value_name_float(0, "Char_Armor", AccountData[playerid][pArmor]);

		cache_get_value_name_int(0, "Char_WID", AccountData[playerid][pWorld]);
		cache_get_value_name_int(0, "Char_IntID", AccountData[playerid][pInterior]);

		cache_get_value_name(0, "Char_Birthday", age);
		strcopy(AccountData[playerid][pBirthday], age);

		cache_get_value_name(0, "Char_Origin", tmporigin);
		strcopy(AccountData[playerid][pOrigin], tmporigin);
		cache_get_value_name_int(0, "Char_Gender", AccountData[playerid][pGender]);
		cache_get_value_name_int(0, "Char_BodyHeight", AccountData[playerid][pBodyHeight]);
		cache_get_value_name_int(0, "Char_BodyWeight", AccountData[playerid][pBodyWeight]);
		cache_get_value_name_int(0, "Char_Skin", AccountData[playerid][pSkin]);

		cache_get_value_name_int(0, "Char_Level", AccountData[playerid][pLevel]);
		cache_get_value_name_int(0, "Char_Uniform", AccountData[playerid][pUniform]);
		cache_get_value_name_int(0, "Char_Job", AccountData[playerid][pJob]);
		cache_get_value_name_int(0, "Char_FightStyle", AccountData[playerid][pFightingStyle]);
		cache_get_value_name_int(0, "Char_JobKargoBisnisTime", AccountData[playerid][pJobKargoBisnisTime]);

		cache_get_value_name_int(0, "Char_InDoor", AccountData[playerid][pInDoor]);
		cache_get_value_name_int(0, "Char_InHouse", AccountData[playerid][pInHouse]);
		cache_get_value_name_int(0, "Char_InBiz", AccountData[playerid][pInBiz]);
		cache_get_value_name_int(0, "Char_InRusun", AccountData[playerid][pInRusun]);

		cache_get_value_name_int(0, "Char_Hunger", AccountData[playerid][pHunger]);
		cache_get_value_name_int(0, "Char_Thirst", AccountData[playerid][pThirst]);
		cache_get_value_name_int(0, "Char_Stress", AccountData[playerid][pStress]);

		cache_get_value_name_int(0, "Char_Faction", AccountData[playerid][pFaction]);
		cache_get_value_name_int(0, "Char_FactionRank", AccountData[playerid][pFactionRank]);
		cache_get_value_name_int(0, "Char_Badge", AccountData[playerid][pBadge]);

		cache_get_value_name_int(0, "Char_OnDuty", AccountData[playerid][pOnDuty]);
		cache_get_value_name_int(0, "Char_UsingUniform", AccountData[playerid][pIsUsingUniform]);

		cache_get_value_name_int(0, "Char_Family", AccountData[playerid][pFamily]);
		cache_get_value_name_int(0, "Char_FamilyRank", AccountData[playerid][pFamilyRank]);

		cache_get_value_name_int(0, "Char_JDM", AccountData[playerid][pJDM]);
		cache_get_value_name_int(0, "Char_JDMRank", AccountData[playerid][pJDMRank]);
		cache_get_value_name_int(0, "Char_JDMPoints", AccountData[playerid][pJDMPoints]);

		cache_get_value_name_int(0, "Char_Marga", AccountData[playerid][pMarga]);
		cache_get_value_name_int(0, "Char_MargaRank", AccountData[playerid][pMargaRank]);

		//handlegoodside && handlebadside
		cache_get_value_name_int(0, "Char_HandleGoodside", AccountData[playerid][pHandleGoodside]);
		cache_get_value_name_int(0, "Char_HandleBadside", AccountData[playerid][pHandleBadside]);

		//get jail data
		cache_get_value_name_int(0, "Char_Jailed", OJailData[playerid][jailed]);
		cache_get_value_name_int(0, "Char_JailCell", OJailData[playerid][jailCell]);

		cache_get_value_name(0, "Char_JailAdmin", jadmn);
		strcopy(OJailData[playerid][jailAdmin], jadmn);

		cache_get_value_name_int(0, "Char_JailTime", OJailData[playerid][jailTime]);
		cache_get_value_name_int(0, "Char_JailDur", OJailData[playerid][jailDur]);

		cache_get_value_name(0, "Char_JailReason", jrson);
		strcopy(OJailData[playerid][jailReason], jrson);

		cache_get_value_name_int(0, "Char_JailFine", OJailData[playerid][jailFine]);

		cache_get_value_name_int(0, "Char_Arrest", AccountData[playerid][pArrested]);
		cache_get_value_name_int(0, "Char_ArrestTime", AccountData[playerid][pArrestTime]);

		cache_get_value_name_int(0, "Char_ComServing", AccountData[playerid][pHowMuchComServing]);

		cache_get_value_name_int(0, "Char_Warn", AccountData[playerid][pWarn]);

		cache_get_value_name_int(0, "Char_TogPM", ToggleInfo[playerid][TogPM]);
		cache_get_value_name_int(0, "Char_TogGOOC", ToggleInfo[playerid][TogGOOC]);
		cache_get_value_name_int(0, "Char_TogLogin", ToggleInfo[playerid][TogLogin]);
		cache_get_value_name_int(0, "Char_TogLevel", ToggleInfo[playerid][TogLevel]);
		cache_get_value_name_int(0, "Char_TogAdv", ToggleInfo[playerid][TogAdv]);
		cache_get_value_name_int(0, "Char_TogAdmCmd", ToggleInfo[playerid][TogAdmCmd]);

		cache_get_value_name_int(0, "Char_XmasGiftTime", AccountData[playerid][pXmasGiftTime]);

		cache_get_value_name_float(0, "Char_RenderSetting", AccountData[playerid][pRenderSetting]);

		cache_get_value_name_int(0, "Char_KTP", AccountData[playerid][pHasKTP]);
		cache_get_value_name_int(0, "Char_KTPTime", AccountData[playerid][pKTPTime]);
		cache_get_value_name_int(0, "Char_Radio", PlayerVoiceData[playerid][pHasRadio]);
		cache_get_value_name_int(0, "Char_Earphone", AccountData[playerid][pEarphone]);
		cache_get_value_name_int(0, "Char_Boombox", AccountData[playerid][pBoombox]);
		cache_get_value_name_int(0, "Char_HuntingRifle", AccountData[playerid][pHasHuntingRifle]);

		cache_get_value_name_int(0, "Char_HasGudangID", AccountData[playerid][pHasGudangID]);
		cache_get_value_name_int(0, "Char_GudangRentTime", AccountData[playerid][pGudangRentTime]);

		cache_get_value_name_int(0, "Char_Knockdown", AccountData[playerid][pKnockdown]);
		cache_get_value_name_int(0, "Char_KnockdownTime", AccountData[playerid][pKnockdownTime]);
		
		cache_get_value_name_int(0, "Char_GVL1Lic", AccountData[playerid][pGVL1Lic]);
		cache_get_value_name_int(0, "Char_GVL1LicTime", AccountData[playerid][pGVL1LicTime]);

		cache_get_value_name_int(0, "Char_GVL2Lic", AccountData[playerid][pGVL2Lic]);
		cache_get_value_name_int(0, "Char_GVL2LicTime", AccountData[playerid][pGVL2LicTime]);

		cache_get_value_name_int(0, "Char_MBLic", AccountData[playerid][pMBLic]);
		cache_get_value_name_int(0, "Char_MBLicTime", AccountData[playerid][pMBLicTime]);
		
		cache_get_value_name_int(0, "Char_BLic", AccountData[playerid][pBLic]);
		cache_get_value_name_int(0, "Char_BLicTime", AccountData[playerid][pBLicTime]);

		cache_get_value_name_int(0, "Char_Air1Lic", AccountData[playerid][pAir1Lic]);
		cache_get_value_name_int(0, "Char_Air1LicTime", AccountData[playerid][pAir1LicTime]);

		cache_get_value_name_int(0, "Char_Air2Lic", AccountData[playerid][pAir2Lic]);
		cache_get_value_name_int(0, "Char_Air2LicTime", AccountData[playerid][pAir2LicTime]);

		cache_get_value_name_int(0, "Char_FirearmLic", AccountData[playerid][pFirearmLic]);
		cache_get_value_name_int(0, "Char_FirearmLicTime", AccountData[playerid][pFirearmLicTime]);

		cache_get_value_name_int(0, "Char_HuntingLic", AccountData[playerid][pHuntingLic]);
		cache_get_value_name_int(0, "Char_HuntingLicTime", AccountData[playerid][pHuntingLicTime]);

		cache_get_value_name_int(0, "Char_MowingDelay", AccountData[playerid][pMowingSidejobDelay]);
		cache_get_value_name_int(0, "Char_SweeperDelay", AccountData[playerid][pSweeperSidejobDelay]);
		cache_get_value_name_int(0, "Char_ForkliftDelay", AccountData[playerid][pForkliftSidejobDelay]);
		cache_get_value_name_int(0, "Char_TrashCollectorDelay", AccountData[playerid][pTrashCollectorDelay]);
		cache_get_value_name_int(0, "Char_PizzaDelay", AccountData[playerid][pPizzaSidejobDelay]);
		cache_get_value_name_int(0, "Char_TaxMinute", AccountData[playerid][pTaxMinute]);

		cache_get_value_name_int(0, "Char_HouseSharedID", AccountData[playerid][pHouseSharedID]);
		
		cache_get_value_name_int(0, "Char_TutorialPassed", AccountData[playerid][pTutorialPassed]);
		cache_get_value_name_int(0, "Char_WBTime", AccountData[playerid][pWBTime]);
		cache_get_value_name_int(0, "Char_Hours", AccountData[playerid][pHours]);
		cache_get_value_name_int(0, "Char_Minutes", AccountData[playerid][pMinutes]);
		cache_get_value_name_int(0, "Char_Seconds", AccountData[playerid][pSeconds]);
		cache_get_value_name_int(0, "Char_AdminDutyHours", AccountData[playerid][pAdminDutyHours]);
		cache_get_value_name_int(0, "Char_AdminDutyMinutes", AccountData[playerid][pAdminDutyMinutes]);
		cache_get_value_name_int(0, "Char_SlipSalary", AccountData[playerid][pSlipSalary]);
		cache_get_value_name_int(0, "Char_WaterInBucket", AccountData[playerid][pWaterInBucket]);
		cache_get_value_name_int(0, "Char_Status", AccountData[playerid][pStatus]);
		cache_get_value_name_int(0, "Char_ClaimGirl", AccountData[playerid][pClaimGirl]);
		cache_get_value_name_int(0, "Char_ClaimGoodside", AccountData[playerid][pClaimGoodside]);

		cache_get_value_name_int(0, "Char_LastTransferInAmount", AccountData[playerid][pLastTransferInAmount]);
		cache_get_value_name_int(0, "Char_LastTransferOutAmount", AccountData[playerid][pLastTransferOutAmount]);

		new tmpTransferInDate[16], tmpTransferOutDate[16];
		cache_get_value_name(0, "Char_LastTransferInDate", tmpTransferInDate);
		strcopy(AccountData[playerid][pLastTransferInDate], tmpTransferInDate);
		cache_get_value_name(0, "Char_LastTransferOutDate", tmpTransferOutDate);
		strcopy(AccountData[playerid][pLastTransferOutDate], tmpTransferOutDate);

		cache_get_value_name_int(0, "Char_ClaimSP", AccountData[playerid][pStarterPack]);
		cache_get_value_name_int(0, "Char_WeaponCooldown", AccountData[playerid][pWeaponCooldown]);
		if(AccountData[playerid][pWeaponCooldown] > 0)
		{
			AccountData[playerid][pWeaponCooldownActive] = true;
			
			new str[64];
			format(string, sizeof(str), "~r~Weapon locked~n~~w~%d seconds remaining", AccountData[playerid][pWeaponCooldown]);
			GameTextForPlayer(playerid, str, 5000, 3);
		}
		else
		{
			AccountData[playerid][pWeaponCooldownActive] = false;
		}

		cache_get_value_name(0, "Char_UCP", tmpucp);
		strcopy(AccountData[playerid][pUCP], tmpucp);

		//new g_strQuery[256];
		//mysql_format(g_SQL, g_strQuery, sizeof(g_strQuery), "DELETE FROM player_characters");
		//mysql_pquery(g_SQL, g_strQuery);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `inventory` WHERE `Owner_ID` = %d LIMIT %d", AccountData[playerid][pID], MAX_INVENTORY);
		mysql_pquery(g_SQL, string, "LoadPlayerItems", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_weapons` WHERE `Owner_ID` = %d LIMIT 1", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerWeapons", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `gudang_brankas` WHERE `Owner` = %d LIMIT %d", AccountData[playerid][pID], MAX_GUDANG_ITEMS);
		mysql_pquery(g_SQL, string, "LoadGudangBrankas", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `rusun_brankas` WHERE `Owner` = %d LIMIT %d", AccountData[playerid][pID], MAX_RUSUN_ITEMS);
		mysql_pquery(g_SQL, string, "LoadRusunBrankas", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `house_brankas` WHERE `Owner` = %d LIMIT %d", AccountData[playerid][pID], MAX_HOUSE_ITEMS);
		mysql_pquery(g_SQL, string, "LoadHouseBrankas", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `invoices` WHERE `Owner` = %d LIMIT %d", AccountData[playerid][pID], MAX_INVOICES);
		mysql_pquery(g_SQL, string, "LoadPlayerInvoices", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_warns` WHERE `Owner_ID` = %d LIMIT 100", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerWarns", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_phones` WHERE `phoneOwner` = %d LIMIT 1", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerPhone", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `phone_contacts` WHERE `contactOwnerID` = %d LIMIT %d", AccountData[playerid][pID], MAX_CONTACTS);
		mysql_pquery(g_SQL, string, "LoadPlayerContact", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `documents` WHERE `Owner_ID` = %d", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerDocuments", "i", playerid);

		EditingWeapon[playerid] = 0;

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `gunpos` WHERE `Owner` = %d LIMIT 1", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "OnWeaponsLoaded", "d", playerid);
		
		Streamer_SetRadiusMultiplier(STREAMER_TYPE_OBJECT, AccountData[playerid][pRenderSetting], playerid);
		SetPlayerName(playerid, AccountData[playerid][pName]);

		//CallLocalFunction("PlayerLoginLog", "i", playerid);

		if(AccountData[playerid][pHealth] < 5.0) AccountData[playerid][pHealth] = 100.00;

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_clothes` WHERE `Owner`=%d", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerClothes", "i", playerid);

		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_toys` WHERE `Owner`='%e' LIMIT 1", AccountData[playerid][pName]);
		mysql_pquery(g_SQL, string, "LoadPlayerFashion", "i", playerid);
		
		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `avtreasure` WHERE `Owner_ID` = %d LIMIT 1", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerAVTreasure", "i", playerid);

		/*
		static fileName[144];
		format(fileName, sizeof(fileName), "PlayerEvent/%d.ini", AccountData[playerid][pID]);
		if(!dini_Exists(fileName))
		{
            dini_Create(fileName);
			dini_IntSet(fileName, "Pumpkin", 0);
		}
		else
		{
			AccountData[playerid][pPumpkins] = dini_Int(fileName, "Pumpkin");
		}
		*/
		
		RefreshMapJob(playerid);
		
		GetPlayerCountry(playerid, AccountData[playerid][pCountry], MAX_COUNTRY_LENGTH);
		GetPlayerCity(playerid, AccountData[playerid][pCity], MAX_CITY_LENGTH);
		
		SetPlayerFightingStyle(playerid, AccountData[playerid][pFightingStyle]);
		
		foreach(new i : Player)
		{
			if(ToggleInfo[i][TogLogin] && AccountData[i][pSpawned])
			{
				SendClientMessageEx(i, X11_GREY, "** %s[%d] telah terkoneksi ke dalam server (%s, %s).", AccountData[playerid][pName], playerid, AccountData[playerid][pCity], AccountData[playerid][pCountry]);
			}
		}

		/*if(AccountData[playerid][pFaction] != FACTION_NONE) //jika anggota fraksi
		{
			mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `demand_vehicles` WHERE `ownerid` = %d LIMIT 1", AccountData[playerid][pID]);
			mysql_pquery(g_SQL, string, "LoadPlayerFactVeh", "i", playerid);
		}
		else //jika bukan anggota fraksi
		{
			for(new x; x < MAX_FACTIONS; x++)
			{
				DestroyVehicle(PlayerFactionVehicle[playerid][x]);
			}
			LSPDPlayerCallsign[playerid][0] = EOS;

			mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `demand_vehicles` WHERE `ownerid` = %d", AccountData[playerid][pID]);
			mysql_pquery(g_SQL, string);
		}*/

		if(AccountData[playerid][pGender] == 0) //jika gender belum terisi dan player belum spawn
		{
			SetPlayerHealth(playerid, 100);
			SetPlayerArmour(playerid, 0);

			SendClientMessage(playerid, -1, "Pembuatan karakter sebelumnya belum sempurna, harap lakukan hingga selesai.");

			Dialog_Show(playerid, "NewCharAge", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Birthday", "Please insert the birthday with following format hh/bb/tttt cth: (25/08/2001)", "Input", "");
		}
		else
		{
			AVC_PConnected[playerid] = true;

			SetSpawnInfo(playerid, NO_TEAM, AccountData[playerid][pSkin], AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2], 0.0, 0, 0, 0, 0, 0, 0);
			TogglePlayerSpectating(playerid, false);

			SetCameraBehindPlayer(playerid);
			Anticheat[playerid][acImmunity] = gettime() + 5;
			GameTextForPlayer(playerid, "Memuat Objek...", 6500, 3);
		}
		mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_vehicles` WHERE `PVeh_Owner` = %d", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string, "LoadPlayerVehicle", "i", playerid);

		Iter_Init(VehicleKeyIndex[playerid]);
		for(new x = 0; x < 20; x++)
		{
			VehicleKeys[playerid][x][vKeyID] = -1;
			VehicleKeys[playerid][x][vKeyVehicleDBID] = -1;
			VehicleKeys[playerid][x][vKeyOwnerID] = -1;
			VehicleKeys[playerid][x][vKeyHolderID] = -1;
			VehicleKeys[playerid][x][vKeyHolderName][0] = EOS;
			VehicleKeys[playerid][x][vKeyExpireTime] = -1;
			VehicleKeys[playerid][x][vKeyGivenTime] = 0;
		}
						
		// Load kunci dari database
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `vehicle_keys` WHERE `HolderID` = %d AND (`ExpireTime` = 0 OR `ExpireTime` > UNIX_TIMESTAMP())", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, query, "LoadPlayerKeys", "i", playerid);
	}
	else
	{
		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Problem", 
		"Karkater anda tidak dapat kami temukan, database error!", "Tutup", "");
		KickEx(playerid);
	}
    return 1;
}

forward LoadCharacter(playerid);
public LoadCharacter(playerid) //jika sudah berhasil memasukkan password maka karakter list akan ditampilkan
{
	for (new i; i < MAX_CHARS; i ++)
	{
		PlayerChar[playerid][i][0] = EOS;
		PlayerCharLevel[playerid][i] = 1;
		PlayerCharCash[playerid][i] = 0;
		PlayerCharBank[playerid][i] = 0;
	}

	for (new i; i < cache_num_rows(); i ++)
	{
		cache_get_value_name(i, "Char_Name", PlayerChar[playerid][i]);
		cache_get_value_name_int(i, "Char_Level", PlayerCharLevel[playerid][i]);
		cache_get_value_name_int(i, "Char_Money", PlayerCharCash[playerid][i]);
		cache_get_value_name_int(i, "Char_BankMoney", PlayerCharBank[playerid][i]);
	}

	KillTimer(pLoginTimer[playerid]);
    pLoginTimer[playerid] = -1;

	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");
	SendClientMessage(playerid, X11_WHITE, "");

	ShowCharacterList(playerid);
  	return 1;
}