YCMD:sid(playerid, params[], help)
{
    if(AccountData[playerid][pToggleNameID])
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Matikan /ntag terlebih dahulu!");

    DisplayPlayerNameTag(playerid);
    return 1;
}

YCMD:ntag(playerid, params[], help)
{
    if (AccountData[playerid][pAdmin] < 1 && !AccountData[playerid][pWitch])
        return PermissionError(playerid);

    if(AccountData[playerid][pNameTagShown])
        return ShowTDN(playerid, NOTIFICATION_WARNING, "Matikan /sid terlebih dahulu!");

    DisplayAdminNameTag(playerid);
    return 1;
}