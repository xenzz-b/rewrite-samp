#include <YSI_Coding\y_hooks>

// ---------- define ----------
#define SAWIT_TREE_MODEL        3505
#define SAWIT_LADDER_MODEL      1437
#define SAWIT_COOLDOWN          60
#define SAWIT_PROGRESS_TICK     15
#define OLAH_PROGRESS_TICK      10
#define SAWIT_SELL_PRICE        150
#define SAWIT_LABEL_RANGE       20.0
#define SAWIT_INTERACT_RANGE    10.0
#define MAX_SAWIT_PER_PLAYER    100

static const Float:g_SawitPabrikPos[][3] =
{
    {-1101.9188,-1626.6993,76.36720},
    {-1104.6560,-1626.6497,76.3739},
    {-1107.8336,-1626.5166,76.3739},
    {-1110.8291,-1626.3914,76.3739},
    {-1113.8638,-1626.2645,76.3739},
    {-1113.9280,-1615.8728,76.3672},
    {-1110.7405,-1615.6522,76.3672},
    {-1107.7469,-1615.6312,76.3672},
    {-1104.9724,-1615.6119,76.3672},
    {-1101.7906,-1615.5902,76.3672}
};
#define MAX_SAWIT_PABRIK sizeof(g_SawitPabrikPos)
#define PABRIK_RADIUS 3.0

#define JUAL_X 1250.0      // ganti koordinat asli
#define JUAL_Y -460.0
#define JUAL_Z 5.0
#define JUAL_RADIUS 3.0

new STREAMER_TAG_AREA:SawitPabrikArea[MAX_SAWIT_PABRIK];
new STREAMER_TAG_AREA:SawitJualArea;

// ---------- posisi tangga disimpan terpisah ----------
new Float:SawitLadderPos[MAX_SAWIT][6];     // [0-2] = xyz tangga, [3-5] = rxryrz tangga

// ---------- timer flag ----------
new bool:pTakingSawitTimer[MAX_PLAYERS];
new bool:pOlahSawitTimer[MAX_PLAYERS];
new pSawitActiveTree[MAX_PLAYERS];

// ---------- forward ----------
forward Sawit_CooldownTick(playerid, sawitid);
forward LoadSawits();
forward OnSawitCreated(playerid, sawitid);

new STREAMER_TAG_3D_TEXT_LABEL:SawitOlahText[MAX_SAWIT_PABRIK];

hook OnGameModeInit()
{
    for(new i; i < MAX_SAWIT_PABRIK; i++)
    {
        SawitPabrikArea[i] = CreateDynamicSphere(g_SawitPabrikPos[i][0], g_SawitPabrikPos[i][1], g_SawitPabrikPos[i][2], 3.5, 0, 0, -1);
        SawitOlahText[i] = CreateDynamic3DTextLabel("Tekan "RED"[Y] "WHITE"untuk mengelolah sawit mentah", Y_WHITE, g_SawitPabrikPos[i][0], g_SawitPabrikPos[i][1], g_SawitPabrikPos[i][2], 5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 0, 0, -1, 10.00, -1, 0);
    }
    SawitJualArea = CreateDynamicSphere(JUAL_X, JUAL_Y, JUAL_Z, 3.5, 0, 0, -1);
    return 1;
}

hook OnGameModeExit()
{   
    for(new i; i < MAX_SAWIT_PABRIK; i++)
    {
        if(DestroyDynamic3DTextLabel(SawitOlahText[i]))
            SawitOlahText[i] = STREAMER_TAG_3D_TEXT_LABEL: INVALID_STREAMER_ID;
    }
    return 1;
}

// ---------- cek apakah sawit sedang diedit admin lain ----------
Sawit_BeingEdited(sawitid)
{
    if(!Iter_Contains(Sawits, sawitid)) return 0;
    foreach(new i : Player) if(AccountData[i][EditingSawitID] == sawitid) return 1;
    return 0;
}

// ---------- cari pohon sawit terdekat ----------
Sawit_Nearest(playerid)
{
    foreach(new i : Sawits)
    {
        if(IsPlayerInRangeOfPoint(playerid, SAWIT_INTERACT_RANGE, SawitData[i][sawPos][0], SawitData[i][sawPos][1], SawitData[i][sawPos][2]+10.0))
        {
            if(GetPlayerInterior(playerid) == 0 && GetPlayerVirtualWorld(playerid) == 0)
                return i;
        }
    }
    return -1;
}

