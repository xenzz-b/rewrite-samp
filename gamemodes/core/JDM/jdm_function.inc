// ============================================================
// JDM SYSTEM - Japanese Domestic Market (Goodside)
// ============================================================

#include <YSI_Coding\y_hooks>

#define MAX_JDM 100
#define MAX_JDM_ITEMS 1000
#define MAX_JDM_HOLSTER 5

// ============================================================
// ENUMS
// ============================================================

enum e_jdm
{
    jdmID,
    jdmLeaderID,
    jdmLeaderName[32],
    jdmName[32],
    jdmMoney,
    jdmPoints,              // JDM Points / Reputation

    jdmVaultWorld,
    jdmVaultInt,
    Float:jdmVaultPos[3],
    jdmDeskWorld,
    jdmDeskInt,
    Float:jdmDeskPos[3],

    jdmGarageWorld,
    jdmGarageInt,
    Float:jdmGaragePos[3],
    jdmGarageSpWorld,
    jdmGarageSpInt,
    Float:jdmGarageSpPos[4],

    // not save
    STREAMER_TAG_3D_TEXT_LABEL:jdmVaultLabel,
    STREAMER_TAG_3D_TEXT_LABEL:jdmDeskLabel,
    STREAMER_TAG_OBJECT:jdmGarageObjid,
    STREAMER_TAG_PICKUP:jdmGaragePickup,
    STREAMER_TAG_3D_TEXT_LABEL:jdmGarageLabel
};

enum e_jdm_brankas
{
    jdmBrankasID,
    jdmBrankasJDMID,
    jdmBrankasItem[32],
    jdmBrankasModel,
    jdmBrankasQuant,
    bool:jdmBrankasExists
};

enum e_jdm_holster
{
    jdmHolsterID,
    bool:jdmHolsterTaken,
    jdmHolsterWeaponID,
    jdmHolsterWeaponAmmo
};

// ============================================================
// VARIABLES
// ============================================================

new JDMData[MAX_JDM][e_jdm],
    Iterator:JDMs<MAX_JDM>;

new JDMBrankas[MAX_JDM_ITEMS][e_jdm_brankas];
new JDMHolster[MAX_JDM][MAX_JDM_HOLSTER][e_jdm_holster];

// JDM Rank
static const JDMRank[7][] = 
{
    "N/A",       // 0
    "Newbie",    // 1
    "Enthusiast",// 2
    "Pro",       // 3
    "Elite",     // 4
    "Veteran",   // 5
    "Legend"     // 6
};

// ============================================================
// HELPER FUNCTIONS
// ============================================================

GetJDMName(jdm)
{
    new name[32];
    if(jdm != -1)
    {
        if(!isnull(JDMData[jdm][jdmName]))
            format(name, sizeof(name), "%s", JDMData[jdm][jdmName]);
        else
            format(name, sizeof(name), "Kosong");
    }
    else
        format(name, sizeof(name), "N/A");
    return name;
}

GetJDMLeaderName(jdm)
{
    new name[32];
    if(jdm != -1)
    {
        if(!isnull(JDMData[jdm][jdmLeaderName]))
            format(name, sizeof(name), "%s", JDMData[jdm][jdmLeaderName]);
        else
            format(name, sizeof(name), "Tidak Ada");
    }
    return name;
}

CountJDMOnline(jdm)
{
    new jumlah;
    if(jdm != -1)
    {
        foreach(new i : Player)
        {
            if(AccountData[i][pJDM] == jdm)
                jumlah++;
        }
    }
    return jumlah;
}

Player_JDMCount(playerid)
{
    new counting;
    foreach(new jid : JDMs)
    {
        if(JDMData[jid][jdmLeaderID] == AccountData[playerid][pID])
            counting++;
    }
    return counting;
}

