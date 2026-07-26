
new Float:JPJDriveCheckpoints[4][3] = {
    {-1612.0, 694.0, 7.0},
    {-1590.0, 720.0, 7.0},
    {-1565.0, 695.0, 7.0},
    {-1580.0, 670.0, 7.0}
};

new JPJDriveCP[MAX_PLAYERS];
new JPJDriveCPID[MAX_PLAYERS];
new bool:JPJInDriveTest[MAX_PLAYERS];

stock StartJPJDriveTest(playerid)
{
    JPJInDriveTest[playerid]                = true;
    JPJDriveCP[playerid]                    = 0;
    JPJTemp[playerid][jpjDriveViolations]   = 0;
    JPJTemp[playerid][jpjDriveNotes]        = "\0";

    SetJPJNextCheckpoint(playerid);
    ShowTDN(playerid, NOTIFICATION_INFO, "Ujian mengemudi dimulai! Kendarai ke checkpoint yang ditandai.");
}

stock JPJAddViolation(playerid, reason[])
{
    if(!JPJInDriveTest[playerid]) return;

    JPJTemp[playerid][jpjDriveViolations]++;

    new notes[256];
    format(notes, sizeof(notes), "%s[%d] %s | ",
        JPJTemp[playerid][jpjDriveNotes],
        JPJTemp[playerid][jpjDriveViolations],
        reason);
    strcopy(JPJTemp[playerid][jpjDriveNotes], notes);

    new msg[128];
    format(msg, sizeof(msg), "Pelanggaran #%d dicatat: %s", JPJTemp[playerid][jpjDriveViolations], reason);
    ShowTDN(playerid, NOTIFICATION_WARNING, msg);
}

stock SetJPJNextCheckpoint(playerid)
{
    if(JPJDriveCPID[playerid] != 0)
    {
        DestroyDynamicCP(JPJDriveCPID[playerid]);
        JPJDriveCPID[playerid] = 0;
    }

    new cp = JPJDriveCP[playerid];
    if(cp >= sizeof(JPJDriveCheckpoints))
    {
        FinishJPJDriveTest(playerid, true);
        return;
    }

    JPJDriveCPID[playerid] = CreateDynamicCP(
        JPJDriveCheckpoints[cp][0],
        JPJDriveCheckpoints[cp][1],
        JPJDriveCheckpoints[cp][2],
        3.0, -1, -1, playerid);

    new msg[64];
    format(msg, sizeof(msg), "Checkpoint %d/%d - Kendarai ke tanda merah!", cp + 1, sizeof(JPJDriveCheckpoints));
    ShowTDN(playerid, NOTIFICATION_INFO, msg);
}

stock FinishJPJDriveTest(playerid, bool:passed)
{
    if(JPJDriveCPID[playerid] != 0)
    {
        DestroyDynamicCP(JPJDriveCPID[playerid]);
        JPJDriveCPID[playerid] = 0;
    }

    JPJInDriveTest[playerid]          = false;
    JPJTemp[playerid][jpjPassedDrive] = passed;

    if(passed)
    {
        GrantPlayerLicense(playerid, JPJTemp[playerid][jpjLicType]);

        new msg[128];
        format(msg, sizeof(msg), "Selamat! Kamu lulus ujian mengemudi. SIM %s telah diberikan!",
            GetLicName(JPJTemp[playerid][jpjLicType]));
        ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);

        new str[256];
        format(str, sizeof(str),
            "{00FF00}SELAMAT!\n\n\
            {FFFFFF}Kamu berhasil mendapatkan {FFFF00}SIM %s{FFFFFF}!\n\
            SIM kamu berlaku selama {FFFF00}30 hari{FFFFFF}.\n\n\
            {FFFFFF}Berkendara dengan aman dan tertib!",
            GetLicName(JPJTemp[playerid][jpjLicType]));

        Dialog_Show(playerid, "JPJSuccess", DIALOG_STYLE_MSGBOX,
            "{00BFFF}Vertex Roleplay {FFFFFF}- SIM Berhasil Diterbitkan",
            str, "Tutup", "");
    }
    else
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu gagal ujian mengemudi! Silakan daftar ulang.");
    }

    ResetJPJTemp(playerid);
}

