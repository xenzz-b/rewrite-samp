//===============Script lockpick optimize by Rayyzix===================//

            // Definers
#define        MAX_LOCKPICK_PINS        (8)

            // Includes
#include <YSI_Coding\y_hooks>

            // Forwards
forward OnLockPick_Tick(playerid);
forward OnLockPick_PinAnimation(playerid);
forward lockpickfitur(playerid, E_LOCKPICK_STATUS:status);

enum E_LOCKPICK_STATUS {
    E_LOCKPICK_SUCCESS,
    E_LOCKPICK_ERROR
};

static const 
    e_LockPick_Pinos[MAX_LOCKPICK_PINS][2] = {

        /*
            [0] - Pin Limit
            [1] - Pin
        */
        {1, 2}, 
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16}
    },
    
    // configurations
    updateTicks = 50,
    Float:pinTicks = 1.0,           // steps pin
    Float:dynamicPinSteps = 5.0,    // steps up
    Float:pinDistance = 10.0;       // steps for pin limit 

static enum E_LOCKPICK {
    E_LOCKPICK_CALLBACK[30 + 1],
    E_LOCKPICK_TIMER,
    E_LOCKPICK_TIMER_ANIM,
    E_LOCKPICK_PINTICK,
    E_LOCKPICK_PINTYPE,
    E_LOCKPICK_SECONDS,
    E_LOCKPICK_PROGRESS,
    Float:E_LOCKPICK_POS_Y, // backup y pos
    bool:E_LOCKPICK_PINS[MAX_LOCKPICK_PINS],
    bool:E_LOCKPICK_ANIM_PIN,
    bool:E_LOCKPICK_BACKWARD
};

static
    e_Lockpick[MAX_PLAYERS][E_LOCKPICK],
    PlayerText:tLockpick[MAX_PLAYERS][24];
new LockpickCooldown[MAX_PLAYERS];

hook OnPlayerDisconnect(playerid, reason) {

    Lockpick_Reset(playerid);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

    if(newkeys == KEY_YES && IsPlayerInLockPick(playerid) && !e_Lockpick[playerid][E_LOCKPICK_TIMER_ANIM]) {
        Lockpick_CheckPins(playerid);
        return Y_HOOKS_BREAK_RETURN_1;
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

public lockpickfitur(playerid, E_LOCKPICK_STATUS:status)
{
    if(status == E_LOCKPICK_SUCCESS)
    {
        new vehid = GetNearestVehicleToPlayer(playerid, 2.0, false);

        foreach(new i : PvtVehicles)
        {
            if(PlayerVehicle[i][pVehPhysic] == vehid)
            {
                PlayerVehicle[i][pVehLocked] = false;
                LockVehicle(PlayerVehicle[i][pVehPhysic], 0);
                ToggleVehicleLights(PlayerVehicle[i][pVehPhysic], 0);
                break;
            }
        }

        NearestVehicleID[playerid] = INVALID_VEHICLE_ID;
        AccountData[playerid][pTempVehID] = -1;

        PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
        ClearAnimations(playerid, 1);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membobol kendaraan.");
        Toggle_AllTextdraws(playerid, true);
    }
    else if(status == E_LOCKPICK_ERROR)
    {
        ClearAnimations(playerid, 1);
        ShowTDN(playerid, NOTIFICATION_ERROR, "Anda gagal membobol kendaraan.");
        Toggle_AllTextdraws(playerid, true);
    }
    LockpickCooldown[playerid] = gettime() + 60;
}

public OnLockPick_Tick(playerid) {

    // progress
    e_Lockpick[playerid][E_LOCKPICK_SECONDS]++;
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][21], 119.000 - ((119.000 / e_Lockpick[playerid][E_LOCKPICK_PROGRESS]) * e_Lockpick[playerid][E_LOCKPICK_SECONDS]), 7.0);
    PlayerTextDrawShow(playerid, tLockpick[playerid][21]);

    if(e_Lockpick[playerid][E_LOCKPICK_SECONDS] >= e_Lockpick[playerid][E_LOCKPICK_PROGRESS]) {
        Lockpick_Response(playerid, E_LOCKPICK_ERROR);
        return true;
    }

    // wait for anim pin
    if(e_Lockpick[playerid][E_LOCKPICK_ANIM_PIN])
        return true;

    new Float:position[2];
    PlayerTextDrawGetPos(playerid, tLockpick[playerid][23], position[0], position[1]);

    if(e_Lockpick[playerid][E_LOCKPICK_BACKWARD]) position[0] -= pinTicks;
    else position[0] += pinTicks;

    new Float:mainBoxPos, Float:mainBoxSize;
    PlayerTextDrawGetPos(playerid, tLockpick[playerid][0], mainBoxPos);
    PlayerTextDrawGetTextSize(playerid, tLockpick[playerid][0], mainBoxSize);
    
    if(position[0] <= mainBoxPos) e_Lockpick[playerid][E_LOCKPICK_BACKWARD] = false;                           // min limit
    else if(position[0] >= (mainBoxPos + mainBoxSize)) e_Lockpick[playerid][E_LOCKPICK_BACKWARD] = true;       // max limit

    SetLockPick_Pin(playerid, position[0], position[1]);
    return true;
}

