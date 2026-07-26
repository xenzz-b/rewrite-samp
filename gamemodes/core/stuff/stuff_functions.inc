#include <YSI_Coding\y_hooks>

#define MAX_LEXIT 1000

new 
    STREAMER_TAG_CP:CarDealerCP,

    STREAMER_TAG_CP:AsuransiCP,

    STREAMER_TAG_AREA:RPSchoolZone,
    STREAMER_TAG_OBJECT:RPSchoolText,

    //bool:g_TailorRightOpen,

    STREAMER_TAG_OBJECT:BankVault,
    STREAMER_TAG_3D_TEXT_LABEL:BankRobStatusLabel,

    STREAMER_TAG_3D_TEXT_LABEL:g_FarmerLabel,
    STREAMER_TAG_3D_TEXT_LABEL:g_ComponentLabel,

    STREAMER_TAG_AREA:BennysLVArea,
    STREAMER_TAG_AREA:DriftKingServiceArea,
    STREAMER_TAG_AREA:JayaAbadiServiceArea,

    STREAMER_TAG_AREA:AirportGreenZone,

    STREAMER_TAG_AREA:FarmingZone1,
    STREAMER_TAG_AREA:FarmingZone2,
    STREAMER_TAG_AREA:FarmingZone3,
    STREAMER_TAG_AREA:FarmingFruitZone,

    STREAMER_TAG_AREA:AreaSantaiZone,
    STREAMER_TAG_AREA:KonserMusicZone,
    STREAMER_TAG_AREA:PDCMusicZone,
    STREAMER_TAG_AREA:BHMSMusicZone,

    STREAMER_TAG_AREA:Miner_TakeStoneArea,
    STREAMER_TAG_AREA:Miner_WashStoneArea,
    STREAMER_TAG_AREA:Miner_SmeltStoneArea,

    STREAMER_TAG_AREA:Butcher_TakeChickArea,
    STREAMER_TAG_AREA:Butcher_CutChickArea,
    STREAMER_TAG_AREA:Butcher_PackChickArea,

    STREAMER_TAG_AREA:Oilman_TakeOilArea[sizeof(__g_OilTakePos)],
    STREAMER_TAG_AREA:Oilman_RefineArea,
    STREAMER_TAG_AREA:Oilman_MixArea,

    STREAMER_TAG_AREA:Fisherman_TakeFish,
    STREAMER_TAG_CP:Fisherman_BoatCP,

    STREAMER_TAG_CP:PelautStartLV,
    STREAMER_TAG_CP:PelautStartLS,

    STREAMER_TAG_AREA:Porter_StartArea,

    STREAMER_TAG_AREA:LumberCutLogArea[sizeof(__g_CutLog)],
    STREAMER_TAG_AREA:LumberPackArea[sizeof(__g_PackLog)],

    STREAMER_TAG_AREA:MilkerProcessArea[sizeof(__g_MilkProcessPos)],

    STREAMER_TAG_AREA:Penjahit_TakeWoolArea,
    STREAMER_TAG_AREA:PenjahitFabricArea[sizeof(__g_MakeFabric)],
    STREAMER_TAG_AREA:PenjahitJahitArea[sizeof(__g_MakeClothes)],

    STREAMER_TAG_OBJECT:LSPDAcademyGate,
    bool:g_LSPDAcademyGateOpened,

    bool:g_DisnakerDoorOpened,
    STREAMER_TAG_AREA:DisnakerDoorSensor,
    STREAMER_TAG_OBJECT:DisnakerDoor,

    bool:g_PringSewuDoorOpened,
    STREAMER_TAG_AREA:PringSewuDoorSensor,
    STREAMER_TAG_OBJECT:PringSewuDoor[2],
    
    bool:g_SriMersingFDoorOpened,
    STREAMER_TAG_AREA:SriMersingFDoorSensor,
    bool:g_SriMersingBDoorOpened,
    STREAMER_TAG_AREA:SriMersingBDoorSensor,
    STREAMER_TAG_OBJECT:SriMersingDoor[4],
    
    bool:g_sBoxDoorOpened,
    STREAMER_TAG_AREA:sBoxDoorSensor,
    STREAMER_TAG_OBJECT:sBoxDoor[2],

    //area billiard
	STREAMER_TAG_AREA:BilliardArea,
    
    bool:g_PenjahitDoorOpened,
    STREAMER_TAG_AREA:PenjahitDoorSensor,
    STREAMER_TAG_OBJECT:PenjahitDoor[2];

//iterators
new 
    Iterator:PeLabelExit<MAX_LEXIT>;

new STREAMER_TAG_3D_TEXT_LABEL:PlayerLabelExit[MAX_LEXIT];

