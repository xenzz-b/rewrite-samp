// Constants - UBAH KE HARI (PRODUCTION)
#define MAX_COUPLE_REWARDS      10
#define COUPLE_BREAKUP_COOLDOWN 604800  // 7 hari dalam detik
#define COUPLE_REWARD_CHECK      3600   // 1 jam dalam detik (kembali ke 1 jam)

// Milestone rewards (dalam HARI - PRODUCTION)
#define MILESTONE_30_DAYS        30
#define MILESTONE_60_DAYS        60
#define MILESTONE_90_DAYS        90

// Reward types
#define REWARD_TYPE_VIP          "vip"
#define REWARD_TYPE_VEHICLE      "vehicle"

// COUPLE ENUM - All couple data in one enum with cData tag
enum cData {
    // Couple status
    cID,                    // ID di tabel couple
    cPartnerID,             // PlayerID partner (pID)
    cPartnerName[MAX_PLAYER_NAME], // Nama partner untuk offline reference
    cStartDate,             // Unix timestamp start (first time)
    cTotalDuration,         // Total akumulasi waktu dalam detik (hanya saat bersama)
    cLastUpdate,            // Terakhir kali update durasi
    cBreakupCooldown,       // Unix timestamp cooldown
    cLastRewardCheck,       // Unix timestamp last reward check
    cActive,                // 1 = active, 0 = inactive
    cCoupleDays,            // Total days together (cached)
    
    // Milestone flags (0 = belum, 1 = sudah)
    cReward30,              // 30 days reward claimed
    cReward60,              // 60 days reward claimed
    cReward90,              // 90 days reward claimed
    cRewardVehicle,         // Vehicle reward claimed
    
    // Proposal system
    cProposeFrom,           // PlayerID yang melamar
    cProposeTime,           // Waktu proposal dikirim
    
    // Dialog state
    cDialogTick             // Untuk async dialog refresh
}

// Milestone config - tetap sama, hanya untuk referensi
enum E_MILESTONE_CONFIG {
    milestone_days,
    milestone_rewardType[20],
    milestone_rewardValue[50],
    milestone_rewardDesc[100]
}

// new const gMilestoneConfig[][E_MILESTONE_CONFIG] = {
//     {MILESTONE_30_DAYS, REWARD_TYPE_VIP, "7",    "VIP Level 1 - 7 Hari"},
//     {MILESTONE_60_DAYS, REWARD_TYPE_VIP, "14",   "VIP Level 1 - 14 Hari"},
//     {MILESTONE_90_DAYS, REWARD_TYPE_VIP, "30",   "VIP Level 1 - 30 Hari"},
//     {MILESTONE_90_DAYS, REWARD_TYPE_VEHICLE, "541", "Kendaraan Bullet"},
// };

// Global couple data array dengan tag cData
new CoupleData[MAX_PLAYERS][cData];

// Forward declarations
forward OnCoupleDataLoaded(playerid);
forward OnCouplePendingRewards(playerid);
forward OnCoupleProposeResponse(playerid, response, targetid);
forward OnCoupleBreakupConfirm(playerid, response);
forward OnCoupleRewardHistory(playerid, tick);

// Global iterators
new Iterator:CoupleOnline<MAX_PLAYERS>;