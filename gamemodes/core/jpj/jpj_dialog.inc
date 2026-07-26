stock ShowJPJMainMenu(playerid)
{
    if(!IsJPJStaffOnDuty())
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak ada staff JPJ yang bertugas saat ini!");

    Dialog_Show(playerid, "JPJMain", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Layanan SIM",
        "Daftar & Ambil SIM Baru\nCek SIM Saya\nPerpanjang SIM",
        "Pilih", "Keluar");
}

Dialog:JPJMain(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: ShowJPJRegisterForm(playerid);
        case 1: ShowJPJMyLicense(playerid);
        case 2: ShowJPJRenewMenu(playerid);
    }
    return 1;
}

// ---------- DIALOG: FORM PENDAFTARAN - NAMA ----------

stock ShowJPJRegisterForm(playerid)
{
    if(!IsJPJStaffOnDuty())
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Tidak ada staff JPJ yang bertugas saat ini!");

    ResetJPJTemp(playerid);
    JPJTemp[playerid][jpjStep] = 1;

    Dialog_Show(playerid, "JPJFormName", DIALOG_STYLE_INPUT,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Formulir Pendaftaran (1/3)",
        "{FFFFFF}Masukkan {FFFF00}Nama Lengkap {FFFFFF}kamu:",
        "Selanjutnya", "Batal");
}

Dialog:JPJFormName(playerid, response, listitem, inputtext[])
{
    if(!response) { ResetJPJTemp(playerid); return 1; }
    if(!strlen(inputtext) || strlen(inputtext) < 3)
        return Dialog_Show(playerid, "JPJFormName", DIALOG_STYLE_INPUT,
            "{00BFFF}Vertex Roleplay {FFFFFF}- Formulir Pendaftaran (1/3)",
            "{FF0000}Nama terlalu pendek!\n{FFFFFF}Masukkan {FFFF00}Nama Lengkap {FFFFFF}kamu:",
            "Selanjutnya", "Batal");

    strcopy(JPJTemp[playerid][jpjRegName], inputtext);

    Dialog_Show(playerid, "JPJFormAddress", DIALOG_STYLE_INPUT,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Formulir Pendaftaran (2/3)",
        "{FFFFFF}Masukkan {FFFF00}Alamat Tempat Tinggal {FFFFFF}kamu:",
        "Selanjutnya", "Batal");
    return 1;
}

Dialog:JPJFormAddress(playerid, response, listitem, inputtext[])
{
    if(!response) { ResetJPJTemp(playerid); return 1; }
    if(!strlen(inputtext) || strlen(inputtext) < 5)
        return Dialog_Show(playerid, "JPJFormAddress", DIALOG_STYLE_INPUT,
            "{00BFFF}Vertex Roleplay {FFFFFF}- Formulir Pendaftaran (2/3)",
            "{FF0000}Alamat terlalu pendek!\n{FFFFFF}Masukkan {FFFF00}Alamat Tempat Tinggal {FFFFFF}kamu:",
            "Selanjutnya", "Batal");

    strcopy(JPJTemp[playerid][jpjRegAddress], inputtext);

    Dialog_Show(playerid, "JPJFormSSN", DIALOG_STYLE_INPUT,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Formulir Pendaftaran (3/3)",
        "{FFFFFF}Masukkan {FFFF00}Nomor KTP {FFFFFF}kamu:",
        "Selanjutnya", "Batal");
    return 1;
}

Dialog:JPJFormSSN(playerid, response, listitem, inputtext[])
{
    if(!response) { ResetJPJTemp(playerid); return 1; }
    if(!strlen(inputtext) || strlen(inputtext) < 6)
        return Dialog_Show(playerid, "JPJFormSSN", DIALOG_STYLE_INPUT,
            "{00BFFF}Vertex Roleplay {FFFFFF}- Formulir Pendaftaran (3/3)",
            "{FF0000}Nomor KTP tidak valid!\n{FFFFFF}Masukkan {FFFF00}Nomor KTP {FFFFFF}kamu:",
            "Selanjutnya", "Batal");

    strcopy(JPJTemp[playerid][jpjRegSSN], inputtext);
    ShowJPJLicTypeSelect(playerid);
    return 1;
}

// ---------- DIALOG: PILIH JENIS SIM ----------

