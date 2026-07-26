#include <YSI_Coding\y_hooks>

#define MAX_CONTACT_PER_PAGE    4
#define MAX_CONTACT_PAGE (MAX_CONTACTS / MAX_CONTACT_PER_PAGE)

new g_ContactSearchFilter[MAX_PLAYERS][24];
new PlayerText:KontakListVRP[MAX_PLAYERS][MAX_CONTACT_PER_PAGE][6];

HideKontakListTD(playerid)
{
    for(new x = 0; x < 4; x++)
    {
        for(new i = 0; i < 6; i++)
        {
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][x][i]);
        }
    }
}

static const g_AvatarBG[5] = {
    0xF28B82FF, // Merah
    0xAECBFAFF, // Biru
    0xCEEAD6FF, // Hijau
    0xE6C9FFFF, // Ungu
    0xFDD663FF  // Kuning
};

static const g_AvatarTX[5] = {
    0x7B1F1AFF, // Merah teks
    0x174EA6FF, // Biru teks
    0x1E5E2AFF, // Hijau teks
    0x4A148CFF, // Ungu teks
    0x7A4F00FF  // Kuning teks
};

static GetInitials(const name[], output[], len)
{
    new parts = 0, i = 0, out_i = 0;
    while(name[i] != EOS && out_i < len - 1)
    {
        if(i == 0 || name[i - 1] == ' ')
        {
            output[out_i++] = name[i];
            parts++;
            if(parts >= 2) break;
        }
        i++;
    }
    output[out_i] = EOS;
}

static GetAvatarColorIndex(const name[])
{
    return (name[0] % 5);
}

CreateContactListTD(playerid)
{
    for(new idx = 0; idx < MAX_CONTACT_PER_PAGE; idx++)
    {
        new Float:y = float(idx) * 26.0;

        KontakListVRP[playerid][idx][0] = CreatePlayerTextDraw(playerid, 513.000, 187.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, KontakListVRP[playerid][idx][0], 25.000, 29.000);
        PlayerTextDrawAlignment(playerid, KontakListVRP[playerid][idx][0], 1);
        PlayerTextDrawColor(playerid, KontakListVRP[playerid][idx][0], -225737985);
        PlayerTextDrawSetShadow(playerid, KontakListVRP[playerid][idx][0], 0);
        PlayerTextDrawSetOutline(playerid, KontakListVRP[playerid][idx][0], 0);
        PlayerTextDrawBackgroundColor(playerid, KontakListVRP[playerid][idx][0], 255);
        PlayerTextDrawFont(playerid, KontakListVRP[playerid][idx][0], 4);
        PlayerTextDrawSetProportional(playerid, KontakListVRP[playerid][idx][0], 1);

        KontakListVRP[playerid][idx][1] = CreatePlayerTextDraw(playerid, 525.500, 197.000 + y, "RV");
        PlayerTextDrawLetterSize(playerid, KontakListVRP[playerid][idx][1], 0.190, 0.899);
        PlayerTextDrawAlignment(playerid, KontakListVRP[playerid][idx][1], 2);
        PlayerTextDrawColor(playerid, KontakListVRP[playerid][idx][1], 2065636095);
        PlayerTextDrawSetShadow(playerid, KontakListVRP[playerid][idx][1], 0);
        PlayerTextDrawSetOutline(playerid, KontakListVRP[playerid][idx][1], 0);
        PlayerTextDrawBackgroundColor(playerid, KontakListVRP[playerid][idx][1], 150);
        PlayerTextDrawFont(playerid, KontakListVRP[playerid][idx][1], 1);
        PlayerTextDrawSetProportional(playerid, KontakListVRP[playerid][idx][1], 1);

        KontakListVRP[playerid][idx][2] = CreatePlayerTextDraw(playerid, 535.000, 189.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, KontakListVRP[playerid][idx][2], 75.000, 23.000);
        PlayerTextDrawAlignment(playerid, KontakListVRP[playerid][idx][2], 1);
        PlayerTextDrawColor(playerid, KontakListVRP[playerid][idx][2], -1);
        PlayerTextDrawSetShadow(playerid, KontakListVRP[playerid][idx][2], 0);
        PlayerTextDrawSetOutline(playerid, KontakListVRP[playerid][idx][2], 0);
        PlayerTextDrawBackgroundColor(playerid, KontakListVRP[playerid][idx][2], 255);
        PlayerTextDrawFont(playerid, KontakListVRP[playerid][idx][2], 4);
        PlayerTextDrawSetProportional(playerid, KontakListVRP[playerid][idx][2], 1);
        PlayerTextDrawSetSelectable(playerid, KontakListVRP[playerid][idx][2], 1);

        KontakListVRP[playerid][idx][3] = CreatePlayerTextDraw(playerid, 539.500, 193.000 + y, "Ronnie Varquez");
        PlayerTextDrawLetterSize(playerid, KontakListVRP[playerid][idx][3], 0.150, 0.899);
        PlayerTextDrawAlignment(playerid, KontakListVRP[playerid][idx][3], 1);
        PlayerTextDrawColor(playerid, KontakListVRP[playerid][idx][3], 539043071);
        PlayerTextDrawSetShadow(playerid, KontakListVRP[playerid][idx][3], 0);
        PlayerTextDrawSetOutline(playerid, KontakListVRP[playerid][idx][3], 0);
        PlayerTextDrawBackgroundColor(playerid, KontakListVRP[playerid][idx][3], 150);
        PlayerTextDrawFont(playerid, KontakListVRP[playerid][idx][3], 1);
        PlayerTextDrawSetProportional(playerid, KontakListVRP[playerid][idx][3], 1);

        KontakListVRP[playerid][idx][4] = CreatePlayerTextDraw(playerid, 539.500, 202.000 + y, "+62 812-3456-7890");
        PlayerTextDrawLetterSize(playerid, KontakListVRP[playerid][idx][4], 0.109, 0.699);
        PlayerTextDrawAlignment(playerid, KontakListVRP[playerid][idx][4], 1);
        PlayerTextDrawColor(playerid, KontakListVRP[playerid][idx][4], 1600350463);
        PlayerTextDrawSetShadow(playerid, KontakListVRP[playerid][idx][4], 0);
        PlayerTextDrawSetOutline(playerid, KontakListVRP[playerid][idx][4], 0);
        PlayerTextDrawBackgroundColor(playerid, KontakListVRP[playerid][idx][4], 150);
        PlayerTextDrawFont(playerid, KontakListVRP[playerid][idx][4], 1);
        PlayerTextDrawSetProportional(playerid, KontakListVRP[playerid][idx][4], 1);

        KontakListVRP[playerid][idx][5] = CreatePlayerTextDraw(playerid, 540.000, 213.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, KontakListVRP[playerid][idx][5], 70.000, 1.000);
        PlayerTextDrawAlignment(playerid, KontakListVRP[playerid][idx][5], 1);
        PlayerTextDrawColor(playerid, KontakListVRP[playerid][idx][5], -387256833);
        PlayerTextDrawSetShadow(playerid, KontakListVRP[playerid][idx][5], 0);
        PlayerTextDrawSetOutline(playerid, KontakListVRP[playerid][idx][5], 0);
        PlayerTextDrawBackgroundColor(playerid, KontakListVRP[playerid][idx][5], 255);
        PlayerTextDrawFont(playerid, KontakListVRP[playerid][idx][5], 4);
        PlayerTextDrawSetProportional(playerid, KontakListVRP[playerid][idx][5], 1);
    }
}

