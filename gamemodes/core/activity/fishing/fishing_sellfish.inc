#define MAX_FISH_SELL 2
enum e_FishSellData
{
    sellID,
    Float:sellX,
    Float:sellY,
    Float:sellZ,
    sellVW,
    sellInt,
    STREAMER_TAG_PICKUP:sellPickupID,
    STREAMER_TAG_3D_TEXT_LABEL:sellTextID,
    // Harga per ikan (6 jenis)
    sellPriceIkan,
    sellPricePenyu,
    sellPriceHiu,
    sellPriceLumbaLumba,
    sellPriceUburUbur,
    sellPriceMegalodon
}
new FishSellData[MAX_FISH_SELL][e_FishSellData];
new Iterator:FishSellIterator<MAX_FISH_SELL>;
new g_FishSellCount;

// Load semua fish sell point dari database
forward LoadFishSellPoints();
public LoadFishSellPoints()
{
    new rows = cache_num_rows();
    if(rows)
    {
        for(new i; i < rows; i++)
        {
            cache_get_value_name_int(i, "ID", FishSellData[i][sellID]);
            cache_get_value_name_float(i, "X", FishSellData[i][sellX]);
            cache_get_value_name_float(i, "Y", FishSellData[i][sellY]);
            cache_get_value_name_float(i, "Z", FishSellData[i][sellZ]);
            cache_get_value_name_int(i, "VW", FishSellData[i][sellVW]);
            cache_get_value_name_int(i, "Interior", FishSellData[i][sellInt]);
            
            // Load harga per ikan
            cache_get_value_name_int(i, "PriceIkan", FishSellData[i][sellPriceIkan]);
            cache_get_value_name_int(i, "PricePenyu", FishSellData[i][sellPricePenyu]);
            cache_get_value_name_int(i, "PriceHiu", FishSellData[i][sellPriceHiu]);
            cache_get_value_name_int(i, "PriceLumbaLumba", FishSellData[i][sellPriceLumbaLumba]);
            cache_get_value_name_int(i, "PriceUburUbur", FishSellData[i][sellPriceUburUbur]);
            cache_get_value_name_int(i, "PriceMegalodon", FishSellData[i][sellPriceMegalodon]);
            
            if (DestroyDynamicPickup(FishSellData[i][sellPickupID]))
		        FishSellData[i][sellPickupID] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

            FishSellData[i][sellPickupID] = CreateDynamicPickup(1274, 1, 
                FishSellData[i][sellX], FishSellData[i][sellY], FishSellData[i][sellZ], 
                FishSellData[i][sellVW], FishSellData[i][sellInt]);
            
            UpdateFishSellLabel(i);
            
            Iter_Add(FishSellIterator, i);
            g_FishSellCount++;
        }
        printf("[FISHSELL] Loaded %d fish sell points.", rows);
    }
    return 1;
}

// Update 3D Text Label
UpdateFishSellLabel(id)
{
    new labelStr[512];
    format(labelStr, sizeof(labelStr), 
        ""RED"[Y] "WHITE"JUAL IKAN\n"WHITE\
        "Ikan: "GREEN"$%s\n"\
        ""WHITE"Penyu: "GREEN"$%s\n"\
        ""WHITE"Hiu: "GREEN"$%s\n"\
        ""WHITE"Lumba-lumba: "GREEN"$%s\n"\
        ""WHITE"Ubur-ubur: "GREEN"$%s\n"\
        ""WHITE"Hiu Megalodon: "GREEN"$%s",
        FormatMoney(FishSellData[id][sellPriceIkan]),
        FormatMoney(FishSellData[id][sellPricePenyu]),
        FormatMoney(FishSellData[id][sellPriceHiu]),
        FormatMoney(FishSellData[id][sellPriceLumbaLumba]),
        FormatMoney(FishSellData[id][sellPriceUburUbur]),
        FormatMoney(FishSellData[id][sellPriceMegalodon])
    );

    if (DestroyDynamic3DTextLabel(FishSellData[id][sellTextID]))
		FishSellData[id][sellTextID] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
    
    FishSellData[id][sellTextID] = CreateDynamic3DTextLabel(labelStr, X11_GREEN, 
        FishSellData[id][sellX], FishSellData[id][sellY], FishSellData[id][sellZ] + 0.5, 4.0,
        INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, FishSellData[id][sellVW], FishSellData[id][sellInt]);
}

