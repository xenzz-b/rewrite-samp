YCMD:psdj(playerid, params[], help)
{
    if(AccountData[playerid][pFaction] != FACTION_PRINGSEWU) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Pring Sewu Beach Club!");

    if(!IsPlayerInRangeOfPoint(playerid, 3.0, 612.2645,-1873.5389,10.8429))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak berada di alat DJ Pring Sewu");
    
    new link[144];
    if(sscanf(params, "s[144]", link)) return ShowTDN(playerid, NOTIFICATION_SYNTAX, "/psdj [link mp3]~n~'off' untuk matikan");
    
    if(!strcmp(link, "off", true))
    {
        GM[PSDJLink] = EOS;
        foreach(new i : Player) if(IsPlayerInDynamicArea(i, PDCMusicZone))
        {
            StopAudioStreamForPlayer(i);
        }
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil matikan musik DJ!");
    }
    else
    {
        strcopy(GM[PSDJLink], link);
        foreach(new i : Player) if(IsPlayerInDynamicArea(i, PDCMusicZone))
        {
            PlayAudioStreamForPlayer(i, link);
        }
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil memainkan musik!");
    }
    return 1;
}