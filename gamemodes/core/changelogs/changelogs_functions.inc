Dialog:ChangeLogs(playerid, response, listitem, inputtext[])
{
    switch(listitem)
    {
        case 0:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add mapping Bintang Kejora cafe\n\
            "GREEN"Add save database setiap 1 jam sekali\n\
            "GREEN"Add cmd /fmodif untuk semua faction bengek (sementara)\n\n\
            "PINK"Chnage Texas Chiken to Bintang Kejora\n\
            "PINK"Change location kanpol Vertex\n\
            "PINK"Change mapping kanpol\n\
            "PINK"Change dialog gps\n\
            "PINK"Change pajak uang bank 0,8 > 0.4\n\
            "PINK"Change pajak kendaraan pribadi 0,5 > 0.2\n\
            "PINK"Change harga pangan di megamall\n\n\
            "ORANGE"Fixxed cmd sid/ntag\n\
            "ORANGE"Fixxed kehabisan waktu saat login\n\
            "ORANGE"Fixxed kendaraan faction ke double\n\
            "ORANGE"Fixxed faction uber, invoice, uang masuk perjalanan, locker\n\
            "GREEN"etc", "Tutup", "");
        }
        case 1:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add td menu sri mersing\n\
            "GREEN"Add mekanik bisa refair kendaraan faction\n\
            "GREEN"Add pamer hasil pancing\n\
            "GREEN"Add kendaraan uber\n\
            "GREEN"Add seragam uber\n\
            "GREEN"Add pengambilan berangkas ems hanya rank 5 ke atas\n\
            "GREEN"Add skin pewarta\n\
            "GREEN"Add skin pring sewu\n\n\
            "PINK"Change harga pring sewu\n\
            "PINK"Change harga berban di warung\n\
            "PINK"Change harga pangan di megamall\n\
            "ORANGE"Fixxed kendaraan fraksi kalo kesantet ilang\n\
            "ORANGE"Fixxed sid/ntag\n\
            "ORANGE"Fixxed dynamic door\n\
            "GREEN"etc", "Tutup", "");
        }
        case 2:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add cmd /okickadmin untuk kick admin offline\n\
            "GREEN"Add pangkay baru kepolisian\n\
            "ORANGE"Change td hbe\n\
            "ORANGE"Change td down\n\
            "ORANGE"Change waktu makan minum\n\
            "RED"Fixxed ptask timer update\n\
            "RED"Fixxed max player\n\
            "GREEN"etc", "Tutup", "");
        }
        case 3:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add mappingan monciliat\n\
            "GREEN"Add point area modif jaya abadi\n\
            "GREEN"Fixxed /sm /flist\n\
            "GREEN"Fixxed max player\n\
            "RED"Otimazed Script\n\
            "GREEN"etc", "Tutup", "");
        }
        case 4:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add gusur house\n\
            "GREEN"Add mappingan donate\n\
            "GREEN"Add price system\n\
            "GREEN"Add mapping IKEA\n\
            "GREEN"Add gps IKEA\n\
            "GREEN"Add cmd /modesan hehe\n\
            "GREEN"Add cmd /mprice untuk melihat harga penjualan\n\
            "GREEN"Add cmd kick player chiters\n\
            "GREEN"Fixxed SID/NTAG for admin\n\
            "GREEN"Fixxed bot register\n\
            "GREEN"Fixxed dj pring sewu\n\
            "RED"Remove beberapa mapping\n\
            "GREEN"etc", "Tutup", "");
        }
        case 5:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add price pada house\n\
            "GREEN"Add /fhelp pewarta\n\
            "GREEN"Add system race /race\n\
            "GREEN"Add mappingan kopi kenangan\n\
            "ORANGE"Change mappingan pedagang\n\
            "RED"Remove beberapa senjata di ammunition\n\
            "GREEN"etc", "Tutup", "");
        }
        case 6:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add bengkel Jaya abadi\n\
            "GREEN"Add kebutuhan bengkel jaya abadi\n\
            "GREEN"Add gps jaya abadi\n\
            "GREEN"Add anti abuse admin\n\
            "GREEN"Add mapping donation\n\
            "GREEN"Add mappimg /oresetapoint\n\
            "PINK"Change name admin\n\
            "ORANGE"Fixxed HBE dan kotak Voice tidak singkron\n\
            "ORANGE"Fixxed blackjack\n\
            "GREEN"etc", "Tutup", "");
        }
        case 7:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add mapping new bombomcar\n\
            "GREEN"Add warna color pda dialog mekanik\n\
            "PINK"Change warna object hp saat membuka hp\n\
            "ORANGE"Fixxed HBE dan kotak Voice tidak singkron\n\
            "ORANGE"Otimazed Script td supaya tidak kena limit\n\
            "GREEN"etc", "Tutup", "");
        }
        case 8:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add mapping depan bandara\n\
            "GREEN"Add mapping idelwood\n\
            "ORANGE"Fixxed /makewedding\n\
            "GREEN"etc", "Tutup", "");
        }
        case 9:
        {
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Change Logs", 
            ""GREEN"Add cmd /changelogs\n\
            "GREEN"Add Mappingan donation\n\
            "GREEN"Add mappingan wedding\n\
            "ORANGE"Fixxed cursor hilang saat buka radial\n\
            "ORANGE"Fixxed megamall\n\
            "PINK"Change tempat wedding\n\
            "GREEN"etc", "Tutup", "");
        }
    }
    return 1;
}