new Float:__g_GasPumpLoc[][3] =
{
    {-1826.1365,135.4456,15.3093},
    {-1827.3057,135.3554,15.3093},
    {1942.0054,-1775.6212,13.3906},
    {1941.9496,-1773.2562,13.3906},
    {1938.9218,-1773.2375,13.3828},
    {1939.0602,-1775.5587,13.3906},
    {656.7482,-570.3331,16.3359},
    {656.7169,-559.6761,16.3359},
    {654.5762,-559.7827,16.3359},
    {654.6103,-570.4913,16.3359},
    {-1610.1063,-2720.4148,48.5391},
    {-1611.0909,-2721.6318,48.5391},
    {-1607.7657,-2717.2554,48.5391},
    {-1606.8579,-2715.9397,48.5391},
    {-1604.4913,-2712.8027,48.5335},
    {-1603.5839,-2711.5012,48.5335},
    {-1601.1996,-2708.3735,48.5391},
    {-1600.2355,-2707.1313,48.5391},
    {-2247.3862,-2559.3633,31.9219},
    {-2245.9978,-2560.0300,31.9219},
    {-2242.4219,-2561.9707,31.9219},
    {-2241.0112,-2562.6003,31.9219},
    {-97.9221,-1173.3942,2.3911},
    {-96.1238,-1174.0770,2.3387},
    {-90.9591,-1176.2719,2.1795},
    {-89.2355,-1176.9580,2.1280},
    {-84.3961,-1165.3840,2.2380},
    {-86.0244,-1164.5387,2.2369},
    {-91.1845,-1162.1592,2.2460},
    {-92.9578,-1161.4288,2.2119},
    {1379.4380,459.7512,19.9839},
    {1383.9420,457.9529,19.9986},
    {1380.1157,461.5264,20.0623},
    {1384.5535,459.4971,20.0624},
    {-2409.3193,970.9178,45.3016},
    {-2409.3760,976.2313,45.2969},
    {-2409.4150,981.6394,45.2969},
    {-2412.4526,981.4411,45.2969},
    {-2412.5876,976.2273,45.2969},
    {-2412.4958,970.7640,45.2969},
    {-1664.6053,416.0013,7.1797},
    {-1669.0374,411.6378,7.1797},
    {-1674.3929,406.3891,7.1797},
    {-1678.4847,402.2149,7.1797},
    {-1680.3030,403.9763,7.1797},
    {-1676.1698,408.1084,7.1797},
    {-1670.6017,413.2598,7.1797},
    {-1666.5291,417.8644,7.1797},
    {-1671.3170,422.6615,7.1797},
    {-1675.6462,418.2252,7.1797},
    {-1680.9011,412.9570,7.1797},
    {-1685.1774,408.8246,7.1797},
    {-1686.8708,410.6203,7.1797},
    {-1682.8536,414.6105,7.1797},
    {-1677.5645,420.0285,7.1797},
    {-1673.0499,424.3636,7.1797},
    {2120.7734,926.5634,10.8203},
    {2114.8333,926.6227,10.8203},
    {2109.0239,926.7670,10.8203},
    {2109.0750,924.2640,10.8203},
    {2114.9360,924.4465,10.8203},
    {2120.8613,924.5010,10.8203},
    {2120.6921,915.7863,10.8203},
    {2114.8677,915.8232,10.8203},
    {2109.0171,915.7261,10.8203},
    {2109.0386,913.3179,10.8203},
    {2114.8779,913.5323,10.8203},
    {2120.8533,913.5173,10.8203},
    {-2025.4119,156.7410,28.8359},
    {-2027.7198,156.7926,28.8359},
    {-737.1257,2743.6580,47.3266},
    {-737.0552,2745.9063,47.3266},
    {75.1046,1218.8502,18.8221},
    {72.4562,1219.6635,18.8183},
    {69.2709,1220.4227,18.8064},
    {66.5878,1221.2931,18.8199},
    {602.9976,1707.8370,7.0922},
    {603.9360,1706.6132,7.0922},
    {606.3970,1703.0121,7.0995},
    {607.3939,1701.4779,7.0922},
    {609.7972,1698.0864,7.0922},
    {610.8420,1696.3627,7.0922},
    {613.2617,1693.1293,7.0922},
    {614.1649,1691.5063,7.0922},
    {616.6318,1688.2274,7.0922},
    {617.7126,1686.6324,7.0922},
    {620.0844,1683.2865,7.0922},
    {621.1713,1681.5356,7.0922},
    {623.5208,1678.4962,7.0922},
    {624.4994,1676.9287,7.0922},
    {1008.8644,-937.3472,42.2797},
    {1006.1509,-937.7299,42.2797},
    {1001.8756,-938.3301,42.2797},
    {999.0380,-938.7355,42.2797},
    {998.6432,-936.3448,42.2797},
    {1001.5916,-935.9311,42.2797},
    {1005.7913,-935.3421,42.2797},
    {1008.5472,-934.9543,42.2797},
    {54.4710,-306.5020,1.6403},
    {54.4650,-312.1057,1.6404},
    {52.1974,-312.1374,1.6975},
    {52.1975,-306.5461,1.6975},
    {2645.2563,1100.3795,10.9609},
    {2639.9265,1100.3806,10.9609},
    {2634.6191,1100.3649,10.9609},
    {2634.6296,1111.1655,10.9609},
    {2639.8420,1111.1700,10.9609},
    {2645.2461,1111.1698,10.9609},
    {-1465.0095,1861.3320,32.6398},
    {-1477.6851,1860.5088,32.6328},
    {-1477.9027,1868.0790,32.6398},
    {-1465.4794,1869.0483,32.6328},
    {-1326.8601,2686.3557,50.0625},
    {-1327.2151,2684.8340,50.0625},
    {-1327.7240,2681.0122,50.0625},
    {-1327.9141,2679.3386,50.0625},
    {-1328.5188,2675.6401,50.0625},
    {-1328.7196,2673.9390,50.0625},
    {-1329.0305,2670.2429,50.0625},
    {-1329.3096,2668.3770,50.0625},
    {1590.3710,2205.6401,10.8203},
    {1596.0963,2205.6367,10.8203},
    {1601.9835,2205.6438,10.8203},
    {1601.9976,2203.3682,10.8203},
    {1596.1243,2203.3672,10.8203},
    {1590.3240,2203.3638,10.8203},
    {1590.3799,2194.8335,10.8203},
    {1596.1210,2194.8337,10.8203},
    {1602.0131,2194.8367,10.8203},
    {1602.0011,2192.5652,10.8203},
    {1596.1174,2192.5640,10.8203},
    {1590.3502,2192.5615,10.8203}
};
new STREAMER_TAG_3D_TEXT_LABEL:g_GasPumpLabel[MAX_PLAYERS][sizeof(__g_GasPumpLoc)];

new Float:BennysLVAreaPoints[] = {
    2862.6,-1824.3,
    2865.0,-1824.3,
    2865.0,-1856.6,
    2860.0,-1856.6
};

new Float:DriftKingServiceAreaPoints[] = {
    1018.6018,-1979.1229,
    1024.5875,-1979.1564,
    1033.0808,-1956.7339,
    1033.2651,-1952.7805
};

new Float:JayaAbadiServiceAreaPoints[] = {
    208.9125,-241.9519,
    217.7594,-242.4603,
    206.8305,-230.9348,
    216.8260,-230.8345
};

new Float:AirportGreenZonePoints[] = {
    1807.6920,-2231.0347,
    1807.6720,-2342.1152,
    1359.0895,-2368.6873,
    1361.4047,-2204.0667
};

new Float:FarmingZone1Points[] = {
    -326.5422,-1312.5914,
    -267.7631,-1310.5787,
    -210.7340,-1308.5919,
    -160.8558,-1299.2610,
    -163.7526,-1330.4385,
    -163.4685,-1342.3496,
    -164.2732,-1368.0691,
    -162.9311,-1392.5737,
    -158.6863,-1416.4041,
    -273.7257,-1433.4932,
    -333.5458,-1433.8040,
    -328.5420,-1374.7395,
    -324.6108,-1345.8428,
    -326.5422,-1312.5914
};

new Float:FarmingZone2Points[] = {
    -336.1881,-1465.8601,
    -274.1329,-1465.8363,
    -242.0341,-1465.9004,
    -210.8846,-1465.7716,
    -210.8239,-1496.3890,
    -210.8122,-1559.4760,
    -273.1469,-1559.6786,
    -305.0318,-1559.7067,
    -333.4580,-1560.8357,
    -338.0981,-1529.1604,
    -338.3006,-1493.3085
};

new Float:FarmingZone3Points[] = {
    -400.4246,-1401.1951,
    -371.7427,-1380.1797,
    -363.0264,-1351.9346,
    -352.5082,-1321.4351,
    -346.8655,-1291.3608,
    -340.6685,-1262.0256,
    -360.4930,-1265.7692,
    -406.6977,-1273.4542,
    -435.5148,-1278.0302,
    -467.6897,-1286.8334,
    -500.2994,-1288.1132,
    -529.2067,-1286.4628,
    -560.7270,-1286.7174,
    -592.1779,-1286.7192,
    -592.2961,-1319.0254,
    -592.2871,-1348.1022,
    -592.2476,-1365.1831,
    -592.2761,-1380.3379,
    -592.2804,-1410.3859,
    -553.5673,-1441.0657,
    -529.2413,-1423.7784,
    -504.7486,-1413.7004,
    -482.6187,-1411.1017,
    -461.8249,-1409.1080,
    -442.4775,-1406.7712,
    -420.3277,-1403.7703
};

