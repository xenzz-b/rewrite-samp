#include <YSI_Coding\y_hooks>

/*
index setplayerattachedobject
0 = hat /helmet
1 = Kacamata
2 = Aksesoris
3 = Tas/Koper
4 = gun pos
5 = gun pos
6 = gun pos
7 = gun pos
8 = gun pos
9 = kosong
*/

new Male_Skin[] = {1, 2, 3, 4, 5, 6, 7, 8, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 33, 34, 35, 36, 37, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
    51, 52, 57, 58, 59, 60, 61, 62, 66, 67, 68, 72, 73, 78, 79, 80, 81, 82, 83, 84, 86, 94, 95, 96, 97, 98, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 
    110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 132, 133, 134, 135, 136, 137, 142, 143, 144, 146, 147, 149, 153, 154, 155, 
    156, 158, 159, 160, 161, 162, 167, 168, 170, 171, 173, 174, 175, 176, 177, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 200, 202, 203, 204, 206, 208, 
    209, 210, 212, 213, 217, 220, 221, 222, 223, 228, 229, 230, 234, 235, 236, 239, 240, 241, 242, 247, 248, 249, 250, 253, 254, 255, 258, 259, 260, 261, 262, 264, 268, 
    269, 270, 271, 272, 273, 289, 290, 291, 292, 293, 294, 295, 296, 297, 299, 303, 304, 305};

new Female_Skin[] = {9, 10, 11, 12, 13, 31, 38, 39, 40, 41, 53, 54, 55, 56, 63, 64, 65, 69, 75, 76, 77, 85, 88, 89, 90, 91, 93, 129, 130, 131, 138, 140, 141, 145, 148, 
    150, 151, 152, 157, 169, 178, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 201, 205, 207, 211, 214, 215, 216, 219, 224, 225, 226, 231, 232, 233, 237, 238, 243, 244, 
    245, 246, 251, 256, 257, 263, 298};

new Hat_Model[] = {1254, 19517, 19516, 19274, 19518, 19519, 19077, 18640, 1598, 19200, 19141, 18964, 18965, 18966, 19320, 18895, 18901, 18979, 19136, 18978, 18953, 18954, 18961, 18893, 18910, 19114, 19115, 19116, 
    18645, 18977, 19100, 19099, 18897, 18947, 18969, 19137, 18944, 18945, 19068, 18951, 18962, 19066, 19064, 19065, 19528, 19069, 19096, 19098, 18968, 18935, 18934, 18933, 18929, 18926, 18973, 18972, 18971,
    19488, 18967, 18927, 18932, 18950, 18928, 18948, 18946, 18930, 18931, 18949, 2053, 2052, 2054, 19521, 19161, 19520, 19553, 19487, 19352, 19331, 19330, 19558, 19162, 19067, 19160, 18638,
    18639, 19093, 19094, 19095, 19097, 19113, 18891, 18892, 18893, 18896, 18898, 18900, 18902, 18904, 18906, 18907, 18908, 19423, 19424, 18975, 19421, 
    18941, 18942, 18943, 19422, 19163, 18894, 19107, 19106, 18976, 18957, 18903, 18952, 18899, 18636, 19801, 19579};

new Glasses_Model[] = {19085, 19025, 19026, 19031, 19028, 19023, 19010, 19024, 19138, 19007, 19035, 19034, 19033, 19032, 19030, 19029, 19027, 19006, 19014, 19008, 19009, 19011, 19012, 19021, 19013, 19015, 19016, 19017, 19018, 
    19019, 19020, 19139, 19140};

new Accessories_Model[] = {954, 19626, 19054, 19055, 19057, 19058, 19056, 18632, 1485, 902, 19092, 19773, 19555, 19556, 19348, 18634, 18637, 18641, 19777, 1242, 19515, 19904, 19142, 11712, 19847, 19341, 19343, 19344, 19345, 19527, 19578, 
    19590, 2803, 19591, 19039, 19043, 325, 19319, 19317, 19318, 19625, 19038, 19036, 18919, 18912, 18913, 18914, 18915, 18916, 18917, 18918, 18911, 18920, 18974, 19472, 11704, 19037, 19557, 19942, 367, 19623, 336, 
    334, 2045, 321, 322, 19086, 18633, 19079, 339, 18635, 19631, 18642, 19347, 18875, 19627, 18644, 19610, 337, 19622, 19878, 18749, 1608, 19315, 1609, 19833};

