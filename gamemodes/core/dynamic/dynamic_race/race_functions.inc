#define MAX_CHECKPOINTS 100
#define DIALOG_RACE_MAIN     5000
#define DIALOG_RACE_INVITE   5001
#define DIALOG_RACE_KICK     5002
#define DIALOG_RACE_LIST     5003
#define DIALOG_TRACK_SAVE 5101
#define MAX_TRACKS   50
#define DIALOG_RACE_DELETE   5102
#define DIALOG_RACE_LEADERBOARD  1850
new DeleteListID[MAX_PLAYERS][MAX_TRACKS];
new TrackListID[MAX_PLAYERS][MAX_TRACKS];

new
    Float:RacePos[MAX_PLAYERS][MAX_CHECKPOINTS][3],
    RaceIndex[MAX_PLAYERS],
    RaceWith[MAX_PLAYERS],
    bool:InRace[MAX_PLAYERS],
    CountdownTimer[MAX_PLAYERS],
    RankingsTimer[MAX_PLAYERS],
    RaceCPCount[MAX_PLAYERS];

new InviteList[MAX_PLAYERS][MAX_PLAYERS];
new InviteCount[MAX_PLAYERS];
new KickList[MAX_PLAYERS][MAX_PLAYERS];
new KickCount[MAX_PLAYERS];
new bool:SaveMode[MAX_PLAYERS];
new RaceTimeTimer[MAX_PLAYERS];       // timer handle
new RaceTimeStart[MAX_PLAYERS];       // tick count saat start
new bool:RaceTimeRunning[MAX_PLAYERS];// status aktif
new RaceFinishTime[MAX_PLAYERS];   // waktu finish dalam ms


#include <YSI_Coding\y_hooks>

static stock bool:IsValidOwner(playerid)
{
    return (playerid != INVALID_PLAYER_ID && IsPlayerConnected(playerid));
}

hook OnPlayerConnect(playerid)
{
    for (new i = 0; i < MAX_CHECKPOINTS; i++)
    {
        RacePos[playerid][i][0] = 0.0;
        RacePos[playerid][i][1] = 0.0;
        RacePos[playerid][i][2] = 0.0;
    }
    InRace[playerid]        = false;
    RaceIndex[playerid]     = -1;
    RaceWith[playerid]      = INVALID_PLAYER_ID;
    RaceCPCount[playerid]   = 0;
    CountdownTimer[playerid]= -1;
    RankingsTimer[playerid] = -1;
    SaveMode[playerid]      = false;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    RaceUI_Hide(playerid);
    Race_EnableGhost(playerid, false);
    if (CountdownTimer[playerid] != -1)
    {
        KillTimer(CountdownTimer[playerid]);
        CountdownTimer[playerid] = -1;
    }
    RaceTimeRunning[playerid] = false;
    if(RaceTimeTimer[playerid] != -1)
    {
        KillTimer(RaceTimeTimer[playerid]);
        RaceTimeTimer[playerid] = -1;
    }

    if (IsValidOwner(playerid))
    {
        if (RankingsTimer[playerid] != -1)
        {
            KillTimer(RankingsTimer[playerid]);
            RankingsTimer[playerid] = -1;
        }

        foreach (new p : Player)
        {
            if (RaceWith[p] == playerid)
            {
                InRace[p]      = false;
                RaceIndex[p]   = -1;
                RaceWith[p]    = INVALID_PLAYER_ID;
                DisablePlayerRaceCheckpoint(p);
                if (p != playerid)
                    SendClientMessageEx(p, COLOR_YELLOW, "[Race] {FFFFFF}Race dihentikan karena owner disconnect.");
                RaceUI_Hide(p);
                //ShowStatsTD(p);
            }
        }
    }

    if (InRace[playerid] && RaceWith[playerid] != INVALID_PLAYER_ID)
    {
        new ownerid = RaceWith[playerid];
        if (IsValidOwner(ownerid))
            SendClientMessageEx(ownerid, COLOR_YELLOW, "[Race] {FFFFFF}Seorang peserta disconnect.");

        InRace[playerid]    = false;
        RaceIndex[playerid] = -1;
        RaceWith[playerid]  = INVALID_PLAYER_ID;
        DisablePlayerRaceCheckpoint(playerid);
        RaceUI_Hide(playerid);
    }

    InRace[playerid]      = false;
    RaceIndex[playerid]   = -1;
    RaceWith[playerid]    = INVALID_PLAYER_ID;
    RaceCPCount[playerid] = 0;
    SaveMode[playerid]    = false;
    return 1;
}

