#include <YSI_Coding\y_hooks>

new bool:InCctv[MAX_PLAYERS];
new CctvIndex[MAX_PLAYERS];
new Float:CctvPitch[MAX_PLAYERS];

#define MAX_CCTV_ROOMS      12
#define CCTV_PITCH_MIN  -30.0
#define CCTV_PITCH_MAX   30.0
#define CCTV_PITCH_STEP  0.1

static const Float:CctvPos[][6] = {
    {1869.9292,120.2705,1338.9314,  1869.1766,119.7769,1338.9314},  // 0 - Lobby & Waiting Area
    {1847.8584,112.1861,1337.9949,  1847.4385,112.6147,1337.9949},  // 1 - Reception & Front Desk
    {1838.6208,119.7753,1338.6949,  1838.2014,119.4042,1338.6949},  // 2 - Officer Work Room
    {1829.5806,93.0036,1338.6949,  1829.9640,93.1748,1338.6949},  // 3 - Chief of Police Room
    {1829.6134,110.3400,1338.6949,  1829.7290,110.2611,1338.6949},  // 4 - Rooftop Area
    {1869.8247,100.8624,1338.0049,  1869.3828,100.4565,1338.0049},  // 5 - Duty Locker Room
    {1840.3293,73.2141,1338.5549,  1840.4194,73.3212,1338.5549},  // 6 - Briefing Room
    {1869.3314,87.3247,1338.8350,  1869.1805,87.0889,1338.8350},  // 7 - Conference Room
    {1854.8046,109.4657,1337.7148,  1854.8009,109.0457,1337.7148},  // 8 - Evidence Inspect Area
    {1854.7388,71.6767,1338.4149,  1854.7635,70.9772,1338.4149},  // 9 - Arrest & Holding Area
    {1861.7753,71.4115,1338.4149,  1861.9523,71.1947,1338.4149},  // 10 - Interrogation Room
    {1840.8959,63.6053,1338.1903,  1841.1233,63.8009,1338.1903}   // 11 - Mugshot Photo Room
};

static const CctvRoomName[][] = {
    "Lobby & Waiting Area",
    "Reception & Front Desk",
    "Officer Work Room",
    "Chief of Police Room",
    "Rooftop Area",
    "Duty Locker Room",
    "Briefing Room",
    "Conference Room",
    "Evidence Inspect Area",
    "Arrest & Holding Area",
    "Interrogation Room",
    "Mugshot Photo Room"
};

//------ update zoom bar ----------//
static UpdateCctvPitchBar(playerid)
{
    new Float:percent = (CctvPitch[playerid] - CCTV_PITCH_MIN) / (CCTV_PITCH_MAX - CCTV_PITCH_MIN);
    new Float:barHeight = -(percent * 83.0);
    PlayerTextDrawTextSize(playerid, CctvVRP[playerid][24], 2.0, barHeight);
    PlayerTextDrawShow(playerid, CctvVRP[playerid][24]);
}
static ApplyCctvCamera(playerid)
{
    new idx = CctvIndex[playerid];
    SetPlayerCameraPos(playerid, CctvPos[idx][0], CctvPos[idx][1], CctvPos[idx][2]);
    SetPlayerCameraLookAt(playerid, CctvPos[idx][3], CctvPos[idx][4], CctvPos[idx][5], CAMERA_CUT);
}

static ApplyCctvPitch(playerid)
{
    new idx = CctvIndex[playerid];

    SetPlayerCameraLookAt(playerid,
        CctvPos[idx][3],
        CctvPos[idx][4],
        CctvPos[idx][5] + CctvPitch[playerid],
        CAMERA_MOVE
    );
}

//------ update semua textdraw info ----------//
static UpdateCctvUI(playerid)
{
    new idx = CctvIndex[playerid];

    PlayerTextDrawSetString(playerid, CctvVRP[playerid][18], CctvRoomName[idx]);

    new szCoord[64];
    format(szCoord, sizeof(szCoord), "X: %.2f Y: %.2f Z: %.2f", CctvPos[idx][0], CctvPos[idx][1], CctvPos[idx][2]);
    PlayerTextDrawSetString(playerid, CctvVRP[playerid][7], szCoord);

    UpdateCctvPitchBar(playerid);
    ApplyCctvCamera(playerid);
}