stock GrantPlayerLicense(playerid, lictype)
{
    new expTime = gettime() + JPJ_LIC_DURATION;
    switch(lictype)
    {
        case JPJ_LIC_MOTOR:
        {
            AccountData[playerid][pMBLic]      = 1;
            AccountData[playerid][pMBLicTime]  = expTime;
        }
        case JPJ_LIC_CAR:
        {
            AccountData[playerid][pGVL1Lic]     = 1;
            AccountData[playerid][pGVL1LicTime] = expTime;
        }
        case JPJ_LIC_TRUCK:
        {
            AccountData[playerid][pGVL2Lic]     = 1;
            AccountData[playerid][pGVL2LicTime] = expTime;
        }
        case JPJ_LIC_HELI:
        {
            AccountData[playerid][pAir1Lic]     = 1;
            AccountData[playerid][pAir1LicTime] = expTime;
        }
    }
    SaveJPJLicense(playerid);
}

stock RenewPlayerLicense(playerid, lictype)
{
    new expTime = gettime() + JPJ_LIC_DURATION;
    switch(lictype)
    {
        case JPJ_LIC_MOTOR: AccountData[playerid][pMBLicTime]   = expTime;
        case JPJ_LIC_CAR:   AccountData[playerid][pGVL1LicTime] = expTime;
        case JPJ_LIC_TRUCK: AccountData[playerid][pGVL2LicTime] = expTime;
        case JPJ_LIC_HELI:  AccountData[playerid][pAir1LicTime] = expTime;
    }
    SaveJPJLicense(playerid);
}

stock SaveJPJLicense(playerid)
{
    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "UPDATE `player_characters` SET \
        `Char_MBLic` = %d, `Char_MBLicTime` = %d, \
        `Char_GVL1Lic` = %d, `Char_GVL1LicTime` = %d, \
        `Char_GVL2Lic` = %d, `Char_GVL2LicTime` = %d, \
        `Char_Air1Lic` = %d, `Char_Air1LicTime` = %d \
        WHERE `pID` = %d",
        AccountData[playerid][pMBLic],   AccountData[playerid][pMBLicTime],
        AccountData[playerid][pGVL1Lic], AccountData[playerid][pGVL1LicTime],
        AccountData[playerid][pGVL2Lic], AccountData[playerid][pGVL2LicTime],
        AccountData[playerid][pAir1Lic], AccountData[playerid][pAir1LicTime],
        AccountData[playerid][pID]);

    mysql_tquery(g_SQL, query);
}

stock CheckJPJLicenseExpiry(playerid)
{
    new licTypes[4] = {JPJ_LIC_MOTOR, JPJ_LIC_CAR, JPJ_LIC_TRUCK, JPJ_LIC_HELI};
    for(new i = 0; i < 4; i++)
    {
        if(PlayerHasLicense(playerid, licTypes[i]) && IsLicenseExpired(playerid, licTypes[i]))
        {
            switch(licTypes[i])
            {
                case JPJ_LIC_MOTOR:
                {
                    AccountData[playerid][pMBLic]     = 0;
                    AccountData[playerid][pMBLicTime] = 0;
                }
                case JPJ_LIC_CAR:
                {
                    AccountData[playerid][pGVL1Lic]     = 0;
                    AccountData[playerid][pGVL1LicTime] = 0;
                }
                case JPJ_LIC_TRUCK:
                {
                    AccountData[playerid][pGVL2Lic]     = 0;
                    AccountData[playerid][pGVL2LicTime] = 0;
                }
                case JPJ_LIC_HELI:
                {
                    AccountData[playerid][pAir1Lic]     = 0;
                    AccountData[playerid][pAir1LicTime] = 0;
                }
            }
            new msg[128];
            format(msg, sizeof(msg), "SIM %s kamu sudah kadaluarsa!", GetLicName(licTypes[i]));
            ShowTDN(playerid, NOTIFICATION_WARNING, msg);
        }
    }
    SaveJPJLicense(playerid);
}

