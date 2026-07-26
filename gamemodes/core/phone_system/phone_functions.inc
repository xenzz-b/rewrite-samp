#include <YSI_Coding\y_hooks>

#define MAX_CONTACT_ROWS 10 // cuma nampilin 10 kontak per-page

new 
    index_contact[MAX_PLAYERS]; // selalu reset ke 0 setiap pertamakali ShowContactList(playerid) dipake pertamakali

enum e_PlayerPhoneDetails
{
    phoneOwnerName[24],
    phoneNumber[13],
    phoneWallpaper,
    bool:phoneWhatsAppInstalled,
    bool:phoneSpotifyInstalled,
    bool:phoneTwitterInstalled,
    bool:phoneUberInstalled,
    bool:phoneYellowInstalled,
    IsTwitterLoggedIn,

    //not save
    phoneShowedPageTD,
    phoneContactSelected,
    phoneCallingWithPlayerID,
    bool:phoneIncomingCall,
    bool:phoneDuringConversation,
    phoneCallingTime,
    phoneTempName[24],
    phoneTempNumber[13],

    bool:phoneDownloadingApp,
    phoneDownloadingProg,
    phoneInstallAppTimer,

    bool:phoneListeningSelf,
    bool:phoneListeningBoombox,

    bool:CurrentlyReadTweet,
    bool:CurrentlyReadWA,

    bool:phoneShown,
    bool:phoneOn
};
new PlayerPhoneData[MAX_PLAYERS][e_PlayerPhoneDetails];

enum contactData
{
	contactID,
	contactExists,
	contactName[24],
	contactNumber[13],
	contactOwnerID,
    bool:contactBlocked,
    contactUnread
};

new ContactData[MAX_PLAYERS][MAX_CONTACTS][contactData];
new ListedContacts[MAX_PLAYERS][MAX_CONTACTS];
new TempWAText[MAX_PLAYERS][128];

enum E_BOOMBOX
{
	BoomBoxOwner[MAX_PLAYER_NAME + 1],
	BoomBoxLink[144],

	bool:BoomBoxPlaced,
	
	BoomBoxObj,
	BoomBoxArea,
	Text3D:BoomBoxLabel,

	Float:BoomX,
	Float:BoomY,
	Float:BoomZ,
	Float:BoomA,

	BoomVw,
	BoomInt

};
new BoomBoxInfo[MAX_PLAYERS][E_BOOMBOX];

enum e_uberapptemp
{
    DestTemp[128],
    CostTemp,
    PassangerTemp,
    Float:PosTemp[3],
    bool:NeedUber,
    bool:NeedUberEat,
    NeedUberTimer,
    ServiceAcceptedBy,

    //keranjang
    ShotDeluxeQuant,
    UberEatTemp,
    TotalQuant

};
new UberAppTemp[MAX_PLAYERS][e_uberapptemp];

ResetUberAppTemp(playerid)
{
    UberAppTemp[playerid][DestTemp][0] = EOS;
    UberAppTemp[playerid][PassangerTemp] = 0;
    UberAppTemp[playerid][NeedUber] = false;
    UberAppTemp[playerid][NeedUberEat] = false;
    UberAppTemp[playerid][NeedUberTimer] = 0;

    if(UberAppTemp[playerid][ServiceAcceptedBy] == INVALID_PLAYER_ID) //jika orderan belum diterima maka akan ikut terhapus
    {
        UberAppTemp[playerid][PosTemp][0] = 0;
        UberAppTemp[playerid][PosTemp][1] = 0;
        UberAppTemp[playerid][PosTemp][2] = 0;
        UberAppTemp[playerid][CostTemp] = 0;
        UberAppTemp[playerid][ServiceAcceptedBy] = INVALID_PLAYER_ID;
        UberAppTemp[playerid][ShotDeluxeQuant] = 0;
        UberAppTemp[playerid][UberEatTemp] = -1;
        UberAppTemp[playerid][TotalQuant] = 0;
    }
    return 1;
}

ShowPhoneVRP(playerid)
{
    new years,
	months,
	days;

	new MonthName[12][] =
	{
		"Januari", "Februari", "Maret", "April", "Mei", "Juni",
		"Juli",	"Agustus", "September", "Oktober", "November", "Desember"
	};
    getdate(years, months, days);
    PlayerTextDrawSetString(playerid, PhoneVRP[playerid][19], sprintf("%s, %02d %s %d", GetWeekDay(days, months, years), days, MonthName[months-1], years));
    for(new x; x < 73; x++)
    {
        PlayerTextDrawShow(playerid, PhoneVRP[playerid][x]);
    }
    SelectTextDraw(playerid, Y_Vertex);
}

HidePhoneMainMenuTD(playerid)
{
    for(new x; x < 73; x++)
    {
        PlayerTextDrawHide(playerid, PhoneVRP[playerid][x]);
    }
}

// ShowPhoneAppStoreTD(playerid)
// {
//     HidePhoneMainMenuTD(playerid);

//     for(new x; x < 26; x++)
//     {
//         TextDrawShowForPlayer(playerid, AppStoreTD[x]);
//     }
//     TextDrawShowForPlayer(playerid, InstallWAButtonPhone);
//     TextDrawShowForPlayer(playerid, InstallSpotifyButtonPhone);
//     TextDrawShowForPlayer(playerid, InstallTwitterButtonPhone);
//     TextDrawShowForPlayer(playerid, InstallUberButtonPhone);
//     TextDrawShowForPlayer(playerid, InstallYellowButtonPhone);

//     // PlayerPhoneData[playerid][phoneShowedPageTD] = 3;
// }

HidePhoneAppStoreTD(playerid)
{
    for(new x; x < 26; x++)
    {
        TextDrawHideForPlayer(playerid, AppStoreTD[x]);
    }
    TextDrawHideForPlayer(playerid, InstallWAButtonPhone);
    TextDrawHideForPlayer(playerid, InstallSpotifyButtonPhone);
    TextDrawHideForPlayer(playerid, InstallTwitterButtonPhone);
    TextDrawHideForPlayer(playerid, InstallUberButtonPhone);
    TextDrawHideForPlayer(playerid, InstallYellowButtonPhone);
}

ShowPhoneContactTD(playerid)
{
    for(new x; x < 70; x++)
    {
        PlayerTextDrawShow(playerid, KontakVRP[playerid][x]);
    }
    ShowContactList(playerid);
    SetPVarInt(playerid, "OpenKontakTD", true);
}

HidePhoneContactTD(playerid)
{
    for(new x; x < 70; x++)
    {
        PlayerTextDrawHide(playerid, KontakVRP[playerid][x]);
    }
    SetPVarInt(playerid, "OpenKontakTD", false);
}

ShowPhoneBankingTD(playerid)
{
    PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][48], sprintf("%s", GetPlayerRoleplayName(playerid))); //nama
    PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][50], sprintf("$%s", FormatMoney(AccountData[playerid][pBankMoney]))); // saldo
    PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][52], sprintf("%d", AccountData[playerid][pBankNumber])); //no rek
    if (AccountData[playerid][pLastTransferInAmount] > 0)
    {
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][60], AccountData[playerid][pLastTransferInDate]);
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][61], sprintf("+$%s", FormatMoney(AccountData[playerid][pLastTransferInAmount])));
    }
    else
    {
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][60], "- - -");
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][61], "N/A");
    }
    if (AccountData[playerid][pLastTransferOutAmount] > 0)
    {
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][64], AccountData[playerid][pLastTransferOutDate]);
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][65], sprintf("-$%s", FormatMoney(AccountData[playerid][pLastTransferOutAmount])));
    }
    else
    {
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][64], "- - -");
        PlayerTextDrawSetString(playerid, PhoneBankVRP[playerid][65], "N/A");
    }
    for(new x; x < 68; x++)
    {
        PlayerTextDrawShow(playerid, PhoneBankVRP[playerid][x]);
    }
}

HidePhoneBankingTD(playerid)
{
    for(new x; x < 68; x++)
    {
        PlayerTextDrawHide(playerid, PhoneBankVRP[playerid][x]);
    }
}

// ShowPhoneSettingsTD(playerid)
// {
//     TextDrawShowForPlayer(playerid, SettingsTD[0]);
//     TextDrawShowForPlayer(playerid, SettingsTD[1]);
//     TextDrawShowForPlayer(playerid, SettingsTD[2]);

//     for(new x; x < 5; x++)
//     {
//         switch(x)
//         {
//             case 1, 3, 4:
//             {
//                 continue;
//             }
//         }
//         TextDrawShowForPlayer(playerid, ContactTD[x]);
//     }
//     // PlayerPhoneData[playerid][phoneShowedPageTD] = 6;
// }

HidePhoneSettingsTD(playerid)
{
    TextDrawHideForPlayer(playerid, SettingsTD[0]);
    TextDrawHideForPlayer(playerid, SettingsTD[1]);
    TextDrawHideForPlayer(playerid, SettingsTD[2]);

    for(new x; x < 5; x++)
    {
        switch(x)
        {
            case 1, 3, 4:
            {
                continue;
            }
        }
    }
}

ShowTwitterLoginTD(playerid)
{
    for(new x; x < 26; x++)
    {
        PlayerTextDrawShow(playerid, LoginTwittVRP[playerid][x]);
    }
}

ShowTwitterMainTD(playerid)
{
    for(new x; x < 29; x++)
    {
        PlayerTextDrawShow(playerid, HomeTwittVRP[playerid][x]);
    }
    PlayerPhoneData[playerid][CurrentlyReadTweet] = true;
    pageTwitter[playerid] = 0;
    PhoneSyncTwitterUI(playerid);
}

HideTwitterTD(playerid)
{
    for(new x; x < 26; x++)
    {
        PlayerTextDrawHide(playerid, LoginTwittVRP[playerid][x]);
    }

    for(new x; x < 29; x++)
    {
        PlayerTextDrawHide(playerid, HomeTwittVRP[playerid][x]);
    }
    HideTwitterUIList(playerid);
}

ShowCameraTD(playerid, bool:status)
{
    if(status)
    {
        for(new i = 0; i < 60; i++)
        {
            PlayerTextDrawShow(playerid, CameraVRP[playerid][i]);
        }
    }
    else 
    {
        for(new x; x < 60; x++)
        {
            PlayerTextDrawHide(playerid, CameraVRP[playerid][x]);
        }
    }
    return 1;
}

ShowKalkulatorTD(playerid, bool:status)
{
    if(status)
    {
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], "0");
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][57], "_");
        for(new i = 0; i < 59; i++)
        {
            PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][i]);
        }
    }
    else 
    {
        for(new i = 0; i < 59; i++)
        {
            PlayerTextDrawHide(playerid, KalkulatorVRP[playerid][i]);
        }
    }
    return 1;
}

ShowUberPhoneTD(playerid)
{
    PlayerTextDrawColor(playerid, UberVRP[playerid][50], -2004317953);
    PlayerTextDrawColor(playerid, UberVRP[playerid][52], -2004317953);
    PlayerTextDrawColor(playerid, UberVRP[playerid][76], -2004317953);
    PlayerTextDrawColor(playerid, UberVRP[playerid][78], -2004317953);
    for(new x; x < 93; x++)
    {
        PlayerTextDrawShow(playerid, UberVRP[playerid][x]);
    }
    if(SelectUberTD[playerid] == -1)
    {
        for(new i = 79; i < 89; i++)
        {
            PlayerTextDrawHide(playerid, UberVRP[playerid][i]);
        }
    }
}

HideUberPhoneTD(playerid)
{
    for(new x; x < 93; x++)
    {
        PlayerTextDrawHide(playerid, UberVRP[playerid][x]);
    }
}

ShowSpotifyTD(playerid)
{
    if(SelectMusicTD[playerid] == -1)
    {
        for(new i = 30; i < 36; i++) //boombox color redup
        {
            PlayerTextDrawColor(playerid, MusicVRP[playerid][i], 254613759);
        }
        PlayerTextDrawColor(playerid, MusicVRP[playerid][64], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][66], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][46], 1521318655);

        for(new i = 68; i < 74; i++) //earphone color redup
        {
            PlayerTextDrawColor(playerid, MusicVRP[playerid][i], 254613759);
        }
        PlayerTextDrawColor(playerid, MusicVRP[playerid][101], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][103], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][83], 1521318655);
    }
    for(new i = 0; i < 107; i++)
    {
        PlayerTextDrawShow(playerid, MusicVRP[playerid][i]);
    }
}

HideSpotifyTD(playerid)
{
    for(new x; x < 107; x++)
    {
        PlayerTextDrawHide(playerid, MusicVRP[playerid][x]);
    }
}

// HidePhoneTD(playerid)
// {
//     for(new x; x < 73; x++)
//     {
//         PlayerTextDrawHide(playerid, PhoneVRP[playerid][x]);
//     }
//     CancelSelectTextDraw(playerid);
// }

HideAllPhoneTD(playerid)
{
    HideUberPhoneTD(playerid);
    HideSpotifyTD(playerid);
    HideTwitterTD(playerid);
    HidePhoneSettingsTD(playerid);
    HidePhoneAppStoreTD(playerid);
    HidePhoneMainMenuTD(playerid);
    HidePhoneBankingTD(playerid);
    HidePhoneContactTD(playerid);

    PlayerTextDrawHide(playerid, ContactNameTD[playerid]);
    PlayerTextDrawHide(playerid, StatusDialingTD[playerid]);

    PlayerPhoneData[playerid][phoneShown] = false;
    pShortcutResultShown[playerid] = false;
    CancelSelectTextDraw(playerid);

    ShowServerNameTD(playerid);
    //ShowStatsTD(playerid);
    ShowHBETD(playerid);
    ShowRadioVoiceInfoTD(playerid);

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
        ShowSpeedoTD(playerid);
}

ShowContactListV1(playerid) 
{
    new 
        curr_page = index_contact[playerid],
        count = 0,
        string[1012],
        real_i = 0,
        contact_exists[MAX_CONTACT_ROWS],
        contact_name[MAX_CONTACT_ROWS][24],
        contact_number[MAX_CONTACT_ROWS][13],
        contact_unread[MAX_CONTACT_ROWS],
        contact_blocked[MAX_CONTACT_ROWS],
        contact_id[MAX_CONTACT_ROWS],
        curr_idx;

    curr_idx = MAX_CONTACT_ROWS * curr_page;

    PlayerPhoneData[playerid][CurrentlyReadWA] = false;
    PlayerPhoneData[playerid][phoneContactSelected] = -1;

    for(new i = 0; i < MAX_CONTACT_ROWS; i++) {
        contact_exists[i] = 0;
    }

    strcat(string, "Nama Kontak\tNomor\tStatus\tBlokir\n");
    for(new i = 0; i < MAX_CONTACTS; i++) {
        if(ContactData[playerid][i][contactExists]) {
            if (real_i >= curr_idx && real_i < curr_idx + MAX_CONTACT_ROWS) {
                contact_exists[real_i - curr_idx] = 1;
                contact_id[real_i - curr_idx] = i;
                strcopy(contact_number[real_i - curr_idx], ContactData[playerid][i][contactNumber], 13);
                contact_unread[real_i - curr_idx] = ContactData[playerid][i][contactUnread];
                strcopy(contact_name[real_i - curr_idx], ContactData[playerid][i][contactName], 24);
                contact_blocked[real_i - curr_idx] = ContactData[playerid][i][contactBlocked];
            }
            real_i++;
        }
    }
    for(new i = 0; i < MAX_CONTACT_ROWS; i++) {
        if(contact_exists[i]) {
            new numberowner = GetNumberOwner(contact_number[i]);
            if(!contact_unread[i]) {
                strcat(string, sprintf("%s\t%s\t%s\t%s\n", 
                    contact_name[i], contact_number[i], IsPlayerConnected(numberowner) ? ""GREEN"(Online)" : ""ORANGE"(Offline)", contact_blocked[i] ? ""RED"Diblokir" : ""GREEN"-"));
            } else {
                strcat(string, sprintf("%s\t%s\t%s "LIGHTGREY"[%d unread]\t%s\n", 
                    contact_name[i], contact_number[i], IsPlayerConnected(numberowner) ? ""GREEN"(Online)" : ""ORANGE"(Offline)", contact_unread[i], contact_blocked[i] ? ""RED"Diblokir" : ""GREEN"-"));
            }
            ListedContacts[playerid][count++] = contact_id[i];
        }
    }

    new max_contact_page = (real_i + MAX_CONTACT_ROWS - 1) / MAX_CONTACT_ROWS; 

    if(curr_page > 0) {
        strcat(string, ""RED"<< Sebelumnya");
        strcat(string, "\n");
    }
    if(curr_page < max_contact_page - 1) {
        strcat(string, ""GREEN">> Selanjutnya");
        strcat(string, "\n");
    }

    Dialog_Show(playerid, "ContactList", DIALOG_STYLE_TABLIST_HEADERS, sprintf("Contact List: Page %d of %d", curr_page + 1, max_contact_page), string, "Pilih", "Batal");
    return 1;
}