new Float:FarmingFruitPoints[] = {
    -277.3616,-1003.1321,
    -245.6616,-971.7176,
    -230.1860,-951.7639,
    -248.0340,-934.8511,
    -277.3081,-908.6822,
    -293.7511,-892.7662,
    -310.8699,-910.7489,
    -331.3307,-931.0640,
    -340.3831,-940.1583,
    -316.2074,-964.5222,
    -300.1815,-980.6424
};

new Float:AreaSantaiZonePoints[] = {
    434.9454,-1975.3125,
    380.6761,-1975.1884,
    380.9133,-1932.6625,
    389.2097,-1932.4968,
    389.2099,-1912.8756,
    435.1371,-1913.0262
};

new Float:KonserZoneMusic[] = {
    1037.8229,-1937.4438,
    1035.2466,-1844.9012,
    990.8073,-1835.3180,
    901.3717,-1819.2495,
    890.7999,-1952.9771
};

new Float:PDCZoneMusic[] = {
    612.1830,-1873.5358,
    626.7588,-1882.2095,
    599.7283,-1881.0978,
    612.1545,-1889.6062
};

// Show All Gas Station List
ShowAllGasListGPS(playerid)
{
    new count;
    new gas_string[2048]; // Kurangi ukuran
    format(gas_string, sizeof(gas_string), "SPBU\tLokasi\tJarak\n");
    
    for(new x; x < sizeof(__g_GasPumpLoc); x++)
    {
        new Float:distance = GetPlayerDistanceFromPoint(playerid, __g_GasPumpLoc[x][0], __g_GasPumpLoc[x][1], __g_GasPumpLoc[x][2]);
        
        if(count % 2 == 0)
        {
            format(gas_string, sizeof(gas_string), "%s"WHITE"SPBU %d\t"WHITE"%s\t"YELLOW"%.0f m\n", 
                gas_string, 
                x + 1, 
                GetLocation(__g_GasPumpLoc[x][0], __g_GasPumpLoc[x][1], __g_GasPumpLoc[x][2]), 
                distance);
        }
        else
        {
            format(gas_string, sizeof(gas_string), "%s"GRAY"SPBU %d\t"GRAY"%s\t"YELLOW"%.0f m\n", 
                gas_string, 
                x + 1, 
                GetLocation(__g_GasPumpLoc[x][0], __g_GasPumpLoc[x][1], __g_GasPumpLoc[x][2]), 
                distance);
        }
        count++;
        
        if(count >= 50) break;
    }
    
    SetPVarInt(playerid, "GPSListType", 3);
    Dialog_Show(playerid, "GPSBizList", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- GPS - SPBU Kota", gas_string, "Pilih", "Kembali");
    return 1;
}

forward ResetLabelExit(LabelExit);
public ResetLabelExit(LabelExit)
{
    if(DestroyDynamic3DTextLabel(PlayerLabelExit[LabelExit]))
        PlayerLabelExit[LabelExit] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
    Iter_Remove(PeLabelExit, LabelExit);
    return 1;
}

static bool:IsFactionItemValid(slot)
{
    new bool:itemExists = false;
    for(new i = 0; i < sizeof(g_aInventoryItems); i++) 
    {
        // Kalau item-nya ada, ganti itemExists
        if(!strcmp(FactionBrankas[slot][factionBrankasTemp], g_aInventoryItems[i][e_InventoryItem], true)) {
            itemExists = true;
            break;
        }
 
        // Nah ini bakal nge-loop terus sampai ketemu si item atau gak sampai
        // size-nya abis. Kenapa? Karena kan si nama item gak selalu ada di
        // index yang lagi di-loop ini, bisa aja di index yang lain.
    }
 
    // Habis nge-loop seluruh index ternyata namanya bener-bener gak ada. Nah
    // di sini deh baru di-delete.
    if(!itemExists) 
    {
        FactionBrankas[slot][factionBrankasExists] = false;
        FactionBrankas[slot][factionBrankasModel] = 0;
        FactionBrankas[slot][factionBrankasQuant] = 0;
        FactionBrankas[slot][factionBrankasFID] = FACTION_NONE;
 
        FactionBrankas[slot][factionBrankasTemp][0] = EOS;
 
        static invstr[555];
        mysql_format(g_SQL, invstr, sizeof(invstr), "DELETE FROM `faction_brankas` WHERE `ID`=%d", FactionBrankas[slot][factionBrankasID]);
        mysql_pquery(g_SQL, invstr);
    }
 
    return itemExists;
}

forward LoadFactionBrankas();
public LoadFactionBrankas()
{
    if(cache_num_rows() > 0)
    {
        new totalInvalidItems = 0;
        for(new x; x < cache_num_rows(); x++)
        {
            if(!FactionBrankas[x][factionBrankasExists])
            {
                FactionBrankas[x][factionBrankasExists] = true;
                cache_get_value_name_int(x, "ID", FactionBrankas[x][factionBrankasID]);
                cache_get_value_name_int(x, "FID", FactionBrankas[x][factionBrankasFID]);
                cache_get_value_name(x, "Item", FactionBrankas[x][factionBrankasTemp]);
                cache_get_value_name_int(x, "Model", FactionBrankas[x][factionBrankasModel]);
                cache_get_value_name_int(x, "Quantity", FactionBrankas[x][factionBrankasQuant]);

                if(!IsFactionItemValid(x)) 
                {
                    totalInvalidItems++;
                }
            }
        }
    }
    return 1;
}

forward LoadServerStuffs();
public LoadServerStuffs()
{
    cache_get_value_name_int(0, "rusunreset", RusunExpired);
    cache_get_value_name_int(0, "taxtiming", FactBadTaxTime);
    cache_get_value_name_int(0, "polisimoneyvault", PolisiMoneyVault);
    cache_get_value_name_int(0, "emsmoneyvault", EMSMoneyVault);
    cache_get_value_name_int(0, "pringsewumoneyvault", PringSewuMoneyVault);
    cache_get_value_name_int(0, "pemermoneyvault", PemerMoneyVault);
    cache_get_value_name_int(0, "bennysmoneyvault", BennysMoneyVault);
    cache_get_value_name_int(0, "ubermoneyvault", UberMoneyVault);
    cache_get_value_name_int(0, "dinarbucksmoneyvault", DinarbucksMoneyVault);
    cache_get_value_name_int(0, "fox11moneyvault", Fox11MoneyVault);
    cache_get_value_name_int(0, "driftkingmoneyvault", DriftKingMoneyVault);
    cache_get_value_name_int(0, "jayaabadimoneyvault", JayaAbadiMoneyVault);
    cache_get_value_name_int(0, "srimersingmoneyvault", SriMersingMoneyVault);
    cache_get_value_name_int(0, "bintangkejoramoneyvault", BintangKejoraMoneyVault);
    
    printf("[Stuffs] Server Stuff berhasil dimuat...");
    return 1;
}

hook OnGameModeInit()
{
    //mappingan tambang ext
    static sxtsw, jjhs[512];
    sxtsw = CreateDynamicObject(18766, 698.091186, 905.486694, -37.313617, 0.000000, 90.000000, 119.799972, 0, 0, -1, 200.00, 200.00); 
    SetDynamicObjectMaterial(sxtsw, 0, 17079, "cuntwland", "stones256", 0x00000000);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CreateDynamicObject(1497, 696.468688, 907.318908, -39.027435, -0.000013, 0.000007, -59.999977, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(1497, 697.973876, 904.711914, -39.027435, 0.000013, -0.000007, 119.999954, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(19834, 697.495300, 905.317260, -37.765472, 0.000000, -63.199966, 119.999961, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(1228, 693.077575, 906.369140, -39.921718, -5.199998, 0.000000, 90.000000, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(1228, 692.261718, 909.421203, -40.046817, -5.199998, 0.000000, 43.899993, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(1228, 696.637329, 902.800964, -39.556652, -0.299998, 0.000000, 360.000000, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(1238, 692.571472, 907.688476, -40.044639, -4.299999, -7.099998, 0.000000, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(3461, 698.653930, 902.139709, -37.519275, 0.000000, 0.000000, 0.000000, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(3577, 697.045410, 897.784423, -39.162036, 0.000000, -4.000000, 0.000000, 0, 0, -1, 200.00, 200.00); 
    CreateDynamicObject(19967, 698.320739, 904.038024, -40.069160, 0.000000, 0.000000, 300.000000, 0, 0, -1, 200.00, 200.00); 
    
    RPSchoolZone = CreateDynamicSphere(1054.6622,2445.7090,301.5000, 100.00, 256, 0, -1);

    RPSchoolText = CreateDynamicObject(4735, 1035.140502, 2457.628662, 307.712280, 0.000000, 0.000000, 90.699989, 256, 0, -1, 200.00, 200.00); 
    SetDynamicObjectMaterial(RPSchoolText, 0, 10765, "airportgnd_sfse", "black64", 0x00000000);
    SetDynamicObjectMaterialText(RPSchoolText, 0, "Roleplay School\nKamis, 07 Agustus 2025\nBersama Minimalst - Shan", 120, "Arial", 15, 1, 0xFFFFFFFF, 0x00000000, 1);

    CreateDynamicPickup(1239, 23, 2238.5657,1595.6613,1019.3632, 777, 1, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Chip Purchasing Counter]\n"WHITE"Gunakan "YELLOW"'/buychip' "WHITE"untuk membeli chip casino", Y_CYAN, 2238.5657,1595.6613,1019.3632+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 777, 1, -1, 10.00, -1, 0);
    
    CreateDynamic3DTextLabel(""GRAY"[Starterpack Point]\n"WHITE"Tekan "YELLOW"[Y]"WHITE" disini untuk mendapatkan starterpack.", -1, 1674.0328,-2245.7637,13.5639 + 0.1, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1);// federal
    CreateDynamicPickup(1239, 23, 2231.1189,1595.9353,1019.3696, 777, 1, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Redeeming]\n"WHITE"Gunakan "YELLOW"'/redeemchip' "WHITE"untuk menukar chip casino", Y_CYAN, 2231.1189,1595.9353,1019.3696+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 777, 1, -1, 10.00, -1, 0);

    g_LSPDAcademyGateOpened = false;
    LSPDAcademyGate = CreateDynamicObject(19913, 1142.335937, 1363.166870, 11.331659, 0.000000, 0.000000, 0.000000, 0, 0, -1, 200.00, 200.00); // close

    g_DisnakerDoorOpened = false;
    DisnakerDoorSensor = CreateDynamicSphere(1814.5287,-1425.7465,13.7244, 4.25, 0, 0, -1);
    DisnakerDoor = CreateDynamicObject(1532, 1814.136108, -1426.479492, 12.724380, -0.000000, -0.000000, 90.000000, 0, 0, -1, 200.00, 200.00);  // close kanan
    SetDynamicObjectMaterial(DisnakerDoor, 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(DisnakerDoor, 1, 19325, "lsmall_shops", "lsmall_window01", 0x00000000);
    SetDynamicObjectMaterial(DisnakerDoor, 2, 18996, "mattextures", "sampblack", 0x00000000);
    
    g_PringSewuDoorOpened = false;
    PringSewuDoorSensor = CreateDynamicSphere(611.9699,-1871.0973,6.2220, 4.25, 0, 0, -1);
    PringSewuDoor[0] = CreateDynamicObject(1532, 612.021423, -1871.533203, 5.184029, 0.000000, 0.000000, 0.000000, 0, 0, -1, 200.00, 200.00); // kiri closed
    SetDynamicObjectMaterial(PringSewuDoor[0], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(PringSewuDoor[0], 1, 19325, "lsmall_shops", "lsmall_window01", 0x00000000);
    SetDynamicObjectMaterial(PringSewuDoor[0], 2, 18996, "mattextures", "sampblack", 0x00000000);
    PringSewuDoor[1] = CreateDynamicObject(1532, 610.501403, -1871.533203, 5.184029, 0.000000, 0.000000, 0.000000, 0, 0, -1, 200.00, 200.00); // kanana close
    SetDynamicObjectMaterial(PringSewuDoor[1], 0, 19297, "matlights", "invisible", 0x00000000);
    SetDynamicObjectMaterial(PringSewuDoor[1], 1, 19325, "lsmall_shops", "lsmall_window01", 0x00000000);
    SetDynamicObjectMaterial(PringSewuDoor[1], 2, 18996, "mattextures", "sampblack", 0x00000000);
    
    g_SriMersingFDoorOpened = false;
    SriMersingFDoorSensor = CreateDynamicSphere(-310.8187,1303.3573,54.7098, 4.25, 0, 0, -1);
    SriMersingDoor[0] = CreateDynamicObject(1569, -312.357177, 1302.924804, 53.688583, 0.000000, 0.000082, 0.000000, 0, 0, -1, 200.00, 200.00); // dkanan
    SriMersingDoor[1] = CreateDynamicObject(1569, -309.357238, 1302.944824, 53.688583, 0.000000, -0.000082, 179.999496, 0, 0, -1, 200.00, 200.00); // dkiri
    
    g_SriMersingBDoorOpened = false;
    SriMersingBDoorSensor = CreateDynamicSphere(-305.6303,1285.0519,54.5486, 4.25, 0, 0, -1);
    SriMersingDoor[2] = CreateDynamicObject(1569, -307.222137, 1285.447509, 53.548583, 0.000000, 0.000000, 0.000000, 0, 0, -1, 200.00, 200.00); // bkanan
    SriMersingDoor[3] = CreateDynamicObject(1569, -304.222167, 1285.466064, 53.548587, 0.000000, 0.000000, 180.000000, 0, 0, -1, 200.00, 200.00); // bkiri

    g_sBoxDoorOpened = false;
    sBoxDoorSensor = CreateDynamicSphere(442.4587,-1807.7310,6.1309, 4.25, 0, 0, -1);
    sBoxDoor[0] = CreateDynamicObject(3089, 442.841583, -1809.264404, 6.447765, 0.000000, 0.000000, 90.000000, 0, 0, -1, 200.0, 200.0); // kanan tutup
    SetDynamicObjectMaterial(sBoxDoor[0], 0, 14581, "ab_mafiasuitea", "barbersmir1", 0x00000000);
    SetDynamicObjectMaterial(sBoxDoor[0], 1, 10765, "airportgnd_sfse", "black64", 0x00000000);
    SetDynamicObjectMaterial(sBoxDoor[0], 2, 10765, "airportgnd_sfse", "white", 0x00000000);
    sBoxDoor[1] = CreateDynamicObject(3089, 442.841583, -1806.294311, 6.447765, 0.000000, 0.000000, 270.000000, 0, 0, -1, 200.0, 200.0); // kiri tutup
    SetDynamicObjectMaterial(sBoxDoor[1], 0, 14581, "ab_mafiasuitea", "barbersmir1", 0x00000000);
    SetDynamicObjectMaterial(sBoxDoor[1], 1, 10765, "airportgnd_sfse", "black64", 0x00000000);
    SetDynamicObjectMaterial(sBoxDoor[1], 2, 10765, "airportgnd_sfse", "white", 0x00000000);
    
    g_PenjahitDoorOpened = false;
    PenjahitDoorSensor = CreateDynamicSphere(2530.3674,2027.4543,11.1719, 4.25, 0, 0, -1);
    PenjahitDoor[0] = CreateDynamicObject(1569, 2530.833740, 2025.922119, 10.170944, 0.000082, 0.000000, 91.499748, 0, 0, -1, 200.00, 200.00); // kanan close
    PenjahitDoor[1] = CreateDynamicObject(1569, 2530.744873, 2028.920654, 10.170944, -0.000082, 0.000000, -88.499748, 0, 0, -1, 200.00, 200.00); // kiri close

    BennysLVArea = CreateDynamicPolygon(BennysLVAreaPoints, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(BennysLVAreaPoints), 0, 0, -1);
    CreateDynamic3DTextLabel("[Modif]\n"WHITE"Gunakan "YELLOW"'/modif' "WHITE"untuk modifikasi kendaraan!", Y_Nexston, 2862.6250,-1824.3909,11.2466+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Modif]\n"WHITE"Gunakan "YELLOW"'/modif' "WHITE"untuk modifikasi kendaraan!", Y_Nexston, 2862.4351,-1832.1539,11.2466+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Modif]\n"WHITE"Gunakan "YELLOW"'/modif' "WHITE"untuk modifikasi kendaraan!", Y_Nexston, 2861.5549,-1840.2876,11.2466+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Modif]\n"WHITE"Gunakan "YELLOW"'/modif' "WHITE"untuk modifikasi kendaraan!", Y_Nexston, 2860.9819,-1848.6063,11.2466+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Modif]\n"WHITE"Gunakan "YELLOW"'/modif' "WHITE"untuk modifikasi kendaraan!", Y_Nexston, 2860.4265,-1856.6699,11.2466+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    DriftKingServiceArea = CreateDynamicPolygon(DriftKingServiceAreaPoints, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(DriftKingServiceAreaPoints), 0, 0, -1);
    JayaAbadiServiceArea = CreateDynamicPolygon(JayaAbadiServiceAreaPoints, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(JayaAbadiServiceAreaPoints), 0, 0, -1);

    AirportGreenZone = CreateDynamicPolygon(AirportGreenZonePoints, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(AirportGreenZonePoints), 0, 0, -1);

    FarmingZone1 = CreateDynamicPolygon(FarmingZone1Points, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(FarmingZone1Points), 0, 0, -1);
    FarmingZone2 = CreateDynamicPolygon(FarmingZone2Points, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(FarmingZone2Points), 0, 0, -1);
    FarmingZone3 = CreateDynamicPolygon(FarmingZone3Points, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(FarmingZone3Points), 0, 0, -1);
    FarmingFruitZone = CreateDynamicPolygon(FarmingFruitPoints, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(FarmingFruitPoints), 0, 0, -1);
    
    AreaSantaiZone = CreateDynamicPolygon(AreaSantaiZonePoints, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(AreaSantaiZonePoints), 0, 0, -1);
    
    KonserMusicZone = CreateDynamicPolygon(KonserZoneMusic, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(KonserZoneMusic), 0, 0, -1);
    
    PDCMusicZone = CreateDynamicPolygon(PDCZoneMusic, -FLOAT_INFINITY, FLOAT_INFINITY, sizeof(PDCZoneMusic), 0, 0, -1);

    BilliardArea = CreateDynamicSphere(501.980987,-67.150199,998.757812, 30.0, 99, 11, -1, 1);

    // Posisi pusat dan radius
    BHMSMusicZone = CreateDynamicSphere(1263.2372,-15.1435,1001.0234, 45.0, 98, 89, -1);

    CreateDynamicPickup(1239, 23, 608.6196,-1885.0508,6.2320, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Pring Sewu Beach Club]\n"WHITE"Gunakan "YELLOW"'/cook' "WHITE"untuk masak!", Y_Nexston, 608.6196,-1885.0508,6.2320+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    CreateDynamicPickup(1239, 23, 611.9481,-1888.5270,6.2320, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Pring Sewu Beach Club]\n"WHITE"Gunakan "YELLOW"'/slice' "WHITE"untuk memotong!", Y_Nexston, 611.9481,-1888.5270,6.2320+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    CreateDynamic3DTextLabel("[Pring Sewu Beach Club]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk melihat menu resto", Y_Nexston, 614.3849,-1879.2244,6.2220, 5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 4.00, -1, 0);
    
    CreateDynamicPickup(1314, 23, 612.2645,-1873.5389,10.8429, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Pring Sewu Beach Club]\n"WHITE"Gunakan "YELLOW"'/psdj' "WHITE"untuk memainkan musik!", Y_Nexston, 612.2645,-1873.5389,10.8429+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    
    // CreateDynamicPickup(1239, 23, 2370.5295,-1701.4884,14.7022, 0, 0, -1, 30.00, -1, 0);
    // CreateDynamic3DTextLabel("[Bintang Kejora]\n"WHITE"Gunakan "YELLOW"'/cook' "WHITE"untuk masak!", Y_Nexston, 2370.5295,-1701.4884,14.7022+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    // CreateDynamicPickup(1239, 23, 2370.6423,-1705.1929,14.7022, 0, 0, -1, 30.00, -1, 0);
    // CreateDynamic3DTextLabel("[Bintang Kejora]\n"WHITE"Gunakan "YELLOW"'/slice' "WHITE"untuk memotong!", Y_Nexston, 2370.6423,-1705.1929,14.7022+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    
    CreateDynamicPickup(1239, 23, -2454.1924,2194.3889,6.3566, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Loving Donuts Cooking Point]\n"WHITE"Gunakan "YELLOW"'/cook' "WHITE"untuk masak!", Y_Nexston, 381.2641,-184.5646,1000.6328+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 44, 17, -1, 10.00, -1, 0);

    CreateDynamicPickup(1239, 23, 381.2641,-182.3879,1000.6328, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Loving Donuts Slicing Point]\n"WHITE"Gunakan"YELLOW"'/slice' "WHITE"untuk memotong!", Y_Nexston, 381.2641,-182.3879,1000.6328+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 44, 17, -1, 10.00, -1, 0);
    
    CreateDynamicPickup(1239, 23, -320.5377,1298.4698,54.3645, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Sri Mersing Resto Cooking Point]\n"WHITE"Gunakan "YELLOW"'/cook' "WHITE"untuk masak!", Y_Nexston, -320.5377,1298.4698,54.3645+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    CreateDynamic3DTextLabel("[Sri Mersing]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk melihat menu resto", Y_Nexston, -313.9656,1298.4697,54.3655, 5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 5.00, -1, 0);

    CreateDynamicPickup(1239, 23, -328.0962,1301.1195,54.3635, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Sri Mersing Resto Slicing Point]\n"WHITE"Gunakan"YELLOW"'/slice' "WHITE"untuk memotong!", Y_Nexston, -328.0962,1301.1195,54.3635+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    
    CreateDynamicPickup(1239, 23, 2479.1294,-1963.1271,16.7578, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("Gunakan "YELLOW"'/megamall' "WHITE"untuk akses mega mall", Y_WHITE, 2479.1294,-1963.1271,16.7578+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.0, -1, 0);
 
    CreateDynamicPickup(1239, 23, -1881.4132,823.1917,35.1767, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("Gunakan "YELLOW"'/megamall' "WHITE"untuk akses mega mall", Y_WHITE, -1881.4132,823.1917,35.1767+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.0, -1, 0);
 
    CreateDynamicPickup(1276, 23, 795.0921,1687.0704,5.2813, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Pawn Shop]\n"WHITE"Gunakan "YELLOW"'/pawn' "WHITE"untuk akses pawn shop", 0xc0c0c8A6, 795.0921,1687.0704,5.2813+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
 
    CreateDynamicPickup(1276, 23, 379.7550,-2020.6007,7.8301, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Bombom Car]\n"WHITE"Gunakan "YELLOW"[Y] "WHITE"untuk akses bombomcar", Y_Nexston, 379.7550,-2020.6007,7.8301+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    CreateDynamic3DTextLabel("[Penyewaan Gudang]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk menyewa gudang", Y_Nexston, 2480.7302,43.3903,1069.6959, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 99, 3, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Klaim Slip Gaji]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk klaim slip gaji", Y_Nexston, 2478.1804,48.2690,1069.6959, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 99, 3, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Buat KTP]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk membuat KTP", Y_Nexston, 2487.0767,43.3927,1069.6959, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 99, 3, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Wedding]\n"WHITE"Gunakan "GREEN"/makewedding "WHITE"untuk menikahkan sesorang", Y_Nexston, 727.8998, -1655.3708, 2.4596, 4.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, 91, -1, 4.00, -1, 0);
    //CreateDynamic3DTextLabel("[RP Quiz]\n"WHITE"Gunakan "YELLOW"'/rpquiz' "WHITE"untuk memulai RP Quiz", Y_Nexston, 1368.1154,1568.2551,17.0003, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 99, 3, -1, 10.00, -1, 0);
    
    CreateDynamic3DTextLabel("[Mobile Data Terminal]\n"WHITE"Gunakan "YELLOW"'/mdt' "WHITE"untuk akses MDT", Y_Nexston, 1833.3292,114.8682,1335.5945, 5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 55, 10, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Mobile Data Terminal]\n"WHITE"Gunakan "YELLOW"'/mdt' "WHITE"untuk akses MDT", Y_Nexston, 1830.2609,117.4763,1335.5945, 5.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 55, 10, -1, 10.00, -1, 0);

    CreateDynamic3DTextLabel("[Mobile Data Terminal]\n"WHITE"Gunakan "YELLOW"'/mdt' "WHITE"untuk akses MDT", Y_Nexston, 242.6550,1845.5930,8.7578+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 69, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 242.6550,1845.5930,8.7578, 69, 0, -1, 30.00, -1, 0);

    //------------------------- BATAS JOB ------------------------//
    CreateDynamic3DTextLabel("[Police Helicopter Spawn Point]\n"WHITE"Gunakan "YELLOW"'/spawnheli' "WHITE"untuk akses Police Air Support Maverick\n"WHITE"Guanakan "YELLOW"'/despawnheli' "WHITE"Untuk mengdespawn Police Air Support Maverick", Y_Nexston, 615.1179,-546.8383,21.3375+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 615.1179,-546.8383,21.3375, 0, 0, -1, 30.00, -1, 0);

    CreateDynamic3DTextLabel("[Police Helicopter Spawn Point]\n"WHITE"Gunakan "YELLOW"'/spawnheli' "WHITE"untuk akses Police Air Support Maverick\n"WHITE"Guanakan "YELLOW"'/despawnheli' "WHITE"Untuk mengdespawn Police Air Support Maverick", Y_Nexston, 615.0135,-590.6496,21.3375+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 615.0135,-590.6496,21.3375, 0, 0, -1, 30.00, -1, 0);

    CreateDynamic3DTextLabel("[SA News Heli Spawn Point]\n"WHITE"Gunakan "YELLOW"'/spawnsanewsheli' "WHITE"untuk akses News Chopper", Y_Nexston, 734.7684,-1381.4521,25.6922+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 734.7684,-1381.4521,25.6922, 0, 0, -1, 30.00, -1, 0);

    CreateDynamic3DTextLabel("[Police Boat Spawn Point]\n"WHITE"Gunakan "YELLOW"'/spawnboat' "WHITE"untuk akses Police Boat Marine Unit", Y_Nexston, 2938.5337,-2051.8362,3.5480+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 2938.5337,-2051.8362,3.5480, 0, 0, -1, 30.00, -1, 0);

    CreateDynamic3DTextLabel("[EMS Heli Spawn Point]\n"WHITE"Gunakan "YELLOW"'/emsheli' "WHITE"untuk akses EMS Helipad", Y_Nexston, 1780.3328,-1112.9495,38.1213+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 1780.3328,-1112.9495,38.1213, 0, 0, -1, 30.00, -1, 0);

    CreateDynamic3DTextLabel("[Impound Lot]\n"WHITE"Gunakan "GREEN"'[Y] "WHITE"untuk akses menu impound", Y_Nexston, 612.7303,-600.1203,16.3259+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);
    CreateDynamicPickup(1239, 23, 612.7303,-600.1203,16.3259, 0, 0, -1, 30.00, -1, 0);

    CreateDynamicPickup(1239, 23, -168.2616,1032.5665,19.7344, 0, 0, -1, 30.00, -1, 0);

    // ================= JOB =============
    CreateDynamic3DTextLabel(""YELLOW"Press "RED"[Y] "WHITE"untuk ambil pekerjaan", Y_WHITE, 1809.3967,-1423.4990,13.7644, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);

    CreateDynamicPickup(1239, 23, -381.9745,-1438.8531,25.7266, 0, 0, -1, 30.00, -1, 0);
    format(jjhs, sizeof(jjhs), "[Toko Bibit]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk beli bibit\n\nCabai: "RED"$%s"GRAY"/pcs => "GREEN"$%s"GRAY"/pcs\n"WHITE"Padi: "RED"$%s"GRAY"/pcs => "GREEN"$%s"GRAY"/pcs\n"WHITE"Tebu: "RED"$%s"GRAY"/pcs => "GREEN"$%s"GRAY"/pcs\n"WHITE"Strawberry: "RED"$%s"GRAY"/pcs => "GREEN"$%s"GRAY"/pcs\n"WHITE"Jeruk: "RED"$%s"GRAY"/pcs => "GREEN"$%s"GRAY"/pcs\n"WHITE"Anggur: "RED"$%s"GRAY"/pcs => "GREEN"$%s"GRAY"/pcs\n"WHITE"Drop tanaman hasil panen disini untuk dijual!", FormatMoney(OldChiliSalary), FormatMoney(ChiliSalary), FormatMoney(OldRiceSalary), FormatMoney(RiceSalary), FormatMoney(OldSugarSalary), FormatMoney(SugarSalary),
        FormatMoney(OldStrawberrySalary), FormatMoney(StrawberrySalary), FormatMoney(OldJerukSalary), FormatMoney(JerukSalary), FormatMoney(OldAnggurSalary), FormatMoney(AnggurSalary));
    g_FarmerLabel = CreateDynamic3DTextLabel(jjhs, Y_Nexston, -381.9745,-1438.8531,25.7266+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    CreateDynamicPickup(1239, 23, -347.8932,-1046.3129,59.8125, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Toko Bibit]\n"WHITE"Gunakan "GREEN"[Y] "WHITE"untuk beli bibit", Y_Nexston, -347.8932,-1046.3129,59.8125+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    //miner
    Miner_TakeStoneArea = CreateDynamicCircle(649.4097,811.0303, 15.00, 0, 0, -1);
    Miner_WashStoneArea = CreateDynamicCircle(-2.3599,1361.3862, 15.00, 0, 0, -1);
    Miner_SmeltStoneArea = CreateDynamicCircle(2151.9377,-2263.2871, 8.00, 0, 0, -1);

    //pasar
    CreateDynamic3DTextLabel("[Hasil Recycler]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 828.9771,-1211.2855,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Hasil Tambang/Minyak]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 830.5294,-1196.3843,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Hasil Berburu]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 834.4956,-1187.4409,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Hasil Penjahit]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 848.2664,-1209.9836,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Hasil Kayu]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 863.1450,-1209.8562,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Pemerah Susu]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 850.3705,-1187.3176,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    CreateDynamic3DTextLabel("[Sell Sawit]\n"WHITE"Drop item disini untuk menjualnya!", Y_Nexston, 842.0912,-1177.7681,16.9935, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    //butcher
    Butcher_TakeChickArea = CreateDynamicCircle(-2087.1978,-2422.1245, 6.25, 0, 0, -1);
    Butcher_CutChickArea = CreateDynamicCircle(-2078.7065,-2431.0396, 6.25, 0, 0, -1);
    Butcher_PackChickArea = CreateDynamicCircle(-2067.4421,-2439.2791, 6.25, 0, 0, -1);

    //oilman

    for(new x; x < sizeof(__g_OilTakePos); x++)
    {
        Oilman_TakeOilArea[x] = CreateDynamicSphere(__g_OilTakePos[x][0], __g_OilTakePos[x][1], __g_OilTakePos[x][2], 3.0, 0, 0, -1);
    }

    Oilman_RefineArea = CreateDynamicSphere(486.5157,1534.1334,1.0032, 4.0, 0, 0, -1);
    Oilman_MixArea = CreateDynamicSphere(281.4672,1341.9341,10.5859, 4.0, 0, 0, -1);
    
    CreateDynamicPickup(954, 23, 2455.3972,-2751.9919,2.2129, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"keluarkan/kembalikan kapal kerja minyak", Y_Nexston, 2455.3972,-2751.9919,2.2129+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);

    CreateDynamicPickup(954, 23, 2707.2742,-6830.4526,2.0425, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"keluarkan/kembalikan kapal kerja minyak", Y_Nexston, 2707.2742,-6830.4526,2.0425+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);

    //supir angkot
    CreateDynamicPickup(1275, 23, 1691.8894,-1458.7782,13.5469, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"mulai pekerjaan supir angkot", Y_Nexston, 1691.8894,-1458.7782,13.5469+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    //supir mixer
    CreateDynamicPickup(1275, 23, 640.5365,1237.4777,11.6895, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"mulai pekerjaan supir mixer", Y_Nexston, 640.5365,1237.4777,11.6895+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    CreateDynamicPickup(19904, 23, 589.4763,1245.1146,12.6529, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[KLAKSON] "WHITE"untuk minta beton dituang", Y_Nexston, 589.4763,1245.1146,12.6529+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    CreateDynamicPickup(19904, 23, 565.0966,1252.4762,12.6899, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[KLAKSON] "WHITE"untuk minta beton dituang", Y_Nexston, 565.0966,1252.4762,12.6899+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    //Hauling
    CreateDynamicPickup(1275, 23, -1680.2018,26.4608,3.6853, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"mulai pekerjaan Hauling", Y_Nexston, -1680.2018,26.4608,3.6853+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    //fisherman
    
    Fisherman_TakeFish = CreateDynamicCircle(5164.2573,-2347.5452, 30.25, 0, 0, -1);

    Fisherman_BoatCP = CreateDynamicCP(2929.6865,-2141.0935,1.8903, 1.5, 0, 0, -1, 15.0, -1, 0);

    CreateDynamicPickup(954, 23, 2929.6865,-2141.0935,1.8903, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"keluarkan/kembalikan kapal kerja nelayan", Y_Nexston, 2929.6865,-2141.0935,1.8903+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);

    CreateDynamicPickup(1212, 23, -2057.6643,-2464.8784,31.1797, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("Drop Ikan disini untuk dijual!", Y_GREEN, -2057.6643,-2464.8784,31.1797+0.65, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    
    //porter

    Porter_StartArea = CreateDynamicSphere(2388.9077,586.0323,7.9351, 3.25, 0, 0, -1);

    for(new x; x < sizeof(PorterDropCoord); x++)
    {
        CreateDynamic3DTextLabel("[Y] "WHITE"letakkan barang", Y_Nexston, PorterDropCoord[x][0], PorterDropCoord[x][1], PorterDropCoord[x][2], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    }

    //pelaut
    PelautStartLV = CreateDynamicCP(1623.8348,581.4980,1.7578, 1.5, 0, 0, -1, 15.0, -1, 0);
    PelautStartLS = CreateDynamicCP(715.0849,-1703.3191,2.4297, 1.5, 0, 0, -1, 15.0, -1, 0);

    //lumberjack
    for(new x; x < 7; x++)
    {
        CreateDynamic3DTextLabel("[Y] "WHITE"ambil kayu", Y_Nexston, __g_TreePos[x][0], __g_TreePos[x][1], __g_TreePos[x][2], 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    }
    
    for(new x; x < 6; x++)
    {
        CreateDynamicPickup(19468, 23, __g_FarmWellPos[x][0], __g_FarmWellPos[x][1], __g_FarmWellPos[x][2], 0, 0, -1, 30.00, -1, 0);
        CreateDynamic3DTextLabel("[ (Y) "YELLOW"untuk menggunakan sumur dan mengisi air "GREEN"]", Y_GREEN, __g_FarmWellPos[x][0], __g_FarmWellPos[x][1], __g_FarmWellPos[x][2] + 0.45, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    }

    for(new x; x < sizeof(__g_CutLog); x++)
    {
        LumberCutLogArea[x] = CreateDynamicSphere(__g_CutLog[x][0], __g_CutLog[x][1], __g_CutLog[x][2], 3.0, 0, 0, -1);
    }

    for(new x; x < sizeof(__g_PackLog); x++)
    {
        LumberPackArea[x] = CreateDynamicSphere(__g_PackLog[x][0], __g_PackLog[x][1], __g_PackLog[x][2], 3.0, 0, 0, -1);
    }
    //peternak
    CreateDynamicPickup(1275, 23, 303.0617,1138.4205,8.5859, 0, 0, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"Mulai bekerja sebagai Peternak", Y_Nexston, 303.0617,1138.4205,8.5859, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1, 10.00, -1, 0);

    for(new x; x < sizeof(__g_MilkProcessPos); x++)
    {
        MilkerProcessArea[x] = CreateDynamicSphere(__g_MilkProcessPos[x][0], __g_MilkProcessPos[x][1], __g_MilkProcessPos[x][2], 3.0, 0, 0, -1);
    }

    //penjahit
    Penjahit_TakeWoolArea = CreateDynamicCircle(1938.5723,165.7293, 6.25, 0, 0, -1);

    for(new x; x < sizeof(__g_MakeFabric); x++)
    {
        PenjahitFabricArea[x] = CreateDynamicSphere(__g_MakeFabric[x][0], __g_MakeFabric[x][1], __g_MakeFabric[x][2], 3.0, 0, 0, -1);
    }

    for(new x; x < sizeof(__g_MakeClothes); x++)
    {
        PenjahitJahitArea[x] = CreateDynamicSphere(__g_MakeClothes[x][0], __g_MakeClothes[x][1], __g_MakeClothes[x][2], 3.0, 0, 0, -1);
    }

    GM[g_ComponentStock] = 100000;

    format(jjhs, sizeof(jjhs), "[Gudang Komponen]\n"WHITE"Harga: "GREEN"$7/komponen\n"WHITE"Stock: "YELLOW"%d/100000\n"WHITE"Gunakan "YELLOW"'/buycomponent' "WHITE"untuk membeli komponen", GM[g_ComponentStock]);
    g_ComponentLabel = CreateDynamic3DTextLabel(jjhs, Y_Nexston, -168.2616,1032.5665,19.7344+0.65, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);

    CarDealerCP = CreateDynamicCP(397.3322,-1329.0055,14.8170, 1.5, 0, 0, -1, 15.0, -1, 0);
    AsuransiCP = CreateDynamicCP(632.0632,-509.6069,16.3359, 1.5, 0, 0, -1, 15.0, -1, 0);

    BankVault = CreateDynamicObject(19799, 1444.822631, -1124.319946, 24.488027, 0.000000, 0.000000, 579.799987, 0, 0, -1, 200.00, 200.00);
    BankRobStatusLabel = CreateDynamic3DTextLabel("Pacific Standard Public Deposit Bank\n"YELLOW"/robbank\n\n"WHITE"Status: "GREEN"Ready", Y_WHITE, 1447.3456,-1123.2587,23.9590, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);


    for(new x; x < sizeof(HintPickup); x++)
    {
        CreateDynamicPickup(1239, 23, HintPickup[x][0],HintPickup[x][1],HintPickup[x][2], 0, 0, -1, 20.0, -1, 0);
        CreateDynamic3DTextLabel("Selamat datang di "Nexston"Nexston Roleplay\n"YELLOW"'/help' "WHITE"~> Petunjuk & bantuan.\n\
        "YELLOW"'/ask' "WHITE"~> Hanya untuk bertanya seputar server & fitur.\n\
        "YELLOW"'/report' "WHITE"~> Melaporkan bug atau player yang melanggar aturan", Y_WHITE, HintPickup[x][0],HintPickup[x][1],HintPickup[x][2]+1.0, 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.0, -1, 0);
    }
    
    CreateDynamicPickup(371, 23, -2237.6172,-1744.6632,480.8505, 0, 0, -1, 20.0, -1, 0);
    CreateDynamic3DTextLabel("[Mount Chilliad Skydiving Point]\n"WHITE"Gunakan "YELLOW"'/skydive' "WHITE"untuk mulai terjun payung.\n[Harga]: "DARKGREEN"$650", Y_Nexston, -2237.6172,-1744.6632,480.8505, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    
    CreateDynamicPickup(371, 23, 767.2671,-22.9374,1000.5859, 2001, 6, -1, 20.0, -1, 0);
    CreateDynamic3DTextLabel("[Cobra GYM]\n"WHITE"Gunakan "YELLOW"'/fs' "WHITE"untuk belajar bela diri.\n[Harga]: "DARKGREEN"$5,000", Y_Nexston, 767.2671,-22.9374,1000.5859, 10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 2001, 6, -1, 10.00, -1, 0);
    
    CreateDynamicPickup(1212, 23, 1477.2319,-31.4594,9.0832, 87, 1, -1, 30.00, -1, 0);
    CreateDynamic3DTextLabel("[Y] "WHITE"untuk akses pencucian uang", Y_Nexston, 1477.2319,-31.4594,9.0832+0.65, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 87, 1, -1, 3.0, -1, 0);
    return 1;
}

hook OnPlayerEnterDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
    if(checkpointid == CarDealerCP)
    {
        ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~Akses Showroom");
    }

    if(checkpointid == AsuransiCP)
    {
        ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~Akses Asuransi");
    }
    return 1;
}

hook OnPlayerLeaveDynamicCP(playerid, STREAMER_TAG_CP:checkpointid)
{
    if(checkpointid == CarDealerCP)
    {
        HideNotifBox(playerid);
        PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
    }

    if(checkpointid == AsuransiCP)
    {
        HideNotifBox(playerid);
        PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
    }
    return 1;
}