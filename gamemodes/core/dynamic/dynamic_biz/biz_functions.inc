#include <YSI_Coding\y_hooks>

//----- Nearest Fuel Station (Bisnis Type 6) -----
FuelStation_Nearest(playerid)
{
    foreach(new bizid : Bizes)
    {
        if(BizData[bizid][bizType] == 6)
        {
            if(IsPlayerInRangeOfPoint(playerid, 2.0, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]))
            {
                return bizid;
            }
        }
    }
    return -1;
}
ShowAllBizListGPS(playerid)
{
    new count;
    new biz_string[2048];
    format(biz_string, sizeof(biz_string), "Nama Bisnis\tType\tJarak\n");
    
    foreach(new bizid : Bizes)
    {
        if(BizData[bizid][bizExtInt] == 0 && BizData[bizid][bizExtVw] == 0)
        {
            new type_name[16];
            switch(BizData[bizid][bizType])
            {
                case 1: type_name = "Minimarket";
                case 2: type_name = "Clothes";
                case 3: type_name = "Electronic";
                case 4: type_name = "Ammunation";
                case 5: type_name = "Bar";
                case 6: type_name = "Pom Bensin";
                default: type_name = "Unknown";
            }
            
            new Float:distance = GetPlayerDistanceFromPoint(playerid, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
            
            if(count % 2 == 0)
            {
                format(biz_string, sizeof(biz_string), "%s"WHITE"%s\t"WHITE"%s\t"YELLOW"%.0f m\n", 
                    biz_string, 
                    BizData[bizid][bizName], 
                    type_name, 
                    distance);
            }
            else
            {
                format(biz_string, sizeof(biz_string), "%s"GRAY"%s\t"GRAY"%s\t"YELLOW"%.0f m\n", 
                    biz_string, 
                    BizData[bizid][bizName], 
                    type_name, 
                    distance);
            }
            count++;
            
            if(count >= 50) break;
        }
    }
    
    if(count == 0)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada bisnis yang tersedia!");
        return 1;
    }
    
    SetPVarInt(playerid, "GPSListType", 1);
    Dialog_Show(playerid, "GPSBizList", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- GPS - Business Kota", biz_string, "Pilih", "Kembali");
    return 1;
}

ReturnBizTypeName(bizid)
{
    new typename[24];
    
    if(bizid != -1)
    {
        switch(BizData[bizid][bizType])
        {
            case 1: //minimarket
            {
                strcopy(typename, "[Minimarket]");
            }
            case 2: //clothes
            {
                strcopy(typename, "[Clothes Shop]");
            }
            case 3: //electronic
            {
                strcopy(typename, "[Electronic Shop]");
            }
            case 4: //ammunitions
            {
                strcopy(typename, "[Ammunation]");
            }
            case 5: //bar
            {
                strcopy(typename, "[Bar]");
            }
            case 6: //pom bensin
            {
                strcopy(typename, "[Pom Bensin]");
            }
            default:
            {
                strcopy(typename, "[Unknown]");
            }
        }
    }
    return typename;
}

Biz_Save(bizid)
{
    static dddstr[2800];
    mysql_format(g_SQL, dddstr, sizeof(dddstr), 
        "UPDATE `biz` SET \
        `Name`='%e', `OwnerID`=%d, `OwnerName`='%e', `Locked`=%d, `Money`=%d, `Type`=%d, `Price`=%d, `Fee`=%d, \
        `ProdStock0`=%d, `ProdStock1`=%d, `ProdStock2`=%d, `ProdStock3`=%d, `ProdStock4`=%d, `ProdStock5`=%d, `ProdStock6`=%d, `ProdStock7`=%d, \
        `ProdStock8`=%d, `ProdStock9`=%d, `ProdStock10`=%d, `ProdStock11`=%d, `ProdStock12`=%d, `ProdStock13`=%d, `ProdStock14`=%d, `ProdStock15`=%d, \
        `ProdPrice0`=%d, `ProdPrice1`=%d, `ProdPrice2`=%d, `ProdPrice3`=%d, `ProdPrice4`=%d, `ProdPrice5`=%d, `ProdPrice6`=%d, `ProdPrice7`=%d, \
        `ProdPrice8`=%d, `ProdPrice9`=%d, `ProdPrice10`=%d, `ProdPrice11`=%d, `ProdPrice12`=%d, `ProdPrice13`=%d, `ProdPrice14`=%d, `ProdPrice15`=%d, \
        `ClothesStock0`=%d, `ClothesStock1`=%d, `ClothesStock2`=%d, `ClothesStock3`=%d, `ClothesStock4`=%d, \
        `ClothesPrice0`=%d, `ClothesPrice1`=%d, `ClothesPrice2`=%d, `ClothesPrice3`=%d, `ClothesPrice4`=%d, \
        `X`='%f', `Y`='%f', `Z`='%f', `A`='%f', `IntX`='%f', `IntY`='%f', `IntZ`='%f', `IntA`='%f', \
        `ExtVw`=%d, `ExtInt`=%d, `IntVw`=%d, `IntInt`=%d, \
        `PointX`='%f', `PointY`='%f', `PointZ`='%f', `PointVw`=%d, `PointInt`=%d, \
        `fuel_price`=%d, `fuel_stock`=%d, `jerigen_price`=%d \
        WHERE `ID`=%d", 
        BizData[bizid][bizName], 
        BizData[bizid][bizOwnerID], 
        BizData[bizid][bizOwnerName], 
        BizData[bizid][bizLocked], 
        BizData[bizid][bizMoney], 
        BizData[bizid][bizType],
        BizData[bizid][bizPrice],
        BizData[bizid][bizEnteranceFee],
        // ProdStock 0-15
        BizData[bizid][bizProdStock][0],
        BizData[bizid][bizProdStock][1],
        BizData[bizid][bizProdStock][2],
        BizData[bizid][bizProdStock][3],
        BizData[bizid][bizProdStock][4],
        BizData[bizid][bizProdStock][5],
        BizData[bizid][bizProdStock][6],
        BizData[bizid][bizProdStock][7],
        BizData[bizid][bizProdStock][8],
        BizData[bizid][bizProdStock][9],
        BizData[bizid][bizProdStock][10],
        BizData[bizid][bizProdStock][11],
        BizData[bizid][bizProdStock][12],
        BizData[bizid][bizProdStock][13],
        BizData[bizid][bizProdStock][14],
        BizData[bizid][bizProdStock][15],
        // ProdPrice 0-15
        BizData[bizid][bizProdPrice][0],
        BizData[bizid][bizProdPrice][1],
        BizData[bizid][bizProdPrice][2],
        BizData[bizid][bizProdPrice][3],
        BizData[bizid][bizProdPrice][4],
        BizData[bizid][bizProdPrice][5],
        BizData[bizid][bizProdPrice][6],
        BizData[bizid][bizProdPrice][7],
        BizData[bizid][bizProdPrice][8],
        BizData[bizid][bizProdPrice][9],
        BizData[bizid][bizProdPrice][10],
        BizData[bizid][bizProdPrice][11],
        BizData[bizid][bizProdPrice][12],
        BizData[bizid][bizProdPrice][13],
        BizData[bizid][bizProdPrice][14],
        BizData[bizid][bizProdPrice][15],
        // Clothes Stock 0-4
        BizData[bizid][bizClothesStock][0],
        BizData[bizid][bizClothesStock][1],
        BizData[bizid][bizClothesStock][2],
        BizData[bizid][bizClothesStock][3],
        BizData[bizid][bizClothesStock][4],
        // Clothes Price 0-4
        BizData[bizid][bizClothesPrice][0],
        BizData[bizid][bizClothesPrice][1],
        BizData[bizid][bizClothesPrice][2],
        BizData[bizid][bizClothesPrice][3],
        BizData[bizid][bizClothesPrice][4],
        // Position
        BizData[bizid][bizExtPos][0], 
        BizData[bizid][bizExtPos][1], 
        BizData[bizid][bizExtPos][2], 
        BizData[bizid][bizExtPos][3],
        BizData[bizid][bizIntPos][0],
        BizData[bizid][bizIntPos][1],
        BizData[bizid][bizIntPos][2],
        BizData[bizid][bizIntPos][3],
        BizData[bizid][bizExtVw],
        BizData[bizid][bizExtInt],
        BizData[bizid][bizIntVw],
        BizData[bizid][bizIntInt],
        // Point
        BizData[bizid][bizPointPos][0],
        BizData[bizid][bizPointPos][1],
        BizData[bizid][bizPointPos][2],
        BizData[bizid][bizPointVw],
        BizData[bizid][bizPointInt],
        // Fuel
        BizData[bizid][bizFuelPrice],
        BizData[bizid][bizFuelStock],
        BizData[bizid][bizJerigenPrice],
        bizid);
    mysql_pquery(g_SQL, dddstr);
    return 1;
}

Biz_Rebuild(bizid)
{
    if(bizid != -1)
    {
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizLabel]))
            BizData[bizid][bizLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        
        if(DestroyDynamicPickup(BizData[bizid][bizPickup]))
            BizData[bizid][bizPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
            
        if(DestroyDynamicPickup(BizData[bizid][bizPointPickup]))
            BizData[bizid][bizPointPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
            
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizPointLabel]))
            BizData[bizid][bizPointLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        
        if(DestroyDynamicArea(BizData[bizid][bizFuelArea]))
            BizData[bizid][bizFuelArea] = STREAMER_TAG_AREA: INVALID_STREAMER_ID;

        if(DestroyDynamicPickup(BizData[bizid][bizFuelPickup]))
            BizData[bizid][bizFuelPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

        new sjws[525];
        
        //----- KHUSUS POM BENSIN TYPE 6 -----
        if(BizData[bizid][bizType] == 6)
        {
            if(isnull(BizData[bizid][bizOwnerName]))
            {
                format(sjws, sizeof(sjws), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'", 
                    BizData[bizid][bizName], 
                    FormatMoney(BizData[bizid][bizPrice]));
            }
            else
            {   
                format(sjws, sizeof(sjws), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"Pemilik: "GREEN"%s\n"WHITE"Harga: "GREEN"%s/liter\n"WHITE"Jerigen: "GREEN"%s\nStok: "YELLOW"%d liter",
                    BizData[bizid][bizName],
                    BizData[bizid][bizOwnerName],
                    FormatMoney(BizData[bizid][bizFuelPrice]),
                    FormatMoney(BizData[bizid][bizJerigenPrice]),
                    BizData[bizid][bizFuelStock]);
            }
            
            // //----- BUAT AREA & PICKUP KHUSUS FUEL -----
            // BizData[bizid][bizFuelArea] = CreateDynamicSphere(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 5.0, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
            // BizData[bizid][bizFuelPickup] = CreateDynamicPickup(19621, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
        }
        else
        {
            //----- UNTUK BISNIS BIASA (TYPE 1-5) -----
            if(isnull(BizData[bizid][bizOwnerName]))
            {
                format(sjws, sizeof(sjws), "%s\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'\n"WHITE"Enterance Fee $%s\n%s", 
                    ReturnBizTypeName(bizid), 
                    BizData[bizid][bizName], 
                    FormatMoney(BizData[bizid][bizPrice]), 
                    FormatMoney(BizData[bizid][bizEnteranceFee]), 
                    (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            }
            else
            {
                format(sjws, sizeof(sjws), "%s\n"YELLOW"%s\n"WHITE"%s\n%s\n"WHITE"Enterance Fee $%s\n%s", 
                    ReturnBizTypeName(bizid), 
                    BizData[bizid][bizName], 
                    BizData[bizid][bizOwnerName], 
                    GetLocation(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]), 
                    FormatMoney(BizData[bizid][bizEnteranceFee]), 
                    (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            }
        }
        BizData[bizid][bizLabel] = CreateDynamic3DTextLabel(sjws, 0xFFFFFFBF, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 10.00, -1, 0);
        if(BizData[bizid][bizType] == 6)
        {
            BizData[bizid][bizFuelArea] = CreateDynamicSphere(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 5.0, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
            BizData[bizid][bizFuelPickup] = CreateDynamicPickup(19621, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
        }
        else 
        {
            BizData[bizid][bizPickup] = CreateDynamicPickup(19133, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 30.00, -1, 0);
            BizData[bizid][bizPointPickup] = CreateDynamicPickup(1239, 23, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2], BizData[bizid][bizPointVw], BizData[bizid][bizPointInt], -1, 10.00, -1, 0);
            BizData[bizid][bizPointLabel] = CreateDynamic3DTextLabel(""GREEN"[Y] "WHITE"untuk membeli produk\n"YELLOW"Tekan Y di sini", 0x00FF00FF, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2] + 0.5, 5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizPointVw], BizData[bizid][bizPointInt], -1, 10.00, -1, 0);    
        }
    }
    return 1;
}
Biz_Refresh(bizid)
{
    if(bizid != -1)
    {
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizLabel]))
            BizData[bizid][bizLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        
        if(DestroyDynamicPickup(BizData[bizid][bizPickup]))
            BizData[bizid][bizPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
            
        if(DestroyDynamicPickup(BizData[bizid][bizPointPickup]))
            BizData[bizid][bizPointPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
            
        if(DestroyDynamic3DTextLabel(BizData[bizid][bizPointLabel]))
            BizData[bizid][bizPointLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
        
        if(DestroyDynamicArea(BizData[bizid][bizFuelArea]))
            BizData[bizid][bizFuelArea] = STREAMER_TAG_AREA: INVALID_STREAMER_ID;

        if(DestroyDynamicPickup(BizData[bizid][bizFuelPickup]))
            BizData[bizid][bizFuelPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

        new sjws[525];
        
        //----- KHUSUS POM BENSIN TYPE 6 -----
        if(BizData[bizid][bizType] == 6)
        {
            if(isnull(BizData[bizid][bizOwnerName]))
            {
                format(sjws, sizeof(sjws), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'", 
                    BizData[bizid][bizName], 
                    FormatMoney(BizData[bizid][bizPrice]));
            }
            else
            {
                format(sjws, sizeof(sjws), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"Pemilik: "GREEN"%s\n"WHITE"Harga: "GREEN"%s/liter\n"WHITE"Jerigen: "GREEN"%s\nStok: "YELLOW"%d liter",
                    BizData[bizid][bizName],
                    BizData[bizid][bizOwnerName],
                    FormatMoney(BizData[bizid][bizFuelPrice]),
                    FormatMoney(BizData[bizid][bizJerigenPrice]),
                    BizData[bizid][bizFuelStock]);
            }
            
            // //----- BUAT AREA & PICKUP KHUSUS FUEL -----
            // BizData[bizid][bizFuelArea] = CreateDynamicSphere(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 5.0, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
            // BizData[bizid][bizFuelPickup] = CreateDynamicPickup(19621, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
        }
        else
        {
            //----- UNTUK BISNIS BIASA (TYPE 1-5) -----
            if(isnull(BizData[bizid][bizOwnerName]))
            {
                format(sjws, sizeof(sjws), "%s\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'\n"WHITE"Enterance Fee $%s\n%s", 
                    ReturnBizTypeName(bizid), 
                    BizData[bizid][bizName], 
                    FormatMoney(BizData[bizid][bizPrice]), 
                    FormatMoney(BizData[bizid][bizEnteranceFee]), 
                    (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            }
            else
            {
                format(sjws, sizeof(sjws), "%s\n"YELLOW"%s\n"WHITE"%s\n%s\n"WHITE"Enterance Fee $%s\n%s", 
                    ReturnBizTypeName(bizid), 
                    BizData[bizid][bizName], 
                    BizData[bizid][bizOwnerName], 
                    GetLocation(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]), 
                    FormatMoney(BizData[bizid][bizEnteranceFee]), 
                    (BizData[bizid][bizLocked]) ? (""RED"Closed") : (""GREEN"Open"));
            }
        }
        
        BizData[bizid][bizLabel] = CreateDynamic3DTextLabel(sjws, 0xFFFFFFBF, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 10.00, -1, 0);
        if(BizData[bizid][bizType] == 6)
        {
            BizData[bizid][bizFuelArea] = CreateDynamicSphere(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], 5.0, BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
            BizData[bizid][bizFuelPickup] = CreateDynamicPickup(19621, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt]);
        }
        else 
        {
            BizData[bizid][bizPickup] = CreateDynamicPickup(19133, 23, BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2], BizData[bizid][bizExtVw], BizData[bizid][bizExtInt], -1, 30.00, -1, 0);
            BizData[bizid][bizPointPickup] = CreateDynamicPickup(1239, 23, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2], BizData[bizid][bizPointVw], BizData[bizid][bizPointInt], -1, 10.00, -1, 0);
            BizData[bizid][bizPointLabel] = CreateDynamic3DTextLabel(""GREEN"[Y] "WHITE"untuk membeli produk\n"YELLOW"Tekan Y di sini", 0x00FF00FF, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2] + 0.5, 5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, BizData[bizid][bizPointVw], BizData[bizid][bizPointInt], -1, 10.00, -1, 0);
        }
        UpdateDynamic3DTextLabelText(BizData[bizid][bizLabel], 0xFFFFFFBF, sjws);

        Streamer_SetItemPos(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizPointLabel], BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2] + 1.25);
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizPointLabel], E_STREAMER_WORLD_ID, BizData[bizid][bizPointVw]);
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizPointLabel], E_STREAMER_INTERIOR_ID, BizData[bizid][bizPointInt]);

        Streamer_SetItemPos(STREAMER_TYPE_PICKUP, BizData[bizid][bizPointPickup], BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2]);
        Streamer_SetIntData(STREAMER_TYPE_PICKUP, BizData[bizid][bizPointPickup], E_STREAMER_WORLD_ID, BizData[bizid][bizPointVw]);
        Streamer_SetIntData(STREAMER_TYPE_PICKUP, BizData[bizid][bizPointPickup], E_STREAMER_INTERIOR_ID, BizData[bizid][bizPointInt]);

        Streamer_SetItemPos(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizLabel], BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2] + 1.25);
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizLabel], E_STREAMER_WORLD_ID, BizData[bizid][bizExtVw]);
        Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, BizData[bizid][bizLabel], E_STREAMER_INTERIOR_ID, BizData[bizid][bizExtInt]);

        Streamer_SetItemPos(STREAMER_TYPE_PICKUP, BizData[bizid][bizPickup], BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]);
        Streamer_SetIntData(STREAMER_TYPE_PICKUP, BizData[bizid][bizPickup], E_STREAMER_WORLD_ID, BizData[bizid][bizExtVw]);
        Streamer_SetIntData(STREAMER_TYPE_PICKUP, BizData[bizid][bizPickup], E_STREAMER_INTERIOR_ID, BizData[bizid][bizExtInt]);
    }
    return 1;
}

