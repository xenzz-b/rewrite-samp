YCMD:modshop(playerid, params[], help)
{
    if(AccountData[playerid][pLevel] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus mencapai setidaknya level 5 karakter!");
    if(!IsPlayerInModshopArea(playerid) && AccountData[playerid][pVIP] != 3) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di modshop point manapun!");
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di kursi pengemudi!");
    
    new vehicleid = GetPlayerVehicleID(playerid);
    new iterid = Vehicle_GetIterID(vehicleid);
    if(iterid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini bukan jenis kendaraan pribadi!");
    if(PlayerVehicle[iterid][pVehRental] > -1 || PlayerVehicle[iterid][pVehRentTime] > 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan rental tidak dapat akses modshop!");
    if(PlayerVehicle[iterid][pVehOwnerID] != AccountData[playerid][pID]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini bukan milik anda!");
    
    new string[555], count;
    format(string, sizeof(string), "Catalogs\tParameters\n");
    for(new x; x < 11; x++)
    {
        if(vtData[iterid][x][vtoy_modelid] != 0)
        {
            strcat(string, sprintf(""WHITE"Edit Toys Model: "YELLOW"%d\t"WHITE"Slot: "RED"%d\n", vtData[iterid][x][vtoy_modelid], x), sizeof(string));
            count++;
        }
    }
    if(count < 11)
    {
        strcat(string, ""GREEN"+ Beli baru\t"GREEN"$5,000", sizeof(string));
    }
    Dialog_Show(playerid, "ModshopCatalog", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Modshop", 
    string, "Pilih", "Batal");
    return 1;
}