hook OnPlayerConnect(playerid)
{
    CreateContactListTD(playerid);
    return 1;
}

ShowContactList(playerid)
{
    new
        curr_page  = index_contact[playerid],
        real_i     = 0,
        slot       = 0,
        has_filter = (g_ContactSearchFilter[playerid][0] != EOS);

    new
        slot_exists[MAX_CONTACT_PER_PAGE],
        slot_name  [MAX_CONTACT_PER_PAGE][24],
        slot_number[MAX_CONTACT_PER_PAGE][13],
        slot_id    [MAX_CONTACT_PER_PAGE];

    new start_idx = MAX_CONTACT_PER_PAGE * curr_page;

    for(new i = 0; i < MAX_CONTACTS; i++)
    {
        if(!ContactData[playerid][i][contactExists]) continue;

        if(has_filter)
        {
            if(strfind(ContactData[playerid][i][contactName], g_ContactSearchFilter[playerid], true) == -1) continue;
        }

        if(real_i >= start_idx && slot < MAX_CONTACT_PER_PAGE)
        {
            slot_exists[slot] = 1;
            slot_id    [slot] = i;
            strcopy(slot_name  [slot], ContactData[playerid][i][contactName],   24);
            strcopy(slot_number[slot], ContactData[playerid][i][contactNumber], 13);
            slot++;
        }
        real_i++;
    }

    new max_pages = MAX_CONTACT_PAGE;

    new page_str[16];
    format(page_str, sizeof(page_str), "Hal %d/%d", curr_page + 1, max_pages);
    PlayerTextDrawSetString(playerid, KontakVRP[playerid][65], page_str);

    PlayerPhoneData[playerid][CurrentlyReadWA] = false;
    PlayerPhoneData[playerid][phoneContactSelected] = -1;

    for(new s = 0; s < MAX_CONTACT_PER_PAGE; s++)
    {
        ListedContacts[playerid][s] = -1;

        if(slot_exists[s])
        {
            new initials[4];
            new color_idx = GetAvatarColorIndex(slot_name[s]);
            GetInitials(slot_name[s], initials, sizeof(initials));

            PlayerTextDrawColor(playerid, KontakListVRP[playerid][s][0], g_AvatarBG[color_idx]);
            PlayerTextDrawShow(playerid, KontakListVRP[playerid][s][0]);

            PlayerTextDrawSetString(playerid, KontakListVRP[playerid][s][1], initials);
            PlayerTextDrawColor(playerid, KontakListVRP[playerid][s][1], g_AvatarTX[color_idx]);
            PlayerTextDrawShow(playerid, KontakListVRP[playerid][s][1]);

            PlayerTextDrawShow(playerid, KontakListVRP[playerid][s][2]);

            PlayerTextDrawSetString(playerid, KontakListVRP[playerid][s][3], slot_name[s]);
            PlayerTextDrawShow(playerid, KontakListVRP[playerid][s][3]);

            PlayerTextDrawSetString(playerid, KontakListVRP[playerid][s][4], slot_number[s]);
            PlayerTextDrawShow(playerid, KontakListVRP[playerid][s][4]);

            PlayerTextDrawShow(playerid, KontakListVRP[playerid][s][5]);
            ListedContacts[playerid][s] = slot_id[s];
        }
        else
        {
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][s][0]);
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][s][1]);
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][s][2]);
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][s][3]);
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][s][4]);
            PlayerTextDrawHide(playerid, KontakListVRP[playerid][s][5]);
        }
    }

    PlayerTextDrawShow(playerid, KontakVRP[playerid][65]);
    SelectTextDraw(playerid, 0xFFFFFF80);
    return 1;
}

