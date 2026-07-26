YCMD:buy(playerid, params[], help)
{
    if(AccountData[playerid][pInBiz] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam bisnis!");

    new bizid = AccountData[playerid][pInBiz];
    
    // Cek posisi point pembelian
    if(!IsPlayerInRangeOfPoint(playerid, 2.0, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2]))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di titik point pembelian");
    
    switch(BizData[bizid][bizType])
    {
        case 1: // minimarket - hanya barang non-senjata (tanpa senjata & cangkul)
        {
            new haji[555];
            format(haji, sizeof(haji), "Nama\tHarga\n\
            Nasi Uduk\t$%s\n\
            "GRAY"Air Mineral\t"GRAY"$%s\n\
            Skateboard\t$%s\n\
            "GRAY"Udud (12 batang)\t"GRAY"$%s\n\
            Obeng\t$%s\n\
            "GRAY"Pilox\t"GRAY"$%s\n\
            Senter\t$%s\n\
            "GRAY"Pancingan\t"GRAY"$%s\n\
            Umpan\t$%s\n\
            "GRAY"Ember\t"GRAY"$%s\n\
            Toolkit\t$%s",
            FormatMoney(BizData[bizid][bizProdPrice][0]),  // Nasi Uduk
            FormatMoney(BizData[bizid][bizProdPrice][1]),  // Air Mineral
            FormatMoney(BizData[bizid][bizProdPrice][2]),  // Skateboard
            FormatMoney(BizData[bizid][bizProdPrice][3]),  // Udud
            FormatMoney(BizData[bizid][bizProdPrice][4]),  // Obeng
            FormatMoney(BizData[bizid][bizProdPrice][5]),  // Pilox
            FormatMoney(BizData[bizid][bizProdPrice][6]),  // Senter
            FormatMoney(BizData[bizid][bizProdPrice][7]),  // Pancingan
            FormatMoney(BizData[bizid][bizProdPrice][8]),  // Umpan
            FormatMoney(BizData[bizid][bizProdPrice][9]),  // Ember
            FormatMoney(BizData[bizid][bizProdPrice][10])); // Toolkit
            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Minimarket", haji, "Buy", "Batal");
        }
        case 2: // clothes
        {
            ShowClothesBizMenuTD(playerid, bizid);
        }
        case 3: // electronic
        {
            new haji[555];
            format(haji, sizeof(haji), "Nama\tHarga\n\
            Iphone 16 Pro(Smartphone)\t$%s\n\
            "GRAY"Radio\t"GRAY"$%s\n\
            Earphone\t$%s\n\
            "GRAY"Boombox\t"GRAY"$%s\n\
            Vape\t$%s\n\
            Race Tablet\t$%s",
            FormatMoney(BizData[bizid][bizProdPrice][0]),  // Smartphone
            FormatMoney(BizData[bizid][bizProdPrice][1]),  // Radio
            FormatMoney(BizData[bizid][bizProdPrice][2]),  // Earphone
            FormatMoney(BizData[bizid][bizProdPrice][3]),  // Boombox
            FormatMoney(BizData[bizid][bizProdPrice][4]),  // Vape
            FormatMoney(BizData[bizid][bizProdPrice][5])); // Race Tablet
            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Electronic Shop", haji, "Buy", "Batal");
        }
        case 4: // ammunations - semua senjata + cangkul
        {
            if(AccountData[playerid][pFirearmLicTime] == 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Firearm License!");
            
            new haji[555];
            format(haji, sizeof(haji), "Nama\tPeluru\tHarga\n\
            Baseball Bat\t-\t$%s\n\
            "GRAY"Knife\t"GRAY"-\t$%s\n\
            Golf Stick\t-\t$%s\n\
            "GRAY"Pool Cue\t"GRAY"-\t$%s\n\
            Hunting Rifle\t-\t$%s\n\
            "GRAY"Hunting Ammo\t"GRAY"24x\t$%s\n\
            Katana\t-\t$%s\n\
            "GRAY"Cangkul\t"GRAY"-\t$%s\n\
            Silenced Pistol\t250\t$%s",
            FormatMoney(BizData[bizid][bizProdPrice][0]),  // Baseball Bat
            FormatMoney(BizData[bizid][bizProdPrice][1]),  // Knife
            FormatMoney(BizData[bizid][bizProdPrice][2]),  // Golf Stick
            FormatMoney(BizData[bizid][bizProdPrice][3]),  // Pool Cue
            FormatMoney(BizData[bizid][bizProdPrice][4]),  // Hunting Rifle
            FormatMoney(BizData[bizid][bizProdPrice][5]),  // Hunting Ammo
            FormatMoney(BizData[bizid][bizProdPrice][6]),  // Katana
            FormatMoney(BizData[bizid][bizProdPrice][7]),  // Cangkul (Hoe)
            FormatMoney(BizData[bizid][bizProdPrice][8])); // Silenced Pistol
            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Ammunation", haji, "Buy", "Batal");
        }
        case 5: // Bar - 7 items (minuman alkohol)
        {
            new haji[555];
            format(haji, sizeof(haji), "Nama\tHarga\n\
            Whiskey Premium\t$%s\n\
            "GRAY"Vodka Special\t"GRAY"$%s\n\
            Rum Gold\t$%s\n\
            "GRAY"Tequila Shot\t"GRAY"$%s\n\
            Champagne Deluxe\t$%s\n\
            "GRAY"Beer Classic\t"GRAY"$%s\n\
            Red Wine Exclusive\t$%s",
            FormatMoney(BizData[bizid][bizProdPrice][0]),
            FormatMoney(BizData[bizid][bizProdPrice][1]),
            FormatMoney(BizData[bizid][bizProdPrice][2]),
            FormatMoney(BizData[bizid][bizProdPrice][3]),
            FormatMoney(BizData[bizid][bizProdPrice][4]),
            FormatMoney(BizData[bizid][bizProdPrice][5]),
            FormatMoney(BizData[bizid][bizProdPrice][6]));
            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Bar", haji, "Buy", "Batal");
        }
    }
    return 1;
}
YCMD:bizmenu(playerid, params[], help)
{
    //----- CEK DULU APAKAH PLAYER DI POM BENSIN (TYPE 6) -----
    new fuelid = FuelStation_Nearest(playerid);
    if(fuelid != -1 && BizData[fuelid][bizType] == 6)
    {
        if(BizData[fuelid][bizOwnerID] != AccountData[playerid][pID])
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

        new erex[1024];
        format(erex, sizeof(erex), "Name\tSettings\n\
            Nama Biz\t%s\n\
            "GRAY"Withdraw Kas\t"GRAY"%s\n\
            Deposit Kas\t"GRAY"%s\n\
            Harga BBM\t%s/liter\n\
            "GRAY"Harga Jerigen\t"GRAY"%s\n\
            "GRAY"Status\t"GRAY"%s\n\
            Request Restock Hauling\t%s",
            BizData[fuelid][bizName],
            FormatMoney(BizData[fuelid][bizMoney]),
            FormatMoney(AccountData[playerid][pMoney]),
            FormatMoney(BizData[fuelid][bizFuelPrice]),
            FormatMoney(BizData[fuelid][bizJerigenPrice]),
            (BizData[fuelid][bizLocked]) ? (""RED"Tutup") : (""GREEN"Buka"),
            (g_FuelRestockRequest[fuelid] > 0) ? (""YELLOW"Aktif") : (""GRAY"Tidak Ada"));
        
        Dialog_Show(playerid, "BizMenuFuel", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Menu (Pom Bensin)", erex, "Pilih", "Batal");
        return 1;
    }
    
    //----- JIKA BUKAN POM BENSIN, LANJUT KE BISNIS BIASA -----
    if(AccountData[playerid][pInBiz] == -1) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam bisnis!");

    new bizid = AccountData[playerid][pInBiz];
    if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID]) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

    new erex[1024];
    
    switch(BizData[bizid][bizType])
    {
        case 1: // minimarket - 11 items
        {
            format(erex, sizeof(erex), "Name\tSettings\n\
            Nama Biz\t%s\n\
            "GRAY"Profit\t"GRAY"$%s\n\
            Biaya Masuk\t$%s\n\
            "GRAY"Harga Nasi Uduk\t"GRAY"$%s\n\
            Harga Air Mineral\t$%s\n\
            "GRAY"Harga Skateboard\t"GRAY"$%s\n\
            Harga Udud\t$%s\n\
            "GRAY"Harga Obeng\t"GRAY"$%s\n\
            Harga Pilox\t$%s\n\
            "GRAY"Harga Senter\t"GRAY"$%s\n\
            Harga Pancingan\t$%s\n\
            "GRAY"Harga Umpan\t"GRAY"$%s\n\
            Harga Ember\t$%s\n\
            "GRAY"Harga Toolkit\t"GRAY"$%s\n\
            Status\t%s",
            BizData[bizid][bizName],
            FormatMoney(BizData[bizid][bizMoney]),
            FormatMoney(BizData[bizid][bizEnteranceFee]),
            FormatMoney(BizData[bizid][bizProdPrice][0]),  // Nasi Uduk
            FormatMoney(BizData[bizid][bizProdPrice][1]),  // Air Mineral
            FormatMoney(BizData[bizid][bizProdPrice][2]),  // Skateboard
            FormatMoney(BizData[bizid][bizProdPrice][3]),  // Udud
            FormatMoney(BizData[bizid][bizProdPrice][4]),  // Obeng
            FormatMoney(BizData[bizid][bizProdPrice][5]),  // Pilox
            FormatMoney(BizData[bizid][bizProdPrice][6]),  // Senter
            FormatMoney(BizData[bizid][bizProdPrice][7]),  // Pancingan
            FormatMoney(BizData[bizid][bizProdPrice][8]),  // Umpan
            FormatMoney(BizData[bizid][bizProdPrice][9]),  // Ember
            FormatMoney(BizData[bizid][bizProdPrice][10]), // Toolkit
            (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Menu", erex, "Pilih", "Batal");
        }
        case 2: // clothes - 5 kategori
        {
            format(erex, sizeof(erex), "Name\tSettings\n\
            Nama Biz\t%s\n\
            "GRAY"Profit\t"GRAY"$%s\n\
            Biaya Masuk\t$%s\n\
            "GRAY"Harga Pakaian\t"GRAY"$%s\n\
            Harga Topi/Helm\t$%s\n\
            "GRAY"Harga Kacamata\t"GRAY"$%s\n\
            Harga Aksesoris\t$%s\n\
            "GRAY"Harga Tas/Koper\t"GRAY"$%s\n\
            Status\t%s",
            BizData[bizid][bizName],
            FormatMoney(BizData[bizid][bizMoney]),
            FormatMoney(BizData[bizid][bizEnteranceFee]),
            FormatMoney(BizData[bizid][bizClothesPrice][0]), // Pakaian
            FormatMoney(BizData[bizid][bizClothesPrice][1]), // Topi/Helm
            FormatMoney(BizData[bizid][bizClothesPrice][2]), // Kacamata
            FormatMoney(BizData[bizid][bizClothesPrice][3]), // Aksesoris
            FormatMoney(BizData[bizid][bizClothesPrice][4]), // Tas/Koper
            (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Menu", erex, "Pilih", "Batal");
        }
        case 3: // electronic - 5 items
        {
            format(erex, sizeof(erex), "Name\tSettings\n\
            Nama Biz\t%s\n\
            "GRAY"Profit\t"GRAY"$%s\n\
            Biaya Masuk\t$%s\n\
            "GRAY"Harga Smartphone\t"GRAY"$%s\n\
            Harga Radio\t$%s\n\
            "GRAY"Harga Earphone\t"GRAY"$%s\n\
            Harga Boombox\t$%s\n\
            "GRAY"Harga Vape\t"GRAY"$%s\n\
            Harga Race Tablet\t%s\n\
            Status\t%s",
            BizData[bizid][bizName],
            FormatMoney(BizData[bizid][bizMoney]),
            FormatMoney(BizData[bizid][bizEnteranceFee]),
            FormatMoney(BizData[bizid][bizProdPrice][0]),  // Smartphone
            FormatMoney(BizData[bizid][bizProdPrice][1]),  // Radio
            FormatMoney(BizData[bizid][bizProdPrice][2]),  // Earphone
            FormatMoney(BizData[bizid][bizProdPrice][3]),  // Boombox
            FormatMoney(BizData[bizid][bizProdPrice][4]),  // Vape
            FormatMoney(BizData[bizid][bizProdPrice][5]), //race tablet
            (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Menu", erex, "Pilih", "Batal");
        }
        case 4: // ammunations - 9 items
        {
            format(erex, sizeof(erex), "Name\tSettings\n\
            Nama Biz\t%s\n\
            "GRAY"Profit\t"GRAY"$%s\n\
            Biaya Masuk\t$%s\n\
            "GRAY"Harga Baseball Bat\t"GRAY"$%s\n\
            Harga Knife\t$%s\n\
            "GRAY"Harga Golf Stick\t"GRAY"$%s\n\
            Harga Pool Cue\t$%s\n\
            "GRAY"Harga Hunting Rifle\t"GRAY"$%s\n\
            Harga Hunting Ammo\t$%s\n\
            "GRAY"Harga Katana\t"GRAY"$%s\n\
            Harga Cangkul\t$%s\n\
            "GRAY"Harga Silenced Pistol\t"GRAY"$%s\n\
            Status\t%s",
            BizData[bizid][bizName],
            FormatMoney(BizData[bizid][bizMoney]),
            FormatMoney(BizData[bizid][bizEnteranceFee]),
            FormatMoney(BizData[bizid][bizProdPrice][0]),  // Baseball Bat
            FormatMoney(BizData[bizid][bizProdPrice][1]),  // Knife
            FormatMoney(BizData[bizid][bizProdPrice][2]),  // Golf Stick
            FormatMoney(BizData[bizid][bizProdPrice][3]),  // Pool Cue
            FormatMoney(BizData[bizid][bizProdPrice][4]),  // Hunting Rifle
            FormatMoney(BizData[bizid][bizProdPrice][5]),  // Hunting Ammo
            FormatMoney(BizData[bizid][bizProdPrice][6]),  // Katana
            FormatMoney(BizData[bizid][bizProdPrice][7]),  // Cangkul (Hoe)
            FormatMoney(BizData[bizid][bizProdPrice][8]),  // Silenced Pistol
            (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Menu", erex, "Pilih", "Batal");
        }
        case 5: // Bar - 7 items
        {
            format(erex, sizeof(erex), "Name\tSettings\n\
            Nama Biz\t%s\n\
            "GRAY"Profit\t"GRAY"$%s\n\
            Biaya Masuk\t$%s\n\
            "GRAY"Harga Whiskey Premium\t"GRAY"$%s\n\
            Harga Vodka Special\t$%s\n\
            "GRAY"Harga Rum Gold\t"GRAY"$%s\n\
            Harga Tequila Shot\t$%s\n\
            "GRAY"Harga Champagne Deluxe\t"GRAY"$%s\n\
            Harga Beer Classic\t$%s\n\
            "GRAY"Harga Red Wine Exclusive\t"GRAY"$%s\n\
            Status\t%s",
            BizData[bizid][bizName],
            FormatMoney(BizData[bizid][bizMoney]),
            FormatMoney(BizData[bizid][bizEnteranceFee]),
            FormatMoney(BizData[bizid][bizProdPrice][0]),
            FormatMoney(BizData[bizid][bizProdPrice][1]),
            FormatMoney(BizData[bizid][bizProdPrice][2]),
            FormatMoney(BizData[bizid][bizProdPrice][3]),
            FormatMoney(BizData[bizid][bizProdPrice][4]),
            FormatMoney(BizData[bizid][bizProdPrice][5]),
            FormatMoney(BizData[bizid][bizProdPrice][6]),
            (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            Dialog_Show(playerid, "BizMenu", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Menu", erex, "Pilih", "Batal");
        }
    }
    return 1;
}

YCMD:restockbiz(playerid, params[], help)
{
    if(AccountData[playerid][pInBiz] == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam bisnis!");

    new bizid = AccountData[playerid][pInBiz];
    if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

    new erex[1024];
    
    switch(BizData[bizid][bizType])
    {
        case 1: // minimarket - 11 items
        {
            format(erex, sizeof(erex), "Name\tCurrent stocks\n\
            Nasi Uduk\t%d\n\
            "GRAY"Air Mineral\t"GRAY"%d\n\
            Skateboard\t%d\n\
            "GRAY"Udud (12 batang)\t"GRAY"%d\n\
            Obeng\t%d\n\
            "GRAY"Pilox\t"GRAY"%d\n\
            Senter\t%d\n\
            "GRAY"Pancingan\t"GRAY"%d\n\
            Umpan\t%d\n\
            "GRAY"Ember\t"GRAY"%d\n\
            Toolkit\t%d",
            BizData[bizid][bizProdStock][0],  // Nasi Uduk
            BizData[bizid][bizProdStock][1],  // Air Mineral
            BizData[bizid][bizProdStock][2],  // Skateboard
            BizData[bizid][bizProdStock][3],  // Udud
            BizData[bizid][bizProdStock][4],  // Obeng
            BizData[bizid][bizProdStock][5],  // Pilox
            BizData[bizid][bizProdStock][6],  // Senter
            BizData[bizid][bizProdStock][7],  // Pancingan
            BizData[bizid][bizProdStock][8],  // Umpan
            BizData[bizid][bizProdStock][9],  // Ember
            BizData[bizid][bizProdStock][10]); // Toolkit
            Dialog_Show(playerid, "BizRestock", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Restock", erex, "Pilih", "Batal");
        }
        case 2: // clothes
        {
            ShowTDN(playerid, NOTIFICATION_INFO, "Clothes shop tidak memiliki sistem restock!");
        }
        case 3: // electronic - 5 items
        {
            format(erex, sizeof(erex), "Name\tCurrent stocks\n\
            Iphone 16 Pro(Smartphone)\t%d\n\
            "GRAY"Radio\t"GRAY"%d\n\
            Earphone\t%d\n\
            "GRAY"Boombox\t"GRAY"%d\n\
            Vape\t%d\n\
            "GRAY"Race Tablet]\t"GRAY"%d",
            BizData[bizid][bizProdStock][0],  // Smartphone
            BizData[bizid][bizProdStock][1],  // Radio
            BizData[bizid][bizProdStock][2],  // Earphone
            BizData[bizid][bizProdStock][3],  // Boombox
            BizData[bizid][bizProdStock][4],  // Vape
            BizData[bizid][bizProdStock][5]); // Race Tablet
            Dialog_Show(playerid, "BizRestock", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Restock", erex, "Pilih", "Batal");
        }
        case 4: // ammunations - 9 items
        {
            format(erex, sizeof(erex), "Name\tCurrent stocks\n\
            Baseball Bat\t%d\n\
            "GRAY"Knife\t"GRAY"%d\n\
            Golf Stick\t%d\n\
            "GRAY"Pool Cue\t"GRAY"%d\n\
            Hunting Rifle\t%d\n\
            "GRAY"Hunting Ammo (24x)\t"GRAY"%d\n\
            Katana\t%d\n\
            "GRAY"Cangkul\t"GRAY"%d\n\
            Silenced Pistol\t%d",
            BizData[bizid][bizProdStock][0],  // Baseball Bat
            BizData[bizid][bizProdStock][1],  // Knife
            BizData[bizid][bizProdStock][2],  // Golf Stick
            BizData[bizid][bizProdStock][3],  // Pool Cue
            BizData[bizid][bizProdStock][4],  // Hunting Rifle
            BizData[bizid][bizProdStock][5],  // Hunting Ammo
            BizData[bizid][bizProdStock][6],  // Katana
            BizData[bizid][bizProdStock][7],  // Cangkul (Hoe)
            BizData[bizid][bizProdStock][8]); // Silenced Pistol
            Dialog_Show(playerid, "BizRestock", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Restock", erex, "Pilih", "Batal");
        }
        case 5: // Bar - 7 items
        {
            format(erex, sizeof(erex), "Name\tCurrent stocks\n\
            Whiskey Premium\t%d\n\
            "GRAY"Vodka Special\t"GRAY"%d\n\
            Rum Gold\t%d\n\
            "GRAY"Tequila Shot\t"GRAY"%d\n\
            Champagne Deluxe\t%d\n\
            "GRAY"Beer Classic\t"GRAY"%d\n\
            Red Wine Exclusive\t%d",
            BizData[bizid][bizProdStock][0],
            BizData[bizid][bizProdStock][1],
            BizData[bizid][bizProdStock][2],
            BizData[bizid][bizProdStock][3],
            BizData[bizid][bizProdStock][4],
            BizData[bizid][bizProdStock][5],
            BizData[bizid][bizProdStock][6]);
            Dialog_Show(playerid, "BizRestock", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Biz Restock", erex, "Pilih", "Batal");
        }
    }
    return 1;
}

YCMD:addbiz(playerid, params[], help)
{
    new bizid = Iter_Free(Bizes), type, price;
    if(AccountData[playerid][pAdmin] < 7) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);
    if(bizid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic businesses telah mencapai batas maksimum!");
    if(sscanf(params, "dd", type, price)) return SUM(playerid, "/addbiz [type] [price]\nType: 1.Minimarket, 2.Clothes, 3.Electronic, 4.Ammunation, 5.Bar, 6.PomBensin");

    if(type < 1 || type > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Type tidak valid! (1 - 6)");
    if(price < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga tidak valid!");

    strcopy(BizData[bizid][bizName], "-");
    BizData[bizid][bizOwnerID] = 0;
    BizData[bizid][bizOwnerName][0] = EOS;
    BizData[bizid][bizLocked] = false;
    BizData[bizid][bizMoney] = 0;
    BizData[bizid][bizType] = type;
    BizData[bizid][bizPrice] = price;
    BizData[bizid][bizEnteranceFee] = 500;

    switch(type)
    {
        case 1:
        {
            for(new x; x < 11; x++)
            {
                BizData[bizid][bizProdStock][x] = 200;
                BizData[bizid][bizProdPrice][x] = 2000;
            }
        }
        case 2:
        {
            for(new x; x < 5; x++)
            {
                BizData[bizid][bizClothesStock][x] = 200;
                BizData[bizid][bizClothesPrice][x] = 2000;
            }
        }
        case 3:
        {
            for(new x; x < 6; x++)
            {
                BizData[bizid][bizProdStock][x] = 200;
                BizData[bizid][bizProdPrice][x] = 2000;
            }
        }
        case 4:
        {
            for(new x; x < 9; x++)
            {
                BizData[bizid][bizProdStock][x] = 200;
                BizData[bizid][bizProdPrice][x] = 2000;
            }
        }
        case 5:
        {
            for(new x; x < 7; x++)
            {
                BizData[bizid][bizProdStock][x] = 200;
                BizData[bizid][bizProdPrice][x] = 2000;
            }
        }
        case 6:
        {
            BizData[bizid][bizFuelPrice] = 50;
            BizData[bizid][bizFuelStock] = 5000;
            BizData[bizid][bizJerigenPrice] = 1500;
            BizData[bizid][bizIntPos][0] = 0.0;
            BizData[bizid][bizIntPos][1] = 0.0;
            BizData[bizid][bizIntPos][2] = 0.0;
            BizData[bizid][bizIntInt] = 0;
        }
    }

    GetPlayerPos(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
    GetPlayerFacingAngle(playerid, BizData[bizid][bizExtPos][3]);

    BizData[bizid][bizPointPos][0] = 0.0;
    BizData[bizid][bizPointPos][1] = 0.0;
    BizData[bizid][bizPointPos][2] = 0.0;
    BizData[bizid][bizPointVw] = GetPlayerVirtualWorld(playerid);
    BizData[bizid][bizPointInt] = GetPlayerInterior(playerid);

    if(type != 6)
    {
        switch(type)
        {
            case 1:
            {
                BizData[bizid][bizIntPos][0] = 1151.1515;
                BizData[bizid][bizIntPos][1] = 1262.2477;
                BizData[bizid][bizIntPos][2] = 11.1779;
                BizData[bizid][bizIntPos][3] = 88.8090;
                BizData[bizid][bizIntInt] = 1;
            }
            case 2:
            {
                BizData[bizid][bizIntPos][0] = 207.5200;
                BizData[bizid][bizIntPos][1] = -109.7400;
                BizData[bizid][bizIntPos][2] = 1005.5300;
                BizData[bizid][bizIntPos][3] = 0.0000;
                BizData[bizid][bizIntInt] = 15;
            }
            case 3:
            {
                BizData[bizid][bizIntPos][0] = 1156.5273;
                BizData[bizid][bizIntPos][1] = 1303.2030;
                BizData[bizid][bizIntPos][2] = 10.8507;
                BizData[bizid][bizIntPos][3] = 89.1223;
                BizData[bizid][bizIntInt] = 2;
            }
            case 4:
            {
                BizData[bizid][bizIntPos][0] = 1156.5273;
                BizData[bizid][bizIntPos][1] = 1303.2030;
                BizData[bizid][bizIntPos][2] = 10.8507;
                BizData[bizid][bizIntPos][3] = 89.1223;
                BizData[bizid][bizIntInt] = 2;
            }
            case 5:
            {
                BizData[bizid][bizIntPos][0] = 501.95;
                BizData[bizid][bizIntPos][1] = -70.56;
                BizData[bizid][bizIntPos][2] = 998.75;
                BizData[bizid][bizIntPos][3] = 00.00;
                BizData[bizid][bizIntInt] = 11;
            }
        }
    }

    BizData[bizid][bizExtVw] = GetPlayerVirtualWorld(playerid);
    BizData[bizid][bizExtInt] = GetPlayerInterior(playerid);
    BizData[bizid][bizIntVw] = bizid+1;

    new sjws[525];

    if(type == 6)
    {
        format(sjws, sizeof(sjws), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'", 
            BizData[bizid][bizName], 
            FormatMoney(BizData[bizid][bizPrice]));
    }
    else
    {
        format(sjws, sizeof(sjws), "%s\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'\n"WHITE"Enterance Fee $%s\n%s", 
            ReturnBizTypeName(bizid), 
            BizData[bizid][bizName], 
            FormatMoney(BizData[bizid][bizPrice]), 
            FormatMoney(BizData[bizid][bizEnteranceFee]), 
            (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
    }

    BizData[bizid][bizLabel] = CreateDynamic3DTextLabel(sjws, 0xFFFFFFBF, 
        BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25, 
        10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 10.00, -1, 0);

    if(type == 6)
    {
        // Pom bensin: hanya fuel area, fuel pickup, dan label — TIDAK ada bizPickup pintu
        BizData[bizid][bizFuelArea] = CreateDynamicSphere(
            BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 
            5.0, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
        
        BizData[bizid][bizFuelPickup] = CreateDynamicPickup(19621, 23, 
            BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 
            BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
    }
    else
    {
        BizData[bizid][bizPickup] = CreateDynamicPickup(19133, 23, 
            BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 
            BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 30.00, -1, 0);
        
        BizData[bizid][bizPointPickup] = CreateDynamicPickup(1239, 23, 
            BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2], 
            BizData[bizid][bizPointVw], BizData[bizid][bizPointInt], -1, 10.00, -1, 0);
        
        BizData[bizid][bizPointLabel] = CreateDynamic3DTextLabel(""GREEN"[Y] "WHITE"untuk membeli produk\n"YELLOW"Tekan Y di sini", 
            0x00FF00FF, 
            BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2] + 0.5, 
            5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizPointVw], BizData[bizid][bizPointInt], -1, 10.00, -1, 0);
    }

    Iter_Add(Bizes, bizid);

    static dddstr[2800];
    mysql_format(g_SQL, dddstr, sizeof(dddstr), 
        "INSERT INTO `biz` SET `ID`=%d, `Name`='%e', `OwnerID`=%d, `OwnerName`='%e', `Locked`=%d, `Money`=%d, `Type`=%d, `Price`=%d, `Fee`=%d, \
        `ProdStock0`=%d, `ProdStock1`=%d, `ProdStock2`=%d, `ProdStock3`=%d, `ProdStock4`=%d, `ProdStock5`=%d, `ProdStock6`=%d, `ProdStock7`=%d, \
        `ProdStock8`=%d, `ProdStock9`=%d, `ProdStock10`=%d, `ProdStock11`=%d, `ProdStock12`=%d, `ProdStock13`=%d, `ProdStock14`=%d, `ProdStock15`=%d, \
        `ProdPrice0`=%d, `ProdPrice1`=%d, `ProdPrice2`=%d, `ProdPrice3`=%d, `ProdPrice4`=%d, `ProdPrice5`=%d, `ProdPrice6`=%d, `ProdPrice7`=%d, \
        `ProdPrice8`=%d, `ProdPrice9`=%d, `ProdPrice10`=%d, `ProdPrice11`=%d, `ProdPrice12`=%d, `ProdPrice13`=%d, `ProdPrice14`=%d, `ProdPrice15`=%d, \
        `ClothesStock0`=%d, `ClothesStock1`=%d, `ClothesStock2`=%d, `ClothesStock3`=%d, `ClothesStock4`=%d, \
        `ClothesPrice0`=%d, `ClothesPrice1`=%d, `ClothesPrice2`=%d, `ClothesPrice3`=%d, `ClothesPrice4`=%d, \
        `X`='%f', `Y`='%f', `Z`='%f', `A`='%f', `IntX`='%f', `IntY`='%f', `IntZ`='%f', `IntA`='%f', \
        `ExtVw`=%d, `ExtInt`=%d, `IntVw`=%d, `IntInt`=%d, \
        `PointX`='%f', `PointY`='%f', `PointZ`='%f', `PointVw`=%d, `PointInt`=%d, \
        `fuel_price`=%d, `fuel_stock`=%d, `jerigen_price`=%d", 
        bizid,
        BizData[bizid][bizName], 
        BizData[bizid][bizOwnerID], 
        BizData[bizid][bizOwnerName], 
        BizData[bizid][bizLocked], 
        BizData[bizid][bizMoney], 
        BizData[bizid][bizType],
        BizData[bizid][bizPrice],
        BizData[bizid][bizEnteranceFee],
        BizData[bizid][bizProdStock][0], BizData[bizid][bizProdStock][1], BizData[bizid][bizProdStock][2], BizData[bizid][bizProdStock][3],
        BizData[bizid][bizProdStock][4], BizData[bizid][bizProdStock][5], BizData[bizid][bizProdStock][6], BizData[bizid][bizProdStock][7],
        BizData[bizid][bizProdStock][8], BizData[bizid][bizProdStock][9], BizData[bizid][bizProdStock][10], BizData[bizid][bizProdStock][11],
        BizData[bizid][bizProdStock][12], BizData[bizid][bizProdStock][13], BizData[bizid][bizProdStock][14], BizData[bizid][bizProdStock][15],
        BizData[bizid][bizProdPrice][0], BizData[bizid][bizProdPrice][1], BizData[bizid][bizProdPrice][2], BizData[bizid][bizProdPrice][3],
        BizData[bizid][bizProdPrice][4], BizData[bizid][bizProdPrice][5], BizData[bizid][bizProdPrice][6], BizData[bizid][bizProdPrice][7],
        BizData[bizid][bizProdPrice][8], BizData[bizid][bizProdPrice][9], BizData[bizid][bizProdPrice][10], BizData[bizid][bizProdPrice][11],
        BizData[bizid][bizProdPrice][12], BizData[bizid][bizProdPrice][13], BizData[bizid][bizProdPrice][14], BizData[bizid][bizProdPrice][15],
        BizData[bizid][bizClothesStock][0], BizData[bizid][bizClothesStock][1], BizData[bizid][bizClothesStock][2], BizData[bizid][bizClothesStock][3], BizData[bizid][bizClothesStock][4],
        BizData[bizid][bizClothesPrice][0], BizData[bizid][bizClothesPrice][1], BizData[bizid][bizClothesPrice][2], BizData[bizid][bizClothesPrice][3], BizData[bizid][bizClothesPrice][4],
        BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtPos][3],
        BizData[bizid][bizIntPos][0], BizData[bizid][bizIntPos][1], BizData[bizid][bizIntPos][2], BizData[bizid][bizIntPos][3],
        BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], BizData[bizid][bizIntVw], BizData[bizid][bizIntInt],
        BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2],
        BizData[bizid][bizPointVw], BizData[bizid][bizPointInt],
        BizData[bizid][bizFuelPrice], BizData[bizid][bizFuelStock], BizData[bizid][bizJerigenPrice]);

    mysql_pquery(g_SQL, dddstr, "OnBizCreated", "ii", playerid, bizid);
    return 1;
}
YCMD:editbiz(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new bizid, type[24], string[128];
    if(sscanf(params, "ds[24]S()[128]", bizid, type, string)) return SUM(playerid, "/editbiz [id] [option] [value]\nOptions: name, pos, pointpos, type, reset, remove, restock, fuelprice, fuelstock, jerigenprice");
    if(!Iter_Contains(Bizes, bizid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Bisnis tidak valid!");

    if(!strcmp(type, "pos", true))
    {
        GetPlayerPos(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
        GetPlayerFacingAngle(playerid, BizData[bizid][bizExtPos][3]);
        BizData[bizid][bizExtVw] = GetPlayerVirtualWorld(playerid);
        BizData[bizid][bizExtInt] = GetPlayerInterior(playerid);
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s change location for Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    }
    else if(!strcmp(type, "pointpos", true))
    {
        GetPlayerPos(playerid, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2]);
        BizData[bizid][bizPointVw] = GetPlayerVirtualWorld(playerid);
        BizData[bizid][bizPointInt] = GetPlayerInterior(playerid);
        Biz_Save(bizid);
        Biz_Rebuild(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s change point position for Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    }
    else if(!strcmp(type, "name", true))
    {
        if(isnull(string)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nama tidak boleh kosong!");
        strcopy(BizData[bizid][bizName], string);
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s change name for Business ID: %d to %s.", AccountData[playerid][pAdminname], bizid, string);
    }
    else if(!strcmp(type, "type", true))
    {
        new btype;
        if(sscanf(string, "d", btype)) return SUM(playerid, "/editbiz [id] [type] [1 - 6]");
        if(btype < 1 || btype > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Type tidak valid! (1-6)");
        BizData[bizid][bizType] = btype;
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has change the type of Business ID: %d to %d.", AccountData[playerid][pAdminname], bizid, btype);
    }
    else if(!strcmp(type, "reset", true))
    {
        strcopy(BizData[bizid][bizName], "-");
        BizData[bizid][bizOwnerName][0] = EOS;
        BizData[bizid][bizOwnerID] = 0;
        BizData[bizid][bizMoney] = 0;
        switch(BizData[bizid][bizType])
        {
            case 1:
            {
                for(new x; x < 11; x++)
                {
                    BizData[bizid][bizProdStock][x] = 200;
                    BizData[bizid][bizProdPrice][x] = 2000;
                }
            }
            case 2:
            {
                for(new x; x < 5; x++)
                {
                    BizData[bizid][bizClothesStock][x] = 200;
                    BizData[bizid][bizClothesPrice][x] = 2000;
                }
            }
            case 3:
            {
                for(new x; x < 6; x++)
                {
                    BizData[bizid][bizProdStock][x] = 200;
                    BizData[bizid][bizProdPrice][x] = 2000;
                }
            }
            case 4:
            {
                for(new x; x < 9; x++)
                {
                    BizData[bizid][bizProdStock][x] = 200;
                    BizData[bizid][bizProdPrice][x] = 2000;
                }
            }
            case 5:
            {
                for(new x; x < 7; x++)
                {
                    BizData[bizid][bizProdStock][x] = 200;
                    BizData[bizid][bizProdPrice][x] = 2000;
                }
            }
            case 6:
            {
                BizData[bizid][bizFuelPrice] = 50;
                BizData[bizid][bizFuelStock] = 5000;
                BizData[bizid][bizJerigenPrice] = 1500;
            }
        }
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has reset Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    }
    else if(!strcmp(type, "restock", true))
    {
        new productid, amount;
        if(sscanf(string, "dd", productid, amount)) return SUM(playerid, "/editbiz [id] restock [productid] [amount]");
        
        new max_productid;
        new bool:is_clothes = false;
        
        switch(BizData[bizid][bizType])
        {
            case 1: max_productid = 10;
            case 2: is_clothes = true;
            case 3: max_productid = 4;
            case 4: max_productid = 8;
            case 5: max_productid = 6;
            default: max_productid = -1;
        }
        
        if(is_clothes)
        {
            if(productid < 0 || productid > 4) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Product ID tidak valid untuk Clothes Shop! (0-4)");
            if(amount < 1 || amount > 1000) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Amount harus 1-1000!");
            new total = BizData[bizid][bizClothesStock][productid] + amount;
            if(total > 1000) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Stok melebihi batas maksimal 1000!");
            BizData[bizid][bizClothesStock][productid] += amount;
            Biz_Save(bizid);
            new category_name[32];
            switch(productid)
            {
                case 0: category_name = "Pakaian";
                case 1: category_name = "Topi/Helm";
                case 2: category_name = "Kacamata";
                case 3: category_name = "Aksesoris";
                case 4: category_name = "Tas/Koper";
            }
            SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s restocked Business ID: %d category %s (%d) with %d items.", AccountData[playerid][pAdminname], bizid, category_name, productid, amount);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Berhasil merestok %d item untuk %s!", amount, category_name));
            return 1;
        }
        
        if(BizData[bizid][bizType] == 2 || BizData[bizid][bizType] == 6) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Tipe bisnis ini tidak memiliki sistem restock!");
        if(max_productid == -1) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Tipe bisnis ini tidak memiliki sistem restock!");
        if(productid < 0 || productid > max_productid) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Product ID tidak valid! (0-%d)", max_productid));
        if(amount < 1 || amount > 1000) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Amount harus 1-1000!");
        new total = BizData[bizid][bizProdStock][productid] + amount;
        if(total > 1000) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Stok melebihi batas maksimal 1000!");
        BizData[bizid][bizProdStock][productid] += amount;
        Biz_Save(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s restocked Business ID: %d product %d with %d items.", AccountData[playerid][pAdminname], bizid, productid, amount);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Berhasil merestok %d item untuk product ID %d!", amount, productid));
    }
    //----- EDIT FUEL PRICE -----
    else if(!strcmp(type, "fuelprice", true))
    {
        if(BizData[bizid][bizType] != 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bukan pom bensin!");
        new price;
        if(sscanf(string, "d", price)) return SUM(playerid, "/editbiz [id] fuelprice [harga]");
        if(price < 1 || price > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga 1-1000!");
        BizData[bizid][bizFuelPrice] = price;
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set fuel price Biz ID %d to %s", AccountData[playerid][pAdminname], bizid, FormatMoney(price));
    }
    //----- EDIT FUEL STOCK -----
    else if(!strcmp(type, "fuelstock", true))
    {
        if(BizData[bizid][bizType] != 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bukan pom bensin!");
        new Stok;
        if(sscanf(string, "d", Stok)) return SUM(playerid, "/editbiz [id] fuelstock [jumlah]");
        if(Stok < 0 || Stok > 50000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stok 0-50000 liter!");
        BizData[bizid][bizFuelStock] = Stok;
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set fuel stock Biz ID %d to %d liter", AccountData[playerid][pAdminname], bizid, Stok);
    }
    //----- EDIT JERIGEN PRICE -----
    else if(!strcmp(type, "jerigenprice", true))
    {
        if(BizData[bizid][bizType] != 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bukan pom bensin!");
        new price;
        if(sscanf(string, "d", price)) return SUM(playerid, "/editbiz [id] jerigenprice [harga]");
        if(price < 1 || price > 100000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga 1-100000!");
        BizData[bizid][bizJerigenPrice] = price;
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set jerigen price Biz ID %d to %s", AccountData[playerid][pAdminname], bizid, FormatMoney(price));
    }
    else if(!strcmp(type, "remove", true))
    {
        if(DestroyDynamicPickup(BizData[bizid][bizPickup]))
            BizData[bizid][bizPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizLabel]))
            BizData[bizid][bizLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        if(DestroyDynamicPickup(BizData[bizid][bizPointPickup]))
            BizData[bizid][bizPointPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizPointLabel]))
            BizData[bizid][bizPointLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
            
        if(DestroyDynamicArea(BizData[bizid][bizFuelArea]))
            BizData[bizid][bizFuelArea] = STREAMER_TAG_AREA: INVALID_STREAMER_ID;

        if(DestroyDynamicPickup(BizData[bizid][bizFuelPickup]))
            BizData[bizid][bizFuelPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

        Iter_Remove(Bizes, bizid);
        new query[128];
        mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `biz` WHERE `ID` = %d", bizid);
        mysql_pquery(g_SQL, query);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s has removed Business ID: %d.", AccountData[playerid][pAdminname], bizid);
    }
    return 1;
}

YCMD:gotobiz(playerid, params[], help)
{
    new bizid;
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);
		
	if(sscanf(params, "d", bizid))
		return SUM(playerid, "/gotobiz [bizid]");

	if(!Iter_Contains(Bizes, bizid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Bisnis tidak valid!");
	SetPlayerPositionEx(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], -90);
    SetPlayerInteriorEx(playerid, BizData[bizid][bizExtInt]);
    SetPlayerVirtualWorldEx(playerid, BizData[bizid][bizExtVw]);

    AccountData[playerid][pInDoor] = -1;
	AccountData[playerid][pInHouse] = -1;
    AccountData[playerid][pInBiz] = -1;
	AccountData[playerid][pInRusun] = -1;
    AccountData[playerid][pInGudang] = -1;
	return 1;
}

YCMD:bizhelp(playerid, params[], help)
{
    new string[2024];
    
    format(string, sizeof(string), ""WHITE"Sistem Bisnis Dynamic\n\
    \n"YELLOW"Command untuk Player:\n\
    "WHITE"- "GREEN"/buybiz "WHITE"- Membeli bisnis yang tidak dimiliki\n\
    - "GREEN"/enter "WHITE"- Masuk ke dalam bisnis\n\
    - "GREEN"/exit "WHITE"- Keluar dari bisnis\n\
    - "GREEN"/bizmenu "WHITE"- Menu pengelolaan bisnis (khusus pemilik)\n\
    - "GREEN"/restockbiz "WHITE"- Restock produk bisnis (khusus pemilik)\n\
    - "GREEN"/buy "WHITE"- Membeli produk di dalam bisnis\n\
    \n"YELLOW"Tipe Bisnis:\n\
    "WHITE"1. "GREEN"Minimarket "WHITE"- Menjual berbagai kebutuhan sehari-hari\n\
    2. "GREEN"Clothes Shop "WHITE"- Menjual pakaian dan aksesoris\n\
    3. "GREEN"Electronic Shop "WHITE"- Menjual barang elektronik\n\
    4. "GREEN"Ammunation "WHITE"- Menjual senjata dan amunisi\n\
    \n"YELLOW"Informasi:\n\
    "WHITE"- Setiap bisnis memiliki "GREEN"Biz Point "WHITE"untuk melakukan pembelian\n\
    - Tekan "GREEN"Y "WHITE"di dekat Biz Point untuk membeli produk\n\
    - Harga restock per stok adalah "GREEN"$15.00\n\
    - Maksimal stok per produk adalah "GREEN"1000\n\
    - Biaya masuk maksimal "GREEN"$50\n\
    \n"YELLOW"Tips:\n\
    "WHITE"- Gunakan "GREEN"/gotobiz "WHITE"untuk teleport ke bisnis (Admin)\n\
    - Gunakan "GREEN"/editbiz "WHITE"untuk mengedit bisnis (Admin)");
    Dialog_Show(playerid, "BizHelp", DIALOG_STYLE_MSGBOX, ""Nexston"Nexston Roleplay "WHITE"- Bantuan Bisnis", string, "Tutup", "");
    return 1;
}


YCMD:buybiz(playerid, params[], help)
{
    new bizid = Biz_Nearest(playerid);
    if(bizid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan bisnis manapun!");
    if(!isnull(BizData[bizid][bizOwnerName])) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini sudah dimiliki seseorang!");
    if(Player_BizCount(playerid) > 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memiliki bisnis!");
    if(AccountData[playerid][pMoney] < BizData[bizid][bizPrice]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

    TakePlayerMoneyEx(playerid, BizData[bizid][bizPrice]);
    BizData[bizid][bizOwnerID] = AccountData[playerid][pID];
    strcopy(BizData[bizid][bizOwnerName], AccountData[playerid][pName]);
    BizData[bizid][bizMoney] = 0;

    Biz_Save(bizid);
    Biz_Refresh(bizid);
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli bisnis ini!");
    SendClientMessageEx(playerid, Y_SERVER, "Gunakan "RED"/bizhelp "WHITE"untuk melihat informasi detail tentang bisnis");
    return 1;
}