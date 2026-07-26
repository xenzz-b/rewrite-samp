// ============================================
// NPC AI INTERACTIVE SYSTEM v2.0
// 1 Dynamic Actor - Jalan Bolak-Balik di Bandara
// ============================================
#pragma dynamic 32768   // Tambah stack size
// Definisi Invalid_Node jika belum ada
#define Invalid_Node (Node:-1)
#include <YSI_Coding\y_hooks>
#include <requests>

// ============================================
// KONFIGURASI SERVER
// ============================================

#define SERVER_NAME         "Nexston Roleplay"
#define SERVER_OWNER        "Felix"
#define SERVER_DEVELOPER    "Anonim-X7"
#define SERVER_IC_NAME      "Los Santos"
#define SERVER_IC_DESC      "Kota metropolitan dengan berbagai aktivitas roleplay"
#define AI_NAME             "Nexston Guardian"  // Nama AI
#define AI_CHARACTER        "Petugas bandara yang ramah dan membantu"

// ============================================
// KONFIGURASI
// ============================================

#define MAX_NPC_ACTORS          (1)          // Hanya 1 NPC
#define MAX_MEMORY_MESSAGES     (10)
#define MAX_MESSAGE_LENGTH      (256)
#define NPC_INTERACT_RADIUS     (3.0)
#define NPC_COOLDOWN_TIME       (3000)
#define MOVEMENT_UPDATE_TIME    (1000)
#define WAYPOINT_WAIT_MIN       (2000)
#define WAYPOINT_WAIT_MAX       (5000)

// API Endpoint
#define AI_API_URL "http://217.216.109.45:7010/api/npc/chat"
// Warna
#define COLOR_NPC               0x00FF00FF
#define COLOR_ERROR             0xFF0000FF
#define COLOR_INFO              0xFFFF00FF
#define COLOR_SUCCESS           0x00FF00FF

// ============================================
// ENUM & STRUCTURE
// ============================================

enum e_NPC_DATA {
    STREAMER_TAG_ACTOR:npc_actorId,
    npc_currentWaypoint,
    npc_nextWaypoint,
    npc_waitTimer,
    npc_movementTimer,
    bool:npc_isWalking,
    bool:npc_isInteracting,
    Float:npc_lastX,
    Float:npc_lastY,
    npc_interactingPlayer,
    npc_waypointCount
};

enum e_PLAYER_NPC_DATA {
    bool:player_isTalking,
    player_currentNPC,
    player_cooldownTick,
    player_friendlyLevel,
    player_mood,
    player_memoryCount
};

// ============================================
// VARIABEL GLOBAL
// ============================================

static g_NPCData[MAX_NPC_ACTORS][e_NPC_DATA];
static g_PlayerNPCData[MAX_PLAYERS][e_PLAYER_NPC_DATA];
static g_TotalNPCs = 0;
static Float:g_NPCWaypoints[MAX_NPC_ACTORS][10][3];
static g_PlayerLastMessages[MAX_PLAYERS][MAX_MEMORY_MESSAGES][MAX_MESSAGE_LENGTH];
static g_RequestPlayer[512];
static RequestsClient:g_HTTPClient = RequestsClient:-1;

// ============================================
// WAYPOINTS BANDARA (2 TITIK BOLAK-BALIK)
// Sesuai dengan AddPlayerClass Anda
// ============================================

static const Float:g_AirportWaypoints[2][3] = {
    {1722.0999, -2259.5120, 13.5442},   // Start (spawn pertama)
    {1589.3441, -2260.3784, 13.5420}    // End (spawn kedua)
};

// Skin NPC petugas bandara
static const g_NPCSkins[1] = {200};      // Petugas pria

// Animations
static const g_WalkAnimLib[] = "PED";
static const g_WalkAnimName[] = "WALK_gang";
static const g_IdleAnimLib[] = "PED";
static const g_IdleAnimName[] = "IDLE_chat";

// ============================================
// FUNGSI UTILITY
// ============================================