public OnLockPick_PinAnimation(playerid) {

    new Float:position[2], Float:position_y = e_Lockpick[playerid][E_LOCKPICK_POS_Y];
    PlayerTextDrawGetPos(playerid, tLockpick[playerid][23], position[0], position[1]);

    switch(e_Lockpick[playerid][E_LOCKPICK_PINTYPE]) {
        case 0: // pin up
        {
            if(position[1] <= (position_y - pinDistance))
                e_Lockpick[playerid][E_LOCKPICK_PINTYPE] = 1;

            position[1] -= pinTicks;
        }
        
        case 1: // checkpin and move
        {
            new pin_index = e_Lockpick[playerid][E_LOCKPICK_PINTICK];
            if(pin_index != -1 && !e_Lockpick[playerid][E_LOCKPICK_PINS][pin_index])
            {
                // get positions
                new Float:dynamicPosition[2], Float:dynamicLimitPos[2];
                PlayerTextDrawGetPos(playerid, tLockpick[playerid][e_LockPick_Pinos[pin_index][0]], dynamicLimitPos[0], dynamicLimitPos[1]);
                PlayerTextDrawGetPos(playerid, tLockpick[playerid][e_LockPick_Pinos[pin_index][1]], dynamicPosition[0], dynamicPosition[1]);

                // set up pin animation
                dynamicPosition[1] -= dynamicPinSteps;
                PlayerTextDrawSetPos(playerid, tLockpick[playerid][e_LockPick_Pinos[pin_index][1]], dynamicPosition[0], dynamicPosition[1]);

                e_Lockpick[playerid][E_LOCKPICK_PINS][pin_index] = true;  // set pin finish
            }
            else 
            {
                Lockpick_Response(playerid, E_LOCKPICK_ERROR);
                return false;
            }

            e_Lockpick[playerid][E_LOCKPICK_PINTYPE] = 2;
        }

        case 2: // back pin main
        {
            if(position[1] >= position_y) {
                e_Lockpick[playerid][E_LOCKPICK_PINTYPE] = 3;
                position[1] = position_y;
            }
            else position[1] += pinTicks;
        }

        case 3: // check and continue anims
        {
            KillTimer(e_Lockpick[playerid][E_LOCKPICK_TIMER_ANIM]);
            e_Lockpick[playerid][E_LOCKPICK_TIMER_ANIM] = 0;
            e_Lockpick[playerid][E_LOCKPICK_PINTYPE] = 0;
            e_Lockpick[playerid][E_LOCKPICK_ANIM_PIN] = false;

            new bool:hasPin;
            for(new i = 0; i < MAX_LOCKPICK_PINS; i++) {
                if(e_Lockpick[playerid][E_LOCKPICK_PINS][i])
                    continue;

                hasPin = true;
                break;
            }

            if(!hasPin)
                Lockpick_Response(playerid, E_LOCKPICK_SUCCESS);
        }
    }

    SetLockPick_Pin(playerid, position[0], position[1]);
    return true;
}

stock CreateLockPick(playerid, const callback[], seconds) {

    // Block
    if(IsPlayerInLockPick(playerid))
        return false;

    ShowLockPick(playerid);
    SetLockPick_Pin(playerid, 252.000, 249.000);

    format(e_Lockpick[playerid][E_LOCKPICK_CALLBACK], 30, callback);
    e_Lockpick[playerid][E_LOCKPICK_PROGRESS] = (seconds * 1000) / 100;
    e_Lockpick[playerid][E_LOCKPICK_TIMER] = SetTimerEx("OnLockPick_Tick", updateTicks, true, "i", playerid);
    return true;
}