forward CctvInit(playerid);
public CctvInit(playerid)
{
    if(!IsPlayerConnected(playerid)) return 1;
    if(!InCctv[playerid]) return 1;
    UpdateCctvUI(playerid);
    return 1;
}

hook OnGameModeInit()
{
    CreateDynamic3DTextLabel("Press "RED"[Y] "WHITE"akses Cctv", Y_WHITE, 1848.6569, 112.2898, 1335.5945, 3.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, 55, 10, -1, 2.5, -1, 0);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    InCctv[playerid] = false;
    CctvIndex[playerid] = 0;
    CreateCctvTD(playerid);
    CctvPitch[playerid] = 0.0;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(InCctv[playerid])
    {
        TogglePlayerControllable(playerid, true);
        SetCameraBehindPlayer(playerid);
        InCctv[playerid] = false;
    }
    CctvIndex[playerid] = 0;
    CctvPitch[playerid] = 0.0;
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if((newkeys & KEY_YES) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if(IsPlayerInRangeOfPoint(playerid, 3.0, 1848.6569, 112.2898, 1335.5945))
        {
            if(AccountData[playerid][pFaction] != FACTION_LSPD)
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan bagian dari kepolisian!");

            if(!AccountData[playerid][pOnDuty])
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda belom onduty kepolisian!");

            if(InCctv[playerid])
                return 1;

            InCctv[playerid] = true;
            CctvIndex[playerid] = 0;
            CctvPitch[playerid] = 0.0;

            TogglePlayerControllable(playerid, false);
            TogglePlayerSpectating(playerid, true);
            ShowCctv(playerid, true);
            SetTimerEx("CctvInit", 300, false, "i", playerid);
        }
    }
    return 1;
}

hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(!InCctv[playerid])
        return 1;

    if(playertextid == CctvVRP[playerid][38])
    {
        CctvIndex[playerid] = 0;
        CctvPitch[playerid] = 0.0;
        ShowCctv(playerid, false);
        TogglePlayerSpectating(playerid, false);
        InCctv[playerid] = false;
        TogglePlayerControllable(playerid, true);
        SetCameraBehindPlayer(playerid);
        SetTimerEx("CctvExit", 100, false, "i", playerid);
        return 1;
    }
    if(playertextid == CctvVRP[playerid][14])
    {
        CctvIndex[playerid] = (CctvIndex[playerid] - 1 + MAX_CCTV_ROOMS) % MAX_CCTV_ROOMS;
        SetPlayerPos(playerid, CctvPos[CctvIndex[playerid]][0], CctvPos[CctvIndex[playerid]][1], CctvPos[CctvIndex[playerid]][2]);
        UpdateCctvUI(playerid);
        CctvPitch[playerid] = 0.0;
        FadeIn(playerid);
        return 1;
    }
    if(playertextid == CctvVRP[playerid][15])
    {
        CctvIndex[playerid] = (CctvIndex[playerid] + 1) % MAX_CCTV_ROOMS;
        SetPlayerPos(playerid, CctvPos[CctvIndex[playerid]][0], CctvPos[CctvIndex[playerid]][1], CctvPos[CctvIndex[playerid]][2]);
        UpdateCctvUI(playerid);
        CctvPitch[playerid] = 0.0;
        FadeIn(playerid);
        return 1;
    }
    if(playertextid == CctvVRP[playerid][21])
    {
        if(CctvPitch[playerid] < CCTV_PITCH_MAX)
        {
            CctvPitch[playerid] += CCTV_PITCH_STEP;
            if(CctvPitch[playerid] > CCTV_PITCH_MAX) CctvPitch[playerid] = CCTV_PITCH_MAX;
            ApplyCctvPitch(playerid);
        }
        return 1;
    }
    if(playertextid == CctvVRP[playerid][22])
    {
        if(CctvPitch[playerid] > CCTV_PITCH_MIN)
        {
            CctvPitch[playerid] -= CCTV_PITCH_STEP;
            if(CctvPitch[playerid] < CCTV_PITCH_MIN) CctvPitch[playerid] = CCTV_PITCH_MIN;
            ApplyCctvPitch(playerid);
        }
        return 1;
    }
    return 1;
}

forward CctvExit(playerid);
public CctvExit(playerid)
{
    if(!IsPlayerConnected(playerid)) return 1;
    SetPlayerPos(playerid, 1848.6569, 112.2898, 1335.5945);
    return 1;
}