Player_BizCount(playerid)
{
    new counting;
    foreach(new bizid : Bizes)
    {
        if(BizData[bizid][bizOwnerID] == AccountData[playerid][pID])
        {
            counting++;
        }
    }
    return counting;
}

Biz_Nearest(playerid)
{
    foreach(new i : Bizes) if (IsPlayerInRangeOfPoint(playerid, 3.0, BizData[i][bizExtPos][0], BizData[i][bizExtPos][1], BizData[i][bizExtPos][2]))
	{
		if (GetPlayerInterior(playerid) == BizData[i][bizExtInt] && GetPlayerVirtualWorld(playerid) == BizData[i][bizExtVw])
			return i;
	}
	return -1;
}

/*
GetBizNearestFromPlayer(playerid)
{
    foreach(new x : Bizes)
    {
        if(BizData[x][bizExtInt] == 0 && BizData[x][bizExtVw] == 0)
        {
            if(IsPlayerInRangeOfPoint(playerid, 600.0, BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2]))
            {
                if(DestroyDynamicRaceCP(AccountData[playerid][pGPSCP]))
                    AccountData[playerid][pGPSCP] = STREAMER_TAG_RACE_CP: INVALID_STREAMER_ID;

                AccountData[playerid][pUsingGPS] = true;
                AccountData[playerid][pGPSCP] = CreateDynamicRaceCP(1, BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2], BizData[x][bizExtPos][0], BizData[x][bizExtPos][1], BizData[x][bizExtPos][2], 5.0, 0, 0, playerid, 10000.00, -1, 0);
                ShowTDN(playerid, "Please follow the checkpoint in your map!");
                return 1;
            }
        }
    }
    ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada Biz terdekat dari posisi anda!");
    return 1;
}
*/

