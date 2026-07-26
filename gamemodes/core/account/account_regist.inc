forward CheckingWhitelistLogin(playerid);
public CheckingWhitelistLogin(playerid)
{
	static strba[512], rows;
	rows = cache_num_rows();
	if(!rows)
	{
		format(strba, sizeof(strba), ""WHITE"Mohon baca pesan ini sebelum melanjutkan, "RED"%s\n\n"WHITE"UCP yang anda gunakan saat ini belum terdaftar, segera ke discord untuk membuat akun UCP\nLink Discord: "YELLOW"discord.gg/vertexroleplay", AccountData[playerid][pUCP]);
		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Tiket Theater", strba, "Quit", "");

		//CallLocalFunction("PlayerKickedNotWhitelistedLog", "i", playerid);
		KickEx(playerid);
	}
	else
	{
		cache_get_value_name_int(0, "verify", tempverify[playerid]);
		cache_get_value_name_int(0, "recovery", temprecovery[playerid]);

		if(tempverify[playerid] != -1)
		{
			format(strba, sizeof(strba), ""WHITE"Selamat datang di "Vertex"Vertex Roleplay\n"WHITE"UCP ini telah terdaftar namun belum melakukan verifikasi!\nNama UCP: "DARK_SEA_GREEN_2"%s\n"YELLOW"(Silakan masukkan kode verifikasi):", AccountData[playerid][pUCP]);
			Dialog_Show(playerid, "VerificationLogin", DIALOG_STYLE_PASSWORD, ""Vertex"Vertex Roleplay "WHITE"- Verifikasi", strba, "Verify", "Batal");
		}
		else
		{
			if(temprecovery[playerid] != -1)
			{
				format(strba, sizeof(strba), "Selamat datang di "Vertex"Vertex Roleplay\nNama UCP: %s\n\
				Anda telah meminta layanan lupa password.\nKami telah mengirimkan anda kode recovery melalui DM discord anda.\n"YELLOW"(Mohon masukkan kode tersebut di bawah ini):", AccountData[playerid][pUCP]);
				Dialog_Show(playerid, "VerifPW", DIALOG_STYLE_PASSWORD, ""Vertex"Vertex Roleplay "WHITE"- Lupa Sandi", strba, "Input", "Batal");
			}
			else
			{
				ShowLoginDialog(playerid);
			}
		}
	}
	return 1;
}

forward CheckingWhitelistRegist(playerid);
public CheckingWhitelistRegist(playerid)
{
	static strba[512], rows;
	rows = cache_num_rows();
	
	if(!rows)
	{
		format(strba, sizeof(strba), ""WHITE"Mohon baca pesan ini sebelum melanjutkan, "RED"%s\n\n"WHITE"UCP yang anda gunakan saat ini belum terdaftar, segera ke discord untuk membuat akun UCP\nLink Discord: "YELLOW"discord.gg/vertexroleplay", AccountData[playerid][pUCP]);
		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Tiket Theater", strba, "Quit", "");

		//CallLocalFunction("PlayerKickedNotWhitelistedLog", "i", playerid);
		KickEx(playerid);
	}
	else
	{
		cache_get_value_name_int(0, "verify", tempverify[playerid]);

		if(tempverify[playerid] != -1)
		{
			format(strba, sizeof(strba), ""WHITE"Selamat datang di "Vertex"Vertex Roleplay\n"WHITE"UCP ini belum terdaftar dan terverifikasi!\nNama UCP: "RED"%s\n"YELLOW"(Silakan masukkan kode verifikasi):", AccountData[playerid][pUCP]);
			Dialog_Show(playerid, "Verification", DIALOG_STYLE_PASSWORD, ""Vertex"Vertex Roleplay "WHITE"- Tiket Theater", strba, "Verify", "Batal");
		}
		else
		{
			format(strba, sizeof(strba), ""WHITE"Selamat datang di "Vertex"Vertex Roleplay\n"WHITE"UCP ini belum terdaftar!\nNama UCP: "RED"%s\n"YELLOW"(Silakan masukkan kata sandi untuk mendaftar):", AccountData[playerid][pUCP]);
			Dialog_Show(playerid, "Register", DIALOG_STYLE_PASSWORD, "UCP - Register", strba, "Input", "Quit");
		}
	}
    return 1;
}

