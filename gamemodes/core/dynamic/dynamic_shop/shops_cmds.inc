YCMD:addshop(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new sid = Iter_Free(Shops), query[248];
	if(sid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic Shops sudah maksimal!");

	new stype;
	if(sscanf(params, "d", stype)) return SUM(playerid, "/addshop [type]~n~1. Minimarket, 2. Clothes, 3. Electronic, 4. Ammunation");

    if(stype < 1 || stype > 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Mohon masukkan type untuk toko tersebut yang sesuai!");

    GetPlayerPos(playerid, ShopData[sid][shopPos][0], ShopData[sid][shopPos][1], ShopData[sid][shopPos][2]);
    ShopData[sid][shopVw] = GetPlayerVirtualWorld(playerid);
    ShopData[sid][shopInt] = GetPlayerInterior(playerid);

    ShopData[sid][shopType] = stype;

    Shop_Rebuild(sid);
	Iter_Add(Shops, sid);

    mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `shops` SET `ID`=%d, `type`=%d, `shopX`='%f', `shopY`='%f', `shopZ`='%f', `shopVw`=%d, `shopInt`=%d", sid, ShopData[sid][shopType], ShopData[sid][shopPos][0], ShopData[sid][shopPos][1], ShopData[sid][shopPos][2], ShopData[sid][shopVw], ShopData[sid][shopInt]);
	mysql_pquery(g_SQL, query, "OnShopsCreated", "ii", playerid, sid);
    return 1;
}

YCMD:editshop(playerid, params[], help)
{
    static
        sid,
        type[24],
        string[128];

    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    if(sscanf(params, "ds[24]S()[128]", sid, type, string)) return SUM(playerid, "/editshop [id] [name]~n~location, type, remove");
	
    if(!Iter_Contains(Shops, sid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Shops tersebut tidak valid!");

    if(!strcmp(type, "location", true))
    {
		GetPlayerPos(playerid, ShopData[sid][shopPos][0], ShopData[sid][shopPos][1], ShopData[sid][shopPos][2]);

        ShopData[sid][shopVw] = GetPlayerVirtualWorld(playerid);
		ShopData[sid][shopInt] = GetPlayerInterior(playerid);
        Shop_Save(sid);
		Shop_Refresh(sid);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s menetapkan lokasi Shops ID: %d.", AccountData[playerid][pAdminname], sid);
    }

    else if(!strcmp(type, "type", true))
    {
        new stype;

        if(sscanf(string, "d", stype))
            return SUM(playerid, "/editshop [id] [type]~n~1. Minimarket, 2. Clothes, 3. Electronic, 4. Ammunation");

        if(stype < 1 || stype > 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Type Shops tidak valid!");

        ShopData[sid][shopType] = stype;
        Shop_Save(sid);
		Shop_Refresh(sid);

    
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s mengubah type Shops ID: %d menjadi %d.", AccountData[playerid][pAdminname], sid, stype);
    }

    else if(!strcmp(type, "remove", true))
    {
        if(DestroyDynamic3DTextLabel(ShopData[sid][shopLabel]))
            ShopData[sid][shopLabel] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

        if(DestroyDynamicMapIcon(ShopData[sid][shopIcon]))
            ShopData[sid][shopIcon] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;

        if(DestroyDynamicPickup(ShopData[sid][shopPickup]))
            ShopData[sid][shopPickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;
		
        ShopData[sid][shopType] = 0;
		ShopData[sid][shopPos][0] = 0;
		ShopData[sid][shopPos][1] = 0;
		ShopData[sid][shopPos][2] = 0;
		ShopData[sid][shopVw] = 0;
		ShopData[sid][shopInt] = 0;
		
		Iter_Remove(Shops, sid);
		new query[128];
		mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `shops` WHERE `ID`=%d", sid);
		mysql_pquery(g_SQL, query);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s telah menghapus Shops ID: %d.", AccountData[playerid][pAdminname], sid);
	}
    return 1;
}

YCMD:gotoshop(playerid, params[], help)
{
	new id;
	if(AccountData[playerid][pAdmin] < 5) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);
		
	if(sscanf(params, "d", id))
		return SUM(playerid, "/gotoshop [id]");

	if(!Iter_Contains(Shops, id)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Shops tersebut tidak valid!");
	SetPlayerPositionEx(playerid, ShopData[id][shopPos][0], ShopData[id][shopPos][1], ShopData[id][shopPos][2], -90);
    SetPlayerInteriorEx(playerid, ShopData[id][shopInt]);
    SetPlayerVirtualWorldEx(playerid, ShopData[id][shopVw]);

    AccountData[playerid][pInDoor] = -1;
	AccountData[playerid][pInHouse] = -1;
    AccountData[playerid][pInBiz] = -1;
	AccountData[playerid][pInRusun] = -1;
    AccountData[playerid][pInGudang] = -1;
	return 1;
}