stock ShowJPJLicTypeSelect(playerid)
{
    new str[512];
    format(str, sizeof(str),
        "{FFFF00}Nama :{FFFFFF} %s\n\
        {FFFF00}Alamat :{FFFFFF} %s\n\
        {FFFF00}No. KTP :{FFFFFF} %s\n\n\
        {FFFFFF}Pilih jenis SIM yang ingin diambil:",JPJTemp[playerid][jpjRegName],JPJTemp[playerid][jpjRegAddress],JPJTemp[playerid][jpjRegSSN]);

    Dialog_Show(playerid, "JPJLicType", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Pilih Jenis SIM",
        "SIM Motor - $125\nSIM Mobil - $200\nSIM Truk - $300\nSIM Helikopter - $750",
        "Pilih", "Batal");
}

Dialog:JPJLicType(playerid, response, listitem, inputtext[])
{
    if(!response) { ResetJPJTemp(playerid); return 1; }

    JPJTemp[playerid][jpjLicType] = listitem + 1;

    if(PlayerHasLicense(playerid, JPJTemp[playerid][jpjLicType]) &&
       !IsLicenseExpired(playerid, JPJTemp[playerid][jpjLicType]))
    {
        ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu sudah punya SIM jenis ini dan masih aktif!");
        ResetJPJTemp(playerid);
        return 1;
    }

    new str[256], fee = GetLicFee(JPJTemp[playerid][jpjLicType]);
    format(str, sizeof(str),
        "{FFFFFF}Kamu akan mendaftar SIM {FFFF00}%s{FFFFFF}\n\
        Biaya pendaftaran: {FFFF00}$%d\n\n\
        {FFFFFF}Uang kamu saat ini: {00FF00}$%d\n\n\
        Apakah kamu yakin ingin melanjutkan?",
        GetLicName(JPJTemp[playerid][jpjLicType]),
        fee,
        AccountData[playerid][pMoney]);

    Dialog_Show(playerid, "JPJConfirmFee", DIALOG_STYLE_MSGBOX,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Konfirmasi Pembayaran",
        str, "Ya, Bayar", "Batal");
    return 1;
}

Dialog:JPJConfirmFee(playerid, response, listitem, inputtext[])
{
    if(!response) { ResetJPJTemp(playerid); return 1; }

    new fee = GetLicFee(JPJTemp[playerid][jpjLicType]);
    if(AccountData[playerid][pMoney] < fee)
    {
        ShowTDN(playerid, NOTIFICATION_WARNING, "Uang kamu tidak cukup untuk mendaftar SIM ini!");
        ResetJPJTemp(playerid);
        return 1;
    }

    GivePlayerMoneyEx(playerid, -fee);
    ShowTDN(playerid, NOTIFICATION_INFO, "Pembayaran berhasil! Silakan mulai Ujian Teori.");
    JPJTemp[playerid][jpjStep] = 2;
    JPJTemp[playerid][jpjExamScore] = 0;
    JPJTemp[playerid][jpjCurrentQ]  = 0;

    ShowJPJExamQuestion(playerid);
    return 1;
}

// ---------- DIALOG: UJIAN TEORI ----------

stock ShowJPJExamQuestion(playerid)
{
    new q = JPJTemp[playerid][jpjCurrentQ];
    if(q >= JPJ_MAX_QUESTIONS)
    {
        ShowTDN(playerid, NOTIFICATION_INFO, "Ujian teori selesai! Tunggu penilaian dari staff JPJ.");
        JPJTemp[playerid][jpjStep] = 2; 
        return;
    }

    new str[512];
    format(str, sizeof(str), "{FFFF00}Soal %d/%d\n\n{FFFFFF}%s\n\n%s\n%s\n%s\n%s",
        q + 1, JPJ_MAX_QUESTIONS,
        JPJQuestions[q][qText],
        JPJQuestions[q][qOpt][0],
        JPJQuestions[q][qOpt][1],
        JPJQuestions[q][qOpt][2],
        JPJQuestions[q][qOpt][3]);

    Dialog_Show(playerid, "JPJExamQ", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Ujian Teori",
        str, "Jawab", "");
}

