ptask WeaponCooldownUpdate[1000](playerid) 
{
    if(AccountData[playerid][pWeaponCooldownActive] || IsPlayerConnected(playerid) || AccountData[playerid][pSpawned])
    {    
        if(AccountData[playerid][pWeaponCooldown] > 0)
        {
            AccountData[playerid][pWeaponCooldown]--;
            if(AccountData[playerid][pWeaponCooldown] % 60 == 0 && AccountData[playerid][pWeaponCooldown] > 0)
            {
                new timeleft = AccountData[playerid][pWeaponCooldown] / 60;
                new string[64];
                format(string, sizeof(string), "~r~Cannot shoot~w~: %d minute(s) left", timeleft);
                GameTextForPlayer(playerid, string, 3000, 3);
            }
            if(AccountData[playerid][pWeaponCooldown] == 0)
            {
                AccountData[playerid][pWeaponCooldownActive] = false;
                GameTextForPlayer(playerid, "~g~You can shoot again!", 3000, 3);
            }
        }
        else
        {
            if(AccountData[playerid][pWeaponCooldownActive])
            {
                AccountData[playerid][pWeaponCooldownActive] = false;
            }
        }
    }
    return 1;
}