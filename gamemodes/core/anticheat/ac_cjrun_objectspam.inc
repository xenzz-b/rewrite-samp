#include <YSI_Coding\y_hooks>

// CJ Run: anim 1231/1226 + speed >45km/h = violation. 3 violations = kick.
//   Decay: reset violations jika >=2 detik sejak terakhir CJ run terdeteksi.
//   Object Spam: GetPlayerObjectCount >2000 + spike >200 = kick (open.mp only).

#define AC_CJRUN_SPEED_THRESHOLD  45.0
#define AC_CJRUN_DECAY_TIME       2
#define AC_OBJECT_SPAM_MAX        2000
#define AC_OBJECT_SPAM_SPIKE      200

#define AC_CJRUN_ANIM_1           1231
#define AC_CJRUN_ANIM_2           1226

enum e_ACCJRun
{
    acLastPlayerObjectCount,
    acCJRunViolations,
    acCJRunLastDetectTime
};

new AC_CJData[MAX_PLAYERS][e_ACCJRun];

hook OnPlayerConnect(playerid)
{
    AC_CJData[playerid][acLastPlayerObjectCount] = 0;
    AC_CJData[playerid][acCJRunViolations]       = 0;
    AC_CJData[playerid][acCJRunLastDetectTime]   = 0;
    return 1;
}

hook OnPlayerUpdate(playerid)
{
    if(!AC_CanPunish(playerid))
        return 1;

    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && 
       GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK)
    {
        new animidx = GetPlayerAnimationIndex(playerid);
        if(animidx == AC_CJRUN_ANIM_1 || animidx == AC_CJRUN_ANIM_2)
        {
            new Float:speed = AC_GetSpeed(playerid);
            new Float:speedKmh = speed * 179.28625;

            if(speedKmh > AC_CJRUN_SPEED_THRESHOLD)
            {
                AC_CJData[playerid][acCJRunViolations]++;
                AC_CJData[playerid][acCJRunLastDetectTime] = gettime();
                
                if(AC_CJData[playerid][acCJRunViolations] >= 3)
                {
                    new acdetail[96];
                    format(acdetail, sizeof(acdetail), "anim %d, speed %.1fkm/h > %.1fkm/h (violations: %d)",
                        animidx, speedKmh, AC_CJRUN_SPEED_THRESHOLD, AC_CJData[playerid][acCJRunViolations]);
                    AC_Kick(playerid, "CJ Run Hack", acdetail);
                    return 0;
                }

                SendStaffMessage(Y_RED, "[AntiCheat] "YELLOW"%s(%i) {DBD7D2}diduga menggunakan CJ Run Hack. "YELLOW"[Speed: %.1fkm/h]", GetName(playerid), playerid, speedKmh);
            }
        }
        else
        {
            if(AC_CJData[playerid][acCJRunViolations] > 0 && 
               gettime() - AC_CJData[playerid][acCJRunLastDetectTime] >= AC_CJRUN_DECAY_TIME)
            {
                AC_CJData[playerid][acCJRunViolations] = 0;
            }
        }
    }

    #if defined GetPlayerObjectCount
    {
        new objectCount = GetPlayerObjectCount(playerid);
        if(objectCount > AC_OBJECT_SPAM_MAX && 
           objectCount > AC_CJData[playerid][acLastPlayerObjectCount] + AC_OBJECT_SPAM_SPIKE)
        {
            new acdetail[96];
            format(acdetail, sizeof(acdetail), "objects: %d (spike: %d, max: %d)",
                objectCount, objectCount - AC_CJData[playerid][acLastPlayerObjectCount], AC_OBJECT_SPAM_MAX);
            AC_Kick(playerid, "Mapping Stealer", acdetail);
            return 0;
        }
        AC_CJData[playerid][acLastPlayerObjectCount] = objectCount;
    }
    #endif

    return 1;
}