// Save fish sell point baru
SaveFishSellPoint(playerid, Float:xf, Float:yf, Float:zf)
{
    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "INSERT INTO `fish_sell_points` (`X`, `Y`, `Z`, `VW`, `Interior`, `PriceIkan`, `PricePenyu`, `PriceHiu`, `PriceLumbaLumba`, `PriceUburUbur`, `PriceMegalodon`) VALUES ('%f', '%f', '%f', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d')",
        xf, yf, zf,
        GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid),
        500, 
        1000,
        2000,
        3000, 
        2500, 
        5000  
    );
    mysql_pquery(g_SQL, query, "OnFishSellPointSaved", "i", playerid);
    return 1;
}

// Callback setelah save
forward OnFishSellPointSaved(playerid);
public OnFishSellPointSaved(playerid)
{
    new id = cache_insert_id();
    
    FishSellData[g_FishSellCount][sellID] = id;
    GetPlayerPos(playerid, FishSellData[g_FishSellCount][sellX], FishSellData[g_FishSellCount][sellY], FishSellData[g_FishSellCount][sellZ]);
    FishSellData[g_FishSellCount][sellVW] = GetPlayerVirtualWorld(playerid);
    FishSellData[g_FishSellCount][sellInt] = GetPlayerInterior(playerid);
    
    // Set default prices
    FishSellData[g_FishSellCount][sellPriceIkan] = 500;
    FishSellData[g_FishSellCount][sellPricePenyu] = 1000;
    FishSellData[g_FishSellCount][sellPriceHiu] = 2000;
    FishSellData[g_FishSellCount][sellPriceLumbaLumba] = 3000;
    FishSellData[g_FishSellCount][sellPriceUburUbur] = 2500;
    FishSellData[g_FishSellCount][sellPriceMegalodon] = 5000;
    
    if (DestroyDynamicPickup(FishSellData[g_FishSellCount][sellPickupID]))
		FishSellData[g_FishSellCount][sellPickupID] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    FishSellData[g_FishSellCount][sellPickupID] = CreateDynamicPickup(1274, 1, 
        FishSellData[g_FishSellCount][sellX], FishSellData[g_FishSellCount][sellY], FishSellData[g_FishSellCount][sellZ],
        FishSellData[g_FishSellCount][sellVW], FishSellData[g_FishSellCount][sellInt]);
    
    UpdateFishSellLabel(g_FishSellCount);
    
    Iter_Add(FishSellIterator, g_FishSellCount);
    g_FishSellCount++;
    
    SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] Berhasil membuat tempat jual ikan (ID: %d) - Max 2 location!", id));
    return 1;
}

// Update location fish sell point
UpdateFishSellLocation(id, playerid)
{
    GetPlayerPos(playerid, FishSellData[id][sellX], FishSellData[id][sellY], FishSellData[id][sellZ]);
    FishSellData[id][sellVW] = GetPlayerVirtualWorld(playerid);
    FishSellData[id][sellInt] = GetPlayerInterior(playerid);
    
    // Update pickup
    if (DestroyDynamicPickup(FishSellData[id][sellPickupID]))
		FishSellData[id][sellPickupID] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    FishSellData[id][sellPickupID] = CreateDynamicPickup(1274, 1, 
        FishSellData[id][sellX], FishSellData[id][sellY], FishSellData[id][sellZ],
        FishSellData[id][sellVW], FishSellData[id][sellInt]);
    
    // Update label
    UpdateFishSellLabel(id);
    
    // Update database
    new query[256];
    mysql_format(g_SQL, query, sizeof(query),
        "UPDATE `fish_sell_points` SET `X`='%f', `Y`='%f', `Z`='%f', `VW`=%d, `Interior`=%d WHERE `ID`=%d",
        FishSellData[id][sellX], FishSellData[id][sellY], FishSellData[id][sellZ],
        FishSellData[id][sellVW], FishSellData[id][sellInt], FishSellData[id][sellID]
    );
    mysql_pquery(g_SQL, query);
    
    return 1;
}

