// ---------- JPJ DEFINES & VARIABLES ----------

#define FACTION_JPJ             14

#define JPJ_LIC_MOTOR           1
#define JPJ_LIC_CAR             2
#define JPJ_LIC_TRUCK           3
#define JPJ_LIC_HELI            4

#define JPJ_FEE_MOTOR           125
#define JPJ_FEE_CAR             200
#define JPJ_FEE_TRUCK           300
#define JPJ_FEE_HELI            750

#define JPJ_EXAM_PASS_SCORE     4       // minimal benar dari 5 soal
#define JPJ_LIC_DURATION        2592000 // 30 hari dalam detik (expired)

#define JPJ_MAX_QUESTIONS       5

// ---------- PLAYER TEMP DATA ----------

enum E_JPJ_TEMP
{
    jpjRegName[32],
    jpjRegAddress[64],
    jpjRegSSN[20],
    jpjLicType,
    jpjExamScore,
    jpjCurrentQ,
    jpjStep,        // 0=idle 1=register 2=exam 3=drivetest
    bool:jpjPassedExam,
    bool:jpjPassedDrive,
    jpjDriveViolations,         // jumlah pelanggaran drive test
    jpjDriveNotes[256],         // catatan pelanggaran drive test
    jpjTheoryAnswers[5],        // jawaban pemohon (index 0-3)
    jpjTheoryCorrect[5]         // 1 = benar, 0 = salah
};
new JPJTemp[MAX_PLAYERS][E_JPJ_TEMP];
new JPJStaffTargetID[MAX_PLAYERS];

// ---------- SOAL UJIAN TEORI ----------

enum E_JPJ_QUESTION
{
    qText[128],
    qOpt[4][64],
    qAnswer // index jawaban benar (0-3)
};

new JPJQuestions[JPJ_MAX_QUESTIONS][E_JPJ_QUESTION] = {
    {
        "Lampu lalu lintas berwarna KUNING bermaksud?",
        {"Berhenti segera", "Bersiap untuk berhenti atau jalan", "Jalan terus laju", "Undur kereta"},
        1
    },
    {
        "Apakah tanda had laju 60 km/j bermaksud?",
        {"Minimum laju 60 km/j", "Laju tidak melebihi 60 km/j", "Laju bebas di kawasan ini", "Tiada had laju"},
        1
    },
    {
        "Di persimpangan tanpa lampu isyarat, siapa yang perlu bagi laluan?",
        {"Kenderaan dari kanan", "Kenderaan dari kiri", "Kenderaan yang masuk dari jalan kecil", "Semua kenderaan berhenti"},
        2
    },
    {
        "Apakah yang perlu dilakukan jika tayar kereta meletup semasa memandu?",
        {"Tekan brek dengan kuat", "Pusing stereng ke arah yang bertentangan", "Pegang stereng kuat & lepaskan minyak perlahan", "Tukar gear ke neutral terus"},
        2
    },
    {
        "Tanda 'P' di Malaysia bermaksud?",
        {"Parking dibenarkan", "Pemandu baru (probationary)", "Kawasan polis", "Laluan keutamaan"},
        1
    }
};

// ---------- HELPER: CEK STAFF JPJ ONDUTY ----------

stock bool:IsJPJStaffOnDuty()
{
    for(new i = 0; i < MAX_PLAYERS; i++)
    {
        if(!IsPlayerConnected(i)) continue;
        if(AccountData[i][pFaction] == FACTION_JPJ && AccountData[i][pOnDuty])
            return true;
    }
    return false;
}

// ---------- HELPER: NAMA JENIS LESEN ----------

stock GetLicName(lictype)
{
    new str[32];
    switch(lictype)
    {
        case JPJ_LIC_MOTOR: str = "Motor";
        case JPJ_LIC_CAR:   str = "Kereta (Mobil)";
        case JPJ_LIC_TRUCK: str = "Lori (Truk)";
        case JPJ_LIC_HELI:  str = "Helikopter";
        default:            str = "Unknown";
    }
    return str;
}

// ---------- HELPER: BIAYA LESEN ----------

stock GetLicFee(lictype)
{
    switch(lictype)
    {
        case JPJ_LIC_MOTOR: return JPJ_FEE_MOTOR;
        case JPJ_LIC_CAR:   return JPJ_FEE_CAR;
        case JPJ_LIC_TRUCK: return JPJ_FEE_TRUCK;
        case JPJ_LIC_HELI:  return JPJ_FEE_HELI;
    }
    return 0;
}