forward LoadBizes();
public LoadBizes()
{
    new rows = cache_num_rows();
    if(rows)
    {
        new bizid;
        for(new i; i < rows; i++)
        {
            cache_get_value_name_int(i, "ID", bizid);
            cache_get_value_name(i, "Name", BizData[bizid][bizName]);
            cache_get_value_name_int(i, "OwnerID", BizData[bizid][bizOwnerID]);
            cache_get_value_name(i, "OwnerName", BizData[bizid][bizOwnerName]);
            cache_get_value_name_int(i, "Locked", BizData[bizid][bizLocked]);
            cache_get_value_name_int(i, "Money", BizData[bizid][bizMoney]);
            cache_get_value_name_int(i, "Type", BizData[bizid][bizType]);
            cache_get_value_name_int(i, "Price", BizData[bizid][bizPrice]);
            cache_get_value_name_int(i, "Fee", BizData[bizid][bizEnteranceFee]);
            
            // ProdStock 0-15
            cache_get_value_name_int(i, "ProdStock0", BizData[bizid][bizProdStock][0]);
            cache_get_value_name_int(i, "ProdStock1", BizData[bizid][bizProdStock][1]);
            cache_get_value_name_int(i, "ProdStock2", BizData[bizid][bizProdStock][2]);
            cache_get_value_name_int(i, "ProdStock3", BizData[bizid][bizProdStock][3]);
            cache_get_value_name_int(i, "ProdStock4", BizData[bizid][bizProdStock][4]);
            cache_get_value_name_int(i, "ProdStock5", BizData[bizid][bizProdStock][5]);
            cache_get_value_name_int(i, "ProdStock6", BizData[bizid][bizProdStock][6]);
            cache_get_value_name_int(i, "ProdStock7", BizData[bizid][bizProdStock][7]);
            cache_get_value_name_int(i, "ProdStock8", BizData[bizid][bizProdStock][8]);
            cache_get_value_name_int(i, "ProdStock9", BizData[bizid][bizProdStock][9]);
            cache_get_value_name_int(i, "ProdStock10", BizData[bizid][bizProdStock][10]);
            cache_get_value_name_int(i, "ProdStock11", BizData[bizid][bizProdStock][11]);
            cache_get_value_name_int(i, "ProdStock12", BizData[bizid][bizProdStock][12]);
            cache_get_value_name_int(i, "ProdStock13", BizData[bizid][bizProdStock][13]);
            cache_get_value_name_int(i, "ProdStock14", BizData[bizid][bizProdStock][14]);
            cache_get_value_name_int(i, "ProdStock15", BizData[bizid][bizProdStock][15]);
            
            // ProdPrice 0-15
            cache_get_value_name_int(i, "ProdPrice0", BizData[bizid][bizProdPrice][0]);
            cache_get_value_name_int(i, "ProdPrice1", BizData[bizid][bizProdPrice][1]);
            cache_get_value_name_int(i, "ProdPrice2", BizData[bizid][bizProdPrice][2]);
            cache_get_value_name_int(i, "ProdPrice3", BizData[bizid][bizProdPrice][3]);
            cache_get_value_name_int(i, "ProdPrice4", BizData[bizid][bizProdPrice][4]);
            cache_get_value_name_int(i, "ProdPrice5", BizData[bizid][bizProdPrice][5]);
            cache_get_value_name_int(i, "ProdPrice6", BizData[bizid][bizProdPrice][6]);
            cache_get_value_name_int(i, "ProdPrice7", BizData[bizid][bizProdPrice][7]);
            cache_get_value_name_int(i, "ProdPrice8", BizData[bizid][bizProdPrice][8]);
            cache_get_value_name_int(i, "ProdPrice9", BizData[bizid][bizProdPrice][9]);
            cache_get_value_name_int(i, "ProdPrice10", BizData[bizid][bizProdPrice][10]);
            cache_get_value_name_int(i, "ProdPrice11", BizData[bizid][bizProdPrice][11]);
            cache_get_value_name_int(i, "ProdPrice12", BizData[bizid][bizProdPrice][12]);
            cache_get_value_name_int(i, "ProdPrice13", BizData[bizid][bizProdPrice][13]);
            cache_get_value_name_int(i, "ProdPrice14", BizData[bizid][bizProdPrice][14]);
            cache_get_value_name_int(i, "ProdPrice15", BizData[bizid][bizProdPrice][15]);
            
            // Clothes Stock 0-4
            cache_get_value_name_int(i, "ClothesStock0", BizData[bizid][bizClothesStock][0]);
            cache_get_value_name_int(i, "ClothesStock1", BizData[bizid][bizClothesStock][1]);
            cache_get_value_name_int(i, "ClothesStock2", BizData[bizid][bizClothesStock][2]);
            cache_get_value_name_int(i, "ClothesStock3", BizData[bizid][bizClothesStock][3]);
            cache_get_value_name_int(i, "ClothesStock4", BizData[bizid][bizClothesStock][4]);
            
            // Clothes Price 0-4
            cache_get_value_name_int(i, "ClothesPrice0", BizData[bizid][bizClothesPrice][0]);
            cache_get_value_name_int(i, "ClothesPrice1", BizData[bizid][bizClothesPrice][1]);
            cache_get_value_name_int(i, "ClothesPrice2", BizData[bizid][bizClothesPrice][2]);
            cache_get_value_name_int(i, "ClothesPrice3", BizData[bizid][bizClothesPrice][3]);
            cache_get_value_name_int(i, "ClothesPrice4", BizData[bizid][bizClothesPrice][4]);
            
            // Position
            cache_get_value_name_float(i, "X", BizData[bizid][bizExtPos][0]);
            cache_get_value_name_float(i, "Y", BizData[bizid][bizExtPos][1]);
            cache_get_value_name_float(i, "Z", BizData[bizid][bizExtPos][2]);
            cache_get_value_name_float(i, "A", BizData[bizid][bizExtPos][3]);
            cache_get_value_name_float(i, "IntX", BizData[bizid][bizIntPos][0]);
            cache_get_value_name_float(i, "IntY", BizData[bizid][bizIntPos][1]);
            cache_get_value_name_float(i, "IntZ", BizData[bizid][bizIntPos][2]);
            cache_get_value_name_float(i, "IntA", BizData[bizid][bizIntPos][3]);
            cache_get_value_name_int(i, "ExtVw", BizData[bizid][bizExtVw]);
            cache_get_value_name_int(i, "ExtInt", BizData[bizid][bizExtInt]);
            cache_get_value_name_int(i, "IntVw", BizData[bizid][bizIntVw]);
            cache_get_value_name_int(i, "IntInt", BizData[bizid][bizIntInt]);
            
            // Point
            cache_get_value_name_float(i, "PointX", BizData[bizid][bizPointPos][0]);
            cache_get_value_name_float(i, "PointY", BizData[bizid][bizPointPos][1]);
            cache_get_value_name_float(i, "PointZ", BizData[bizid][bizPointPos][2]);
            cache_get_value_name_int(i, "PointVw", BizData[bizid][bizPointVw]);
            cache_get_value_name_int(i, "PointInt", BizData[bizid][bizPointInt]);
            
            //----- LOAD FUEL DATA -----
            cache_get_value_name_int(i, "fuel_price", BizData[bizid][bizFuelPrice]);
            cache_get_value_name_int(i, "fuel_stock", BizData[bizid][bizFuelStock]);
            cache_get_value_name_int(i, "jerigen_price", BizData[bizid][bizJerigenPrice]);
            
            Biz_Rebuild(bizid);
            Iter_Add(Bizes, bizid);
        }
        printf("[Dynamic Biz] Total number of loaded Biz: %d.", rows);
    }
    return 1;
}

