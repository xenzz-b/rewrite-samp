//#include "core/anticheat/ddos"
#include "core/anticheat/cbug"

#define MAX_ANTICHEAT_WARNINGS 3
#define AC_HISTORY_FRAMES       4
#define AC_AIRBREAK_POS_SPEED   8.0
#define AC_AIRBREAK_VEL_MAX     0.08

static const Float:modShopLocations[][] =
{
    {10.0,  -1936.0861, 237.4443,   34.3125},
	{10.0,  -2714.6309, 217.3955,   4.2965},
	{10.0,  2386.7686,  1042.1649,  10.8203},
	{10.0,  2644.9480,  -2037.6088, 13.5500},
	{10.0,  1041.2783,  -1027.8124, 32.1016},
	{50.0,  616.0253,   -8.0157,    1000.9219},
	{50.0,  615.2108,   -75.3288,   997.9922},
	{50.0,  612.9303,   -124.1615,  997.9922}
};

IsPlayerNearModShop(playerid)
{
	if(IsPlayerInAnyVehicle(playerid))
	{
		for(new i; i < sizeof(modShopLocations); i ++)
		{
		    if(IsPlayerInRangeOfPoint(playerid, modShopLocations[i][0], modShopLocations[i][1], modShopLocations[i][2], modShopLocations[i][3]))
		    {
		        return 1;
			}
		}
	}
	
	return 0;
}

AC_RangeCheck(Float:x1, Float:y1, Float:z1, Float:radius, Float:x2, Float:y2, Float:z2)
{
	x1 -= x2;
	y1 -= y2;
	z1 -= z2;

	return ((x1 * x1) + (y1 * y1) + (z1 * z1)) < (radius * radius);
}

Float:AC_GetSpeed(playerid)
{
	new
		Float:vx,
		Float:vy,
		Float:vz;

	if(IsPlayerInAnyVehicle(playerid))
	{
		GetVehicleVelocity(GetPlayerVehicleID(playerid), vx, vy, vz);
	}
	else
	{
	    GetPlayerVelocity(playerid, vx, vy, vz);
	}

	return floatsqroot((vx * vx) + (vy * vy) + (vz * vz));
}

enum e_Anticheat
{
    Float:acPos[3],
    Float:acSpawn[3],
    acImmunity,
    acAirbreakTime,
    acArmorTime,
    acHealthTime,
    Float:acHealth,
    Float:acArmour,
    Float:acDBHealth,
    Float:acDBArmour,
    acHealthWarns,
    acArmorWarns,
    acVehHealthWarns,
    acHistoryIdx,
    acAirbreakV2Warns
};
new Anticheat[MAX_PLAYERS][e_Anticheat];
new Float:ac_HistoryPos[MAX_PLAYERS][AC_HISTORY_FRAMES * 3];
new ac_HistoryTime[MAX_PLAYERS][AC_HISTORY_FRAMES];

OnPlayerTeleport(playerid, Float:distance)
{
    if(AccountData[playerid][pAdmin] < 1 || !AccountData[playerid][pWitch])
    {
        if(!IsPlayerInRangeOfPoint(playerid, 4.0, AccountData[playerid][pPos][0], AccountData[playerid][pPos][1], AccountData[playerid][pPos][2]))
        {
            AccountData[playerid][pACWarns]++;

            if(AccountData[playerid][pACWarns] >= MAX_ANTICHEAT_WARNINGS)
            {
                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}ditendang dari server karena Teleport Hack.", GetName(playerid), playerid);
                SendClientMessage(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda ditendang dari server karena Teleport Hack.");
                return KickEx(playerid);
            }

            if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER || GetPlayerState(playerid) == PLAYER_STATE_PASSENGER)
            {
                new vsID = GetVehicleModel(GetPlayerVehicleID(playerid));
                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Teleport Hack. "YELLOW"[D: %.1f m] [%s]", GetName(playerid), playerid, distance, GetVehicleModelName(vsID));
            }
            else
            {
                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Teleport Hack. "YELLOW"[D: %.1f m] [F]", GetName(playerid), playerid, distance);
            }
        }
    }
	return 1;
}

OnPlayerAirbreak(playerid)
{
	if(AccountData[playerid][pAdmin] < 1 || !AccountData[playerid][pWitch])
    {
	    AccountData[playerid][pACWarns]++;

	    if(AccountData[playerid][pACWarns] >= MAX_ANTICHEAT_WARNINGS)
	    {
	        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}ditendang dari server karena Airbreak.", GetName(playerid), playerid);
            SendClientMessage(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda telah ditendang dari server karena Airbreak.");
            return KickEx(playerid);
		}

        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan Airbreak.", GetName(playerid), playerid);
	}
	return 1;
}