// ShowContactList(playerid)
// {
// 	new
// 		count = 0;

//     PlayerPhoneData[playerid][CurrentlyReadWA] = false;
//     PlayerPhoneData[playerid][phoneContactSelected] = -1;

//     AddDialogListitem(playerid, "Nama Kontak\tNomor\tStatus\tBlokir");
// 	for (new i; i < MAX_CONTACTS; i ++) if (ContactData[playerid][i][contactExists] && ContactData[playerid][i][contactOwnerID] == AccountData[playerid][pID])
// 	{
//         new numberowner = GetNumberOwner(ContactData[playerid][i][contactNumber]);
//         if(!ContactData[playerid][i][contactUnread])
//         {
//             AddDialogListitem(playerid, "%s\t%s\t%s\t%s", ContactData[playerid][i][contactName], ContactData[playerid][i][contactNumber], IsPlayerConnected(numberowner) ? ""GREEN"(Online)" : ""ORANGE"(Offline)", ContactData[playerid][i][contactBlocked] ? ""RED"Diblokir" : ""GREEN"-");
//         }
//         else
//         {
//             AddDialogListitem(playerid, "%s\t%s\t%s "LIGHTGREY"[%d unread]\t%s", ContactData[playerid][i][contactName], ContactData[playerid][i][contactNumber], IsPlayerConnected(numberowner) ? ""GREEN"(Online)" : ""ORANGE"(Offline)", ContactData[playerid][i][contactUnread], ContactData[playerid][i][contactBlocked] ? ""RED"Diblokir" : ""GREEN"-");
//         }
// 		ListedContacts[playerid][count++] = i;
// 	}

//     if(count != 0)
//     {
//         ShowPlayerDialogPages(playerid, "ContactListDialog", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Daftar Kontak", "Pilih", "Batal", 15, ""GREEN">> Lanjut", ""ORANGE"<< Kembali");
//     }
//     else
//     {
//         Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Daftar Kontak", "Anda tidak memiliki kontak yang tersimpan", "Tutup", "");
//     }
//     return 1;
// }

GetNumberOwner(const number[])
{
	foreach (new i : Player) if (!strcmp(PlayerPhoneData[i][phoneNumber], number, false) && PlayerHasItem(i, "Smartphone"))
	{
		return i;
	}
	return INVALID_PLAYER_ID;
}

GetMySavedContactName(targetid, const number[]) //simpelnya, apakah si targetid itu menyimpan number[] tersebut atau tidak, jika iya maka akan dilihatkan nama, jika tidak maka hanya nomor
{
    //targetid adalah orang yang akan dicek kontaknya, number adalah nomor tujuan untuk dicek apakah tersimpan oleh targetid atau tidak
    new frmtname[24];
    format(frmtname, sizeof(frmtname), "%s", number); //secara default akan diset menjadi nomor
    for(new cid; cid < MAX_CONTACTS; cid++)
    {
        if(ContactData[targetid][cid][contactExists]) //jika kontaknya tersimpan di targetid
        {
            if(!strcmp(ContactData[targetid][cid][contactNumber], number, false)) //jika nomor yang ingin dicek ada di kontak targetid
            {
                format(frmtname, sizeof(frmtname), "%s", ContactData[targetid][cid][contactName]); //maka didapatkan nama kontak yang tersimpan
            }
        }
    }
    return frmtname; //dikembalikan ke teks string yang akan dihasilkan
}

IsMyNumberBlocked(targetid, const number[]) //simpelnya, apakah si targetid memblokir nomor saya atau tidak
{
    //targetid adalah orang yang akan dicek kontaknya, number adalah nomor tujuan untuk dicek apakah diblokir oleh targetid atau tidak
    for(new cid; cid < MAX_CONTACTS; cid++)
    {
        if(ContactData[targetid][cid][contactExists]) //jika kontaknya tersimpan di targetid
        {
            if(!strcmp(ContactData[targetid][cid][contactNumber], number, false)) //jika nomor yang ingin dicek ada di kontak targetid
            {
                if(ContactData[targetid][cid][contactBlocked])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

CountPlayerContacts(playerid)
{
    new count;
    for(new x; x < MAX_CONTACTS; x++)
    {
        if(ContactData[playerid][x][contactExists])
        {
            count++;
        }
    }
    return count;
}

CutCallingLine(playerid)
{
    new inlinewithplayerID = PlayerPhoneData[playerid][phoneCallingWithPlayerID]; //orang yang menelepon
    PlayerPhoneData[playerid][phoneIncomingCall] = false;
    PlayerPhoneData[playerid][phoneDuringConversation] = false;
    PlayerPhoneData[playerid][phoneCallingTime] = 0;

    if(IsPlayerConnected(inlinewithplayerID))
    {
        PlayerPhoneData[inlinewithplayerID][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;
        PlayerPhoneData[inlinewithplayerID][phoneIncomingCall] = false;
        PlayerPhoneData[inlinewithplayerID][phoneDuringConversation] = false;
        PlayerPhoneData[inlinewithplayerID][phoneCallingTime] = 0;

        HideAllPhoneTD(inlinewithplayerID);
        RemovePlayerAttachedObject(inlinewithplayerID, 9);
        ApplyAnimation(inlinewithplayerID, "PED", "PHONE_OUT", 4.1, false, false, false, false, 0, true);

        SendRPMeAboveHead(inlinewithplayerID, "Memutuskan panggilan dan menutup smartphone.");
    }

    PlayerPhoneData[playerid][phoneCallingWithPlayerID] = INVALID_PLAYER_ID;

    HideAllPhoneTD(playerid);
    RemovePlayerAttachedObject(playerid, 9);
    ApplyAnimation(playerid, "PED", "PHONE_OUT", 4.1, false, false, false, false, 0, true);
    
    SendRPMeAboveHead(playerid, "Memutuskan panggilan dan menutup smartphone.");
    CallRemoteFunction("DisconnectPlayerCalling", "ii", playerid, inlinewithplayerID);
}

forward OnOutcomingCall(playerid, const targetnumber[]); //disaat player menghubungi player lain
public OnOutcomingCall(playerid, const targetnumber[])
{
    HideAllPhoneTD(playerid);

    // for(new x; x < 11; x++)
    // {
    //     switch(x)
    //     {
    //         case 6, 7: continue;
    //     }
    //     TextDrawShowForPlayer(playerid, LockScreenTD[x]);
    // }
    // TextDrawShowForPlayer(playerid, RedButtonOutcomingPhone);

    new contnstr[25];
    format(contnstr, sizeof(contnstr), "%s", targetnumber);
    for(new cid; cid < MAX_CONTACTS; cid++)
    {
        if(ContactData[playerid][cid][contactExists])
        {
            if(!strcmp(ContactData[playerid][cid][contactNumber], targetnumber, false)) //jika nomor tersimpan di kontak player yang menelepon
            {
                format(contnstr, sizeof(contnstr), "%s", ContactData[playerid][cid][contactName]);
            }
        }
    }
    PlayerTextDrawSetString(playerid, ContactNameTD[playerid], contnstr);
    new targetnumownerid = GetNumberOwner(targetnumber);
    if(IsPlayerConnected(targetnumownerid))
    {
        if(IsMyNumberBlocked(targetnumownerid, PlayerPhoneData[playerid][phoneNumber]))
        {
            PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "Anda Diblokir...");
            PlayerPhoneData[playerid][phoneIncomingCall] = true;
        }
        else
        {
            if(PlayerPhoneData[targetnumownerid][phoneIncomingCall] || PlayerPhoneData[targetnumownerid][phoneDuringConversation])
            {
                PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "Panggilan Sibuk...");
                PlayerPhoneData[playerid][phoneIncomingCall] = true;
            }
            else
            {
                if(!PlayerPhoneData[targetnumownerid][phoneOn]) 
                {
                    PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "Nomor Tidak Aktif...");
                    PlayerPhoneData[playerid][phoneIncomingCall] = true;
                }
                else
                {
                    PlayerPlaySound(targetnumownerid, 20804, 0.0, 0.0, 0.0);
                    ShowTDN(targetnumownerid, NOTIFICATION_WARNING, "Smartphone anda berdering...");
                    PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "Berdering...");
                    PlayerPhoneData[targetnumownerid][phoneIncomingCall] = true;
                    PlayerPhoneData[playerid][phoneIncomingCall] = true;
                    PlayerPhoneData[playerid][phoneCallingWithPlayerID] = targetnumownerid;
                    PlayerPhoneData[targetnumownerid][phoneCallingWithPlayerID] = playerid;
                    strcopy(PlayerPhoneData[targetnumownerid][phoneTempNumber], PlayerPhoneData[playerid][phoneNumber]);
                    strcopy(PlayerPhoneData[playerid][phoneTempNumber], PlayerPhoneData[playerid][phoneNumber]);
                    OnIncomingCall(targetnumownerid, PlayerPhoneData[playerid][phoneTempNumber]);
                }
            }
        }
    }
    else
    {
        PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "Memanggil...");
        PlayerPhoneData[playerid][phoneIncomingCall] = true;
    }
    PlayerPlaySound(playerid, 3600, 0.0, 0.0, 0.0);
    // TextDrawShowForPlayer(playerid, HomeButtonPhone[0]);
    // TextDrawShowForPlayer(playerid, HomeButtonPhone[1]);
    // TextDrawShowForPlayer(playerid, GreyBoxBackground);
    PlayerTextDrawShow(playerid, ContactNameTD[playerid]);
    PlayerTextDrawShow(playerid, StatusDialingTD[playerid]);

    SelectTextDraw(playerid, Y_Vertex);

    ApplyAnimation(playerid, "ped", "phone_talk", 2.00, true, true, true, true, 1, true);
    SetPlayerAttachedObject(playerid, 9, 18871, 6, 0.078999, 0.047999, 0.023999, 0.000000, 0.000000, 179.099899, 1.000000, 1.000000, 1.000000);
    return 1;
}

forward OnIncomingCall(playerid, const fromnumber[]);
public OnIncomingCall(playerid, const fromnumber[])
{
    HideAllPhoneTD(playerid);

    // for(new x; x < 11; x++)
    // {
    //     switch(x)
    //     {
    //         case 6, 7: continue;
    //     }
    //     TextDrawShowForPlayer(playerid, LockScreenTD[x]);
    // }

    new contnstr[25];
    format(contnstr, sizeof(contnstr), "%s", fromnumber); //secara default akan menampilkan nomor hp saja
    for(new cid; cid < MAX_CONTACTS; cid++)
    {
        if(ContactData[playerid][cid][contactExists])
        {
            if(!strcmp(ContactData[playerid][cid][contactNumber], fromnumber, false)) //jika nomor tersimpan di kontak player yang ditelpon
            {
                format(contnstr, sizeof(contnstr), "%s", ContactData[playerid][cid][contactName]); //maka diset namanya sesuai nama kontak
            }
        }
    }
    PlayerTextDrawSetString(playerid, ContactNameTD[playerid], contnstr);
    PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "Panggilan Masuk...");

    // TextDrawShowForPlayer(playerid, HomeButtonPhone[0]);
    // TextDrawShowForPlayer(playerid, HomeButtonPhone[1]);
    // TextDrawShowForPlayer(playerid, GreyBoxBackground);
    // TextDrawShowForPlayer(playerid, RedButtonIncomingPhone);
    // TextDrawShowForPlayer(playerid, GreenButtonIncomingPhone);
    PlayerTextDrawShow(playerid, ContactNameTD[playerid]);
    PlayerTextDrawShow(playerid, StatusDialingTD[playerid]);

    SelectTextDraw(playerid, Y_Vertex);
    return 1;
}

forward OnContactAdded(playerid, contid);
public OnContactAdded(playerid, contid)
{
    ContactData[playerid][contid][contactID] = cache_insert_id();
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil menambahkan %s ke kontak.", ContactData[playerid][contid][contactName]));
    if(GetPVarInt(playerid, "OpenKontakTD"))
    {
        ShowContactList(playerid);
    }
    return 1;
}

forward OnWhatsappSent(playerid, targetid, contactselected, serverid, const textuals[]);
public OnWhatsappSent(playerid, targetid, contactselected, serverid, const textuals[])
{
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Pesan telah dikirim kepada %s", ContactData[playerid][contactselected][contactName]));
    SendClientMessageEx(targetid, X11_YELLOW, "Pesan WhatsApp dari "RED"%s: "WHITE"%s", GetMySavedContactName(targetid, PlayerPhoneData[playerid][phoneNumber]), textuals);

    new cidt = PlayerPhoneData[targetid][phoneContactSelected];
    if(cidt != -1)
    {
        if(PlayerPhoneData[targetid][CurrentlyReadWA])
        {
            if(!strcmp(ContactData[targetid][cidt][contactNumber], PlayerPhoneData[playerid][phoneNumber], false))
            {
                new query[512], harlem[128];
                mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `whatsapp_chats` WHERE `ID`=%d ORDER BY `chatTimestamp` ASC LIMIT 30", serverid);
                mysql_query(g_SQL, query);
                new rows = cache_num_rows();
                if(rows) 
                {
                    if(rows >= 30)
                    {
                        mysql_format(g_SQL, harlem, sizeof(harlem), "DELETE FROM `whatsapp_chats` WHERE `ID`=%d", serverid);
                        mysql_pquery(g_SQL, harlem);
                    }

                    new list[2500], date[64], issuer[24], watext[128];

                    ContactData[targetid][cidt][contactUnread] = 0;
                    mysql_format(g_SQL, query, sizeof(query), "UPDATE `phone_contacts` SET `contactUnread`=0 WHERE `contactID`=%d", ContactData[targetid][cidt][contactID]);
                    mysql_pquery(g_SQL, query);
                    
                    format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
                    for(new i; i < rows; ++i)
                    {
                        cache_get_value_name(i, "chatTimestamp", date);
                        cache_get_value_name(i, "chatSender", issuer);
                        cache_get_value_name(i, "chatMessage", watext);
                        
                        strcat(list, sprintf("%s\t%s\t%s\n", date, issuer, watext), sizeof(list));
                    }
                    new title[100];
                    format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[targetid][cidt][contactName]);
                    Dialog_Show(targetid, "WhatsappChat", DIALOG_STYLE_TABLIST_HEADERS, title, list, "Send", "Kembali");
                }
                else
                {
                    new list[268], title[108];
                    
                    format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
                    strcat(list, "Messages and calls are end-to-end encrypted.", sizeof(list));
                    format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[targetid][cidt][contactName]);
                    Dialog_Show(targetid, "WhatsappChatEmpty", DIALOG_STYLE_TABLIST_HEADERS, title, list, "Send", "Kembali");
                }
            }
        }
    }

    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `whatsapp_chats` WHERE `ID`=%d ORDER BY `chatTimestamp` ASC LIMIT 30", serverid);
    mysql_query(g_SQL, query);
    new rows = cache_num_rows();
    if(rows) 
    {
        if(rows >= 30)
        {
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `whatsapp_chats` WHERE `ID`=%d", serverid);
            mysql_pquery(g_SQL, query);
        }

        new list[2500], date[64], issuer[24], watext[128];

        ContactData[playerid][contactselected][contactUnread] = 0;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `phone_contacts` SET `contactUnread`=0 WHERE `contactID`=%d", ContactData[playerid][contactselected][contactID]);
        mysql_pquery(g_SQL, query);
        
        format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
        for(new i; i < rows; ++i)
        {
            cache_get_value_name(i, "chatTimestamp", date);
            cache_get_value_name(i, "chatSender", issuer);
            cache_get_value_name(i, "chatMessage", watext);
            
            strcat(list, sprintf("%s\t%s\t%s\n", date, issuer, watext), sizeof(list));
        }
        new title[100];
        format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][contactselected][contactName]);
        Dialog_Show(playerid, "WhatsappChat", DIALOG_STYLE_TABLIST_HEADERS, title, list, "Send", "Kembali");
    }
    else
    {
        new list[268], title[108];
        
        format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
        strcat(list, "Messages and calls are end-to-end encrypted.", sizeof(list));
        format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][contactselected][contactName]);
        Dialog_Show(playerid, "WhatsappChatEmpty", DIALOG_STYLE_TABLIST_HEADERS, title, list, "Send", "Kembali");
    }
    return 1;
}