static stock strtolower(str[]) {
    for(new i = 0; str[i]; i++) {
        if('A' <= str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

static stock Float:DistanceBetweenPoints(Float:x1, Float:y1, Float:x2, Float:y2) {
    return floatsqroot((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

static stock GetPlayerNameEx(playerid) {
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    return name;
}

static stock clamps(value, min, max) {
    if(value < min) return min;
    if(value > max) return max;
    return value;
}

// ============================================
// MOVEMENT SYSTEM (SEDERHANA & SMOOTH)
// ============================================

// Variabel untuk menyimpan arah gerak
static g_NPCDirection[MAX_NPC_ACTORS] = {1}; // 0 = ke kiri/start, 1 = ke kanan/end

static stock StartNPCMovement(npcId) {
    if(npcId >= g_TotalNPCs) return 0;
    if(g_NPCData[npcId][npc_isInteracting]) return 0;
    
    if(g_NPCData[npcId][npc_movementTimer] != -1) {
        KillTimer(g_NPCData[npcId][npc_movementTimer]);
        g_NPCData[npcId][npc_movementTimer] = -1;
    }
    
    // Mulai timer movement
    g_NPCData[npcId][npc_movementTimer] = SetTimerEx("MoveNPCToTarget", MOVEMENT_UPDATE_TIME, true, "i", npcId);
    return 1;
}

forward MoveNPCToTarget(npcId);
public MoveNPCToTarget(npcId) {
    if(npcId >= g_TotalNPCs) return 0;
    if(g_NPCData[npcId][npc_isInteracting]) return 0;
    if(!g_NPCData[npcId][npc_isWalking]) return 0;
    
    new STREAMER_TAG_ACTOR:actorId = g_NPCData[npcId][npc_actorId];
    
    // Tentukan target berdasarkan arah
    new targetWaypoint;
    if(g_NPCDirection[npcId] == 1) {
        targetWaypoint = 1; // Menuju End
    } else {
        targetWaypoint = 0; // Menuju Start
    }
    
    new Float:targetX = g_NPCWaypoints[npcId][targetWaypoint][0];
    new Float:targetY = g_NPCWaypoints[npcId][targetWaypoint][1];
    new Float:targetZ = g_NPCWaypoints[npcId][targetWaypoint][2];
    
    new Float:currentX, Float:currentY, Float:currentZ;
    GetDynamicActorPos(actorId, currentX, currentY, currentZ);
    
    new Float:distance = DistanceBetweenPoints(targetX, targetY, currentX, currentY);
    
    // Jika sudah sampai di target
    if(distance < 1.5) {
        // Set posisi tepat di target
        SetDynamicActorPos(actorId, targetX, targetY, targetZ);
        
        // Stop animasi jalan
        StopDynamicActorAnim(actorId);
        
        // Berhenti sebentar
        g_NPCData[npcId][npc_isWalking] = false;
        
        if(g_NPCData[npcId][npc_waitTimer] != -1) {
            KillTimer(g_NPCData[npcId][npc_waitTimer]);
        }
        
        new waitTime = WAYPOINT_WAIT_MIN + random(WAYPOINT_WAIT_MAX - WAYPOINT_WAIT_MIN);
        g_NPCData[npcId][npc_waitTimer] = SetTimerEx("NPCTurnAround", waitTime, false, "i", npcId);
        
        // Hentikan movement timer sementara
        if(g_NPCData[npcId][npc_movementTimer] != -1) {
            KillTimer(g_NPCData[npcId][npc_movementTimer]);
            g_NPCData[npcId][npc_movementTimer] = -1;
        }
        
        return 1;
    }
    
    // Hitung arah gerak
    new Float:angle = atan2(targetY - currentY, targetX - currentX);
    
    // Gerakan smooth (kecepatan 1.2 per tick)
    new Float:moveX = currentX + (floatcos(angle, degrees) * 1.2);
    new Float:moveY = currentY + (floatsin(angle, degrees) * 1.2);
    
    // SetDynamicActorPos(actorId, moveX, moveY, targetZ);
    SetDynamicActorFacingAngle(actorId, angle);
    ApplyDynamicActorWalkAnim(actorId);
    
    return 1;
}

forward NPCTurnAround(npcId);
public NPCTurnAround(npcId) {
    if(npcId >= g_TotalNPCs) return 0;
    if(g_NPCData[npcId][npc_isInteracting]) return 0;
    
    // Balik arah
    if(g_NPCDirection[npcId] == 1) {
        g_NPCDirection[npcId] = 0; // Balik ke start
    } else {
        g_NPCDirection[npcId] = 1; // Balik ke end
    }
    
    // Update arah hadap NPC sesuai arah baru
    new STREAMER_TAG_ACTOR:actorId = g_NPCData[npcId][npc_actorId];
    new Float:targetX, Float:targetY;
    
    if(g_NPCDirection[npcId] == 1) {
        targetX = g_NPCWaypoints[npcId][1][0];
        targetY = g_NPCWaypoints[npcId][1][1];
    } else {
        targetX = g_NPCWaypoints[npcId][0][0];
        targetY = g_NPCWaypoints[npcId][0][1];
    }
    
    new Float:currentX, Float:currentY, Float:currentZ;
    GetDynamicActorPos(actorId, currentX, currentY, currentZ);
    
    new Float:angle = atan2(targetY - currentY, targetX - currentX);
    SetDynamicActorFacingAngle(actorId, angle);
    
    // Mulai jalan lagi
    g_NPCData[npcId][npc_isWalking] = true;
    g_NPCData[npcId][npc_waitTimer] = -1;
    
    // Restart movement timer
    StartNPCMovement(npcId);
    
    return 1;
}

// ============================================
// FUNGSI ANIMASI DYNAMIC ACTOR
// ============================================

static stock ApplyDynamicActorWalkAnim(actorid) {
    ApplyDynamicActorAnimation(actorid, g_WalkAnimLib, g_WalkAnimName, 4.1, 1, 0, 0, 0, 0);
}

static stock ApplyDynamicActorIdleAnim(actorid) {
    ApplyDynamicActorAnimation(actorid, g_IdleAnimLib, g_IdleAnimName, 4.1, 1, 0, 0, 0, 0);
}

static stock StopDynamicActorAnim(actorid) {
    ClearDynamicActorAnimations(actorid);
}

// ============================================
// INISIALISASI NPC (1 ACTOR BOLAK-BALIK)
// ============================================

static stock InitializeNPCs() {
    for(new i = 0; i < MAX_NPC_ACTORS; i++) {
        // Create Dynamic Actor di titik start
        g_NPCData[i][npc_actorId] = CreateDynamicActor(g_NPCSkins[i % 1], 
            g_AirportWaypoints[0][0], 
            g_AirportWaypoints[0][1], 
            g_AirportWaypoints[0][2], 
            0.0,
            true, 100.0, 0, -1, -1, 300.0);
        
        if(g_NPCData[i][npc_actorId] != INVALID_STREAMER_ID) {
            // Setup waypoints (2 titik: start dan end)
            g_NPCData[i][npc_waypointCount] = 2;
            
            // Waypoint 0: start
            g_NPCWaypoints[i][0][0] = g_AirportWaypoints[0][0];
            g_NPCWaypoints[i][0][1] = g_AirportWaypoints[0][1];
            g_NPCWaypoints[i][0][2] = g_AirportWaypoints[0][2];
            
            // Waypoint 1: end
            g_NPCWaypoints[i][1][0] = g_AirportWaypoints[1][0];
            g_NPCWaypoints[i][1][1] = g_AirportWaypoints[1][1];
            g_NPCWaypoints[i][1][2] = g_AirportWaypoints[1][2];
            
            g_NPCDirection[i] = 1;  // Arah awal: menuju End
            g_NPCData[i][npc_currentWaypoint] = 0;
            g_NPCData[i][npc_nextWaypoint] = 1;    // Mulai jalan ke end
            g_NPCData[i][npc_isWalking] = true;
            g_NPCData[i][npc_isInteracting] = false;
            g_NPCData[i][npc_interactingPlayer] = -1;
            g_NPCData[i][npc_waitTimer] = -1;
            g_NPCData[i][npc_movementTimer] = -1;
            
            SetDynamicActorPos(g_NPCData[i][npc_actorId],
                g_NPCWaypoints[i][0][0],
                g_NPCWaypoints[i][0][1],
                g_NPCWaypoints[i][0][2]);
            
            g_TotalNPCs++;
        }
    }
    
    printf("[NPC AI] Total Dynamic NPC initialized: %d", g_TotalNPCs);
    return 1;
}

// ============================================
// MOVEMENT SYSTEM
// ============================================


forward MoveDynamicNPCToWaypoint(npcId);
public MoveDynamicNPCToWaypoint(npcId) {
    if(npcId >= g_TotalNPCs) return 0;
    if(g_NPCData[npcId][npc_isInteracting]) return 0;
    if(!g_NPCData[npcId][npc_isWalking]) return 0;
    
    new STREAMER_TAG_ACTOR:actorId = g_NPCData[npcId][npc_actorId];
    new targetWaypoint = g_NPCData[npcId][npc_nextWaypoint];
    
    new Float:currentX, Float:currentY, Float:currentZ;
    GetDynamicActorPos(actorId, currentX, currentY, currentZ);
    
    new Float:targetX = g_NPCWaypoints[npcId][targetWaypoint][0];
    new Float:targetY = g_NPCWaypoints[npcId][targetWaypoint][1];
    new Float:targetZ = g_NPCWaypoints[npcId][targetWaypoint][2];
    
    new Float:distance = DistanceBetweenPoints(targetX, targetY, currentX, currentY);
    
    // Jika sudah sampai atau melewati target
    if(distance < 1.0) {
        // Sampai di waypoint
        SetDynamicActorPos(actorId, targetX, targetY, targetZ);
        StopDynamicActorAnim(actorId);
        
        if(g_NPCData[npcId][npc_waitTimer] != -1) {
            KillTimer(g_NPCData[npcId][npc_waitTimer]);
        }
        
        new waitTime = WAYPOINT_WAIT_MIN + random(WAYPOINT_WAIT_MAX - WAYPOINT_WAIT_MIN);
        g_NPCData[npcId][npc_waitTimer] = SetTimerEx("DynamicNPCWaitAtWaypoint", waitTime, false, "i", npcId);
        
        g_NPCData[npcId][npc_currentWaypoint] = targetWaypoint;
        
        // Bolak-balik
        if(targetWaypoint == 1) {
            g_NPCData[npcId][npc_nextWaypoint] = 0;
        } else {
            g_NPCData[npcId][npc_nextWaypoint] = 1;
        }
        
        // Stop movement timer
        if(g_NPCData[npcId][npc_movementTimer] != -1) {
            KillTimer(g_NPCData[npcId][npc_movementTimer]);
            g_NPCData[npcId][npc_movementTimer] = -1;
        }
        
        return 1;
    }
    
    // Hitung arah gerak
    new Float:angle = atan2(targetY - currentY, targetX - currentX);
    
    // Kecepatan gerak (1.5 unit per tick)
    new Float:moveX = currentX + (floatcos(angle, degrees) * 1.5);
    new Float:moveY = currentY + (floatsin(angle, degrees) * 1.5);
    
    // Cek jika gerakan akan melewati target
    new Float:newDistance = DistanceBetweenPoints(targetX, targetY, moveX, moveY);
    if(newDistance > distance) {
        // Jika akan melewati, langsung set ke target
        SetDynamicActorPos(actorId, targetX, targetY, targetZ);
    } else {
        SetDynamicActorPos(actorId, moveX, moveY, targetZ);
    }
    
    SetDynamicActorFacingAngle(actorId, angle);
    ApplyDynamicActorWalkAnim(actorId);
    
    return 1;
}

forward DynamicNPCWaitAtWaypoint(npcId);
public DynamicNPCWaitAtWaypoint(npcId) {
    if(npcId >= g_TotalNPCs) return 0;
    if(g_NPCData[npcId][npc_isInteracting]) return 0;
    
    g_NPCData[npcId][npc_waitTimer] = -1;
    g_NPCData[npcId][npc_isWalking] = true;
    ApplyDynamicActorIdleAnim(g_NPCData[npcId][npc_actorId]);
    
    // Lanjut jalan ke waypoint berikutnya
    StartNPCMovement(npcId);
    
    return 1;
}
// ============================================
// INTERAKSI SYSTEM (SAMA PERSIS DENGAN SCRIPT ANDA)
// ============================================

static stock GetNearestNPC(playerid) {
    new Float:playerX, Float:playerY, Float:playerZ;
    GetPlayerPos(playerid, playerX, playerY, playerZ);
    
    for(new i = 0; i < g_TotalNPCs; i++) {
        new Float:npcX, Float:npcY, Float:npcZ;
        GetDynamicActorPos(g_NPCData[i][npc_actorId], npcX, npcY, npcZ);
        
        new Float:distance = DistanceBetweenPoints(playerX, playerY, npcX, npcY);
        if(distance <= NPC_INTERACT_RADIUS && !g_NPCData[i][npc_isInteracting]) {
            return i;
        }
    }
    return -1;
}

static stock StartInteraction(playerid, npcId) {
    if(npcId == -1) return 0;
    if(g_NPCData[npcId][npc_isInteracting]) return 0;
    
    new STREAMER_TAG_ACTOR:actorId = g_NPCData[npcId][npc_actorId];
    
    // Stop NPC movement
    g_NPCData[npcId][npc_isWalking] = false;
    g_NPCData[npcId][npc_isInteracting] = true;
    g_NPCData[npcId][npc_interactingPlayer] = playerid;
    
    if(g_NPCData[npcId][npc_movementTimer] != -1) {
        KillTimer(g_NPCData[npcId][npc_movementTimer]);
        g_NPCData[npcId][npc_movementTimer] = -1;
    }
    
    if(g_NPCData[npcId][npc_waitTimer] != -1) {
        KillTimer(g_NPCData[npcId][npc_waitTimer]);
        g_NPCData[npcId][npc_waitTimer] = -1;
    }
    
    // Stop animation
    StopDynamicActorAnim(actorId);
    
    // Face player
    new Float:playerX, Float:playerY, Float:playerZ;
    GetPlayerPos(playerid, playerX, playerY, playerZ);
    
    new Float:npcX, Float:npcY, Float:npcZ;
    GetDynamicActorPos(actorId, npcX, npcY, npcZ);
    
    new Float:angle = atan2(playerY - npcY, playerX - npcX);
    SetDynamicActorFacingAngle(actorId, angle);
    
    // Apply idle animation
    ApplyDynamicActorIdleAnim(actorId);
    
    // Set player state
    g_PlayerNPCData[playerid][player_isTalking] = true;
    g_PlayerNPCData[playerid][player_currentNPC] = npcId;
    
    // Perkenalan dengan nama AI
    new greetingMsg[128];
    format(greetingMsg, sizeof(greetingMsg), "Halo, saya %s, petugas bandara. Ada yang bisa saya bantu?", AI_NAME);
    SendNPCMessage(npcId, greetingMsg);
    ShowTDN(playerid, NOTIFICATION_INFO, "Gunakana /npc [text] untuk ngobrol");
    
    return 1;
}
static stock EndInteraction(playerid) {
    if(!g_PlayerNPCData[playerid][player_isTalking]) return 0;
    
    new npcId = g_PlayerNPCData[playerid][player_currentNPC];
    
    if(npcId != -1 && npcId < g_TotalNPCs) {
        // Stop idle animation
        StopDynamicActorAnim(g_NPCData[npcId][npc_actorId]);
        
        g_NPCData[npcId][npc_isInteracting] = false;
        g_NPCData[npcId][npc_interactingPlayer] = -1;
        g_NPCData[npcId][npc_isWalking] = true;
        StartNPCMovement(npcId);
    }
    
    g_PlayerNPCData[playerid][player_isTalking] = false;
    g_PlayerNPCData[playerid][player_currentNPC] = -1;
    g_PlayerNPCData[playerid][player_cooldownTick] = 0;
    
    SendClientMessage(playerid, COLOR_NPC, "NPC: * Petugas melanjutkan tugasnya *");
    
    return 1;
}

// ============================================
// MEMORY SYSTEM (SAMA PERSIS DENGAN SCRIPT ANDA)
// ============================================

static stock AddMemory(playerid, const message[]) {
    new idx = g_PlayerNPCData[playerid][player_memoryCount] % MAX_MEMORY_MESSAGES;
    format(g_PlayerLastMessages[playerid][idx], MAX_MESSAGE_LENGTH, "%s", message);
    g_PlayerNPCData[playerid][player_memoryCount]++;
    
    if(g_PlayerNPCData[playerid][player_memoryCount] > MAX_MEMORY_MESSAGES) {
        g_PlayerNPCData[playerid][player_memoryCount] = MAX_MEMORY_MESSAGES;
    }
}

static stock BuildMemoryContext(playerid, dest[], destSize) {
    dest[0] = '\0';
    
    new startIdx = 0;
    if(g_PlayerNPCData[playerid][player_memoryCount] >= MAX_MEMORY_MESSAGES) {
        startIdx = g_PlayerNPCData[playerid][player_memoryCount] % MAX_MEMORY_MESSAGES;
    }
    
    // Format memory yang lebih jelas
    strcat(dest, "=== PERCAKAPAN SEBELUMNYA ===\n", destSize);
    strcat(dest, "Format: [PEMBICARA]: pesan\n", destSize);
    
    for(new i = 0; i < g_PlayerNPCData[playerid][player_memoryCount]; i++) {
        new idx = (startIdx + i) % MAX_MEMORY_MESSAGES;
        if(strlen(g_PlayerLastMessages[playerid][idx]) > 0) {
            format(dest, destSize, "%s%s\n", dest, g_PlayerLastMessages[playerid][idx]);
        }
    }
    
    strcat(dest, "=== AKHIR PERCAKAPAN ===\n", destSize);
}

// ============================================
// PERSONALITY SYSTEM (SAMA PERSIS DENGAN SCRIPT ANDA)
// ============================================

static stock AnalyzePersonality(playerid, const message[]) {
    new lowerMsg[MAX_MESSAGE_LENGTH];
    strcat(lowerMsg, message);
    strtolower(lowerMsg);
    
    if(strfind(lowerMsg, "anjing") != -1 || strfind(lowerMsg, "bangsat") != -1 || 
       strfind(lowerMsg, "tolol") != -1 || strfind(lowerMsg, "goblok") != -1) {
        g_PlayerNPCData[playerid][player_friendlyLevel] -= 15;
        g_PlayerNPCData[playerid][player_mood] -= 10;
    }
    else if(strfind(lowerMsg, "tolong") != -1 || strfind(lowerMsg, "maaf") != -1 || 
            strfind(lowerMsg, "terima kasih") != -1 || strfind(lowerMsg, "permisi") != -1 ||
            strfind(lowerMsg, "pak") != -1 || strfind(lowerMsg, "bu") != -1) {
        g_PlayerNPCData[playerid][player_friendlyLevel] += 10;
        g_PlayerNPCData[playerid][player_mood] += 5;
    }
    
    g_PlayerNPCData[playerid][player_friendlyLevel] = clamps(g_PlayerNPCData[playerid][player_friendlyLevel], 0, 100);
    g_PlayerNPCData[playerid][player_mood] = clamps(g_PlayerNPCData[playerid][player_mood], 0, 100);
}

static stock GetPersonalityPrompt(playerid, dest[], destSize) {
    new friendlyStr[32], moodStr[32];
    
    if(g_PlayerNPCData[playerid][player_friendlyLevel] >= 70) format(friendlyStr, 32, "sangat ramah");
    else if(g_PlayerNPCData[playerid][player_friendlyLevel] >= 40) format(friendlyStr, 32, "cukup ramah");
    else if(g_PlayerNPCData[playerid][player_friendlyLevel] >= 20) format(friendlyStr, 32, "agak dingin");
    else format(friendlyStr, 32, "sangat dingin");
    
    if(g_PlayerNPCData[playerid][player_mood] >= 70) format(moodStr, 32, "senang");
    else if(g_PlayerNPCData[playerid][player_mood] >= 40) format(moodStr, 32, "biasa saja");
    else if(g_PlayerNPCData[playerid][player_mood] >= 20) format(moodStr, 32, "kesal");
    else format(moodStr, 32, "sangat kesal");
    
    format(dest, destSize, "\
    Anda adalah Nexston Guardian, AI asisten cerdas di Bandara Internasional Los Santos.\n\
    \n\
    === DATA DIRI ===\n\
    - Nama: Nexston Guardian\n\
    - Pekerjaan: Asisten virtual di bandara\n\
    - Pembuat: Tim Developer Nexston Roleplay (Owner: %s, Developer: %s)\n\
    - Server: %s\n\
    - Kota: %s (%s)\n\
    \n\
    === INSTRUKSI PENTING ===\n\
    1. INGAT dan CATAT nama player jika mereka menyebutkannya! Contoh: 'nama saya X' atau 'nama gw X'\n\
    2. GUNAKAN nama player yang sudah disebutkan di percakapan berikutnya.\n\
    3. JIKA player bertanya 'nama saya siapa?', JAWAB dengan nama yang sudah disebutkan sebelumnya.\n\
    4. JIKA player bertanya sesuatu yang sudah pernah ditanyakan, GUNAKAN jawaban dari percakapan sebelumnya.\n\
    5. BERSIKAPLAH KONSISTEN dengan informasi yang sudah diberikan.\n\
    6. Jika player mengucapkan terima kasih, jawab 'sama-sama' atau 'terima kasih kembali'.\n\
    7. Jika player kasar, kurangi keramahan Anda.\n\
    \n\
    === GAYA BICARA ===\n\
    - Karakter: %s\n\
    - Mood: %s\n\
    - Bahasa: Indonesia\n\
    - Panjang: Singkat, padat, maksimal 100 karakter\n\
    \n\
    Ingat! Anda adalah AI yang CERDAS dan INGAT percakapan sebelumnya!",
        SERVER_OWNER, SERVER_DEVELOPER, SERVER_NAME, SERVER_IC_NAME, SERVER_IC_DESC,
        friendlyStr, moodStr);
    
    return 1;
}

// ============================================
// AI COMMUNICATION - SEND TO AI
// ============================================

static stock SendToAI(playerid, const message[]) {
    new currentTick = GetTickCount();
    if(currentTick - g_PlayerNPCData[playerid][player_cooldownTick] < NPC_COOLDOWN_TIME) {
        SendClientMessageEx(playerid, COLOR_ERROR, "NPC: Tunggu sebentar sebelum berbicara lagi.");
        return 0;
    }
    
    g_PlayerNPCData[playerid][player_cooldownTick] = currentTick;
    
    // Ekstrak nama player jika ada
    ExtractPlayerName(playerid, message);
    
    new memoryContext[2048];
    BuildMemoryContext(playerid, memoryContext, sizeof(memoryContext));
    
    new personalityPrompt[1024];
    GetPersonalityPrompt(playerid, personalityPrompt, sizeof(personalityPrompt));
    
    new formattedMsg[MAX_MESSAGE_LENGTH];
    format(formattedMsg, sizeof(formattedMsg), "Player: %s", message);
    AddMemory(playerid, formattedMsg);
    
    AnalyzePersonality(playerid, message);
    
    // Buat JSON object
    new Node:jsonNode = JsonObject(
        "player_text", JsonString(message),
        "memory", JsonString(memoryContext),
        "personality", JsonString(personalityPrompt),
        "friendly_level", JsonInt(g_PlayerNPCData[playerid][player_friendlyLevel]),
        "mood", JsonInt(g_PlayerNPCData[playerid][player_mood]),
        "player_id", JsonInt(playerid)
    );
    
    // Buat client jika belum ada
    if(g_HTTPClient == RequestsClient:-1) {
        g_HTTPClient = RequestsClient("http://127.0.0.1:3000");
        if(g_HTTPClient == RequestsClient:-1) {
            SendClientMessageEx(playerid, COLOR_ERROR, "NPC: Tidak bisa connect ke server.");
            JsonCleanup(jsonNode);
            return 0;
        }
    }
    
    // Kirim request JSON
    new Request:req = RequestJSON(g_HTTPClient, "/api/npc/chat", HTTP_POST, "OnAIResponse", jsonNode);
    g_RequestPlayer[_:req] = playerid;
    
    return 1;
}

#pragma warning disable 213
// ============================================
// AI COMMUNICATION - CALLBACK
// ============================================
// ============================================
// AI COMMUNICATION - CALLBACK
// ============================================
forward OnAIResponse(Request:id, response_code, Node:json);
public OnAIResponse(Request:id, response_code, Node:json) {
    new reqId = _:id;
    
    // Validasi index
    if(reqId < 0 || reqId >= 512) {
        printf("[NPC AI] Invalid request ID: %d", reqId);
        JsonCleanup(json);
        return;
    }
    
    new playerid = g_RequestPlayer[reqId];
    g_RequestPlayer[reqId] = -1;
    
    if(!IsPlayerConnected(playerid)) {
        JsonCleanup(json);
        return;
    }
    if(response_code != 200) {
        printf("[NPC AI] HTTP Error for player %d: %d", playerid, response_code);
        SendClientMessageEx(playerid, COLOR_ERROR, "NPC: AI sedang sibuk.");
        JsonCleanup(json);
        return;
    }
    
    // Perbesar buffer untuk response
    new aiResponse[1024];
    JsonGetString(json, "response", aiResponse, sizeof(aiResponse));
    
    // Bersihkan karakter aneh
    for(new i = 0; aiResponse[i]; i++) {
        if(aiResponse[i] == '\n' || aiResponse[i] == '\r') {
            aiResponse[i] = ' ';
        }
    }
    
    // Hapus spasi berlebih
    new cleanResponse[1024];
    new j = 0;
    new lastWasSpace = false;
    for(new i = 0; aiResponse[i]; i++) {
        if(aiResponse[i] == ' ') {
            if(!lastWasSpace) {
                cleanResponse[j++] = ' ';
                lastWasSpace = true;
            }
        } else {
            cleanResponse[j++] = aiResponse[i];
            lastWasSpace = false;
        }
    }
    cleanResponse[j] = '\0';
    
    // Hapus spasi di awal
    new start = 0;
    while(cleanResponse[start] == ' ') start++;
    
    // Perbesar buffer finalResponse
    new finalResponse[1024];
    strmid(finalResponse, cleanResponse, start, strlen(cleanResponse));
    
    // JANGAN POTONG! Biarkan SendLongMessage yang memecah
    printf("[NPC AI] Response length: %d", strlen(finalResponse));
    printf("[NPC AI] Response: %s", finalResponse);
    
    // Format dan kirim
    new finalMsg[1100];
    format(finalMsg, sizeof(finalMsg), "NPC: %s", finalResponse);
    
    new npcId = g_PlayerNPCData[playerid][player_currentNPC];
    if(npcId != -1) {
        new STREAMER_TAG_ACTOR:actorId = g_NPCData[npcId][npc_actorId];
        new Float:x, Float:y, Float:z;
        GetDynamicActorPos(actorId, x, y, z);
        
        for(new i = 0; i < MAX_PLAYERS; i++) {
            if(IsPlayerConnected(i)) {
                new Float:px, Float:py, Float:pz;
                GetPlayerPos(i, px, py, pz);
                
                if(DistanceBetweenPoints(x, y, px, py) <= 15.0) {
                    SendLongMessage(i, COLOR_NPC, finalMsg);
                }
            }
        }
    } else {
        SendLongMessage(playerid, COLOR_NPC, finalMsg);
    }
    
    // Simpan ke memory (potong jika perlu)
    new formattedResponse[MAX_MESSAGE_LENGTH];
    format(formattedResponse, sizeof(formattedResponse), "NPC: %s", finalResponse);
    AddMemory(playerid, formattedResponse);
    
    JsonCleanup(json);
}

static stock SendNPCMessage(npcId, const message[]) {
    if(npcId == -1 || npcId >= g_TotalNPCs) return 0;
    
    new STREAMER_TAG_ACTOR:actorId = g_NPCData[npcId][npc_actorId];
    new Float:x, Float:y, Float:z;
    GetDynamicActorPos(actorId, x, y, z);
    
    // Format pesan dengan prefix NPC
    new finalMsg[512];
    format(finalMsg, sizeof(finalMsg), "NPC: %s", message);
    
    for(new i = 0; i < MAX_PLAYERS; i++) {
        if(IsPlayerConnected(i)) {
            new Float:px, Float:py, Float:pz;
            GetPlayerPos(i, px, py, pz);
            
            if(DistanceBetweenPoints(x, y, px, py) <= 15.0) {
                // Gunakan fungsi pemecah pesan panjang
                SendLongMessage(i, COLOR_NPC, finalMsg);
            }
        }
    }
    
    return 1;
}

static stock ClearAIHistory(playerid) {
    new Node:jsonNode = JsonObject(
        "player_id", JsonInt(playerid)
    );
    
    new RequestsClient:client = RequestsClient("http://192.168.1.5:3000");
    if(client == RequestsClient:-1) return;
    
    RequestJSON(client, "/api/npc/clear", HTTP_POST, "OnClearResponse", jsonNode);
}

forward OnClearResponse(Request:id, response_code, Node:json);
public OnClearResponse(Request:id, response_code, Node:json) {
    JsonCleanup(json);
}

// ============================================
// YCMD COMMANDS (SAMA PERSIS DENGAN SCRIPT ANDA)
// ============================================

YCMD:leavenpc(playerid, params[], help) {
    #pragma unused params, help
    
    if(!g_PlayerNPCData[playerid][player_isTalking]) {
        SendClientMessage(playerid, COLOR_ERROR, "Anda sedang tidak berbicara dengan NPC.");
        return 1;
    }
    
    EndInteraction(playerid);
    return 1;
}

YCMD:npcinfo(playerid, params[], help) {
    #pragma unused params, help
    
    new message[512];
    format(message, sizeof(message), "=== NPC AI System Info ===\n");
    format(message, sizeof(message), "%sTotal NPC aktif: %d\n", message, g_TotalNPCs);
    
    if(g_PlayerNPCData[playerid][player_isTalking]) {
        new npcId = g_PlayerNPCData[playerid][player_currentNPC];
        format(message, sizeof(message), "%s\n--- Status Percakapan ---\n", message);
        format(message, sizeof(message), "%sSedang berbicara dengan NPC ID: %d\n", message, npcId);
        format(message, sizeof(message), "%sFriendly Level: %d/100\n", message, g_PlayerNPCData[playerid][player_friendlyLevel]);
        format(message, sizeof(message), "%sMood: %d/100\n", message, g_PlayerNPCData[playerid][player_mood]);
        format(message, sizeof(message), "%sMemory tersimpan: %d/%d pesan", message, g_PlayerNPCData[playerid][player_memoryCount], MAX_MEMORY_MESSAGES);
    } else {
        format(message, sizeof(message), "%s\nTidak sedang berbicara dengan NPC.\nTekan Y di dekat NPC untuk mulai berbicara.", message);
    }
    
    SendClientMessage(playerid, COLOR_INFO, message);
    return 1;
}

YCMD:resetnpc(playerid, params[], help) {
    #pragma unused help
    
    if(!IsPlayerAdmin(playerid)) {
        SendClientMessage(playerid, COLOR_ERROR, "Hanya admin RCON yang dapat menggunakan command ini.");
        return 1;
    }
    
    new targetid;
    if(sscanf(params, "u", targetid)) {
        SendClientMessage(playerid, COLOR_INFO, "Usage: /resetnpc [playerid]");
        return 1;
    }
    
    if(!IsPlayerConnected(targetid)) {
        SendClientMessage(playerid, COLOR_ERROR, "Player tidak ditemukan.");
        return 1;
    }
    
    g_PlayerNPCData[targetid][player_friendlyLevel] = 50;
    g_PlayerNPCData[targetid][player_mood] = 50;
    g_PlayerNPCData[targetid][player_memoryCount] = 0;
    
    for(new i = 0; i < MAX_MEMORY_MESSAGES; i++) {
        g_PlayerLastMessages[targetid][i][0] = '\0';
    }
    
    new message[128];
    format(message, sizeof(message), "NPC memory dan personality player %s telah direset.", GetPlayerNameEx(targetid));
    SendClientMessage(playerid, COLOR_SUCCESS, message);
    
    return 1;
}

YCMD:npclist(playerid, params[], help) {
    #pragma unused params, help
    
    if(!IsPlayerAdmin(playerid)) {
        SendClientMessage(playerid, COLOR_ERROR, "Hanya admin yang dapat menggunakan command ini.");
        return 1;
    }
    
    SendClientMessage(playerid, COLOR_INFO, "=== Daftar NPC Bandara ===");
    
    for(new i = 0; i < g_TotalNPCs; i++) {
        new Float:x, Float:y, Float:z;
        GetDynamicActorPos(g_NPCData[i][npc_actorId], x, y, z);
        
        new status[32];
        if(g_NPCData[i][npc_isInteracting]) {
            format(status, 32, "Interaksi dgn player %d", g_NPCData[i][npc_interactingPlayer]);
        } else if(g_NPCData[i][npc_isWalking]) {
            format(status, 32, "Jalan ke WP %d", g_NPCData[i][npc_nextWaypoint]);
        } else {
            status = "Berhenti";
        }
        
        new message[128];
        format(message, sizeof(message), "NPC %d | Pos: %.0f, %.0f | Status: %s", i, x, y, status);
        SendClientMessage(playerid, COLOR_INFO, message);
    }
    
    return 1;
}

YCMD:aboutnpc(playerid, params[], help) {
    #pragma unused params, help
    
    new message[256];
    format(message, sizeof(message), "Saya adalah %s, asisten virtual di Bandara Internasional Los Santos. Saya didukung oleh teknologi AI Google Gemini dan dikembangkan untuk server %s.", AI_NAME, SERVER_NAME);
    SendClientMessage(playerid, COLOR_INFO, message);
    return 1;
}
// ============================================
// AUTO EXIT CHECK (SAMA PERSIS DENGAN SCRIPT ANDA)
// ============================================

forward CheckPlayerDistance();
public CheckPlayerDistance() {
    for(new i = 0; i < MAX_PLAYERS; i++) {
        if(IsPlayerConnected(i) && g_PlayerNPCData[i][player_isTalking]) {
            new npcId = g_PlayerNPCData[i][player_currentNPC];
            if(npcId != -1) {
                new Float:playerX, Float:playerY, Float:playerZ;
                new Float:npcX, Float:npcY, Float:npcZ;
                
                GetPlayerPos(i, playerX, playerY, playerZ);
                GetDynamicActorPos(g_NPCData[npcId][npc_actorId], npcX, npcY, npcZ);
                
                if(DistanceBetweenPoints(playerX, playerY, npcX, npcY) > 5.0) {
                    EndInteraction(i);
                    SendClientMessage(i, COLOR_INFO, "Anda menjauh dari NPC, percakapan berakhir.");
                }
            }
        }
    }
    return 1;
}

// ============================================
// YSI HOOKS (SAMA PERSIS DENGAN SCRIPT ANDA)
// ============================================

hook OnGameModeExit() {
    // Stop semua timer
    for(new i = 0; i < g_TotalNPCs; i++) {
        if(g_NPCData[i][npc_movementTimer] != -1) {
            KillTimer(g_NPCData[i][npc_movementTimer]);
        }
        if(g_NPCData[i][npc_waitTimer] != -1) {
            KillTimer(g_NPCData[i][npc_waitTimer]);
        }
    }
    return 1;
}

hook OnGameModeInit() {
    print("[NPC AI] Initializing NPC AI System with Dynamic Actor...");
    
    for(new i = 0; i < MAX_PLAYERS; i++) {
        g_PlayerNPCData[i][player_isTalking] = false;
        g_PlayerNPCData[i][player_currentNPC] = -1;
        g_PlayerNPCData[i][player_cooldownTick] = 0;
        g_PlayerNPCData[i][player_friendlyLevel] = 50;
        g_PlayerNPCData[i][player_mood] = 50;
        g_PlayerNPCData[i][player_memoryCount] = 0;
        
        for(new j = 0; j < MAX_MEMORY_MESSAGES; j++) {
            g_PlayerLastMessages[i][j][0] = '\0';
        }
    }
    for(new i = 0; i < 512; i++) {
        g_RequestPlayer[i] = -1;
    }
    
    g_HTTPClient = RequestsClient("http://127.0.0.1:3000");
    if(g_HTTPClient == RequestsClient:-1) {
        print("[NPC AI] ERROR: Failed to create HTTP client!");
    } else {
        print("[NPC AI] HTTP Client created successfully!");
    }

    InitializeNPCs();
    
    for(new i = 0; i < g_TotalNPCs; i++) {
        StartNPCMovement(i);
    }
    
    SetTimer("CheckPlayerDistance", 2000, true);
    
    print("[NPC AI] System initialized!");
    printf("[NPC AI] Total NPCs: %d | API: %s", g_TotalNPCs, AI_API_URL);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if(newkeys & KEY_YES) {
        if(g_PlayerNPCData[playerid][player_isTalking]) return 1;
        
        new nearestNPC = GetNearestNPC(playerid);
        if(nearestNPC != -1) {
            StartInteraction(playerid, nearestNPC);
        }
    }
    return 1;
}

hook OnPlayerText(playerid, text[]) {
    // Jika sedang interaksi dengan NPC, arahkan ke /npc command
    if(g_PlayerNPCData[playerid][player_isTalking]) {
        // Kirim pesan via command /npc
        CallRemoteFunction("npc", "is", playerid, text);
        return 0; // Jangan tampilkan chat biasa
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason) {
    #pragma unused reason
    
    if(g_PlayerNPCData[playerid][player_isTalking]) {
        EndInteraction(playerid);
    }
    
    g_PlayerNPCData[playerid][player_isTalking] = false;
    g_PlayerNPCData[playerid][player_currentNPC] = -1;
    g_PlayerNPCData[playerid][player_cooldownTick] = 0;
    g_PlayerNPCData[playerid][player_friendlyLevel] = 50;
    g_PlayerNPCData[playerid][player_mood] = 50;
    g_PlayerNPCData[playerid][player_memoryCount] = 0;
    
    for(new i = 0; i < MAX_MEMORY_MESSAGES; i++) {
        g_PlayerLastMessages[playerid][i][0] = '\0';
    }
    ClearAIHistory(playerid);
    
    return 1;
}

// ============================================
// COMMAND /npc - Chat dengan NPC
// ============================================

YCMD:npc(playerid, params[], help) {
    #pragma unused help
    
    // Cek apakah sedang dalam mode interaksi
    if(!g_PlayerNPCData[playerid][player_isTalking]) {
        SendClientMessage(playerid, COLOR_ERROR, "Anda sedang tidak berbicara dengan NPC. Tekan Y untuk memulai interaksi.");
        return 1;
    }
    
    // Cek apakah params kosong
    if(isnull(params)) {
        SendClientMessage(playerid, COLOR_INFO, "Usage: /npc [pesan]");
        return 1;
    }
    
    // Kirim pesan ke AI
    SendToAI(playerid, params);
    SendClientMessageEx(playerid, -1, params);
    
    return 1;
}

// ============================================
// FUNGSI SEND LONG MESSAGE
// ============================================

// ============================================
// FUNGSI SEND LONG MESSAGE (144 KARAKTER MAX)
// ============================================

static stock SendLongMessage(playerid, color, const message[]) {
    new len = strlen(message);
    if(len == 0) return;
    
    // Batas SA-MP = 144 karakter
    new maxLine = 144;
    new pos = 0;
    new line[145];
    
    while(pos < len) {
        new remaining = len - pos;
        new chunk = (remaining > maxLine) ? maxLine : remaining;
        
        // Cari spasi terakhir biar rapi
        if(chunk == maxLine && remaining > maxLine) {
            new lastSpace = -1;
            for(new i = pos + chunk; i > pos; i--) {
                if(message[i] == ' ') {
                    lastSpace = i;
                    break;
                }
            }
            if(lastSpace != -1) {
                chunk = lastSpace - pos;
            }
        }
        
        strmid(line, message, pos, pos + chunk);
        line[chunk] = '\0';
        
        SendClientMessageEx(playerid, color, line);
        
        pos += chunk;
        while(pos < len && message[pos] == ' ') pos++;
    }
}

static stock ExtractPlayerName(playerid, const message[]) {
    new lowerMsg[MAX_MESSAGE_LENGTH];
    strcat(lowerMsg, message);
    strtolower(lowerMsg);
    
    // Cek pola nama
    new namePos = -1;
    new patterns[][] = {
        "nama saya ", "nama gw ", "nama aku ", "namaku ", 
        "panggil saya ", "panggil gw ", "panggil aku ",
        "saya ", "gw ", "aku "
    };
    
    for(new p = 0; p < sizeof(patterns); p++) {
        namePos = strfind(lowerMsg, patterns[p]);
        if(namePos != -1) {
            namePos += strlen(patterns[p]);
            break;
        }
    }
    
    if(namePos != -1) {
        new endPos = namePos;
        while(lowerMsg[endPos] != ' ' && lowerMsg[endPos] != '\0' && lowerMsg[endPos] != '?' && lowerMsg[endPos] != '.' && lowerMsg[endPos] != '!') {
            endPos++;
        }
        
        if(endPos > namePos) {
            new playerName[MAX_PLAYER_NAME];
            strmid(playerName, message, namePos, endPos);
            
            // Simpan nama player
            format(g_PlayerLastMessages[playerid][0], MAX_MESSAGE_LENGTH, "[SISTEM] Nama player adalah %s", playerName);
            
            // Tambahkan ke memory
            new nameMemory[MAX_MESSAGE_LENGTH];
            format(nameMemory, sizeof(nameMemory), "Sistem: Nama player adalah %s", playerName);
            AddMemory(playerid, nameMemory);
            
            return 1;
        }
    }
    return 0;
}