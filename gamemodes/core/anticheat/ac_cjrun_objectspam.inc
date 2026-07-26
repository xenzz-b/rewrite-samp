#include <YSI_Coding\y_hooks>

// ---------------------------------------------------------------------------
//  AC_CJRUN_OBJECTSPAM — Deteksi CJ Run hack + Object spam (mapping stealer)
//  Adaptasi dari ac-hytam-legam, disesuaikan dengan framework Vertex
// ---------------------------------------------------------------------------

#define AC_CJRUN_SPEED_THRESHOLD  45.0    // km/h: CJ run di atas ini = hack
#define AC_OBJECT_SPAM_MAX        2000    // max player objects yang wajar
#define AC_OBJECT_SPAM_SPIKE      200     // spike tambahan dalam 1 detik = stealer

// CJ Run animations (index 1231 = CJ run fast, 1226 = CJ run stamina)
#define AC_CJRUN_ANIM_1           1231
#define AC_CJRUN_ANIM_2           1226

enum e_ACCJRun
{
    acLastPlayerObjectCount,
    acCJRunViolations
};

new AC_CJData[MAX_PLAYERS][e_ACCJRun];

hook OnPlayerConnect(playerid)
{
    AC_CJData[playerid][acLastPlayerObjectCount] = 0;
    AC_CJData[playerid][acCJRunViolations]       = 0;
    return 1;
}

hook OnPlayerUpdate(playerid)
{
    if(!AC_CanPunish(playerid))
        return 1;

    // --- CJ RUN DETECTION ---
    // Animasi CJ run dengan kecepatan abnormal
    if(GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && 
       GetPlayerSpecialAction(playerid) != SPECIAL_ACTION_USEJETPACK)
    {
        new animidx = GetPlayerAnimationIndex(playerid);
        if(animidx == AC_CJRUN_ANIM_1 || animidx == AC_CJRUN_ANIM_2)
        {
            // CJ run speed hack: kecepatan > threshold saat anim CJ run
            new Float:speed = AC_GetSpeed(playerid);
            new Float:speedKmh = speed * 179.28625; // konversi velocity ke km/h

            if(speedKmh > AC_CJRUN_SPEED_THRESHOLD)
            {
                AC_CJData[playerid][acCJRunViolations]++;
                
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
            // Reset jika animasi normal
            if(AC_CJData[playerid][acCJRunViolations] > 0)
                AC_CJData[playerid][acCJRunViolations] = 0;
        }
    }

    // --- OBJECT SPAM / MAPPING STEALER ---
    // open.mp mendukung GetPlayerObjectCount
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