forward OnPhoneInstallApp(playerid, appselected);
public OnPhoneInstallApp(playerid, appselected)
{
    if(!IsPlayerConnected(playerid))
    {
        KillTimer(PlayerPhoneData[playerid][phoneInstallAppTimer]);
        PlayerPhoneData[playerid][phoneInstallAppTimer] = -1;

        PlayerPhoneData[playerid][phoneDownloadingApp] = false;
        PlayerPhoneData[playerid][phoneDownloadingProg] = 0;
        return 0;
    }
    if(!PlayerPhoneData[playerid][phoneDownloadingApp])
    {
        KillTimer(PlayerPhoneData[playerid][phoneInstallAppTimer]);
        PlayerPhoneData[playerid][phoneInstallAppTimer] = -1;

        PlayerPhoneData[playerid][phoneDownloadingApp] = false;
        PlayerPhoneData[playerid][phoneDownloadingProg] = 0;
        return 0;
    }
    if(!PlayerHasItem(playerid, "Smartphone"))
    {
        KillTimer(PlayerPhoneData[playerid][phoneInstallAppTimer]);
        PlayerPhoneData[playerid][phoneInstallAppTimer] = -1;

        PlayerPhoneData[playerid][phoneDownloadingApp] = false;
        PlayerPhoneData[playerid][phoneDownloadingProg] = 0;
        return 0;
    }
    if(PlayerPhoneData[playerid][phoneDownloadingProg] >= 100)
    {
        KillTimer(PlayerPhoneData[playerid][phoneInstallAppTimer]);
        PlayerPhoneData[playerid][phoneInstallAppTimer] = -1;

        PlayerPhoneData[playerid][phoneDownloadingApp] = false;
        PlayerPhoneData[playerid][phoneDownloadingProg] = 0;

        new sqlfstr[128];

        switch(appselected)
        {
            case 1:
            {
                PlayerPhoneData[playerid][phoneWhatsAppInstalled] = true;
                mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `WhatsappInstalled`=1 WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                mysql_pquery(g_SQL, sqlfstr);
            }
            case 2:
            {
                PlayerPhoneData[playerid][phoneSpotifyInstalled] = true;
                mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `SpotifyInstalled`=1 WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                mysql_pquery(g_SQL, sqlfstr);
            }
            case 3:
            {
                PlayerPhoneData[playerid][phoneTwitterInstalled] = true;
                mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `TwitterInstalled`=1 WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                mysql_pquery(g_SQL, sqlfstr);
            }
            case 4:
            {
                PlayerPhoneData[playerid][phoneUberInstalled] = true;
                mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `UberInstalled`=1 WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                mysql_pquery(g_SQL, sqlfstr);
            }
            case 5:
            {
                PlayerPhoneData[playerid][phoneYellowInstalled] = true;
                mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `YellowInstalled`=1 WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                mysql_pquery(g_SQL, sqlfstr);
            }
        }
    }
    else
    {
        PlayerPhoneData[playerid][phoneDownloadingProg] += 5;
        GameTextForPlayer(playerid, sprintf("Downloading: %d/100", PlayerPhoneData[playerid][phoneDownloadingProg]), 1000, 3);
    }
    return 1;
}

forward LoadPlayerContact(playerid);
public LoadPlayerContact(playerid)
{
	if(cache_num_rows() > 0)
	{
		for(new i; i < cache_num_rows(); i++)
		{
            if(!ContactData[playerid][i][contactExists])
            {
                ContactData[playerid][i][contactExists] = true;
                cache_get_value_name_int(i, "contactID", ContactData[playerid][i][contactID]);
                cache_get_value_name(i, "contactName", ContactData[playerid][i][contactName]);
                cache_get_value_name(i, "contactNumber", ContactData[playerid][i][contactNumber]);
                cache_get_value_name_int(i, "contactUnread", ContactData[playerid][i][contactUnread]);
                cache_get_value_name_int(i, "contactOwnerID", ContactData[playerid][i][contactOwnerID]);
                cache_get_value_name_int(i, "contactBlocked", ContactData[playerid][i][contactBlocked]);
            }
		}
        printf("[Player Contacts] Jumlah total Contacts yang dimuat untuk %s [DBID: %d]: %d.", AccountData[playerid][pUCP], AccountData[playerid][pID], cache_num_rows());
	}
	return 1;
}

forward LoadPlayerPhone(playerid);
public LoadPlayerPhone(playerid)
{
    new count = cache_num_rows();
    if(count)
    {
        cache_get_value_name(0, "phoneOwnerName", PlayerPhoneData[playerid][phoneOwnerName]);
        cache_get_value_name(0, "phoneNumber", PlayerPhoneData[playerid][phoneNumber]);
        cache_get_value_name_int(0, "phoneWallpaper", PlayerPhoneData[playerid][phoneWallpaper]);
        cache_get_value_name_int(0, "WhatsappInstalled", PlayerPhoneData[playerid][phoneWhatsAppInstalled]);
        cache_get_value_name_int(0, "SpotifyInstalled", PlayerPhoneData[playerid][phoneSpotifyInstalled]);
        cache_get_value_name_int(0, "TwitterInstalled", PlayerPhoneData[playerid][phoneTwitterInstalled]);
        cache_get_value_name_int(0, "UberInstalled", PlayerPhoneData[playerid][phoneUberInstalled]);
        cache_get_value_name_int(0, "YellowInstalled", PlayerPhoneData[playerid][phoneYellowInstalled]);
        cache_get_value_name_int(0, "TwitterLoggedIn", PlayerPhoneData[playerid][IsTwitterLoggedIn]);
        printf("[Player Smartphone Loaded] %s [DBID: %d]", AccountData[playerid][pUCP], AccountData[playerid][pID]);
    }
    return 1;
}

forward MakeNewPhoneNumber(playerid, const phone[]);
public MakeNewPhoneNumber(playerid, const phone[])
{
	if(cache_num_rows() > 0)
	{
		//nomor HP Exist
		static query[128], lray[128];
        new rand = RandomEx(1111111, 9888888);
		new phones = rand+AccountData[playerid][pID];
        format(lray, sizeof(lray), "0828%d", phones);
		mysql_format(g_SQL, query, sizeof(query), "SELECT `phoneNumber` FROM `player_phones` WHERE `phoneNumber`='%e'", lray);
		mysql_pquery(g_SQL, query, "MakeNewPhoneNumber", "is", playerid, lray);
	}
	else
	{
		strcopy(PlayerPhoneData[playerid][phoneOwnerName], GetPlayerRoleplayName(playerid));
        strcopy(PlayerPhoneData[playerid][phoneNumber], phone);
		PlayerPhoneData[playerid][phoneWallpaper] = 5;
		PlayerPhoneData[playerid][phoneWhatsAppInstalled] = false;
		PlayerPhoneData[playerid][phoneSpotifyInstalled] = false;
		PlayerPhoneData[playerid][phoneTwitterInstalled] = false;
        PlayerPhoneData[playerid][phoneUberInstalled] = false;
		PlayerPhoneData[playerid][phoneYellowInstalled] = false;
		PlayerPhoneData[playerid][phoneOn] = false;

		static query[560];
		mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `player_phones` SET `phoneOwner`=%d, `phoneOwnerName`='%e', `phoneNumber`='%e', `phoneWallpaper`=5, `WhatsappInstalled`=0, `SpotifyInstalled`=0, `TwitterInstalled`=0, `UberInstalled`=0, `YellowInstalled`=0", 
		AccountData[playerid][pID], PlayerPhoneData[playerid][phoneOwnerName], PlayerPhoneData[playerid][phoneNumber]);
		mysql_pquery(g_SQL, query);

		Inventory_Add(playerid, "Smartphone", 18873);
	}
    return 1;
}

forward OnPlayerBuySmartphone(playerid);
public OnPlayerBuySmartphone(playerid)
{
	if(cache_num_rows() > 0)
	{
		Inventory_Add(playerid, "Smartphone", 18873);
	}
	else
	{
        static query[128], lray[128];
        new rand = RandomEx(1111111, 9888888);
		new simnumb = rand+AccountData[playerid][pID];
        format(lray, sizeof(lray), "0828%d", simnumb);
		mysql_format(g_SQL, query, sizeof(query), "SELECT `phoneNumber` FROM `player_phones` WHERE `phoneNumber`='%e'", lray);
		mysql_pquery(g_SQL, query, "MakeNewPhoneNumber", "is", playerid, lray);
	}
	return 1;
}