Dialog:JPJExamQ(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new q = JPJTemp[playerid][jpjCurrentQ];

    JPJTemp[playerid][jpjTheoryAnswers][q] = listitem;
    if(listitem == JPJQuestions[q][qAnswer])
    {
        JPJTemp[playerid][jpjExamScore]++;
        JPJTemp[playerid][jpjTheoryCorrect][q] = 1;
    }
    else
    {
        JPJTemp[playerid][jpjTheoryCorrect][q] = 0;
    }

    JPJTemp[playerid][jpjCurrentQ]++;
    ShowJPJExamQuestion(playerid);
    return 1;
}

// ---------- DIALOG: UJIAN MENGEMUDI ----------

stock ShowJPJDriveTest(playerid)
{
    JPJTemp[playerid][jpjStep] = 3;

    new str[512];
    format(str, sizeof(str),
        "{FFFFFF}Kamu akan mengikuti {FFFF00}Ujian Mengemudi {FFFFFF}untuk SIM {FFFF00}%s{FFFFFF}.\n\n\
        {FFFFFF}Instruksi Ujian:\n\
        - Ambil kendaraan yang tersedia di luar kantor JPJ\n\
        - Kendarai ke {FFFF00}checkpoint {FFFFFF}yang ditandai\n\
        - Kembali ke {FFFF00}counter JPJ {FFFFFF}setelah selesai\n\
        - Jangan menabrak, terbalik, atau keluar area\n\n\
        {FF0000}Peringatan: {FFFFFF}Jika keluar area atau kendaraan rusak, ujian gagal!",
        GetLicName(JPJTemp[playerid][jpjLicType]));

    Dialog_Show(playerid, "JPJDriveTest", DIALOG_STYLE_MSGBOX,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Ujian Mengemudi",
        str, "Mulai Ujian", "Batal");
}

Dialog:JPJDriveTest(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        ShowTDN(playerid, NOTIFICATION_INFO, "Ujian mengemudi dibatalkan. Kamu perlu daftar ulang.");
        ResetJPJTemp(playerid);
        return 1;
    }

    StartJPJDriveTest(playerid);
    return 1;
}

// ---------- DIALOG: CEK SIM ----------

stock ShowJPJMyLicense(playerid)
{
    new str[512];
    new licTypes[4] = {JPJ_LIC_MOTOR, JPJ_LIC_CAR, JPJ_LIC_TRUCK, JPJ_LIC_HELI};
    new licNames[4][] = {"Motor", "Mobil", "Truk", "Helikopter"};

    format(str, sizeof(str), "{FFFF00}Nama: {FFFFFF}%s\n\n{FFFFFF}Status SIM:\n\n", AccountData[playerid][pName]);

    for(new i = 0; i < 4; i++)
    {
        new lt = licTypes[i];
        if(PlayerHasLicense(playerid, lt))
        {
            if(IsLicenseExpired(playerid, lt))
                strcat(str, sprintf("{FF0000}[KADALUARSA] {FFFFFF}SIM %s\n", licNames[i]), sizeof(str));
            else
            {
                new days = GetLicDaysLeft(playerid, lt);
                strcat(str, sprintf("{00FF00}[AKTIF] {FFFFFF}SIM %s - Sisa {FFFF00}%d hari\n", licNames[i], days), sizeof(str));
            }
        }
        else
            strcat(str, sprintf("{AAAAAA}[TIDAK ADA] {FFFFFF}SIM %s\n", licNames[i]), sizeof(str));
    }

    Dialog_Show(playerid, "JPJMyLic", DIALOG_STYLE_MSGBOX,
        "{00BFFF}Vertex Roleplay {FFFFFF}- SIM Saya",
        str, "Tutup", "");
}

// ---------- DIALOG: PERPANJANG SIM ----------

stock ShowJPJRenewMenu(playerid)
{
    new str[256];
    new hasExpired = false;

    new licTypes[4] = {JPJ_LIC_MOTOR, JPJ_LIC_CAR, JPJ_LIC_TRUCK, JPJ_LIC_HELI};
    new licNames[4][] = {"Motor", "Mobil", "Truk", "Helikopter"};

    for(new i = 0; i < 4; i++)
    {
        if(PlayerHasLicense(playerid, licTypes[i]) && IsLicenseExpired(playerid, licTypes[i]))
        {
            hasExpired = true;
            strcat(str, sprintf("SIM %s - ${FFFF00}%d\n{FFFFFF}", licNames[i], GetLicFee(licTypes[i])), sizeof(str));
        }
    }

    if(!hasExpired)
    {
        ShowTDN(playerid, NOTIFICATION_INFO, "Tidak ada SIM kamu yang perlu diperpanjang.");
        return;
    }

    Dialog_Show(playerid, "JPJRenew", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Perpanjang SIM",
        str, "Pilih", "Batal");
}

