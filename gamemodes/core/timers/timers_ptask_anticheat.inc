#include <YSI_Coding\y_hooks>

hook OnPlayerUpdate(playerid)
{
    if(!AccountData[playerid][pSpawned] || !AccountData[playerid][IsLoggedIn])
    {
        if(GetPlayerWeapon(playerid) != 0)
        {
            new acdetail[64];
            format(acdetail, sizeof(acdetail), "pre-spawn weapon: %s", ReturnWeaponName(GetPlayerWeapon(playerid)));
            AC_KickRaw(playerid, "Weapon Hack", acdetail);
            return 0;
        }
    }

    if(GetPlayerWeapon(playerid) == 40 && !AC_IsExempt(playerid))
    {
        AC_KickRaw(playerid, "Crasher Weapon", "weaponid 40");
        return 0;
    }
    return 1;
}

task AntiCheatVehSlap[1000]() 
{
    foreach(new v : Vehicle)
    {
        if(IsValidVehicle(v) && v != INVALID_VEHICLE_ID)
        {
            new Float:vlx[3], impstr[158];
            GetVehicleVelocity(v, vlx[0], vlx[1], vlx[2]);
            if(vlx[0] > 1.7 || vlx[1] > 1.7 || vlx[2] > 1.7)
            {
                if(!IsAPlane(v))
                {
                    foreach(new i : Player)
                    {
                        if(v == JobVehicle[i])
                        {
                            DestroyVehicle(JobVehicle[i]);
                        }
                        
                        if(v == TrailerVehicle[i])
                        {
                            DestroyVehicle(TrailerVehicle[i]);
                        }

                        if(v == FactionHeliVeh[i])
                        {
                            DestroyVehicle(FactionHeliVeh[i]);
                        }

                        if(v == ShowroomVeh[i])
                        {
                            DestroyVehicle(ShowroomVeh[i]);
                        }

                        if(v == DMVVeh[i])
                        {
                            DestroyVehicle(DMVVeh[i]);
                        }

                        if(v == PlayerFactionVehicle[i][AccountData[i][pFaction]])
                        {
                            if(VehicleCore[PlayerFactionVehicle[i][AccountData[i][pFaction]]][vIsDeath])
                            {
                                DestroyVehicle(PlayerFactionVehicle[i][AccountData[i][pFaction]]);
                                FactionVehHasCallsign[PlayerFactionVehicle[i][AccountData[i][pFaction]]] = false;

                                LSPDPlayerCallsign[i][0] = EOS;

                                static string[168];
                                mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `demand_vehicles` WHERE `ownerid` = %d", AccountData[i][pID]);
                                mysql_pquery(g_SQL, string);
                            }
                            else
                            {
                                SetVehiclePos(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehPos][0], PlayerFactionVehStats[i][pFactVehPos][1], PlayerFactionVehStats[i][pFactVehPos][2]);
                                SetVehicleZAngle(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehPos][3]);
                                ChangeVehicleColor(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehColor1], PlayerFactionVehStats[i][pFactVehColor2]);
                                VehicleCore[PlayerFactionVehicle[i][AccountData[i][pFaction]]][vCoreFuel] = PlayerFactionVehStats[i][pFactVehFuel];
                                VehicleCore[PlayerFactionVehicle[i][AccountData[i][pFaction]]][vMaxHealth] = PlayerFactionVehStats[i][pFactVehMaxHealth];
                                VehicleCore[PlayerFactionVehicle[i][AccountData[i][pFaction]]][vIsBodyUpgraded] = PlayerFactionVehStats[i][pFactVehBodyUpgraded];
                                VehicleCore[PlayerFactionVehicle[i][AccountData[i][pFaction]]][vIsBodyBroken] = PlayerFactionVehStats[i][pFactVehBodyBroken];
                                SetVehicleVirtualWorldEx(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehWorld]);

                                if(PlayerFactionVehStats[i][pFactVehHealth] < 350.0)
                                {
                                    SetValidVehicleHealth(PlayerFactionVehicle[i][AccountData[i][pFaction]], 350.0);
                                }
                                else
                                {
                                    SetValidVehicleHealth(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehHealth]);
                                }
                                UpdateVehicleDamageStatus(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehDamage][0], PlayerFactionVehStats[i][pFactVehDamage][1], PlayerFactionVehStats[i][pFactVehDamage][2], PlayerFactionVehStats[i][pFactVehDamage][3]);
                                SwitchVehicleEngine(PlayerFactionVehicle[i][AccountData[i][pFaction]], false);
                                SwitchVehicleDoors(PlayerFactionVehicle[i][AccountData[i][pFaction]], PlayerFactionVehStats[i][pFactVehLocked]);
                                VehicleCore[PlayerFactionVehicle[i][AccountData[i][pFaction]]][vCoreLocked] = PlayerFactionVehStats[i][pFactVehLocked];
                            }
                        }
                            
                        if(v == EventVehicle[i])
                        {
                            DestroyVehicle(EventVehicle[i]);
                        }

                        if((pInSpecMode[i] == 2 || pInSpecMode[i] == 3) && SavingVehID[i] == v)
                        {
                            GetVehicleBoot(v, AccountData[i][pPos][0], AccountData[i][pPos][1], AccountData[i][pPos][2]);

                            AccountData[i][pInterior] = GetVehicleInterior(v);
                            AccountData[i][pWorld] = GetVehicleVirtualWorld(v);

                            SetSpawnInfo(i, NO_TEAM, AccountData[i][pSkin], AccountData[i][pPos][0], AccountData[i][pPos][1], AccountData[i][pPos][2], 180.0, 0, 0, 0, 0, 0, 0);
                            TogglePlayerSpectating(i, false);

                            PlayerSpectatePlayer(i, INVALID_PLAYER_ID);
                            PlayerSpectateVehicle(i, INVALID_VEHICLE_ID);
                            
                            SavingVehID[i] = INVALID_VEHICLE_ID;
                            pInSpecMode[i] = 0;

                            ShowTDN(i, NOTIFICATION_INFO, "Anda telah keluar dari trunk kendaraan.");

                            PlayerPlaySound(i, 12200, 0, 0, 0);
                        }

                        if(AccountData[i][pDuringCarsteal])
                        {
                            if(v == g_CarstealCarPhysic[i])
                            {
                                DestroyVehicle(g_CarstealCarPhysic[i]);

                                g_CarstealCountdown = 0;
                                AccountData[i][pDuringCarsteal] = false;
                                g_IsCarstealStarted = false;
                                g_CarstealCarFound[i] = false;
                                g_CarstealCooldown = gettime() + 1800;

                                ResetAllRaceCP(i);
                                
                                foreach(new x : LSPDDuty)
                                {
                                    if(DestroyDynamicMapIcon(AccountData[i][g_CarstealIcon][x]))
                                        AccountData[i][g_CarstealIcon][x] = STREAMER_TAG_MAP_ICON: INVALID_STREAMER_ID;
                                }

                                ShowFivemNotify(i, "Vertex Roleplay~n~CAR STEAL", "Kendaraan carsteal telah hancur, misi dinyatakan gagal!", "hud:radar_qmark", 25);
                            }
                        }
                    }
                    
                    foreach(new vid : PvtVehicles)
                    {
                        if(v == PlayerVehicle[vid][pVehPhysic])
                        {
                            if(!PlayerVehicle[vid][pVehInsuranced])
                            {
                                SetVehiclePos(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehPos][0], PlayerVehicle[vid][pVehPos][1], PlayerVehicle[vid][pVehPos][2]);
                                SetVehicleZAngle(v, PlayerVehicle[vid][pVehPos][3]);
                                ChangeVehicleColor(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehColor1], PlayerVehicle[vid][pVehColor2]);
                                VehicleCore[PlayerVehicle[vid][pVehPhysic]][vCoreFuel] = PlayerVehicle[vid][pVehFuel];
                                SetVehicleNumberPlate(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehPlate]);
                                SetVehicleVirtualWorldEx(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehWorld]);
                                LinkVehicleToInteriorEx(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehInterior]);

                                if(PlayerVehicle[vid][pVehHealth] < 350.0)
                                {
                                    SetValidVehicleHealth(PlayerVehicle[vid][pVehPhysic], 350.0);
                                }
                                else
                                {
                                    SetValidVehicleHealth(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehHealth]);
                                    VehicleCore[PlayerVehicle[vid][pVehPhysic]][vMaxHealth] = PlayerVehicle[vid][pVehMaxHealth];
                                    VehicleCore[PlayerVehicle[vid][pVehPhysic]][vIsBodyUpgraded] = PlayerVehicle[vid][pVehBodyUpgraded];
                                    VehicleCore[PlayerVehicle[vid][pVehPhysic]][vIsBodyBroken] = PlayerVehicle[vid][pVehBodyBroken];
                                }
                                UpdateVehicleDamageStatus(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehDamage][0], PlayerVehicle[vid][pVehDamage][1], PlayerVehicle[vid][pVehDamage][2], PlayerVehicle[vid][pVehDamage][3]);
                                if(PlayerVehicle[vid][pVehPaintjob] != -1)
                                {
                                    ChangeVehiclePaintjob(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehPaintjob]);
                                }
                                
                                for(new z = 0; z < 17; z++)
                                {
                                    if(PlayerVehicle[vid][pVehMod][z]) AddVehicleComponent(PlayerVehicle[vid][pVehPhysic], PlayerVehicle[vid][pVehMod][z]);
                                }

                                if(PlayerVehicle[vid][pVehLocked])
                                {
                                    SwitchVehicleDoors(PlayerVehicle[vid][pVehPhysic], true);
                                    VehicleCore[PlayerVehicle[vid][pVehPhysic]][vCoreLocked] = true;
                                }
                                else
                                {
                                    SwitchVehicleDoors(PlayerVehicle[vid][pVehPhysic], false);
                                    VehicleCore[PlayerVehicle[vid][pVehPhysic]][vCoreLocked] = false;
                                }

                                if(IsEngineVehicle(PlayerVehicle[vid][pVehPhysic]))
                                {
                                    SwitchVehicleEngine(PlayerVehicle[vid][pVehPhysic], false);
                                }
                                else
                                {
                                    SwitchVehicleEngine(PlayerVehicle[vid][pVehPhysic], true);
                                }
                            }
                            else
                            {
                                if(PlayerVehicle[vid][pVehRental] > -1 || PlayerVehicle[vid][pVehRentTime] > 0)
                                {
                                    PlayerVehicle[vid][pVehRental] = -1;
                                    PlayerVehicle[vid][pVehRentTime] = 0;

                                    if(IsValidVehicle(PlayerVehicle[vid][pVehPhysic]))
                                    {
                                        SetVehicleNeonLights(PlayerVehicle[vid][pVehPhysic], false, PlayerVehicle[vid][pVehNeon], 0);
                                    }
                                    DestroyVehicle(PlayerVehicle[vid][pVehPhysic]);
                                    PlayerVehicle[vid][pVehHandbraked] = false;
                                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vehicle_bagasi` WHERE `Veh_DBID`=%d", PlayerVehicle[vid][pVehID]);
                                    mysql_pquery(g_SQL, impstr);
                                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vehicle_holster` WHERE `Veh_DBID`=%d", PlayerVehicle[vid][pVehID]);
                                    mysql_pquery(g_SQL, impstr);
                                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `player_vehicles` WHERE `id` = %d", PlayerVehicle[vid][pVehID]);
                                    mysql_pquery(g_SQL, impstr);
                                    mysql_format(g_SQL, impstr, sizeof(impstr), "DELETE FROM `vtoys` WHERE `Veh_DBID`=%d", PlayerVehicle[vid][pVehID]);
                                    mysql_pquery(g_SQL, impstr);

                                    for(new x; x < MAX_BAGASI_ITEMS; x++)
                                    {
                                        VehicleBagasi[vid][x][vehicleBagasiExists] = false;
                                        VehicleBagasi[vid][x][vehicleBagasiID] = 0;
                                        VehicleBagasi[vid][x][vehicleBagasiVDBID] = 0;
                                        VehicleBagasi[vid][x][vehicleBagasiTemp][0] = EOS;
                                        VehicleBagasi[vid][x][vehicleBagasiModel] = 0;
                                        VehicleBagasi[vid][x][vehicleBagasiQuant] = 0;
                                    }

                                    for(new z; z < 3; z++)
                                    {
                                        VehicleHolster[vid][vHolsterTaken][z] = false;
                                        VehicleHolster[vid][vHolsterID][z] = -1;
                                        VehicleHolster[vid][vHolsterWeaponID][z] = 0;
                                        VehicleHolster[vid][vHolsterWeaponAmmo][z] = 0;
                                    }

                                    for(new x; x < 6; x++)
                                    {
                                        vtData[vid][x][vtoy_modelid] = 0;
                                        vtData[vid][x][vtoy_text][0] = EOS;
                                        strcopy(vtData[vid][x][vtoy_font], "Arial");
                                        vtData[vid][x][vtoy_fontsize] = 11;
                                        vtData[vid][x][vtoy_fontcolor][0] = 255;
                                        vtData[vid][x][vtoy_fontcolor][1] = 0;
                                        vtData[vid][x][vtoy_fontcolor][2] = 0;
                                        vtData[vid][x][vtoy_fontcolor][3] = 0;
                                        vtData[vid][x][vtoy_fontcolor][4] = 0;
                                        vtData[vid][x][vtoy_objectcolor][0] = 255;
                                        vtData[vid][x][vtoy_objectcolor][1] = 0;
                                        vtData[vid][x][vtoy_objectcolor][2] = 0;
                                        vtData[vid][x][vtoy_objectcolor][3] = 0;
                                        vtData[vid][x][vtoy_objectcolor][4] = 0;
                                        vtData[vid][x][vtoy_x] = 0.0;
                                        vtData[vid][x][vtoy_y] = 0.0;
                                        vtData[vid][x][vtoy_z] = 0.0;
                                        vtData[vid][x][vtoy_rx] = 0.0;
                                        vtData[vid][x][vtoy_ry] = 0.0;
                                        vtData[vid][x][vtoy_rz] = 0.0;
                                    }

                                    Iter_Remove(PvtVehicles, vid);
                                }
                                else
                                {
                                    if(IsValidVehicle(PlayerVehicle[vid][pVehPhysic]))
                                    {
                                        SetVehicleNeonLights(PlayerVehicle[vid][pVehPhysic], false, PlayerVehicle[vid][pVehNeon], 0);
                                    }
                                    DestroyVehicle(PlayerVehicle[vid][pVehPhysic]);
                                    PlayerVehicle[vid][pVehInsuranced] = true;
                                    PlayerVehicle[vid][pVehHandbraked] = false;
                                    mysql_format(g_SQL, impstr, sizeof(impstr), "UPDATE `player_vehicles` SET `PVeh_Insuranced` = 1 WHERE `id`=%d", PlayerVehicle[vid][pVehID]);
                                    mysql_pquery(g_SQL, impstr);
                                }
                            }
                        }
                    }

                    for(new i; i < MAX_ADMIN_VEHICLES; i++)
                    {
                        if(v == GM[adminV][i])
                        {
                            DestroyVehicle(GM[adminV][i]);
                        }
                    }
                    VehicleCore[v][vIsDeath] = true;
                }
            }
        }
    }
    return 1;
}