// Update price fish sell point
UpdateFishSellPrice(playerid, id, const fishType[], price)
{
    new query[256];
    
    if(strcmp(fishType, "ikan", true) == 0)
    {
        FishSellData[id][sellPriceIkan] = price;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `fish_sell_points` SET `PriceIkan`=%d WHERE `ID`=%d", price, FishSellData[id][sellID]);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Harga Ikan diubah menjadi $%d", id, price));
    }
    else if(strcmp(fishType, "penyu", true) == 0)
    {
        FishSellData[id][sellPricePenyu] = price;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `fish_sell_points` SET `PricePenyu`=%d WHERE `ID`=%d", price, FishSellData[id][sellID]);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Harga Penyu diubah menjadi $%d", id, price));
    }
    else if(strcmp(fishType, "hiu", true) == 0)
    {
        FishSellData[id][sellPriceHiu] = price;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `fish_sell_points` SET `PriceHiu`=%d WHERE `ID`=%d", price, FishSellData[id][sellID]);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Harga Hiu diubah menjadi $%d", id, price));
    }
    else if(strcmp(fishType, "lumba", true) == 0 || strcmp(fishType, "lumbalumba", true) == 0)
    {
        FishSellData[id][sellPriceLumbaLumba] = price;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `fish_sell_points` SET `PriceLumbaLumba`=%d WHERE `ID`=%d", price, FishSellData[id][sellID]);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Harga Lumba-lumba diubah menjadi $%d", id, price));
    }
    else if(strcmp(fishType, "ubur", true) == 0 || strcmp(fishType, "uburubur", true) == 0)
    {
        FishSellData[id][sellPriceUburUbur] = price;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `fish_sell_points` SET `PriceUburUbur`=%d WHERE `ID`=%d", price, FishSellData[id][sellID]);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Harga Ubur-ubur diubah menjadi $%d", id, price));
    }
    else if(strcmp(fishType, "megalodon", true) == 0 || strcmp(fishType, "hiu megalodon", true) == 0)
    {
        FishSellData[id][sellPriceMegalodon] = price;
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `fish_sell_points` SET `PriceMegalodon`=%d WHERE `ID`=%d", price, FishSellData[id][sellID]);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Harga Hiu Megalodon diubah menjadi $%d", id, price));
    }
    else
    {
        return 0;
    }
    
    mysql_pquery(g_SQL, query);
    UpdateFishSellLabel(id);
    return 1;
}

// Delete fish sell point
DeleteFishSellPoint(id)
{
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `fish_sell_points` WHERE `ID`=%d", FishSellData[id][sellID]);
    mysql_pquery(g_SQL, query);
    
    if (DestroyDynamicPickup(FishSellData[id][sellPickupID]))
		FishSellData[id][sellPickupID] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if (DestroyDynamic3DTextLabel(FishSellData[id][sellTextID]))
		FishSellData[id][sellTextID] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
    
    Iter_Remove(FishSellIterator, id);
    g_FishSellCount--;
    
    return 1;
}


// /createfishsell - buat tempat jual ikan baru (max 2 location)
YCMD:createfishsell(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan admin!");
    
    if(g_FishSellCount >= 2) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maaf, maksimal hanya 2 location fish sell point!");
    static Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    SaveFishSellPoint(playerid, x, y, z);
    return 1;
}