// ---------- stop animasi & progress ----------
Sawit_StopActivity(playerid)
{
    AccountData[playerid][pActivityTime] = 0;
    HideProgressBar(playerid);
    ClearAnimations(playerid, true);
    StopLoopingAnim(playerid);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    TogglePlayerControllable(playerid, true);
}

// ---------- rebuild object pohon + tangga + label ----------
Sawit_Rebuild(sawitid)
{
    if(!Iter_Contains(Sawits, sawitid)) return 0;

    if(SawitData[sawitid][sawTreeObject] != STREAMER_TAG_OBJECT:INVALID_STREAMER_ID)
        DestroyDynamicObject(SawitData[sawitid][sawTreeObject]);

    if(SawitData[sawitid][sawLadderObject] != STREAMER_TAG_OBJECT:INVALID_STREAMER_ID)
        DestroyDynamicObject(SawitData[sawitid][sawLadderObject]);

    if(SawitData[sawitid][sawArea] != STREAMER_TAG_AREA:INVALID_STREAMER_ID)
        DestroyDynamicArea(SawitData[sawitid][sawArea]);

    SawitData[sawitid][sawArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
    SawitData[sawitid][sawTreeObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
    SawitData[sawitid][sawLadderObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;

    // pohon
    SawitData[sawitid][sawTreeObject] = CreateDynamicObject(
        SAWIT_TREE_MODEL,
        SawitData[sawitid][sawPos][0], SawitData[sawitid][sawPos][1], SawitData[sawitid][sawPos][2],
        SawitData[sawitid][sawPos][3], SawitData[sawitid][sawPos][4], SawitData[sawitid][sawPos][5]
    );

    // tangga
    SawitData[sawitid][sawLadderObject] = CreateDynamicObject(
        SAWIT_LADDER_MODEL,
        SawitLadderPos[sawitid][0], SawitLadderPos[sawitid][1], SawitLadderPos[sawitid][2],
        SawitLadderPos[sawitid][3], SawitLadderPos[sawitid][4], SawitLadderPos[sawitid][5]
    );

    SawitData[sawitid][sawArea] = CreateDynamicSphere(
        SawitData[sawitid][sawPos][0], SawitData[sawitid][sawPos][1], SawitData[sawitid][sawPos][2] + 9.0,
        3.5, 0, 0, -1);

    return 1;
}

// ---------- destroy object pohon + tangga + label ----------
Sawit_Destroy(sawitid)
{
    if(SawitData[sawitid][sawTreeObject] != STREAMER_TAG_OBJECT:INVALID_STREAMER_ID)
        DestroyDynamicObject(SawitData[sawitid][sawTreeObject]);

    if(SawitData[sawitid][sawLadderObject] != STREAMER_TAG_OBJECT:INVALID_STREAMER_ID)
        DestroyDynamicObject(SawitData[sawitid][sawLadderObject]);

    if(SawitData[sawitid][sawArea] != STREAMER_TAG_AREA:INVALID_STREAMER_ID)
        DestroyDynamicArea(SawitData[sawitid][sawArea]);
        
    SawitData[sawitid][sawArea] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
    SawitData[sawitid][sawTreeObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
    SawitData[sawitid][sawLadderObject] = STREAMER_TAG_OBJECT:INVALID_STREAMER_ID;
    return 1;
}

public LoadSawits()
{
    new rows = cache_num_rows();
    if(!rows) return 1;

    for(new i; i < rows; i++)
    {
        new sawitid;
        cache_get_value_name_int(i, "id", sawitid);  // id DB = slot array

        SawitData[sawitid][sawDBID] = sawitid;
        cache_get_value_name_float(i, "x",   SawitData[sawitid][sawPos][0]);
        cache_get_value_name_float(i, "y",   SawitData[sawitid][sawPos][1]);
        cache_get_value_name_float(i, "z",   SawitData[sawitid][sawPos][2]);
        cache_get_value_name_float(i, "rx",  SawitData[sawitid][sawPos][3]);
        cache_get_value_name_float(i, "ry",  SawitData[sawitid][sawPos][4]);
        cache_get_value_name_float(i, "rz",  SawitData[sawitid][sawPos][5]);
        cache_get_value_name_float(i, "lx",  SawitLadderPos[sawitid][0]);
        cache_get_value_name_float(i, "ly",  SawitLadderPos[sawitid][1]);
        cache_get_value_name_float(i, "lz",  SawitLadderPos[sawitid][2]);
        cache_get_value_name_float(i, "lrx", SawitLadderPos[sawitid][3]);
        cache_get_value_name_float(i, "lry", SawitLadderPos[sawitid][4]);
        cache_get_value_name_float(i, "lrz", SawitLadderPos[sawitid][5]);

        Iter_Add(Sawits, sawitid);
        Sawit_Rebuild(sawitid);
    }

    printf("[Sawit] Jumlah total pohon sawit yang dimuat: %d.", rows);
    return 1;
}

// ---------- save posisi pohon ke DB ----------
Sawit_Save(sawitid)
{
    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "UPDATE `sawit_objects` SET `x`=%.4f,`y`=%.4f,`z`=%.4f,`rx`=%.4f,`ry`=%.4f,`rz`=%.4f WHERE `id`=%d",
        SawitData[sawitid][sawPos][0], SawitData[sawitid][sawPos][1], SawitData[sawitid][sawPos][2],
        SawitData[sawitid][sawPos][3], SawitData[sawitid][sawPos][4], SawitData[sawitid][sawPos][5],
        SawitData[sawitid][sawDBID]
    );
    mysql_pquery(g_SQL, query);
    return 1;
}

// ---------- save posisi tangga ke DB ----------
Sawit_SaveLadder(sawitid)
{
    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "UPDATE `sawit_objects` SET `lx`=%.4f,`ly`=%.4f,`lz`=%.4f,`lrx`=%.4f,`lry`=%.4f,`lrz`=%.4f WHERE `id`=%d",
        SawitLadderPos[sawitid][0], SawitLadderPos[sawitid][1], SawitLadderPos[sawitid][2],
        SawitLadderPos[sawitid][3], SawitLadderPos[sawitid][4], SawitLadderPos[sawitid][5],
        SawitData[sawitid][sawDBID]
    );
    mysql_pquery(g_SQL, query);
    return 1;
}

// ---------- callback sawit baru dibuat ----------
public OnSawitCreated(playerid, sawitid)
{
    SawitData[sawitid][sawDBID] = sawitid; 

    new msg[64];
    format(msg, sizeof(msg), "Pohon sawit berhasil dibuat! ID: %d", sawitid);
    ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s membuat pohon sawit ID: %d.", AccountData[playerid][pAdminname], sawitid);
    return 1;
}

// ---------- handler tekan Y job sawit ----------
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(AccountData[playerid][pJob] != JOB_SAWIT) return 1;
        if(AccountData[playerid][pKnockdown]) return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dapat melakukannya saat ini!"), 1;
        if(AccountData[playerid][pActivityTime] != 0) return ShowTDN(playerid, NOTIFICATION_WARNING, "Anda sedang melakukan sesuatu, mohon tunggu progress bar selesai!"), 1;

        new sawitid = Sawit_Nearest(playerid);
        if(sawitid != -1)
        {
            if(SawitData[sawitid][sawCooldown][playerid] > 0)
            {
                new cdstr[64];
                format(cdstr, sizeof(cdstr), "Pohon ini masih cooldown, tunggu %d detik lagi!", SawitData[sawitid][sawCooldown][playerid]);
                return ShowTDN(playerid, NOTIFICATION_WARNING, cdstr), 1;
            }

            if(Inventory_Count(playerid, "Sawit Mentah") >= MAX_SAWIT_PER_PLAYER)
                return ShowTDN(playerid, NOTIFICATION_WARNING, "Sawit mentah anda sudah penuh (100)! Olah dulu di pabrik."), 1;

            new Float:ctw = GetTotalWeightFloat(playerid) + float(GetItemWeight("Sawit Mentah")) / 1000.0;
            if(ctw > GetPlayerInventoryWeight(playerid))
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda telah penuh!"), 1;

            pTakingSawitTimer[playerid] = true;
            pSawitActiveTree[playerid] = sawitid;
            AccountData[playerid][pActivityTime] = 1;

            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENGAMBIL SAWIT");
            ShowProgressBar(playerid);
            // ApplyAnimation(playerid,"BD_FIRE","wash_up",4.1, true, false, false, false, 0, true);
            ApplyAnimation(playerid,"CARRY", "putdwn105", 4.1, true, false, false, false, 0, true);
            HideNotifBox(playerid);
            return 1;
        }
        new bool:diPabrik = false;
        for(new i; i < MAX_SAWIT_PABRIK; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, PABRIK_RADIUS, g_SawitPabrikPos[i][0], g_SawitPabrikPos[i][1], g_SawitPabrikPos[i][2]))
            {
                diPabrik = true;
                break;
            }
        }
        if(diPabrik)
        {
            if(Inventory_Count(playerid, "Sawit Mentah") < 2)
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda membutuhkan minimal 2 sawit mentah!"), 1;

            pOlahSawitTimer[playerid] = true;
            AccountData[playerid][pActivityTime] = 1;

            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MENGOLAH SAWIT");
            ShowProgressBar(playerid);
            ApplyAnimation(playerid, "BD_FIRE", "wash_up", 3.0, true, false, false, false, 0, true);
            HideNotifBox(playerid);
            return 1;
        }
        if(IsPlayerInRangeOfPoint(playerid, JUAL_RADIUS, JUAL_X, JUAL_Y, JUAL_Z))
        {
            new jumlah = Inventory_Count(playerid, "Sawit Olahan");
            if(jumlah <= 0)
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki sawit olahan!"), 1;

            new total = jumlah * SawitPrice;
            Inventory_Remove(playerid, "Sawit Olahan", jumlah);
            GivePlayerMoneyEx(playerid, total);

            new sellstr[64];
            format(sellstr, sizeof(sellstr), "Berhasil menjual %d sawit olahan seharga $%d!", jumlah, total);
            ShowItemBox(playerid, "Sawit Olahan", sprintf("Sold %dx | +$%d", jumlah, total), 19636, 5);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, sellstr);
            return 1;
        }
    }
    return 1;
}

