YCMD:mysalary(playerid, params[], help)
{
    DisplaySalary(playerid);
    return 1;
}

YCMD:paycheck(playerid, params[], help)
{
    if(!IsPlayerNearPaycheckPoint(playerid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di loket pencairan Bank Pacific!");

    if(AccountData[playerid][pPaycheckTime] > 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Belum saatnya untuk mengambil paycheck!");

    DisplayPaycheck(playerid);
    return 1;
}