task AntiCheatVehicleHealth[700]()
{
    static Float:health, Float:maxhp, Float:before, driver, acdetail[96];

    AC_RefreshDriverCache();

    foreach(new v : Vehicle)
    {
        if(v == INVALID_VEHICLE_ID || !IsValidVehicle(v)) continue;
        if(!GetVehicleHealth(v, health)) continue;

        driver = AC_GetVehicleDriverAC(v);

        // Kendaraan tanpa driver dikelola server, jangan pernah dideteksi.
        if(driver == INVALID_PLAYER_ID)
        {
            AC_LedgerVehHP[v]            = health;
            VehicleHealthSecurityData[v] = health;
            AC_VehFlagged[v]             = false;
            continue;
        }

        if(AC_IsExempt(driver))
        {
            AC_LedgerVehHP[v]            = health;
            VehicleHealthSecurityData[v] = health;
            continue;
        }

        maxhp = VehicleCore[v][vMaxHealth];
        if(maxhp <= 0.0) maxhp = 1000.0;

        if(gettime() <= AC_GrantVehTime[v])
        {
            AC_LedgerVehHP[v]            = health;
            VehicleHealthSecurityData[v] = health;
            continue;
        }

        // Kenaikan tanpa repair resmi.
        if(health > AC_LedgerVehHP[v] + AC_VEH_TOLERANCE || health > maxhp + AC_VEH_TOLERANCE)
        {
            if(AC_HasLegitRepairSource(driver))
            {
                AC_LedgerVehHP[v] = (health > maxhp) ? (maxhp) : (health);
                VehicleHealthSecurityData[v] = AC_LedgerVehHP[v];
                continue;
            }

            before = health;
            AC_RevertVehicleState(v);

            if(!AC_VehFlagged[v])
            {
                AC_VehFlagged[v] = true;
                format(acdetail, sizeof(acdetail), "VehHP %.0f -> %.0f (%s)", AC_LedgerVehHP[v], before, GetVehicleModelName(GetVehicleModel(v)));
                AC_Kick(driver, "Vehicle Health Hack", acdetail);
            }
            continue;
        }

        /*  Penurunan health hanya dicurigai bila kendaraan praktis DIAM.
            Tabrakan kecepatan tinggi, jatuh, atau tabrak beruntun bisa
            menghapus 300-500 HP dalam satu tick dan itu wajar.           */
        if(GetVehicleSpeedKMH(v) > AC_VEH_MOVING_KMH)
        {
            AC_VehMoveTick[v] = gettime();
        }
        else if(AC_LedgerVehHP[v] - health > AC_VEH_DROP_LIMIT
             && AC_LedgerVehHP[v] > AC_VEH_DEATH_HP
             && gettime() - AC_VehMoveTick[v] > AC_VEH_CRASH_GRACE
             && !VehicleCore[v][vIsDeath])
        {
            before = health;
            AC_RevertVehicleState(v);

            if(!AC_VehFlagged[v])
            {
                AC_VehFlagged[v] = true;
                format(acdetail, sizeof(acdetail), "VehHP terjun %.0f -> %.0f saat diam (%s)", AC_LedgerVehHP[v], before, GetVehicleModelName(GetVehicleModel(v)));
                AC_Kick(driver, "Vehicle Damage Hack", acdetail);
            }
            continue;
        }

        AC_LedgerVehHP[v]            = health;
        AC_VehFlagged[v]             = false;
        VehicleHealthSecurityData[v] = health;
    }
    return 1;
}