hook OnPlayerEnterDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(AccountData[playerid][pJob] == JOB_SAWIT && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        foreach(new i : Sawits)
        {
            if(areaid == SawitData[i][sawArea])
            {
                ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk ambil Sawit Mentah");
                return 1;
            }
        }
        for(new i; i < MAX_SAWIT_PABRIK; i++)
        {
            if(areaid == SawitPabrikArea[i])
            {
                ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk olah Sawit Mentah");
                return 1;
            }
        }
        if(areaid == SawitJualArea)
        {
            ShowNotifBox(playerid, "Tekan ~p~'Y' ~w~untuk jual Sawit Olahan");
            return 1;
        }
    }
    return 1;
}

hook OnPlayerLeaveDynArea(playerid, STREAMER_TAG_AREA:areaid)
{
    if(AccountData[playerid][pJob] == JOB_SAWIT)
    {
        foreach(new i : Sawits)
        {
            if(areaid == SawitData[i][sawArea])
            {
                PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
                HideNotifBox(playerid);
                return 1;
            }
        }
        for(new i; i < MAX_SAWIT_PABRIK; i++)
        {
            if(areaid == SawitPabrikArea[i])
            {
                PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
                HideNotifBox(playerid);
                return 1;
            }
        }
        if(areaid == SawitJualArea)
        {
            PlayerPlaySound(playerid, 30803, 0.0, 0.0, 0.0);
            HideNotifBox(playerid);
            return 1;
        }
    }
    return 1;
}