stock ToggleJPJDuty(playerid)
{
    if(AccountData[playerid][pFaction] != FACTION_JPJ)
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu bukan staff JPJ!"), 1;

    AccountData[playerid][pOnDuty] = !AccountData[playerid][pOnDuty];

    if(AccountData[playerid][pOnDuty])
    {
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Kamu sekarang SEDANG BERTUGAS sebagai staff JPJ.");
        if(AccountData[playerid][pIsUsingUniform])
            SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
    }
    else
    {
        ShowTDN(playerid, NOTIFICATION_INFO, "Kamu sekarang TIDAK BERTUGAS.");
    }
    return 1;
}
stock ShowJPJApplicantList(playerid)
{
    new str[512], count = 0;
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJTemp[i][jpjStep] >= 2)
        {
            new step[32];
            if(JPJTemp[i][jpjStep] == 2)      step = "Ujian Teori";
            else if(JPJTemp[i][jpjStep] == 3) step = "Ujian Mengemudi";
            strcat(str, sprintf("%s [ID:%d] - %s\n", AccountData[i][pName], i, step), sizeof(str));
            count++;
        }
    }

    if(!count)
        return ShowTDN(playerid, NOTIFICATION_INFO, "Tidak ada pemohon yang sedang dalam proses ujian.");

    Dialog_Show(playerid, "JPJApplicantList", DIALOG_STYLE_MSGBOX,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Daftar Pemohon",
        str, "Tutup", "");
}

stock ShowJPJPassApplicant(playerid)
{
    new str[1024], count = 0;
    foreach(new i : Player)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJInDriveTest[i])
        {
            format(str, sizeof(str), "%s%s [ID:%d] | Pelanggaran: %d\n",
                str,
                AccountData[i][pName], i,
                JPJTemp[i][jpjDriveViolations]);
            count++;
        }
    }

    if(!count)
        return ShowTDN(playerid, NOTIFICATION_INFO, "Tidak ada pemohon yang sedang ujian mengemudi.");

    Dialog_Show(playerid, "JPJPassApplicant", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Luluskan Pemohon",
        str, "Lihat Detail & Luluskan", "Batal");
}

Dialog:JPJPassApplicant(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new count = 0;
    foreach(new i : Player)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJInDriveTest[i])
        {
            if(count == listitem)
            {
                JPJStaffTargetID[playerid] = i;
                ShowJPJDriveDetail(playerid, i);
                return 1;
            }
            count++;
        }
    }
    return 1;
}

stock ShowJPJDriveDetail(playerid, targetid)
{
    new str[512];
    new viol = JPJTemp[targetid][jpjDriveViolations];

    format(str, sizeof(str),
        "{FFFF00}Nama :{FFFFFF} %s\n\
        {FFFF00}SIM :{FFFFFF} %s\n\
        {FFFF00}Pelanggaran :{FFFFFF} %d kali\n\n",
        AccountData[targetid][pName],
        GetLicName(JPJTemp[targetid][jpjLicType]),
        viol);

    if(viol > 0)
        strcat(str, sprintf("{FFFF00}Catatan:\n{FFFFFF}%s\n\n", JPJTemp[targetid][jpjDriveNotes]), sizeof(str));
    else
        strcat(str, "{00FF00}Tidak ada pelanggaran tercatat.\n\n", sizeof(str));

    strcat(str, "{FFFFFF}Pilih tindakan:", sizeof(str));

    Dialog_Show(playerid, "JPJDriveDetail", DIALOG_STYLE_LIST,"{00BFFF}Vertex Roleplay {FFFFFF}- Detail Ujian Mengemudi",str,"Luluskan\nGagalkan (Input Alasan)", "Batal");
}