CMD:race(playerid, params[])
{
    new type[24], string[128], Float:pos[3];
    GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

    if (sscanf(params, "s[24]S()[128]", type, string))
    {
        SUM(playerid, "/race [save/reset/start/leave/setcp]");
        return 1;
    }
    else if (!strcmp(type, "save", true))
    {
        if(Inventory_Count(playerid, "Race Tablet") < 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Race Tablet");

        new ind;
        if (sscanf(string, "d", ind) == 1)
        {
            if (ind < 1 || ind > MAX_CHECKPOINTS - 1) return Error(playerid, "Index hanya 1 - 99.");
            RacePos[playerid][ind - 1] = pos;

            if (ind > RaceCPCount[playerid])
                RaceCPCount[playerid] = ind;

            SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Checkpoint %d disimpan!", ind);
            return 1;
        }
    }
    else if (!strcmp(type, "setcp", true))
    {
        if(Inventory_Count(playerid, "Race Tablet") < 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Race Tablet");

        if (!strlen(string)) return SUM(playerid, "Gunakan: /race setcp [namatrack]");

        new query[256];
        mysql_format(g_SQL, query, sizeof(query),"INSERT INTO race_tracks (name, owner) VALUES ('%e','%e')",string, GetName(playerid));
        mysql_tquery(g_SQL, query, "OnTrackCreated", "is", playerid, string);
    }
    else if (!strcmp(type, "reset", true))
    {
        if(Inventory_Count(playerid, "Race Tablet") < 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Race Tablet");

        for (new i = 0; i < MAX_CHECKPOINTS; i++)
        {
            RacePos[playerid][i][0] = 0.0;
            RacePos[playerid][i][1] = 0.0;
            RacePos[playerid][i][2] = 0.0;
        }
        RaceCPCount[playerid] = 0;
        SaveMode[playerid]    = false;

        SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Semua checkpoint berhasil direset.");
    }
    else if (!strcmp(type, "leave", true))
    {
        if (!InRace[playerid]) return Error(playerid, "Kamu tidak sedang dalam balapan.");

        new ownerid = RaceWith[playerid];

        InRace[playerid]  = false;
        RaceIndex[playerid]= -1;
        RaceWith[playerid]= INVALID_PLAYER_ID;
        DisablePlayerRaceCheckpoint(playerid);
        SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Kamu keluar dari balapan.");
        RaceUI_Hide(playerid);
        Race_EnableGhost(playerid, false);

        if (ownerid == playerid && IsValidOwner(ownerid))
        {
            foreach (new p : Player)
            {
                if (RaceWith[p] == ownerid)
                {
                    InRace[p]    = false;
                    RaceIndex[p] = -1;
                    RaceWith[p]  = INVALID_PLAYER_ID;
                    DisablePlayerRaceCheckpoint(p);
                    SendClientMessageEx(p, COLOR_YELLOW, "[Race] {FFFFFF}Race dihentikan karena owner keluar.");
                    RaceUI_Hide(p);
                    //ShowStatsTD(p);
                }
            }
            if (RankingsTimer[ownerid] != -1)
            {
                KillTimer(RankingsTimer[ownerid]);
                RankingsTimer[ownerid] = -1;
            }
        }
    }
    else if (!strcmp(type, "start", true))
    {
        if(Inventory_Count(playerid, "Race Tablet") < 1)
		return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memiliki Race Tablet");

        if (RaceCPCount[playerid] < 2)
            return Error(playerid, "Belum cukup checkpoint untuk start (min 1 + finish)!");

        foreach (new p : Player)
        {
            if (RaceWith[p] == playerid)
            {
                if (CountdownTimer[p] != -1) { KillTimer(CountdownTimer[p]); CountdownTimer[p] = -1; }
                CountdownTimer[p] = SetTimerEx("CountdownStartRace", 1000, false, "ii", p, 10);
                SendClientMessageEx(p, COLOR_YELLOW, "[Race] {FFFFFF}Countdown dimulai...");
                //HideStatsTD(p);
            }
        }

        if (CountdownTimer[playerid] != -1) { KillTimer(CountdownTimer[playerid]); CountdownTimer[playerid] = -1; }
        CountdownTimer[playerid] = SetTimerEx("CountdownStartRace", 1000, false, "ii", playerid, 10);
        SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Countdown dimulai...");
        //HideStatsTD(playerid);
    }
    return 1;
}

CMD:deltrack(playerid, params[])
{
    if(AccountData[playerid][pAdmin] < 2) return PermissionError(playerid);

    new query[128];
    mysql_format(g_SQL, query, sizeof(query),
        "SELECT id, name, owner, created_at FROM race_tracks ORDER BY id DESC");
    mysql_tquery(g_SQL, query, "OnShowDeleteTrackList", "i", playerid);
    return 1;
}

ShowRaceLeaderboard(playerid)
{
    new str[1024], line[128];
    str[0] = '\0';

    // Buat array temporary peserta race
    new temp[MAX_PLAYERS], count = 0;
    foreach(new p : Player)
    {
        if(InRace[p]) // masih balapan
        {
            temp[count++] = p;
        }
        else if(RaceFinishTime[p] > 0) // sudah finish
        {
            temp[count++] = p;
        }
    }

    if(count == 0)
    {
        return ShowPlayerDialog(playerid, DIALOG_RACE_LEADERBOARD, DIALOG_STYLE_MSGBOX,"Race Leaderboard", "Tidak ada peserta dalam race.", "Tutup", "");
    }

    // Urutkan: finish duluan paling atas, sisanya berdasarkan CP
    for(new i = 0; i < count - 1; i++)
    {
        for(new j = i + 1; j < count; j++)
        {
            new a = temp[i], b = temp[j];

            new scoreA = (RaceFinishTime[a] > 0) ? 9999999 - RaceFinishTime[a] : RaceIndex[a];
            new scoreB = (RaceFinishTime[b] > 0) ? 9999999 - RaceFinishTime[b] : RaceIndex[b];

            if(scoreB > scoreA)
            {
                new tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
            }
        }
    }

    // Buat isi leaderboard
    for(new i = 0; i < count; i++)
    {
        new p = temp[i];

        if(RaceFinishTime[p] > 0) // sudah finish
        {
            new menit = (RaceFinishTime[p] / 60000);
            new detik = (RaceFinishTime[p] / 1000) % 60;
            new ms    = (RaceFinishTime[p] % 1000) / 10;

            format(line, sizeof(line), "%d. %s - Finish (%02d:%02d:%02d)\n",
                i+1, GetName(p), menit, detik, ms);
        }
        else // masih balapan
        {
            format(line, sizeof(line), "%d. %s - CP %d/%d\n",
                i+1, GetName(p), RaceIndex[p], RaceCPCount[p]);
        }
        strcat(str, line);
    }

    // Tampilkan dialog leaderboard
    ShowPlayerDialog(playerid, DIALOG_RACE_LEADERBOARD, DIALOG_STYLE_LIST,"Race Leaderboard", str, "Tutup", "");
    return 1;
}

forward OnShowDeleteTrackList(playerid);
public OnShowDeleteTrackList(playerid)
{
    new rows;
    cache_get_row_count(rows);

    if(rows <= 0)
    {
        SendClientMessage(playerid, -1, "Tidak ada track untuk dihapus.");
        return 1;
    }

    new list[2048];
    list[0] = '\0';

    for(new i = 0; i < rows; i++)
    {
        new trackname[64], owner[32], created_at[32], line[256];
        cache_get_value_name_int(i, "id", DeleteListID[playerid][i]);
        cache_get_value_name(i, "name", trackname, sizeof(trackname));
        cache_get_value_name(i, "owner", owner, sizeof(owner));
        cache_get_value_name(i, "created_at", created_at, sizeof(created_at));

        format(line, sizeof(line), "%s\t%s\t%s\n", trackname, owner, created_at);
        strcat(list, line, sizeof(list));
    }

    ShowPlayerDialog(playerid, DIALOG_RACE_DELETE, DIALOG_STYLE_TABLIST_HEADERS,"Hapus Track","Nama\tDibuat Oleh\tTanggal","Hapus", "Batal");
    ShowPlayerDialog(playerid, DIALOG_RACE_DELETE, DIALOG_STYLE_TABLIST,"Pilih Track untuk Dihapus", list, "Hapus", "Batal");
    return 1;
}

// COUNTDOWN -> START RACE (fixed)
forward CountdownStartRace(playerid, count);
public CountdownStartRace(playerid, count)
{
    if (count > 0)
    {
        new text[16];
        format(text, sizeof(text), "~r~%d", count);
        GameTextForPlayer(playerid, text, 1500, 3);

        CountdownTimer[playerid] = SetTimerEx("CountdownStartRace", 1000, false, "ii", playerid, count - 1);
    }
    else
    {
        GameTextForPlayer(playerid, "~g~GO!", 1500, 3);

        RaceTimeStart[playerid] = GetTickCount();
        RaceTimeRunning[playerid] = true;

        if(RaceTimeTimer[playerid] != -1) KillTimer(RaceTimeTimer[playerid]);
        RaceTimeTimer[playerid] = SetTimerEx("UpdateRaceTime", 100, true, "i", playerid);

        InRace[playerid]    = true;
        RaceIndex[playerid] = 0;
        RaceUI_Show(playerid);
        Race_EnableGhost(playerid, true);

        new ownerid = (RaceWith[playerid] == INVALID_PLAYER_ID) ? playerid : RaceWith[playerid];
        if (!IsValidOwner(ownerid))
        {
            InRace[playerid]     = false;
            RaceIndex[playerid]   = -1;
            RaceWith[playerid]    = INVALID_PLAYER_ID;
            RaceUI_Hide(playerid);
            return 1;
        }

        RaceUI_UpdateRanking(ownerid);

        if (RankingsTimer[ownerid] != -1) KillTimer(RankingsTimer[ownerid]);
        RankingsTimer[ownerid] = SetTimerEx("UpdateRaceRankings", 1000, true, "i", ownerid);

        if (RaceCPCount[ownerid] > 1)
        {
            SetPlayerRaceCheckpoint(playerid, 0,
                RacePos[ownerid][0][0], RacePos[ownerid][0][1], RacePos[ownerid][0][2],
                RacePos[ownerid][1][0], RacePos[ownerid][1][1], RacePos[ownerid][1][2],
                5.0
            );
        }

        new str[32];
        format(str, sizeof str, "%d/%d", RaceIndex[playerid], RaceCPCount[ownerid]);

        for (new i = 0; i < MAX_PLAYERS; i++)
        {
            if (IsPlayerConnected(i) && InRace[i] && (RaceWith[i] == ownerid || i == ownerid))
            {
                PlayerTextDrawSetString(i, ui_racing[i][7], str);
            }
        }

        CountdownTimer[playerid] = -1;
    }
    return 1;
}

forward UpdateRaceTime(playerid);
public UpdateRaceTime(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    if(!RaceTimeRunning[playerid]) return 0;

    new elapsed = GetTickCount() - RaceTimeStart[playerid]; // dalam ms

    new menit = (elapsed / 60000);
    new detik = (elapsed / 1000) % 60;
    new ms    = (elapsed % 1000) / 10; // ambil 2 digit

    new str[32];
    format(str, sizeof str, "%02d:%02d:%02d", menit, detik, ms);

    PlayerTextDrawSetString(playerid, ui_racing[playerid][10], str); // pastikan index 8 kosong untuk timer
    return 1;
}

forward OnTrackCreated(playerid, trackname[]);
public OnTrackCreated(playerid, trackname[])
{
    new trackid = cache_insert_id();
    if (trackid > 0)
    {
        for (new i = 0; i < RaceCPCount[playerid]; i++)
        {
            new query[256];
            mysql_format(g_SQL, query, sizeof(query),
                "INSERT INTO race_checkpoints (track_id, cp_order, pos_x, pos_y, pos_z) VALUES (%d,%d,%f,%f,%f)",
                trackid, i,
                RacePos[playerid][i][0],
                RacePos[playerid][i][1],
                RacePos[playerid][i][2]);
            mysql_tquery(g_SQL, query);
        }

        SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Track '%s' berhasil disimpan ke database!", trackname);
    }
    return 1;
}

forward OnShowTrackList(playerid);
public OnShowTrackList(playerid)
{
    new rows;
    cache_get_row_count(rows);

    if (rows <= 0)
    {
        Dialog_Show(playerid, "UnusedDialog", DIALOG_STYLE_MSGBOX,"List Track Race","Tidak ada track yang tersedia.","Tutup", "");
        return 1;
    }

    new list[2048];
    list[0] = '\0'; // clear string

    for (new i = 0; i < rows; i++)
    {
        new trackname[64], creator[32], created_at[32], line[256];
        
        cache_get_value_name(i, "name", trackname, sizeof(trackname));
        cache_get_value_name(i, "owner", creator, sizeof(creator));
        cache_get_value_name(i, "created_at", created_at, sizeof(created_at));
        cache_get_value_name_int(i, "id", TrackListID[playerid][i]);

        format(line, sizeof(line), "%s\t%s\t%s\n", trackname, creator, created_at);
        strcat(list, line, sizeof(list));
    }

    Dialog_Show(playerid, "DialogTrackList", DIALOG_STYLE_TABLIST_HEADERS,"List Track Race","Nama\tDibuat Oleh\tTanggal","Pilih", "Batal");
    Dialog_Show(playerid, "DialogTrackList", DIALOG_STYLE_TABLIST,"List Track Race", list, "Pilih", "Batal");

    return 1;
}

forward OnLoadTrackCheckpoints(playerid);
public OnLoadTrackCheckpoints(playerid)
{
    new rows;
    cache_get_row_count(rows);

    RaceCPCount[playerid] = 0;
    for (new i = 0; i < rows; i++)
    {
        cache_get_value_name_float(i, "pos_x", RacePos[playerid][i][0]);
        cache_get_value_name_float(i, "pos_y", RacePos[playerid][i][1]);
        cache_get_value_name_float(i, "pos_z", RacePos[playerid][i][2]);
        RaceCPCount[playerid]++;
    }

    SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Track berhasil dimuat! Total CP: %d", RaceCPCount[playerid]);
    return 1;
}

// ---- DETEKSI TOMBOL Y ----
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (SaveMode[playerid] && (newkeys & KEY_YES))
    {
        new Float:pos[3];
        GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

        RacePos[playerid][RaceCPCount[playerid]][0] = pos[0];
        RacePos[playerid][RaceCPCount[playerid]][1] = pos[1];
        RacePos[playerid][RaceCPCount[playerid]][2] = pos[2];

        RaceCPCount[playerid]++;

        SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Checkpoint %d disimpan!", RaceCPCount[playerid]);
    }
    return 1;
}

stock Float:GetRaceProgress(playerid, ownerid)
{
    if (!InRace[playerid]) return 0.0;
    if (!IsValidOwner(ownerid)) return 0.0;

    new total   = RaceCPCount[ownerid];
    new current = RaceIndex[playerid];

    if (current < 0) return 0.0;
    if (current >= total) return float(total);

    if (current + 1 >= total) return float(current);

    new veh = GetPlayerVehicleID(playerid);
    if (veh == 0) return float(current);

    new Float:px, Float:py, Float:pz;
    GetVehiclePos(veh, px, py, pz);

    new Float:cx = RacePos[ownerid][current][0];
    new Float:cy = RacePos[ownerid][current][1];
    new Float:cz = RacePos[ownerid][current][2];

    new Float:nx = RacePos[ownerid][current+1][0];
    new Float:ny = RacePos[ownerid][current+1][1];
    new Float:nz = RacePos[ownerid][current+1][2];

    new Float:totalDist = floatsqroot((nx-cx)*(nx-cx) + (ny-cy)*(ny-cy) + (nz-cz)*(nz-cz));
    new Float:playerDist= floatsqroot((nx-px)*(nx-px) + (ny-py)*(ny-py) + (nz-pz)*(nz-pz));

    new Float:segProgress = 0.0;
    if (totalDist > 0.0) segProgress = (totalDist - playerDist) / totalDist;

    return float(current) + segProgress;
}

RaceUI_Show(playerid)
{
    for (new x = 0; x < 11; x++) PlayerTextDrawShow(playerid, ui_racing[playerid][x]);
    return 1;
}

RaceUI_Hide(playerid)
{
    for (new x = 0; x < 11; x++) PlayerTextDrawHide(playerid, ui_racing[playerid][x]);
    return 1;
}

forward UpdateRaceRankings(ownerid);
public UpdateRaceRankings(ownerid)
{
    if (!IsValidOwner(ownerid))
    {
        if (RankingsTimer[ownerid] != -1)
        {
            KillTimer(RankingsTimer[ownerid]);
            RankingsTimer[ownerid] = -1;
        }
        return 1;
    }

    new hasAny = false;
    foreach (new p : Player)
    {
        if ((RaceWith[p] == ownerid || p == ownerid) && InRace[p])
        {
            hasAny = true;
            break;
        }
    }
    if (!hasAny)
    {
        if (RankingsTimer[ownerid] != -1)
        {
            KillTimer(RankingsTimer[ownerid]);
            RankingsTimer[ownerid] = -1;
        }
        return 1;
    }

    RaceUI_UpdateRanking(ownerid);
    return 1;
}

stock RaceUI_UpdateRanking(ownerid)
{
    if (!IsValidOwner(ownerid)) return 0;

    new participants[MAX_PLAYERS];
    new Float:progress[MAX_PLAYERS];
    new count;

    foreach (new p : Player)
    {
        if ((RaceWith[p] == ownerid || p == ownerid) && InRace[p])
        {
            participants[count] = p;
            progress[count] = GetRaceProgress(p, ownerid);
            count++;
        }
    }
    if (count == 0) return 0;

    for (new i = 0; i < count - 1; i++)
    {
        for (new j = i + 1; j < count; j++)
        {
            if (progress[j] > progress[i])
            {
                new tmpP = participants[i];
                participants[i] = participants[j];
                participants[j] = tmpP;

                new Float:tmpProg = progress[i];
                progress[i] = progress[j];
                progress[j] = tmpProg;
            }
        }
    }

    new line[64];
    foreach (new p : Player)
    {
        if ((RaceWith[p] == ownerid || p == ownerid) && InRace[p])
        {
            if (count >= 1) format(line, sizeof(line), "#1 %s", GetName(participants[0]));
            else format(line, sizeof(line), "#1 -");
            PlayerTextDrawSetString(p, ui_racing[p][4], line);

            if (count >= 2) format(line, sizeof(line), "#2 %s", GetName(participants[1]));
            else format(line, sizeof(line), "#2 -");
            PlayerTextDrawSetString(p, ui_racing[p][5], line);

            if (count >= 3) format(line, sizeof(line), "#3 %s", GetName(participants[2]));
            else format(line, sizeof(line), "#3 -");
            PlayerTextDrawSetString(p, ui_racing[p][6], line);
        }
    }
    return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if (!response) return 0;

    switch (dialogid)
    {
        case DIALOG_RACE_MAIN:
        {
            if (listitem == 0) // Invite
            {
                new str[512], line[64];
                str[0] = '\0';
                InviteCount[playerid] = 0;

                new Float:px, Float:py, Float:pz;
                GetPlayerPos(playerid, px, py, pz);

                foreach (new p : Player)
                {
                    if (!IsPlayerConnected(p)) continue;
                    if (RaceWith[p] != INVALID_PLAYER_ID) continue;

                    if (p != playerid) // kalau bukan dirinya sendiri
                    {
                        new Float:tx, Float:ty, Float:tz;
                        GetPlayerPos(p, tx, ty, tz);

                        if (GetDistanceBetweenPoints(px, py, pz, tx, ty, tz) > 3.0) continue;
                    }

                    format(line, sizeof(line), "%s (ID:%d)\n", GetName(p), p);
                    strcat(str, line);

                    InviteList[playerid][InviteCount[playerid]++] = p;
                }

                if (!InviteCount[playerid])
                    format(str, sizeof(str), "Tidak ada player di dekatmu untuk diundang.");

                ShowPlayerDialog(playerid, DIALOG_RACE_INVITE, DIALOG_STYLE_LIST, "Invite Pemain", str, "Invite", "Back");
            }
            else if (listitem == 1) // Kick
            {
                new str[512], line[64];
                str[0] = '\0';
                KickCount[playerid] = 0;

                foreach (new p : Player)
                {
                    if (RaceWith[p] == playerid) // owner ikut muncul juga
                    {
                        format(line, sizeof(line), "%s (ID:%d)\n", GetName(p), p);
                        strcat(str, line);
                        KickList[playerid][KickCount[playerid]++] = p;
                    }
                }

                if (!KickCount[playerid])
                    format(str, sizeof(str), "Tidak ada peserta untuk di-kick.");

                ShowPlayerDialog(playerid, DIALOG_RACE_KICK, DIALOG_STYLE_LIST,"Kick Pemain", str, "Kick", "Back");
            }
            else if (listitem == 2) // List
            {
                new str[512], line[64];
                str[0] = '\0';

                foreach (new p : Player)
                {
                    if (RaceWith[p] == playerid)
                    {
                        format(line, sizeof(line), "- %s (ID:%d)\n", GetName(p), p);
                        strcat(str, line);
                    }
                }

                if (!strlen(str))
                    format(str, sizeof(str), "Belum ada yang join.");

                ShowPlayerDialog(playerid, DIALOG_RACE_LIST, DIALOG_STYLE_MSGBOX,"Peserta Balapan", str, "OK", "");
            }
        }

        case DIALOG_RACE_INVITE:
        {
            if (!InviteCount[playerid]) return 1;

            new target = InviteList[playerid][listitem];
            if (!IsPlayerConnected(target)) return Error(playerid, "Player tidak valid.");
            if (RaceWith[target] != INVALID_PLAYER_ID) return Error(playerid, "Player sudah ada di race lain.");

            RaceWith[target] = playerid;
            InRace[target] = false;
            RaceIndex[target] = -1;

            SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Kamu berhasil invite %s.", GetName(target));
            SendClientMessageEx(target, COLOR_YELLOW, "[Race] {FFFFFF}Kamu diundang %s ke race.", GetName(playerid));
        }

        case DIALOG_RACE_KICK:
        {
            if (!KickCount[playerid]) return 1;

            new target = KickList[playerid][listitem];
            if (!IsPlayerConnected(target)) return Error(playerid, "Player tidak valid.");
            if (RaceWith[target] != playerid) return Error(playerid, "Player bukan peserta kamu.");

            RaceWith[target] = INVALID_PLAYER_ID;
            InRace[target] = false;
            RaceIndex[target] = -1;
            DisablePlayerRaceCheckpoint(target);
            RaceUI_Hide(target);

            SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Kamu mengeluarkan %s dari race.", GetName(target));
            SendClientMessageEx(target, COLOR_YELLOW, "[Race] {FFFFFF}Kamu dikeluarkan dari race oleh %s.", GetName(playerid));

            // Kalau owner kick dirinya sendiri → bubar semua
            if (target == playerid)
            {
                foreach (new p : Player)
                {
                    if (RaceWith[p] == playerid)
                    {
                        RaceWith[p] = INVALID_PLAYER_ID;
                        InRace[p] = false;
                        RaceIndex[p] = -1;
                        DisablePlayerRaceCheckpoint(p);
                        RaceUI_Hide(p);
                        SendClientMessageEx(p, COLOR_YELLOW, "[Race] {FFFFFF}Race dihentikan karena owner keluar.");
                    }
                }
                if (RankingsTimer[playerid] != -1)
                {
                    KillTimer(RankingsTimer[playerid]);
                    RankingsTimer[playerid] = -1;
                }
            }
        }
        case DIALOG_RACE_DELETE:
        {
            if(!response) return 1;

            new trackid = DeleteListID[playerid][listitem];
            if(trackid <= 0) return Error(playerid, "Track tidak valid.");

            new query[256];
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM race_tracks WHERE id=%d", trackid);
            mysql_tquery(g_SQL, query);

            // juga hapus semua checkpoint dari track ini
            mysql_format(g_SQL, query, sizeof(query), "DELETE FROM race_checkpoints WHERE track_id=%d", trackid);
            mysql_tquery(g_SQL, query);

            SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Track berhasil dihapus!");
        }
    }
    return 1;
}

Dialog:DialogTrackList(playerid, response, listitem, inputtext[])
{
    if (!response) return 1;

    new query[128];
    mysql_format(g_SQL, query, sizeof(query),
        "SELECT pos_x, pos_y, pos_z FROM race_checkpoints WHERE track_id=%d ORDER BY cp_order ASC",
        TrackListID[playerid][listitem]);

    mysql_tquery(g_SQL, query, "OnLoadTrackCheckpoints", "i", playerid);

    return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
    if (!InRace[playerid]) return 1;

    new ownerid = (RaceWith[playerid] == INVALID_PLAYER_ID) ? playerid : RaceWith[playerid];
    if (!IsValidOwner(ownerid)) return 1;

    new total = RaceCPCount[ownerid];
    new idx   = RaceIndex[playerid];

    if (idx < 0 || idx >= total) return 1;

    RaceIndex[playerid]++;

    new buf[32];
    format(buf, sizeof buf, "%d/%d", RaceIndex[playerid], total);

    PlayerTextDrawSetString(playerid, ui_racing[playerid][7], buf);

    if (RaceIndex[playerid] >= total)
    {
        DisablePlayerRaceCheckpoint(playerid);
        InRace[playerid] = false;

        // STOP TIMER
        RaceFinishTime[playerid] = GetTickCount() - RaceTimeStart[playerid];
        if(RaceTimeTimer[playerid] != -1)
        {
            KillTimer(RaceTimeTimer[playerid]);
            RaceTimeTimer[playerid] = -1;
        }
        RaceTimeRunning[playerid] = false;

        SendClientMessageEx(playerid, COLOR_YELLOW, "[Race] {FFFFFF}Selamat! Kamu sudah finish.");
        SendClientMessageEx(ownerid, COLOR_YELLOW, "[Race] {FFFFFF}%s sudah finish.", GetName(playerid));
        RaceUI_Hide(playerid);
        Race_EnableGhost(playerid, false);
        //ShowStatsTD(playerid);
    }
    else
    {
        SetPlayerRaceCheckpoint(
            playerid,
            (RaceIndex[playerid] + 1 == total) ? 1 : 0,
            RacePos[ownerid][RaceIndex[playerid]][0],
            RacePos[ownerid][RaceIndex[playerid]][1],
            RacePos[ownerid][RaceIndex[playerid]][2],
            RacePos[ownerid][RaceIndex[playerid] + 1][0],
            RacePos[ownerid][RaceIndex[playerid] + 1][1],
            RacePos[ownerid][RaceIndex[playerid] + 1][2],
            5.0
        );
    }
    return 1;
}

stock Race_EnableGhost(playerid, bool:toggle) 
{ 
    new veh = GetPlayerVehicleID(playerid); 
    if (!veh) return; 

    if (toggle) 
    {
        DisableRemoteVehicleCollisions(playerid, true); 
    } 
    else 
    {
        DisableRemoteVehicleCollisions(playerid, false); 
    }
}