// ---------- tick ambil sawit (dipanggil tiap detik) ----------
ptask Sawit_AllTick[1000](playerid)
{
    if(pTakingSawitTimer[playerid])
    {
        if(AccountData[playerid][pJob] != JOB_SAWIT)
        {
            pTakingSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);
            return 0;
        }

        if(!IsPlayerConnected(playerid))
        {
            pTakingSawitTimer[playerid] = false;
            return 0;
        }

        if(Sawit_Nearest(playerid) == -1)
        {
            pTakingSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);
            return 0;
        }

        if(GetTotalWeightFloat(playerid) >= GetPlayerInventoryWeight(playerid))
        {
            pTakingSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);
            ShowTDN(playerid, NOTIFICATION_ERROR, "Inventory anda sudah penuh!");
            return 0;
        }

        if(AccountData[playerid][pActivityTime] >= SAWIT_PROGRESS_TICK)
        {
            pTakingSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);

            if(Inventory_Count(playerid, "Sawit Mentah") >= MAX_SAWIT_PER_PLAYER)
            {
                ShowTDN(playerid, NOTIFICATION_WARNING, "Sawit mentah anda sudah 100! Olah dulu di pabrik.");
                return 0;
            }

            Inventory_Add(playerid, "Sawit Mentah", 19575, 1);
            ShowItemBox(playerid, "Sawit Mentah", "Received 1x", 19575, 5);

            new sid = pSawitActiveTree[playerid];
            if(Iter_Contains(Sawits, sid))
            {
                SawitData[sid][sawCooldown][playerid] = SAWIT_COOLDOWN;
                SetTimerEx("Sawit_CooldownTick", 1000, false, "ii", playerid, sid);
            }
        }
        else
        {
            AccountData[playerid][pActivityTime]++;
            PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

            static Float:pv;
            pv = AccountData[playerid][pActivityTime] * 102.0 / SAWIT_PROGRESS_TICK;
            PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], pv, 20.0);
            PlayerTextDrawShow(playerid, ProgressBar[playerid][0]);
        }
    }
    if(pOlahSawitTimer[playerid])
    {
        if(AccountData[playerid][pJob] != JOB_SAWIT)
        {
            pOlahSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);
            return 0;
        }

        if(!IsPlayerConnected(playerid))
        {
            pOlahSawitTimer[playerid] = false;
            return 0;
        }
        new bool:diPabrik = false;
        for(new i; i < MAX_SAWIT_PABRIK; i++)
        {
            if(IsPlayerInRangeOfPoint(playerid, PABRIK_RADIUS, g_SawitPabrikPos[i][0], g_SawitPabrikPos[i][1], g_SawitPabrikPos[i][2]))
            {
                diPabrik = true;
                break;
            }
        }
        if(!diPabrik)
        {
            pOlahSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);
            return 0;
        }
        if(AccountData[playerid][pActivityTime] >= OLAH_PROGRESS_TICK)
        {
            pOlahSawitTimer[playerid] = false;
            Sawit_StopActivity(playerid);

            new rand = RandomEx(2, 3);
            Inventory_Remove(playerid, "Sawit Mentah", 2);
            Inventory_Add(playerid, "Sawit Olahan", 19636, rand);
            ShowItemBox(playerid, "Sawit Olahan", sprintf("Received %dx", rand), 19636, 5);

            new olahstr[80];
            format(olahstr, sizeof(olahstr), "Berhasil mengolah 2 sawit mentah menjadi %dx sawit olahan!", rand);
            ShowTDN(playerid, NOTIFICATION_SUCCESS, olahstr);
        }
        else
        {
            AccountData[playerid][pActivityTime]++;
            PlayerPlaySound(playerid, 11200, 0.0, 0.0, 0.0);

            static Float:pv;
            pv = AccountData[playerid][pActivityTime] * 102.0 / OLAH_PROGRESS_TICK;
            PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], pv, 20.0);
            PlayerTextDrawShow(playerid, ProgressBar[playerid][0]);
        }
    }
    return 1;
}