forward CheckPlayerUCP(playerid, race_check); //player yang connect dicek UCP nya ada apa tidak
public CheckPlayerUCP(playerid, race_check)
{
	if(race_check != g_MysqlRaceCheck[playerid]) return Kick(playerid);

	new query[512], rgdate[50], bool:isucpblocked, ucpblockdur, ucpblockreason[128], 
	ucpissueddate[30], ucpblockadminname[24];

	if(cache_num_rows() > 0)
	{
		cache_get_value_name(0, "Register_Date", rgdate);
		strcopy(UCPRegisterDate[playerid], rgdate); //udah dapat tanggal register UCP nya

		cache_get_value_name_int(0, "Blocked", isucpblocked);
		cache_get_value_name_int(0, "Block_Duration", ucpblockdur);
		cache_get_value_name(0, "Block_Reason", ucpblockreason);
		cache_get_value_name(0, "Block_AdminName", ucpblockadminname);
		cache_get_value_name(0, "Block_IssuedDate", ucpissueddate);
		cache_get_value_name_int(0, "FreeCar", TempFreeCar[playerid]);

		if(isucpblocked) //jika dibanned (true / 1)
		{
			new currentTime = gettime();
			if(ucpblockdur != 0 && ucpblockdur <= currentTime) // Unban the player.
			{
				mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_ucp` SET `Blocked`=0, `Block_Duration`=0, `Block_Reason`='', `Block_AdminName`='',  `Block_IssuedDate`='' WHERE `UCP`='%e'", AccountData[playerid][pUCP]);
				mysql_pquery(g_SQL, query);

				SendAdm(playerid, "Your banned status was over since %s ago.", ReturnTimelapse(ucpblockdur, gettime()));

				mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `whitelists` WHERE `ucp`='%e' LIMIT 1", AccountData[playerid][pUCP]);
				mysql_pquery(g_SQL, query, "CheckingWhitelistLogin", "i", playerid);
			}
			else
			{
				AccountData[playerid][IsLoggedIn] = false;
				SendAdm(playerid, "Your UCP has been blocked from the server!");

				if(ucpblockdur == 0)
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					new lstr[512];
					format(lstr, sizeof(lstr), ""WHITE"UCP Anda diblokir dari Vertex!\n\n\
					Berdasarkan Informasi:\n\
					"ORANGE"Nama UCP: "WHITE"%s\n\
					"ORANGE"IP Address: "WHITE"%s\n\
					"ORANGE"Admin On Duty: "WHITE"%s\n\
					"ORANGE"Tanggal diblokir: "WHITE"%s\n\
					"ORANGE"Reason: "WHITE"%s\n\
					"ORANGE"Durasi Blokir: "WHITE"Permanent\n\n\
					"YELLOW"INGAT: "WHITE"Jika anda ingin bermain lagi dan bertobat, masuk ke Discord: "YELLOW"discord.gg/vertexroleplay "WHITE"kemudian pilih channel #buka-blokir", 
					AccountData[playerid][pUCP], 
					AccountData[playerid][pIP], 
					ucpblockadminname, 
					ucpissueddate,
					ucpblockreason);
					Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- UCP Blocked", lstr, "Quit", "");
				}
				else
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					new lstr[512];
					format(lstr, sizeof(lstr), ""WHITE"UCP Anda diblokir dari Vertex!\n\n\
					Berdasarkan Informasi:\n\
					"ORANGE"Nama UCP: "WHITE"%s\n\
					"ORANGE"IP Address: "WHITE"%s\n\
					"ORANGE"Admin On Duty: "WHITE"%s\n\
					"ORANGE"Tanggal diblokir: "WHITE"%s\n\
					"ORANGE"Reason: "WHITE"%s\n\
					"ORANGE"Durasi Blokir: "WHITE"%s\n\n\
					"YELLOW"INGAT: "WHITE"Jika anda ingin bermain lagi dan bertobat, masuk ke Discord: "YELLOW"discord.gg/vertexroleplay "WHITE"kemudian pilih channel #buka-blokir", 
					AccountData[playerid][pUCP], 
					AccountData[playerid][pIP], 
					ucpblockadminname, 
					ucpissueddate,
					ucpblockreason,
					ReturnTimelapse(gettime(), ucpblockdur), ""DARKGREEN"Selesai");
					Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- UCP Blocked", lstr, "Quit", "");
				}

				//CallLocalFunction("PlayerKickedBlockedUCPLog", "i", playerid);
				KickEx(playerid);
			}
		}
		else
		{
			mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `whitelists` WHERE `ucp`='%e' LIMIT 1", AccountData[playerid][pUCP]);
			mysql_pquery(g_SQL, query, "CheckingWhitelistLogin", "i", playerid);
		}
	}
	else
	{
		mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `whitelists` WHERE `ucp`='%e' LIMIT 1", AccountData[playerid][pUCP]);
		mysql_pquery(g_SQL, query, "CheckingWhitelistRegist", "i", playerid);
	}
	return 1;
}

forward CheckBan(playerid);
public CheckBan(playerid)
{
	new cQuery[315];
	
	if(cache_num_rows() > 0)
	{
		new Reason[40], PlayerName[24], BannedName[24];
	    new banTime_Int, banDate, banIP[16];
		cache_get_value_name(0, "name", BannedName);
		cache_get_value_name(0, "admin", PlayerName);
		cache_get_value_name(0, "reason", Reason);
		cache_get_value_name(0, "ip", banIP);
		cache_get_value_name_int(0, "ban_expire", banTime_Int);
		cache_get_value_name_int(0, "ban_date", banDate);

		new currentTime = gettime();
        if(banTime_Int != 0 && banTime_Int <= currentTime) // Unban the player.
		{
			new query[512];
			mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `player_bans` WHERE `name` = '%e'", AccountData[playerid][pName]);
			mysql_pquery(g_SQL, query);

			SendAdm(playerid, "Selamat datang di Vertex, status ban sudah selesai sejak %s.", ReturnTimelapse(banTime_Int, gettime()));

			mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT * FROM `player_characters` WHERE `Char_Name` = '%e' LIMIT 1", AccountData[playerid][pName]);
			mysql_pquery(g_SQL, cQuery, "LoadCharacterData", "i", playerid);
		}
		else
		{
			new query[512];
  			mysql_format(g_SQL, query, sizeof query, "UPDATE `player_bans` SET `last_activity_timestamp` = %i WHERE `name` = '%e'", gettime(), AccountData[playerid][pName]);
			mysql_pquery(g_SQL, query);

			AccountData[playerid][IsLoggedIn] = false;
			
			SendAdm(playerid, "Anda telah dibanned dari server!");
			if(banTime_Int == 0)
			{
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new lstr[512];
				format(lstr, sizeof(lstr), ""WHITE"Anda dibanned dari server!\n\nInformasi:\nNama: %s\nIP: %s\nAdmin: %s\nTanggal dibanned: %s\nReason: %s\nDurasi Banned: Permanent\n\nMerasa tidak bersalah terkena banned? Appeal di "YELLOW"discord.gg/vertexroleplay", BannedName, banIP, PlayerName, ReturnDate(banDate), Reason);
				Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Banned", lstr, "Quit", "");
			}
			else
			{
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new lstr[512];
				format(lstr, sizeof(lstr), ""WHITE"Anda dibanned dari server!\n\nInformasi:\nNama: %s\nIP: %s\nAdmin: %s\nTanggal dibanned: %s\nReason: %s\nDurasi Banned: %s\n\nMerasa tidak bersalah terkena banned? Appeal di "YELLOW"discord.gg/vertexroleplay", BannedName, banIP, PlayerName, ReturnDate(banDate), Reason, ReturnTimelapse(gettime(), banTime_Int));
				Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Banned", lstr, "Quit", "");
			}
			KickEx(playerid);
  		}
	}
	else
	{
		mysql_format(g_SQL, cQuery, sizeof(cQuery), "SELECT * FROM `player_characters` WHERE `Char_Name` = '%e' LIMIT 1", AccountData[playerid][pName]);
		mysql_pquery(g_SQL, cQuery, "LoadCharacterData", "i", playerid);
	}
	return 1;
}

forward OnPasswordHashed(playerid); //register player passwordnya di hash sama bcrypt
public OnPasswordHashed(playerid)
{
	new str[256], query[256], pwhashed[BCRYPT_HASH_LENGTH], PlayerIP[16];

	bcrypt_get_hash(pwhashed);
	GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
	mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `player_ucp` (`UCP`, `IP`, `Password`, `Register_Date`, `Last_Login`) VALUES ('%e', '%e', '%e', CURRENT_TIMESTAMP(), CURRENT_TIMESTAMP())", AccountData[playerid][pUCP], PlayerIP, pwhashed);
	mysql_pquery(g_SQL, query);
	
    format(str, sizeof(str), ""WHITE"Selamat, akun anda telah berhasil didaftarkan!\n"WHITE"Nama UCP: "DARK_SEA_GREEN_2"%s\n"YELLOW"(Mohon masukkan password di bawah ini untuk login):", AccountData[playerid][pUCP]);
	Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "UCP - Login", str, "Input", "Quit");
	pLoginTimer[playerid] = SetTimerEx("OnPlayerNotLogin", 60000, false, "i", playerid);
	return 1;
}

forward OnPlayerPasswordChecked(playerid, bool:success);
public OnPlayerPasswordChecked(playerid, bool:success)
{
    if(!success)
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        TempPasswordLogin[playerid][0] = EOS;
        LoginAttempts[playerid]++;

        if(LoginAttempts[playerid] >= 3)
        {
            LoginAttempts[playerid] = 0;
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "UCP - Login","Anda telah salah memasukkan kata sandi 3 kali.\n\n"YELLOW"Anda telah ditendang dari server!", "Quit", "");
            return KickEx(playerid);
        }

        static strnotif[128];
        format(strnotif, sizeof(strnotif), "Password salah! Sisa kesempatan: %dx", 3 - LoginAttempts[playerid]);
        ShowTDN(playerid, NOTIFICATION_ERROR, strnotif);
        ShowLoginDialog(playerid, strnotif);
        return 1;
    }

    LoginAttempts[playerid] = 0;
    TempPasswordLogin[playerid][0] = EOS;

    new query[555];
    mysql_format(g_SQL, query, sizeof(query), "SELECT `Char_Name`, `Char_Level`, `Char_Money`, `Char_BankMoney` FROM `player_characters` WHERE `Char_UCP` = '%e' LIMIT %d", AccountData[playerid][pUCP], MAX_CHARS);
    mysql_pquery(g_SQL, query, "LoadCharacter", "i", playerid);
    return 1;
}

forward OnLoginPassCheck(playerid, const password[]);
public OnLoginPassCheck(playerid, const password[])
{
	if(cache_num_rows())
	{
		new hash[BCRYPT_HASH_LENGTH];
		cache_get_value_index(0, 0, hash);
		bcrypt_verify(playerid, "OnPlayerPasswordChecked", password, hash);
		// strcat(TempPasswordLogin, password);
	}
	else
	{
		PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		ShowTDN(playerid, NOTIFICATION_ERROR, "Ada yang salah dengan database, silakan coba relog!");
		KickEx(playerid);
	}
	return 1;
}

forward OnPasswordRecChanged(playerid);
public OnPasswordRecChanged(playerid)
{
	new pwhashed[BCRYPT_HASH_LENGTH], query[842];

	bcrypt_get_hash(pwhashed);
	mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_ucp` SET `Password`='%e' WHERE `UCP`='%e'", pwhashed, AccountData[playerid][pUCP]);
	mysql_pquery(g_SQL, query);

	mysql_format(g_SQL, query, sizeof(query), "UPDATE `whitelists` SET `recovery`=-1 WHERE `ucp`='%e'", AccountData[playerid][pUCP]);
	mysql_pquery(g_SQL, query);

	new lstring[512];
	format(lstring, sizeof(lstring), ""WHITE"Selamat, recovery akun telah selesai!\n"WHITE"Nama UCP: "DARK_SEA_GREEN_2"%s\n"YELLOW"(Mohon masukkan password di bawah ini untuk login):", AccountData[playerid][pUCP]);
	Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "UCP - Login", lstring, "Input", "Quit");
	return 1;
}

/*forward InsertPlayerName(playerid, name[]); //player yang buat karakter baru nama karakternya dimasukkan ke mysql tabel characters
public InsertPlayerName(playerid, name[])
{
	new query[145];
	if(cache_num_rows() > 0)
	{
        Dialog_Show(playerid, MakeNewChar, DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Pembuatan Karakter", ""RED"ERROR: "WHITE"Nama sudah digunakan!\nMohon masukkan kembali\n\nCth: Udin_Ahmad, Jefri_Sianturi", "Input", "Kembali");
	}
	else
	{
		mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `player_characters` (`Char_Name`,`Char_UCP`) VALUES('%e','%e')", name, AccountData[playerid][pUCP]);
		mysql_pquery(g_SQL, query, "OnPlayerRegister", "i", playerid);

		SetPlayerName(playerid, name);

		strcopy(AccountData[playerid][pName], name);
	}
	return 1;
}*/

forward InsertPlayerName(playerid, const name[]); //player yang buat karakter baru nama karakternya dimasukkan ke mysql tabel characters
public InsertPlayerName(playerid, const name[])
{
	new query[1024], PlayerIP[16];
	if(cache_num_rows() > 0)
	{
        Dialog_Show(playerid, "MakeNewChar", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Pembuatan Karakter", ""RED"Error: "WHITE"Nama sudah digunakan!\nMohon masukkan kembali\n\nCth: Udin_Ahmad, Jefri_Sianturi", "Input", "Kembali");
	}
	else
	{
		GetPlayerIp(playerid, PlayerIP, sizeof(PlayerIP));
		mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `player_characters` (`Char_RegisterDate`,`Char_LastLogin`,`Char_IP`,`Char_Name`,`Char_UCP`,`Char_AdminName`,`Char_Skin`,`Char_Money`,`Char_BankMoney`) VALUES(CURRENT_TIMESTAMP(), CURRENT_TIMESTAMP(), '%e','%e','%e','%e', '250', '0', '0')", PlayerIP, name, AccountData[playerid][pUCP], AccountData[playerid][pUCP]);
		mysql_pquery(g_SQL, query, "OnPlayerRegister", "i", playerid);

		SetPlayerName(playerid, name);

		strcopy(AccountData[playerid][pName], name); //udah dapat nama karakternya
	}
	return 1;
}

forward OnPlayerRegister(playerid);
public OnPlayerRegister(playerid)
{
	if(AccountData[playerid][IsLoggedIn])
	{
		return PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
	}
	
	AccountData[playerid][pID] = cache_insert_id();

	AccountData[playerid][pSSN] = 0;

	AccountData[playerid][pSkin] = 2;
	AccountData[playerid][pWorld] = 0;
	AccountData[playerid][pInterior] = 0;
	AccountData[playerid][pInDoor] = -1;
	AccountData[playerid][pInHouse] = -1;
	AccountData[playerid][pInBiz] = -1;
	AccountData[playerid][pInRusun] = -1;
	AccountData[playerid][pInGudang] = -1;
	AccountData[playerid][pKnockdown] = false;
	AccountData[playerid][pKnockdownTime] = 0;
	AccountData[playerid][pAccDeathTime] = 0;
	
	AccountData[playerid][pUniform] = 1;

	AccountData[playerid][pGender] = 0;

	AccountData[playerid][pJob] = JOB_NONE;
	AccountData[playerid][pFightingStyle] = FIGHT_STYLE_NORMAL;

	AccountData[playerid][pFaction] = 0;
	AccountData[playerid][pFactionRank] = 0;
	AccountData[playerid][pBadge] = 0;

	AccountData[playerid][pOnDuty] = false;
	AccountData[playerid][pIsUsingUniform] = false;

	AccountData[playerid][pFamily] = -1;
	AccountData[playerid][pFamilyRank] = 0;

	AccountData[playerid][pJDM] = -1;
	AccountData[playerid][pJDMRank] = 0;
	AccountData[playerid][pJDMPoints] = 0;

	AccountData[playerid][pDirtyMoney] = 0;
	AccountData[playerid][pMoney] = 3000;
	AccountData[playerid][pDj] = 0;
	AccountData[playerid][pBankMoney] = 500;
	AccountData[playerid][pBankNumber] = 0;
	AccountData[playerid][pCasinoChip] = 0;
	AccountData[playerid][pAdmin] = 0;
	AccountData[playerid][pAdminGirl] = 0;
	AccountData[playerid][pAdminHelper] = 0;
	AccountData[playerid][pAdminVlounter] = 0;
	AccountData[playerid][pApoint] = 0;
	AccountData[playerid][pClaimGirl] = 0;
	AccountData[playerid][pClaimGoodside] = 0;
	strcopy(AccountData[playerid][pAdminname], AccountData[playerid][pUCP]);
	AccountData[playerid][pApprentice] = false;
	AccountData[playerid][pWitch] = false;
	AccountData[playerid][pWitchTime] = 0;
	AccountData[playerid][pStatus] = 0;

	AccountData[playerid][pVIP] = 0;
	AccountData[playerid][pVIPTime] = 0;

	AccountData[playerid][pHealth] = 100.0;
	AccountData[playerid][pArmor] = 0.0;
	AccountData[playerid][pLevel] = 1;

	AccountData[playerid][pWarn] = 0;

	AccountData[playerid][pHandleBadside] = 0;
	AccountData[playerid][pHandleGoodside] = 0;

	OJailData[playerid][jailed] = false;
	OJailData[playerid][jailCell] = -1;
	OJailData[playerid][jailAdmin][0] = EOS;
	OJailData[playerid][jailTime] = 0;
	OJailData[playerid][jailDur] = 0;
	OJailData[playerid][jailReason][0] = EOS;
	OJailData[playerid][jailFine] = 0;

	AccountData[playerid][pArrested] = false;
	AccountData[playerid][pArrestTime] = 0;

	AccountData[playerid][pGivenComServBy] = INVALID_PLAYER_ID;
    AccountData[playerid][pGiveComServTo] = INVALID_PLAYER_ID;
    AccountData[playerid][pCommunityService] = false;
    AccountData[playerid][pTotalComServed] = -1;
	AccountData[playerid][pHowMuchComServing] = 0;

	AccountData[playerid][pGVL1Lic] = false;
	AccountData[playerid][pGVL1LicTime] = 0;

	AccountData[playerid][pGVL2Lic] = false;
	AccountData[playerid][pGVL2LicTime] = 0;

	AccountData[playerid][pMBLic] = false;
	AccountData[playerid][pMBLicTime] = 0;

	AccountData[playerid][pBLic] = false;
	AccountData[playerid][pBLicTime] = 0;

	AccountData[playerid][pAir1Lic] = false;
	AccountData[playerid][pAir1LicTime] = 0;

	AccountData[playerid][pAir2Lic] = false;
	AccountData[playerid][pAir2LicTime] = 0;

	AccountData[playerid][pFirearmLic] = false;
	AccountData[playerid][pFirearmLicTime] = 0;

	AccountData[playerid][pHuntingLic] = false;
	AccountData[playerid][pHuntingLicTime] = 0;

	AccountData[playerid][pHouseSharedID] = -1;

	//toggle
	ToggleInfo[playerid][TogPM] = true;
	ToggleInfo[playerid][TogGOOC] = true;
	ToggleInfo[playerid][TogLogin] = false;
	ToggleInfo[playerid][TogLevel] = false;
	ToggleInfo[playerid][TogAdv] = true;
	ToggleInfo[playerid][TogAdmCmd] = true;

	AccountData[playerid][pHunger] = 100;
	AccountData[playerid][pThirst] = 100;
	AccountData[playerid][pStress] = 0;

	AccountData[playerid][pMarga] = -1;
	AccountData[playerid][pMargaRank] = 0;

	AccountData[playerid][pRenderSetting] = 1.0;

	AccountData[playerid][pHasKTP] = false;
	AccountData[playerid][pKTPTime] = 0;
	PlayerVoiceData[playerid][pHasRadio] = false;
	AccountData[playerid][pEarphone] = false;
	AccountData[playerid][pBoombox] = false;
	AccountData[playerid][pHasHuntingRifle] = false;

	AccountData[playerid][pHasGudangID] = -1;
	AccountData[playerid][pGudangRentTime] = 0;

	AccountData[playerid][pTutorialPassed] = false;
	
	AccountData[playerid][pWBTime] = 21600;
	AccountData[playerid][pHours] = 0;
	AccountData[playerid][pMinutes] = 0;
	AccountData[playerid][pSeconds] = 0;
	AccountData[playerid][pPaycheckIndex] = 0;
	AccountData[playerid][pSlipSalary] = 0;
	AccountData[playerid][pWaterInBucket] = 0;

	//delays
	AccountData[playerid][pMowingSidejobDelay] = 0;
	AccountData[playerid][pSweeperSidejobDelay] = 0;
	AccountData[playerid][pForkliftSidejobDelay] = 0;
	AccountData[playerid][pTrashCollectorDelay] = 0;
	AccountData[playerid][pPizzaSidejobDelay] = 0;
	AccountData[playerid][pTaxMinute] = 0;

	AccountData[playerid][pPos][0] = 1765.4015;
	AccountData[playerid][pPos][1] = -1949.4750;
	AccountData[playerid][pPos][2] = 14.1096;
	AccountData[playerid][pPos][3] = 357.3250;

	AccountData[playerid][pStarterPack] = 0;

	//weapon
	GunData[playerid][0][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][1][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][2][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][3][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][4][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][5][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][6][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][7][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][8][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][9][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][10][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][11][WeaponType] = WEAPON_TYPE_NONE;
	GunData[playerid][12][WeaponType] = WEAPON_TYPE_NONE;

	GunData[playerid][0][WeaponID] = 0;
	GunData[playerid][1][WeaponID] = 0;
	GunData[playerid][2][WeaponID] = 0;
	GunData[playerid][3][WeaponID] = 0;
	GunData[playerid][4][WeaponID] = 0;
	GunData[playerid][5][WeaponID] = 0;
	GunData[playerid][6][WeaponID] = 0;
	GunData[playerid][7][WeaponID] = 0;
	GunData[playerid][8][WeaponID] = 0;
	GunData[playerid][9][WeaponID] = 0;
	GunData[playerid][10][WeaponID] = 0;
	GunData[playerid][11][WeaponID] = 0;
	GunData[playerid][12][WeaponID] = 0;

	GunData[playerid][0][WeaponAmmo] = 0;
	GunData[playerid][1][WeaponAmmo] = 0;
	GunData[playerid][2][WeaponAmmo] = 0;
	GunData[playerid][3][WeaponAmmo] = 0;
	GunData[playerid][4][WeaponAmmo] = 0;
	GunData[playerid][5][WeaponAmmo] = 0;
	GunData[playerid][6][WeaponAmmo] = 0;
	GunData[playerid][7][WeaponAmmo] = 0;
	GunData[playerid][8][WeaponAmmo] = 0;
	GunData[playerid][9][WeaponAmmo] = 0;
	GunData[playerid][10][WeaponAmmo] = 0;
	GunData[playerid][11][WeaponAmmo] = 0;
	GunData[playerid][12][WeaponAmmo] = 0;

	SavePlayerRegister(playerid);
	
	Dialog_Show(playerid, "NewCharAge", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Birthday", "Please insert the birthday with following format hh/bb/tttt cth: (25/08/2001)", "Input", "");

	ShowItemBox(playerid, "Cash", sprintf("Received $%sx", FormatMoney(AccountData[playerid][pMoney])), 1212, 5);
	
	// Inventory_Add(playerid, "Ransel", 3026);
	// ShowItemBox(playerid, "Ransel", "Received 1x", 3026, 5);

	new query[228], rand = RandomEx(111111, 999999);
	new rek = rand+AccountData[playerid][pID];
	mysql_format(g_SQL, query, sizeof(query), "SELECT `Char_BankNumber` FROM `player_characters` WHERE `Char_BankNumber`='%d'", rek);
	mysql_pquery(g_SQL, query, "BankNewRek", "id", playerid, rek);

	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_phones` WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
	mysql_pquery(g_SQL, query, "OnPlayerBuySmartphone", "i", playerid);
	return 1;
}

SavePlayerRegister(playerid)
{
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

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JDM` = %d, ", cQuery, AccountData[playerid][pJDM]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JDMRank` = %d, ", cQuery, AccountData[playerid][pJDMRank]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JDMPoints` = %d, ", cQuery, AccountData[playerid][pJDMPoints]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Jailed` = %d, ", cQuery, OJailData[playerid][jailed]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailCell` = %d, ", cQuery, OJailData[playerid][jailCell]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailAdmin` = '%e', ", cQuery, OJailData[playerid][jailAdmin]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailTime` = %d, ", cQuery, OJailData[playerid][jailTime]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailDur` = %d, ", cQuery, OJailData[playerid][jailDur]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailReason` = '%e', ", cQuery, OJailData[playerid][jailReason]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JailFine` = %d, ", cQuery, OJailData[playerid][jailFine]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_JobKargoBisnisTime` = '%d', ", cQuery, AccountData[playerid][pJobKargoBisnisTime]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Marga` = %d, ", cQuery, AccountData[playerid][pMarga]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_MargaRank` = %d, ", cQuery, AccountData[playerid][pMargaRank]);

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

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_HouseSharedID` = %d, ", cQuery, AccountData[playerid][pHouseSharedID]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_TutorialPassed` = %d, ", cQuery, AccountData[playerid][pTutorialPassed]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_WBTime` = %d, ", cQuery, AccountData[playerid][pWBTime]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Hours` = %d, ", cQuery, AccountData[playerid][pHours]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Minutes` = %d, ", cQuery, AccountData[playerid][pMinutes]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Seconds` = %d, ", cQuery, AccountData[playerid][pSeconds]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_Seconds` = %d, ", cQuery, AccountData[playerid][pSeconds]);

	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferInAmount` = %d, ", cQuery, AccountData[playerid][pLastTransferInAmount]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferInDate` = '%e', ", cQuery, AccountData[playerid][pLastTransferInDate]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferOutAmount` = %d, ", cQuery, AccountData[playerid][pLastTransferOutAmount]);
	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_LastTransferOutDate` = '%e', ", cQuery, AccountData[playerid][pLastTransferOutDate]);


	mysql_format(g_SQL, cQuery, sizeof(cQuery), "%s`Char_UCP` = '%e' WHERE `pID` = %d", cQuery, AccountData[playerid][pUCP], AccountData[playerid][pID]);
	mysql_pquery(g_SQL, cQuery);

	mysql_format(g_SQL, cQuery2, sizeof(cQuery2), "UPDATE `player_ucp` SET `Last_Login` = CURRENT_TIMESTAMP() WHERE `ID` = %d", AccountData[playerid][pID]);
	mysql_pquery(g_SQL, cQuery2);
	return 1;
}

stock bool:IsValidNameUCP(const name[])
{
    new len = strlen(name);
    if (len < 5 || len > 10) return false;
    for (new i = 0; i < len; i++)
    {
        if (!(name[i] >= 'A' && name[i] <= 'Z') &&
            !(name[i] >= 'a' && name[i] <= 'z'))
        {
            return false;
        }
    }
    return true;
}