ptask AntiCheatWeapon[1000](playerid) 
{
    if(AccountData[playerid][IsLoggedIn] && AccountData[playerid][pSpawned])
    {
        if(IsPlayerInAnyVehicle(playerid))
        {
            if(!IsAPlane(GetPlayerVehicleID(playerid)))
            {
                if(GetPlayerSpeed(playerid) > 300)
                {
                    new acdetail[64];
                    format(acdetail, sizeof(acdetail), "veh speed %d km/h", GetPlayerSpeed(playerid));
                    AC_Kick(playerid, "Vehicle Speed Hack", acdetail);
                }
            }
        }
        else
        {
            if(GetPlayerSpeed(playerid) > 300)
            {
                new acdetail[64];
                format(acdetail, sizeof(acdetail), "onfoot speed %d km/h", GetPlayerSpeed(playerid));
                AC_Kick(playerid, "Player Speed Hack", acdetail);
            }
        }
        
        if(GetPlayerWeapon(playerid) == 40)
        {
            static string[522];
		    mysql_format(g_SQL, string, sizeof(string), "UPDATE `player_ucp` SET `Blocked`=1, `Block_Duration`=0, `Block_Reason`='Crasher', `Block_AdminName`='AV_AntiCheat', `Block_IssuedDate`=CURRENT_TIMESTAMP() WHERE `UCP`='%e'", AccountData[playerid][pUCP]);
		    mysql_pquery(g_SQL, string);

            SetWeapons(playerid);
            AC_Notify(playerid, "Crasher", "weaponid 40 (akun diblokir)", true);
            AC_Kicked[playerid] = true;
            KickEx(playerid, 1555);
        }

        if(IsPlayerInAnyVehicle(playerid))
        {
            if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER && GetPlayerState(playerid) != PLAYER_STATE_PASSENGER)
            {
                new acdetail[64];
                format(acdetail, sizeof(acdetail), "state %d in veh %d", GetPlayerState(playerid), GetPlayerVehicleID(playerid));
                AC_Kick(playerid, "Vehicle Troll", acdetail);
            }
        }

        if(!AccountData[playerid][pInEvent])
        {
            if(IsAFireArm(GetPlayerWeapon(playerid)))
            {
                if(AccountData[playerid][pLevel] < 5)
                {
                    new acdetail[64];
                    format(acdetail, sizeof(acdetail), "firearm %s on level %d", ReturnWeaponName(GetPlayerWeapon(playerid)), AccountData[playerid][pLevel]);
                    SetWeapons(playerid);
                    AC_Kick(playerid, "Weapon Hack", acdetail);
                }
            }
        }

        if(!AccountData[playerid][pInEvent])
		{
            static pwpid[MAX_PLAYERS];
            if(GetPlayerWeapon(playerid) != pwpid[playerid])
            {
                pwpid[playerid] = GetPlayerWeapon(playerid);

                if(pwpid[playerid] >= 1 && pwpid[playerid] <= 45)
                {
                    if(pwpid[playerid] != 40 && GunData[playerid][g_aWeaponSlots[pwpid[playerid]]][WeaponType] == WEAPON_TYPE_NONE)
                    {
                        new acdetail[64];
                        format(acdetail, sizeof(acdetail), "invalid weapon %s", ReturnWeaponName(pwpid[playerid]));
                        SetWeapons(playerid);
                        AC_Kick(playerid, "Weapon Hack", acdetail);
                    }

                    if(!AccountData[playerid][pTaser] && !AccountData[playerid][pUseBeanbag])
                    {
                        if(pwpid[playerid] != 40 && GunData[playerid][g_aWeaponSlots[pwpid[playerid]]][WeaponID] != pwpid[playerid])
                        {
                            new acdetail[64];
                            format(acdetail, sizeof(acdetail), "slot mismatch %s", ReturnWeaponName(pwpid[playerid]));
                            SetWeapons(playerid);
                            AC_Kick(playerid, "Weapon Hack", acdetail);
                        }
                    }
                }
            }
        }
        else
        {
            static pwpid[MAX_PLAYERS];
            if(GetPlayerWeapon(playerid) != pwpid[playerid])
            {
                pwpid[playerid] = GetPlayerWeapon(playerid);

                if(Iter_Contains(EvRedTeam, playerid))
                {
                    if(pwpid[playerid] != 0 && pwpid[playerid] != EventInfo[redWeapon][0] && pwpid[playerid] != EventInfo[redWeapon][1] && pwpid[playerid] != EventInfo[redWeapon][2])
                    {
                        new acdetail[64];
                        format(acdetail, sizeof(acdetail), "invalid weapon %s", ReturnWeaponName(pwpid[playerid]));
                        SetWeapons(playerid);
                        AC_Kick(playerid, "Weapon Hack", acdetail);
                    }
                }
                else if(Iter_Contains(EvBlueTeam, playerid))
                {
                    if(pwpid[playerid] != 0 && pwpid[playerid] != EventInfo[blueWeapon][0] && pwpid[playerid] != EventInfo[blueWeapon][1] && pwpid[playerid] != EventInfo[blueWeapon][2])
                    {
                        new acdetail[64];
                        format(acdetail, sizeof(acdetail), "invalid weapon %s", ReturnWeaponName(pwpid[playerid]));
                        SetWeapons(playerid);
                        AC_Kick(playerid, "Weapon Hack", acdetail);
                    }
                }
            }
            if(!EventInfo[eventStarted] && !EventInfo[eventOpened])
            {
                ResetPlayerWeapons(playerid);
            }
        }
    }
    return 1;
}