forward OnBizCreated(playerid, bizid);
public OnBizCreated(playerid, bizid)
{
    Biz_Save(bizid);

    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s create Biz with ID: %d.", AccountData[playerid][pAdminname], bizid);
    SendClientMessageEx(playerid, Y_SERVER, "Gunakan "RED"/editbiz "GRAY"[bizid] [pointpos] "WHITE"untuk memindahkan posisi point buy product");
    return 1;
}

Dialog:BizBuyProduct(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        static string[512];
        
        // Cek apakah player di dekat Biz Point
        if(!IsPlayerInRangeOfPoint(playerid, 3.0, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2]))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dekat point pembelian!");
        
        switch(BizData[bizid][bizType])
        {
            case 1: // minimarket - 11 items (non-senjata)
            {
                if(listitem < 0 || listitem > 10) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");
                if(BizData[bizid][bizProdStock][listitem] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stock sudah habis!");
                
                new price = BizData[bizid][bizProdPrice][listitem];
                
                switch(listitem)
                {
                    case 0: // Nasi Uduk
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][0]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Nasi Uduk", 2769);
                        ShowItemBox(playerid, "Nasi Uduk", "Received 1x", 2769, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Nasi Uduk!");
                    }
                    case 1: // Air Mineral
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][1]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Air Mineral", 19570);
                        ShowItemBox(playerid, "Air Mineral", "Received 1x", 19570, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Air Mineral!");
                    }
                    case 2: // Skateboard
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][2]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Skateboard", 19878);
                        ShowItemBox(playerid, "Skateboard", "Received 1x", 19878, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Skateboard!");
                    }
                    case 3: // Udud
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][3]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Udud", 19896, 12);
                        ShowItemBox(playerid, "Udud", "Received 12x", 19896, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Udud!");
                    }
                    case 4: // Obeng
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][4]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Obeng", 19627);
                        ShowItemBox(playerid, "Obeng", "Received 1x", 19627, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Obeng!");
                    }
                    case 5: // Pilox
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][5]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Pilox", 365);
                        ShowItemBox(playerid, "Pilox", "Received 1x", 365, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Pilox!");
                    }
                    case 6: // Senter
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][6]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Senter", 18641);
                        ShowItemBox(playerid, "Senter", "Received 1x", 18641, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Senter!");
                    }
                    case 7: // Pancingan
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][7]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Pancingan", 18632);
                        ShowItemBox(playerid, "Pancingan", "Received 1x", 18632, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Pancingan!");
                    }
                    case 8: // Umpan
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][8]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Umpan", 1603, 5);
                        ShowItemBox(playerid, "Umpan", "Received 1x", 1603, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Umpan!");
                    }
                    case 9: // Ember
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][9]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Ember", 19468);
                        ShowItemBox(playerid, "Ember", "Received 1x", 19468, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Ember!");
                    }
                    case 10: // Toolkit
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][10]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Toolkit", 19921);
                        ShowItemBox(playerid, "Toolkit", "Received 1x", 19921, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Toolkit!");
                    }
                }
            }
            case 2: // clothes - panggil menu baju
            {
                ShowClothesBizMenuTD(playerid, bizid);
            }
            case 3: // electronic - 5 items
            {
                if(listitem < 0 || listitem > 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");
                if(BizData[bizid][bizProdStock][listitem] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stock sudah habis!");
                
                new price = BizData[bizid][bizProdPrice][listitem];
                
                switch(listitem)
                {
                    case 0: // Smartphone
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][0]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        mysql_format(g_SQL, string, sizeof(string), "SELECT * FROM `player_phones` WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
                        mysql_pquery(g_SQL, string, "OnPlayerBuySmartphone", "i", playerid);
                        ShowItemBox(playerid, "Smartphone", "Received 1x", 19942, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Smartphone!");
                    }
                    case 1: // Radio
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][1]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        PlayerVoiceData[playerid][pHasRadio] = true;
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Radio!");
                        Inventory_Add(playerid, "Radio", 19942);
                        ShowItemBox(playerid, "Radio", "Received 1x", 19942, 5);
                    }
                    case 2: // Earphone
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][2]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        AccountData[playerid][pEarphone] = true;
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Earphone!");
                        ShowItemBox(playerid, "Earphone", "Received 1x", 19421, 5);
                    }
                    case 3: // Boombox
                    {
                        if(AccountData[playerid][pVIP] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus menjadi donatur!");
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][3]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        AccountData[playerid][pBoombox] = true;
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Boombox!");
                        ShowItemBox(playerid, "Boombox", "Received 1x", 2103, 5);
                    }
                    case 4: // Vape
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][4]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Vape", 19823);
                        ShowItemBox(playerid, "Vape", "Received 1x", 19823, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Vape!");
                    }
                    case 5: // Race Tablet
                    {
                        if(AccountData[playerid][pMoney] < price )  return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][5]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Race Tablet", 19894);
                        ShowItemBox(playerid, "Race Tablet", "Received 1x", 19894, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Race Tablet!");
                    }
                }
            }
            case 4: // ammunations - 9 items (senjata + cangkul)
            {
                if(AccountData[playerid][pFirearmLicTime] == 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Firearm License!");
                
                if(listitem < 0 || listitem > 8) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");
                if(BizData[bizid][bizProdStock][listitem] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stock sudah habis!");
                
                new price = BizData[bizid][bizProdPrice][listitem];
                
                switch(listitem)
                {
                    case 0: // Baseball Bat
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][0]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        GivePlayerWeaponEx(playerid, 5, 1, WEAPON_TYPE_PLAYER);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Baseball Bat!");
                    }
                    case 1: // Knife
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][1]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        GivePlayerWeaponEx(playerid, 4, 1, WEAPON_TYPE_PLAYER);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Knife!");
                    }
                    case 2: // Golf Stick
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][2]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        GivePlayerWeaponEx(playerid, 2, 1, WEAPON_TYPE_PLAYER);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Golf Stick!");
                    }
                    case 3: // Pool Cue
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][3]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        GivePlayerWeaponEx(playerid, 7, 1, WEAPON_TYPE_PLAYER);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Pool Cue!");
                    }
                    case 4: // Hunting Rifle
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][4]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        AccountData[playerid][pHasHuntingRifle] = true;
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Hunting Rifle!");
                    }
                    case 5: // Hunting Ammo
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][5]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Hunt Ammo", 2358, 24);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Hunting Ammo!");
                    }
                    case 6: // Katana
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][6]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        GivePlayerWeaponEx(playerid, 8, 1, WEAPON_TYPE_PLAYER);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Katana!");
                    }
                    case 7: // Cangkul
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][7]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Cangkul", 2228);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Cangkul!");
                    }
                    case 8: // Silenced Pistol
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][8]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        GivePlayerWeaponEx(playerid, 23, 250, WEAPON_TYPE_PLAYER);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Silenced Pistol!");
                    }
                }
            }
            case 5: // Bar - 7 items (minuman alkohol)
            {
                if(listitem < 0 || listitem > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");
                if(BizData[bizid][bizProdStock][listitem] < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stock sudah habis!");
                
                new price = BizData[bizid][bizProdPrice][listitem];
                
                switch(listitem)
                {
                    case 0: // Whiskey Premium
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][0]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Whiskey Premium", 19824, 1);
                        ShowItemBox(playerid, "Whiskey Premium", "Received 1x", 19824, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Whiskey Premium!");
                    }
                    case 1: // Vodka Special
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][1]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Vodka Special", 19823, 1);
                        ShowItemBox(playerid, "Vodka Special", "Received 1x", 19823, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Vodka Special!");
                    }
                    case 2: // Rum Gold
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][2]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Rum Gold", 19820, 1);
                        ShowItemBox(playerid, "Rum Gold", "Received 1x", 19820, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Rum Gold!");
                    }
                    case 3: // Tequila Shot
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][3]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Tequila Shot", 19821, 1);
                        ShowItemBox(playerid, "Tequila Shot", "Received 1x", 19821, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Tequila Shot!");
                    }
                    case 4: // Champagne Deluxe
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][4]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Champagne Deluxe", 19822, 1);
                        ShowItemBox(playerid, "Champagne Deluxe", "Received 1x", 19822, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Champagne Deluxe!");
                    }
                    case 5: // Beer Classic
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][5]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Beer Classic", 1544, 1);
                        ShowItemBox(playerid, "Beer Classic", "Received 1x", 1544, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Beer Classic!");
                    }
                    case 6: // Red Wine Exclusive
                    {
                        if(AccountData[playerid][pMoney] < price) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
                        TakePlayerMoneyEx(playerid, price);
                        BizData[bizid][bizProdStock][6]--;
                        BizData[bizid][bizMoney] += price;
                        Biz_Save(bizid);
                        Inventory_Add(playerid, "Red Wine Exclusive", 1512, 1);
                        ShowItemBox(playerid, "Red Wine Exclusive", "Received 1x", 1512, 5);
                        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membeli Red Wine Exclusive!");
                    }
                }
            }
        }
    }
    return 1;
}