Dialog:ContactAddName(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(isnull(inputtext))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactAddName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: Tidak dapat dikosongkan!\n\
        Please insert the contact name that will be saved below:", "Input", "Kembali");
        return 1;
    }

    if(strlen(inputtext) > 24)
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactAddName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: Panjang nama kontak melebihi batas!\n\
        Please insert the contact name that will be saved below:", "Input", "Kembali");
        return 1;
    }

    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1) 
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactAddName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: You cannot input percent symbol!\n\
        Please insert the contact name that will be saved below:", "Input", "Kembali");
        return 1;
    }
    
    strcopy(PlayerPhoneData[playerid][phoneTempName], inputtext);
    new jjstr[155];
    format(jjstr, sizeof(jjstr), "Please insert phone number for %s:", PlayerPhoneData[playerid][phoneTempName]);
    Dialog_Show(playerid, "ContactAddNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
    jjstr, "Input", "Kembali");
    return 1;
}
Dialog:ContactAddNumber(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(isnull(inputtext))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactAddNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: Tidak dapat dikosongkan!\n\
        Please enter the phone number of the contact to be saved below:", "Input", "Kembali");
        return 1;
    }

    if(!IsNumericEx(inputtext))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactAddNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: The contact number must only contain digits!\n\
        Please enter the phone number of the contact to be saved below:", "Input", "Kembali");
        return 1;
    }

    if(strlen(inputtext) < 4 || strlen(inputtext) > 12)
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactAddNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: The phone number must be between 4 and 12 digits!\n\
        Please enter the phone number of the contact to be saved below:", "Input", "Kembali");
        return 1;
    }


    if(CountPlayerContacts(playerid) >= MAX_CONTACTS - 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kontak anda sudah mencapai batas maksimum!");

    new strasc[528];
    for(new i; i < MAX_CONTACTS; i ++)
    {
        if(ContactData[playerid][i][contactOwnerID] == AccountData[playerid][pID])
        {
            if(!strcmp(ContactData[playerid][i][contactNumber], inputtext, false))
                return SendClientMessageEx(playerid, 0xFF6347AA, "This number has been saved to your contact as %s", ContactData[playerid][i][contactName]);
        }

        if(!ContactData[playerid][i][contactExists])
        {
            ContactData[playerid][i][contactExists] = true;
            strcopy(ContactData[playerid][i][contactNumber], inputtext);
            ContactData[playerid][i][contactOwnerID] = AccountData[playerid][pID];
            strcopy(ContactData[playerid][i][contactName], PlayerPhoneData[playerid][phoneTempName]);

            mysql_format(g_SQL, strasc, sizeof(strasc), "INSERT INTO `phone_contacts` SET `contactName`='%e', `contactNumber`='%e', `contactOwnerID`=%d", ContactData[playerid][i][contactName], ContactData[playerid][i][contactNumber], AccountData[playerid][pID]);
            mysql_pquery(g_SQL, strasc, "OnContactAdded", "id", playerid, i);
            return 1;
        }
    }
    return 1;
}
Dialog:ContactSelect(playerid, response, listitem, inputtext[])
{
    if(!response)
    {   
        if(GetPVarInt(playerid, "OpenKontakTD"))
        {
            ShowContactList(playerid);
        }
        else 
        {
            ShowContactListV1(playerid);
        }
        return 1;
    } 

    new cid = PlayerPhoneData[playerid][phoneContactSelected],
        sstraw[144];
    if(cid == -1) return Info(playerid, "Anda belum memilih kontak apapun!");

    switch(listitem)
    {
        case 0: //call
        {
            new targetid = GetNumberOwner(ContactData[playerid][cid][contactNumber]);
            if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemilik nomor tersebut tidak terkoneksi ke server!");
            if(OJailData[targetid][jailed]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang di jail OOC!");
            if(AccountData[targetid][pArrested]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut sedang dipenjara kepolisian!");
            if(ContactData[playerid][cid][contactBlocked]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menghubungi kontak yang telah anda blokir!");
            strcopy(PlayerPhoneData[playerid][phoneTempNumber], ContactData[playerid][cid][contactNumber]);
            OnOutcomingCall(playerid, PlayerPhoneData[playerid][phoneTempNumber]);
        }
        case 1: //whatsapp
        {
            // if(!PlayerPhoneData[playerid][phoneWhatsAppInstalled]) return ShowTDN(playerid, NOTIFICATION_ERROR, "WhatsApp tidak terpasang di perangkat anda!");

            new targetid = GetNumberOwner(ContactData[playerid][cid][contactNumber]);
            if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemilik nomor tersebut tidak terkoneksi ke server!");

            PlayerPhoneData[playerid][CurrentlyReadWA] = true;

            new whatsappserverid = AccountData[playerid][pID] + AccountData[targetid][pID];
            new query[512];
            mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `whatsapp_chats` WHERE `ID`=%d ORDER BY `chatTimestamp` ASC LIMIT 30", whatsappserverid);
            mysql_query(g_SQL, query);
            new rows = cache_num_rows();
            if(rows) 
            {
                if(rows >= 30)
                {
                    mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `whatsapp_chats` WHERE `ID`=%d", whatsappserverid);
                    mysql_pquery(g_SQL, query);
                }

                new list[2500], date[64], issuer[24], watext[128];

                ContactData[playerid][cid][contactUnread] = 0;
                mysql_format(g_SQL, query, sizeof(query), "UPDATE `phone_contacts` SET `contactUnread`=0 WHERE `contactID`=%d", ContactData[playerid][cid][contactID]);
                mysql_pquery(g_SQL, query);
                
                format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
                for(new i; i < rows; ++i)
                {
                    cache_get_value_name(i, "chatTimestamp", date);
                    cache_get_value_name(i, "chatSender", issuer);
                    cache_get_value_name(i, "chatMessage", watext);
                    
                    strcat(list, sprintf("%s\t%s\t%s\n", date, issuer, watext), sizeof(list));
                }
                new title[100];
                format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cid][contactName]);
                Dialog_Show(playerid, "WhatsappChat", DIALOG_STYLE_TABLIST_HEADERS, title, list, "Send", "Kembali");
            }
            else
            {
                new list[268], title[108];
                
                format(list, sizeof(list), "Tanggal\tPengirim\tPesan\n");
                strcat(list, "Messages and calls are end-to-end encrypted.", sizeof(list));
                format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cid][contactName]);
                Dialog_Show(playerid, "WhatsappChatEmpty", DIALOG_STYLE_TABLIST_HEADERS, title, list, "Send", "Kembali");
            }
        }
        case 2: //shareloc
        {
            new Float:px, Float:py, Float:pz;
            new targetid = GetNumberOwner(ContactData[playerid][cid][contactNumber]);
            if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kontak tersebut tidak sedang terkoneksi ke server!");
            GetPlayerPos(playerid, px, py, pz);

            if(DestroyDynamicMapIcon(AccountData[targetid][pSharedGPSIcon]))
                AccountData[targetid][pSharedGPSIcon] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;

            AccountData[targetid][pSharedGPSIcon] = CreateDynamicMapIcon(px, py, pz, 0, 0x00FF00FF, -1, -1, targetid, 10000.00, MAPICON_GLOBAL, -1, 0);
            SendClientMessageEx(targetid, 0x80FF80AA, "[Server] Player %s has sent you their location.", GetMySavedContactName(targetid, PlayerPhoneData[playerid][phoneNumber]));
            SendClientMessageEx(playerid, 0x80FF80AA, "[Server] You have sent your location to %s.", ContactData[playerid][cid][contactName]);
        }
        case 3: //ubah nama kontak
        {
            format(sstraw, sizeof(sstraw), "Kontak %s - Edit Nama", ContactData[playerid][cid][contactName]);
            Dialog_Show(playerid, "ContactChangeName", DIALOG_STYLE_INPUT, sstraw, "Please enter a new name for this contact:", "Input", "Batal");
        }
        case 4: //blokir kontak
        {
            if(ContactData[playerid][cid][contactBlocked])
            {
                ContactData[playerid][cid][contactBlocked] = false;
                SendClientMessageEx(playerid, 0x80FF80AA, "[Server] You have unblocked %s from your contact list.", ContactData[playerid][cid][contactName]);
            }
            else
            {
                ContactData[playerid][cid][contactBlocked] = true;
                SendClientMessageEx(playerid, 0x80FF80AA, "[Server] You have blocked %s from your contact list.", ContactData[playerid][cid][contactName]);
            }
            mysql_format(g_SQL, sstraw, sizeof(sstraw), "UPDATE `phone_contacts` SET `contactBlocked`=%d WHERE `contactOwnerID` = %d AND `contactID` = %d", ContactData[playerid][cid][contactBlocked], AccountData[playerid][pID], ContactData[playerid][cid][contactID]);
            mysql_pquery(g_SQL, sstraw);

            index_contact[playerid] = 0;
            if(GetPVarInt(playerid, "OpenKontakTD"))
            {
                ShowContactList(playerid);
            }
            else 
            {
                ShowContactListV1(playerid);
            }
        }
        case 5: //hapus kontak
        {
            mysql_format(g_SQL, sstraw, sizeof(sstraw), "DELETE FROM `phone_contacts` WHERE `contactOwnerID` = %d AND `contactID` = %d", AccountData[playerid][pID], ContactData[playerid][cid][contactID]);
            mysql_pquery(g_SQL, sstraw);

            SendClientMessageEx(playerid, 0x80FF80AA, "[Server] You have removed %s from your contact list.", ContactData[playerid][cid][contactName]);

            ContactData[playerid][cid][contactID] = 0;
            ContactData[playerid][cid][contactExists] = false;
            ContactData[playerid][cid][contactName][0] = EOS;
            ContactData[playerid][cid][contactNumber][0] = EOS;
            ContactData[playerid][cid][contactOwnerID] = 0;
            ContactData[playerid][cid][contactUnread] = 0;

            index_contact[playerid] = 0;
            if(GetPVarInt(playerid, "OpenKontakTD"))
            {
                ShowContactList(playerid);
            }
            else 
            {
                ShowContactListV1(playerid);
            }
        }
    }
    return 1;
}
Dialog:ContactChangeName(playerid, response, listitem, inputtext[])
{
    new cid = PlayerPhoneData[playerid][phoneContactSelected],
        sstraw[144];
    if(cid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih kontak apapun!");

    if(!response) 
    {
        PlayerPhoneData[playerid][phoneContactSelected] = -1;
        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
        return 1;
    }

    if(isnull(inputtext))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactChangeName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: Tidak dapat dikosongkan!\n\
        Please enter a new name for this contact:", "Input", "Kembali");
        return 1;
    }

    if(strlen(inputtext) > 24)
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactChangeName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: Panjang nama kontak melebihi batas!\n\
        Please enter a new name for this contact:", "Input", "Kembali");
        return 1;
    }

    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1) 
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "ContactChangeName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Error: You cannot input percent symbol!\n\
        Please enter a new name for this contact:", "Input", "Kembali");
        return 1;
    }
    
    strcopy(ContactData[playerid][cid][contactName], inputtext);

    mysql_format(g_SQL, sstraw, sizeof(sstraw), "UPDATE `phone_contacts` SET `contactName`='%e' WHERE `contactOwnerID` = %d AND `contactID` = %d", ContactData[playerid][cid][contactName], AccountData[playerid][pID], ContactData[playerid][cid][contactID]);
    mysql_pquery(g_SQL, sstraw);
    ShowTDN(playerid, NOTIFICATION_INFO, sprintf("Anda telah mengganti nama kontak menjadi %s", ContactData[playerid][cid][contactName]));
    if(GetPVarInt(playerid, "OpenKontakTD"))
    {
        ShowContactList(playerid);
    }
    else 
    {
        ShowContactListV1(playerid);
    }
    PlayerPhoneData[playerid][phoneContactSelected] = -1;
    return 1;
}
Dialog:WhatsappChat(playerid, response, listitem, inputtext[])
{
    new cid = PlayerPhoneData[playerid][phoneContactSelected];
    if(cid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih kontak apapun!");

    if(!response) 
    {
        PlayerPhoneData[playerid][CurrentlyReadWA] = false;
        index_contact[playerid] = 0;
        if(GetPVarInt(playerid, "OpenKontakTD"))
        {
            ShowContactList(playerid);
        }
        else 
        {
            ShowContactListV1(playerid);
        }
        return 1;
    }
    
    new title[108];
    format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cid][contactName]);
    Dialog_Show(playerid, "WhatsappSend", DIALOG_STYLE_INPUT, title, "Enter your WhatsApp message in the field below:", "Send", "Kembali");
    return 1;
}
Dialog:WhatsappChatEmpty(playerid, response, listitem, inputtext[])
{
    new cid = PlayerPhoneData[playerid][phoneContactSelected];

    if(!response) 
    {
        PlayerPhoneData[playerid][CurrentlyReadWA] = false;
        index_contact[playerid] = 0;
        if(GetPVarInt(playerid, "OpenKontakTD"))
        {
            ShowContactList(playerid);
        }
        else 
        {
            ShowContactListV1(playerid);
        }
        return 1;
    }
    
    new title[108];
    format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cid][contactName]);
    Dialog_Show(playerid, "WhatsappSend", DIALOG_STYLE_INPUT, title, "Enter your WhatsApp message in the field below:", "Send", "Kembali");
    return 1;
}
Dialog:WhatsappSend(playerid, response, listitem, inputtext[])
{
    new cid = PlayerPhoneData[playerid][phoneContactSelected],
    query[522];

    if(!response)
    {
        new fzstr[128];
        format(fzstr, sizeof(fzstr), "Contact - %s", ContactData[playerid][PlayerPhoneData[playerid][phoneContactSelected]][contactName]);
        Dialog_Show(playerid, "ContactSelect", DIALOG_STYLE_LIST, fzstr, "Call\n"GRAY"WhatsApp\nShareloc\n"GRAY"Edit Contact Name\nUnblock/Block Contact\n"GRAY"Delete Contact", "Pilih", "Kembali");
        return 1;
    }
    if(isnull(inputtext))
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        new title[108];
        format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cid][contactName]);
        Dialog_Show(playerid, "WhatsappSend", DIALOG_STYLE_INPUT, title, "Error: Message Tidak dapat dikosongkan!\n\
        Enter your WhatsApp message in the field below:", "Send", "Kembali");
        return 1;
    }
    if(strlen(inputtext) < 1 || strlen(inputtext) > 128)
    {
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
        new title[108];
        format(title, sizeof(title), "WhatsApp Chat - %s", ContactData[playerid][cid][contactName]);
        Dialog_Show(playerid, "WhatsappSend", DIALOG_STYLE_INPUT, title, "Error: Message must be between 1 - 128 characters!\n\
        Enter your WhatsApp message in the field below:", "Send", "Kembali");
        return 1;
    }


    new targetid = GetNumberOwner(ContactData[playerid][cid][contactNumber]);
    if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemilik nomor tersebut tidak terkoneksi ke server!");
    if(ContactData[playerid][cid][contactBlocked]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menghubungi kontak yang telah anda blokir!");
    if(IsMyNumberBlocked(targetid, PlayerPhoneData[playerid][phoneNumber])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pesan tidak terkirim, kontak tersebut telah memblokir anda!");
    new whatsappserverid = AccountData[playerid][pID] + AccountData[targetid][pID];

    strcopy(TempWAText[playerid], inputtext);
    for(new x; x < MAX_CONTACTS; x++) if (ContactData[targetid][x][contactExists] && ContactData[targetid][x][contactOwnerID] == AccountData[targetid][pID])
    {
        if(!strcmp(ContactData[targetid][x][contactNumber], PlayerPhoneData[playerid][phoneNumber], false))
        {
            ContactData[targetid][x][contactUnread]++;
            mysql_format(g_SQL, query, sizeof(query), "UPDATE `phone_contacts` SET `contactUnread`=%d WHERE `contactID`=%d", ContactData[targetid][x][contactUnread], ContactData[targetid][x][contactID]);
            mysql_pquery(g_SQL, query);
        }
    }

    new biaya = strlen(TempWAText[playerid]) * 2;
    AccountData[playerid][pBankMoney] -= biaya;

    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `whatsapp_chats` (`ID`, `chatTimestamp`, `chatMessage`, `chatSender`, `chatNumber`, `chatOwner`) VALUES (%d, CURRENT_TIMESTAMP(), '%e', '%e', '%e', %d)", whatsappserverid, TempWAText[playerid], GetMySavedContactName(targetid, PlayerPhoneData[playerid][phoneNumber]), ContactData[playerid][cid][contactNumber], AccountData[playerid][pID]);
    mysql_pquery(g_SQL, query, "OnWhatsappSent", "iidds", playerid, targetid, cid, whatsappserverid, TempWAText[playerid]);
    return 1;
}
Dialog:PhoneAirdrop(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(listitem < 0 || listitem > 99) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada player lain di sekitar!");

    new targetid = NearestUser[playerid][listitem], ddstr[200];
    
    if(targetid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada player lain di sekitar!");

    if(!IsPlayerConnected(targetid)) return Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Airdrop", "Mohon maaf layanan Airdrop dibatalkan karena pemain tidak terkoneksi ke dalam server :(", 
    "Tutup", "");
    if(!IsPlayerNearPlayer(playerid, targetid, 1.5)) return Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Airdrop", "Mohon maaf That player is not near you!", 
    "Tutup", "");

    strcopy(PlayerPhoneData[targetid][phoneTempName], PlayerPhoneData[playerid][phoneOwnerName]);
    strcopy(PlayerPhoneData[targetid][phoneTempNumber], PlayerPhoneData[playerid][phoneNumber]);
    format(ddstr, sizeof(ddstr), "You have received a contact save request from:\n\
    Name: %s\n\
    Phone Number: %s\n\
    Are you sure you want to save this contact?", PlayerPhoneData[targetid][phoneTempName], PlayerPhoneData[targetid][phoneTempNumber]);
    Dialog_Show(targetid, "PhoneAirdropConfirm", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Airdrop", ddstr, "Yes", "No");
    return 1;
}
Dialog:PhoneAirdropConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah menolak airdrop!");

    if(CountPlayerContacts(playerid) >= MAX_CONTACTS - 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kontak anda telah mencapai maksimum!");

    new strasc[528];
    for (new i; i < MAX_CONTACTS; i ++)
    {
        if(ContactData[playerid][i][contactOwnerID] == AccountData[playerid][pID])
        {
            if(!strcmp(ContactData[playerid][i][contactNumber], PlayerPhoneData[playerid][phoneTempNumber], false))
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Nomor tersebut sudah ada di kontak atas nama %s.", ContactData[playerid][i][contactName]));
                return 1;
            }
        }
        
        if(!ContactData[playerid][i][contactExists])
        {
            ContactData[playerid][i][contactExists] = true;
            strcopy(ContactData[playerid][i][contactNumber], PlayerPhoneData[playerid][phoneTempNumber]);
            ContactData[playerid][i][contactOwnerID] = AccountData[playerid][pID];
            strcopy(ContactData[playerid][i][contactName], PlayerPhoneData[playerid][phoneTempName]);
            ContactData[playerid][i][contactBlocked] = false;

            mysql_format(g_SQL, strasc, sizeof(strasc), "INSERT INTO `phone_contacts` SET `contactName`='%e', `contactNumber`='%e', `contactOwnerID`=%d, `contactBlocked`=%d", ContactData[playerid][i][contactName], PlayerPhoneData[playerid][phoneTempNumber], AccountData[playerid][pID], ContactData[playerid][i][contactBlocked]);
            mysql_pquery(g_SQL, strasc, "OnContactAdded", "id", playerid, i);
            return 1;
        }
    }
    return 1;
}
Dialog:PhoneWallpaper(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(listitem == -1) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda belum memilih wallpaper apapun!");

    PlayerPhoneData[playerid][phoneWallpaper] = listitem;

    RemovePlayerAttachedObject(playerid, 9);
    StopLoopingAnim(playerid);

    HideAllPhoneTD(playerid);

    new sqlfstr[128];
    mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `phoneWallpaper`=%d WHERE `phoneOwner`=%d", listitem, AccountData[playerid][pID]);
    mysql_pquery(g_SQL, sqlfstr);
    return 1;
}
Dialog:SpotifyEarphone(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");
    if(isnull(inputtext)) return Info(playerid, "Tidak dapat dikosongkan!");

    PlayAudioStreamForPlayer(playerid, inputtext);
    PlayerPhoneData[playerid][phoneListeningSelf] = true;
    HideAllPhoneTD(playerid);
    return 1;
}
Dialog:SpotifyBoombox(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");
    if(isnull(inputtext)) return Info(playerid, "Tidak dapat dikosongkan!");

    if(!BoomBoxInfo[playerid][BoomBoxPlaced])
    {
        static labels[128];
        foreach(new i : Player)
        {
            if(BoomBoxInfo[i][BoomBoxPlaced])
            {
                if(IsPlayerInRangeOfPoint(playerid, 50.0, BoomBoxInfo[i][BoomX], BoomBoxInfo[i][BoomY], BoomBoxInfo[i][BoomZ]))
                    return Info(playerid, "Anda terlalu dekat dengan boombox player lain!");
            }
        }

        GetPlayerPos(playerid, BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ]);
        GetPlayerFacingAngle(playerid, BoomBoxInfo[playerid][BoomA]);

        BoomBoxInfo[playerid][BoomVw] = GetPlayerVirtualWorld(playerid);
        BoomBoxInfo[playerid][BoomInt] = GetPlayerInterior(playerid);

        BoomBoxInfo[playerid][BoomBoxPlaced] = true;
        HideAllPhoneTD(playerid);

        strcopy(BoomBoxInfo[playerid][BoomBoxOwner], AccountData[playerid][pName]);
        strcopy(BoomBoxInfo[playerid][BoomBoxLink], inputtext);

        BoomBoxInfo[playerid][BoomBoxObj] = CreateDynamicObject(2103, BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ]-0.9, 0.0, 0.0, BoomBoxInfo[playerid][BoomA], BoomBoxInfo[playerid][BoomVw], BoomBoxInfo[playerid][BoomInt], -1, 200.00, 200.00, -1);
        
        format(labels, sizeof(labels), ""WHITE"[ "Vertex"Boombox"WHITE" ]\n"YELLOW"'/takebx'",
        AccountData[playerid][pName], playerid);
        BoomBoxInfo[playerid][BoomBoxLabel] = CreateDynamic3DTextLabel(labels, 0xffffffff, BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ]+0.5, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BoomBoxInfo[playerid][BoomVw], BoomBoxInfo[playerid][BoomInt], -1, 5.0, -1, 0);
        BoomBoxInfo[playerid][BoomBoxArea] = CreateDynamicSphere(BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ], 20.0, BoomBoxInfo[playerid][BoomVw], BoomBoxInfo[playerid][BoomInt], -1);

        foreach(new i : Player)
        {
            if(IsPlayerInDynamicArea(i, BoomBoxInfo[playerid][BoomBoxArea]))
            {
                PlayAudioStreamForPlayer(i, inputtext, BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ], 20.0, 1);
            }
        }
    }
    else
    {
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ]))
            return Info(playerid, "Anda tidak dekat dengan boombox anda sendiri!");

        foreach(new i : Player)
        {
            if(strcmp(BoomBoxInfo[i][BoomBoxOwner], AccountData[playerid][pName]))
                return Info(playerid, "Boombox tersebut bukan milik anda!");
            else
            {
                if(IsPlayerInDynamicArea(i, BoomBoxInfo[playerid][BoomBoxArea]))
                {
                    strcopy(BoomBoxInfo[playerid][BoomBoxLink], inputtext);
                    PlayAudioStreamForPlayer(i, inputtext, BoomBoxInfo[playerid][BoomX], BoomBoxInfo[playerid][BoomY], BoomBoxInfo[playerid][BoomZ], 20.0, 1);
                }
            }
        }
    }
    return 1;
}
Dialog:UberRideConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return ResetUberAppTemp(playerid);
    if(isnull(inputtext)) return Dialog_Show(playerid, "UberRideConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Tidak dapat dikosongkan!\n\
    Hi, you are about to order Uber Rides. Where are you going today?", "Input", "Batal");
    
    if(strlen(inputtext) > 128) return Dialog_Show(playerid, "UberRideConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Cannot exceed 128 characters!\n\
    Hi, you are about to order Uber Rides. Where are you going today?", "Input", "Batal");

    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "UberRideConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: You cannot enter a percent symbol!\n\
    Hi, you are about to order Uber Rides. Where are you going today?", "Input", "Batal");

    strcopy(UberAppTemp[playerid][DestTemp], inputtext);
    Dialog_Show(playerid, "UberRidePassanger", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Uber App",
    "How many people are there in your group?\n\
    One\n\
    "GRAY"Two\n\
    Three", "Pilih", "Batal");
    return 1;
}
Dialog:UberRidePassanger(playerid, response, listitem, inputtext[])
{
    if(!response) return ResetUberAppTemp(playerid);
    switch(listitem)
    {
        case 0:
        {
            UberAppTemp[playerid][PassangerTemp] = 1;
        }
        case 1:
        {
            UberAppTemp[playerid][PassangerTemp] = 2;
        }
        case 2:
        {
            UberAppTemp[playerid][PassangerTemp] = 3;
        }
    }
    new hjhs[528];
    format(hjhs, sizeof(hjhs), "Okay, you want to go to %s and there are %d people in your group\n\
    Please enter the fare offer you want to provide:", UberAppTemp[playerid][DestTemp], UberAppTemp[playerid][PassangerTemp]);
    Dialog_Show(playerid, "UberRideSetPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    hjhs, "Input", "Batal");
    return 1;
}
Dialog:UberRideSetPrice(playerid, response, listitem, inputtext[])
{
    if (!response) return ResetUberAppTemp(playerid);
    
    new hjhs[528];

    if (isnull(inputtext))
    {
        format(hjhs, sizeof(hjhs), "Error: Cannot be left blank!\n\
            Okay, you want to go to %s and there are %d people in your group\n\
            Please enter the fare offer you want to provide:", UberAppTemp[playerid][DestTemp], UberAppTemp[playerid][PassangerTemp]);
        return Dialog_Show(playerid, DinarbucksWithdrawCash, DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Dinarbucks Withdraw", hjhs, "Withdraw", "Batal");
    }

    if (!IsNumericEx(inputtext))
    {
        format(hjhs, sizeof(hjhs), "Error: Can only be filled with numbers!\n\
            Okay, you want to go to %s and there are %d people in your group\n\
            Please enter the fare offer you want to provide:", UberAppTemp[playerid][DestTemp], UberAppTemp[playerid][PassangerTemp]);
        Dialog_Show(playerid, "UberRideSetPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", hjhs, "Input", "Batal");
        return 1;
    }

    if (strval(inputtext) < 1)
    {
        format(hjhs, sizeof(hjhs), "Error: Invalid fare amount!\n\
            Okay, you want to go to %s and there are %d people in your group\n\
            Please enter the fare offer you want to provide:", UberAppTemp[playerid][DestTemp], UberAppTemp[playerid][PassangerTemp]);
        Dialog_Show(playerid, "UberRideSetPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", hjhs, "Input", "Batal");
        return 1;
    }

    if (AccountData[playerid][pBankMoney] < RoundNegativeToPositive(strval(inputtext))) 
        return Error(playerid, "Jumlah tidak valid, saldo tidak cukup!");

    UberAppTemp[playerid][CostTemp] = strval(inputtext);

    if (AccountData[playerid][pBankMoney] < RoundNegativeToPositive(UberAppTemp[playerid][CostTemp])) 
        return Error(playerid, "Saldo anda tidak cukup!");

    UberAppTemp[playerid][NeedUberTimer] = gettime() + 120;
    UberAppTemp[playerid][NeedUber] = true;
    GetPlayerPos(playerid, UberAppTemp[playerid][PosTemp][0], UberAppTemp[playerid][PosTemp][1], UberAppTemp[playerid][PosTemp][2]);
    Info(playerid, "Anda berhasil membuat pesanan.");

    foreach (new i : UberDuty)
    {
        SendClientMessageEx(i, 0xc0c0c8A6, "[Uber Rides] "WHITE"Orderan masuk atas nama %s", GetPlayerRoleplayName(playerid));
        SendClientMessageEx(i, Y_WHITE, "-   [Details] No. HP: %s // Lokasi: %s - Tujuan: %s // Ongkos: $%s", PlayerPhoneData[playerid][phoneNumber], GetLocation(UberAppTemp[playerid][PosTemp][0], UberAppTemp[playerid][PosTemp][1], UberAppTemp[playerid][PosTemp][2]), UberAppTemp[playerid][DestTemp], FormatMoney(UberAppTemp[playerid][CostTemp]));
        SendClientMessageEx(i, Y_WHITE, "-   [Payment] Credits // Penumpang: %d // ID Pesanan: %d", UberAppTemp[playerid][PassangerTemp], playerid);
    }
    return 1;
}
Dialog:UberEatMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return ResetUberAppTemp(playerid);
    //if(listitem == 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat memilih ini!");
    else if(listitem == 1)
    {
        UberAppTemp[playerid][TotalQuant] = UberAppTemp[playerid][ShotDeluxeQuant];
        if(UberAppTemp[playerid][TotalQuant] == 0) return Error(playerid, "Tidak dapat melanjutkan, pesanan anda masih kosong!");

        return Dialog_Show(playerid, "UberEatConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
        "Kemana pesanan akan diantarkan (tulis catatan kepada driver)", "Input", "Batal");
    }
    UberAppTemp[playerid][UberEatTemp] = listitem;

    Dialog_Show(playerid, "UberEatValue", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Mohon masukkan jumlah yang ingin dibeli:", "Input", "Batal");
    return 1;
}

Dialog:UberEatValue(playerid, response, listitem, inputtext[])
{
    if(!response) return ResetUberAppTemp(playerid);
    if(isnull(inputtext)) return Dialog_Show(playerid, "UberEatValue", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan jumlah yang ingin dibeli:", "Input", "Batal");
    if(!IsNumericEx(inputtext)) return Dialog_Show(playerid, "UberEatValue", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Hanya angka!\n\
    Mohon masukkan jumlah yang ingin dibeli:", "Input", "Batal");

    switch(UberAppTemp[playerid][UberEatTemp])
    {
        case 0: //NasiGoreng
        {
            UberAppTemp[playerid][ShotDeluxeQuant] = strval(inputtext);
        }
    }
    //UberAppTemp[playerid][CostTemp] = (UberAppTemp[playerid][ShotDeluxeQuant] * 42325);
    UberAppTemp[playerid][TotalQuant] = UberAppTemp[playerid][ShotDeluxeQuant];

    // if(AccountData[playerid][pBankMoney] < RoundNegativeToPositive(UberAppTemp[playerid][CostTemp])) 
    // {
    //     UberAppTemp[playerid][CostTemp] = 0;
    //     UberAppTemp[playerid][TotalQuant] = 0;
    //     return ShowTDN(playerid, NOTIFICATION_ERROR, "Saldo anda tidak cukup!");
    // }

    new gofood[588];
    format(gofood, sizeof(gofood), "Name Item\tQuantity\n\
    BBQ delicy\t%dx\n\
    "GRAY"Selesaikan pesanan", UberAppTemp[playerid][ShotDeluxeQuant], UberAppTemp[playerid][TotalQuant]);
    Dialog_Show(playerid, "UberEatMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    gofood, "Pilih", "Batal");
    return 1;
}

Dialog:UberEatConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return ResetUberAppTemp(playerid);
    if(isnull(inputtext)) return Dialog_Show(playerid, "UberEatConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Tidak dapat dikosongkan!\n\
    Kemana pesanan akan diantarkan (tulis catatan kepada driver)", "Input", "Batal");
    
    if(strlen(inputtext) > 128) return Dialog_Show(playerid, "UberEatConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Maksimum 128 karakter!\n\
    Kemana pesanan akan diantarkan (tulis catatan kepada driver)", "Input", "Batal");

    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "UberRideConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
    "Error: Tidak dapat memasukkan simbol persen!\n\
    Kemana pesanan akan diantarkan (tulis catatan kepada driver)", "Input", "Batal");

    strcopy(UberAppTemp[playerid][DestTemp], inputtext);
    
    //if(AccountData[playerid][pBankMoney] < RoundNegativeToPositive(UberAppTemp[playerid][CostTemp])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Saldo anda tidak cukup!");

    UberAppTemp[playerid][NeedUberTimer] = gettime() + 120;
    UberAppTemp[playerid][NeedUber] = true;
    UberAppTemp[playerid][NeedUberEat] = true;
    GetPlayerPos(playerid, UberAppTemp[playerid][PosTemp][0], UberAppTemp[playerid][PosTemp][1], UberAppTemp[playerid][PosTemp][2]);
    Info(playerid, "Anda berhasil memesan Uber Eat");

    foreach(new i : UberDuty)
    {
        SendClientMessageEx(i, 0xc0c0c8A6, "[Uber Eats] "WHITE"Orderan masuk atas nama %s", GetPlayerRoleplayName(playerid));
        SendClientMessageEx(i, Y_WHITE, "-   [Details] No. HP: %s // Lokasi: %s", PlayerPhoneData[playerid][phoneNumber], GetLocation(UberAppTemp[playerid][PosTemp][0], UberAppTemp[playerid][PosTemp][1], UberAppTemp[playerid][PosTemp][2]));
        SendClientMessageEx(i, Y_WHITE, "-   [Notes] %s", UberAppTemp[playerid][DestTemp]);
        SendClientMessageEx(i, Y_WHITE, "-   [Pembayaran] Credits // ID Pesanan: %d", playerid);
    }
    return 1;
}
Dialog:Yellowpage(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");

    switch(listitem)
    {
        case 0:
        {
            static 
                caption_str[128],
                primary_str[1618];

            format(primary_str, sizeof(primary_str), "Pembuat\tHandphone\tAd\n");

            new counting;
            for(new x = 0; x < MAX_ADVERTISEMENT; x++) // buat aja 50
            {
                if(AdvertisementEnum[x][adSubmitted])
                {
                    strcat(primary_str, sprintf("%s\t%s\t%.24s...\n", AdvertisementEnum[x][adIssuer], AdvertisementEnum[x][adNumb], AdvertisementEnum[x][adDetail]), sizeof(primary_str));
                    PlayerListitem[playerid][counting++] = x;
                }
            }
            format(caption_str, sizeof(caption_str), "Lihat Iklan Sekarang (%d total)", GM[g_TotalAdverts]);

            if(counting > 0)
            {
                Dialog_Show(playerid, "CheckAdverts", DIALOG_STYLE_TABLIST_HEADERS, caption_str, primary_str, "Rincian", "Tutup"); // ini bebas mau langsung bisa SMS/CALL yang buat iklan atau close aja.
            }
            else
            {
                Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Advert Lists", "Tidak ada iklan dalam antrean", "Tutup", "");
            }
        }
        case 1:
        {
            Dialog_Show(playerid, "YellowpageAdd", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- YellowPage", 
            "Mohon buat kalimat untuk iklan anda:", "Buat", "Batal");
        }
    }
    return 1;
}

Dialog:YellowpageAdd(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");

    if(isnull(inputtext))
    {
        return Dialog_Show(playerid, "YellowpageAdd", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- YellowPage", 
        "Error: Iklan tidak dapat dikosongkan!\n\
        Mohon buat kalimat untuk iklan anda:", "Buat", "Batal");
    }

    if(strlen(inputtext) < 24 || strlen(inputtext) > 144)
    {
        return Dialog_Show(playerid, "YellowpageAdd", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- YellowPage", 
        "Error: Iklan anda terlalu singkat/terlalu panjang!\n\
        Iklan hanya dapat mengandung 24 - 144 karakter!\n\
        Mohon buat kalimat untuk iklan anda:", "Buat", "Batal");
    }

    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1) 
    {
        return Dialog_Show(playerid, "YellowpageAdd", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- YellowPage", 
        "Error: Iklan tidak dapat mengandung simbol persen!\n\
        Mohon buat kalimat untuk iklan anda:", "Buat", "Batal");
    }

    if(AccountData[playerid][pAdvertDelay] != 0) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Anda harus menunggu %d menit sebelum membuat iklan baru!", (AccountData[playerid][pAdvertDelay] - gettime())/60));
    
    new paid = strlen(inputtext) * 150;
    if(AccountData[playerid][pBankMoney] < paid)
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Iklan anda mengandung %d karakter, biaya $%s dan saldo tidak cukup!", strlen(inputtext), FormatMoney(paid)));

    if(GM[g_TotalAdverts] <= 14)
    {
        if(!AdvertisementEnum[GM[g_TotalAdverts]][adActive]) // masih 0
        {
            AdvertisementEnum[GM[g_TotalAdverts]][adActive] = true;
            AdvertisementEnum[GM[g_TotalAdverts]][adSubmitted] = true;
            strcopy(AdvertisementEnum[GM[g_TotalAdverts]][adNumb], PlayerPhoneData[playerid][phoneNumber]);
            strcopy(AdvertisementEnum[GM[g_TotalAdverts]][adIssuer], AccountData[playerid][pName]);
            strcopy(AdvertisementEnum[GM[g_TotalAdverts]][adDetail], inputtext);
        }
        GM[g_TotalAdverts]++; // jadi 1
        ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda membayar $%s untuk %d karakter dalam iklan!", FormatMoney(paid), strlen(inputtext)));
        AccountData[playerid][pBankMoney] -= paid;
        AccountData[playerid][pAdvertDelay] = gettime() + 900; 

        SendTeamMessage(FACTION_FOX11, 0x075ebfA6, "(Pembuatan Iklan) Uang masuk sebesar "GREEN"$%s {075ebf}dari pembuatan iklan "RED"%s", FormatMoney(paid), AccountData[playerid][pName]);
        
        Fox11MoneyVault += paid;

        new strgbg[144];
        mysql_format(g_SQL, strgbg, sizeof(strgbg), "UPDATE `stuffs` SET `fox11moneyvault`=%d WHERE `id`=0", Fox11MoneyVault);
        mysql_pquery(g_SQL, strgbg);
    }
    else
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Antrean iklan sudah penuh, mohon menunggu!");
    }
    return 1;
}
Dialog:CallGOV(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        CutCallingLine(playerid);
        return 1;
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, "CallGOV", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- SAGOV Service", 
    "Error: Cannot be left blank!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");
    
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "CallGOV", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- SAGOV Service", 
    "Error: You cannot enter a percent symbol!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");

    if(gettime() < AccountData[playerid][pPemdaHotline]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon tunggu beberapa saat sebelum menggunakannya kembali!");

    AccountData[playerid][pPemdaHotline] = gettime()+60;

    static Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    SendTeamMessage(FACTION_SAGOV, -1, "HOTLINE | %s [Ph: %s] | %s", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber], GetLocation(px, py, pz));
    SendTeamMessage(FACTION_SAGOV, -1, "~> %s", inputtext);

    ShowTDN(playerid, NOTIFICATION_INFO, "Pesan yang anda kirim telah berhasil disampaikan!");

    CutCallingLine(playerid);
    return 1;
}
Dialog:CallBennys(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        CutCallingLine(playerid);
        return 1;
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, "CallBennys", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Bennys Automotive", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");
    
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "CallBennys", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Bennys Automotive", 
    "Error: Anda tidak dapat memasukkan simbol persen!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");

    if(gettime() < AccountData[playerid][pMekHotline]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harap tunggu beberapa saat sebelum menggunakannya kembali!");

    AccountData[playerid][pMekHotline] = gettime()+60;

    static Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    SendTeamMessage(FACTION_BENNYS, -1, "HOTLINE | %s [Ph: %s] | %s", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber], GetLocation(px, py, pz));
    SendTeamMessage(FACTION_BENNYS, -1, "~> %s", inputtext);

    ShowTDN(playerid, NOTIFICATION_INFO, "Pesan yang anda kirim telah berhasil disampaikan!");

    CutCallingLine(playerid);
    return 1;
}
Dialog:CallPringSewu(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        CutCallingLine(playerid);
        return 1;
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, "CallPringSewu", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Pring Sewu Order", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");
    
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "CallPringSewu", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Pring Sewu Order", 
    "Error: Anda tidak dapat memasukkan simbol persen!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");

    if(gettime() < AccountData[playerid][pPdgHotline]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harap tunggu beberapa saat sebelum menggunakannya kembali!");

    AccountData[playerid][pPdgHotline] = gettime()+60;

    static Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    SendTeamMessage(FACTION_PRINGSEWU, -1, "HOTLINE | %s [Ph: %s] | %s", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber], GetLocation(px, py, pz));
    SendTeamMessage(FACTION_PRINGSEWU, -1, "~> %s", inputtext);

    ShowTDN(playerid, NOTIFICATION_INFO, "Pesan yang anda kirim telah berhasil disampaikan!");

    CutCallingLine(playerid);
    return 1;
}
Dialog:CallDinarbucks(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        CutCallingLine(playerid);
        return 1;
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, "CallDinarbucks", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Dinarbucks Online", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");
    
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "CallDinarbucks", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Dinarbucks Online", 
    "Error: Anda tidak dapat memasukkan simbol persen!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");

    if(gettime() < AccountData[playerid][pDinarHotline]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harap tunggu beberapa saat sebelum menggunakannya kembali!");

    AccountData[playerid][pDinarHotline] = gettime()+60;

    static Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    SendTeamMessage(FACTION_DINARBUCKS, -1, "HOTLINE | %s [Ph: %s] | %s", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber], GetLocation(px, py, pz));
    SendTeamMessage(FACTION_DINARBUCKS, -1, "~> %s", inputtext);

    ShowTDN(playerid, NOTIFICATION_INFO, "Pesan yang anda kirim telah berhasil disampaikan!");

    CutCallingLine(playerid);
    return 1;
}
Dialog:CallDriftKing(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        CutCallingLine(playerid);
        return 1;
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, "CallDriftKing", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- DriftKing Automotive", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");
    
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "CallDriftKing", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- DriftKing Automotive", 
    "Error: Anda tidak dapat memasukkan simbol persen!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");

    if(gettime() < AccountData[playerid][pMekHotline]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harap tunggu beberapa saat sebelum menggunakannya kembali!");

    AccountData[playerid][pMekHotline] = gettime()+60;

    static Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    SendTeamMessage(FACTION_DRIFTKING, -1, "HOTLINE | %s [Ph: %s] | %s", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber], GetLocation(px, py, pz));
    SendTeamMessage(FACTION_DRIFTKING, -1, "~> %s", inputtext);

    ShowTDN(playerid, NOTIFICATION_INFO, "Pesan yang anda kirim telah berhasil disampaikan!");

    CutCallingLine(playerid);
    return 1;
}
Dialog:CallJayaAbadi(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        CutCallingLine(playerid);
        return 1;
    }

    if(isnull(inputtext)) return Dialog_Show(playerid, "CallJayaAbadi", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Jaya Abadi", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");
    
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return Dialog_Show(playerid, "CallJayaAbadi", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Jaya Abadi", 
    "Error: Anda tidak dapat memasukkan simbol persen!\n\
    Mohon masukkan pesan yang ingin anda sampaikan:", "Input", "Batal");

    if(gettime() < AccountData[playerid][pMekHotline]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harap tunggu beberapa saat sebelum menggunakannya kembali!");

    AccountData[playerid][pMekHotline] = gettime()+60;

    static Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);
    SendTeamMessage(FACTION_JAYAABADI, -1, "HOTLINE | %s [Ph: %s] | %s", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber], GetLocation(px, py, pz));
    SendTeamMessage(FACTION_JAYAABADI, -1, "~> %s", inputtext);

    ShowTDN(playerid, NOTIFICATION_INFO, "Pesan yang anda kirim telah berhasil disampaikan!");

    CutCallingLine(playerid);
    return 1;
}
Dialog:PhoneCallList(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");
    
    switch(listitem)
    {
        case 0: //emergency
        {
            OnOutcomingCall(playerid, "911");

            Dialog_Show(playerid, "EmergencyChoose", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- 911 Emergency Hotline", 
            "Dispatcher: 911, What service do you need?\nKepolisian Vertex\nParamedis Vertex", "Pilih", "Batal");
        }
        case 1: //gov
        {
            OnOutcomingCall(playerid, "111");

            Dialog_Show(playerid, "CallGOV", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Layanan Pemerintah", 
            "Dispatcher: Halo, ada yang bisa kami bantu?", "Input", "Batal");
        }
        case 2: //benys
        {
            OnOutcomingCall(playerid, "112");

            Dialog_Show(playerid, "CallBennys", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Bennys Automotive", 
            "Dispatcher: Halo, ada yang bisa kami bantu?", "Input", "Batal");
        }
        case 3: //Pring Sewu
        {
            OnOutcomingCall(playerid, "222");

            Dialog_Show(playerid, "CallPringSewu", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Pring Sewu Order", 
            "Dispatcher: Halo, ada yang bisa kami bantu?", "Input", "Batal");
        }
        case 4: //dinarbucks
        {
            OnOutcomingCall(playerid, "444");

            Dialog_Show(playerid, "CallDinarbucks", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Dinarbucks Online", 
            "Dispatcher: Halo, ada yang bisa kami bantu?", "Input", "Batal");
        }
        case 5: //driftking
        {
            OnOutcomingCall(playerid, "113");

            Dialog_Show(playerid, "CallDriftKing", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- DriftKing Workshop", 
            "Dispatcher: Halo, ada yang bisa kami bantu?", "Input", "Batal");
        }
        case 6: //jaya abadi
        {
            OnOutcomingCall(playerid, "114");

            Dialog_Show(playerid, "CallJayaAbadi", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Jaya Abadi", 
            "Dispatcher: Halo, ada yang bisa kami bantu?", "Input", "Batal");
        }
        case 7: //cust number
        {
            Dialog_Show(playerid, "CallCustomNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Call", 
            "Mohon masukkan nomor HP tujuan:", "Input", "Batal");
        }
    }
    return 1;
}
Dialog:CallCustomNumber(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(isnull(inputtext)) return Dialog_Show(playerid, "CallCustomNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Call", 
    "Error: Tidak dapat dikosongkan!\n\
    Mohon masukkan nomor HP tujuan:", "Input", "Batal");
    if(!IsNumericEx(inputtext)) return Dialog_Show(playerid, "CallCustomNumber", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Call", 
    "Error: Masukkan hanya angka!\n\
    Mohon masukkan nomor HP tujuan:", "Input", "Batal");
    
    strcopy(PlayerPhoneData[playerid][phoneTempNumber], inputtext);
    HidePhoneMainMenuTD(playerid);
    OnOutcomingCall(playerid, PlayerPhoneData[playerid][phoneTempNumber]);
    return 1;
}
Dialog:GPSMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");

    switch(listitem)
    {
        case 0: //lokasi umum
        {
            static minstry[3555];
            format(minstry, sizeof(minstry), "Name\tLocation\tDistance\n");
            for(new x; x < sizeof(_g_GPS_Public); x++)
            {
                if (x % 2 == 0) {
                    strcat(minstry, sprintf(""WHITE"%s\t"WHITE"%s\t"YELLOW"%.0f m\n", _g_GPS_Public[x][JobName], GetLocation(_g_GPS_Public[x][Pos][0],_g_GPS_Public[x][Pos][1],_g_GPS_Public[x][Pos][2]), GetPlayerDistanceFromPoint(playerid, _g_GPS_Public[x][Pos][0],_g_GPS_Public[x][Pos][1],_g_GPS_Public[x][Pos][2])), sizeof(minstry));
                } else {
                    strcat(minstry, sprintf(""GRAY"%s\t"GRAY"%s\t"YELLOW"%.0f m\n", _g_GPS_Public[x][JobName], GetLocation(_g_GPS_Public[x][Pos][0],_g_GPS_Public[x][Pos][1],_g_GPS_Public[x][Pos][2]), GetPlayerDistanceFromPoint(playerid, _g_GPS_Public[x][Pos][0],_g_GPS_Public[x][Pos][1],_g_GPS_Public[x][Pos][2])), sizeof(minstry));
                }
            }
            Dialog_Show(playerid, "GPSPublic", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- GPS", minstry, "Pilih", "Kembali");
        }
        case 1: //lokasi pekerjaan
        {
            static minstry[3555];
            format(minstry, sizeof(minstry), "Job\tDescription\tLocation\tDistance\n");
            for(new x; x < sizeof(_g_GPS_Job); x++)
            {
                new Float:posX = _g_GPS_Job[x][Pos][0];
                new Float:posY = _g_GPS_Job[x][Pos][1];
                new Float:posZ = _g_GPS_Job[x][Pos][2];
                new jobName[64], jobDesc[64];
                format(jobName, 64, "%s", _g_GPS_Job[x][JobName]);
                format(jobDesc, 64, "%s", _g_GPS_Job[x][Name]);

                if(strcmp(_g_GPS_Job[x][JobName], "Tukang Sawit #1") == 0)
                {
                    if(!Iter_Contains(Sawits, 0))
                    {
                        if(x % 2 == 0)
                            strcat(minstry, sprintf(""WHITE"%s\t"WHITE"%s\t"RED"Belum tersedia\t"YELLOW"-\n", jobName, jobDesc), sizeof(minstry));
                        else
                            strcat(minstry, sprintf(""GRAY"%s\t"GRAY"%s\t"RED"Belum tersedia\t"YELLOW"-\n", jobName, jobDesc), sizeof(minstry));
                        continue;
                    }
                    posX = SawitData[0][sawPos][0];
                    posY = SawitData[0][sawPos][1];
                    posZ = SawitData[0][sawPos][2];
                }

                if(x % 2 == 0)
                    strcat(minstry, sprintf(""WHITE"%s\t"WHITE"%s\t"WHITE"%s\t"YELLOW"%.0f m\n", jobName, jobDesc, GetLocation(posX, posY, posZ), GetPlayerDistanceFromPoint(playerid, posX, posY, posZ)), sizeof(minstry));
                else
                    strcat(minstry, sprintf(""GRAY"%s\t"GRAY"%s\t"GRAY"%s\t"YELLOW"%.0f m\n", jobName, jobDesc, GetLocation(posX, posY, posZ), GetPlayerDistanceFromPoint(playerid, posX, posY, posZ)), sizeof(minstry));
            }
            Dialog_Show(playerid, "GPSJob", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- GPS", minstry, "Pilih", "Kembali");
        }
        case 2: //hobi
        {
            static minstry[555];
            format(minstry, sizeof(minstry), "Hobi\tNama\tLokasi\tJarak\n\
            Mancing\tSpot Mancing\t%s\t"YELLOW"%.0f m\n\
            "GRAY"Mancing\t"GRAY"Penjualan Ikan\t%s\t"YELLOW"%.0f m\n\
            Berburu\tZona Berburu\t%s\t"YELLOW"%.0f m\n\
            "GRAY"Berburu\t"GRAY"Penjualan Hasil Berburu\t%s\t"YELLOW"%.0f m",
            GetLocation(369.8166,-2042.0115,7.6719), GetPlayerDistanceFromPoint(playerid, 369.8166,-2042.0115,7.6719),
            GetLocation(-2057.6643,-2464.8784,31.1797), GetPlayerDistanceFromPoint(playerid, -2057.6643,-2464.8784,31.1797),
            GetLocation(-544.7436,-2314.0288,29.1985), GetPlayerDistanceFromPoint(playerid, -544.7436,-2314.0288,29.1985),
            GetLocation(2780.2712,-2535.2139,13.6950), GetPlayerDistanceFromPoint(playerid, 2780.2712,-2535.2139,13.6950));
            Dialog_Show(playerid, "GPSHobby", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- GPS", minstry, "Pilih", "Kembali");
        }
        case 3: //lokasi restorant
        {
            static minstry[3555];
            format(minstry, sizeof(minstry), "Name\tLocation\tDistance\n");
            for(new x; x < sizeof(_g_GPS_Resto); x++)
            {
                if (x % 2 == 0) {
                    strcat(minstry, sprintf(""WHITE"%s\t"WHITE"%s\t"YELLOW"%.0f m\n", _g_GPS_Resto[x][JobName], GetLocation(_g_GPS_Resto[x][Pos][0],_g_GPS_Resto[x][Pos][1],_g_GPS_Resto[x][Pos][2]), GetPlayerDistanceFromPoint(playerid, _g_GPS_Resto[x][Pos][0],_g_GPS_Resto[x][Pos][1],_g_GPS_Resto[x][Pos][2])), sizeof(minstry));
                } else {
                    strcat(minstry, sprintf(""GRAY"%s\t"GRAY"%s\t"YELLOW"%.0f m\n", _g_GPS_Resto[x][JobName], GetLocation(_g_GPS_Resto[x][Pos][0],_g_GPS_Resto[x][Pos][1],_g_GPS_Resto[x][Pos][2]), GetPlayerDistanceFromPoint(playerid, _g_GPS_Resto[x][Pos][0],_g_GPS_Resto[x][Pos][1],_g_GPS_Resto[x][Pos][2])), sizeof(minstry));
                }
            }
            Dialog_Show(playerid, "GPSResto", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- GPS", minstry, "Pilih", "Kembali");
        }
        case 4:
        {
            static minstry[3555];
            format(minstry, sizeof(minstry), "Name\tLocation\tDistance\n");
            for(new x; x < sizeof(_g_GPS_Bengkel); x++)
            {
                if (x % 2 == 0) {
                    strcat(minstry, sprintf(""WHITE"%s\t"WHITE"%s\t"YELLOW"%.0f m\n", _g_GPS_Bengkel[x][JobName], GetLocation(_g_GPS_Bengkel[x][Pos][0],_g_GPS_Bengkel[x][Pos][1],_g_GPS_Bengkel[x][Pos][2]), GetPlayerDistanceFromPoint(playerid, _g_GPS_Bengkel[x][Pos][0],_g_GPS_Bengkel[x][Pos][1],_g_GPS_Bengkel[x][Pos][2])), sizeof(minstry));
                } else {
                    strcat(minstry, sprintf(""GRAY"%s\t"GRAY"%s\t"YELLOW"%.0f m\n", _g_GPS_Bengkel[x][JobName], GetLocation(_g_GPS_Bengkel[x][Pos][0],_g_GPS_Bengkel[x][Pos][1],_g_GPS_Bengkel[x][Pos][2]), GetPlayerDistanceFromPoint(playerid, _g_GPS_Bengkel[x][Pos][0],_g_GPS_Bengkel[x][Pos][1],_g_GPS_Bengkel[x][Pos][2])), sizeof(minstry));
                }
            }
            Dialog_Show(playerid, "GPSBengkel", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- GPS", minstry, "Pilih", "Kembali");
        }
        case 5: //Business Kota
        {
            ShowAllBizListGPS(playerid);
        }
        case 6: //ATM Kota
        {
            ShowAllAtmListGPS(playerid);
        }
        case 7: //SPBU Kota
        {
            ShowAllGasListGPS(playerid);
        }
        case 8: //Garasi Kota
        {
            ShowAllGarageListGPS(playerid);
        }
        case 9: //House Tersedia
        {
            ShowAllAvailableHousesGPS(playerid);
        }
        case 10: //reset checkpoint
        {
            if(!AccountData[playerid][pUsingGPS] && !IsValidDynamicRaceCP(AccountData[playerid][pGPSCP])) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada checkpoint GPS yang aktif!");

            ResetAllRaceCP(playerid);
            
            if(DestroyDynamicMapIcon(AccountData[playerid][pSignalIcon]))
                AccountData[playerid][pSignalIcon] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;

            AccountData[playerid][pUsingGPS] = false;
            ShowTDN(playerid, NOTIFICATION_INFO, "Checkpoint telah dihapuskan.");
        }
        case 11: //reset shareloc
        {
            if(DestroyDynamicMapIcon(AccountData[playerid][pSharedGPSIcon]))
                AccountData[playerid][pSharedGPSIcon] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;
            ShowTDN(playerid, NOTIFICATION_INFO, "Tanda shareloc telah dihapuskan.");
        }
    }
    return 1;
}

Dialog:GPSResto(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Lokasi Restorant\n\
        Lokasi Bengkel\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
        return 1;
    }
    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

    if(listitem < 0 || listitem > sizeof(_g_GPS_Resto))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "It seems like you haven't made a choice yet!");

    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;
    
    AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, _g_GPS_Resto[listitem][Pos][0],_g_GPS_Resto[listitem][Pos][1],_g_GPS_Resto[listitem][Pos][2], _g_GPS_Resto[listitem][Pos][0],_g_GPS_Resto[listitem][Pos][1],_g_GPS_Resto[listitem][Pos][2], 3.5, 0, 0, playerid, 10000.00, -1, 0);
    ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
    return 1;
}

Dialog:GPSBengkel(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Lokasi Restorant\n\
        Lokasi Bengkel\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
        return 1;
    }
    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

    if(listitem < 0 || listitem > sizeof(_g_GPS_Bengkel))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "It seems like you haven't made a choice yet!");

    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;
    
    AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, _g_GPS_Bengkel[listitem][Pos][0],_g_GPS_Bengkel[listitem][Pos][1],_g_GPS_Bengkel[listitem][Pos][2], _g_GPS_Bengkel[listitem][Pos][0],_g_GPS_Bengkel[listitem][Pos][1],_g_GPS_Bengkel[listitem][Pos][2], 3.5, 0, 0, playerid, 10000.00, -1, 0);
    ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
    return 1;
}