// ---------- HELPER: CEK PLAYER PUNYA LESEN ----------

stock bool:PlayerHasLicense(playerid, lictype)
{
    switch(lictype)
    {
        case JPJ_LIC_MOTOR: return bool:(AccountData[playerid][pMBLic] == 1);
        case JPJ_LIC_CAR:   return bool:(AccountData[playerid][pGVL1Lic] == 1);
        case JPJ_LIC_TRUCK: return bool:(AccountData[playerid][pGVL2Lic] == 1);
        case JPJ_LIC_HELI:  return bool:(AccountData[playerid][pAir1Lic] == 1);
    }
    return false;
}

// ---------- HELPER: CEK LESEN EXPIRED ----------

stock bool:IsLicenseExpired(playerid, lictype)
{
    new expTime;
    switch(lictype)
    {
        case JPJ_LIC_MOTOR: expTime = AccountData[playerid][pMBLicTime];
        case JPJ_LIC_CAR:   expTime = AccountData[playerid][pGVL1LicTime];
        case JPJ_LIC_TRUCK: expTime = AccountData[playerid][pGVL2LicTime];
        case JPJ_LIC_HELI:  expTime = AccountData[playerid][pAir1LicTime];
        default: return false;
    }
    if(expTime == 0) return false;
    return bool:(gettime() > expTime);
}

// ---------- HELPER: SISA HARI LESEN ----------

stock GetLicDaysLeft(playerid, lictype)
{
    new expTime;
    switch(lictype)
    {
        case JPJ_LIC_MOTOR: expTime = AccountData[playerid][pMBLicTime];
        case JPJ_LIC_CAR:   expTime = AccountData[playerid][pGVL1LicTime];
        case JPJ_LIC_TRUCK: expTime = AccountData[playerid][pGVL2LicTime];
        case JPJ_LIC_HELI:  expTime = AccountData[playerid][pAir1LicTime];
        default: return 0;
    }
    if(expTime == 0) return 0;
    new sisa = expTime - gettime();
    if(sisa <= 0) return 0;
    return sisa / 86400;
}

// ---------- RESET TEMP DATA ----------

stock ResetJPJTemp(playerid)
{
    JPJTemp[playerid][jpjRegName]       = "\0";
    JPJTemp[playerid][jpjRegAddress]    = "\0";
    JPJTemp[playerid][jpjRegSSN]        = "\0";
    JPJTemp[playerid][jpjLicType]       = 0;
    JPJTemp[playerid][jpjExamScore]     = 0;
    JPJTemp[playerid][jpjCurrentQ]      = 0;
    JPJTemp[playerid][jpjStep]          = 0;
    JPJTemp[playerid][jpjPassedExam]    = false;
    JPJTemp[playerid][jpjPassedDrive]   = false;
    JPJTemp[playerid][jpjDriveViolations] = 0;
    JPJTemp[playerid][jpjDriveNotes]    = "\0";
    for(new i = 0; i < 5; i++)
    {
        JPJTemp[playerid][jpjTheoryAnswers][i] = -1;
        JPJTemp[playerid][jpjTheoryCorrect][i] = 0;
    }
}

/*
 * ============================================================================
 *  SQL SETUP - Jalankan query ini di database lu sekali aja
 * ============================================================================
 *
 *  Kolom untuk lesen sudah ada di server lu:
 *  - Char_MBLic / Char_MBLicTime       (Motor)
 *  - Char_GVL1Lic / Char_GVL1LicTime   (Kereta/Mobil)
 *  - Char_GVL2Lic / Char_GVL2LicTime   (Truk/Lori)
 *  - Char_Air1Lic / Char_Air1LicTime    (Helikopter)
 *
 *  Tidak perlu buat kolom baru! Tinggal tambah FACTION_JPJ = 14
 *  di enum faction dan tambah AssignFactionStuff untuk JPJ.
 *
 *  Untuk save lesen, gunakan UpdateAccountData yang sudah ada,
 *  pastikan kolom berikut sudah di-query UPDATE nya:
 *  Char_MBLic, Char_MBLicTime, Char_GVL1Lic, Char_GVL1LicTime,
 *  Char_GVL2Lic, Char_GVL2LicTime, Char_Air1Lic, Char_Air1LicTime
 * ============================================================================
 */