ptask AntiCheatHealthArmor[700](playerid)
{
    if(!AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        return 1;

    static Float:health, Float:armour, Float:maxhp, Float:maxap, acdetail[96];

    GetPlayerHealth(playerid, health);
    GetPlayerArmour(playerid, armour);

    if(!AC_CanPunish(playerid))
    {
        if(AC_Kicked[playerid] && !AC_IsExempt(playerid))
            AC_RevertPlayerState(playerid);

        if(health < AC_LedgerHP[playerid])     AC_LedgerHP[playerid]     = health;
        if(armour < AC_LedgerArmour[playerid]) AC_LedgerArmour[playerid] = armour;
        return 1;
    }

    maxhp = 100.0;
    if(AccountData[playerid][pInEvent]) maxhp = 255.0;
    if(AC_LedgerHP[playerid] > maxhp) maxhp = AC_LedgerHP[playerid];

    maxap = (AccountData[playerid][pInEvent]) ? (255.0) : (100.0);
    if(AC_LedgerArmour[playerid] > maxap) maxap = AC_LedgerArmour[playerid];

    // ---------------- HEALTH ----------------
    if(health > maxhp + AC_HP_TOLERANCE)
    {
        AC_RawSetHealth(playerid, maxhp);
        AccountData[playerid][pHealth] = maxhp;
        Anticheat[playerid][acHealth]  = maxhp;
        AC_LedgerHP[playerid]          = maxhp;

        if(!AC_HPFlagged[playerid])
        {
            AC_HPFlagged[playerid] = true;
            format(acdetail, sizeof(acdetail), "HP %.1f melebihi batas %.0f", health, maxhp);
            AC_Kick(playerid, "Health Hack", acdetail);
        }
    }
    else if(health > AC_LedgerHP[playerid] + AC_HP_TOLERANCE)
    {
        if(AC_HasLegitHealSource(playerid))
        {
            AC_LedgerHP[playerid] = health;
        }
        else
        {
            new Float:before = health, Float:revert = AC_LedgerHP[playerid];
            if(revert > maxhp) revert = maxhp;
            if(revert < 1.0)   revert = 1.0;   // jangan bunuh player karena desync

            AC_RawSetHealth(playerid, revert);
            AccountData[playerid][pHealth] = revert;
            Anticheat[playerid][acHealth]  = revert;

            if(!AC_HPFlagged[playerid])
            {
                AC_HPFlagged[playerid] = true;
                format(acdetail, sizeof(acdetail), "HP %.1f -> %.1f (ledger %.1f)", revert, before, AC_LedgerHP[playerid]);
                AC_Kick(playerid, "Health Hack", acdetail);
            }
        }
    }
    else
    {
        AC_LedgerHP[playerid]  = health;
        AC_HPFlagged[playerid] = false;
    }

    // ---------------- ARMOUR ----------------
    if(armour > maxap + AC_ARMOUR_TOLERANCE)
    {
        new Float:cap = AC_LedgerArmour[playerid];
        if(cap > maxap) cap = maxap;
        if(cap < 0.0)   cap = 0.0;

        AC_RawSetArmour(playerid, cap);
        AccountData[playerid][pArmor]      = cap;
        AccountData[playerid][pHasArmor]   = (cap > 0.0);
        AccountData[playerid][pArmorEmpty] = (cap <= 0.0);
        Anticheat[playerid][acArmour]      = cap;
        AC_LedgerArmour[playerid]          = cap;

        if(!AC_ArmourFlagged[playerid])
        {
            AC_ArmourFlagged[playerid] = true;
            format(acdetail, sizeof(acdetail), "AP %.1f melebihi batas %.0f", armour, maxap);
            AC_Kick(playerid, "Armour Hack", acdetail);
        }
    }
    else if(armour > AC_LedgerArmour[playerid] + AC_ARMOUR_TOLERANCE)
    {
        if(gettime() <= AC_GrantArmourTime[playerid])
        {
            AC_LedgerArmour[playerid] = armour;
        }
        else
        {
            new Float:before = armour, Float:revert = AC_LedgerArmour[playerid];
            if(revert > maxap) revert = maxap;
            if(revert < 0.0)   revert = 0.0;

            AC_RawSetArmour(playerid, revert);
            AccountData[playerid][pArmor]      = revert;
            AccountData[playerid][pHasArmor]   = (revert > 0.0);
            AccountData[playerid][pArmorEmpty] = (revert <= 0.0);
            Anticheat[playerid][acArmour]      = revert;

            if(!AC_ArmourFlagged[playerid])
            {
                AC_ArmourFlagged[playerid] = true;
                format(acdetail, sizeof(acdetail), "AP %.1f -> %.1f (ledger %.1f)", revert, before, AC_LedgerArmour[playerid]);
                AC_Kick(playerid, "Armour Hack", acdetail);
            }
        }
    }
    else
    {
        AC_LedgerArmour[playerid]  = armour;
        AC_ArmourFlagged[playerid] = false;

        if(armour <= 0.0 && AccountData[playerid][pHasArmor])
        {
            AccountData[playerid][pHasArmor]   = false;
            AccountData[playerid][pArmorEmpty] = true;
            AccountData[playerid][pArmor]      = 0.0;
        }
    }
    return 1;
}


ptask AntiCheatMoneyAndAmmo[1000](playerid) 
{
    if(GetPlayerMoney(playerid) != AccountData[playerid][pMoney])
    {
        ResetPlayerMoney(playerid);
        GivePlayerMoney(playerid, AccountData[playerid][pMoney]);
    }

    if(AccountData[playerid][IsLoggedIn])
    {
        // Anti ammo hack - optimized loop
        for(new slot = 0; slot < 13; slot++)
        {
            if(GunData[playerid][slot][WeaponAmmo] > 500)
            {
                GunData[playerid][slot][WeaponAmmo] = 500;
                SetWeapons(playerid);
                SendStaffMessage(Y_RED, "[AntiCheat] %s(%d) Ammo >500 in slot %d - capped", GetName(playerid), playerid, slot);
            }
        }
        
        /*  Kekebalan staff ditentukan terpusat oleh AC_IsExempt() yang
            dipanggil AC_Kick(): HANYA admin on duty (/aduty) yang kebal.
            Pengecekan pAdmin/pWitch/pHelper/pVlounter di sini dihapus
            supaya staff yang sedang OFF DUTY tetap bisa terdeteksi.     */
        if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK)
        {
            AC_Kick(playerid, "Jetpack Hack", "special action jetpack");
        }

        if(IsProhibitedWeapon(GetPlayerWeapon(playerid)))
        {
            new acdetail[64];
            format(acdetail, sizeof(acdetail), "prohibited weapon %s", ReturnWeaponName(GetPlayerWeapon(playerid)));
            AC_Kick(playerid, "Senjata Terlarang", acdetail);
        }
        
        // Anti-Lag: butuh ping tinggi konsisten 5 detik berturut-turut agar spike sesaat tidak menendang
        static acHighPing[MAX_PLAYERS];
        if(GetPlayerPing(playerid) >= 650)
        {
            if(++acHighPing[playerid] >= 5)
            {
                acHighPing[playerid] = 0;
                if(!AC_Kicked[playerid])
                {
                    AC_Kicked[playerid] = true;
                    SendClientMessageEx(playerid, Y_RED, "[Anti-Lag] {DBD7D2}Anda ditendang dari server karena high-ping "YELLOW"(%d/650).", GetPlayerPing(playerid));
                    printf("[Anti-Lag] %s(%d) kicked - high ping %d", GetName(playerid), playerid, GetPlayerPing(playerid));
                    KickEx(playerid);
                }
            }
        }
        else acHighPing[playerid] = 0;
        
        new formulas = NetStats_GetConnectedTime(playerid)/1000;
        static acHighLoss[MAX_PLAYERS];
        if(GetPlayerPacketLoss(playerid) >= 10.00 && formulas >= 360)
        {
            if(++acHighLoss[playerid] >= 5)
            {
                acHighLoss[playerid] = 0;
                if(!AC_Kicked[playerid])
                {
                    AC_Kicked[playerid] = true;
                    SendClientMessageEx(playerid, Y_RED, "[Anti-Lag] {DBD7D2}Anda ditendang dari server karena packetloss tinggi "YELLOW"(%.2f/10.00).", GetPlayerPacketLoss(playerid));
                    printf("[Anti-Lag] %s(%d) kicked - packetloss %.2f", GetName(playerid), playerid, GetPlayerPacketLoss(playerid));
                    KickEx(playerid);
                }
            }
        }
        else acHighLoss[playerid] = 0;
    }
    return 1;
}

