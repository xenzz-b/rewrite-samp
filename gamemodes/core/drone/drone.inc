#include <YSI_Coding\y_hooks>

new Drones[MAX_PLAYERS];

hook OnPlayerConnect(playerid)
{
    SetPVarInt( playerid, "DroneSpawned", 0 );
 	SetPVarFloat( playerid, "OldPosX", 0 );
	SetPVarFloat( playerid, "OldPosY", 0 );
	SetPVarFloat( playerid, "OldPosZ", 0 );
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    DestroyVehicle( Drones[playerid] );
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if( GetPVarInt(playerid, "DroneSpawned" ) == 1) 
    {
    	SetPVarInt(playerid, "DroneSpawned", 0);
    	DestroyVehicle(Drones[playerid]);
    	Info(playerid, "Your drone was automatically shut down as you have died." );
	}
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    if(vehicleid == Drones[playerid]) 
    {
	    Info(playerid, "You can't exit the drone! Use /drone remove or /drone detonate." );
	}
    return 1;
}

YCMD:drone(playerid, params[], help)
{
    if(!AccountData[playerid][pSpawned])
        return 1;
    
    if(AccountData[playerid][pFaction] != FACTION_LSPD)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari kepolisian");
    
    if(!AccountData[playerid][pOnDuty])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belom bertugas!");
    
    new str[128];
    if(sscanf(params, "s[128]", str))
        return SUM(playerid, "/drone [spawn/ex/end]");
    
    if(strcmp(str, "spawn") == 0)
    {
        if(GetPVarInt(playerid, "DroneSpawned") == 0)
        {
            new Float:Health;
            GetPlayerHealth(playerid, Health);

            if(Health != 0)
            {
                new Float:PosDrone[3];
                GetPlayerPos(playerid, PosDrone[0], PosDrone[1], PosDrone[2]);
                SetPVarFloat(playerid, "OldPosX", PosDrone[0]);
                SetPVarFloat(playerid, "OldPosY", PosDrone[1]); 
                SetPVarFloat(playerid, "OldPosZ", PosDrone[2]);
                SetPVarInt(playerid, "DroneSpawned", 1);

                Success(playerid, "You have successfully spawned a drone.");
                Drones[playerid] = CreateVehicle(465, PosDrone[0], PosDrone[1], PosDrone[2], 1, 1, 60000, false);
                VehicleCore[Drones[playerid]][vCoreFuel] = 55;
                SetValidVehicleHealth(Drones[playerid], 1000.0); 
                VehicleCore[Drones[playerid]][vMaxHealth] = 1000.0;
                VehicleCore[Drones[playerid]][vIsBodyUpgraded] = false;
                VehicleCore[Drones[playerid]][vIsBodyBroken] = false;
                VehicleCore[Drones[playerid]][vCoreLocked] = false;
                PutPlayerInVehicle(playerid, Drones[playerid], 0);
                SwitchVehicleEngine(Drones[playerid], true);
            }
        }
        else 
        {
            Error(playerid, "You already have a drone spawned in!");
        }
    }
    else 
    {
        if(strcmp(str, "ex") == 0)
        {
            if(GetPVarInt(playerid, "DroneSpawned") == 1)
            {
                new Float:PosDrone[3];
                GetVehiclePos(Drones[playerid], PosDrone[0], PosDrone[1], PosDrone[2]);

                SetPVarInt(playerid, "DroneSpawned", 0);
                Success(playerid, "Drone successfully detonated.");
                DestroyVehicle(Drones[playerid]);

                CreateExplosion(PosDrone[0], PosDrone[1], PosDrone[2], 7, 25);
                SetPlayerPos(playerid, GetPVarFloat(playerid, "OldPosX"), GetPVarFloat(playerid, "OldPosY"), GetPVarFloat(playerid, "OldPosZ"));
            }
            else 
            {
                Error(playerid, "You need to have a drone spawned in!");
            }
        }
        else 
        {
            if(strcmp(str, "end") == 0)
            {
                if(GetPVarInt(playerid, "DroneSpawned") == 1)
                {
                    SetPVarInt(playerid, "DroneSpawned", 0);
                    Success(playerid, "You have shut your drone down.");
                    DestroyVehicle(Drones[playerid]);
                    SetPlayerPos(playerid, GetPVarFloat(playerid, "OldPosX"), GetPVarFloat(playerid, "OldPosY"), GetPVarFloat(playerid, "OldPosZ"));
                }
                else 
                {
                    Error(playerid, "You need to have a drone spawned in!");
                }
            }
        }
    }
    return 1;
}