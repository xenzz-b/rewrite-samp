#include <YSI_Coding\y_hooks>

new Float:CamAngle[MAX_PLAYERS];
new Float:CamZoom[MAX_PLAYERS];
new Float:CamDist[MAX_PLAYERS];
new bool:CamActive[MAX_PLAYERS];

#define CAM_ZOOM_MIN        (15.0)
#define CAM_ZOOM_MAX        (75.0)
#define CAM_ZOOM_STEP       (5.0)
#define CAM_ZOOM_DEFAULT    (60.0)
#define CAM_DIST_DEFAULT    (6.0)
#define CAM_ANGLE_STEP      (15)
#define CAM_BAR_WIDTH_MIN   (0.0)
#define CAM_BAR_WIDTH_MAX   (4.0)

//------ update angle text ----------//
static UpdateAngleText(playerid)
{
    new szAngle[16];
    format(szAngle, sizeof(szAngle), "%d deg", floatround(CamAngle[playerid]));
    PlayerTextDrawSetString(playerid, CameraNSRP[playerid][35], szAngle);
}

//------ update koordinat text ----------//
static UpdateCoordText(playerid)
{
    new Float:x, Float:y, Float:z, szCoord[64];
    GetPlayerPos(playerid, x, y, z);
    format(szCoord, sizeof(szCoord), "X: %.2f Y: %.2f Z: %.2f", x, y, z);
    PlayerTextDrawSetString(playerid, CameraNSRP[playerid][7], szCoord);
}

//------ update bar zoom ----------//
static UpdateZoomBar(playerid)
{
    new Float:percent = (CAM_ZOOM_MAX - CamZoom[playerid]) / (CAM_ZOOM_MAX - CAM_ZOOM_MIN);
    new Float:barHeight = -(percent * 83.0);
    PlayerTextDrawTextSize(playerid, CameraNSRP[playerid][41], 2.0, barHeight);
    PlayerTextDrawShow(playerid, CameraNSRP[playerid][41]); 
}
//------ apply posisi kamera ----------//
static ApplyCamera(playerid)
{
    new Float:px, Float:py, Float:pz;
    GetPlayerPos(playerid, px, py, pz);

    new Float:rad = CamAngle[playerid] * (3.14159265 / 180.0);
    new Float:zoomDist = CamDist[playerid] * (CamZoom[playerid] / CAM_ZOOM_DEFAULT);
    new Float:camX = px + (zoomDist * floatsin(-rad, radian));
    new Float:camY = py + (zoomDist * floatcos(-rad, radian));
    new Float:camZ = pz + 0.8;

    SetPlayerCameraPos(playerid, camX, camY, camZ);
    SetPlayerCameraLookAt(playerid, px, py, pz + 0.5, CAMERA_MOVE);
}

//------ open camera mode ----------//
OpenCameraMode(playerid)
{
    RemovePlayerAttachedObject(playerid, 9);
	StopLoopingAnim(playerid);
    ClearAllChat(playerid);

    if(!IsPlayerInAnyVehicle(playerid))
    {
        ApplyAnimation(playerid, "ROB_BANK", "SHP_HandsUp_Scr", 4.1, 0, 0, 0, 1, 0, 1);
    }
    ShowCameraTD(playerid, true);

    new Float:facing;
    GetPlayerFacingAngle(playerid, facing);

    CamAngle[playerid]  = facing;
    if(CamAngle[playerid] >= 360.0) CamAngle[playerid] -= 360.0;
    CamZoom[playerid]   = CAM_ZOOM_DEFAULT;
    CamDist[playerid]   = CAM_DIST_DEFAULT;
    CamActive[playerid] = true;

    ApplyCamera(playerid);
    UpdateAngleText(playerid);
    UpdateCoordText(playerid);
    UpdateZoomBar(playerid);
}

hook OnPlayerConnect(playerid)
{
    CamAngle[playerid]  = 0.0;
    CamZoom[playerid]   = CAM_ZOOM_DEFAULT;
    CamDist[playerid]   = CAM_DIST_DEFAULT;
    CamActive[playerid] = false;
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(CamActive[playerid]) CloseCameraMode(playerid);
    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason)
{
    if(CamActive[playerid]) CloseCameraMode(playerid);
    return 1;
}

//------ close camera mode ----------//
CloseCameraMode(playerid)
{
    ShowCameraTD(playerid, false);
    CamActive[playerid] = false;
    SetCameraBehindPlayer(playerid);
    if(!IsPlayerInAnyVehicle(playerid))
	{
		ApplyAnimation(playerid, "ped","Jetpack_Idle", 4.1, false, false, false, true, 0, true);
		SetPlayerAttachedObject(playerid, 9, 18871, 5, 0.043000, 0.022999, -0.006000, -112.000022, -34.900020, -8.500002, 1.000000, 1.000000, 1.000000);
	}
}

//------ click textdraw ----------//
hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(!CamActive[playerid]) return 0;

    if(playertextid == CameraNSRP[playerid][30])
    {
        CamAngle[playerid] -= float(CAM_ANGLE_STEP);
        if(CamAngle[playerid] < 0.0) CamAngle[playerid] += 360.0;
        UpdateAngleText(playerid);
        ApplyCamera(playerid);
        return 1;
    }

    if(playertextid == CameraNSRP[playerid][31])
    {
        CamAngle[playerid] += float(CAM_ANGLE_STEP);
        if(CamAngle[playerid] >= 360.0) CamAngle[playerid] -= 360.0;
        UpdateAngleText(playerid);
        ApplyCamera(playerid);
        return 1;
    }

    if(playertextid == CameraNSRP[playerid][38])
    {
        if(CamZoom[playerid] > CAM_ZOOM_MIN)
        {
            CamZoom[playerid] -= CAM_ZOOM_STEP;
            if(CamZoom[playerid] < CAM_ZOOM_MIN) CamZoom[playerid] = CAM_ZOOM_MIN;
            UpdateZoomBar(playerid);
            ApplyCamera(playerid);
        }
        return 1;
    }

    if(playertextid == CameraNSRP[playerid][39])
    {
        if(CamZoom[playerid] < CAM_ZOOM_MAX)
        {
            CamZoom[playerid] += CAM_ZOOM_STEP;
            if(CamZoom[playerid] > CAM_ZOOM_MAX) CamZoom[playerid] = CAM_ZOOM_MAX;
            UpdateZoomBar(playerid);
            ApplyCamera(playerid);
        }
        return 1;
    }

    if(playertextid == CameraNSRP[playerid][59])
    {
        ShowCameraTD(playerid, false);
        SetTimerEx("CameraShowTextdrawBack", 5000, false, "i", playerid);
        return 1;
    }

    if(playertextid == CameraNSRP[playerid][55])
    {
        CloseCameraMode(playerid);
        ShowPhoneNSRP(playerid);
        return 1;
    }
    return 0;
}

//------ timer show textdraw setelah capture ----------//
forward CameraShowTextdrawBack(playerid);
public CameraShowTextdrawBack(playerid)
{
    if(!IsPlayerConnected(playerid)) return 0;
    ShowCameraTD(playerid, true);
    return 1;
}