ptask AntiFlyHack[1000](playerid) 
{
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        switch(GetPlayerAnimationIndex(playerid))
        {
            case 958, 1538, 1539, 1543:
            {
                new
                    Float:z,
                    Float:vx,
                    Float:vy,
                    Float:vz;

                GetPlayerPos(playerid, z, z, z);
                GetPlayerVelocity(playerid, vx, vy, vz);

                if((z > 20.0) && (0.9 <= floatsqroot((vx * vx) + (vy * vy) + (vz * vz)) <= 1.9))
                {
                    new acdetail[64];
                    format(acdetail, sizeof(acdetail), "anim %d z %.1f", GetPlayerAnimationIndex(playerid), z);
                    AC_Kick(playerid, "Flyhack", acdetail);
                }
            }
        }
    }

    if(AccountData[playerid][pSpawned])
    {
        if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
        {
            if(pInSpecMode[playerid] == 0 && AccountData[playerid][pSpec] == INVALID_PLAYER_ID)
            {
                AC_Kick(playerid, "Invalid State", "spectating tanpa spec mode");
            }
        }

        if(!IsPlayerInAnyVehicle(playerid))
        {
            switch(GetPlayerAnimationIndex(playerid))
            {
                case 123, 1128:
                {
                    new acdetail[48];
                    format(acdetail, sizeof(acdetail), "anim %d", GetPlayerAnimationIndex(playerid));
                    AC_Kick(playerid, "Slapper", acdetail);
                }
            }
        }
    }
    return 1;
}