Dialog:JPJDriveDetail(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new targetid = JPJStaffTargetID[playerid];
    if(!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Pemohon sudah tidak terhubung!"), 1;

    switch(listitem)
    {
        case 0: // luluskan
        {
            FinishJPJDriveTest(targetid, true);
            new msg[64];
            format(msg, sizeof(msg), "Kamu telah meluluskan ujian mengemudi %s.", AccountData[targetid][pName]);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
        }
        case 1: // gagalkan, input alasan
        {
            Dialog_Show(playerid, "JPJFailReasonDrive", DIALOG_STYLE_INPUT,
                "{00BFFF}Vertex Roleplay {FFFFFF}- Alasan Gagal Mengemudi",
                "{FFFFFF}Masukkan alasan kamu menggagalkan ujian mengemudi pemohon ini:",
                "Konfirmasi", "Batal");
        }
    }
    return 1;
}

Dialog:JPJFailReasonDrive(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new targetid = JPJStaffTargetID[playerid];
    if(!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Pemohon sudah tidak terhubung!"), 1;

    if(!strlen(inputtext))
        return Dialog_Show(playerid, "JPJFailReasonDrive", DIALOG_STYLE_INPUT,
            "{00BFFF}Vertex Roleplay {FFFFFF}- Alasan Gagal Mengemudi",
            "{FF0000}Alasan tidak boleh kosong!\n{FFFFFF}Masukkan alasan kamu menggagalkan pemohon ini:",
            "Konfirmasi", "Batal");

    new str[256];
    format(str, sizeof(str),
        "{FF0000}GAGAL - Ujian Mengemudi\n\n\
        {FFFFFF}Staff JPJ telah menggagalkan ujian mengemudi kamu.\n\
        {FFFF00}Alasan: {FFFFFF}%s\n\n\
        Biaya tidak dikembalikan. Silakan daftar ulang.", inputtext);

    Dialog_Show(targetid, "JPJFailNotif", DIALOG_STYLE_MSGBOX,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Hasil Ujian Mengemudi",
        str, "Tutup", "");

    if(JPJDriveCPID[targetid] != 0)
    {
        DestroyDynamicCP(JPJDriveCPID[targetid]);
        JPJDriveCPID[targetid] = 0;
    }
    JPJInDriveTest[targetid] = false;
    ResetJPJTemp(targetid);

    new msg[128];
    format(msg, sizeof(msg), "Kamu telah menggagalkan ujian mengemudi %s. Alasan: %s",AccountData[targetid][pName], inputtext);
    ShowTDN(playerid, NOTIFICATION_INFO, msg);
    return 1;
}

stock ShowJPJFailApplicant(playerid)
{
    new str[1024], count = 0;
    foreach(new i : Player)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJInDriveTest[i])
        {
            format(str, sizeof(str), "%s%s [ID:%d] | Pelanggaran: %d\n",
                str,
                AccountData[i][pName], i,
                JPJTemp[i][jpjDriveViolations]);
            count++;
        }
    }

    if(!count)
        return ShowTDN(playerid, NOTIFICATION_INFO, "Tidak ada pemohon yang sedang ujian mengemudi.");

    Dialog_Show(playerid, "JPJFailApplicant", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Gagalkan Pemohon",
        str, "Pilih & Input Alasan", "Batal");
}

Dialog:JPJFailApplicant(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new count = 0;
    foreach(new i : Player)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJInDriveTest[i])
        {
            if(count == listitem)
            {
                JPJStaffTargetID[playerid] = i;
                Dialog_Show(playerid, "JPJFailReasonDrive", DIALOG_STYLE_INPUT,
                    "{00BFFF}Vertex Roleplay {FFFFFF}- Alasan Gagal Mengemudi",
                    "{FFFFFF}Masukkan alasan kamu menggagalkan ujian mengemudi pemohon ini:",
                    "Konfirmasi", "Batal");
                return 1;
            }
            count++;
        }
    }
    return 1;
}

CMD:jpj(playerid, params[])
{
    if(!IsJPJStaffOnDuty())
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak ada staff JPJ yang bertugas. Coba lagi nanti."), 1;

    new Float:cx = -1580.0, Float:cy = 680.0, Float:cz = 7.0;
    new Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    if(GetDistanceBetweenCoords(px, py, pz, cx, cy, cz) > 5.0)
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu tidak berada di counter JPJ!"), 1;

    ShowJPJMainMenu(playerid);
    return 1;
}

CMD:jpjtugas(playerid, params[])
{
    if(AccountData[playerid][pFaction] != FACTION_JPJ)
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu bukan staff JPJ!"), 1;

    ToggleJPJDuty(playerid);
    return 1;
}
CMD:jpjmenu(playerid, params[])
{
    if(AccountData[playerid][pFaction] != FACTION_JPJ)
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu bukan staff JPJ!"), 1;

    ShowJPJStaffMenu(playerid);
    return 1;
}

CMD:ceksim(playerid, params[])
{
    ShowJPJMyLicense(playerid);
    return 1;
}

hook OnVehicleDeath(vehicleid, killerid)
{
    foreach(new i : Player)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJInDriveTest[i] && GetPlayerVehicleID(i) == vehicleid)
        {
            JPJAddViolation(i, "Kendaraan hancur/terbalik");
        }
    }    
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(JPJInDriveTest[playerid])
    {
        if(JPJDriveCPID[playerid] != 0)
        {
            DestroyDynamicCP(JPJDriveCPID[playerid]);
            JPJDriveCPID[playerid] = 0;
        }
        JPJInDriveTest[playerid] = false;
    }
    ResetJPJTemp(playerid);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
    if(JPJInDriveTest[playerid] && checkpointid == JPJDriveCPID[playerid])
    {
        JPJDriveCP[playerid]++;
        SetJPJNextCheckpoint(playerid);
        return 1;
    }
    return 1;
}