stock CancelLockPick(playerid) {

    if(!IsPlayerInLockPick(playerid))
        return false;
    
    Lockpick_Reset(playerid);
    return true;
}

stock IsPlayerInLockPick(playerid)
    return e_Lockpick[playerid][E_LOCKPICK_TIMER] != 0;

static stock Lockpick_CheckPins(playerid) {

    new 
        Float:dynamicPosition,
        Float:dynamicPositionSize,
        Float:position[2],
        pinFound = -1;

    e_Lockpick[playerid][E_LOCKPICK_ANIM_PIN] = true;
    PlayerTextDrawGetPos(playerid, tLockpick[playerid][23], position[0], position[1]);

    for(new i = 0; i < sizeof e_LockPick_Pinos; i++) {
        PlayerTextDrawGetPos(playerid, tLockpick[playerid][e_LockPick_Pinos[i][1]], dynamicPosition);
        PlayerTextDrawGetTextSize(playerid, tLockpick[playerid][e_LockPick_Pinos[i][1]], dynamicPositionSize);

        if(position[0] >= dynamicPosition && position[0] <= dynamicPosition + dynamicPositionSize) {
            pinFound = i;
            break;
        }
    }

    e_Lockpick[playerid][E_LOCKPICK_PINTYPE] = 0;
    e_Lockpick[playerid][E_LOCKPICK_PINTICK] = pinFound;
    e_Lockpick[playerid][E_LOCKPICK_POS_Y] = position[1];
    e_Lockpick[playerid][E_LOCKPICK_TIMER_ANIM] = SetTimerEx("OnLockPick_PinAnimation", 50, true, "i", playerid);
}

static stock SetLockPick_Pin(playerid, Float:x, Float:y) {

    PlayerTextDrawSetPos(playerid, tLockpick[playerid][22], x - 45.0, y);
    PlayerTextDrawSetPos(playerid, tLockpick[playerid][23], x, y);
}

static stock Lockpick_Response(playerid, E_LOCKPICK_STATUS:status) {

    new callback[30 + 1];
    strcat(callback, e_Lockpick[playerid][E_LOCKPICK_CALLBACK]);

    Lockpick_Reset(playerid);
    CallLocalFunction(callback, "ii", playerid, _:status);
}

static stock Lockpick_Reset(playerid) {

    if(e_Lockpick[playerid][E_LOCKPICK_TIMER_ANIM])
        KillTimer(e_Lockpick[playerid][E_LOCKPICK_TIMER_ANIM]);    

    if(e_Lockpick[playerid][E_LOCKPICK_TIMER])
        KillTimer(e_Lockpick[playerid][E_LOCKPICK_TIMER]); 

    HideLockPick(playerid);

    static const e_Clear[E_LOCKPICK];
    e_Lockpick[playerid] = e_Clear;
}