Dialog:BizMenu(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        switch(BizData[bizid][bizType])
        {
            case 1: // Minimarket (11 items)
            {
                if(listitem < 0 || listitem > 14) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Nama Biz
                    {
                        Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", 
                        "Set", "Batal");
                    }
                    case 1: // Profit
                    {
                        Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                    }
                    case 2: // Biaya Masuk
                    {
                        Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                    }
                    case 3: // Harga Nasi Uduk
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Nasi Uduk:", "Set", "Batal");
                    }
                    case 4: // Harga Air Mineral
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Air Mineral:", "Set", "Batal");
                    }
                    case 5: // Harga Skateboard
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Skateboard:", "Set", "Batal");
                    }
                    case 6: // Harga Udud
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Udud:", "Set", "Batal");
                    }
                    case 7: // Harga Obeng
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Obeng:", "Set", "Batal");
                    }
                    case 8: // Harga Pilox
                    {
                        AccountData[playerid][pTempValue] = 5;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Pilox:", "Set", "Batal");
                    }
                    case 9: // Harga Senter
                    {
                        AccountData[playerid][pTempValue] = 6;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Senter:", "Set", "Batal");
                    }
                    case 10: // Harga Pancingan
                    {
                        AccountData[playerid][pTempValue] = 7;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Pancingan:", "Set", "Batal");
                    }
                    case 11: // Harga Umpan
                    {
                        AccountData[playerid][pTempValue] = 8;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Umpan:", "Set", "Batal");
                    }
                    case 12: // Harga Ember
                    {
                        AccountData[playerid][pTempValue] = 9;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Ember:", "Set", "Batal");
                    }
                    case 13: // Harga Toolkit
                    {
                        AccountData[playerid][pTempValue] = 10;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Toolkit:", "Set", "Batal");
                    }
                    case 14: // Status Buka/Tutup
                    {
                        if(BizData[bizid][bizLocked])
                        {
                            BizData[bizid][bizLocked] = false;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                        }
                        else
                        {
                            BizData[bizid][bizLocked] = true;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                        }

                        Biz_Save(bizid);
                        Biz_Refresh(bizid);
                    }
                }
            }
            case 2: // Clothes Shop - 5 kategori dengan harga masing-masing
            {
                if(listitem < 0 || listitem > 7) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Nama Biz
                    {
                        Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", 
                        "Set", "Batal");
                    }
                    case 1: // Profit
                    {
                        Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                    }
                    case 2: // Biaya Masuk
                    {
                        Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                    }
                    case 3: // Harga Pakaian
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizMenuClothesPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk semua pakaian:", "Set", "Batal");
                    }
                    case 4: // Harga Topi/Helm
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizMenuClothesPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk semua topi/helm:", "Set", "Batal");
                    }
                    case 5: // Harga Kacamata
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizMenuClothesPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk semua kacamata:", "Set", "Batal");
                    }
                    case 6: // Harga Aksesoris
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizMenuClothesPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk semua aksesoris:", "Set", "Batal");
                    }
                    case 7: // Harga Tas/Koper
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizMenuClothesPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk semua tas/koper:", "Set", "Batal");
                    }
                    case 8: // Status Buka/Tutup
                    {
                        if(BizData[bizid][bizLocked])
                        {
                            BizData[bizid][bizLocked] = false;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                        }
                        else
                        {
                            BizData[bizid][bizLocked] = true;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                        }
                        Biz_Save(bizid);
                        Biz_Refresh(bizid);
                    }
                }
            }
            
            case 3: // Electronic Shop (5 items)
            {
                if(listitem < 0 || listitem > 9) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Nama Biz
                    {
                        Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", 
                        "Set", "Batal");
                    }
                    case 1: // Profit
                    {
                        Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                    }
                    case 2: // Biaya Masuk
                    {
                        Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                    }
                    case 3: // Harga Smartphone
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Smartphone:", "Set", "Batal");
                    }
                    case 4: // Harga Radio
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Radio:", "Set", "Batal");
                    }
                    case 5: // Harga Earphone
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Earphone:", "Set", "Batal");
                    }
                    case 6: // Harga Boombox
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Boombox:", "Set", "Batal");
                    }
                    case 7: // Harga Vape
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Vape:", "Set", "Batal");
                    }
                    case 8: // Harga Race Tablet
                    {
                        AccountData[playerid][pTempValue] = 5;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Race Tablet:", "Set", "Batal");
                    }
                    case 9: // Status Buka/Tutup
                    {
                        if(BizData[bizid][bizLocked])
                        {
                            BizData[bizid][bizLocked] = false;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                        }
                        else
                        {
                            BizData[bizid][bizLocked] = true;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                        }

                        Biz_Save(bizid);
                        Biz_Refresh(bizid);
                    }
                }
            }
            
            case 4: // Ammunation (9 items)
            {
                if(listitem < 0 || listitem > 12) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Nama Biz
                    {
                        Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", 
                        "Set", "Batal");
                    }
                    case 1: // Profit
                    {
                        Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                    }
                    case 2: // Biaya Masuk
                    {
                        Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                    }
                    case 3: // Harga Baseball Bat
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Baseball Bat:", "Set", "Batal");
                    }
                    case 4: // Harga Knife
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Knife:", "Set", "Batal");
                    }
                    case 5: // Harga Golf Stick
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Golf Stick:", "Set", "Batal");
                    }
                    case 6: // Harga Pool Cue
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Pool Cue:", "Set", "Batal");
                    }
                    case 7: // Harga Hunting Rifle
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Hunting Rifle:", "Set", "Batal");
                    }
                    case 8: // Harga Hunting Ammo
                    {
                        AccountData[playerid][pTempValue] = 5;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Hunting Ammo:", "Set", "Batal");
                    }
                    case 9: // Harga Katana
                    {
                        AccountData[playerid][pTempValue] = 6;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Katana:", "Set", "Batal");
                    }
                    case 10: // Harga Cangkul
                    {
                        AccountData[playerid][pTempValue] = 7;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Cangkul:", "Set", "Batal");
                    }
                    case 11: // Harga Silenced Pistol
                    {
                        AccountData[playerid][pTempValue] = 8;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Silenced Pistol:", "Set", "Batal");
                    }
                    case 12: // Status Buka/Tutup
                    {
                        if(BizData[bizid][bizLocked])
                        {
                            BizData[bizid][bizLocked] = false;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                        }
                        else
                        {
                            BizData[bizid][bizLocked] = true;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                        }

                        Biz_Save(bizid);
                        Biz_Refresh(bizid);
                    }
                }
            }
            case 5: // Bar
            {
                if(listitem < 0 || listitem > 11) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Nama Biz
                    {
                        Dialog_Show(playerid, "BizMenuName", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Nama Biz", "Mohon masukkan nama untuk biz milikmu:", "Set", "Batal");
                    }
                    case 1: // Profit
                    {
                        Dialog_Show(playerid, "BizMenuProfit", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Profit Biz", "Mohon masukkan berapa jumlah yang ingin ditarik:", "Tarik", "Batal");
                    }
                    case 2: // Biaya Masuk
                    {
                        Dialog_Show(playerid, "BizMenuEnterance", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Biaya Masuk", "Mohon masukkan berapa biaya masuk ke biz milikmu:", "Set", "Batal");
                    }
                    case 3: // Harga Whiskey Premium
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Whiskey Premium:", "Set", "Batal");
                    }
                    case 4: // Harga Vodka Special
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Vodka Special:", "Set", "Batal");
                    }
                    case 5: // Harga Rum Gold
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Rum Gold:", "Set", "Batal");
                    }
                    case 6: // Harga Tequila Shot
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Tequila Shot:", "Set", "Batal");
                    }
                    case 7: // Harga Champagne Deluxe
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Champagne Deluxe:", "Set", "Batal");
                    }
                    case 8: // Harga Beer Classic
                    {
                        AccountData[playerid][pTempValue] = 5;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Beer Classic:", "Set", "Batal");
                    }
                    case 9: // Harga Red Wine Exclusive
                    {
                        AccountData[playerid][pTempValue] = 6;
                        Dialog_Show(playerid, "BizMenuProduct", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Produk", "Mohon masukkan harga untuk Red Wine Exclusive:", "Set", "Batal");
                    }
                    case 10: // Status Buka/Tutup
                    {
                        if(BizData[bizid][bizLocked])
                        {
                            BizData[bizid][bizLocked] = false;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
                        }
                        else
                        {
                            BizData[bizid][bizLocked] = true;
                            ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
                        }
                        Biz_Save(bizid);
                        Biz_Refresh(bizid);
                    }
                }
            }
        }
    }
    return 1;
}