YCMD:editfishsell(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan admin!");
    
    new id, type[16], string[64];
    
    if(sscanf(params, "ds[16]S()[64]", id, type, string))
        return SUM(playerid, "/editfishsell [id] [location/price]");
    
    if(!Iter_Contains(FishSellIterator, id)) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "ID fish sell tidak ditemukan!");
    
    if(!strcmp(type, "location", true))
    {
        UpdateFishSellLocation(id, playerid);
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] ID %d: Location dipindahkan!", id));
        return 1;
    }
    
    if(!strcmp(type, "price", true))
    {
        new fishType[32], price;
        
        if(sscanf(string, "s[32]d", fishType, price))
            return SUM(playerid, "/editfishsell [id] price [ikan/penyu/hiu/lumba/ubur/megalodon] [harga]");
        
        if(price < 100 || price > 1000000) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga minimal $100, maksimal $1.000.000!");
        
        if(!UpdateFishSellPrice(playerid, id, fishType, price))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Jenis ikan tidak valid! (ikan/penyu/hiu/lumba/ubur/megalodon)");

        return 1;
    }
    
    SendClientMessage(playerid, X11_RED, "Type: location / price");
    return 1;
}

// /deletefishsell [id]
YCMD:deletefishsell(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan admin!");
    
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, X11_RED, "Usage: /deletefishsell [id]");
    
    if(!Iter_Contains(FishSellIterator, id)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID fish sell tidak ditemukan!");
    
    DeleteFishSellPoint(id);
    
    SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] Berhasil menghapus tempat jual ikan ID: %d", id));
    return 1;
}

// /gotofishsell [id]
YCMD:gotofishsell(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan admin!");
    
    new id;
    if(sscanf(params, "d", id)) return SendClientMessage(playerid, X11_RED, "Usage: /gotofishsell [id]");
    
    if(!Iter_Contains(FishSellIterator, id)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID fish sell tidak ditemukan!");
    
    SetPlayerPos(playerid, FishSellData[id][sellX], FishSellData[id][sellY], FishSellData[id][sellZ] + 1.0);
    SetPlayerVirtualWorld(playerid, FishSellData[id][sellVW]);
    SetPlayerInterior(playerid, FishSellData[id][sellInt]);
    
    SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] Teleport ke fish sell ID %d", id));
    return 1;
}

// /fishselllist - lihat semua fish sell point
YCMD:fishselllist(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan admin!");
    
    new count = 0;
    SendClientMessage(playerid, X11_WHITE, "========== FISH SELL POINTS ==========");
    foreach(new i : FishSellIterator)
    {
        SendClientMessageEx(playerid, X11_YELLOW, 
            sprintf("ID: %d | Location: %.1f, %.1f, %.1f", 
            i, FishSellData[i][sellX], FishSellData[i][sellY], FishSellData[i][sellZ]));
        SendClientMessageEx(playerid, X11_WHITE, 
            sprintf("   Prices: Ikan:$%d | Penyu:$%d | Hiu:$%d | Lumba:$%d | Ubur:$%d | Megalodon:$%d",
            FishSellData[i][sellPriceIkan],
            FishSellData[i][sellPricePenyu],
            FishSellData[i][sellPriceHiu],
            FishSellData[i][sellPriceLumbaLumba],
            FishSellData[i][sellPriceUburUbur],
            FishSellData[i][sellPriceMegalodon]));
        count++;
    }
    if(count == 0) SendClientMessage(playerid, X11_RED, "Belum ada fish sell point!");
    SendClientMessageEx(playerid, X11_WHITE, sprintf("Total: %d/%d points", count, MAX_FISH_SELL));
    return 1;
}