forward AntiKnifeKill(playerid);
public AntiKnifeKill(playerid)
{
    GivePlayerWeaponEx(playerid, 4, 1, WEAPON_TYPE_PLAYER);
    return 1;
}

ptask UpdateSpecialAction[1000](playerid) 
{
    if(GetPlayerAnimationIndex(playerid) == 748)
    {
        ResetWeapon(playerid, 4);
        SetTimerEx("AntiKnifeKill", 2555, false, "i", playerid);
    }
    return 1;
}

ptask UpateAntiFConn[1000](playerid) 
{
    // NPC milik server (npcmodes) tidak boleh di-ban oleh anticheat.
    // Ban otomatis di sini adalah false positive: IP NPC = IP server.
    if(IsPlayerNPC(playerid))
    {
        return 1;
    }

    if(!AccountData[playerid][pSpawned] || !AccountData[playerid][IsLoggedIn])
    {
        if(GetPlayerWeapon(playerid) != 0)
        {
            new acdetail[64];
            format(acdetail, sizeof(acdetail), "pre-spawn weapon: %s", ReturnWeaponName(GetPlayerWeapon(playerid)));
            AC_KickRaw(playerid, "Weapon Hack", acdetail);
            return 1;
        }
    }

    if(IsPlayerSpawned(playerid))
    {
        if(!AVC_PConnected[playerid] || !AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        {
            return AC_KickRaw(playerid, "Fake Connect", "spawned tanpa data akun");
        }

        if(GetPlayerColor(playerid) == 0x7F7F83FF)
        {
            return AC_KickRaw(playerid, "Fake Connect", "default color 0x7F7F83FF");
        }
    }
    
    if(IsPlayerMoving(playerid))
    {
        if(!AVC_PConnected[playerid] || !AccountData[playerid][IsLoggedIn] || !AccountData[playerid][pSpawned])
        {
            return AC_KickRaw(playerid, "Fake Connect", "bergerak tanpa data akun [IPM]");
        }
    }
    return 1;
}
