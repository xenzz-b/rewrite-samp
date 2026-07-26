RemoveBomBomCarExt(playerid)
{
    RemoveBuildingForPlayer(playerid, 1215, 379.593, -2030.339, 7.375, 0.250);
    RemoveBuildingForPlayer(playerid, 1215, 379.593, -2042.489, 7.375, 0.250);
}

CreateBomBomCarExt()
{
    new STREAMER_TAG_OBJECT: bombomcar;
    bombomcar = CreateDynamicObject(18766, 383.228942, -2019.931152, 5.335940, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 383.228942, -2029.771240, 5.335940, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 383.228942, -2039.711425, 5.335940, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 388.679138, -2044.212158, 5.335940, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 392.089172, -2044.212158, 5.335940, 0.000000, 0.000000, 180.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 396.638793, -2019.931152, 9.285955, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 396.638793, -2029.771240, 9.285955, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 396.638793, -2039.711425, 9.285955, 0.000014, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 388.679138, -2015.427734, 5.335940, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(18766, 392.089172, -2015.427734, 5.335940, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(19482, 396.119354, -2026.881103, 9.295953, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterialText(bombomcar, 0, "{FFFFFF}BOM", 30, "Verdana", 20, 1, 0x00000000, 0x00000000, 0);
    bombomcar = CreateDynamicObject(19482, 396.119354, -2030.512939, 9.295953, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterialText(bombomcar, 0, "{FFFFFF}BOM", 30, "Verdana", 20, 1, 0x00000000, 0x00000000, 0);
    bombomcar = CreateDynamicObject(19482, 396.119354, -2034.215087, 9.295953, 0.000000, -0.000007, 179.999954, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10101, "2notherbuildsfe", "ferry_build14", 0x00000000);
    SetDynamicObjectMaterialText(bombomcar, 0, "{FFFFFF}CAR", 30, "Verdana", 20, 1, 0x00000000, 0x00000000, 0);
    bombomcar = CreateDynamicObject(1472, 382.429351, -2024.580566, 7.095943, 0.000000, 0.000000, 270.000000, -1, -1, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 14581, "ab_mafiasuitea", "ab_walnut", 0x00000000);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bombomcar = CreateDynamicObject(970, 380.227111, -2023.298461, 7.320094, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 380.227111, -2027.449096, 7.320094, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 378.647003, -2023.298461, 7.320094, 0.000015, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 378.647003, -2027.449096, 7.320094, 0.000015, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 380.657073, -2031.591064, 7.320094, 0.000015, 0.000000, 179.999954, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 378.647003, -2029.509887, 7.320094, 0.000015, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2017.495483, 8.320106, 0.000030, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2021.646118, 8.320106, 0.000030, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 385.341522, -2015.369140, 8.320106, 0.000038, -0.000007, 179.999816, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 389.492156, -2015.369140, 8.320106, 0.000038, -0.000007, 179.999816, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 391.922424, -2015.369140, 8.320106, 0.000038, -0.000015, 179.999771, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 393.962371, -2015.369140, 8.320106, 0.000038, -0.000015, 179.999771, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 385.341522, -2044.252929, 8.320106, 0.000038, -0.000015, 179.999771, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 389.492156, -2044.252929, 8.320106, 0.000038, -0.000015, 179.999771, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 391.922424, -2044.252929, 8.320106, 0.000038, -0.000022, 179.999725, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 393.962371, -2044.252929, 8.320106, 0.000038, -0.000022, 179.999725, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2027.586059, 8.320106, 0.000038, 0.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2031.736694, 8.320106, 0.000038, 0.000000, 89.999885, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2035.848876, 8.320106, 0.000045, 0.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2039.999511, 8.320106, 0.000045, 0.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 383.266998, -2042.220458, 8.320106, 0.000045, 0.000000, 89.999862, -1, -1, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(970, 381.848815, -2019.713134, 7.320094, 0.000000, 0.000000, -144.699813, -1, -1, -1, 300.00, 300.00); 
}