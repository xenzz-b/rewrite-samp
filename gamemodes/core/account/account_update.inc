UpdateAccountData(playerid)
{
	if(!AccountData[playerid][IsLoggedIn]) 
		return 1;

	if(!AccountData[playerid][pInEvent])
	{
		if(IsPlayerInAnyVehicle(playerid))
		{
			if(IsATruck(GetPlayerVehicleID(playerid)))
			{
				RemovePlayerFromVehicle(playerid);
				GetPlayerPos(playerid, AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2]);
				AccountData[playerid][pPos][2] = AccountData[playerid][pPos][2]+0.4;
			}
			else
			{
				GetPlayerPos(playerid, AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2]);
			}
		}
		else
		{
			GetPlayerPos(playerid, AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2]);
		}
		GetPlayerFacingAngle(playerid, AccountData[playerid][pPos][3]);

		new Float:svHP, Float:svAP;
		GetPlayerHealth(playerid, svHP);
		GetPlayerArmour(playerid, svAP);

		// Batasi dengan ledger hanya bila sudah spawn, agar nilai tersimpan
		// tidak tertimpa 0 saat player masih di kelas / belum spawn.
		if(AccountData[playerid][pSpawned] && !AccountData[playerid][pAdminDuty])
		{
			if(svHP > AC_LedgerHP[playerid])     svHP = AC_LedgerHP[playerid];
			if(svAP > AC_LedgerArmour[playerid]) svAP = AC_LedgerArmour[playerid];

			if(svHP < 0.0) svHP = 0.0;
			if(svAP < 0.0) svAP = 0.0;

			AccountData[playerid][pHealth] = svHP;
			AccountData[playerid][pArmor]  = svAP;
		}
	}
	
	if(IsPlayerHunting[playerid])
    {
        ResetWeapon(playerid, 34);
    }

	if(AccountData[playerid][pSideJob] == SIDEJOB_PIZZA)
	{
		AccountData[playerid][pPizzaSidejobDelay] = 1800;
	}
	
	static cQuery[4885], cQuery2[144];

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "UPDATE `player_characters` SET ");

	//POSISI TERAKHIR PLAYER
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastLogin` = CURRENT_TIMESTAMP(), ", cQuery);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Name` = '%e', ", cQuery, AccountData[playerid][pName]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_SSN` = %d, ", cQuery, AccountData[playerid][pSSN]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_AdminName` = '%e', ", cQuery, AccountData[playerid][pAdminname]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_DonatorTag` = '%e', ", cQuery, DonatorData[playerid][pDTag]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Admin` = %d, ", cQuery, AccountData[playerid][pAdmin]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_AdminGirl` = %d, ", cQuery, AccountData[playerid][pAdminGirl]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_AdminHelper` = %d, ", cQuery, AccountData[playerid][pAdminHelper]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_AdminVlounter` = %d, ", cQuery, AccountData[playerid][pAdminVlounter]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Apprentice` = %d, ", cQuery, AccountData[playerid][pApprentice]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Witch` = %d, ", cQuery, AccountData[playerid][pWitch]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WitchTime` = %d, ", cQuery, AccountData[playerid][pWitchTime]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Apoint` = %d, ", cQuery, AccountData[playerid][pApoint]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_VIP` = %d, ", cQuery, AccountData[playerid][pVIP]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_VIPTime` = %d, ", cQuery, AccountData[playerid][pVIPTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_DirtyMoney` = %d, ", cQuery, AccountData[playerid][pDirtyMoney]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Money` = %d, ", cQuery, AccountData[playerid][pMoney]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_BankMoney` = %d, ", cQuery, AccountData[playerid][pBankMoney]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_BankNumber` = %d, ", cQuery, AccountData[playerid][pBankNumber]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_CasinoChip` = %d, ", cQuery, AccountData[playerid][pCasinoChip]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_PosX` = '%.3f', ", cQuery, AccountData[playerid][pPos][0]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_PosY` = '%.3f', ", cQuery, AccountData[playerid][pPos][1]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_PosZ` = '%.3f', ", cQuery, AccountData[playerid][pPos][2]+0.5);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Health` = '%.2f', ", cQuery, AccountData[playerid][pHealth]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Armor` = '%.2f', ", cQuery, AccountData[playerid][pArmor]);

	if(!AccountData[playerid][pInEvent])
	{
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WID` = %d, ", cQuery, GetPlayerVirtualWorld(playerid));
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_IntID` = %d, ", cQuery, GetPlayerInterior(playerid));
	}
	else
	{
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WID` = %d, ", cQuery, AccountData[playerid][pWorld]);
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_IntID` = %d, ", cQuery, AccountData[playerid][pInterior]);
	}

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Birthday` = '%e', ", cQuery, AccountData[playerid][pBirthday]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Origin` = '%e', ", cQuery, AccountData[playerid][pOrigin]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Gender` = %d, ", cQuery, AccountData[playerid][pGender]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_BodyHeight` = %d, ", cQuery, AccountData[playerid][pBodyHeight]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_BodyWeight` = %d, ", cQuery, AccountData[playerid][pBodyWeight]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Skin` = %d, ", cQuery, AccountData[playerid][pSkin]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Level` = %d, ", cQuery, AccountData[playerid][pLevel]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Uniform` = %d, ", cQuery, AccountData[playerid][pUniform]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Job` = %d, ", cQuery, AccountData[playerid][pJob]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_FightStyle` = %d, ", cQuery, AccountData[playerid][pFightingStyle]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JobKargoBisnisTime` = '%d', ", cQuery, AccountData[playerid][pJobKargoBisnisTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_InDoor` = %d, ", cQuery, AccountData[playerid][pInDoor]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_InHouse` = %d, ", cQuery, AccountData[playerid][pInHouse]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_InBiz` = %d, ", cQuery, AccountData[playerid][pInBiz]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_InRusun` = %d, ", cQuery, AccountData[playerid][pInRusun]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Hunger` = %d, ", cQuery, AccountData[playerid][pHunger]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Thirst` = %d, ", cQuery, AccountData[playerid][pThirst]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Stress` = %d, ", cQuery, AccountData[playerid][pStress]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Faction` = %d, ", cQuery, AccountData[playerid][pFaction]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_FactionRank` = %d, ", cQuery, AccountData[playerid][pFactionRank]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Badge` = %d, ", cQuery, AccountData[playerid][pBadge]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_OnDuty` = %d, ", cQuery, AccountData[playerid][pOnDuty]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_UsingUniform` = %d, ", cQuery, AccountData[playerid][pIsUsingUniform]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Family` = %d, ", cQuery, AccountData[playerid][pFamily]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_FamilyRank` = %d, ", cQuery, AccountData[playerid][pFamilyRank]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Jailed` = %d, ", cQuery, OJailData[playerid][jailed]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailCell` = %d, ", cQuery, OJailData[playerid][jailCell]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailAdmin` = '%e', ", cQuery, OJailData[playerid][jailAdmin]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailTime` = %d, ", cQuery, OJailData[playerid][jailTime]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailDur` = %d, ", cQuery, OJailData[playerid][jailDur]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailReason` = '%e', ", cQuery, OJailData[playerid][jailReason]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailFine` = %d, ", cQuery, OJailData[playerid][jailFine]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Arrest` = %d, ", cQuery, AccountData[playerid][pArrested]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_ArrestTime` = %d, ", cQuery, AccountData[playerid][pArrestTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_ComServing` = %d, ", cQuery, AccountData[playerid][pHowMuchComServing]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Warn` = %d, ", cQuery, AccountData[playerid][pWarn]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TogPM` = %d, ", cQuery, ToggleInfo[playerid][TogPM]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TogGOOC` = %d, ", cQuery, ToggleInfo[playerid][TogGOOC]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TogLogin` = %d, ", cQuery, ToggleInfo[playerid][TogLogin]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TogLevel` = %d, ", cQuery, ToggleInfo[playerid][TogLevel]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TogAdv` = %d, ", cQuery, ToggleInfo[playerid][TogAdv]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TogAdmCmd` = %d, ", cQuery, ToggleInfo[playerid][TogAdmCmd]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_XmasGiftTime` = %d, ", cQuery, AccountData[playerid][pXmasGiftTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_RenderSetting` = '%f', ", cQuery, AccountData[playerid][pRenderSetting]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_KTP` = %d, ", cQuery, AccountData[playerid][pHasKTP]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_KTPTime` = %d, ", cQuery, AccountData[playerid][pKTPTime]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Radio` = %d, ", cQuery, PlayerVoiceData[playerid][pHasRadio]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Earphone` = %d, ", cQuery, AccountData[playerid][pEarphone]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Boombox` = %d, ", cQuery, AccountData[playerid][pBoombox]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HuntingRifle` = %d, ", cQuery, AccountData[playerid][pHasHuntingRifle]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HasGudangID` = %d, ", cQuery, AccountData[playerid][pHasGudangID]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_GudangRentTime` = %d, ", cQuery, AccountData[playerid][pGudangRentTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Knockdown` = %d, ", cQuery, AccountData[playerid][pKnockdown]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_KnockdownTime` = %d, ", cQuery, AccountData[playerid][pKnockdownTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_GVL1Lic` = %d, ", cQuery, AccountData[playerid][pGVL1Lic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_GVL1LicTime` = %d, ", cQuery, AccountData[playerid][pGVL1LicTime]);
	
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_GVL2Lic` = %d, ", cQuery, AccountData[playerid][pGVL2Lic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_GVL2LicTime` = %d, ", cQuery, AccountData[playerid][pGVL2LicTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_MBLic` = %d, ", cQuery, AccountData[playerid][pMBLic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_MBLicTime` = %d, ", cQuery, AccountData[playerid][pMBLicTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_BLic` = %d, ", cQuery, AccountData[playerid][pBLic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_BLicTime` = %d, ", cQuery, AccountData[playerid][pBLicTime]);
	
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Air1Lic` = %d, ", cQuery, AccountData[playerid][pAir1Lic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Air1LicTime` = %d, ", cQuery, AccountData[playerid][pAir1LicTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Air2Lic` = %d, ", cQuery, AccountData[playerid][pAir2Lic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Air2LicTime` = %d, ", cQuery, AccountData[playerid][pAir2LicTime]);
	
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_FirearmLic` = %d, ", cQuery, AccountData[playerid][pFirearmLic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_FirearmLicTime` = %d, ", cQuery, AccountData[playerid][pFirearmLicTime]);
	
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HuntingLic` = %d, ", cQuery, AccountData[playerid][pHuntingLic]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HuntingLicTime` = %d, ", cQuery, AccountData[playerid][pHuntingLicTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_MowingDelay` = %d, ", cQuery, AccountData[playerid][pMowingSidejobDelay]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_SweeperDelay` = %d, ", cQuery, AccountData[playerid][pSweeperSidejobDelay]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_ForkliftDelay` = %d, ", cQuery, AccountData[playerid][pForkliftSidejobDelay]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TrashCollectorDelay` = %d, ", cQuery, AccountData[playerid][pTrashCollectorDelay]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_PizzaDelay` = %d, ", cQuery, AccountData[playerid][pPizzaSidejobDelay]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TaxMinute` = %d, ", cQuery, AccountData[playerid][pTaxMinute]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HandleGoodside` = '%d', ", cQuery, AccountData[playerid][pHandleGoodside]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HandleBadside` = '%d', ", cQuery, AccountData[playerid][pHandleBadside]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HouseSharedID` = %d, ", cQuery, AccountData[playerid][pHouseSharedID]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TutorialPassed` = %d, ", cQuery, AccountData[playerid][pTutorialPassed]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WBTime` = %d, ", cQuery, AccountData[playerid][pWBTime]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Hours` = %d, ", cQuery, AccountData[playerid][pHours]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Minutes` = %d, ", cQuery, AccountData[playerid][pMinutes]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Seconds` = %d, ", cQuery, AccountData[playerid][pSeconds]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_SlipSalary` = %d, ", cQuery, AccountData[playerid][pSlipSalary]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WaterInBucket` = %d, ", cQuery, AccountData[playerid][pWaterInBucket]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Status` = %d, ", cQuery, AccountData[playerid][pStatus]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_ClaimGirl` = %d, ", cQuery, AccountData[playerid][pClaimGirl]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_ClaimGoodside` = %d, ", cQuery, AccountData[playerid][pClaimGoodside]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Marga` = %d, ", cQuery, AccountData[playerid][pMarga]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_MargaRank` = %d, ", cQuery, AccountData[playerid][pMargaRank]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_ClaimSP` = '%d', ", cQuery, AccountData[playerid][pStarterPack]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WeaponCooldown` = %d, ", cQuery, AccountData[playerid][pWeaponCooldown]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferInAmount` = %d, ", cQuery, AccountData[playerid][pLastTransferInAmount]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferInDate` = '%e', ", cQuery, AccountData[playerid][pLastTransferInDate]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferOutAmount` = %d, ", cQuery, AccountData[playerid][pLastTransferOutAmount]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferOutDate` = '%e', ", cQuery, AccountData[playerid][pLastTransferOutDate]);


	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_UCP` = '%e' WHERE `pID` = %d", cQuery, AccountData[playerid][pUCP], AccountData[playerid][pID]);
	mysql_pquery(g_SQL, cQuery);

	mysql_format(g_SQL, cQuery2, sizeof(cQuery2), "UPDATE `player_ucp` SET `Last_Login` = CURRENT_TIMESTAMP() WHERE `ID` = %d", AccountData[playerid][pID]);
	mysql_pquery(g_SQL, cQuery2);

	SavePlayerFashionToMysql(playerid);
	return 1;
}