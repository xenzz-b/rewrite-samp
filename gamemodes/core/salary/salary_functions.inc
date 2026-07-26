#include <YSI_Coding\y_hooks>

// Titik pencairan paycheck di Bank Pacific.
static const Float:g_PaycheckPoint[][3] =
{
	{1445.8564, -1136.7075, 23.9580},
	{1457.9396, -1126.6406, 23.9580}
};

IsPlayerNearPaycheckPoint(playerid)
{
	for(new i; i < sizeof(g_PaycheckPoint); i ++)
	{
		if(IsPlayerInRangeOfPoint(playerid, 3.0, g_PaycheckPoint[i][0], g_PaycheckPoint[i][1], g_PaycheckPoint[i][2]))
			return 1;
	}
	return 0;
}

CreatePaycheckLabels()
{
	for(new i; i < sizeof(g_PaycheckPoint); i ++)
	{
		CreateDynamicPickup(1274, 23, g_PaycheckPoint[i][0], g_PaycheckPoint[i][1], g_PaycheckPoint[i][2], 0, 0, -1, 30.00, -1, 0);
		CreateDynamic3DTextLabel(""GRAY"[Loket Pencairan Gaji]\n"WHITE"Gunakan "YELLOW"'/paycheck' "WHITE"untuk mencairkan gaji\n"WHITE"Gunakan "YELLOW"'/mysalary' "WHITE"untuk melihat rincian",
			Y_CYAN, g_PaycheckPoint[i][0], g_PaycheckPoint[i][1], g_PaycheckPoint[i][2] + 0.45, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
	}
	return 1;
}

// Tipe penghasilan pemain, dipakai untuk menentukan besaran dan sumber gaji.
#define SALARYTYPE_CITIZEN  0
#define SALARYTYPE_JOB      1
#define SALARYTYPE_FACTION  2

GetPlayerSalaryType(playerid)
{
	// Tipe faction hanya berlaku saat benar-benar bertugas. Anggota yang
	// sedang off duty diperlakukan sesuai pekerjaannya, atau sebagai warga.
	if(AccountData[playerid][pFaction] != FACTION_NONE && AccountData[playerid][pOnDuty])
		return SALARYTYPE_FACTION;

	if(AccountData[playerid][pJob] != JOB_NONE)
		return SALARYTYPE_JOB;

	return SALARYTYPE_CITIZEN;
}

// Besaran gaji per periode, menyesuaikan tipe penghasilan pemain.
GetPlayerDutySalary(playerid)
{
	switch(GetPlayerSalaryType(playerid))
	{
		case SALARYTYPE_FACTION:
		{
			new pay = SALARY_BASE + (AccountData[playerid][pFactionRank] * SALARY_PER_RANK);

			if(pay > SALARY_MAX)
				pay = SALARY_MAX;

			return pay;
		}
		case SALARYTYPE_JOB:
		{
			return SALARY_JOB;
		}
	}
	return SALARY_CITIZEN;
}

// Sumber gaji yang tercatat pada slip.
GetPlayerSalaryIssuer(playerid)
{
	static issuer[46];

	switch(GetPlayerSalaryType(playerid))
	{
		case SALARYTYPE_FACTION: format(issuer, sizeof(issuer), "%s", GetFactionName(playerid));
		case SALARYTYPE_JOB:     format(issuer, sizeof(issuer), "%s", GetJobName(playerid));
		default:                 format(issuer, sizeof(issuer), "Pemerintah Vertex");
	}
	return issuer;
}

// Keterangan alasan pada slip.
GetPlayerSalaryReason(playerid)
{
	static reason[46];

	switch(GetPlayerSalaryType(playerid))
	{
		case SALARYTYPE_FACTION: format(reason, sizeof(reason), "Gaji Bertugas");
		case SALARYTYPE_JOB:     format(reason, sizeof(reason), "Gaji Pekerjaan");
		default:                 format(reason, sizeof(reason), "Tunjangan Warga");
	}
	return reason;
}

AddPlayerSalary(playerid, const issuer[], money, const reason[])
{
	static string[514];
	static year, month, day, hour, minute, second;
	gettime(hour, minute, second);
	getdate(year, month, day);

	static date[128];
	format(date, sizeof (date), "%02d/%02d/%d %02d:%02d", day, month, year, hour, minute);

	SendClientMessage(playerid, -1, "Penghasilan anda ditambahkan ke "YELLOW"'/mysalary' "WHITE"silakan dilihat untuk lebih rinci!");
	ShowItemBox(playerid, "Salary Paper", "Received 1x", 2894, 5);

	mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `salary` (`owner`, `issuer`, `money`, `reason`, `date`) VALUES ('%d', '%e', '%d', '%e', '%e')", AccountData[playerid][pID], issuer, money, reason, date);
	mysql_pquery(g_SQL, string);
	return 1;
}

forward SalaryShowForPlayer(playerid);
public SalaryShowForPlayer(playerid)
{
    new rows = cache_num_rows();
    new string[1024];
    new curr_page = index_pagination[playerid];
    new curr_idx = MAX_PAGINATION_PAGES * curr_page;

    strcat(string, "Tanggal\tIssuer\tJumlah\tReason\n");

    new date[30], issuer[46], money, totalpaycheck, reason[46];

    if(rows) 
	{
        if(curr_page == 0) {
            for(new i = 0; i < rows; i++) {
                cache_get_value_name_int(i, "money", money);
                totalpaycheck += money;

            }
            strcat(string, sprintf(""WHITE"\t"WHITE"Grand Total:\t"GREEN"$%s\n", FormatMoney(totalpaycheck)));
        }

        for (new i = curr_idx; i < curr_idx + MAX_PAGINATION_PAGES && i < rows; i++) {

            cache_get_value_name(i, "date", date);
            cache_get_value_name(i, "issuer", issuer);
            cache_get_value_name(i, "reason", reason);
            cache_get_value_name_int(i, "money", money);
            strcat(string, sprintf(""WHITE"%s\t"WHITE"%s\t"GREEN"$%s\t"WHITE"%s\n", date, issuer, FormatMoney(money), reason));
        }

        new max_pages = (rows + MAX_PAGINATION_PAGES - 1) / MAX_PAGINATION_PAGES; 
        if (curr_page > 0) {
            strcat(string, ""RED"<< Sebelumnya\n");
        }
        if (curr_page < max_pages - 1) {
            strcat(string, ""GREEN">> Selanjutnya\n");
        }
        Dialog_Show(playerid, "PlayerSalaryList", DIALOG_STYLE_TABLIST_HEADERS, sprintf("Pending Salary: Page %d of %d", curr_page + 1, max_pages), string, "Tutup", "");
    }
    else 
	{
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki pending salary!");
    }
    return 1;
}

DisplaySalary(playerid)
{
	static query[144];
	mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `salary` WHERE `owner`='%d' ORDER BY `id` ASC", AccountData[playerid][pID]);
	mysql_pquery(g_SQL, query, "SalaryShowForPlayer", "i", playerid);
	return 1;
}

forward PaycheckShowForPlayer(playerid);
public PaycheckShowForPlayer(playerid)
{
    new rows = cache_num_rows();
	if(rows) 
	{
		static string[666], money, totalpaycheck, Float:zakat, newbalance;
		
		money = 0;
		totalpaycheck = 0;
		zakat = 0.0;

		for(new i; i < rows; i++)
		{
			cache_get_value_name_int(i, "money", money);
			totalpaycheck += money;
		}
		format(string, sizeof(string), ""WHITE"Previous Balance: "GREEN"$%s\n", FormatMoney(AccountData[playerid][pBankMoney]));
		strcat(string, sprintf(""WHITE"Paycheck: "GREEN"$%s\n", FormatMoney(totalpaycheck)), sizeof(string));

		if(totalpaycheck >= 36507)
		{
			zakat = floatround(totalpaycheck * 0.025);
			strcat(string, sprintf(""WHITE"Tax (2,5): "RED"$%s\n", FormatMoney(floatround(zakat))), sizeof(string));
		}
		else
		{
			strcat(string, ""WHITE"No Tax Payment\n", sizeof(string));
		}

		newbalance = AccountData[playerid][pBankMoney] + totalpaycheck - floatround(zakat);
		strcat(string, sprintf(""WHITE"New Balance: "GREEN"$%s\n", FormatMoney(newbalance)), sizeof(string));

		SendClientMessageEx(playerid, Y_CYAN, "<=================< {FFFFFF}Paycheck #%04d {00FFFF}>=================>", AccountData[playerid][pPaycheckIndex]);
		SendClientMessageEx(playerid, Y_CYAN, "=> {FFFFFF}Previous Balance: {00FF00}$%s", FormatMoney(AccountData[playerid][pBankMoney]));
		SendClientMessageEx(playerid, Y_CYAN, "=> {FFFFFF}Tax (2,5): "RED"$%s", FormatMoney(floatround(zakat)));
		SendClientMessageEx(playerid, Y_CYAN, "=> {FFFFFF}Paycheck: {00FF00}$%s", FormatMoney(totalpaycheck));
		SendClientMessageEx(playerid, Y_CYAN, "=> {FFFFFF}New Balance: {00FF00}$%s", FormatMoney(newbalance));
		SendClientMessage(playerid, Y_CYAN, "<===================================================>");

		AccountData[playerid][pPaycheckTime] = PAYCHECK_COOLDOWN;

		AccountData[playerid][pBankMoney] = newbalance;

		Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_LIST, sprintf("Paycheck #%04d", AccountData[playerid][pPaycheckIndex]), string, "Tutup", "");

		mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `salary` WHERE `owner`='%d'", AccountData[playerid][pID]);
		mysql_pquery(g_SQL, string);
	}
	else
	{
		// Tidak ada gaji tertunda. Tidak diberi uang apa pun supaya
		// pemain yang tidak bertugas tidak mendapat penghasilan pasif.
		ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki gaji tertunda untuk dicairkan!");
	}
    return 1;
}

DisplayPaycheck(playerid)
{
	static string[144];
	mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `salary` WHERE `owner`='%d' ORDER BY `id` ASC", AccountData[playerid][pID]);
	mysql_pquery(g_SQL, string, "PaycheckShowForPlayer", "i", playerid);
	return 1;
}

Dialog:PlayerSalaryList(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        if (!strcmp(inputtext, ">> Selanjutnya", true))
        {
            index_pagination[playerid]++;
            DisplaySalary(playerid);
        }
        else if (!strcmp(inputtext, "<< Sebelumnya", true))
        {
            index_pagination[playerid]--;
            if (index_pagination[playerid] < 0)
            {
                index_pagination[playerid] = 0;
            }
            DisplaySalary(playerid);
        }
    }
    return 1;
}

hook OnGameModeInit()
{
	CreatePaycheckLabels();
	return 1;
}