Dialog:JPJRenew(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new licTypes[4] = {JPJ_LIC_MOTOR, JPJ_LIC_CAR, JPJ_LIC_TRUCK, JPJ_LIC_HELI};
    new count = 0;
    for(new i = 0; i < 4; i++)
    {
        if(PlayerHasLicense(playerid, licTypes[i]) && IsLicenseExpired(playerid, licTypes[i]))
        {
            if(count == listitem)
            {
                new lt  = licTypes[i];
                new fee = GetLicFee(lt);

                if(AccountData[playerid][pMoney] < fee)
                {
                    ShowTDN(playerid, NOTIFICATION_WARNING, "Uang tidak cukup untuk perpanjang SIM!");
                    return 1;
                }

                GivePlayerMoneyEx(playerid, -fee);
                RenewPlayerLicense(playerid, lt);

                new msg[128];
                format(msg, sizeof(msg), "SIM %s berhasil diperpanjang selama 30 hari!", GetLicName(lt));
                ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
                return 1;
            }
            count++;
        }
    }
    return 1;
}

// ---------- DIALOG: MENU STAFF JPJ ----------

stock ShowJPJStaffMenu(playerid)
{
    if(AccountData[playerid][pFaction] != FACTION_JPJ)
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Kamu bukan staff JPJ!");

    new str[256];
    format(str, sizeof(str),
        "{FFFFFF}Status Tugas: %s\n\nPilih menu di bawah:",
        AccountData[playerid][pOnDuty] ? "{00FF00}SEDANG BERTUGAS" : "{FF0000}TIDAK BERTUGAS");

    Dialog_Show(playerid, "JPJStaffMenu", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Menu Staff JPJ",
        "Toggle On/Off Tugas\nLihat Daftar Pemohon\nNilai Ujian Teori\nLuluskan Ujian Mengemudi\nGagalkan Ujian Mengemudi",
        "Pilih", "Tutup");
}

stock ShowJPJTheoryList(playerid)
{
    new str[1024], count = 0;
    foreach(new i : Player)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJTemp[i][jpjStep] == 2 && JPJTemp[i][jpjCurrentQ] >= JPJ_MAX_QUESTIONS)
        {
            format(str, sizeof(str), "%s%s [ID:%d] - SIM %s | Nilai: %d/%d\n",
                str,
                AccountData[i][pName], i,
                GetLicName(JPJTemp[i][jpjLicType]),
                JPJTemp[i][jpjExamScore], JPJ_MAX_QUESTIONS);
            count++;
        }
    }

    if(!count)
        return ShowTDN(playerid, NOTIFICATION_INFO, "Tidak ada pemohon yang menunggu penilaian teori.");

    Dialog_Show(playerid, "JPJTheoryList", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Daftar Hasil Teori",
        str, "Lihat Detail", "Tutup");
}

Dialog:JPJTheoryList(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new count = 0;
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(JPJTemp[i][jpjStep] == 2 && JPJTemp[i][jpjCurrentQ] >= JPJ_MAX_QUESTIONS)
        {
            if(count == listitem)
            {
                JPJStaffTargetID[playerid] = i;
                ShowJPJTheoryDetail(playerid, i);
                return 1;
            }
            count++;
        }
    }
    return 1;
}

