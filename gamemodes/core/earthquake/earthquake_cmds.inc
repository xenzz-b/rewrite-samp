YCMD:earthquake(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 7)
        return PermissionError(playerid);
    if (AccountData[playerid][pAdminDuty] == false)
        return PermissionErrorDuty(playerid);

    new amount_of_shakes;
    if(sscanf(params, "i", amount_of_shakes))
        return SUM(playerid, "/earthquake [interval]");

    if(amount_of_shakes < 0) return 0;
    
    foreach(new i : Player) if (IsPlayerConnected(i) && AccountData[i][pSpawned])
    {
        SetPlayerEarthquakeEffect( i, amount_of_shakes );
    }
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s telah menggunakan '/earthquake'.", AccountData[playerid][pAdminname]);

	SendClientMessageToAll(-1, "[i] Terjadi gempa bumi %d magnitudo harap menggungsi", amount_of_shakes);
    return 1;
}
