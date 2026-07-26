YCMD:addlocker(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lockertype, name[64];
    if(sscanf(params, "ds[64]", lockertype, name)) return SUM(playerid, "/addlocker [faction id] [name]");

    if(lockertype < 1 || lockertype > MAX_FACTIONS - 1) return SUM(playerid, "Type should be between 1 and 9");
    new lid = Iter_Free(Lockers);
    if(lid <= -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic lockers telah mencapai batas maksimum!");

    GetPlayerPos(playerid, LockerData[lid][Pos][0], LockerData[lid][Pos][1], LockerData[lid][Pos][2]);
    LockerData[lid][World] = GetPlayerVirtualWorld(playerid);
    LockerData[lid][Interior] = GetPlayerInterior(playerid);
    LockerData[lid][Type] = lockertype;
    strcopy(LockerData[lid][Text], name);

    Iter_Add(Lockers, lid);

    static string[258];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `lockers` (`id`, `posx`, `posy`, `posz`, `world`, `interior`, `type`, `name`) VALUES (%d, '%f', '%f', '%f', %d, %d, %d, '%e')", lid, LockerData[lid][Pos][0], LockerData[lid][Pos][1], LockerData[lid][Pos][2], LockerData[lid][World], LockerData[lid][Interior], LockerData[lid][Type], LockerData[lid][Text]);
    mysql_pquery(g_SQL, string);

    Locker_Rebuild(lid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s created a locker with ID: %d.", AccountData[playerid][pAdminname], lid);
    return 1;
}

YCMD:removelocker(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lid;
    if(sscanf(params, "d", lid)) return SUM(playerid, "/removelocker [locker id]");

    if(!Iter_Contains(Lockers, lid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Locker ID tersebut tidak valid!");

    LockerData[lid][Pos][0] = 0.0;
    LockerData[lid][Pos][1] = 0.0;
    LockerData[lid][Pos][2] = 0.0;
    LockerData[lid][World] = 0;
    LockerData[lid][Interior] = 0;
    LockerData[lid][Type] = 0;
    LockerData[lid][Text][0] = EOS;

    if(DestroyDynamicPickup(LockerData[lid][Pickup]))
        LockerData[lid][Pickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if(DestroyDynamic3DTextLabel(LockerData[lid][Label]))
        LockerData[lid][Label] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

    static string[128];
    mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `lockers` WHERE `id` = %d", lid);
    mysql_pquery(g_SQL, string);
    
    Iter_Remove(Lockers, lid);
    return 1;
}

YCMD:addfcrafting(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lockertype;
    if(sscanf(params, "d", lockertype)) return SUM(playerid, "/addfcrafting [faction id]");

    if(lockertype != FACTION_BENNYS && lockertype != FACTION_DRIFTKING && lockertype != FACTION_JAYAABADI) return ShowTDN(playerid, NOTIFICATION_ERROR, "CMD ini hanya untuk faction jenis bengkel!");

    new lid = Iter_Free(FCrafts);
    if(lid <= -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic faction craft telah mencapai batas maksimum!");

    GetPlayerPos(playerid, FCraftData[lid][Pos][0], FCraftData[lid][Pos][1], FCraftData[lid][Pos][2]);
    FCraftData[lid][World] = GetPlayerVirtualWorld(playerid);
    FCraftData[lid][Interior] = GetPlayerInterior(playerid);
    FCraftData[lid][Type] = lockertype;

    Iter_Add(FCrafts, lid);

    static string[258];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `fcrafts` (`id`, `posx`, `posy`, `posz`, `world`, `interior`, `type`) VALUES (%d, '%f', '%f', '%f', %d, %d, %d)", lid, FCraftData[lid][Pos][0], FCraftData[lid][Pos][1], FCraftData[lid][Pos][2], FCraftData[lid][World], FCraftData[lid][Interior], FCraftData[lid][Type]);
    mysql_pquery(g_SQL, string);

    FCraft_Rebuild(lid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s created a facton crafting with ID: %d.", AccountData[playerid][pAdminname], lid);
    return 1;
}

YCMD:removefcraft(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lid;
    if(sscanf(params, "d", lid)) return SUM(playerid, "/removefcraft [faction craft id]");

    if(!Iter_Contains(FCrafts, lid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Faction Craft ID tersebut tidak valid!");

    FCraftData[lid][Pos][0] = 0.0;
    FCraftData[lid][Pos][1] = 0.0;
    FCraftData[lid][Pos][2] = 0.0;
    FCraftData[lid][World] = 0;
    FCraftData[lid][Interior] = 0;
    FCraftData[lid][Type] = 0;

    if(DestroyDynamicPickup(FCraftData[lid][Pickup]))
        FCraftData[lid][Pickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if(DestroyDynamic3DTextLabel(FCraftData[lid][Label]))
        FCraftData[lid][Label] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

    static string[128];
    mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `fcrafts` WHERE `id` = %d", lid);
    mysql_pquery(g_SQL, string);
    
    Iter_Remove(FCrafts, lid);
    return 1;
}

YCMD:addarmoury(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lid = Iter_Free(Armouries), name[64];
    if(sscanf(params, "s[64]", name)) return SUM(playerid, "/addarmoury [name]");

    if(lid <= -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic armoury telah mencapai batas maksimum!");

    GetPlayerPos(playerid, ArmouryData[lid][Pos][0], ArmouryData[lid][Pos][1], ArmouryData[lid][Pos][2]);
    ArmouryData[lid][World] = GetPlayerVirtualWorld(playerid);
    ArmouryData[lid][Interior] = GetPlayerInterior(playerid);
    strcopy(ArmouryData[lid][Text], name);
    Iter_Add(Armouries, lid);

    static string[268];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `armouries` (`id`, `posx`, `posy`, `posz`, `world`, `interior`, `name`) VALUES (%d, '%f', '%f', '%f', %d, %d, '%e')", lid, ArmouryData[lid][Pos][0], ArmouryData[lid][Pos][1], ArmouryData[lid][Pos][2], ArmouryData[lid][World], ArmouryData[lid][Interior], ArmouryData[lid][Text]);
    mysql_pquery(g_SQL, string);

    Armoury_Rebuild(lid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s created an armoury with ID: %d.", AccountData[playerid][pAdminname], lid);
    return 1;
}

YCMD:removearmoury(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lid;
    if(sscanf(params, "d", lid)) return SUM(playerid, "/removearmoury [locker id]");

    if(!Iter_Contains(Armouries, lid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Armoury ID tersebut tidak valid!");

    ArmouryData[lid][Pos][0] = 0.0;
    ArmouryData[lid][Pos][1] = 0.0;
    ArmouryData[lid][Pos][2] = 0.0;
    ArmouryData[lid][World] = 0;
    ArmouryData[lid][Interior] = 0;

    if(DestroyDynamicPickup(ArmouryData[lid][Pickup]))
        ArmouryData[lid][Pickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if(DestroyDynamic3DTextLabel(ArmouryData[lid][Label]))
        ArmouryData[lid][Label] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

    static string[128];
    mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `armouries` WHERE `id` = %d", lid);
    mysql_pquery(g_SQL, string);
    
    Iter_Remove(Armouries, lid);
    return 1;
}

YCMD:addvault(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lockertype, name[64];
    if(sscanf(params, "ds[64]", lockertype, name)) return SUM(playerid, "/addvault [faction id] [name]");

    if(lockertype < 1 || lockertype > MAX_FACTIONS - 1) return SUM(playerid, "Invalid faction ID");
    new lid = Iter_Free(Vaults);
    if(lid <= -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic faction vaults telah mencapai batas maksimum!");

    GetPlayerPos(playerid, VaultData[lid][Pos][0], VaultData[lid][Pos][1], VaultData[lid][Pos][2]);
    VaultData[lid][World] = GetPlayerVirtualWorld(playerid);
    VaultData[lid][Interior] = GetPlayerInterior(playerid);
    VaultData[lid][Type] = lockertype;
    strcopy(VaultData[lid][Text], name);

    Iter_Add(Vaults, lid);

    static string[258];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `vaults` (`id`, `posx`, `posy`, `posz`, `world`, `interior`, `type`, `name`) VALUES (%d, '%f', '%f', '%f', %d, %d, %d, '%e')", lid, VaultData[lid][Pos][0], VaultData[lid][Pos][1], VaultData[lid][Pos][2], VaultData[lid][World], VaultData[lid][Interior], VaultData[lid][Type], VaultData[lid][Text]);
    mysql_pquery(g_SQL, string);

    Vault_Rebuild(lid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s created a faction vault with ID: %d.", AccountData[playerid][pAdminname], lid);
    return 1;
}

YCMD:removevault(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lid;
    if(sscanf(params, "d", lid)) return SUM(playerid, "/removevault [locker id]");

    if(!Iter_Contains(Vaults, lid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Vault ID tersebut tidak valid!");

    VaultData[lid][Pos][0] = 0.0;
    VaultData[lid][Pos][1] = 0.0;
    VaultData[lid][Pos][2] = 0.0;
    VaultData[lid][World] = 0;
    VaultData[lid][Interior] = 0;

    if(DestroyDynamicPickup(VaultData[lid][Pickup]))
        VaultData[lid][Pickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if(DestroyDynamic3DTextLabel(VaultData[lid][Label]))
        VaultData[lid][Label] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

    static string[128];
    mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `vaults` WHERE `id` = %d", lid);
    mysql_pquery(g_SQL, string);
    
    Iter_Remove(Vaults, lid);
    return 1;
}

YCMD:addfgarage(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lockertype, name[64];
    if(sscanf(params, "ds[64]", lockertype, name)) return SUM(playerid, "/addfgarage [faction id] [name]");

    if(lockertype < 1 || lockertype > MAX_FACTIONS - 1) return SUM(playerid, "Invalid faction ID");
    new lid = Iter_Free(FGarages);
    if(lid <= -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah dynamic lockers telah mencapai batas maksimum!");

    GetPlayerPos(playerid, FactGarageData[lid][Pos][0], FactGarageData[lid][Pos][1], FactGarageData[lid][Pos][2]);
    
    FactGarageData[lid][GaragePos][0] = FactGarageData[lid][Pos][0];
    FactGarageData[lid][GaragePos][1] = FactGarageData[lid][Pos][1];
    FactGarageData[lid][GaragePos][2] = FactGarageData[lid][Pos][2];

    // Titik spawn kendaraan sengaja dikosongkan, sama seperti /addgarkot.
    // Admin wajib mengaturnya dengan /editfgarage [id] spawnpos supaya
    // kendaraan tidak muncul menimpa titik pintu garasi.
    FactGarageData[lid][GarageSpawnPos][0] = 0.0;
    FactGarageData[lid][GarageSpawnPos][1] = 0.0;
    FactGarageData[lid][GarageSpawnPos][2] = 0.0;
    FactGarageData[lid][GarageSpawnPos][3] = 0.0;

    FactGarageData[lid][World] = GetPlayerVirtualWorld(playerid);
    FactGarageData[lid][Interior] = GetPlayerInterior(playerid);
    FactGarageData[lid][Type] = lockertype;
    strcopy(FactGarageData[lid][Text], name);

    Iter_Add(FGarages, lid);

    static string[512];
    mysql_format(g_SQL, string, sizeof(string), "INSERT INTO `faction_garages` (`id`, `posx`, `posy`, `posz`, `gposx`, `gposy`, `gposz`, `gposspawnx`, `gposspawny`, `gposspawnz`, `gposspawna`, `world`, `interior`, `type`, `name`) VALUES (%d, '%f', '%f', '%f', '%f', '%f', '%f', '%f', '%f', '%f', '%f', %d, %d, %d, '%e')", lid, FactGarageData[lid][Pos][0], FactGarageData[lid][Pos][1], FactGarageData[lid][Pos][2], FactGarageData[lid][GaragePos][0], FactGarageData[lid][GaragePos][1], FactGarageData[lid][GaragePos][2], FactGarageData[lid][GarageSpawnPos][0], FactGarageData[lid][GarageSpawnPos][1], FactGarageData[lid][GarageSpawnPos][2], FactGarageData[lid][GarageSpawnPos][3], FactGarageData[lid][World], FactGarageData[lid][Interior], FactGarageData[lid][Type], FactGarageData[lid][Text]);
    mysql_pquery(g_SQL, string);

    FGarage_Rebuild(lid);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s created a faction garage with ID: %d.", AccountData[playerid][pAdminname], lid);
    return 1;
}

YCMD:editfgarage(playerid, params[], help)
{
    static
        lid,
        type[24],
        string[128];

    if(AccountData[playerid][pAdmin] < 6)
        return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    if(sscanf(params, "ds[24]S()[128]", lid, type, string)) return SUM(playerid, "/editfgarage [id] [name] ~n~spawnpos, position, name");

    if(!Iter_Contains(FGarages, lid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "ID Faction Garage tersebut tidak valid!");

    static query[512];

    if(!strcmp(type, "spawnpos", true))
    {
        GetPlayerPos(playerid, FactGarageData[lid][GarageSpawnPos][0], FactGarageData[lid][GarageSpawnPos][1], FactGarageData[lid][GarageSpawnPos][2]);
        GetPlayerFacingAngle(playerid, FactGarageData[lid][GarageSpawnPos][3]);

        mysql_format(g_SQL, query, sizeof(query), "UPDATE `faction_garages` SET `gposspawnx` = '%f', `gposspawny` = '%f', `gposspawnz` = '%f', `gposspawna` = '%f' WHERE `id` = %d", FactGarageData[lid][GarageSpawnPos][0], FactGarageData[lid][GarageSpawnPos][1], FactGarageData[lid][GarageSpawnPos][2], FactGarageData[lid][GarageSpawnPos][3], lid);
        mysql_pquery(g_SQL, query);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set the spawn position for Faction Garage ID: %d.", AccountData[playerid][pAdminname], lid);
    }
    else if(!strcmp(type, "position", true))
    {
        GetPlayerPos(playerid, FactGarageData[lid][Pos][0], FactGarageData[lid][Pos][1], FactGarageData[lid][Pos][2]);

        FactGarageData[lid][GaragePos][0] = FactGarageData[lid][Pos][0];
        FactGarageData[lid][GaragePos][1] = FactGarageData[lid][Pos][1];
        FactGarageData[lid][GaragePos][2] = FactGarageData[lid][Pos][2];

        FactGarageData[lid][World] = GetPlayerVirtualWorld(playerid);
        FactGarageData[lid][Interior] = GetPlayerInterior(playerid);

        mysql_format(g_SQL, query, sizeof(query), "UPDATE `faction_garages` SET `posx` = '%f', `posy` = '%f', `posz` = '%f', `gposx` = '%f', `gposy` = '%f', `gposz` = '%f', `world` = %d, `interior` = %d WHERE `id` = %d", FactGarageData[lid][Pos][0], FactGarageData[lid][Pos][1], FactGarageData[lid][Pos][2], FactGarageData[lid][GaragePos][0], FactGarageData[lid][GaragePos][1], FactGarageData[lid][GaragePos][2], FactGarageData[lid][World], FactGarageData[lid][Interior], lid);
        mysql_pquery(g_SQL, query);

        FGarage_Rebuild(lid);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set the position for Faction Garage ID: %d.", AccountData[playerid][pAdminname], lid);
    }
    else if(!strcmp(type, "name", true))
    {
        new name[64];

        if(sscanf(string, "s[64]", name))
            return SUM(playerid, "/editfgarage [id] [name] [new name]");

        strcopy(FactGarageData[lid][Text], name);

        mysql_format(g_SQL, query, sizeof(query), "UPDATE `faction_garages` SET `name` = '%e' WHERE `id` = %d", FactGarageData[lid][Text], lid);
        mysql_pquery(g_SQL, query);

        FGarage_Rebuild(lid);

        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s set the name of Faction Garage ID: %d to %s.", AccountData[playerid][pAdminname], lid, name);
    }
    return 1;
}

YCMD:removefgarage(playerid, params[], help)
{
    if(AccountData[playerid][pAdmin] < 6) return PermissionError(playerid);
    if(AccountData[playerid][pAdminDuty] == false) return PermissionErrorDuty(playerid);

    new lid;
    if(sscanf(params, "d", lid)) return SUM(playerid, "Usage: /removefgarage [id]");

    if(!Iter_Contains(FGarages, lid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Invalid Faction Garage ID!");

    FactGarageData[lid][Pos][0] = 0.0;
    FactGarageData[lid][Pos][1] = 0.0;
    FactGarageData[lid][Pos][2] = 0.0;
    FactGarageData[lid][GaragePos][0] = 0.0;
    FactGarageData[lid][GaragePos][1] = 0.0;
    FactGarageData[lid][GaragePos][2] = 0.0;
    FactGarageData[lid][GarageSpawnPos][0] = 0.0;
    FactGarageData[lid][GarageSpawnPos][1] = 0.0;
    FactGarageData[lid][GarageSpawnPos][2] = 0.0;
    FactGarageData[lid][GarageSpawnPos][3] = 0.0;
    FactGarageData[lid][World] = 0;
    FactGarageData[lid][Interior] = 0;

    if(DestroyDynamicPickup(FactGarageData[lid][Pickup]))
        FactGarageData[lid][Pickup] = STREAMER_TAG_PICKUP: INVALID_STREAMER_ID;

    if(DestroyDynamic3DTextLabel(FactGarageData[lid][Label]))
        FactGarageData[lid][Label] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;

    if(DestroyDynamicObject(FactGarageData[lid][Object]))
        FactGarageData[lid][Object] = STREAMER_TAG_OBJECT: INVALID_STREAMER_ID;

    static string[128];
    mysql_format(g_SQL, string, sizeof(string), "DELETE FROM `faction_garages` WHERE `id` = %d", lid);
    mysql_pquery(g_SQL, string);
    
    Iter_Remove(FGarages, lid);
    return 1;
}

YCMD:fcraft(playerid, params[], help)
{
    if(AccountData[playerid][pFaction] != FACTION_BENNYS && AccountData[playerid][pFaction] != FACTION_DRIFTKING && AccountData[playerid][pFaction] != FACTION_JAYAABADI) return ShowTDN(playerid, NOTIFICATION_ERROR, "CMD ini hanya untuk faction berjenis bengkel!");

    if(!IsPlayerNearFCraft(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan titik crafting faction anda!");

    static string[555];
    format(string, sizeof(string), "Katalog\tAlat & Bahan\n\
    Part Mesin\tKomponen: %d/50 | Tembaga: %d/3 | Besi: %d/5 | Plastik: %d/3 | Minyak: %d/5\n\
    "GRAY"Part Body\t"GRAY"Komponen: %d/50 | Tembaga: %d/3 | Besi: %d/5 | Plastik: %d/5 | Minyak: %d/3\n\
    Ban Baru\tKomponen: %d/50 | Tembaga: %d/3 | Besi: %d/5 | Linggis: %d/2 | Plastik: %d/5\n\
    "GRAY"Air Brush\t"GRAY"Komponen: %d/50 | Pilox: %d/1 | Botol: %d/10 | Emas: %d/2\n\
    Toolkit\tKomponen: %d/50 | Tembaga: %d/5 | Besi: %d/10 | Plastik: %d/5 | Minyak: %d/10", 
    Inventory_Count(playerid, "Komponen"), Inventory_Count(playerid, "Tembaga"), Inventory_Count(playerid, "Besi"), Inventory_Count(playerid, "Plastik"), Inventory_Count(playerid, "Minyak"),
    Inventory_Count(playerid, "Komponen"), Inventory_Count(playerid, "Tembaga"), Inventory_Count(playerid, "Besi"), Inventory_Count(playerid, "Plastik"), Inventory_Count(playerid, "Minyak"),
    Inventory_Count(playerid, "Komponen"), Inventory_Count(playerid, "Tembaga"), Inventory_Count(playerid, "Besi"), Inventory_Count(playerid, "Linggis"), Inventory_Count(playerid, "Plastik"),
    Inventory_Count(playerid, "Komponen"), Inventory_Count(playerid, "Pilox"), Inventory_Count(playerid, "Botol"), Inventory_Count(playerid, "Emas"),
    Inventory_Count(playerid, "Komponen"), Inventory_Count(playerid, "Tembaga"), Inventory_Count(playerid, "Besi"), Inventory_Count(playerid, "Plastik"), Inventory_Count(playerid, "Minyak"));
    Dialog_Show(playerid, "FactionCrafting", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Crafting Fraksi", string, "Pilih", "Batal");
    return 1;
}

YCMD:armoury(playerid, params[], help)
{
    if(AccountData[playerid][pFaction] != FACTION_LSPD) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari Kepolisian Vertex!");
    if(!AccountData[playerid][pOnDuty]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus on duty terlebih dahulu!");
    if(!IsPlayerNearArmoury(playerid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan armoury manapun!");

    Dialog_Show(playerid, "PolisiArmoury", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Brankas Senjata", 
    "Restock Ammo\n\
    Refill Health & Regular Armour\n\
    Refill Health & Tactical Armour (SWAT)\n\
    Clear Weapons & Armour\n\
    Desert Eagle\n\
    Shotgun\n\
    MP5\n\
    M4\n\
    Combat Shotgun\n\
    Sniper Rifle", "Pilih", "Batal");
    return 1;
}

YCMD:fmenu(playerid, params[], help)
{
    if(AccountData[playerid][pFaction] == FACTION_NONE) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari faction manapun!");

    if(!AccountData[playerid][pOnDuty]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus on duty terlebih dahulu!");
    switch(AccountData[playerid][pFaction])
    {
        case FACTION_LSPD:
        {
            if(AccountData[playerid][pFactionRank] < 20) return ShowTDN(playerid, NOTIFICATION_ERROR, "Minimal rank PANGKASAT untuk akses Bos Desk!");

            Dialog_Show(playerid, "PolisiBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Kepolisian", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_LSFD:
        {
            if(AccountData[playerid][pFactionRank] < 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Vice Director untuk akses faction menu!");

            Dialog_Show(playerid, "ParamedisBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Paramedis", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_PRINGSEWU:
        {
            if(AccountData[playerid][pFactionRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Store Supervisor untuk akses boss desk!");

            Dialog_Show(playerid, "PringSewuBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Pring Sewu", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_SAGOV:
        {
            if(AccountData[playerid][pFactionRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Sekretaris untuk akses boss desk!");

            Dialog_Show(playerid, "PemerintahBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Pemerintah", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_BENNYS:
        {
            if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Vice Manager untuk akses boss desk!");

            Dialog_Show(playerid, "BennysBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Bennys", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_UBER:
        {
            if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Ast. Boss Uber untuk akses boss desk!");

            Dialog_Show(playerid, "UberBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Uber", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_DINARBUCKS:
        {
            if(AccountData[playerid][pFactionRank] < 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Supervisor untuk akses boss desk!");

            Dialog_Show(playerid, "DinarbucksBosDesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Dinarbucks", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_FOX11:
        {
            if(AccountData[playerid][pFactionRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Chief Officer untuk akses boss desk!");

            Dialog_Show(playerid, "PewartaBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Wartawan", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_DRIFTKING:
        {
            if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Vice Manager untuk akses boss desk!");

            Dialog_Show(playerid, "DriftKingBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu DriftKing", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_JAYAABADI:
        {
            if(AccountData[playerid][pFactionRank] < 4) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Vice Manager untuk akses boss desk!");

            Dialog_Show(playerid, "JayaAbadiBosdesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Jaya Abadi", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        case FACTION_SRIMERSING:
        {
            if(AccountData[playerid][pFactionRank] < 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Supervisor untuk akses boss desk!");

            Dialog_Show(playerid, "SriMersingBosDesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Menu Karens Dinner", 
            "Invite\n\
            Manage Ranks\n\
            Kick\n\
            Cek Saldo\n\
            Deposit Balance\n\
            Withdraw Balance", "Pilih", "Batal");
        }
        //     if(AccountData[playerid][pFactionRank] < 6) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jabatan minimum Supervisor untuk akses boss desk!");

        //     "Invite\n\
        //     Manage Ranks\n\
        //     Kick\n\
        //     Cek Saldo\n\
        //     Deposit Balance\n\
        //     Withdraw Balance", "Pilih", "Batal");
        // }
    }
    return 1;
}