Dialog:BizMenuFuel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
    
    switch(listitem)
    {
        case 0: // Nama Biz
        {
            Dialog_Show(playerid, "BizMenuNameFuel", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Nama Biz", "Mohon masukkan nama untuk bisnis milikmu:", "Set", "Batal");
        }
        case 1: // Withdraw Kas
        {
            Dialog_Show(playerid, "BizMenuWithdrawFuel", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Profit Biz", sprintf("Kas bisnis kamu: %s\n\nMasukkan jumlah yang ingin ditarik:", FormatMoney(BizData[bizid][bizMoney])), "Tarik", "Batal");
        }
        case 2: // Deposit Kas
        {
            Dialog_Show(playerid, "BizMenuDeposit", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Deposit Kas", sprintf("Uang kamu: %s\n\nMasukkan jumlah yang ingin di deposit:", FormatMoney(AccountData[playerid][pMoney])), "Deposit", "Batal");
        }
        case 3: // Harga BBM
        {
            Dialog_Show(playerid, "BizMenuFuelPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga BBM", sprintf("Harga saat ini: %s/liter\n\nMasukkan harga baru (1-1000):", FormatMoney(BizData[bizid][bizFuelPrice])), "Set", "Batal");
        }
        case 4: // Harga Jerigen
        {
            Dialog_Show(playerid, "BizMenuJerigenPrice", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Harga Jerigen", sprintf("Harga saat ini: %s\n\nMasukkan harga baru (1-100000):", FormatMoney(BizData[bizid][bizJerigenPrice])), "Set", "Batal");
        }
        case 5: // Status Buka/Tutup
        {
            if(BizData[bizid][bizLocked])
            {
                BizData[bizid][bizLocked] = false;
                ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~g~membuka ~w~bisnis ini.");
            }
            else
            {
                BizData[bizid][bizLocked] = true;
                ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah ~r~menutup ~w~bisnis ini.");
            }
            Biz_Save(bizid);
            Biz_Refresh(bizid);
        }
        case 6:
        {
            ShowFuelRestockRequestDialog(playerid, bizid);
        }
    }
    return 1;
}

Dialog:BizMenuNameFuel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;

    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(strlen(inputtext) < 5 || strlen(inputtext) > 25) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nama biz diantara 5 - 25 char!");
    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menggunakan simbol persen!");
        
    strcopy(BizData[bizid][bizName], inputtext);
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengganti nama biz!");

    Biz_Save(bizid);
    Biz_Refresh(bizid);
    return 1;
}

Dialog:BizMenuDeposit(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
    
    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
    
    new amount = strval(inputtext);
    if(amount < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");
    if(amount > AccountData[playerid][pMoney]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
    
    TakePlayerMoneyEx(playerid, amount);
    BizData[bizid][bizMoney] += amount;
    Biz_Save(bizid);
    Biz_Refresh(bizid);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Berhasil deposit "GREEN"%s"WHITE" ke kas bisnis!", FormatMoney(amount)));
    return 1;
}

Dialog:BizMenuFuelPrice(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
    
    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
    
    new price = strval(inputtext);
    if(price < 1 || price > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga harus 1-1000!");
    
    BizData[bizid][bizFuelPrice] = price;
    Biz_Save(bizid);
    Biz_Refresh(bizid);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Harga BBM diubah menjadi "GREEN"%s/liter", FormatMoney(price)));
    return 1;
}

Dialog:BizMenuJerigenPrice(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
    
    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
    
    new price = strval(inputtext);
    if(price < 1 || price > 100000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga harus 1-100000!");
    
    BizData[bizid][bizJerigenPrice] = price;
    Biz_Save(bizid);
    Biz_Refresh(bizid);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Harga Jerigen diubah menjadi "GREEN"%s", FormatMoney(price)));
    return 1;
}

Dialog:BizMenuFuelStock(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
    
    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
    
    new Stock = strval(inputtext);
    if(Stock < 0 || Stock > 50000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Stok harus 0-50000 liter!");
    
    BizData[bizid][bizFuelStock] = Stock;
    Biz_Save(bizid);
    Biz_Refresh(bizid);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Stok BBM diubah menjadi "YELLOW"%d liter", Stock));
    return 1;
}

Dialog:BizMenuWithdrawFuel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;

    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
    if(strval(inputtext) < 1 || strval(inputtext) > BizData[bizid][bizMoney]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

    BizData[bizid][bizMoney] -= strval(inputtext);
    GivePlayerMoneyEx(playerid, strval(inputtext));

    ShowTDN(playerid, NOTIFICATION_INFO, sprintf("Anda mengambil $%s dari bisnis ini!", FormatMoney(strval(inputtext))));

    Biz_Save(bizid);
    Biz_Refresh(bizid);
    return 1;
}
Dialog:BizMenuClothesPrice(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        
        new price = strval(inputtext);
        new category = AccountData[playerid][pTempValue];
        
        if(price < 20) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga minimal adalah $20!");
        if(price > 50000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga maksimal adalah $50.000!");
        
        BizData[bizid][bizClothesPrice][category] = price;
        
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengubah harga produk tersebut!");
        
        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuProduct(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        if(AccountData[playerid][pTempValue] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih apapun!");

        new price = strval(inputtext);
        
        // Minimal harga $20
        if(price < 20) return ShowTDN(playerid, NOTIFICATION_ERROR, "Harga minimal adalah $20!");
        
        // Maksimal harga berdasarkan tipe bisnis
        new max_price;
        switch(BizData[bizid][bizType])
        {
            case 1: max_price = 15000;    // Minimarket (maks $500)
            case 2: max_price = 0;      // Clothes (tidak ada produk)
            case 3: max_price = 20000;   // Electronic (maks $5,000)
            case 4: max_price = 100000;  // Ammunation (maks $50,000)
            case 5: max_price = 50000;  // Bar (maks $50.000)
            default: max_price = 50000;
        }
        
        if(price > max_price) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Harga maksimal untuk bisnis ini adalah $%s!", FormatMoney(max_price)));

        BizData[bizid][bizProdPrice][AccountData[playerid][pTempValue]] = price;

        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengubah harga produk tersebut!");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuName(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(strlen(inputtext) < 5 || strlen(inputtext) > 25) return ShowTDN(playerid, NOTIFICATION_ERROR, "Nama biz diantara 5 - 25 char!");
        if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)  return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menggunakan simbol persen!");
        
        strcopy(BizData[bizid][bizName], inputtext);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengganti nama biz!");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuProfit(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        if(strval(inputtext) < 1 || strval(inputtext) > BizData[bizid][bizMoney]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");

        BizData[bizid][bizMoney] -= strval(inputtext);
        GivePlayerMoneyEx(playerid, strval(inputtext));

        ShowTDN(playerid, NOTIFICATION_INFO, sprintf("Anda mengambil $%s dari bisnis ini!", FormatMoney(strval(inputtext))));

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}

Dialog:BizMenuEnterance(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        
        if(strval(inputtext) < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Biaya tidak valid!");
        if(strval(inputtext) > 50) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat di atas $50!");

        BizData[bizid][bizEnteranceFee] = strval(inputtext);

        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengganti biaya masuk bisnis ini!");

        Biz_Save(bizid);
        Biz_Refresh(bizid);
    }
    return 1;
}
Dialog:BizRestock(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        switch(BizData[bizid][bizType])
        {
            case 1: // Minimarket (11 items)
            {
                if(listitem < 0 || listitem > 10) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Nasi Uduk
                    {
                        AccountData[playerid][pTempValue] = 0;
                        AccountData[playerid][pTempValue2] = 0; // 0 = regular stock
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 1: // Air Mineral
                    {
                        AccountData[playerid][pTempValue] = 1;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 2: // Skateboard
                    {
                        AccountData[playerid][pTempValue] = 2;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 3: // Udud
                    {
                        AccountData[playerid][pTempValue] = 3;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 4: // Obeng
                    {
                        AccountData[playerid][pTempValue] = 4;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 5: // Pilox
                    {
                        AccountData[playerid][pTempValue] = 5;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 6: // Senter
                    {
                        AccountData[playerid][pTempValue] = 6;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 7: // Pancingan
                    {
                        AccountData[playerid][pTempValue] = 7;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 8: // Umpan
                    {
                        AccountData[playerid][pTempValue] = 8;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 9: // Ember
                    {
                        AccountData[playerid][pTempValue] = 9;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 10: // Toolkit
                    {
                        AccountData[playerid][pTempValue] = 10;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                }
            }
            
            case 2: // Clothes Shop
            {
                if(listitem < 0 || listitem > 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Pakaian
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizRestockClothesConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", 
                            ""WHITE"Masukkan jumlah stok untuk semua pakaian\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 1: // Topi/Helm
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizRestockClothesConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", 
                            ""WHITE"Masukkan jumlah stok untuk semua topi/helm\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 2: // Kacamata
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizRestockClothesConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", 
                            ""WHITE"Masukkan jumlah stok untuk semua kacamata\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 3: // Aksesoris
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizRestockClothesConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", 
                            ""WHITE"Masukkan jumlah stok untuk semua aksesoris\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 4: // Tas/Koper
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizRestockClothesConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", 
                            ""WHITE"Masukkan jumlah stok untuk semua tas/koper\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                }
            }
            
            case 3: // Electronic Shop (5 items)
            {
                if(listitem < 0 || listitem > 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Smartphone
                    {
                        AccountData[playerid][pTempValue] = 0;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 1: // Radio
                    {
                        AccountData[playerid][pTempValue] = 1;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 2: // Earphone
                    {
                        AccountData[playerid][pTempValue] = 2;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 3: // Boombox
                    {
                        AccountData[playerid][pTempValue] = 3;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 4: // Vape
                    {
                        AccountData[playerid][pTempValue] = 4;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 5: // Race Tablet
                    {
                        AccountData[playerid][pTempValue] = 5;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                }
            }
            
            case 4: // Ammunation (9 items)
            {
                if(listitem < 0 || listitem > 8) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Baseball Bat
                    {
                        AccountData[playerid][pTempValue] = 0;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 1: // Knife
                    {
                        AccountData[playerid][pTempValue] = 1;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 2: // Golf Stick
                    {
                        AccountData[playerid][pTempValue] = 2;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 3: // Pool Cue
                    {
                        AccountData[playerid][pTempValue] = 3;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 4: // Hunting Rifle
                    {
                        AccountData[playerid][pTempValue] = 4;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 5: // Hunting Ammo
                    {
                        AccountData[playerid][pTempValue] = 5;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 6: // Katana
                    {
                        AccountData[playerid][pTempValue] = 6;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 7: // Cangkul
                    {
                        AccountData[playerid][pTempValue] = 7;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 8: // Silenced Pistol
                    {
                        AccountData[playerid][pTempValue] = 8;
                        AccountData[playerid][pTempValue2] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", ""WHITE"Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                }
            }
            case 5: // Bar - 7 items
            {
                if(listitem < 0 || listitem > 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih sesuatu!");

                switch(listitem)
                {
                    case 0: // Whiskey Premium
                    {
                        AccountData[playerid][pTempValue] = 0;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 1: // Vodka Special
                    {
                        AccountData[playerid][pTempValue] = 1;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 2: // Rum Gold
                    {
                        AccountData[playerid][pTempValue] = 2;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 3: // Tequila Shot
                    {
                        AccountData[playerid][pTempValue] = 3;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 4: // Champagne Deluxe
                    {
                        AccountData[playerid][pTempValue] = 4;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 5: // Beer Classic
                    {
                        AccountData[playerid][pTempValue] = 5;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                    case 6: // Red Wine Exclusive
                    {
                        AccountData[playerid][pTempValue] = 6;
                        Dialog_Show(playerid, "BizRestockConfirm", DIALOG_STYLE_INPUT, ""Vertex"Vertex Roleplay "WHITE"- Restock Product", "Masukkan jumlah stok yang ingin dibeli\nHarga: "SEAGREEN"$15.00/stok:", "Restock", "Batal");
                    }
                }
            }
        }
    }
    return 1;
}

Dialog:BizRestockConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        if(AccountData[playerid][pTempValue] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih apapun!");
        
        new amount = strval(inputtext);
        if(amount < 1 || amount > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat restock antara 1 - 1000!");
        
        // Cek batas maksimal product ID berdasarkan type
        new max_productid;
        switch(BizData[bizid][bizType])
        {
            case 1: max_productid = 10;  // Minimarket (11 items: 0-10)
            case 2: max_productid = -1;  // Clothes (ga ada regular stock)
            case 3: max_productid = 5;   // Electronic (5 items: 0-5)
            case 4: max_productid = 8;   // Ammunation (9 items: 0-8)
            default: max_productid = -1;
        }
        
        // Untuk clothes shop, handle terpisah
        if(BizData[bizid][bizType] == 2)
        {
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Gunakan menu restock khusus untuk clothes shop!");
        }
        
        if(AccountData[playerid][pTempValue] > max_productid)
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Product ID tidak valid untuk tipe bisnis ini!");
        
        // Cek total stok tidak melebihi batas maksimal 1000
        new total = BizData[bizid][bizProdStock][AccountData[playerid][pTempValue]] + amount;
        if(total > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimal stok produk adalah 1000!");

        new pricing = amount * 1500; // Harga per stok $15.00
        if(AccountData[playerid][pBankMoney] < pricing) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Saldo rekening anda tidak cukup!");

        AccountData[playerid][pBankMoney] -= pricing;
        BizData[bizid][bizProdStock][AccountData[playerid][pTempValue]] += amount;

        Biz_Save(bizid);
        Biz_Refresh(bizid);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil merestok %d item! Uang terpotong $%s dari rekening.", amount, FormatMoney(pricing)));
    }
    return 1;
}

// Dialog khusus untuk restock Clothes Shop
Dialog:BizRestockClothesConfirm(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = AccountData[playerid][pInBiz];
    if(bizid != -1)
    {
        if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
        if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
        
        new amount = strval(inputtext);
        if(amount < 1 || amount > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat restock antara 1 - 1000!");
        
        new category = AccountData[playerid][pTempValue];
        new total_stock = BizData[bizid][bizClothesStock][category] + amount;
        
        if(total_stock > 1000) return ShowTDN(playerid, NOTIFICATION_ERROR, "Maksimal stok produk adalah 1000!");
        
        new pricing = amount * 1500;
        if(AccountData[playerid][pBankMoney] < pricing) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Saldo rekening anda tidak cukup! Butuh $%s", FormatMoney(pricing)));
        
        AccountData[playerid][pBankMoney] -= pricing;
        BizData[bizid][bizClothesStock][category] += amount;
        
        Biz_Save(bizid);
        Biz_Refresh(bizid);
        
        new category_name[32];
        switch(category)
        {
            case 0: category_name = "Pakaian";
            case 1: category_name = "Topi/Helm";
            case 2: category_name = "Kacamata";
            case 3: category_name = "Aksesoris";
            case 4: category_name = "Tas/Koper";
        }
        
        ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Berhasil merestok %d item untuk %s! Uang terpotong $%s dari rekening.", amount, category_name, FormatMoney(pricing)));
    }
    return 1;
}

Dialog:DialogFuelStation(playerid, response, listitem, inputtext[])
{
        if(!response) return 1;
        
        new bizid = FuelStation_Nearest(playerid);
        if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
        
        switch(listitem)
        {
            case 0:
            {
                Dialog_Show(playerid, "DialogRefuel", DIALOG_STYLE_INPUT, "Isi Bensin",sprintf("Harga per liter: %s\nStok: %d liter\n\nMasukkan jumlah liter:", FormatMoney(BizData[bizid][bizFuelPrice]), BizData[bizid][bizFuelStock]),"Isi", "Batal");
            }
            case 1:
            {
                if(GetTotalWeightFloat(playerid) > 50)
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory penuh!");
                    
                if(AccountData[playerid][pMoney] < BizData[bizid][bizJerigenPrice])
                    return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak cukup! Butuh %s", FormatMoney(BizData[bizid][bizJerigenPrice])));
                
                if(BizData[bizid][bizFuelStock] < 1)
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Stok jerigen habis!");
                
                TakePlayerMoneyEx(playerid, BizData[bizid][bizJerigenPrice]);
                BizData[bizid][bizFuelStock]--;
                BizData[bizid][bizMoney] += BizData[bizid][bizJerigenPrice];
                Biz_Save(bizid);
                
                Inventory_Add(playerid, "Jerigen", 1650, 1);
                ShowItemBox(playerid, "Jerigen", "Received 1x", 1650, 5);
                ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Berhasil membeli jerigen seharga %s", FormatMoney(BizData[bizid][bizJerigenPrice])));
            }
        }
        return 1;
}


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(!AccountData[playerid][pKnockdown])
		{
            foreach(new bizid : Bizes)
            {
                if(IsPlayerInRangeOfPoint(playerid, 2.0, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2]))
                {
                    if(AccountData[playerid][pInBiz] != bizid) 
                        return 1;
                    
                    if(BizData[bizid][bizLocked]) 
                        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini sedang tutup!");
                    
                    switch(BizData[bizid][bizType])
                    {
                        case 1: // minimarket - 11 items (non-senjata)
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
                            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Minimarket", haji, "Buy", "Batal");
                        }
                        case 2: // clothes
                        {
                            ShowClothesBizMenuTD(playerid, bizid);
                        }
                        case 3: // electronic - 5 items
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
                            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Electronic Shop", haji, "Buy", "Batal");
                        }
                        case 4: // ammunations - 9 items (senjata + cangkul)
                        {
                            if(AccountData[playerid][pFirearmLicTime] == 0) 
                                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Firearm License!");
                            
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
                            FormatMoney(BizData[bizid][bizProdPrice][7]),  // Cangkul
                            FormatMoney(BizData[bizid][bizProdPrice][8])); // Silenced Pistol
                            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Ammunation", haji, "Buy", "Batal");
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
                            Dialog_Show(playerid, "BizBuyProduct", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Bar", haji, "Buy", "Batal");
                        }
                    }
                    return 1;
                }
            }
        }
    }
    if(newkeys & KEY_YES && AccountData[playerid][pDuringRefueling])
    {
        CancelRefuel(playerid);
        ShowTDN(playerid, NOTIFICATION_WARNING, "Pengisian BBM dibatalkan!");
        return 1;
    }
    if(newkeys & KEY_YES)
    {
        new fuelid = FuelStation_Nearest(playerid);
        if(fuelid != -1)
        {
            Dialog_Show(playerid, "DialogFuelStation", DIALOG_STYLE_LIST, "Pom Bensin","Isi Bensin Kendaraan\nBeli Jerigen", "Pilih", "Batal");
        }
    }
    return 1;
}

Dialog:DialogRefuel(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;
    
    new bizid = FuelStation_Nearest(playerid);
    if(bizid == -1 || BizData[bizid][bizType] != 6) return 1;
    
    new liter = strval(inputtext);
    if(liter < 1 || liter > 100) return ShowTDN(playerid, NOTIFICATION_ERROR, "Liter harus 1-100!");
    if(liter > BizData[bizid][bizFuelStock]) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Stok tidak cukup! (Stok: %d liter)", BizData[bizid][bizFuelStock]));
    
    // Cari kendaraan terdekat
    new vehicleid = GetNearestVehicleToPlayer(playerid, 4.0, false);
    if(vehicleid == INVALID_VEHICLE_ID) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan di dekat anda!");
    if(GetEngineStatus(vehicleid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus mematikan mesin terlebih dahulu!");
    if(AccountData[playerid][pHoldingFuelCan]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Simpan jerigen terlebih dahulu!");
    
    new currentFuel = VehicleCore[vehicleid][vCoreFuel];
    if(currentFuel >= 100) return ShowTDN(playerid, NOTIFICATION_ERROR, "Bahan bakar kendaraan anda masih penuh!");
    
    new maxCanFill = 100 - currentFuel;
    if(liter > maxCanFill) liter = maxCanFill;
    
    new totalCost = liter * BizData[bizid][bizFuelPrice];
    if(AccountData[playerid][pMoney] < totalCost) return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak cukup! Butuh %s", FormatMoney(totalCost)));
    
    // Simpan data
    AccountData[playerid][pRefuelingAmount] = liter;
    AccountData[playerid][pRefuelingTotalCost] = totalCost;
    AccountData[playerid][pRefuelingVehicle] = vehicleid;
    AccountData[playerid][pRefuelingBizID] = bizid;
    AccountData[playerid][pRefuelingPrice] = 0;
    AccountData[playerid][pRefuelingFilled] = 0;  // Track liter yang sudah terisi
    AccountData[playerid][pRefuelingTimerBiz] = true;
    
    // Mulai proses pengisian
    AccountData[playerid][pDuringRefueling] = true;
    ApplyAnimation(playerid, "CAMERA", "camstnd_lkabt", 4.33, true, false, false, false, 0, true);
    
    // Update label pump
    new gplstr[128];
    format(gplstr, sizeof(gplstr), "Tekan "GREEN"Y "WHITE"untuk membatalkan\nMengisi: 0/%d liter\nHarga: "DARKGREEN"%s", liter, FormatMoney(totalCost));
    
    new gp = FuelStation_Nearest(playerid);
    if(gp != -1)
    {
        if(IsValidDynamic3DTextLabel(g_GasPumpLabel[playerid][gp]))
            UpdateDynamic3DTextLabelText(g_GasPumpLabel[playerid][gp], Y_WHITE, gplstr);
        else
            g_GasPumpLabel[playerid][gp] = CreateDynamic3DTextLabel(gplstr, Y_WHITE, BizData[gp][bizExtPos][0], BizData[gp][bizExtPos][1], BizData[gp][bizExtPos][2] + 0.5, 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, playerid, 5.0);
    }
    
    // Buat progress label di atas kendaraan
    if(IsValidDynamic3DTextLabel(g_GasProgressLabel[playerid]))
        DestroyDynamic3DTextLabel(g_GasProgressLabel[playerid]);
        
    format(gplstr, sizeof(gplstr), "~g~Mengisi BBM...\n~w~%d/%d liter", 0, liter);
    g_GasProgressLabel[playerid] = CreateDynamic3DTextLabel(gplstr, Y_WHITE, 0.0, 0.0, 1.2, 5.0, INVALID_PLAYER_ID, vehicleid, 0, 0, 0, -1, 5.0);
    
    Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);
    PlayerPlaySound(playerid, 4203, 0.0, 0.0, 0.0);
    return 1;
}

ptask UpdateRefuil[1000](playerid)
{
    if(AccountData[playerid][pRefuelingTimerBiz])
    {
        if(!IsPlayerConnected(playerid)) 
        {
            CancelRefuel(playerid);
            return 0;
        }

        new vehicleid = AccountData[playerid][pRefuelingVehicle];
        new totalLiter = AccountData[playerid][pRefuelingAmount];
        new bizid = AccountData[playerid][pRefuelingBizID];
        new filled = AccountData[playerid][pRefuelingFilled];
        
        // Cek apakah kendaraan masih ada dan player masih dekat
        if(!IsValidVehicle(vehicleid))
        {
            CancelRefuel(playerid);
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan tidak valid!");
        }
        
        new Float:x, Float:y, Float:z;
        GetVehiclePos(vehicleid, x, y, z);
        if(!IsPlayerInRangeOfPoint(playerid, 5.0, x, y, z))
        {
            CancelRefuel(playerid);
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda terlalu jauh dari kendaraan! Pengisian dibatalkan.");
        }
        
        if(GetEngineStatus(vehicleid))
        {
            CancelRefuel(playerid);
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus mematikan mesin terlebih dahulu!");
        }
        
        if(AccountData[playerid][pHoldingFuelCan])
        {
            CancelRefuel(playerid);
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Simpan jerigen terlebih dahulu!");
        }
        
        // Cek stok SPBU
        if(BizData[bizid][bizFuelStock] <= 0)
        {
            CancelRefuel(playerid);
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Stok SPBU habis!");
        }
        
        new perLiterCost = BizData[bizid][bizFuelPrice];
        
        // Isi 1 liter per detik (bukan 2 liter)
        if(filled < totalLiter)
        {
            // Cek uang per liter
            if(AccountData[playerid][pMoney] < perLiterCost)
            {
                CancelRefuel(playerid);
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");
            }
            
            // Ambil uang per liter
            TakePlayerMoneyEx(playerid, perLiterCost);
            AccountData[playerid][pRefuelingPrice] += perLiterCost;
            
            // Update fuel kendaraan
            new currentFuel = VehicleCore[vehicleid][vCoreFuel];
            if(currentFuel < 100)
            {
                new newFuel = currentFuel + 1;
                if(newFuel > 100) newFuel = 100;
                VehicleCore[vehicleid][vCoreFuel] = newFuel;
            }

            BizData[bizid][bizFuelStock]--;
            BizData[bizid][bizMoney] += perLiterCost;
            Biz_Save(bizid);
            Biz_Refresh(bizid);
            
            filled++;
            AccountData[playerid][pRefuelingFilled] = filled;
            
            // Update progress label di atas kendaraan
            new gplstr[128];
            format(gplstr, sizeof(gplstr), "~g~Mengisi BBM...\n~w~%d/%d liter", filled, totalLiter);
            if(IsValidDynamic3DTextLabel(g_GasProgressLabel[playerid]))
                UpdateDynamic3DTextLabelText(g_GasProgressLabel[playerid], Y_WHITE, gplstr);
            
            // Update label pump
            new remainingCost = (totalLiter - filled) * perLiterCost;
            new gp = FuelStation_Nearest(playerid);
            if(gp != -1 && IsValidDynamic3DTextLabel(g_GasPumpLabel[playerid][gp]))
            {
                format(gplstr, sizeof(gplstr), "Tekan "GREEN"Y "WHITE"untuk membatalkan\nMengisi: %d/%d liter\nSisa harga: "DARKGREEN"%s", 
                    filled, totalLiter, FormatMoney(remainingCost));
                UpdateDynamic3DTextLabelText(g_GasPumpLabel[playerid][gp], Y_WHITE, gplstr);
            }
            
            PlayerPlaySound(playerid, 4202, 0.0, 0.0, 0.0);
        }
        
        // Cek apakah sudah selesai
        if(filled >= totalLiter || VehicleCore[vehicleid][vCoreFuel] >= 100)
        {
            new totalFilled = filled;
            new totalCost = AccountData[playerid][pRefuelingPrice];
            
            ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Berhasil mengisi %d liter BBM seharga %s", totalFilled, FormatMoney(totalCost)));
            CancelRefuel(playerid);
        }
    }   
    return 1;
}

stock CancelRefuel(playerid)
{
    new bizid = AccountData[playerid][pRefuelingBizID];
    AccountData[playerid][pDuringRefueling] = false;
    AccountData[playerid][pHoldingFuelCan] = false;
    StopRunningAnimation(playerid);
    
    // Reset label pump
    if(bizid != -1 && BizData[bizid][bizType] == 6)
    {
        new str[525];
        if(isnull(BizData[bizid][bizOwnerName]))
        {
            format(str, sizeof(str), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"$%s\n"YELLOW"'/buybiz'", 
                BizData[bizid][bizName], 
                FormatMoney(BizData[bizid][bizPrice]));
        }
        else
        {
            format(str, sizeof(str), "[POM BENSIN]\n"YELLOW"%s\n"WHITE"Pemilik: "GREEN"%s\n"WHITE"Harga: "GREEN"%s/liter\n"WHITE"Jerigen: "GREEN"%s\nStok: "YELLOW"%d liter",
                BizData[bizid][bizName],
                BizData[bizid][bizOwnerName],
                FormatMoney(BizData[bizid][bizFuelPrice]),
                FormatMoney(BizData[bizid][bizJerigenPrice]),
                BizData[bizid][bizFuelStock]);
        }
        
        if(IsValidDynamic3DTextLabel(g_GasPumpLabel[playerid][bizid]))
            UpdateDynamic3DTextLabelText(g_GasPumpLabel[playerid][bizid], Y_WHITE, str);
    }
    
    // Hapus progress label
    if(IsValidDynamic3DTextLabel(g_GasProgressLabel[playerid]))
    {
        DestroyDynamic3DTextLabel(g_GasProgressLabel[playerid]);
        g_GasProgressLabel[playerid] = STREAMER_TAG_3D_TEXT_LABEL:INVALID_STREAMER_ID;
    }
    
    // Reset variables
    AccountData[playerid][pRefuelingAmount] = 0;
    AccountData[playerid][pRefuelingTotalCost] = 0;
    AccountData[playerid][pRefuelingVehicle] = INVALID_VEHICLE_ID;
    AccountData[playerid][pRefuelingBizID] = -1;
    AccountData[playerid][pRefuelingPrice] = 0;
    AccountData[playerid][pRefuelingFilled] = 0;
    AccountData[playerid][pRefuelingTimerBiz] = false;
    
    return 1;
}