ptask CheckingACTeleport[1000](playerid) 
{
    if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING || GetPlayerState(playerid) == PLAYER_STATE_NONE)
        return 1;

    if(!AccountData[playerid][IsLoggedIn])
        return 1;

    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    if(x == 0.0 && y == 0.0 && z == 0.0)
        return 1;

    new pAcState = GetPlayerState(playerid);

    // === Update rolling position history ===
    new hidx = Anticheat[playerid][acHistoryIdx];
    ac_HistoryPos[playerid][hidx * 3] = x;
    ac_HistoryPos[playerid][hidx * 3 + 1] = y;
    ac_HistoryPos[playerid][hidx * 3 + 2] = z;
    ac_HistoryTime[playerid][hidx] = gettime();
    Anticheat[playerid][acHistoryIdx] = (hidx + 1) % AC_HISTORY_FRAMES;

    new immunity = Anticheat[playerid][acImmunity];

    // Teleport >200m
    if(gettime() > immunity && !IsPlayerInRangeOfPoint(playerid, 200.0, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2])
        && !IsPlayerInRangeOfPoint(playerid, 5.0, Anticheat[playerid][acSpawn][0], Anticheat[playerid][acSpawn][1], Anticheat[playerid][acSpawn][2]))
    {
        if(!AC_RangeCheck(Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2],
            3.0, Anticheat[playerid][acSpawn][0], Anticheat[playerid][acSpawn][1], Anticheat[playerid][acSpawn][2])
            && pAcState != PLAYER_STATE_PASSENGER && !IsPlayerNearModShop(playerid))
        {
            OnPlayerTeleport(playerid, GetPlayerDistanceFromPoint(playerid, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]));
        }
    }

    // Teleport bertahap (>50m/3dtk tanpa velocity)
    if(gettime() > immunity && pAcState != PLAYER_STATE_PASSENGER && !IsPlayerNearModShop(playerid))
    {
        new oldestIdx = (Anticheat[playerid][acHistoryIdx] + 1) % AC_HISTORY_FRAMES;
        if(ac_HistoryTime[playerid][oldestIdx] > 0)
        {
            new Float:age = float(gettime() - ac_HistoryTime[playerid][oldestIdx]);
            if(age > 2.0 && age < 5.0)
            {
                new Float:dx = ac_HistoryPos[playerid][oldestIdx * 3] - x;
                new Float:dy = ac_HistoryPos[playerid][oldestIdx * 3 + 1] - y;
                new Float:dz = ac_HistoryPos[playerid][oldestIdx * 3 + 2] - z;
                new Float:dist = floatsqroot(dx*dx + dy*dy + dz*dz);

                if(dist > 50.0 && !IsPlayerInAnyVehicle(playerid))
                {
                    new Float:speed = AC_GetSpeed(playerid);
                    new Float:expSpeed = dist / age;
                    if(speed < expSpeed * 0.3)
                        OnPlayerTeleport(playerid, dist);
                }
            }
        }
    }

    // Airbreak v2 — posSpeed vs velocity
    if(gettime() > immunity && gettime() > Anticheat[playerid][acAirbreakTime]
        && !IsPlayerInRangeOfPoint(playerid, 10.0, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]))
    {
        if((pAcState == PLAYER_STATE_ONFOOT || pAcState == PLAYER_STATE_DRIVER)
            && GetPlayerSurfingVehicleID(playerid) == INVALID_VEHICLE_ID
            && GetPlayerSurfingObjectID(playerid) == INVALID_OBJECT_ID)
        {
            new Float:dx = Anticheat[playerid][acPos][0] - x;
            new Float:dy = Anticheat[playerid][acPos][1] - y;
            new Float:dz = Anticheat[playerid][acPos][2] - z;
            new Float:posSpeed = floatsqroot(dx*dx + dy*dy + dz*dz);

            if(posSpeed > AC_AIRBREAK_POS_SPEED)
            {
                new Float:vel = AC_GetSpeed(playerid);
                if(vel < AC_AIRBREAK_VEL_MAX)
                {
                    Anticheat[playerid][acAirbreakV2Warns]++;
                    if(Anticheat[playerid][acAirbreakV2Warns] >= 3)
                    {
                        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}ditendang karena Airbreak v2.", GetName(playerid), playerid);
                        SendClientMessage(playerid, Y_RED, "[AntiCheat] {DBD7D2}Anda ditendang karena Airbreak.");
                        KickEx(playerid);
                        return 1;
                    }
                    else
                    {
                        SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga Airbreak. [v2 warn %d/3] [posSpeed: %.1f vel: %.3f]",
                            GetName(playerid), playerid, Anticheat[playerid][acAirbreakV2Warns], posSpeed, vel);
                        Anticheat[playerid][acAirbreakTime] = gettime() + 2;
                    }
                }
            }
            else
            {
                new Float:dpx = floatabs(Anticheat[playerid][acPos][0] - x);
                new Float:dpy = floatabs(Anticheat[playerid][acPos][1] - y);
                new Float:dpz = floatabs(Anticheat[playerid][acPos][2] - z);

                if(((0.5 <= dpx < 13.9) && (0.5 <= dpy <= 13.9)) || (4.2 <= dpz <= 19.2))
                {
                    new Float:speed = AC_GetSpeed(playerid);
                    if((0.082 <= speed <= 0.215 && pAcState == PLAYER_STATE_ONFOOT) || (0.0009 <= speed <= 0.0013 && pAcState == PLAYER_STATE_DRIVER))
                    {
                        OnPlayerAirbreak(playerid);
                        Anticheat[playerid][acAirbreakTime] = gettime() + 1;
                    }
                }
            }
        }
    }

    GetPlayerPos(playerid, Anticheat[playerid][acPos][0], Anticheat[playerid][acPos][1], Anticheat[playerid][acPos][2]);
    return 1;
}