new Bag_Model[] = {1279, 19559, 11745, 2919, 1550, 371, 19624, 1210, 11738, 3026};

new idx_itemlistid[MAX_PLAYERS] = 0;
new Float:ClothesBuyA[MAX_PLAYERS];

hook OnPlayerClickTextDraw(playerid, Text:clickedid)
{
    if(clickedid == ClothesShopTD[11])
    {
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        
        idx_itemlistid[playerid] = 0;
        SetPVarInt(playerid, "ClothesShopMode", 0);
        
        if(shop_type == 0) // Shop
        {
            SendClientMessageEx(playerid, Y_SERVER, "Harga: $200");
        }
        else // Bisnis
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            new price = BizData[bizid][bizClothesPrice][0];
            new Stock = BizData[bizid][bizClothesStock][0];
            SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
        }

        switch(AccountData[playerid][pGender])
        {
            case 1: //cowok
            {
                PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Male_Skin) - 1));
                SetPlayerSkin(playerid, Male_Skin[idx_itemlistid[playerid]]);
            }
            case 2: //cewek
            {
                PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Female_Skin) - 1));
                SetPlayerSkin(playerid, Female_Skin[idx_itemlistid[playerid]]);
            }
        }

        ShowClothesBuyClothesTD(playerid);
        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
    }
    // Hat mode
    else if(clickedid == ClothesShopTD[12])
    {
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        
        idx_itemlistid[playerid] = 0;
        SetPVarInt(playerid, "ClothesShopMode", 1);
        
        if(shop_type == 0) // Shop
        {
            SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
        }
        else // Bisnis
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            new price = BizData[bizid][bizClothesPrice][1];
            new Stock = BizData[bizid][bizClothesStock][1];
            SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
        }

        PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Hat_Model) - 1));

        ShowClothesBuyHatTD(playerid);

        SetPlayerAttachedObject(playerid, 0, Hat_Model[idx_itemlistid[playerid]], 2, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
    }
    // Kacamata mode
    else if(clickedid == ClothesShopTD[13])
    {
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        
        idx_itemlistid[playerid] = 0;
        SetPVarInt(playerid, "ClothesShopMode", 2);
        
        if(shop_type == 0) // Shop
        {
            SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
        }
        else // Bisnis
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            new price = BizData[bizid][bizClothesPrice][2];
            new Stock = BizData[bizid][bizClothesStock][2];
            SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
        }

        PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Glasses_Model) - 1));

        ShowClothesBuyGlasesTD(playerid);

        SetPlayerAttachedObject(playerid, 1, Glasses_Model[idx_itemlistid[playerid]], 2, 0.3, 0.0, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
    }
    // Aksesoris mode
    else if(clickedid == ClothesShopTD[14])
    {
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        
        idx_itemlistid[playerid] = 0;
        SetPVarInt(playerid, "ClothesShopMode", 3);
        
        if(shop_type == 0) // Shop
        {
            SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
        }
        else // Bisnis
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            new price = BizData[bizid][bizClothesPrice][3];
            new Stock = BizData[bizid][bizClothesStock][3];
            SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
        }

        PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Accessories_Model) - 1));

        ShowClothesBuyAccessoriesTD(playerid);

        SetPlayerAttachedObject(playerid, 2, Accessories_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
    }
    // Tas/Koper mode
    else if(clickedid == ClothesShopTD[15])
    {
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        
        idx_itemlistid[playerid] = 0;
        SetPVarInt(playerid, "ClothesShopMode", 4);
        
        if(shop_type == 0) // Shop
        {
            SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
        }
        else // Bisnis
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            new price = BizData[bizid][bizClothesPrice][4];
            new Stock = BizData[bizid][bizClothesStock][4];
            SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
        }

        PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Bag_Model) - 1));

        ShowClothesBuyBagTD(playerid);

        SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
    }
    // Next
    else if(clickedid == ClothesShopTD[16])
    {
        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
        
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        new mode = GetPVarInt(playerid, "ClothesShopMode");

        if(mode == 0) //mode beli pakaian
        {
            switch(AccountData[playerid][pGender])
            {
                case 1: //pria
                {
                    if(idx_itemlistid[playerid] < sizeof(Male_Skin) - 1)
                        idx_itemlistid[playerid]++;

                    ApplyAnimation(playerid, "CLOTHES", "CLO_POSE_TORSO", 4.1, false, false, false, false, 0, true);
                    PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Male_Skin) - 1));
                    SetPlayerSkin(playerid, Male_Skin[idx_itemlistid[playerid]]);
                } 
                case 2: //wanita
                {
                    if(idx_itemlistid[playerid] < sizeof(Female_Skin) - 1)
                        idx_itemlistid[playerid]++;

                    ApplyAnimation(playerid, "CLOTHES", "CLO_POSE_TORSO", 4.1, false, false, false, false, 0, true);
                    PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Female_Skin) - 1));
                    SetPlayerSkin(playerid, Female_Skin[idx_itemlistid[playerid]]);
                }
            }
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $200");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][0];
                new Stock = BizData[bizid][bizClothesStock][0];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 1) //mode beli topi/helmet
        {
            if(idx_itemlistid[playerid] < sizeof(Hat_Model) - 1)
                idx_itemlistid[playerid]++;

            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Hat_Model) - 1));
            SetPlayerAttachedObject(playerid, 0, Hat_Model[idx_itemlistid[playerid]], 2, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][1];
                new Stock = BizData[bizid][bizClothesStock][1];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 2) //mode beli kacamata
        {
            if(idx_itemlistid[playerid] < sizeof(Glasses_Model) - 1)
                idx_itemlistid[playerid]++;

            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Glasses_Model) - 1));
            SetPlayerAttachedObject(playerid, 1, Glasses_Model[idx_itemlistid[playerid]], 2, 0.3, 0.0, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][2];
                new Stock = BizData[bizid][bizClothesStock][2];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 3) //mode beli aksesoris
        {
            if(idx_itemlistid[playerid] < sizeof(Accessories_Model) - 1)
                idx_itemlistid[playerid]++;

            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Accessories_Model) - 1));
            SetPlayerAttachedObject(playerid, 2, Accessories_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][3];
                new Stock = BizData[bizid][bizClothesStock][3];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 4) //mode beli tas/koper
        {
            if(idx_itemlistid[playerid] < sizeof(Bag_Model) - 1)
                idx_itemlistid[playerid]++;

            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Bag_Model) - 1));
            
            if(idx_itemlistid[playerid] == 2)
            {
                SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 0.339, 0.123, 0.321, 0, 0);
            }
            else
            {
                SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            }
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][4];
                new Stock = BizData[bizid][bizClothesStock][4];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
    }
    // Prev
    else if(clickedid == ClothesShopTD[17])
    {
        PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
        
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        new mode = GetPVarInt(playerid, "ClothesShopMode");

        if(mode == 0) //mode beli pakaian
        {
            if(idx_itemlistid[playerid] > 0)
                idx_itemlistid[playerid]--;

            switch(AccountData[playerid][pGender])
            {
                case 1: //pria
                {
                    ApplyAnimation(playerid, "CLOTHES", "CLO_POSE_TORSO", 4.1, false, false, false, false, 0, true);

                    PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Male_Skin) - 1));
                    SetPlayerSkin(playerid, Male_Skin[idx_itemlistid[playerid]]);
                } 
                case 2: //wanita
                {
                    ApplyAnimation(playerid, "CLOTHES", "CLO_POSE_TORSO", 4.1, false, false, false, false, 0, true);

                    PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Female_Skin) - 1));
                    SetPlayerSkin(playerid, Female_Skin[idx_itemlistid[playerid]]);
                }
            }
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $200");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][0];
                new Stock = BizData[bizid][bizClothesStock][0];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 1) //mode beli topi/helmet
        {
            if(idx_itemlistid[playerid] > 0)
                idx_itemlistid[playerid]--;
            
            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Hat_Model) - 1));
            SetPlayerAttachedObject(playerid, 0, Hat_Model[idx_itemlistid[playerid]], 2, 0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][1];
                new Stock = BizData[bizid][bizClothesStock][1];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 2) //mode beli kacamata
        {
            if(idx_itemlistid[playerid] > 0)
                idx_itemlistid[playerid]--;
            
            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Glasses_Model) - 1));
            SetPlayerAttachedObject(playerid, 1, Glasses_Model[idx_itemlistid[playerid]], 2, 0.3, 0.0, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][2];
                new Stock = BizData[bizid][bizClothesStock][2];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 3) //mode beli aksesoris
        {
            if(idx_itemlistid[playerid] > 0)
                idx_itemlistid[playerid]--;
            
            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Accessories_Model) - 1));
            SetPlayerAttachedObject(playerid, 2, Accessories_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][3];
                new Stock = BizData[bizid][bizClothesStock][3];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
        else if(mode == 4) //mode beli tas/koper
        {
            if(idx_itemlistid[playerid] > 0)
                idx_itemlistid[playerid]--;
            
            PlayerTextDrawSetString(playerid, ClothesShopIndexTD[playerid], sprintf("%d/%d", idx_itemlistid[playerid], sizeof(Bag_Model) - 1));
            
            if(idx_itemlistid[playerid] == 2)
            {
                SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 0.339, 0.123, 0.321, 0, 0);
            }
            else
            {
                SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            }
            
            if(shop_type == 0) // Shop
            {
                SendClientMessageEx(playerid, Y_SERVER, "Harga: $100");
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                new price = BizData[bizid][bizClothesPrice][4];
                new Stock = BizData[bizid][bizClothesStock][4];
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Harga: $%s | Stock: %d", FormatMoney(price), Stock));
            }
        }
    }
    // Beli
    else if(clickedid == ClothesShopTD[18])
    {
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        new mode = GetPVarInt(playerid, "ClothesShopMode");
        
        if(shop_type == 1) // Bisnis - cek posisi point pembelian
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            if(!IsPlayerInRangeOfPoint(playerid, 3.0, BizData[bizid][bizPointPos][0], BizData[bizid][bizPointPos][1], BizData[bizid][bizPointPos][2]))
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dekat point pembelian!");
                return 1;
            }
        }
        
        if(mode == 0) //mode beli pakaian
        {
            new price, stock_available;
            
            if(shop_type == 0) // Shop
            {
                price = 200;
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                price = BizData[bizid][bizClothesPrice][0];
                stock_available = BizData[bizid][bizClothesStock][0];
                
                if(stock_available < 1) 
                {
                    ShowTDN(playerid, NOTIFICATION_ERROR, "Stock pakaian habis!");
                    return 1;
                }
            }
            
            if(AccountData[playerid][pMoney] < price) 
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak mencukupi ($%s)", FormatMoney(price)));
                return 1;
            }
            
            TakePlayerMoneyEx(playerid, price);
            
            if(shop_type == 1) // Bisnis - kurangi stock
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                BizData[bizid][bizClothesStock][0]--;
                BizData[bizid][bizMoney] += price;
                Biz_Save(bizid);
            }
            
            switch(AccountData[playerid][pGender])
            {
                case 1: //cowo
                {
                    if(idx_itemlistid[playerid] >= sizeof(Male_Skin)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Silakan ulang pemilihan pakaian!");
                    AccountData[playerid][pSkin] = Male_Skin[idx_itemlistid[playerid]];
                }
                case 2: //cewe
                {
                    if(idx_itemlistid[playerid] >= sizeof(Female_Skin)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Silakan ulang pemilihan pakaian!");
                    AccountData[playerid][pSkin] = Female_Skin[idx_itemlistid[playerid]];
                }
            }
            SetPlayerSkin(playerid, AccountData[playerid][pSkin]);

            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda telah membeli pakaian!");
            
            if(shop_type == 1) // Bisnis - tampilkan sisa stock
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Sisa stock: %d", BizData[bizid][bizClothesStock][0]));
            }
        }
        else if(mode == 1) //mode beli hat/helmet
        {
            new price, stock_available;
            
            if(shop_type == 0) // Shop
            {
                price = 100;
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                price = BizData[bizid][bizClothesPrice][1];
                stock_available = BizData[bizid][bizClothesStock][1];
                
                if(stock_available < 1) 
                {
                    ShowTDN(playerid, NOTIFICATION_ERROR, "Stock topi/helm habis!");
                    return 1;
                }
            }
            
            if(AccountData[playerid][pMoney] < price) 
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak mencukupi ($%s)", FormatMoney(price)));
                return 1;
            }

            SetPlayerAttachedObject(playerid, 0, Hat_Model[idx_itemlistid[playerid]], 2, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0, 0);

            TakePlayerMoneyEx(playerid, price);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                BizData[bizid][bizClothesStock][1]--;
                BizData[bizid][bizMoney] += price;
                Biz_Save(bizid);
            }

            SetPVarInt(playerid, "IsPlayerPurchasedToys", 1);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda telah membeli hat/helmet!");

            pToys[playerid][0][toy_model] = Hat_Model[idx_itemlistid[playerid]];
            pToys[playerid][0][toy_bone] = 2;
            pToys[playerid][0][toy_x] = 0.2;
            pToys[playerid][0][toy_y] = 0.0;
            pToys[playerid][0][toy_z] = 0.0;
            pToys[playerid][0][toy_rx] = 0.0;
            pToys[playerid][0][toy_ry] = 0.0;
            pToys[playerid][0][toy_rz] = 0.0;
            pToys[playerid][0][toy_sx] = 1.0;
            pToys[playerid][0][toy_sy] = 1.0;
            pToys[playerid][0][toy_sz] = 1.0;

            SavePlayerToyToDatabase(playerid, 0);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Sisa stock: %d", BizData[bizid][bizClothesStock][1]));
            }
        }
        else if(mode == 2) //mode beli kacamata
        {
            new price, stock_available;
            
            if(shop_type == 0) // Shop
            {
                price = 100;
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                price = BizData[bizid][bizClothesPrice][2];
                stock_available = BizData[bizid][bizClothesStock][2];
                
                if(stock_available < 1) 
                {
                    ShowTDN(playerid, NOTIFICATION_ERROR, "Stock kacamata habis!");
                    return 1;
                }
            }
            
            if(AccountData[playerid][pMoney] < price) 
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak mencukupi ($%s)", FormatMoney(price)));
                return 1;
            }

            SetPlayerAttachedObject(playerid, 1, Glasses_Model[idx_itemlistid[playerid]], 2, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0, 0);

            TakePlayerMoneyEx(playerid, price);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                BizData[bizid][bizClothesStock][2]--;
                BizData[bizid][bizMoney] += price;
                Biz_Save(bizid);
            }

            SetPVarInt(playerid, "IsPlayerPurchasedToys", 2);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda telah membeli kacamata!");

            pToys[playerid][1][toy_model] = Glasses_Model[idx_itemlistid[playerid]];
            pToys[playerid][1][toy_bone] = 2;
            pToys[playerid][1][toy_x] = 0.2;
            pToys[playerid][1][toy_y] = 0.0;
            pToys[playerid][1][toy_z] = 0.0;
            pToys[playerid][1][toy_rx] = 0.0;
            pToys[playerid][1][toy_ry] = 0.0;
            pToys[playerid][1][toy_rz] = 0.0;
            pToys[playerid][1][toy_sx] = 1.0;
            pToys[playerid][1][toy_sy] = 1.0;
            pToys[playerid][1][toy_sz] = 1.0;

            SavePlayerToyToDatabase(playerid, 1);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Sisa stock: %d", BizData[bizid][bizClothesStock][2]));
            }
        }
        else if(mode == 3) //mode beli aksesoris
        {
            new price, stock_available;
            
            if(shop_type == 0) // Shop
            {
                price = 100;
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                price = BizData[bizid][bizClothesPrice][3];
                stock_available = BizData[bizid][bizClothesStock][3];
                
                if(stock_available < 1) 
                {
                    ShowTDN(playerid, NOTIFICATION_ERROR, "Stock aksesoris habis!");
                    return 1;
                }
            }
            
            if(AccountData[playerid][pMoney] < price) 
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak mencukupi ($%s)", FormatMoney(price)));
                return 1;
            }

            SetPlayerAttachedObject(playerid, 2, Accessories_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);

            TakePlayerMoneyEx(playerid, price);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                BizData[bizid][bizClothesStock][3]--;
                BizData[bizid][bizMoney] += price;
                Biz_Save(bizid);
            }

            SetPVarInt(playerid, "IsPlayerPurchasedToys", 3);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda telah membeli aksesoris!");

            pToys[playerid][2][toy_model] = Accessories_Model[idx_itemlistid[playerid]];
            pToys[playerid][2][toy_bone] = 1;
            pToys[playerid][2][toy_x] = 0.2;
            pToys[playerid][2][toy_y] = 0.0;
            pToys[playerid][2][toy_z] = 0.0;
            pToys[playerid][2][toy_rx] = 0.0;
            pToys[playerid][2][toy_ry] = 0.0;
            pToys[playerid][2][toy_rz] = 0.0;
            pToys[playerid][2][toy_sx] = 1.0;
            pToys[playerid][2][toy_sy] = 1.0;
            pToys[playerid][2][toy_sz] = 1.0;

            SavePlayerToyToDatabase(playerid, 2);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Sisa stock: %d", BizData[bizid][bizClothesStock][3]));
            }
        }
        else if(mode == 4) //mode beli tas/koper
        {
            new price, stock_available;
            
            if(shop_type == 0) // Shop
            {
                price = 100;
            }
            else // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                price = BizData[bizid][bizClothesPrice][4];
                stock_available = BizData[bizid][bizClothesStock][4];
                
                if(stock_available < 1) 
                {
                    ShowTDN(playerid, NOTIFICATION_ERROR, "Stock tas/koper habis!");
                    return 1;
                }
            }
            
            if(AccountData[playerid][pMoney] < price) 
            {
                ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Uang tidak mencukupi ($%s)", FormatMoney(price)));
                return 1;
            }

            if(idx_itemlistid[playerid] == 2)
            {
                SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 0.60, 0.40, 0.25, 0, 0);
            }
            else
            {
                SetPlayerAttachedObject(playerid, 3, Bag_Model[idx_itemlistid[playerid]], 1, 0.3, 0.5, 0.0, 90.0, 90.0, 0.0, 1.0, 1.0, 1.0, 0, 0);
            }

            TakePlayerMoneyEx(playerid, price);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                BizData[bizid][bizClothesStock][4]--;
                BizData[bizid][bizMoney] += price;
                Biz_Save(bizid);
            }

            SetPVarInt(playerid, "IsPlayerPurchasedToys", 4);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda telah membeli tas/koper!");

            pToys[playerid][3][toy_model] = Bag_Model[idx_itemlistid[playerid]];
            pToys[playerid][3][toy_bone] = 1;
            pToys[playerid][3][toy_x] = 0.2;
            pToys[playerid][3][toy_y] = 0.0;
            pToys[playerid][3][toy_z] = 0.0;
            pToys[playerid][3][toy_rx] = 0.0;
            pToys[playerid][3][toy_ry] = 0.0;
            pToys[playerid][3][toy_rz] = 0.0;
            pToys[playerid][3][toy_sx] = 1.0;
            pToys[playerid][3][toy_sy] = 1.0;
            pToys[playerid][3][toy_sz] = 1.0;

            SavePlayerToyToDatabase(playerid, 3);
            
            if(shop_type == 1) // Bisnis
            {
                new bizid = GetPVarInt(playerid, "ClothesShopID");
                SendClientMessageEx(playerid, Y_SERVER, sprintf("Sisa stock: %d", BizData[bizid][bizClothesStock][4]));
            }
        }
        DeletePVar(playerid, "ClothesShopMode");
        ApplyAnimation(playerid, "CLOTHES", "CLO_Buy", 4.1, false, false, false, false, 0, true);
    }
    else if(clickedid == ClothesShopTD[19]) //batal
    {
        idx_itemlistid[playerid] = 0;
        HideClothesShopTD(playerid);

        SetCameraBehindPlayer(playerid);
        if(AccountData[playerid][pIsUsingUniform])
		{
			SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
		}
        else
        {
            SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
        }

        DeletePVar(playerid, "ClothesShopMode");      // mode yang dipilih (0-4)
        DeletePVar(playerid, "ClothesShopType");      // 0=shop, 1=bisnis
        DeletePVar(playerid, "ClothesShopID");        // ID bisnis jika type=1
        DeletePVar(playerid, "IsPlayerPurchasedToys");

        PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);

        StopRunningAnimation(playerid);
    }
    else if(clickedid == ClothesShopTD[20]) //rotate +
    {
        GetPlayerFacingAngle(playerid, ClothesBuyA[playerid]);
        SetPlayerFacingAngle(playerid, ClothesBuyA[playerid]+22.5);

        PlayerPlaySound(playerid, 1052, 0.0, 0.0, 0.0);
    }
    else if(clickedid == ClothesShopTD[21]) //rotate -
    {
        GetPlayerFacingAngle(playerid, ClothesBuyA[playerid]);
        SetPlayerFacingAngle(playerid, ClothesBuyA[playerid]-22.5);

        PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);
    }
    else if(clickedid == ClothesShopTD[22]) //kembali
    {
        PlayerPlaySound(playerid, 1053, 0.0, 0.0, 0.0);

        new mode = GetPVarInt(playerid, "ClothesShopMode");
        
        if(mode == 1) //jika mode beli topi
        {
            if(GetPVarInt(playerid, "IsPlayerPurchasedToys") == -1)
            {
                if(pToys[playerid][0][toy_model] == 0)
                {
                    RemovePlayerAttachedObject(playerid, 0);
                }
                else
                {
                    SetPlayerAttachedObject(playerid,
                    0,
                    pToys[playerid][0][toy_model],
                    pToys[playerid][0][toy_bone],
                    pToys[playerid][0][toy_x],
                    pToys[playerid][0][toy_y],
                    pToys[playerid][0][toy_z],
                    pToys[playerid][0][toy_rx],
                    pToys[playerid][0][toy_ry],
                    pToys[playerid][0][toy_rz],
                    pToys[playerid][0][toy_sx],
                    pToys[playerid][0][toy_sy],
                    pToys[playerid][0][toy_sz],
                    pToys[playerid][0][matcolor1][4],
                    pToys[playerid][0][matcolor2][4]);
                }
            }
            else
            {
                SetPlayerAttachedObject(playerid,
                0,
                pToys[playerid][0][toy_model],
                pToys[playerid][0][toy_bone],
                pToys[playerid][0][toy_x],
                pToys[playerid][0][toy_y],
                pToys[playerid][0][toy_z],
                pToys[playerid][0][toy_rx],
                pToys[playerid][0][toy_ry],
                pToys[playerid][0][toy_rz],
                pToys[playerid][0][toy_sx],
                pToys[playerid][0][toy_sy],
                pToys[playerid][0][toy_sz],
                pToys[playerid][0][matcolor1][4],
                pToys[playerid][0][matcolor2][4]);
            }
        }
        else if(mode == 2) //jika mode beli kacamata
        {
            if(GetPVarInt(playerid, "IsPlayerPurchasedToys") == -1)
            {
                if(pToys[playerid][1][toy_model] == 0)
                {
                    RemovePlayerAttachedObject(playerid, 1);
                }
                else
                {
                    SetPlayerAttachedObject(playerid,
                    1,
                    pToys[playerid][1][toy_model],
                    pToys[playerid][1][toy_bone],
                    pToys[playerid][1][toy_x],
                    pToys[playerid][1][toy_y],
                    pToys[playerid][1][toy_z],
                    pToys[playerid][1][toy_rx],
                    pToys[playerid][1][toy_ry],
                    pToys[playerid][1][toy_rz],
                    pToys[playerid][1][toy_sx],
                    pToys[playerid][1][toy_sy],
                    pToys[playerid][1][toy_sz],
                    pToys[playerid][1][matcolor1][4],
                    pToys[playerid][1][matcolor2][4]);
                }
            }
            else
            {
                SetPlayerAttachedObject(playerid,
                1,
                pToys[playerid][1][toy_model],
                pToys[playerid][1][toy_bone],
                pToys[playerid][1][toy_x],
                pToys[playerid][1][toy_y],
                pToys[playerid][1][toy_z],
                pToys[playerid][1][toy_rx],
                pToys[playerid][1][toy_ry],
                pToys[playerid][1][toy_rz],
                pToys[playerid][1][toy_sx],
                pToys[playerid][1][toy_sy],
                pToys[playerid][1][toy_sz],
                pToys[playerid][1][matcolor1][4],
                pToys[playerid][1][matcolor2][4]);
            }
        }
        else if(mode == 3) //jika mode beli aksesoris
        {
            if(GetPVarInt(playerid, "IsPlayerPurchasedToys") == -1)
            {
                if(pToys[playerid][2][toy_model] == 0)
                {
                    RemovePlayerAttachedObject(playerid, 2);
                }
                else
                {
                    SetPlayerAttachedObject(playerid,
                    2,
                    pToys[playerid][2][toy_model],
                    pToys[playerid][2][toy_bone],
                    pToys[playerid][2][toy_x],
                    pToys[playerid][2][toy_y],
                    pToys[playerid][2][toy_z],
                    pToys[playerid][2][toy_rx],
                    pToys[playerid][2][toy_ry],
                    pToys[playerid][2][toy_rz],
                    pToys[playerid][2][toy_sx],
                    pToys[playerid][2][toy_sy],
                    pToys[playerid][2][toy_sz],
                    pToys[playerid][2][matcolor1][4],
                    pToys[playerid][2][matcolor2][4]);
                }
            }
            else
            {
                SetPlayerAttachedObject(playerid,
                2,
                pToys[playerid][2][toy_model],
                pToys[playerid][2][toy_bone],
                pToys[playerid][2][toy_x],
                pToys[playerid][2][toy_y],
                pToys[playerid][2][toy_z],
                pToys[playerid][2][toy_rx],
                pToys[playerid][2][toy_ry],
                pToys[playerid][2][toy_rz],
                pToys[playerid][2][toy_sx],
                pToys[playerid][2][toy_sy],
                pToys[playerid][2][toy_sz],
                pToys[playerid][2][matcolor1][4],
                pToys[playerid][2][matcolor2][4]);
            }
        }
        else if(mode == 4) //jika mode beli tas/koper
        {
            if(GetPVarInt(playerid, "IsPlayerPurchasedToys") == -1)
            {
                if(pToys[playerid][3][toy_model] == 0)
                {
                    RemovePlayerAttachedObject(playerid, 3);
                }
                else
                {
                    SetPlayerAttachedObject(playerid,
                    3,
                    pToys[playerid][3][toy_model],
                    pToys[playerid][3][toy_bone],
                    pToys[playerid][3][toy_x],
                    pToys[playerid][3][toy_y],
                    pToys[playerid][3][toy_z],
                    pToys[playerid][3][toy_rx],
                    pToys[playerid][3][toy_ry],
                    pToys[playerid][3][toy_rz],
                    pToys[playerid][3][toy_sx],
                    pToys[playerid][3][toy_sy],
                    pToys[playerid][3][toy_sz],
                    pToys[playerid][3][matcolor1][4],
                    pToys[playerid][3][matcolor2][4]);
                }
            }
            else
            {
                SetPlayerAttachedObject(playerid,
                3,
                pToys[playerid][3][toy_model],
                pToys[playerid][3][toy_bone],
                pToys[playerid][3][toy_x],
                pToys[playerid][3][toy_y],
                pToys[playerid][3][toy_z],
                pToys[playerid][3][toy_rx],
                pToys[playerid][3][toy_ry],
                pToys[playerid][3][toy_rz],
                pToys[playerid][3][toy_sx],
                pToys[playerid][3][toy_sy],
                pToys[playerid][3][toy_sz],
                pToys[playerid][3][matcolor1][4],
                pToys[playerid][3][matcolor2][4]);
            }
        }

        // Hapus PVar yang tidak perlu
        DeletePVar(playerid, "ClothesShopMode");
        DeletePVar(playerid, "IsPlayerPurchasedToys");
        
        // Sembunyikan semua TextDraw
        HideClothesShopTD(playerid);
        
        // Kembali ke menu utama clothes
        new shop_type = GetPVarInt(playerid, "ClothesShopType");
        
        if(shop_type == 0) // Shop
        {
            ShowClothesShopMenuTD(playerid);
        }
        else // Bisnis
        {
            new bizid = GetPVarInt(playerid, "ClothesShopID");
            ShowClothesBizMenuTD(playerid, bizid);
        }

        // Kembalikan skin player
        if(AccountData[playerid][pIsUsingUniform])
        {
            SetPlayerSkin(playerid, AccountData[playerid][pUniform]);
        }
        else
        {
            SetPlayerSkin(playerid, AccountData[playerid][pSkin]);
        }

        StopRunningAnimation(playerid);
    }
    return 1;
}