stock ShowJPJTheoryDetail(playerid, targetid)
{
    new str[1024];
    format(str, sizeof(str),
        "{FFFF00}Nama :{FFFFFF} %s\n\
        {FFFF00}SIM :{FFFFFF} %s\n\
        {FFFF00}Nilai :{FFFFFF} %d/%d\n\n\
        {FFFFFF}Detail Jawaban:\n",
        AccountData[targetid][pName],
        GetLicName(JPJTemp[targetid][jpjLicType]),
        JPJTemp[targetid][jpjExamScore], JPJ_MAX_QUESTIONS);

    for(new q = 0; q < JPJ_MAX_QUESTIONS; q++)
    {
        new jawaban = JPJTemp[targetid][jpjTheoryAnswers][q];
        new benar   = JPJTemp[targetid][jpjTheoryCorrect][q];
        new status[32];

        if(benar) status = "{00FF00}BENAR";
        else status = "{FF0000}SALAH";

        new jawabanText[64];
        if(jawaban >= 0 && jawaban <= 3)
            strcopy(jawabanText, JPJQuestions[q][qOpt][jawaban]);
        else
            jawabanText = "Tidak dijawab";

        strcat(str, sprintf("%s Soal %d: %s\n", status, q + 1, jawabanText), sizeof(str));
    }

    strcat(str, "\n{FFFFFF}Pilih tindakan:", sizeof(str));

    Dialog_Show(playerid, "JPJTheoryDetail", DIALOG_STYLE_LIST,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Detail Ujian Teori",
        str,
        "Lanjut ke Ujian Mengemudi\nGagalkan (Input Alasan)", "Batal");
}

Dialog:JPJTheoryDetail(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new targetid = JPJStaffTargetID[playerid];
    if(!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Pemohon sudah tidak terhubung!"), 1;

    switch(listitem)
    {
        case 0: // lulus teori, lanjut ke ujian mengemudi
        {
            JPJTemp[targetid][jpjPassedExam] = true;
            ShowTDN(targetid, NOTIFICATION_SUCCESS, "Staff JPJ menyatakan kamu LULUS ujian teori! Silakan lanjut ke ujian mengemudi.");
            ShowJPJDriveTest(targetid);

            new msg[64];
            format(msg, sizeof(msg), "Kamu telah meluluskan ujian teori %s.", AccountData[targetid][pName]);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
        }
        case 1: // gagalkan teori, input alasan
        {
            Dialog_Show(playerid, "JPJFailReasonTheory", DIALOG_STYLE_INPUT,
                "{00BFFF}Vertex Roleplay {FFFFFF}- Alasan Gagal Teori",
                "{FFFFFF}Masukkan alasan kamu menggagalkan ujian teori pemohon ini:",
                "Konfirmasi", "Batal");
        }
    }
    return 1;
}

Dialog:JPJFailReasonTheory(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new targetid = JPJStaffTargetID[playerid];
    if(!IsPlayerConnected(targetid))
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Pemohon sudah tidak terhubung!"), 1;

    if(!strlen(inputtext))
        return Dialog_Show(playerid, "JPJFailReasonTheory", DIALOG_STYLE_INPUT,
            "{00BFFF}Vertex Roleplay {FFFFFF}- Alasan Gagal Teori",
            "{FF0000}Alasan tidak boleh kosong!\n{FFFFFF}Masukkan alasan kamu menggagalkan pemohon ini:",
            "Konfirmasi", "Batal");

    new msg[256];
    format(msg, sizeof(msg), "{FF0000}Kamu dinyatakan GAGAL ujian teori oleh staff JPJ.\n{FFFFFF}Alasan: %s", inputtext);
    ShowTDN(targetid, NOTIFICATION_ERROR, "Kamu gagal ujian teori! Silakan daftar ulang.");

    new str[256];
    format(str, sizeof(str),
        "{FF0000}GAGAL - Ujian Teori\n\n\
        {FFFFFF}Staff JPJ telah menggagalkan ujian teori kamu.\n\
        {FFFF00}Alasan: {FFFFFF}%s\n\n\
        Biaya tidak dikembalikan. Silakan daftar ulang.", inputtext);

    Dialog_Show(targetid, "JPJFailNotif", DIALOG_STYLE_MSGBOX,
        "{00BFFF}Vertex Roleplay {FFFFFF}- Hasil Ujian Teori",
        str, "Tutup", "");

    ResetJPJTemp(targetid);

    format(msg, sizeof(msg), "Kamu telah menggagalkan ujian teori %s. Alasan: %s",AccountData[targetid][pName], inputtext);
    ShowTDN(playerid, NOTIFICATION_INFO, msg);
    return 1;
}

Dialog:JPJStaffMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    switch(listitem)
    {
        case 0: ToggleJPJDuty(playerid);
        case 1: ShowJPJApplicantList(playerid);
        case 2: ShowJPJTheoryList(playerid);      // BARU
        case 3: ShowJPJPassApplicant(playerid);
        case 4: ShowJPJFailApplicant(playerid);
    }
    return 1;
}