Dialog:GPSPublic(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Lokasi Restorant\n\
        Lokasi Bengkel\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
        return 1;
    }

    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

    if(listitem < 0 || listitem > sizeof(_g_GPS_Public))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "It seems like you haven't made a choice yet!");

    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;
    
    AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, _g_GPS_Public[listitem][Pos][0],_g_GPS_Public[listitem][Pos][1],_g_GPS_Public[listitem][Pos][2], _g_GPS_Public[listitem][Pos][0],_g_GPS_Public[listitem][Pos][1],_g_GPS_Public[listitem][Pos][2], 3.5, 0, 0, playerid, 10000.00, -1, 0);
    ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
    return 1;
}
Dialog:GPSJob(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Lokasi Restorant\n\
        Lokasi Bengkel\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
        return 1;
    }

    if(listitem < 0 || listitem >= sizeof(_g_GPS_Job))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "It seems like you haven't made a choice yet!"), 1;

    new Float:posX, Float:posY, Float:posZ;
    if(strcmp(_g_GPS_Job[listitem][JobName], "Tukang Sawit #1") == 0)
    {
        if(!Iter_Contains(Sawits, 0))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Pohon sawit saat ini belum ditambahkan oleh admin!"), 1;

        posX = SawitData[0][sawPos][0];
        posY = SawitData[0][sawPos][1];
        posZ = SawitData[0][sawPos][2];
        AccountData[playerid][pUsingGPS] = true;
    }
    else
    {
        posX = _g_GPS_Job[listitem][Pos][0];
        posY = _g_GPS_Job[listitem][Pos][1];
        posZ = _g_GPS_Job[listitem][Pos][2];
    }

    AccountData[playerid][pUsingGPS] = true;
    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

    AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, posX, posY, posZ, posX, posY, posZ, 3.5, 0, 0, playerid, 10000.00, -1, 0);
    ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
    return 1;
}
Dialog:GPSHobby(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Lokasi Restorant\n\
        Lokasi Bengkel\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
        return 1;
    }

    AccountData[playerid][pUsingGPS] = true;

    if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
        AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

    switch(listitem)
    {
        case 0:
        {
            AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, 369.8166,-2042.0115,7.6719, 369.8166,-2042.0115,7.6719, 3.5, 0, 0, playerid, 10000.00, -1, 0);
            ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
        }
        case 1:
        {
            AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, -2057.6643,-2464.8784,31.1797, -2057.6643,-2464.8784,31.1797, 3.5, 0, 0, playerid, 10000.00, -1, 0);
            ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
        }
        case 2:
        {
            AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, -544.7436,-2314.0288,29.1985, -544.7436,-2314.0288,29.1985, 3.5, 0, 0, playerid, 10000.00, -1, 0);
            ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
        }
        case 3:
        {
            AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, 2780.2712,-2535.2139,13.6950, 2780.2712,-2535.2139,13.6950, 3.5, 0, 0, playerid, 10000.00, -1, 0);
            ShowTDN(playerid, NOTIFICATION_WARNING, "Mohon ikuti checkpoint di map!");
        }
    }
    return 1;
}

hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(playertextid == PhoneVRP[playerid][15]) //close phone
    {
        HideAllPhoneTD(playerid);
        if(!IsPlayerInAnyVehicle(playerid))
        {
            ShowWargaBaruTD(playerid);
            RemovePlayerAttachedObject(playerid, 9);
            StopLoopingAnim(playerid);
        }
		PlayerPhoneData[playerid][phoneShown] = false;
        CancelSelectTextDraw(playerid);

		SendRPMeAboveHead(playerid, "Menutup smartphone miliknya.");
    }
    else if (playertextid == PhoneVRP[playerid][20]) // twitter
    {
        HidePhoneMainMenuTD(playerid);

        if(PlayerPhoneData[playerid][IsTwitterLoggedIn] < 1)
        {
            ShowTwitterLoginTD(playerid);
        }
        else
        {
            new sqlfstr[128];
            mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "SELECT * FROM `player_twitter` WHERE `ID`=%d", PlayerPhoneData[playerid][IsTwitterLoggedIn]);
            mysql_query(g_SQL, sqlfstr);
            new rows = cache_num_rows();
            if(rows)
            {
                cache_get_value_name(0, "Username", TwitterData[playerid][Username]);
                // PlayerTextDrawSetString(playerid, TwitterInfoTD[playerid], sprintf("Hai, %s bagaimana harimu?", TwitterData[playerid][Username]));
                ShowTwitterMainTD(playerid);
            }
        }
    }
    else if(playertextid == PhoneVRP[playerid][21]) //yellow page
    {
        Dialog_Show(playerid, "Yellowpage", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Yellow Page", "View advertisement queues\nSubmit a new advertisement", "Pilih", "Batal");
    }
    else if(playertextid == PhoneVRP[playerid][22]) //GPS
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Lokasi Restorant\n\
        Lokasi Bengkel\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
    }
    else if(playertextid == PhoneVRP[playerid][23]) //vehiclelist
    {
        HidePhoneMainMenuTD(playerid);
        VehiclePage[playerid] = 0;
        SyncVehiclePage(playerid);
        UpdatePageDisplay(playerid);
    }
    else if(playertextid == PhoneVRP[playerid][24]) //spotify
    {
        HidePhoneMainMenuTD(playerid);
        SelectMusicTD[playerid] = -1;
        ShowSpotifyTD(playerid);
    }
    else if(playertextid == PhoneVRP[playerid][25]) //trans / ubber
    {
        HidePhoneMainMenuTD(playerid);
        SelectUberTD[playerid] = -1;
        ShowUberPhoneTD(playerid);
    }
    else if(playertextid == PhoneVRP[playerid][26]) //kalkulator
    {
        HidePhoneMainMenuTD(playerid);
        KalkulatorOpen[playerid] = true;
        ShowKalkulatorTD(playerid, true);
    }
    else if(playertextid == PhoneVRP[playerid][27]) //sotot vip
    {
        ShowTDN(playerid, NOTIFICATION_INFO, "Waiting to process....");
    }
    else if(playertextid == PhoneVRP[playerid][70]) //mbanking
    {
        HidePhoneMainMenuTD(playerid);
        ShowPhoneBankingTD(playerid);
    }
    else if(playertextid == PhoneVRP[playerid][31]) //call
    {
        Dialog_Show(playerid, "PhoneCallList", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Call", 
        "Emergency Service\n\
        SAGov Public Service\n\
        Bennys Automotive Service\n\
        Pring Sewu Beach Club Service\n\
        Loving Donuts Service\n\
        DriftKing Workshop Service\n\
        Jaya Abadi Service\n\
        "GRAY"> Call another number", "Pilih", "Batal");
    }
    else if(playertextid == PhoneVRP[playerid][32])
    {
        HidePhoneMainMenuTD(playerid);
        OpenCameraMode(playerid);
    }
    else if(playertextid == PhoneVRP[playerid][33]) //contact
    {
        HidePhoneMainMenuTD(playerid);
        index_contact[playerid] = 0;
        ShowPhoneContactTD(playerid);
    }
    else if(playertextid == PhoneVRP[playerid][34]) //SMS
    {
        index_contact[playerid] = 0;
        ShowContactListV1(playerid);
    }
    //----- Aplikasi Bank -------
    else if(playertextid == PhoneBankVRP[playerid][15]) //close apk
    {
        HidePhoneBankingTD(playerid);
        ShowPhoneVRP(playerid);
    }
    else if(playertextid == PhoneBankVRP[playerid][53]) //transfer 
    {
        Dialog_Show(playerid, "ATMTransfer", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Transfer", 
        "Mohon masukkan nomor rekening tujuan:", "Set", "Batal");
    }
    //-------- Music --------- //
    else if(playertextid == MusicVRP[playerid][42]) //boombox
    {
        SelectMusicTD[playerid] = 0; //boombox color terang
        for(new i = 30; i < 36; i++)
        {
            PlayerTextDrawColor(playerid, MusicVRP[playerid][i], 498685183);
            PlayerTextDrawHide(playerid, MusicVRP[playerid][i]);
            PlayerTextDrawShow(playerid, MusicVRP[playerid][i]);
        }
        PlayerTextDrawColor(playerid, MusicVRP[playerid][46], -923739905);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][64], 498685183);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][66], 498685183);

        PlayerTextDrawHide(playerid, MusicVRP[playerid][64]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][66]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][46]);

        PlayerTextDrawShow(playerid, MusicVRP[playerid][46]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][64]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][66]);

        for(new i = 68; i < 74; i++) //earphone color redup
        {
            PlayerTextDrawColor(playerid, MusicVRP[playerid][i], 254613759);
            PlayerTextDrawHide(playerid, MusicVRP[playerid][i]);
            PlayerTextDrawShow(playerid, MusicVRP[playerid][i]);
        }
        PlayerTextDrawColor(playerid, MusicVRP[playerid][83], 1521318655);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][101], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][103], 254613759);

        PlayerTextDrawHide(playerid, MusicVRP[playerid][83]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][101]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][103]);

        PlayerTextDrawShow(playerid, MusicVRP[playerid][83]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][101]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][103]);
    }
    else if(playertextid == MusicVRP[playerid][80]) //Earphone
    {
        SelectMusicTD[playerid] = 1; //Earphone

        for(new i = 30; i < 36; i++) //boombox color redup
        {
            PlayerTextDrawColor(playerid, MusicVRP[playerid][i], 254613759);
            PlayerTextDrawHide(playerid, MusicVRP[playerid][i]);
            PlayerTextDrawShow(playerid, MusicVRP[playerid][i]);
        }
        PlayerTextDrawColor(playerid, MusicVRP[playerid][64], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][66], 254613759);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][46], 1521318655);

        PlayerTextDrawHide(playerid, MusicVRP[playerid][64]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][66]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][46]);

        PlayerTextDrawShow(playerid, MusicVRP[playerid][46]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][64]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][66]);

        for(new i = 68; i < 74; i++) //earphone color terang
        {
            PlayerTextDrawColor(playerid, MusicVRP[playerid][i], 498685183);
            PlayerTextDrawHide(playerid, MusicVRP[playerid][i]);
            PlayerTextDrawShow(playerid, MusicVRP[playerid][i]);
        }
        PlayerTextDrawColor(playerid, MusicVRP[playerid][101], 498685183);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][103], 498685183);
        PlayerTextDrawColor(playerid, MusicVRP[playerid][83], -923739905);

        PlayerTextDrawHide(playerid, MusicVRP[playerid][83]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][101]);
        PlayerTextDrawHide(playerid, MusicVRP[playerid][103]);

        PlayerTextDrawShow(playerid, MusicVRP[playerid][83]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][101]);
        PlayerTextDrawShow(playerid, MusicVRP[playerid][103]);
    }
    else if(playertextid == MusicVRP[playerid][105]) //pilih
    {
        if(SelectMusicTD[playerid] == -1)
            return Error(playerid, "Anda belom memilih apapun");
        
        switch(SelectMusicTD[playerid])
        {
            case 0:
            {
                if(!AccountData[playerid][pBoombox]) return Info(playerid, "Anda tidak memiliki Boombox!");
                if(AccountData[playerid][pVIP] < 1) return Info(playerid, "Anda bukan Donatur VIP!");
                
                Dialog_Show(playerid, "SpotifyBoombox", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Spotify", 
                "Masukkan URL/link MP3 yang ingin diputar\n\
                Kami sarankan anda untuk upload file mp3 ke discord terlebih dahulu.\n\
                "RED"Note: Fitur ini tidak support link YouTube secara langsung!\n\n\
                "YELLOW"(Apabila file mp3 telah di upload ke discord, silakan copy linknya dan paste di bawah ini):", "Pilih", "Batal");
            }
            case 1:
            {
                if(!AccountData[playerid][pEarphone]) return Info(playerid, "Anda tidak memiliki Earphone!");

                Dialog_Show(playerid, "SpotifyEarphone", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Spotify", 
                "Masukkan URL/link MP3 yang ingin diputar\n\
                Kami sarankan anda untuk upload file mp3 ke discord terlebih dahulu.\n\
                "RED"Note: Fitur ini tidak support link YouTube secara langsung!\n\n\
                "YELLOW"(Apabila file mp3 telah di upload ke discord, silakan copy linknya dan paste di bawah ini):", "Pilih", "Batal");
            }
        }
    }
    else if(playertextid == MusicVRP[playerid][15]) //close
    {
        HideSpotifyTD(playerid);
        ShowPhoneVRP(playerid);
    }
    //-------- Uber --------//
    else if(playertextid == UberVRP[playerid][39]) //go car
    {
        SelectUberTD[playerid] = 0; // gocar
        PlayerTextDrawColor(playerid, UberVRP[playerid][50], 11164671);
        PlayerTextDrawHide(playerid, UberVRP[playerid][50]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][50]);

        PlayerTextDrawColor(playerid, UberVRP[playerid][52], 11164671);
        PlayerTextDrawHide(playerid, UberVRP[playerid][52]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][52]);

        PlayerTextDrawShow(playerid, UberVRP[playerid][79]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][81]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][82]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][83]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][84]);

        PlayerTextDrawColor(playerid, UberVRP[playerid][76], -2004317953);
        PlayerTextDrawHide(playerid, UberVRP[playerid][76]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][76]);
        PlayerTextDrawColor(playerid, UberVRP[playerid][78], -2004317953);
        PlayerTextDrawHide(playerid, UberVRP[playerid][78]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][78]);

        PlayerTextDrawHide(playerid, UberVRP[playerid][80]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][85]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][86]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][87]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][88]);

    }
    else if(playertextid == UberVRP[playerid][65]) //go ride
    {
        SelectUberTD[playerid] = 1; // goride
        PlayerTextDrawColor(playerid, UberVRP[playerid][76], 11164671);
        PlayerTextDrawHide(playerid, UberVRP[playerid][76]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][76]);
        PlayerTextDrawColor(playerid, UberVRP[playerid][78], 11164671);
        PlayerTextDrawHide(playerid, UberVRP[playerid][78]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][78]);

        PlayerTextDrawShow(playerid, UberVRP[playerid][80]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][85]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][86]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][87]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][88]);

        PlayerTextDrawColor(playerid, UberVRP[playerid][50], -2004317953);
        PlayerTextDrawHide(playerid, UberVRP[playerid][50]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][50]);
        PlayerTextDrawColor(playerid, UberVRP[playerid][52], -2004317953);
        PlayerTextDrawHide(playerid, UberVRP[playerid][52]);
        PlayerTextDrawShow(playerid, UberVRP[playerid][52]);

        PlayerTextDrawHide(playerid, UberVRP[playerid][79]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][81]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][82]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][83]);
        PlayerTextDrawHide(playerid, UberVRP[playerid][84]);
    }
    else if(playertextid == UberVRP[playerid][91]) //pesan
    {
        if(SelectUberTD[playerid] == -1)
            return Error(playerid, "Anda belom memilih apapun!");
        
        switch(SelectUberTD[playerid])
        {
            case 0:
            {
                if(gettime() < UberAppTemp[playerid][NeedUberTimer]) return Error(playerid, "Anda telah memesan uber, mohon tunggu %d detik!", UberAppTemp[playerid][NeedUberTimer] - gettime());
                if(UberAppTemp[playerid][ServiceAcceptedBy] != INVALID_PLAYER_ID) return Error(playerid, "Driver sedang menuju ke titik anda, tetaplah berada di sana!");
                ResetUberAppTemp(playerid);
                Dialog_Show(playerid, "UberRideConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
                "Hi, you are going to book an Uber Ride. Where are you headed today?", "Input", "Batal");
            }
            case 1:
            {
                if(gettime() < UberAppTemp[playerid][NeedUberTimer]) return Error(playerid, "Anda telah memesan uber, mohon tunggu %d detik!", UberAppTemp[playerid][NeedUberTimer] - gettime());
                if(UberAppTemp[playerid][ServiceAcceptedBy] != INVALID_PLAYER_ID) return Error(playerid, "Driver sedang menuju ke titik anda, tetaplah berada di sana!");
                ResetUberAppTemp(playerid);
                new gofood[588];
                format(gofood, sizeof(gofood), "Nama Item\tKeranjang\n\
                BBQ delicy\t%dx\n\
                "GRAY"Selesaikan pesanan", UberAppTemp[playerid][ShotDeluxeQuant], UberAppTemp[playerid][TotalQuant]);
                Dialog_Show(playerid, "UberEatMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
                gofood, "Pilih", "Batal");
            }
        }
    }
    else if(playertextid == UberVRP[playerid][15]) // close
    {
        HideUberPhoneTD(playerid);
        ShowPhoneVRP(playerid);
    }
    return 1;
}
/*
hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(playertextid == KontakButtonPhone)
    {
        HidePhoneMainMenuTD(playerid);
        ShowPhoneContactTD(playerid);
    }
    else if(playertextid == ContactTD[1]) //tambak kontak baru
    {
        Dialog_Show(playerid, "ContactAddName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", 
        "Please insert the contact name that will be saved below:", "Input", "Kembali");
    }
    else if(playertextid == ContactTD[3]) //daftar kontak
    {
        index_contact[playerid] = 0;
        ShowContactList(playerid);
    }
    else if(playertextid == GPSButtonPhone) //GPS
    {
        Dialog_Show(playerid, "GPSMenu", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- GPS", 
        "Lokasi Umum\n\
        "GRAY"Lokasi Kerja\n\
        Lokasi Hobi\n\
        "GRAY"Business Locations\n\
        ATM Locations\n\
        "GRAY"SPBU Locations\n\
        Garasi Locations\n\
        House Tersedia\n\
        "RED"(Hapus Checkpoint GPS)\n\
        "RED"(Hapus Checkpoint Shareloc)", "Pilih", "Batal");
    }
    else if(playertextid == AirdropButtonPhone)
    {
        new frmxt[522], count = 0;

		foreach(new i : Player) if(i != playerid) if(IsPlayerNearPlayer(playerid, i, 1.5)) 
		{
			if (i % 2 == 0) {
                strcat(frmxt, sprintf(""WHITE"Player ID - (%d)\n", i), sizeof(frmxt));
            }
            else {
                strcat(frmxt, sprintf(""GRAY"Player ID - (%d)\n", i), sizeof(frmxt));
            }
			NearestUser[playerid][count++] = i;
		}

		if(count == 0) 
		{
			PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
			return Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Airdrop", "Tidak ada pemain terdekat!", "Tutup", "");
		}

		Dialog_Show(playerid, "PhoneAirdrop", DIALOG_STYLE_TABLIST, ""Vertex"Vertex Roleplay "WHITE"- Airdrop", frmxt, "Pilih", "Batal");
    }
    else if(playertextid == BankingButtonPhone)
    {
        HidePhoneMainMenuTD(playerid);
        ShowPhoneBankingTD(playerid);
    }
    else if(playertextid == SettingsButtonPhone)
    {
        HidePhoneMainMenuTD(playerid);
        ShowPhoneSettingsTD(playerid);
    }
    else if(playertextid == SettingsTD[0]) //wallpaper
    {
        Dialog_Show(playerid, "PhoneWallpaper", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Wallpaper", 
        "Warna Kuning\n\
        "GRAY"Warna Merah\n\
        Warna Hijau\n\
        "GRAY"Warna Biru\n\
        Warna Cyan\n\
        "GRAY"Warna Pink (default)\n\
        Warna Oren\n\
        "GRAY"Warna Abu-Abu\n\
        Warna Cokelat\n\
        "GRAY"Warna Cream", "Pilih", "Batal");
    }
    else if(playertextid == SettingsTD[2]) //tentang ponsel
    {
        new bcstr[258];
        format(bcstr, sizeof(bcstr), "Saturnus AV24 milik %s\n\
        Nomor telepon:\t%s\n\
        Nama model:\tSaturnus AV24\n\
        Nomor serial:\tAS6R8127V1JKW\n\
        IMEI (slot 1):\t7829127392\n\
        IMEI (slot 2):\t8176239102", GetPlayerRoleplayName(playerid), PlayerPhoneData[playerid][phoneNumber]);
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Tentang Ponsel", 
        bcstr, "Tutup", "");
    }
    else if(playertextid == BankingTD[5]) //transfer mbanking
    {
        Dialog_Show(playerid, "ATMTransfer", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Transfer", 
        "Mohon masukkan nomor rekening tujuan:", "Set", "Batal");
    }
    else if(playertextid == RedButtonOutcomingPhone)
    {
        CutCallingLine(playerid);
    }
    else if(playertextid == GreenButtonIncomingPhone)
    {
        new inlinewithplayerID = PlayerPhoneData[playerid][phoneCallingWithPlayerID]; //orang yang menelepon

        if(!IsPlayerConnected(inlinewithplayerID))
        {
            ShowTDN(playerid, NOTIFICATION_ERROR, "Penelepon telah keluar dari server!");
            CutCallingLine(playerid);
            return 1;
        }

        PlayerPhoneData[playerid][phoneIncomingCall] = false; //orang yang ditelpon
        PlayerPhoneData[inlinewithplayerID][phoneIncomingCall] = false;
        PlayerPhoneData[playerid][phoneDuringConversation] = true;
        PlayerPhoneData[inlinewithplayerID][phoneDuringConversation] = true;
        CancelSelectTextDraw(playerid);
        CancelSelectTextDraw(inlinewithplayerID);

        TextDrawHideForPlayer(playerid, GreenButtonIncomingPhone);
        TextDrawHideForPlayer(playerid, RedButtonIncomingPhone);
        TextDrawShowForPlayer(playerid, RedButtonOutcomingPhone);
        PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], "00:00:00");
        PlayerTextDrawSetString(playerid, StatusDialingTD[inlinewithplayerID], "00:00:00");
        
        ApplyAnimation(playerid, "ped", "phone_talk", 2.00, true, true, true, true, 1, true);
        SetPlayerAttachedObject(playerid, 9, 18871, 6, 0.078999, 0.047999, 0.023999, 0.000000, 0.000000, 179.099899, 1.000000, 1.000000, 1.000000);

        CallRemoteFunction("ConnectPlayerCalling", "ii", playerid, inlinewithplayerID);
    }
    else if(playertextid == RedButtonIncomingPhone)
    {
        CutCallingLine(playerid);
    }
    else if(playertextid == AppStoreButtonPhone)
    {
        ShowPhoneAppStoreTD(playerid);
    }
    else if(playertextid == InstallWAButtonPhone)
    {
        if(PlayerPhoneData[playerid][phoneDownloadingApp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang memasang aplikasi lain!");
        if(PlayerPhoneData[playerid][phoneWhatsAppInstalled]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memasang aplikasi ini!");
        PlayerPhoneData[playerid][phoneDownloadingApp] = true;
        PlayerPhoneData[playerid][phoneInstallAppTimer] = SetTimerEx("OnPhoneInstallApp", 1000, true, "id", playerid, 1);
    }
    else if(playertextid == InstallSpotifyButtonPhone)
    {
        if(PlayerPhoneData[playerid][phoneDownloadingApp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang memasang aplikasi lain!");
        if(PlayerPhoneData[playerid][phoneSpotifyInstalled]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memasang aplikasi ini!");
        PlayerPhoneData[playerid][phoneDownloadingApp] = true;
        PlayerPhoneData[playerid][phoneInstallAppTimer] = SetTimerEx("OnPhoneInstallApp", 1000, true, "id", playerid, 2);
    }
    else if(playertextid == InstallTwitterButtonPhone)
    {
        if(PlayerPhoneData[playerid][phoneDownloadingApp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang memasang aplikasi lain!");
        if(PlayerPhoneData[playerid][phoneTwitterInstalled]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memasang aplikasi ini!");
        PlayerPhoneData[playerid][phoneDownloadingApp] = true;
        PlayerPhoneData[playerid][phoneInstallAppTimer] = SetTimerEx("OnPhoneInstallApp", 1000, true, "id", playerid, 3);
    }
    else if(playertextid == InstallUberButtonPhone)
    {
        if(PlayerPhoneData[playerid][phoneDownloadingApp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang memasang aplikasi lain!");
        if(PlayerPhoneData[playerid][phoneUberInstalled]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memasang aplikasi ini!");
        PlayerPhoneData[playerid][phoneDownloadingApp] = true;
        PlayerPhoneData[playerid][phoneInstallAppTimer] = SetTimerEx("OnPhoneInstallApp", 1000, true, "id", playerid, 4);
    }
    else if(playertextid == InstallYellowButtonPhone)
    {
        if(PlayerPhoneData[playerid][phoneDownloadingApp]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang memasang aplikasi lain!");
        if(PlayerPhoneData[playerid][phoneYellowInstalled]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memasang aplikasi ini!");
        PlayerPhoneData[playerid][phoneDownloadingApp] = true;
        PlayerPhoneData[playerid][phoneInstallAppTimer] = SetTimerEx("OnPhoneInstallApp", 1000, true, "id", playerid, 5);
    }
    else if(playertextid == WhatsappButtonPhone[1])
    {
        index_contact[playerid] = 0;
        ShowContactList(playerid);
    }
    else if(playertextid == SpotifyButtonPhone[1])
    {
        HidePhoneMainMenuTD(playerid);
        ShowSpotifyTD(playerid);
    }
    else if(playertextid == SpotifyTD[2]) //boombox
    {
        if(!AccountData[playerid][pBoombox]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Boombox!");
        if(AccountData[playerid][pVIP] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan Donatur VIP!");
        
        Dialog_Show(playerid, "SpotifyBoombox", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Spotify", 
        "Masukkan URL/link MP3 yang ingin diputar\n\
        Kami sarankan anda untuk upload file mp3 ke discord terlebih dahulu.\n\
        "RED"Note: Fitur ini tidak support link YouTube secara langsung!\n\n\
        "YELLOW"(Apabila file mp3 telah di upload ke discord, silakan copy linknya dan paste di bawah ini):", "Pilih", "Batal");
    }
    else if(playertextid == SpotifyTD[5]) //earphone
    {
        if(!AccountData[playerid][pEarphone]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Earphone!");

        Dialog_Show(playerid, "SpotifyEarphone", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Spotify", 
        "Masukkan URL/link MP3 yang ingin diputar\n\
        Kami sarankan anda untuk upload file mp3 ke discord terlebih dahulu.\n\
        "RED"Note: Fitur ini tidak support link YouTube secara langsung!\n\n\
        "YELLOW"(Apabila file mp3 telah di upload ke discord, silakan copy linknya dan paste di bawah ini):", "Pilih", "Batal");
    }
    else if(playertextid == UberButtonPhone[1]) //Uber 
    {
        HidePhoneMainMenuTD(playerid);
        ShowUberPhoneTD(playerid);
    }
    else if(playertextid == UberPhoneTD[5]) //Uber Ride
    {
        if(gettime() < UberAppTemp[playerid][NeedUberTimer]) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Anda telah memesan uber, mohon tunggu %d detik!", UberAppTemp[playerid][NeedUberTimer] - gettime()));
        if(UberAppTemp[playerid][ServiceAcceptedBy] != INVALID_PLAYER_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Driver sedang menuju ke titik anda, tetaplah berada di sana!");
        ResetUberAppTemp(playerid);
        Dialog_Show(playerid, "UberRideConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
        "Hi, you are going to book an Uber Ride. Where are you headed today?", "Input", "Batal");
    }
    else if(playertextid == UberPhoneTD[6]) //uber eat
    {
        if(gettime() < UberAppTemp[playerid][NeedUberTimer]) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Anda telah memesan uber, mohon tunggu %d detik!", UberAppTemp[playerid][NeedUberTimer] - gettime()));
        if(UberAppTemp[playerid][ServiceAcceptedBy] != INVALID_PLAYER_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Driver sedang menuju ke titik anda, tetaplah berada di sana!");
        ResetUberAppTemp(playerid);
        new gofood[588];
        format(gofood, sizeof(gofood), "Nama Item\tKeranjang\n\
        BBQ delicy\t%dx\n\
        "GRAY"Selesaikan pesanan", UberAppTemp[playerid][ShotDeluxeQuant], UberAppTemp[playerid][TotalQuant]);
        Dialog_Show(playerid, "UberEatMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Uber App", 
        gofood, "Pilih", "Batal");
    }
    else if(playertextid == YellowButtonPhone[1]) //yellow page
    {
        Dialog_Show(playerid, "Yellowpage", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Yellow Page", "View advertisement queues\nSubmit a new advertisement", "Pilih", "Batal");
    }
    else if(playertextid == CallButtonPhone) //call
    {
        Dialog_Show(playerid, "PhoneCallList", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Call", 
        "Emergency Service\n\
        SAGov Public Service\n\
        Bennys Automotive Service\n\
        Pring Sewu Beach Club Service\n\
        Loving Donuts Service\n\
        DriftKing Workshop Service\n\
        Jaya Abadi Service\n\
        "GRAY"> Call another number", "Pilih", "Batal");
    }
    return 1;
}
*/
ptask UpdateCallingTime[1000](playerid) 
{
    if(IsPlayerConnected(playerid) && AccountData[playerid][IsLoggedIn] && AccountData[playerid][pSpawned] && PlayerPhoneData[playerid][phoneDuringConversation])
    {
        PlayerPhoneData[playerid][phoneCallingTime]++;
        PlayerTextDrawSetString(playerid, StatusDialingTD[playerid], sprintf("%s", GetFormatTime(PlayerPhoneData[playerid][phoneCallingTime])));
    }
    return 1;
}