// ---------- countdown cooldown pohon per player ----------
public Sawit_CooldownTick(playerid, sawitid)
{
    if(!Iter_Contains(Sawits, sawitid)) return 0;
    if(!IsPlayerConnected(playerid))    return 0;

    if(SawitData[sawitid][sawCooldown][playerid] > 0)
    {
        SawitData[sawitid][sawCooldown][playerid]--;
        if(SawitData[sawitid][sawCooldown][playerid] > 0)
            SetTimerEx("Sawit_CooldownTick", 1000, false, "ii", playerid, sawitid);
    }

    return 1;
}

// ---------- /createsawit ----------
CMD:createsawit(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 4)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki izin!"), 1;

    new sawitid = Iter_Free(Sawits);
    if(sawitid == -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah sawit sudah mencapai batas maksimal!"), 1;

    new Float:px, Float:py, Float:pz, Float:prz;
    GetPlayerPos(playerid, px, py, pz);
    GetPlayerFacingAngle(playerid, prz);

    SawitData[sawitid][sawPos][0] = px;
    SawitData[sawitid][sawPos][1] = py;
    SawitData[sawitid][sawPos][2] = pz;
    SawitData[sawitid][sawPos][3] = 0.0;
    SawitData[sawitid][sawPos][4] = 0.0;
    SawitData[sawitid][sawPos][5] = prz;

    // tangga default offset samping pohon
    SawitLadderPos[sawitid][0] = px + 0.5;
    SawitLadderPos[sawitid][1] = py;
    SawitLadderPos[sawitid][2] = pz;
    SawitLadderPos[sawitid][3] = 0.0;
    SawitLadderPos[sawitid][4] = 0.0;
    SawitLadderPos[sawitid][5] = 0.0;

    Iter_Add(Sawits, sawitid);
    Sawit_Rebuild(sawitid);

    new query[512];
    mysql_format(g_SQL, query, sizeof(query),
        "INSERT INTO `sawit_objects` (`id`,`x`,`y`,`z`,`rx`,`ry`,`rz`,`lx`,`ly`,`lz`,`lrx`,`lry`,`lrz`) VALUES (%d,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f,%.4f)",
        sawitid, px, py, pz, 0.0, 0.0, prz,
        px + 0.5, py, pz, 0.0, 0.0, 0.0
    );
    mysql_pquery(g_SQL, query, "OnSawitCreated", "ii", playerid, sawitid);
    return 1;
}