static stock ShowLockPick(playerid) {

    tLockpick[playerid][0] = CreatePlayerTextDraw(playerid, 252.000, 186.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][0], 119.000, 76.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][0], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][0], 303174399);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][0], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][0], 1);

    tLockpick[playerid][1] = CreatePlayerTextDraw(playerid, 270.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][1], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][1], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][1], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][1], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][1], 1);

    tLockpick[playerid][2] = CreatePlayerTextDraw(playerid, 270.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][2], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][2], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][2], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][2], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][2], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][2], 1);

    tLockpick[playerid][3] = CreatePlayerTextDraw(playerid, 281.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][3], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][3], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][3], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][3], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][3], 1);

    tLockpick[playerid][4] = CreatePlayerTextDraw(playerid, 281.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][4], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][4], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][4], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][4], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][4], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][4], 1);

    tLockpick[playerid][5] = CreatePlayerTextDraw(playerid, 292.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][5], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][5], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][5], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][5], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][5], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][5], 1);

    tLockpick[playerid][6] = CreatePlayerTextDraw(playerid, 292.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][6], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][6], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][6], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][6], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][6], 1);

    tLockpick[playerid][7] = CreatePlayerTextDraw(playerid, 303.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][7], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][7], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][7], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][7], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][7], 1);

    tLockpick[playerid][8] = CreatePlayerTextDraw(playerid, 303.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][8], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][8], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][8], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][8], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][8], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][8], 1);

    tLockpick[playerid][9] = CreatePlayerTextDraw(playerid, 314.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][9], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][9], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][9], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][9], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][9], 1);

    tLockpick[playerid][10] = CreatePlayerTextDraw(playerid, 314.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][10], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][10], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][10], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][10], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][10], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][10], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][10], 1);

    tLockpick[playerid][11] = CreatePlayerTextDraw(playerid, 325.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][11], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][11], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][11], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][11], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][11], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][11], 1);

    tLockpick[playerid][12] = CreatePlayerTextDraw(playerid, 325.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][12], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][12], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][12], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][12], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][12], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][12], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][12], 1);

    tLockpick[playerid][13] = CreatePlayerTextDraw(playerid, 336.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][13], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][13], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][13], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][13], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][13], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][13], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][13], 1);

    tLockpick[playerid][14] = CreatePlayerTextDraw(playerid, 336.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][14], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][14], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][14], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][14], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][14], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][14], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][14], 1);

    tLockpick[playerid][15] = CreatePlayerTextDraw(playerid, 347.000, 196.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][15], 6.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][15], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][15], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][15], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][15], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][15], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][15], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][15], 1);

    tLockpick[playerid][16] = CreatePlayerTextDraw(playerid, 347.000, 204.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][16], 6.000, 33.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][16], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][16], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][16], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][16], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][16], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][16], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][16], 1);

    tLockpick[playerid][17] = CreatePlayerTextDraw(playerid, 252.000, 160.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][17], 119.000, 24.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][17], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][17], 303174399);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][17], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][17], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][17], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][17], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][17], 1);

    tLockpick[playerid][18] = CreatePlayerTextDraw(playerid, 257.000, 164.000, "LOCKPICK");
    PlayerTextDrawLetterSize(playerid, tLockpick[playerid][18], 0.200, 0.999);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][18], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][18], -1);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][18], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][18], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][18], 150);
    PlayerTextDrawFont(playerid, tLockpick[playerid][18], 1);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][18], 1);

    tLockpick[playerid][19] = CreatePlayerTextDraw(playerid, 257.000, 173.000, "Tekan Y untuk mendorong pin ke atas");
    PlayerTextDrawLetterSize(playerid, tLockpick[playerid][19], 0.129, 0.699);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][19], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][19], 1768516095);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][19], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][19], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][19], 150);
    PlayerTextDrawFont(playerid, tLockpick[playerid][19], 1);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][19], 1);

    tLockpick[playerid][20] = CreatePlayerTextDraw(playerid, 252.000, 264.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][20], 119.000, 7.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][20], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][20], 303174399);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][20], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][20], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][20], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][20], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][20], 1);

    tLockpick[playerid][21] = CreatePlayerTextDraw(playerid, 252.000, 264.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][21], 24.000, 7.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][21], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][21], -12582657);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][21], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][21], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][21], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][21], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][21], 1);

    tLockpick[playerid][22] = CreatePlayerTextDraw(playerid, 218.000, 249.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][22], 47.000, 3.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][22], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][22], -1);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][22], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][22], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][22], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][22], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][22], 1);

    tLockpick[playerid][23] = CreatePlayerTextDraw(playerid, 263.000, 249.000, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, tLockpick[playerid][23], 2.000, -8.000);
    PlayerTextDrawAlignment(playerid, tLockpick[playerid][23], 1);
    PlayerTextDrawColor(playerid, tLockpick[playerid][23], -1);
    PlayerTextDrawSetShadow(playerid, tLockpick[playerid][23], 0);
    PlayerTextDrawSetOutline(playerid, tLockpick[playerid][23], 0);
    PlayerTextDrawBackgroundColor(playerid, tLockpick[playerid][23], 255);
    PlayerTextDrawFont(playerid, tLockpick[playerid][23], 4);
    PlayerTextDrawSetProportional(playerid, tLockpick[playerid][23], 1);

    for(new i = 0; i < sizeof tLockpick[]; i++)
        PlayerTextDrawShow(playerid, tLockpick[playerid][i]);
}

static stock HideLockPick(playerid) {

    for(new i = 0; i < sizeof tLockpick[]; i++) {
        PlayerTextDrawDestroy(playerid, tLockpick[playerid][i]);
        tLockpick[playerid][i] = PlayerText:INVALID_TEXT_DRAW;
    }
}