Dialog:ContactList(playerid, response, listitem, inputtext[])
{
    if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");

    if(listitem == -1 || listitem >= MAX_CONTACTS) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih kontak apapun!");

    if(!strcmp(inputtext, ">> Selanjutnya", true)) 
    {
        index_contact[playerid]++;

        new
            max_contact_page = MAX_CONTACTS / MAX_CONTACT_ROWS;

        if(index_contact[playerid] >= max_contact_page) 
        {
            index_contact[playerid] = max_contact_page;
        }
        ShowContactList(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true)) 
    {
        index_contact[playerid]--;
        if(index_contact[playerid] <= 0) {
            index_contact[playerid] = 0;
        }
        ShowContactList(playerid);
    }
    else 
    {
        new contactid = ListedContacts[playerid][listitem];

        PlayerPhoneData[playerid][phoneContactSelected] = contactid;

        if(PlayerPhoneData[playerid][phoneContactSelected] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih kontak apapun!");
        
        new fzstr[128];
        format(fzstr, sizeof(fzstr), "Kontak - %s", ContactData[playerid][contactid][contactName]);
        Dialog_Show(playerid, "ContactSelect", DIALOG_STYLE_LIST, fzstr, "Panggil\n"GRAY"WhatsApp\nShareloc\n"GRAY"Edit Nama Kontak\nBuka/Blokir Kontak\n"GRAY"Hapus Kontak", "Pilih", "Kembali");
    }
    return 1;
}