// ---------- /editsawit [tree/ladder] [id] ----------
CMD:editsawit(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 4)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki izin!"), 1;

    new typestr[10], sawitid;
    if(sscanf(params, "s[10]i", typestr, sawitid))
        return SUM(playerid, "Syntax: /editsawit [tree/ladder] [id]"), 1;

    if(!Iter_Contains(Sawits, sawitid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "ID sawit tidak ditemukan!"), 1;

    if(AccountData[playerid][EditingSawitID] != -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang berada di dalam mode editing!"), 1;

    if(Sawit_BeingEdited(sawitid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Sawit ini sedang diedit oleh admin lain!"), 1;

    if(!strcmp(typestr, "tree", true))
    {
        if(!IsPlayerInRangeOfPoint(playerid, 30.0, SawitData[sawitid][sawPos][0], SawitData[sawitid][sawPos][1], SawitData[sawitid][sawPos][2]))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan pohon sawit tersebut!"), 1;

        AccountData[playerid][EditingSawitID] = sawitid;
        AccountData[playerid][EditingSawitType] = 0;     // 0 = tree
        EditDynamicObject(playerid, SawitData[sawitid][sawTreeObject]);

        new msg[64];
        format(msg, sizeof(msg), "Edit pohon sawit ID %d, pindahkan lalu klik selesai.", sawitid);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s sedang mengedit posisi pohon sawit ID: %d.", AccountData[playerid][pAdminname], sawitid);
    }
    else if(!strcmp(typestr, "ladder", true))
    {
        if(!IsPlayerInRangeOfPoint(playerid, 30.0, SawitLadderPos[sawitid][0], SawitLadderPos[sawitid][1], SawitLadderPos[sawitid][2]))
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak dekat dengan tangga sawit tersebut!"), 1;

        AccountData[playerid][EditingSawitID] = sawitid;
        AccountData[playerid][EditingSawitType] = 1;     // 1 = ladder
        EditDynamicObject(playerid, SawitData[sawitid][sawLadderObject]);

        new msg[64];
        format(msg, sizeof(msg), "Edit tangga sawit ID %d, pindahkan lalu klik selesai.", sawitid);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
        SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s sedang mengedit posisi tangga sawit ID: %d.", AccountData[playerid][pAdminname], sawitid);
    }
    else return ShowTDN(playerid, NOTIFICATION_ERROR, "Tipe tidak valid! Gunakan tree atau ladder."), 1;

    return 1;
}

// ---------- /removesawit [id] ----------
CMD:removesawit(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 4)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki izin!"), 1;

    new sawitid;
    if(sscanf(params, "i", sawitid))
        return SUM(playerid, "Syntax: /removesawit [id]"), 1;

    if(!Iter_Contains(Sawits, sawitid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "ID sawit tidak ditemukan!"), 1;

    Sawit_Destroy(sawitid);

    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "DELETE FROM `sawit_objects` WHERE `id`=%d", SawitData[sawitid][sawDBID]);
    mysql_pquery(g_SQL, query);

    Iter_Remove(Sawits, sawitid);

    new msg[48];
    format(msg, sizeof(msg), "Sawit ID %d berhasil dihapus!", sawitid);
    ShowTDN(playerid, NOTIFICATION_SUCCESS, msg);
    SendStaffMessage(Y_LIGHTRED, "AdmCmd: %s menghapus pohon sawit ID: %d.", AccountData[playerid][pAdminname], sawitid);
    return 1;
}

// ---------- update posisi object setelah diedit ----------
hook OnPlayerEditDynObject(playerid, STREAMER_TAG_OBJECT:objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
{
    if(AccountData[playerid][EditingSawitID] == -1) return 1;

    new sawitid = AccountData[playerid][EditingSawitID];
    if(!Iter_Contains(Sawits, sawitid)) return 1;

    if(response == EDIT_RESPONSE_FINAL)
    {
        if(AccountData[playerid][EditingSawitType] == 0)    // pohon
        {
            SawitData[sawitid][sawPos][0] = x;
            SawitData[sawitid][sawPos][1] = y;
            SawitData[sawitid][sawPos][2] = z;
            SawitData[sawitid][sawPos][3] = rx;
            SawitData[sawitid][sawPos][4] = ry;
            SawitData[sawitid][sawPos][5] = rz;

            SetDynamicObjectPos(objectid, x, y, z);
            SetDynamicObjectRot(objectid, rx, ry, rz);

            Sawit_Save(sawitid);
        }
        else    // tangga
        {
            SawitLadderPos[sawitid][0] = x;
            SawitLadderPos[sawitid][1] = y;
            SawitLadderPos[sawitid][2] = z;
            SawitLadderPos[sawitid][3] = rx;
            SawitLadderPos[sawitid][4] = ry;
            SawitLadderPos[sawitid][5] = rz;

            SetDynamicObjectPos(objectid, x, y, z);
            SetDynamicObjectRot(objectid, rx, ry, rz);

            Sawit_SaveLadder(sawitid);
        }

        AccountData[playerid][EditingSawitID]   = -1;
        AccountData[playerid][EditingSawitType] = -1;
    }
    else if(response == EDIT_RESPONSE_CANCEL)
    {
        if(AccountData[playerid][EditingSawitType] == 0)
        {
            SetDynamicObjectPos(objectid, SawitData[sawitid][sawPos][0], SawitData[sawitid][sawPos][1], SawitData[sawitid][sawPos][2]);
            SetDynamicObjectRot(objectid, SawitData[sawitid][sawPos][3], SawitData[sawitid][sawPos][4], SawitData[sawitid][sawPos][5]);
        }
        else
        {
            SetDynamicObjectPos(objectid, SawitLadderPos[sawitid][0], SawitLadderPos[sawitid][1], SawitLadderPos[sawitid][2]);
            SetDynamicObjectRot(objectid, SawitLadderPos[sawitid][3], SawitLadderPos[sawitid][4], SawitLadderPos[sawitid][5]);
        }

        AccountData[playerid][EditingSawitID]   = -1;
        AccountData[playerid][EditingSawitType] = -1;
    }

    return 1;
}

// ====================================================
//  SQL TABLE
// ====================================================

/*
    CREATE TABLE IF NOT EXISTS `sawit_objects` (
        `id`    INT NOT NULL AUTO_INCREMENT,
        `x`     FLOAT DEFAULT 0,
        `y`     FLOAT DEFAULT 0,
        `z`     FLOAT DEFAULT 0,
        `rx`    FLOAT DEFAULT 0,
        `ry`    FLOAT DEFAULT 0,
        `rz`    FLOAT DEFAULT 0,
        `lx`    FLOAT DEFAULT 0,
        `ly`    FLOAT DEFAULT 0,
        `lz`    FLOAT DEFAULT 0,
        `lrx`   FLOAT DEFAULT 0,
        `lry`   FLOAT DEFAULT 0,
        `lrz`   FLOAT DEFAULT 0,
        PRIMARY KEY (`id`)
    );
*/

// ====================================================
//  INTEGRASI
// ====================================================

/*
    1. Tambah ke enum job       : JOB_SAWIT
    2. Tambah ke AccountData    : EditingSawitID, EditingSawitType (init ke -1 di OnPlayerConnect)
    3. Tambah ke g_aInventoryItems:
           {"Sawit Mentah", 2663, 100},
           {"Sawit Olahan", 2663, 100},
    4. Timer 1 detik            : Sawit_TakeTick(playerid); Sawit_OlahTick(playerid);
    5. Ganti koordinat PABRIK & JUAL dengan lokasi asli server lo
    6. OnGameModeInit, KeyStateChange, EditDynObject sudah pakai y_hooks
*/