Dialog:DialogSellFish(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        DeletePVar(playerid, "TempFishSellID");
        return 1;
    }
        
    new sellIDF = GetPVarInt(playerid, "TempFishSellID");
    new itemName[32];
    new price;
    new fishType;
        
    switch(listitem)
    {
        case 0: // Ikan
        {
            fishType = 0;
            strcopy(itemName, "Ikan");
            price = FishSellData[sellIDF][sellPriceIkan];
        }
        case 1: // Penyu
        {
            fishType = 1;
            strcopy(itemName, "Penyu");
            price = FishSellData[sellIDF][sellPricePenyu];
        }
        case 2: // Hiu
        {
            fishType = 2;
            strcopy(itemName, "Hiu");
            price = FishSellData[sellIDF][sellPriceHiu];
        }
        case 3: // Lumba-lumba
        {
            fishType = 3;
            strcopy(itemName, "Lumba Lumba");
            price = FishSellData[sellIDF][sellPriceLumbaLumba];
        }
        case 4: // Ubur-ubur
        {
            fishType = 4;
            strcopy(itemName, "Ubur Ubur");
            price = FishSellData[sellIDF][sellPriceUburUbur];
        }
        case 5: // Hiu Megalodon
        {
            fishType = 5;
            strcopy(itemName, "Hiu Megalodon");
            price = FishSellData[sellIDF][sellPriceMegalodon];
        }
    }
    
    if(!PlayerHasItem(playerid, itemName))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Anda tidak memiliki %s untuk dijual!", itemName));
        DeletePVar(playerid, "TempFishSellID");
        return 1;
    }
    
    new count = Inventory_Count(playerid, itemName);
    new totalPrice = count * price;
    
    new dialogStr[256];
    format(dialogStr, sizeof(dialogStr),"Item: "YELLOW"%s\nJumlah: "YELLOW"%d\nHarga per item: "GREEN"$%s\nTotal: "GREEN"$%s\n\nApakah anda ingin menjual semua "YELLOW"%s anda?",
        itemName, count, FormatMoney(price), FormatMoney(totalPrice), itemName);
        
    Dialog_Show(playerid, "DialogSellFishConfirm", DIALOG_STYLE_MSGBOX, "Jual Ikan", dialogStr, "Ya, Jual", "Tidak");
        
    SetPVarInt(playerid, "TempFishSellConfirmID", sellIDF);
    SetPVarInt(playerid, "TempFishSellType", fishType);
    SetPVarInt(playerid, "TempFishSellCount", count);
    SetPVarInt(playerid, "TempFishSellPrice", price);
    return 1;
}

Dialog:DialogSellFishConfirm(playerid, response, listitem, inputtext[])
{
    if(response)
    {
        // new sellID = GetPVarInt(playerid, "TempFishSellConfirmID");
        new fishType = GetPVarInt(playerid, "TempFishSellType");
        new count = GetPVarInt(playerid, "TempFishSellCount");
        new price = GetPVarInt(playerid, "TempFishSellPrice");
        new totalPrice = count * price;
            
        new itemName[32];
        switch(fishType)
        {
            case 0: strcopy(itemName, "Ikan");
            case 1: strcopy(itemName, "Penyu");
            case 2: strcopy(itemName, "Hiu");
            case 3: strcopy(itemName, "Lumba Lumba");
            case 4: strcopy(itemName, "Ubur Ubur");
            case 5: strcopy(itemName, "Hiu Megalodon");
        }
        
        // Hapus item dari inventory
        for(new i; i < count; i++)
            Inventory_Remove(playerid, itemName, 1);
        
        // Kasih uang
        GivePlayerMoneyEx(playerid, totalPrice);
        
        SendClientMessageEx(playerid, X11_GREEN, sprintf("[FISHSELL] Anda menjual %d %s seharga $%d", count, itemName, totalPrice));
        PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
    }
    
    DeletePVar(playerid, "TempFishSellConfirmID");
    DeletePVar(playerid, "TempFishSellType");
    DeletePVar(playerid, "TempFishSellCount");
    DeletePVar(playerid, "TempFishSellPrice");
    DeletePVar(playerid, "TempFishSellID");
    return 1;
}