Show_JDMInfo(playerid)
{
    new jid = AccountData[playerid][pJDM];
    if(jid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak tergabung dalam JDM manapun!");

    new info[1024];
    format(info, sizeof(info), "Nama JDM\t"YELLOW"%s\n", GetJDMName(jid));
    format(info, sizeof(info), "%sKetua\t"YELLOW"%s\n", info, GetJDMLeaderName(jid));
    format(info, sizeof(info), "%sPoin JDM\t"YELLOW"%d\n", info, JDMData[jid][jdmPoints]);
    format(info, sizeof(info), "%sAnggota Online\t"YELLOW"%d\n", info, CountJDMOnline(jid));
    format(info, sizeof(info), "%sRank Anda\t"YELLOW"%s\n", info, JDMRank[AccountData[playerid][pJDMRank]]);

    Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Informasi JDM", info, "Tutup", "");
    return 1;
}

// ============================================================
// VEHICLE FUNCTIONS
// ============================================================

CountPlayerVehicleJDM(playerid, jid)
{
    new tmpcount;
    foreach(new id : PvtVehicles)
    {
        if(PlayerVehicle[id][pVehOwnerID] == AccountData[playerid][pID])
        {
            if(!Iter_Contains(Vehicle, PlayerVehicle[id][pVehPhysic]) && PlayerVehicle[id][pVehJDMGarage] == jid)
            {
                tmpcount++;
            }
        }
    }
    return tmpcount;
}

ReturnAnyVehicleJDM(playerid, slot, jid)
{
    new tmpcount = -1;
    if(slot < 0 && slot > MAX_PRIVATE_VEHICLE - 1) return -1;
    foreach(new id : PvtVehicles)
    {
        if(PlayerVehicle[id][pVehOwnerID] == AccountData[playerid][pID])
        {
            if(PlayerVehicle[id][pVehJDMGarage] == jid && PlayerVehicle[id][pVehJDMGarage] > -1)
            {
                tmpcount++;
                if(tmpcount == slot)
                {
                    return id;
                }
            }
        }
    }
    return -1;
}

forward SaveVehicleToJDM(playerid, carid, jid);
public SaveVehicleToJDM(playerid, carid, jid)
{
    if(!IsPlayerConnected(playerid)) return 1;
    if(!AccountData[playerid][pSpawned]) return 1;
    if(PlayerVehicle[carid][pVehPhysic] == INVALID_VEHICLE_ID || !Iter_Contains(Vehicle, PlayerVehicle[carid][pVehPhysic])) return 1;
    if(!Iter_Contains(JDMs, jid)) return 1;
    if(!IsValidDynamicObject(JDMData[jid][jdmGarageObjid])) return 1;

    PlayerVehicle[carid][pVehJDMGarage] = jid;
    SetVehicleNeonLights(PlayerVehicle[carid][pVehPhysic], false, PlayerVehicle[carid][pVehNeon], 0);
    DestroyVehicle(PlayerVehicle[carid][pVehPhysic]);
    PlayerVehicle[carid][pVehPhysic] = INVALID_VEHICLE_ID;

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_vehicles` SET `PVeh_JDM` = %d WHERE `id` = %d", PlayerVehicle[carid][pVehJDMGarage], PlayerVehicle[carid][pVehID]);
    mysql_pquery(g_SQL, query);
    return 1;
}

// ============================================================
// JDM SAVE & LOAD
// ============================================================

JDM_Save(jid)
{
    new query[1024];
    mysql_format(g_SQL, query, sizeof(query), 
        "UPDATE `jdm` SET \
        `LeaderID`=%d, `LeaderName`='%e', `Name`='%e', `Money`=%d, `Points`=%d, \
        `VX`='%f', `VY`='%f', `VZ`='%f', `VW`=%d, `VI`=%d, \
        `DX`='%f', `DY`='%f', `DZ`='%f', `DW`=%d, `DI`=%d, \
        `GX`='%f', `GY`='%f', `GZ`='%f', `GW`=%d, `GI`=%d, \
        `GSX`='%f', `GSY`='%f', `GSZ`='%f', `GSA`='%f', `GSW`=%d, `GSI`=%d \
        WHERE `ID`=%d",
        JDMData[jid][jdmLeaderID],
        JDMData[jid][jdmLeaderName],
        JDMData[jid][jdmName],
        JDMData[jid][jdmMoney],
        JDMData[jid][jdmPoints],
        JDMData[jid][jdmVaultPos][0],
        JDMData[jid][jdmVaultPos][1],
        JDMData[jid][jdmVaultPos][2],
        JDMData[jid][jdmVaultWorld],
        JDMData[jid][jdmVaultInt],
        JDMData[jid][jdmDeskPos][0],
        JDMData[jid][jdmDeskPos][1],
        JDMData[jid][jdmDeskPos][2],
        JDMData[jid][jdmDeskWorld],
        JDMData[jid][jdmDeskInt],
        JDMData[jid][jdmGaragePos][0],
        JDMData[jid][jdmGaragePos][1],
        JDMData[jid][jdmGaragePos][2],
        JDMData[jid][jdmGarageWorld],
        JDMData[jid][jdmGarageInt],
        JDMData[jid][jdmGarageSpPos][0],
        JDMData[jid][jdmGarageSpPos][1],
        JDMData[jid][jdmGarageSpPos][2],
        JDMData[jid][jdmGarageSpPos][3],
        JDMData[jid][jdmGarageSpWorld],
        JDMData[jid][jdmGarageSpInt],
        jid);
    mysql_pquery(g_SQL, query);
    return 1;
}

JDM_Rebuild(jid)
{
    if(jid != -1)
    {
        if(IsValidDynamic3DTextLabel(JDMData[jid][jdmVaultLabel]))
            DestroyDynamic3DTextLabel(JDMData[jid][jdmVaultLabel]);
        JDMData[jid][jdmVaultLabel] = CreateDynamic3DTextLabel("[Y] "WHITE"untuk akses penyimpanan JDM", 
            Y_YELLOW, JDMData[jid][jdmVaultPos][0], JDMData[jid][jdmVaultPos][1], JDMData[jid][jdmVaultPos][2] + 0.35, 
            10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, JDMData[jid][jdmVaultWorld], JDMData[jid][jdmVaultInt], -1, 10.00, -1, 0);
    
        if(IsValidDynamic3DTextLabel(JDMData[jid][jdmDeskLabel]))
            DestroyDynamic3DTextLabel(JDMData[jid][jdmDeskLabel]);
        JDMData[jid][jdmDeskLabel] = CreateDynamic3DTextLabel("[Y] "WHITE"untuk akses bos desk JDM", 
            Y_YELLOW, JDMData[jid][jdmDeskPos][0], JDMData[jid][jdmDeskPos][1], JDMData[jid][jdmDeskPos][2] + 0.35, 
            10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, JDMData[jid][jdmDeskWorld], JDMData[jid][jdmDeskInt], -1, 10.00, -1, 0);
    
        if(IsValidDynamicObject(JDMData[jid][jdmGarageObjid]))
            DestroyDynamicObject(JDMData[jid][jdmGarageObjid]);
        JDMData[jid][jdmGarageObjid] = CreateDynamicObject(1316, 
            JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2] - 0.9, 
            0.0, 0.0, 0.0, JDMData[jid][jdmGarageWorld], JDMData[jid][jdmGarageInt], -1, 100.00, 100.00, -1);
        SetDynamicObjectMaterial(JDMData[jid][jdmGarageObjid], 0, 18646, "matcolours", "white", 0x3399FF91);

        if(IsValidDynamicPickup(JDMData[jid][jdmGaragePickup]))
            DestroyDynamicPickup(JDMData[jid][jdmGaragePickup]);
        if(IsValidDynamic3DTextLabel(JDMData[jid][jdmGarageLabel]))
            DestroyDynamic3DTextLabel(JDMData[jid][jdmGarageLabel]);

        JDMData[jid][jdmGaragePickup] = CreateDynamicPickup(1313, 23, 
            JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]-0.05, 
            JDMData[jid][jdmGarageWorld], JDMData[jid][jdmGarageInt], -1, 30.00, -1, 0);
        
        static strrs[144];
        format(strrs, sizeof(strrs), "[ "WHITE"(Garasi JDM): "YELLOW"%s "GREEN"]", JDMData[jid][jdmName]);
        JDMData[jid][jdmGarageLabel] = CreateDynamic3DTextLabel(strrs, Y_GREEN, 
            JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]+0.45, 
            10.00, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, JDMData[jid][jdmGarageWorld], JDMData[jid][jdmGarageInt], -1, 10.00, -1, 0);
    }
    return 1;
}

forward LoadJDM();
public LoadJDM()
{
    new rows = cache_num_rows();
    if(rows)
    {
        new jid;
        for(new i; i < rows; i++)
        {
            cache_get_value_name_int(i, "ID", jid);
            cache_get_value_name_int(i, "LeaderID", JDMData[jid][jdmLeaderID]);
            cache_get_value_name(i, "LeaderName", JDMData[jid][jdmLeaderName]);
            cache_get_value_name(i, "Name", JDMData[jid][jdmName]);
            cache_get_value_name_int(i, "Money", JDMData[jid][jdmMoney]);
            cache_get_value_name_int(i, "Points", JDMData[jid][jdmPoints]);

            cache_get_value_name_int(i, "VW", JDMData[jid][jdmVaultWorld]);
            cache_get_value_name_int(i, "VI", JDMData[jid][jdmVaultInt]);
            cache_get_value_name_float(i, "VX", JDMData[jid][jdmVaultPos][0]);
            cache_get_value_name_float(i, "VY", JDMData[jid][jdmVaultPos][1]);
            cache_get_value_name_float(i, "VZ", JDMData[jid][jdmVaultPos][2]);

            cache_get_value_name_int(i, "DW", JDMData[jid][jdmDeskWorld]);
            cache_get_value_name_int(i, "DI", JDMData[jid][jdmDeskInt]);
            cache_get_value_name_float(i, "DX", JDMData[jid][jdmDeskPos][0]);
            cache_get_value_name_float(i, "DY", JDMData[jid][jdmDeskPos][1]);
            cache_get_value_name_float(i, "DZ", JDMData[jid][jdmDeskPos][2]);

            cache_get_value_name_int(i, "GW", JDMData[jid][jdmGarageWorld]);
            cache_get_value_name_int(i, "GI", JDMData[jid][jdmGarageInt]);
            cache_get_value_name_float(i, "GX", JDMData[jid][jdmGaragePos][0]);
            cache_get_value_name_float(i, "GY", JDMData[jid][jdmGaragePos][1]);
            cache_get_value_name_float(i, "GZ", JDMData[jid][jdmGaragePos][2]);

            cache_get_value_name_int(i, "GSW", JDMData[jid][jdmGarageSpWorld]);
            cache_get_value_name_int(i, "GSI", JDMData[jid][jdmGarageSpInt]);
            cache_get_value_name_float(i, "GSX", JDMData[jid][jdmGarageSpPos][0]);
            cache_get_value_name_float(i, "GSY", JDMData[jid][jdmGarageSpPos][1]);
            cache_get_value_name_float(i, "GSZ", JDMData[jid][jdmGarageSpPos][2]);
            cache_get_value_name_float(i, "GSA", JDMData[jid][jdmGarageSpPos][3]);

            JDM_Rebuild(jid);
            Iter_Add(JDMs, jid);
        }
        printf("[Dynamic JDM] Total number of loaded JDM: %d.", rows);
    }
    return 1;
}

// ============================================================
// BRANKAS FUNCTIONS (JDM Vault)
// ============================================================

static bool:IsJDMItemValid(slot)
{
    new bool:itemExists = false;
    for(new i = 0; i < sizeof(g_aInventoryItems); i++) 
    {
        if(!strcmp(JDMBrankas[slot][jdmBrankasItem], g_aInventoryItems[i][e_InventoryItem], true)) {
            itemExists = true;
            break;
        }
    }
 
    if(!itemExists) 
    {
        JDMBrankas[slot][jdmBrankasExists] = false;
        JDMBrankas[slot][jdmBrankasModel] = 0;
        JDMBrankas[slot][jdmBrankasQuant] = 0;
        JDMBrankas[slot][jdmBrankasJDMID] = -1;
        JDMBrankas[slot][jdmBrankasItem][0] = EOS;
 
        static invstr[555];
        mysql_format(g_SQL, invstr, sizeof(invstr), "DELETE FROM `jdm_brankas` WHERE `ID`=%d", JDMBrankas[slot][jdmBrankasID]);
        mysql_pquery(g_SQL, invstr);
    }
    return itemExists;
}

forward LoadJDMBrankas();
public LoadJDMBrankas()
{
    if(cache_num_rows() > 0)
    {
        for(new x; x < cache_num_rows(); x++)
        {
            if(!JDMBrankas[x][jdmBrankasExists])
            {
                JDMBrankas[x][jdmBrankasExists] = true;
                cache_get_value_name_int(x, "ID", JDMBrankas[x][jdmBrankasID]);
                cache_get_value_name_int(x, "JDMID", JDMBrankas[x][jdmBrankasJDMID]);
                cache_get_value_name(x, "Item", JDMBrankas[x][jdmBrankasItem]);
                cache_get_value_name_int(x, "Model", JDMBrankas[x][jdmBrankasModel]);
                cache_get_value_name_int(x, "Quantity", JDMBrankas[x][jdmBrankasQuant]);

                if(!IsJDMItemValid(x)) 
                {
                    
                }
            }
        }
    }
    return 1;
}

forward OnJDMBrankasDeposit(playerid, id);
public OnJDMBrankasDeposit(playerid, id)
{
    AccountData[playerid][pMenuShowed] = false;
    JDMBrankas[id][jdmBrankasID] = cache_insert_id();
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil menyimpan item tersebut.");
    return 1;
}

ShowJDMBrankas(playerid)
{
    new 
        curr_page = index_pagination[playerid],
        count = 0,
        string[1012],
        real_i = 0,
        brankas_exists[MAX_PAGINATION_PAGES],
        brankas_item[MAX_PAGINATION_PAGES][32],
        brankas_model[MAX_PAGINATION_PAGES],
        brankas_quant[MAX_PAGINATION_PAGES],
        brankas_id[MAX_PAGINATION_PAGES],
        curr_idx;

    curr_idx = MAX_PAGINATION_PAGES * curr_page;

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++) 
    {
        brankas_exists[i] = false;
    }

    strcat(string, "Nama Item\tJumlah\n");
    for(new i = 0; i < MAX_JDM_ITEMS; i++) 
    {
        if (JDMBrankas[i][jdmBrankasExists] && JDMBrankas[i][jdmBrankasJDMID] == AccountData[playerid][pJDM])
        {
            if (real_i >= curr_idx && real_i < curr_idx + MAX_PAGINATION_PAGES)
            {
                brankas_exists[real_i - curr_idx] = true;
                brankas_id[real_i - curr_idx] = i;
                brankas_model[real_i - curr_idx] = JDMBrankas[i][jdmBrankasModel];
                strcopy(brankas_item[real_i - curr_idx], JDMBrankas[i][jdmBrankasItem], 32);
                brankas_quant[real_i - curr_idx] = JDMBrankas[i][jdmBrankasQuant];
            }
            real_i++;
        }
    }

    for(new i = 0; i < MAX_PAGINATION_PAGES; i++) 
    {
        if(brankas_exists[i]) 
        {
            if (i % 2 == 0)
            {
                strcat(string, sprintf(""WHITE"%s\t"WHITE"%d\n", brankas_item[i], brankas_quant[i]));
            }
            else
            {
                strcat(string, sprintf(""GRAY"%s\t"GRAY"%d\n", brankas_item[i], brankas_quant[i]));
            }
            PlayerListitem[playerid][count++] = brankas_id[i];
        }
    }

    if(count == 0) 
    {
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Lemari JDM", "Lemari penyimpanan ini kosong!", "Tutup", "");
    } 
    else 
    {
        new max_pages = (real_i + MAX_PAGINATION_PAGES - 1) / MAX_PAGINATION_PAGES;

        if (curr_page > 0) {
            strcat(string, ""RED"<< Sebelumnya\n");
        }
        if (curr_page < max_pages - 1) {
            strcat(string, ""GREEN">> Selanjutnya\n");
        }

        Dialog_Show(playerid, "JDMVaultWithdraw", DIALOG_STYLE_TABLIST_HEADERS, sprintf("Lemari JDM: Page %d of %d", curr_page + 1, max_pages),
        string, "Pilih", "Batal");
    }
    return 1;
}

// ============================================================
// JDM HOLSTER FUNCTIONS
// ============================================================

forward LoadJDMHolster(jid);
public LoadJDMHolster(jid)
{
    new count = cache_num_rows();
    if (count)
    {
        for (new i = 0; i < count; i++)
        {
            for (new z = 0; z < MAX_JDM_HOLSTER; z++)
            {
                if (!JDMHolster[jid][z][jdmHolsterTaken])
                {
                    cache_get_value_name_int(i, "ID",         JDMHolster[jid][z][jdmHolsterID]);
                    cache_get_value_name_int(i, "WeaponID",  JDMHolster[jid][z][jdmHolsterWeaponID]);
                    cache_get_value_name_int(i, "WeaponAmmo",JDMHolster[jid][z][jdmHolsterWeaponAmmo]);

                    JDMHolster[jid][z][jdmHolsterTaken] = true;
                    break;
                }
            }
        }
    }
    return 1;
}

forward OnWeaponJDMStored(jid, slot);
public OnWeaponJDMStored(jid, slot)
{
    JDMHolster[jid][slot][jdmHolsterID] = cache_insert_id();
    return 1;
}

// ============================================================
// RANK MANAGEMENT
// ============================================================

Show_JDMRankManage(playerid)
{
    new 
        string[1012],
        member_name[MAX_MEMBER_ROWS][64],
        member_pID[MAX_MEMBER_ROWS],
        member_rank[MAX_MEMBER_ROWS],
        member_lastlog[MAX_MEMBER_ROWS][30],
        curr_page = index_pagination[playerid],
        curr_index;

    curr_index = curr_page * MAX_MEMBER_ROWS;

    for(new i = 0; i < MAX_MEMBER_ROWS; i++) {
        member_pID[i] = 0;
    }

    new real_i = 0;
    
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_JDM` = %d ORDER BY `Char_JDMRank` DESC", AccountData[playerid][pJDM]);
    mysql_query(g_SQL, query);

    new rows = cache_num_rows(),
        count = 0;

    if(rows)
    {
        for(new i = curr_index; i < rows; i++) if(i <= rows)
        {
            if(real_i < sizeof(member_pID)) {
                cache_get_value_name(i, "Char_Name", member_name[real_i]);
                cache_get_value_name_int(i, "Char_JDMRank", member_rank[real_i]);
                cache_get_value_name(i, "Char_LastLogin", member_lastlog[real_i]);
                cache_get_value_name_int(i, "pID", member_pID[real_i]); 
                real_i++;
            }
            else {
                break;
            }
        }

        strcat(string, "Nama\tRank\tLast Online\n");

        for(new i = 0; i < real_i; ++i) if(member_pID[i] != 0)
        {
            strcat(string, sprintf("%s\t%s\t%s\n", member_name[i], JDMRank[member_rank[i]], member_lastlog[i]));
            ListedMember[playerid][count++] = member_pID[i];
        }

        new 
            total_pages = (rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS;
        new 
            max_page = total_pages - 1; 

        TempRows[playerid] = rows;

        if(curr_page > 0) {
            strcat(string, ""RED"<< Sebelumnya");
            strcat(string, "\n");
        }
        if(curr_page < max_page) {
            strcat(string, ""GREEN">> Selanjutnya"); 
            strcat(string, "\n");
        }

        Dialog_Show(playerid, "JDMSetRank", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Manage Rank JDM", string, "Pilih", "Batal");
    }
    else
    {
        PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Manage Rank JDM", "Anda tidak memiliki member di JDM ini!", "Tutup", "");
    }
    return 1;
}

Show_JDMKick(playerid) 
{
    new 
        string[1012],
        member_name[MAX_MEMBER_ROWS][64],
        member_pID[MAX_MEMBER_ROWS],
        member_rank[MAX_MEMBER_ROWS],
        member_lastlog[MAX_MEMBER_ROWS][30],
        curr_page = index_pagination[playerid],
        curr_index;

    curr_index = curr_page * MAX_MEMBER_ROWS;

    for(new i = 0; i < MAX_MEMBER_ROWS; i++) {
        member_pID[i] = 0;
    }

    new real_i = 0;
    new query[512];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_characters` WHERE `Char_JDM` = %d ORDER BY `Char_JDMRank` DESC", AccountData[playerid][pJDM]);
    mysql_query(g_SQL, query);

    new rows = cache_num_rows(),
        count = 0;

    if(rows)
    {
        for(new i = curr_index; i < rows && real_i < MAX_MEMBER_ROWS; i++)
        {
            cache_get_value_name(i, "Char_Name", member_name[real_i]);
            cache_get_value_name_int(i, "Char_JDMRank", member_rank[real_i]);
            cache_get_value_name(i, "Char_LastLogin", member_lastlog[real_i]);
            cache_get_value_name_int(i, "pID", member_pID[real_i]); 
            real_i++;
        }

        strcat(string, "Nama\tRank\tLast Online\n");

        for(new i = 0; i < real_i; ++i)
        {
            strcat(string, sprintf("%s\t%s\t%s\n", member_name[i], JDMRank[member_rank[i]], member_lastlog[i]));
            ListedMember[playerid][count++] = member_pID[i];
        }

        new total_pages = (rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS;
        new max_page = total_pages - 1;

        if(curr_page > 0) {
            strcat(string, ""RED"<< Sebelumnya");
            strcat(string, "\n");
        }
        if(curr_page < max_page) {
            strcat(string, ""GREEN">> Selanjutnya");
            strcat(string, "\n");
        }

        Dialog_Show(playerid, "JDMKickMember", DIALOG_STYLE_TABLIST_HEADERS, ""Vertex"Vertex Roleplay "WHITE"- Kick Member JDM", string, "Pilih", "Batal");
    }
    else
    {
        PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, ""Vertex"Vertex Roleplay "WHITE"- Kick Member JDM", "Anda tidak memiliki member di JDM ini!", "Tutup", "");
    }
    return 1;
}

// ============================================================
// HOOK ON PLAYER KEY STATE CHANGE
// ============================================================

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Ctrl+B untuk interaksi dengan player (seperti family)
    if(newkeys & KEY_CTRL_BACK && AccountData[playerid][pJDM] > -1 && AccountData[playerid][pJDMRank] > 1 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(AccountData[playerid][pInEvent]) return 1;
        
        new count = 0, str[522];
        foreach(new i : Player) if(i != playerid) if(IsPlayerNearPlayer(playerid, i, 2.5)) 
        {
            if (i % 2 == 0) 
            {
                format(str, sizeof(str), "%s"WHITE"Player ID - (%d)\n", str, i);
            }
            else 
            {
                format(str, sizeof(str), "%s"GRAY"Player ID - (%d)\n", str, i);
            }
            NearestUser[playerid][count++] = i;
        }

        if(count > 0) 
        {
            Dialog_Show(playerid, "JDMPanel", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- JDM Panel", 
            str, "Pilih", "Batal");
        }
    }
    // KEY_YES untuk akses vault, desk, garage
    else if(newkeys & KEY_YES && AccountData[playerid][pJDM] > -1 && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        new jid = AccountData[playerid][pJDM];
        
        // Akses Vault (brankas)
        if(IsPlayerInRangeOfPoint(playerid, 1.0, JDMData[jid][jdmVaultPos][0], JDMData[jid][jdmVaultPos][1], JDMData[jid][jdmVaultPos][2]))
        {
            AccountData[playerid][pMenuShowed] = true;
            Dialog_Show(playerid, "JDMChest", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Brankas JDM", 
            "Brankas\n"GRAY"Weapon Brankas", "Pilih", "Kembali");
        }

        // Akses Garage
        if(IsPlayerInRangeOfPoint(playerid, 3.5, JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]))
        {
            if(JDMData[jid][jdmGaragePos][0] == 0.0 && JDMData[jid][jdmGaragePos][1] == 0.0 && JDMData[jid][jdmGaragePos][2] == 0.0) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Garasi JDM ini belum memiliki titik despawn!");
            if(JDMData[jid][jdmGarageSpPos][0] == 0.0 && JDMData[jid][jdmGarageSpPos][1] == 0.0 && JDMData[jid][jdmGarageSpPos][2] == 0.0) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Garasi JDM ini belum memiliki titik spawn kendaraan!");

            if(CountPlayerVehicleJDM(playerid, jid) < 1) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan yang tersimpan di garasi!");

            AccountData[playerid][pInGarkot] = jid;
            new id, count = CountPlayerVehicleJDM(playerid, jid), location[512], lstr[596];

            strcat(location,"No\tModel Kendaraan\tNomor Plat\n",sizeof(location));
            for(new itt; itt < count; itt++)
            {
                id = ReturnAnyVehicleJDM(playerid, itt, jid);
                format(lstr,sizeof(lstr), "%d\t%s\t%s\n", itt + 1, GetVehicleModelName(PlayerVehicle[id][pVehModelID]), PlayerVehicle[id][pVehPlate]);
                strcat(location,lstr,sizeof(location));
            }
            Dialog_Show(playerid, "JDMGarage", DIALOG_STYLE_TABLIST_HEADERS,"Garasi JDM - Ambil Kendaraan", location, "Pilih","Batal");
            HideNotifBox(playerid);
        }

        // Akses Bos Desk (hanya rank 5-6)
        if(AccountData[playerid][pJDMRank] > 4)
        {
            if(IsPlayerInRangeOfPoint(playerid, 1.0, JDMData[jid][jdmDeskPos][0], JDMData[jid][jdmDeskPos][1], JDMData[jid][jdmDeskPos][2]))
            {
                Dialog_Show(playerid, "JDMBosDesk", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Bos Desk JDM", 
                "Invite\n\
                "GRAY"Kelola Jabatan\n\
                Kick\n\
                "GRAY"Saldo JDM\n\
                Deposit Saldo\n\
                "GRAY"Withdraw Saldo\n\
                Deposit Poin\n\
                "GRAY"Withdraw Poin", "Pilih", "Batal");
            }
        }
    }
    // KEY_CROUCH untuk menyimpan kendaraan ke garasi
    else if(newkeys & KEY_CROUCH && AccountData[playerid][pJDM] > -1 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        new jid = AccountData[playerid][pJDM];
        if(IsPlayerInRangeOfPoint(playerid, 3.5, JDMData[jid][jdmGaragePos][0], JDMData[jid][jdmGaragePos][1], JDMData[jid][jdmGaragePos][2]))
        {
            if(JDMData[jid][jdmGaragePos][0] == 0.0 && JDMData[jid][jdmGaragePos][1] == 0.0 && JDMData[jid][jdmGaragePos][2] == 0.0) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Garasi JDM ini belum memiliki titik despawn!");
            if(JDMData[jid][jdmGarageSpPos][0] == 0.0 && JDMData[jid][jdmGarageSpPos][1] == 0.0 && JDMData[jid][jdmGarageSpPos][2] == 0.0) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Garasi JDM ini belum memiliki titik spawn kendaraan!");

            new carid = -1;

            if((carid = GetPlayerVehicleIDInside(playerid)) != -1)
            {
                if(PlayerVehicle[carid][pVehOwnerID] != AccountData[playerid][pID]) 
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini bukan milik anda!");
                if(PlayerVehicle[carid][pVehRental] > -1 || PlayerVehicle[carid][pVehRentTime] > 0) 
                    return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menyimpan kendaraan rental!");
                Vehicle_GetStatus(carid);
                HideNotifBox(playerid);
                
                RemovePlayerFromVehicle(playerid);
                SetTimerEx("SaveVehicleToJDM", 2500, false, "idd", playerid, carid, jid);
            }
            else
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Ini bukan jenis kendaraan pribadi!");
        }
    }
    return 1;
}

// ============================================================
// DIALOGS
// ============================================================

// Panel Interaksi JDM
Dialog:JDMPanel(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    new targetid = NearestSingle[playerid];
    if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!IsPlayerNearPlayer(playerid, targetid, 3.0)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak dekat dengan anda!");
    if(AccountData[playerid][pKnockdown]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Karakter anda terluka parah saat ini!");
    
    switch(listitem)
    {
        case 0: // Cek Info Member
        {
            new info[512];
            format(info, sizeof(info), "Nama: %s\nRank: %s\nPoin JDM: %d\nJDM: %s", 
                ReturnName(targetid),
                JDMRank[AccountData[targetid][pJDMRank]],
                JDMData[AccountData[playerid][pJDM]][jdmPoints],
                GetJDMName(AccountData[playerid][pJDM]));
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Informasi Member JDM", info, "Tutup", "");
        }
        case 1: // Transfer Poin
        {
            Dialog_Show(playerid, "JDMTransferPoints", DIALOG_STYLE_INPUT, "Transfer Poin JDM", 
                sprintf("Masukkan jumlah poin yang ingin ditransfer ke %s:", ReturnName(targetid)), "Transfer", "Batal");
        }
    }
    return 1;
}

// Bos Desk JDM
Dialog:JDMBosDesk(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if(AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi JDM!");

    switch(listitem)
    {
        case 0: // Invite
        {
            new str[522], count = 0;
            foreach(new i : Player) if(i != playerid) if(IsPlayerNearPlayer(playerid, i, 1.5)) 
            {
                if (i % 2 == 0) {
                    format(str, sizeof(str), "%s"WHITE"Player ID - (%d)\n", str, i);
                }
                else {
                    format(str, sizeof(str), "%s"GRAY"Player ID - (%d)\n", str, i);
                }
                NearestUser[playerid][count++] = i;
            }

            if(count == 0)
            {
                PlayerPlaySound(playerid, 5206, 0.0, 0.0, 0.0);
                return Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Invite JDM", "Tidak ada pemain terdekat!", "Tutup", "");
            }
            Dialog_Show(playerid, "JDMInviteConfirm", DIALOG_STYLE_TABLIST, "Invite JDM", str, "Pilih", "Batal");
        }
        case 1: // Kelola Jabatan
        {
            index_pagination[playerid] = 0;
            Show_JDMRankManage(playerid);
        }
        case 2: // Kick
        {
            index_pagination[playerid] = 0;
            Show_JDMKick(playerid);
        }
        case 3: // Saldo JDM
        {
            new rtx[158];
            format(rtx, sizeof(rtx), "JDM ini memiliki saldo sebesar:\n"DARKGREEN"$%s\n"YELLOW"Poin: %d", 
                FormatMoney(JDMData[AccountData[playerid][pJDM]][jdmMoney]), 
                JDMData[AccountData[playerid][pJDM]][jdmPoints]);
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "JDM Money Vault", rtx, "Tutup", "");
        }
        case 4: // Deposit Saldo
        {
            Dialog_Show(playerid, "JDMDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang JDM", 
                "Mohon masukkan nominal deposit untuk saldo JDM:", "Input", "Batal");
        }
        case 5: // Withdraw Saldo
        {
            Dialog_Show(playerid, "JDMWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang JDM", 
                "Mohon masukkan nominal penarikan tunai dari saldo JDM:", "Input", "Batal");
        }
        case 6: // Deposit Poin
        {
            Dialog_Show(playerid, "JDMDepositPoints", DIALOG_STYLE_INPUT, "Deposit Poin JDM", 
                "Mohon masukkan nominal poin yang ingin disimpan:", "Input", "Batal");
        }
        case 7: // Withdraw Poin
        {
            Dialog_Show(playerid, "JDMWithdrawPoints", DIALOG_STYLE_INPUT, "Withdraw Poin JDM", 
                "Mohon masukkan nominal poin yang ingin diambil:", "Input", "Batal");
        }
    }
    return 1;
}

// JDM Chest (Brankas)
Dialog:JDMChest(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    switch(listitem)
    {
        case 0: // Brankas Barang
        {
            AccountData[playerid][pMenuShowed] = true;
            Dialog_Show(playerid, "JDMVault", DIALOG_STYLE_LIST, "Brankas JDM", 
                "Simpan Barang\n"GRAY"Ambil Barang", "Pilih", "Kembali");
        }
        case 1: // Weapon Chest
        {
            AccountData[playerid][pMenuShowed] = true;
            Dialog_Show(playerid, "JDMHolsterMenu", DIALOG_STYLE_LIST, "Weapon Chest JDM", 
                "Simpan Senjata\n"GRAY"Ambil Senjata", "Pilih", "Batal");
        }
    }
    return 1;
}

// JDM Vault (Simpan/Ambil Barang)
Dialog:JDMVault(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
        return 1;
    }

    switch(listitem)
    {
        case 0: // Deposit
        {
            new str[1218], count;
            static invrow[144];
            format(str, sizeof(str), "Nama Item\tJumlah\n");
            for(new index; index < MAX_INVENTORY; index++)
            {
                if(InventoryData[playerid][index][invExists])
                {
                    for(new i; i < sizeof(g_aInventoryItems); i++) 
                        if (!strcmp(g_aInventoryItems[i][e_InventoryItem], InventoryData[playerid][index][invItem], true))
                    {
                        format(invrow, sizeof(invrow), "%s\t%d\n", InventoryData[playerid][index][invItem], InventoryData[playerid][index][invQuantity]);
                        strcat(str, invrow);
                        PlayerListitem[playerid][count++] = index;
                    }
                }
            }

            if(count == 0)
            {
                Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Lemari JDM", 
                    "Anda tidak memiliki barang yang dapat disimpan!", "Tutup", "");
            }
            else
            {
                Dialog_Show(playerid, "JDMVaultDeposit", DIALOG_STYLE_TABLIST_HEADERS, "Lemari JDM", str, "Pilih", "Batal");
            }
        }
        case 1: // Withdraw
        {
            if(AccountData[playerid][pJDMRank] < 5) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi JDM!");
            index_pagination[playerid] = 0;
            ShowJDMBrankas(playerid);
        }
    }
    return 1;
}

// JDM Vault Deposit
Dialog:JDMVaultDeposit(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
        return 1;
    }

    if(listitem == -1) 
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
    }

    AccountData[playerid][pTempValue] = listitem;

    if(!strcmp(InventoryData[playerid][PlayerListitem[playerid][listitem]][invItem], "Changename Card")) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menyimpan Changename Card ke penyimpanan manapun!");
    
    new str[528];
    format(str, sizeof(str), "Anda akan menyimpan item:\nNama: "CYAN"%s\n"WHITE"Jumlah di tas: "YELLOW"%d\n"WHITE"Masukkan jumlah yang ingin disimpan:", 
        InventoryData[playerid][PlayerListitem[playerid][listitem]][invItem], 
        InventoryData[playerid][PlayerListitem[playerid][listitem]][invQuantity]);
    Dialog_Show(playerid, "JDMVaultIn", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
    return 1;
}

// JDM Vault Withdraw
Dialog:JDMVaultWithdraw(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
        return 1;
    }

    if(listitem == -1) 
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
    }

    if(!strcmp(inputtext, ">> Selanjutnya", true)) 
    {
        index_pagination[playerid]++;
        ShowJDMBrankas(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true)) 
    {
        index_pagination[playerid]--;
        if(index_pagination[playerid] <= 0) index_pagination[playerid] = 0;
        ShowJDMBrankas(playerid);
    }
    else 
    {
        if(PlayerListitem[playerid][listitem] == -1)
        {
            AccountData[playerid][pMenuShowed] = false;
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
        }
        
        AccountData[playerid][pTempValue] = listitem;
        new str[528];
        format(str, sizeof(str), "Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Masukkan jumlah yang ingin diambil:", 
            JDMBrankas[PlayerListitem[playerid][listitem]][jdmBrankasItem], 
            JDMBrankas[PlayerListitem[playerid][listitem]][jdmBrankasQuant]);
        Dialog_Show(playerid, "JDMVaultOut", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
    }
    return 1;
}

// JDM Holster Menu
Dialog:JDMHolsterMenu(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    new jid = AccountData[playerid][pJDM]; 
    if(jid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki JDM!");

    switch(listitem)
    {
        case 0: // Simpan senjata
        {
            new wpid = GetPlayerWeaponEx(playerid);
            if(wpid < 1 || wpid > 46) 
            {
                AccountData[playerid][pMenuShowed] = false;
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak sedang memegang senjata apapun!");
            }

            for(new slot = 0; slot < MAX_JDM_HOLSTER; slot++)
            {
                if(!JDMHolster[jid][slot][jdmHolsterTaken]) 
                {
                    JDMHolster[jid][slot][jdmHolsterTaken] = true;
                    GetPlayerWeaponData(playerid, g_aWeaponSlots[wpid], 
                        JDMHolster[jid][slot][jdmHolsterWeaponID], 
                        JDMHolster[jid][slot][jdmHolsterWeaponAmmo]);

                    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda telah menyimpan %s ke dalam weapon chest!", ReturnWeaponName(wpid)));
                    ResetWeapon(playerid, wpid);

                    new query[256];
                    mysql_format(g_SQL, query, sizeof(query), 
                        "INSERT INTO `jdm_holster` (`JDM_DBID`, `WeaponID`, `WeaponAmmo`) VALUES (%d, %d, %d)", 
                        jid, 
                        JDMHolster[jid][slot][jdmHolsterWeaponID],
                        JDMHolster[jid][slot][jdmHolsterWeaponAmmo]);
                    mysql_pquery(g_SQL, query, "OnWeaponJDMStored", "ii", jid, slot);

                    AccountData[playerid][pMenuShowed] = false;
                    return 1;
                }
            }
            ShowTDN(playerid, NOTIFICATION_ERROR, "Weapon chest JDM ini sudah penuh!");
            AccountData[playerid][pMenuShowed] = false;
        }
        case 1: // Ambil senjata
        {
            new dialogstr[512], count;
            format(dialogstr, sizeof(dialogstr), "#\tWeapon\tAmmo\n");

            for(new slot = 0; slot < MAX_JDM_HOLSTER; slot++)
            {
                if(JDMHolster[jid][slot][jdmHolsterTaken]) 
                {
                    format(dialogstr, sizeof(dialogstr), "%s%d\t%s\t%d\n", dialogstr, slot + 1,
                        ReturnWeaponName(JDMHolster[jid][slot][jdmHolsterWeaponID]),
                        JDMHolster[jid][slot][jdmHolsterWeaponAmmo]);
                    count++;
                }
                else
                {
                    format(dialogstr, sizeof(dialogstr), "%s"GREEN"%d\t"GREEN"Kosong\t"GREEN"0\n", dialogstr, slot + 1);
                }
            }

            if(count == 0)
                ShowTDN(playerid, NOTIFICATION_ERROR, "Weapon chest JDM ini kosong!");
            else
                Dialog_Show(playerid, "JDMHolsterWithdraw", DIALOG_STYLE_TABLIST_HEADERS, "Weapon Chest JDM", dialogstr, "Pilih", "Batal");
        }
    }
    return 1;
}

// JDM Invite Confirm
Dialog:JDMInviteConfirm(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (listitem == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih!");
    if (AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if (AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari JDM ini!");

    new targetid = NearestUser[playerid][listitem], query[128];
    if (!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(AccountData[targetid][pLevel] < 3) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut harus memiliki level setidaknya 3!");
    
    AccountData[targetid][pJDM] = AccountData[playerid][pJDM];
    AccountData[targetid][pJDMRank] = 1;
    
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_JDM` = %d, `Char_JDMRank` = 1 WHERE `pID` = %d", 
        AccountData[targetid][pJDM], AccountData[targetid][pID]);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(targetid, NOTIFICATION_INFO, sprintf("Anda telah diundang menjadi anggota %s oleh %s.", GetJDMName(AccountData[targetid][pJDM]), AccountData[playerid][pName]));
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil mengundang %s ke dalam JDM.", AccountData[targetid][pName]));
    return 1;
}

// JDM Set Rank
Dialog:JDMSetRank(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if(listitem == -1) return 1;
    
    if(!strcmp(inputtext, ">> Selanjutnya", true)) 
    {
        index_pagination[playerid]++;
        new rows = TempRows[playerid];
        new max_page = ((rows + MAX_MEMBER_ROWS - 1) / MAX_MEMBER_ROWS) - 1;
        if(index_pagination[playerid] >= max_page) index_pagination[playerid] = max_page;
        Show_JDMRankManage(playerid);
    }
    else if(!strcmp(inputtext, "<< Sebelumnya", true)) 
    {
        index_pagination[playerid]--;
        if(index_pagination[playerid] <= 0) index_pagination[playerid] = 0;
        Show_JDMRankManage(playerid);
    }
    else
    {
        if(AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
        if(AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi JDM!");

        mysql_query(g_SQL, sprintf("SELECT * FROM `player_characters` WHERE `pID` = '%d'", ListedMember[playerid][listitem]));
        new rows = cache_num_rows();
        if(rows)
        {
            cache_get_value_name_int(0, "pID", AccountData[playerid][pTempSQLFactMemberID]);
            cache_get_value_name_int(0, "Char_JDMRank", AccountData[playerid][pTempSQLFactRank]);
            
            if(AccountData[playerid][pID] == AccountData[playerid][pTempSQLFactMemberID]) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menetapkan rank anda sendiri!");
            if(AccountData[playerid][pTempSQLFactRank] >= AccountData[playerid][pJDMRank]) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat menetapkan rank rekan yang sejajar/lebih tinggi dari anda!");
            
            Dialog_Show(playerid, "JDMSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank JDM", 
                "Silahkan pilih jabatan untuk ditetapkan (masukkan angka saja):\n\
                1. Newbie\n\
                2. Enthusiast\n\
                3. Pro\n\
                4. Elite\n\
                5. Veteran\n\
                6. Legend", "Set", "Batal");
        }
    }
    return 1;
}

// JDM Set Rank Confirm
Dialog:JDMSetRankConfirm(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if (AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari JDM ini!");

    if (isnull(inputtext)) 
        return Dialog_Show(playerid, "JDMSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank JDM",
        "Error: Tidak dapat dikosongkan!\nSilahkan pilih jabatan (1-6):", "Set", "Batal");

    if (!IsNumericEx(inputtext)) 
        return Dialog_Show(playerid, "JDMSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank JDM",
        "Error: Masukkan hanya angka!\nSilahkan pilih jabatan (1-6):", "Set", "Batal");

    new rank = strval(inputtext);
    if (rank < 1 || rank > 6) 
        return Dialog_Show(playerid, "JDMSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank JDM",
        "Error: Pilihan tidak valid! (1-6)\nSilahkan pilih jabatan (1-6):", "Set", "Batal");
    
    if(rank >= AccountData[playerid][pJDMRank]) 
        return Dialog_Show(playerid, "JDMSetRankConfirm", DIALOG_STYLE_INPUT, "Manage Rank JDM",
        "Error: Tidak dapat memberikan rank yang sama atau lebih tinggi dari anda!\nSilahkan pilih jabatan (1-6):", "Set", "Batal");

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_JDMRank`=%d WHERE `pID`=%d", 
        rank, AccountData[playerid][pTempSQLFactMemberID]);
    mysql_pquery(g_SQL, query);

    foreach (new i : Player)
    {
        if (AccountData[i][IsLoggedIn] && AccountData[i][pSpawned] && AccountData[playerid][pTempSQLFactMemberID] == AccountData[i][pID])
        {
            AccountData[i][pJDMRank] = rank;
            ShowTDN(i, NOTIFICATION_INFO, sprintf("Jabatan baru anda di JDM telah diubah menjadi %s", JDMRank[rank]));
        }
    }

    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mengubah jabatan JDM Pemain tersebut");
    return 1;
}

// JDM Kick Member
Dialog:JDMKickMember(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if (!strcmp(inputtext, ">> Selanjutnya", true)) 
    {
        index_pagination[playerid]++;
        Show_JDMKick(playerid);
    }
    else if (!strcmp(inputtext, "<< Sebelumnya", true)) 
    {
        index_pagination[playerid]--;
        if (index_pagination[playerid] < 0) index_pagination[playerid] = 0;
        Show_JDMKick(playerid);
    }
    else 
    {
        new member_pid = ListedMember[playerid][listitem];

        if(AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
        if(AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi JDM!");

        mysql_query(g_SQL, sprintf("SELECT * FROM `player_characters` WHERE `pID` = %d", member_pid));
        new rows = cache_num_rows();
        if (rows) 
        {
            new member_name[64], member_rank, member_lastlogin[30], kickstr[225], query[128];
            cache_get_value_name(0, "Char_Name", member_name);
            cache_get_value_name_int(0, "Char_JDMRank", member_rank);
            cache_get_value_name(0, "Char_LastLogin", member_lastlogin);

            if(AccountData[playerid][pID] == member_pid) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya terhadap diri sendiri!");
            if(member_rank >= AccountData[playerid][pJDMRank]) 
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat kick player yang ranknya lebih tinggi atau sama dengan anda!");

            foreach(new i : Player)
            {
                if(member_pid == AccountData[i][pID])
                {
                    AccountData[i][pJDM] = -1;
                    AccountData[i][pJDMRank] = 0;
                    SendClientMessage(i, Y_SERVER, "(Server) "WHITE"Anda telah dikeluarkan dari JDM!");
                }
            }

            mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_JDM` = -1, `Char_JDMRank` = 0 WHERE `pID` = %d", member_pid);
            mysql_pquery(g_SQL, query);

            format(kickstr, sizeof(kickstr), "Anda berhasil mengeluarkan:\nNama: %s\nRank: %s\nLast Online: %s", 
                member_name, JDMRank[member_rank], member_lastlogin);
            Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX, "Kick Member JDM", kickstr, "Tutup", "");
        }
    }
    return 1;
}

// JDM Vault In (Deposit)
Dialog:JDMVaultIn(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
        return 1;
    }

    if(AccountData[playerid][pTempValue] == -1)
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
    }

    new str[512], id = AccountData[playerid][pTempValue];
    
    if(isnull(inputtext)) 
    {
        AccountData[playerid][pMenuShowed] = true;
        format(str, sizeof(str), "Anda akan menyimpan item:\nNama: "CYAN"%s\n"WHITE"Jumlah di tas: "YELLOW"%d\n"WHITE"Error: Tidak dapat dikosongkan!\nMasukkan jumlah yang ingin disimpan:", 
            InventoryData[playerid][PlayerListitem[playerid][id]][invItem], 
            InventoryData[playerid][PlayerListitem[playerid][id]][invQuantity]);
        Dialog_Show(playerid, "JDMVaultIn", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
        return 1;
    }

    if(!IsNumericEx(inputtext))
    {
        AccountData[playerid][pMenuShowed] = true;
        format(str, sizeof(str), "Anda akan menyimpan item:\nNama: "CYAN"%s\n"WHITE"Jumlah di tas: "YELLOW"%d\n"WHITE"Error: Masukkan hanya angka!\nMasukkan jumlah yang ingin disimpan:", 
            InventoryData[playerid][PlayerListitem[playerid][id]][invItem], 
            InventoryData[playerid][PlayerListitem[playerid][id]][invQuantity]);
        Dialog_Show(playerid, "JDMVaultIn", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
        return 1;
    }

    new quantity = strval(inputtext);
    if(quantity < 1 || quantity > InventoryData[playerid][PlayerListitem[playerid][id]][invQuantity])
    {
        AccountData[playerid][pMenuShowed] = true;
        format(str, sizeof(str), "Anda akan menyimpan item:\nNama: "CYAN"%s\n"WHITE"Jumlah di tas: "YELLOW"%d\n"WHITE"Error: Jumlah tidak valid!\nMasukkan jumlah yang ingin disimpan:", 
            InventoryData[playerid][PlayerListitem[playerid][id]][invItem], 
            InventoryData[playerid][PlayerListitem[playerid][id]][invQuantity]);
        Dialog_Show(playerid, "JDMVaultIn", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
        return 1;
    }

    new query[1028];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `jdm_brankas` WHERE `JDMID` = %d AND `Item` = '%e'", 
        AccountData[playerid][pJDM], InventoryData[playerid][PlayerListitem[playerid][id]][invItem]);
    mysql_query(g_SQL, query);

    new rows = cache_num_rows();
    if(rows > 0)
    {
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm_brankas` SET `Quantity` = `Quantity` + %d WHERE `JDMID` = %d AND `Item` = '%e'", 
            quantity, AccountData[playerid][pJDM], InventoryData[playerid][PlayerListitem[playerid][id]][invItem]);
        mysql_pquery(g_SQL, query);

        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil menyimpan item tersebut.");

        for(new x; x < MAX_JDM_ITEMS; ++x)
        {
            if(JDMBrankas[x][jdmBrankasExists] && JDMBrankas[x][jdmBrankasJDMID] == AccountData[playerid][pJDM] && 
                !strcmp(JDMBrankas[x][jdmBrankasItem], InventoryData[playerid][PlayerListitem[playerid][id]][invItem], true))
            {
                JDMBrankas[x][jdmBrankasQuant] += quantity;
            }
        }
    }
    else
    {
        for(new x; x < MAX_JDM_ITEMS; ++x)
        {
            if(!JDMBrankas[x][jdmBrankasExists]) 
            {
                JDMBrankas[x][jdmBrankasExists] = true;
                JDMBrankas[x][jdmBrankasJDMID] = AccountData[playerid][pJDM];
                strcopy(JDMBrankas[x][jdmBrankasItem], InventoryData[playerid][PlayerListitem[playerid][id]][invItem]);
                JDMBrankas[x][jdmBrankasModel] = InventoryData[playerid][PlayerListitem[playerid][id]][invModel];
                JDMBrankas[x][jdmBrankasQuant] = quantity;

                mysql_format(g_SQL, query, sizeof(query), "INSERT INTO `jdm_brankas` SET `JDMID` = %d, `Item`='%e', `Model`=%d, `Quantity`=%d", 
                    AccountData[playerid][pJDM], InventoryData[playerid][PlayerListitem[playerid][id]][invItem], 
                    InventoryData[playerid][PlayerListitem[playerid][id]][invModel], quantity);
                mysql_pquery(g_SQL, query, "OnJDMBrankasDeposit", "id", playerid, x);
                break;
            }
        }
    }
    ShowItemBox(playerid, InventoryData[playerid][PlayerListitem[playerid][id]][invItem], 
        sprintf("Removed %dx", quantity), InventoryData[playerid][PlayerListitem[playerid][id]][invModel], 5);
    Inventory_Remove(playerid, InventoryData[playerid][PlayerListitem[playerid][id]][invItem], quantity);
    return 1;
}

// JDM Vault Out (Withdraw)
Dialog:JDMVaultOut(playerid, response, listitem, inputtext[])
{
    if(!response) 
    {
        AccountData[playerid][pMenuShowed] = false;
        ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
        return 1;
    }

    if(AccountData[playerid][pTempValue] == -1)
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belum memilih item apapun!");
    }

    new str[512], id = AccountData[playerid][pTempValue];
    
    if(isnull(inputtext)) 
    {
        AccountData[playerid][pMenuShowed] = true;
        format(str, sizeof(str), "Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Error: Tidak dapat dikosongkan!\nMasukkan jumlah yang ingin diambil:", 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant]);
        Dialog_Show(playerid, "JDMVaultOut", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
        return 1;
    }

    if(!IsNumericEx(inputtext))
    {
        AccountData[playerid][pMenuShowed] = true;
        format(str, sizeof(str), "Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Error: Masukkan hanya angka!\nMasukkan jumlah yang ingin diambil:", 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant]);
        Dialog_Show(playerid, "JDMVaultOut", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
        return 1;
    }

    new quantity = strval(inputtext);
    if(quantity < 1 || quantity > JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant])
    {
        AccountData[playerid][pMenuShowed] = true;
        format(str, sizeof(str), "Anda akan mengambil item:\nNama: "CYAN"%s\n"WHITE"Jumlah tersimpan: "YELLOW"%d\n"WHITE"Error: Jumlah tidak valid!\nMasukkan jumlah yang ingin diambil:", 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant]);
        Dialog_Show(playerid, "JDMVaultOut", DIALOG_STYLE_INPUT, "Lemari JDM", str, "Input", "Batal");
        return 1;
    }

    new Float:totalweight = GetTotalWeightFloat(playerid) + float(quantity * GetItemWeight(JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem]))/1000;
    if(totalweight > GetPlayerInventoryWeight(playerid)) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");
    
    if(!strcmp(JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], "Obeng") || 
       !strcmp(JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], "Cangkul")) 
    {
        if(PlayerHasItem(playerid, JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem]))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sudah memiliki item tersebut!");
        if(quantity > 1) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat membawa lebih dari satu item ini!");
    }

    if(!strcmp(JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], "Smartphone"))
    {
        new query[128];
        mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_phones` WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
        mysql_pquery(g_SQL, query, "OnPlayerBuySmartphone", "i", playerid);
    }
    else
    {
        Inventory_Add(playerid, JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasModel], quantity);
    }

    ShowItemBox(playerid, JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem], 
        sprintf("Received %dx", quantity), JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasModel], 5);

    JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant] -= quantity;
    
    new query[128];
    if(JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant] > 0)
    {
        mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm_brankas` SET `Quantity`=%d WHERE `ID`=%d", 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant], 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasID]);
        mysql_pquery(g_SQL, query);
    }
    else
    {
        mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `jdm_brankas` WHERE `ID`=%d", 
            JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasID]);
        mysql_pquery(g_SQL, query);

        JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasExists] = false;
        JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasID] = 0;
        JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasJDMID] = -1;
        JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasItem][0] = EOS;
        JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasModel] = 0;
        JDMBrankas[PlayerListitem[playerid][id]][jdmBrankasQuant] = 0;
    }
    AccountData[playerid][pMenuShowed] = false;
    return 1;
}

// JDM Holster Withdraw
Dialog:JDMHolsterWithdraw(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    new jid = AccountData[playerid][pJDM];
    if(jid == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki JDM!");

    if(listitem < 0 || listitem >= MAX_JDM_HOLSTER)
    {
        AccountData[playerid][pMenuShowed] = false;
        return 1;
    }

    if(!JDMHolster[jid][listitem][jdmHolsterTaken])
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Slot penyimpanan tersebut kosong!");
    }

    if(IsAFireArm(JDMHolster[jid][listitem][jdmHolsterWeaponID]) && AccountData[playerid][pLevel] < 5)
    {
        AccountData[playerid][pMenuShowed] = false;
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda dapat memegang senjata jika sudah mencapai level 5 karakter!");
    }

    new query[256];
    mysql_format(g_SQL, query, sizeof(query),
        "DELETE FROM `jdm_holster` WHERE `JDM_DBID` = %d AND `ID` = %d",
        jid, JDMHolster[jid][listitem][jdmHolsterID]);
    mysql_pquery(g_SQL, query);

    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda telah mengambil %s dari weapon chest.", 
        ReturnWeaponName(JDMHolster[jid][listitem][jdmHolsterWeaponID])));
    GivePlayerWeaponEx(playerid, JDMHolster[jid][listitem][jdmHolsterWeaponID], 
        JDMHolster[jid][listitem][jdmHolsterWeaponAmmo], WEAPON_TYPE_PLAYER);

    JDMHolster[jid][listitem][jdmHolsterTaken] = false;
    JDMHolster[jid][listitem][jdmHolsterWeaponID] = 0;
    JDMHolster[jid][listitem][jdmHolsterWeaponAmmo] = 0;
    JDMHolster[jid][listitem][jdmHolsterID] = 0;

    AccountData[playerid][pMenuShowed] = false;
    return 1;
}

// JDM Garage (Ambil Kendaraan)
Dialog:JDMGarage(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        AccountData[playerid][pInGarkot] = -1;
        return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    }

    new jid = AccountData[playerid][pInGarkot];
    new id = ReturnAnyVehicleJDM(playerid, listitem, jid);
    if(id == -1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada kendaraan yang tersimpan di garasi ini!");
    
    if(PlayerVehicle[id][pVehOwnerID] != AccountData[playerid][pID]) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Kendaraan ini bukan milik anda!");
    
    PlayerVehicle[id][pVehParked] = -1;
    PlayerVehicle[id][pVehJDMGarage] = -1;
    PlayerVehicle[id][pVehFamGarage] = -1;
    PlayerVehicle[id][pVehHouseGarage] = -1;
    PlayerVehicle[id][pVehInsuranced] = false;
    PlayerVehicle[id][pVehImpounded] = false;
    PlayerVehicle[id][pVehImpoundDuration] = 0;
    PlayerVehicle[id][pVehImpoundFee] = 0;
    PlayerVehicle[id][pVehImpoundReason][0] = EOS;

    PlayerVehicle[id][pVehPos][0] = JDMData[jid][jdmGarageSpPos][0];
    PlayerVehicle[id][pVehPos][1] = JDMData[jid][jdmGarageSpPos][1];
    PlayerVehicle[id][pVehPos][2] = JDMData[jid][jdmGarageSpPos][2];
    PlayerVehicle[id][pVehPos][3] = JDMData[jid][jdmGarageSpPos][3];
    
    OnPlayerVehicleRespawn(id);
    AccountData[playerid][pInGarkot] = -1;

    SetTimerEx("ForcePlayerHopInVehicle", 1500, false, "idd", playerid, PlayerVehicle[id][pVehPhysic], 0);

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_vehicles` SET `PVeh_JDM` = %d WHERE `id` = %d", 
        PlayerVehicle[id][pVehJDMGarage], PlayerVehicle[id][pVehID]);
    mysql_pquery(g_SQL, query);
    return 1;
}