Dialog:ContactSearch(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        g_ContactSearchFilter[playerid][0] = EOS;
        index_contact[playerid] = 0;
        ShowContactList(playerid);
        return 1;
    }
    strcopy(g_ContactSearchFilter[playerid], inputtext, 24);
    index_contact[playerid] = 0;
    ShowContactList(playerid);
    return 1;
}
Dialog:MenuAddContact(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        Info(playerid, "Anda membatalkan pilihan");
        return 1;
    }
    switch(listitem)
    {
        case 0:
        {
            Dialog_Show(playerid, "ContactAddName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Add Contact", "Please insert the contact name that will be saved below:", "Input", "Kembali");
        }
        case 1:
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
    }
    return 1;
}

HandleContactTDClick(playerid, PlayerText:clickedid)
{
    if(clickedid == KontakVRP[playerid][15]) //close 
    {
        HidePhoneContactTD(playerid);
        ResetContactSearch(playerid);
        HideKontakListTD(playerid);
        ShowPhoneVRP(playerid);
    }
    if(clickedid == KontakVRP[playerid][33])
    {
        Dialog_Show(playerid, "ContactSearch", DIALOG_STYLE_INPUT, "Cari Kontak", "Masukkan nama kontak yang ingin dicari:", "Cari", "Batal");
        return 1;
    }

    if(clickedid == KontakVRP[playerid][45])
    {
        Dialog_Show(playerid, "MenuAddContact", DIALOG_STYLE_LIST, "Menu Ponsel", "Tambah Kontak\nAirdrop", "Pilih", "Tutup");
        return 1;
    }

    if(clickedid == KontakVRP[playerid][61])
    {
        if(index_contact[playerid] > 0)
        {
            index_contact[playerid]--;
            ShowContactList(playerid);
        }
        return 1;
    }

    if(clickedid == KontakVRP[playerid][64])
    {
        if(index_contact[playerid] < MAX_CONTACT_PAGE - 1)
        {
            index_contact[playerid]++;
            ShowContactList(playerid);
        }
        return 1;
    }

    for(new s = 0; s < MAX_CONTACT_PER_PAGE; s++)
    {
        if(clickedid == KontakListVRP[playerid][s][2])
        {
            new contactid = ListedContacts[playerid][s];
            if(contactid == -1) return 1;

            PlayerPhoneData[playerid][phoneContactSelected] = contactid;

            new fzstr[64];
            format(fzstr, sizeof(fzstr), "Kontak - %s", ContactData[playerid][contactid][contactName]);
            Dialog_Show(playerid, "ContactSelect", DIALOG_STYLE_LIST, fzstr,"Panggil\n"GRAY"WhatsApp\nShareloc\n"GRAY"Edit Nama Kontak\nBuka/Blokir Kontak\n"GRAY"Hapus Kontak","Pilih", "Kembali");
            return 1;
        }
    }
    return 0;
}

hook ClickDynPlayerTextdraw(playerid, PlayerText:textid)
{
    if(HandleContactTDClick(playerid, textid)) return 1;
    return 1;
}

ResetContactSearch(playerid)
{
    g_ContactSearchFilter[playerid][0] = EOS;
    index_contact[playerid] = 0;
}