// JDM Transfer Points
Dialog:JDMTransferPoints(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    
    new targetid = NearestSingle[playerid];
    if(!IsPlayerConnected(targetid)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak terkoneksi ke server!");
    if(!IsPlayerNearPlayer(playerid, targetid, 3.0)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Pemain tersebut tidak dekat dengan anda!");
    
    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dikosongkan!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi oleh angka!");
    
    new points = strval(inputtext);
    if(points < 1) return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah tidak valid!");
    
    new jid = AccountData[playerid][pJDM];
    if(JDMData[jid][jdmPoints] < points) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Poin JDM tidak cukup!");
    
    JDMData[jid][jdmPoints] -= points;
    AccountData[targetid][pJDMPoints] += points;
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm` SET `Points` = %d WHERE `ID` = %d", 
        JDMData[jid][jdmPoints], jid);
    mysql_pquery(g_SQL, query);
    
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_JDMPoints` = %d WHERE `pID` = %d", 
        AccountData[targetid][pJDMPoints], AccountData[targetid][pID]);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil mentransfer %d poin JDM ke %s", points, ReturnName(targetid)));
    ShowTDN(targetid, NOTIFICATION_INFO, sprintf("Anda menerima %d poin JDM dari %s", points, ReturnName(playerid)));
    return 1;
}

// JDM Deposit Money
Dialog:JDMDepositMoney(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if (AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari JDM ini!");
    
    if(isnull(inputtext)) return Dialog_Show(playerid, "JDMDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang JDM",
        "Error: Tidak dapat dikosongkan!\nMasukkan nominal deposit:", "Input", "Batal");
    if (!IsNumericEx(inputtext)) return Dialog_Show(playerid, "JDMDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang JDM",
        "Error: Masukkan hanya angka!\nMasukkan nominal deposit:", "Input", "Batal");

    new amount = strval(inputtext);
    if(amount < 1) return Dialog_Show(playerid, "JDMDepositMoney", DIALOG_STYLE_INPUT, "Deposit Uang JDM",
        "Error: Jumlah tidak valid!\nMasukkan nominal deposit:", "Input", "Batal");
    if(amount > AccountData[playerid][pMoney]) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup!");

    new jid = AccountData[playerid][pJDM];
    TakePlayerMoneyEx(playerid, amount);
    JDMData[jid][jdmMoney] += amount;
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm` SET `Money` = %d WHERE `ID` = %d", 
        JDMData[jid][jdmMoney], jid);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil deposit $%s", FormatMoney(amount)));
    return 1;
}

// JDM Withdraw Money
Dialog:JDMWithdrawMoney(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if (AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari JDM ini!");
    
    if(isnull(inputtext)) return Dialog_Show(playerid, "JDMWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang JDM",
        "Error: Tidak dapat dikosongkan!\nMasukkan nominal penarikan:", "Input", "Batal");
    if (!IsNumericEx(inputtext)) return Dialog_Show(playerid, "JDMWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang JDM",
        "Error: Masukkan hanya angka!\nMasukkan nominal penarikan:", "Input", "Batal");

    new amount = strval(inputtext);
    if(amount < 1) return Dialog_Show(playerid, "JDMWithdrawMoney", DIALOG_STYLE_INPUT, "Withdraw Uang JDM",
        "Error: Jumlah tidak valid!\nMasukkan nominal penarikan:", "Input", "Batal");

    new jid = AccountData[playerid][pJDM];
    if(JDMData[jid][jdmMoney] < amount) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Saldo JDM tidak cukup!");

    JDMData[jid][jdmMoney] -= amount;
    GivePlayerMoneyEx(playerid, amount);
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm` SET `Money` = %d WHERE `ID` = %d", 
        JDMData[jid][jdmMoney], jid);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil withdraw $%s", FormatMoney(amount)));
    return 1;
}

// JDM Deposit Points
Dialog:JDMDepositPoints(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if (AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari JDM ini!");
    
    if(isnull(inputtext)) return Dialog_Show(playerid, "JDMDepositPoints", DIALOG_STYLE_INPUT, "Deposit Poin JDM",
        "Error: Tidak dapat dikosongkan!\nMasukkan nominal poin yang ingin disimpan:", "Input", "Batal");
    if (!IsNumericEx(inputtext)) return Dialog_Show(playerid, "JDMDepositPoints", DIALOG_STYLE_INPUT, "Deposit Poin JDM",
        "Error: Masukkan hanya angka!\nMasukkan nominal poin:", "Input", "Batal");

    new points = strval(inputtext);
    if(points < 1) return Dialog_Show(playerid, "JDMDepositPoints", DIALOG_STYLE_INPUT, "Deposit Poin JDM",
        "Error: Jumlah tidak valid!\nMasukkan nominal poin:", "Input", "Batal");
    if(points > AccountData[playerid][pJDMPoints]) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Poin JDM anda tidak cukup!");

    new jid = AccountData[playerid][pJDM];
    AccountData[playerid][pJDMPoints] -= points;
    JDMData[jid][jdmPoints] += points;
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_JDMPoints` = %d WHERE `pID` = %d", 
        AccountData[playerid][pJDMPoints], AccountData[playerid][pID]);
    mysql_pquery(g_SQL, query);
    
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm` SET `Points` = %d WHERE `ID` = %d", 
        JDMData[jid][jdmPoints], jid);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil deposit %d poin JDM", points));
    return 1;
}

// JDM Withdraw Points
Dialog:JDMWithdrawPoints(playerid, response, listitem, inputtext[])
{
    if (!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    if (AccountData[playerid][pJDM] < 0) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan anggota dari JDM manapun!");
    if (AccountData[playerid][pJDMRank] < 5) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan petinggi dari JDM ini!");
    
    if(isnull(inputtext)) return Dialog_Show(playerid, "JDMWithdrawPoints", DIALOG_STYLE_INPUT, "Withdraw Poin JDM",
        "Error: Tidak dapat dikosongkan!\nMasukkan nominal poin yang ingin diambil:", "Input", "Batal");
    if (!IsNumericEx(inputtext)) return Dialog_Show(playerid, "JDMWithdrawPoints", DIALOG_STYLE_INPUT, "Withdraw Poin JDM",
        "Error: Masukkan hanya angka!\nMasukkan nominal poin:", "Input", "Batal");

    new points = strval(inputtext);
    if(points < 1) return Dialog_Show(playerid, "JDMWithdrawPoints", DIALOG_STYLE_INPUT, "Withdraw Poin JDM",
        "Error: Jumlah tidak valid!\nMasukkan nominal poin:", "Input", "Batal");

    new jid = AccountData[playerid][pJDM];
    if(JDMData[jid][jdmPoints] < points) 
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Poin JDM tidak cukup!");

    JDMData[jid][jdmPoints] -= points;
    AccountData[playerid][pJDMPoints] += points;
    
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `jdm` SET `Points` = %d WHERE `ID` = %d", 
        JDMData[jid][jdmPoints], jid);
    mysql_pquery(g_SQL, query);
    
    mysql_format(g_SQL, query, sizeof(query), "UPDATE `player_characters` SET `Char_JDMPoints` = %d WHERE `pID` = %d", 
        AccountData[playerid][pJDMPoints], AccountData[playerid][pID]);
    mysql_pquery(g_SQL, query);
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Anda berhasil withdraw %d poin JDM", points));
    return 1;
}