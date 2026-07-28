#define MAX_VEHICLE_MODELS							212
#define INVALID_SEAT_ID 						-1

#define IsValidVehicleModelID(%0)				(400 <= (%0) <= 611)

new bool:VehicleHealthSecurity[MAX_VEHICLES] = false, Float:VehicleHealthSecurityData[MAX_VEHICLES] = 1000.0;

new const g_arrVehicleNames[][] =
{
	"Landstalker", "Bravura", "Buffalo", "Linerunner", "Pereniel", "Sentinel", "Dumper", "Firetruck", "Trashmaster", 
	"Stretch", "Manana", "Infernus", "Voodoo", "Pony", "Mule", "Cheetah", "Ambulance", "Leviathan", "Moonbeam", 
	"Esperanto", "Taxi", "Washington", "Bobcat", "Mr Whoopee", "BF Injection", "Hunter", "Premier", "Enforcer", 
	"Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks", "Hotknife", "Trailer", "Previon", "Coach", 
	"Cabbie", "Stallion", "Rumpo", "RC Bandit", "Romero", "Packer", "Monster", "Admiral", "Squalo", "Seasparrow",
	"Pizzaboy", "Tram", "Trailer", "Turismo", "Speeder", "Reefer", "Tropic", "Flatbed", "Yankee", "Caddy", "Solair", 
	"Berkley's RC Van", "Skimmer", "PCJ-600", "Faggio", "Freeway", "RC Baron", "RC Raider", "Glendale", "Oceanic", 
	"Sanchez", "Sparrow", "Patriot", "Quad", "Coastguard", "Dinghy", "Hermes", "Sabre", "Rustler", "ZR-350", "Walton", 
	"Regina", "Comet", "BMX", "Burrito", "Camper", "Marquis", "Baggage", "Dozer", "Maverick", "News Chopper", "Rancher", 
	"FBI Rancher", "Virgo", "Greenwood", "Jetmax", "Hotring", "Sandking", "Blista", "Police Maverick", 
	"Boxville", "Benson", "Mesa", "RC Goblin", "Hotring-Racer", "Hotring-Racer", "Bloodring-Banger", "Rancher", 
	"Super-GT", "Elegant", "Journey", "Bike", "Mountain Bike", "Beagle", "Cropdust", "Stunt", "Tanker", "RoadTrain", 
	"Nebula", "Majestic", "Buccaneer", "Shamal", "Hydra", "FCR-900", "NRG-500", "HPV1000", "Cement Truck", "Tow Truck", 
	"Fortune", "Cadrona", "FBI Truck", "Willard", "Forklift", "Tractor", "Combine", "Feltzer", "Remington", "Slamvan", 
	"Blade", "Freight", "Streak", "Vortex", "Vincent", "Bullet", "Clover", "Sadler", "Firetruck", "Hustler", "Intruder", 
	"Primo", "Cargobob", "Tampa", "Sunrise", "Merit", "Utility", "Nevada", "Yosemite", "Windsor", "Monster Truck A", "Monster Truck B", 
	"Uranus", "Jester", "Sultan", "Stratum", "Elegy", "Raindance", "RC Tiger", "Flash", "Tahoma", "Savanna", "Bandito", 
	"Freight", "Trailer", "Kart", "Mower", "Duneride", "Sweeper", "Broadway", "Tornado", "AT-400", "DFT-30", 
	"Huntley", "Stafford", "BF-400", "Newsvan", "Tug", "Trailer", "Emperor", "Wayfarer", "Euros", "Hotdog", "Club", 
	"Trailer", "Trailer", "Andromada", "Dodo", "RC Cam", "Launch", "LSPD Car", "SFPD Car", "LVPD Car", 
	"Police Ranger", "Picador", "S.W.A.T. Van", "Alpha", "Phoenix", "Glendale", "Sadler", "Luggage Trailer", "Luggage Trailer", "Stair Trailer", 
	"Boxville", "Farm Plow", "Utility Trailer"
};

enum NeonOffset {
	Float:NeonX,
	Float:NeonY,
	Float:NeonZ
};

#define MAX_PRIVATE_VEHICLE 1800
#define MAX_PLAYER_VEHICLE 4
#define MAX_FUEL_FULL 1000

#define MAX_BAGASI_ITEMS 100

#define MAX_VEHICLE_NEON_SLOT						3
#define RED_NEON									18647
#define BLUE_NEON									18648
#define GREEN_NEON									18649
#define YELLOW_NEON									18650
#define PINK_NEON 									18651
#define WHITE_NEON									18652

enum e_VehCore
{
	Float:vCoreHealth,
	vCoreFuel,
	bool:vCoreLocked,
	vCoreDamage[4],
	Float:vSpeedLimit,
	bool:vUsedSL,
	vWorld,
	vInterior,
	bool:vIsBlink,
	bool:vIsDeath,
	vBlink,
	bool:vIsBodyUpgraded,
	bool:vIsBodyBroken,
	Float:vMaxHealth,

	bool:vIsRemoted,
	vRemotedType,
	vRemotedCount,

	STREAMER_TAG_OBJECT:pizzaBox[10]
};
new VehicleCore[MAX_VEHICLES][e_VehCore];

enum e_VehDetails
{
	pVehID, //id database
	pVehOwnerID, //id pemilik sesuai pID
	pVehModelID, //model id kendaraan
	pVehPrice, //harga kendaraan ketika pembelian
	pVehParked, //id garkot tempat kendaraan di simpan
	pVehFamGarage, //id garasi family
	pVehHouseGarage, //id garasi rumah
	pVehRentTime,
	pVehRental,
	pVehPlate[64],
	pVehPlateTime,
	Float:pVehHealth,
	bool:pVehLocked,
	pVehFuel,
	pVehMod[17],
	pVehDamage[4],
	Float:pVehPos[4],
	pVehNeon,
	pVehPaintjob,
	pVehColor1,
	pVehColor2,
	pVehWorld,
	pVehInterior,
	bool:pVehImpounded,
	pVehImpoundDuration,
	pVehImpoundFee,
	pVehImpoundReason[128],
	bool:pVehInsuranced,
	bool:pVehTireLocked,
	bool:pVehBodyUpgraded,
	bool:pVehBodyBroken,
	Float:pVehMaxHealth,
	pVehJDMGarage,
	
	//not save
	STREAMER_TAG_3D_TEXT_LABEL:pVehTireLockLabel,
	pVehToySelected,
	bool:pVehHandbraked,
	pVehPhysic
};
new PlayerVehicle[MAX_PRIVATE_VEHICLE][e_VehDetails],
	Iterator:PvtVehicles<MAX_PRIVATE_VEHICLE + 1>;

enum e_vehiclebagasi
{
    vehicleBagasiID,
	vehicleBagasiVDBID,
    vehicleBagasiTemp[32],
    vehicleBagasiModel,
    vehicleBagasiQuant,

	//not save
	bool:vehicleBagasiExists
};
new VehicleBagasi[MAX_PRIVATE_VEHICLE][MAX_BAGASI_ITEMS][e_vehiclebagasi];

enum e_VehicleHolster
{
	vHolsterID,
	bool:vHolsterTaken,
	vHolsterWeaponID,
	vHolsterWeaponAmmo
};
new VehicleHolster[MAX_PRIVATE_VEHICLE][e_VehicleHolster][3];

new vehicleFlashTimer[MAX_PRIVATE_VEHICLE] = {-1, ...};
new vehicleFlashCount[MAX_PRIVATE_VEHICLE] = {0, ...}; 

// Di bagian enum, tambahkan ini
enum e_VehicleKeys
{
    vKeyID,                 // ID database
    vKeyVehicleDBID,        // ID kendaraan (dari player_vehicles)
    vKeyOwnerID,            // ID pemilik asli (pID)
    vKeyHolderID,           // ID pemegang kunci (pID)
    vKeyHolderName[32],     // Nama pemegang kunci
    vKeyExpireTime,         // Waktu expired (0 = permanent)
    vKeyGivenTime           // Waktu pemberian
}

// Variabel untuk menyimpan kunci
new VehicleKeys[MAX_PLAYERS][20][e_VehicleKeys]; // Maksimal 20 kunci per player
new Iterator:VehicleKeyIndex[MAX_PLAYERS] <20>;

/*
new CoreVehicleData[212][E_VEHICLE_CORE_DATA] =
{
	//Windows  	Seats 	Fuel Type   	Trunk Limit (kg)
	{true,		4,		FUEL_DIESEL,	80}, //Landstalker
	{true,		2,		FUEL_PETROL,	35}, //Bravura
	{true,		2,		FUEL_PETROL,	35}, //Buffalo
	{true,		2,		FUEL_DIESEL,	0}, //Linerunner
	{true,		4,		FUEL_PETROL,	70}, //Perenial
	{true,		4,		FUEL_PETROL,	75}, //Sentinel
	{true,		1,		FUEL_DIESEL,	500}, //Dumper
	{true,		2,		FUEL_DIESEL,	35}, //Firetruck
	{true,		2,		FUEL_DIESEL,	35}, //Trashmaster
	{true,		4,		FUEL_PETROL,	35}, //Stretch
	{true,		2,		FUEL_PETROL,	40}, //Manana
	{true,		2,		FUEL_PETROL,	15}, //Infernus
	{true,		2,		FUEL_PETROL,	40}, //Voodoo
	{true,		4,		FUEL_DIESEL,	100}, //Pony
	{true,		2,		FUEL_DIESEL,	225}, //Mule
	{true,		2,		FUEL_PETROL,	15}, //Cheetah
	{true,		4,		FUEL_DIESEL,	40}, //Ambulance
	{true,		2,		FUEL_PETROL,	220}, //Leviathan
	{true,		4,		FUEL_PETROL,	70}, //Moonbeam
	{true,		2,		FUEL_PETROL,	35}, //Esperanto
	{true,		4,		FUEL_PETROL,	35}, //Taxi
	{true,		4,		FUEL_PETROL,	40}, //Washington
	{true,		2,		FUEL_DIESEL,	200}, //Bobcat
	{true,		2,		FUEL_DIESEL,	35}, //Mr Whoopee
	{false,		2,		FUEL_DIESEL,	0}, //BF Injection
	{true,		1,		FUEL_PETROL,	40}, //Hunter
	{true,		4,		FUEL_PETROL,	40}, //Premier
	{true,		4,		FUEL_DIESEL,	150}, //Enforcer
	{true,		4,		FUEL_DIESEL,	150}, //Securicar
	{true,		2,		FUEL_PETROL,	35}, //Banshee
	{false,		1,		FUEL_PETROL,	15}, //Predator
	{false,		8,		FUEL_DIESEL,	10}, //Bus
	{false,		1,		FUEL_DIESEL,	0}, //Rhino
	{true,		2,		FUEL_DIESEL,	250}, //Barracks
	{true,		2,		FUEL_PETROL,	35}, //Hotknife
	{false,		1,		FUEL_NONE,		300}, //Artic Trailer 1
	{true,		2,		FUEL_PETROL,	35}, //Previon
	{false,		8,		FUEL_DIESEL,	10}, //Coach
	{true,		4,		FUEL_PETROL,	35}, //Cabbie
	{true,		2,		FUEL_PETROL,	35}, //Stallion
	{true,		4,		FUEL_DIESEL,	70}, //Rumpo
	{false,		1,		FUEL_PETROL,	0}, //RC Bandit
	{true,		2,		FUEL_PETROL,	35}, //Romero
	{true,		2,		FUEL_DIESEL,	0}, //Packer
	{true,		2,		FUEL_DIESEL,	60}, //Monster
	{true,		4,		FUEL_PETROL,	40}, //Admiral
	{false,		1,		FUEL_PETROL,	25}, //Squallo
	{true,		2,		FUEL_PETROL,	10}, //Seasparrow
	{false,		1,		FUEL_PETROL,	5}, //Pizzaboy
	{false,		1,		FUEL_PETROL,	0}, //Tram
	{false,		1,		FUEL_NONE,		500}, //Artic Trailer 2
	{true,		2,		FUEL_PETROL,	15}, //Turismo
	{false,		1,		FUEL_PETROL,	15}, //Speeder
	{false,		1,		FUEL_PETROL,	30}, //Reefer
	{false,		1,		FUEL_PETROL,	15}, //Tropic
	{true,		2,		FUEL_DIESEL,	300}, //Flatbed
	{true,		2,		FUEL_DIESEL,	250}, //Yankee
	{false,		2,		FUEL_PETROL,	0}, //Caddy
	{true,		4,		FUEL_PETROL,	35}, //Solair
	{true,		4,		FUEL_DIESEL,	0}, //Berkley's RC Van
	{true,		2,		FUEL_PETROL,	0}, //Skimmer
	{false,		1,		FUEL_PETROL,	0}, //PCJ-600
	{false,		1,		FUEL_PETROL,	0}, //Faggio
	{false,		1,		FUEL_PETROL,	0}, //Freeway
	{false,		1,		FUEL_PETROL,	0}, //RC Baron
	{false,		1,		FUEL_PETROL,	0}, //RC Raider
	{true,		4,		FUEL_PETROL,	40}, //Glendale
	{true,		4,		FUEL_PETROL,	40}, //Oceanic
	{false,		1,		FUEL_PETROL,	0}, //Sanchez
	{true,		2,		FUEL_PETROL,	0}, //Sparrow
	{true,		4,		FUEL_DIESEL,	40}, //Patriot
	{false,		2,		FUEL_PETROL,	0}, //Quad
	{false,		1,		FUEL_PETROL,	10}, //Coastguard
	{false,		1,		FUEL_PETROL,	0}, //Dinghy
	{true,		2,		FUEL_PETROL,	40}, //Hermes
	{true,		2,		FUEL_PETROL,	40}, //Sabre
	{false,		1,		FUEL_PETROL,	0}, //Rustler
	{true,		2,		FUEL_PETROL,	35}, //ZR-350
	{true,		2,		FUEL_DIESEL,	150}, //Walton
	{true,		4,		FUEL_DIESEL,	40}, //Regina
	{true,		2,		FUEL_PETROL,	35}, //Comet
	{false,		1,		FUEL_NONE,		0}, //BMX
	{true,		4,		FUEL_DIESEL,	100}, //Burrito
	{true,		3,		FUEL_DIESEL,	40}, //Camper
	{false,		1,		FUEL_PETROL,	0}, //Marquis
	{false,		1,		FUEL_PETROL,	0}, //Baggage
	{false,		1,		FUEL_DIESEL,	0}, //Dozer
	{true,		4,		FUEL_PETROL,	10}, //Maverick
	{true,		2,		FUEL_PETROL,	10}, //SAN News Maverick
	{true,		2,		FUEL_DIESEL,	60}, //Rancher
	{true,		4,		FUEL_DIESEL,	60}, //FBI Rancher
	
	//lanjut
	{true,		2,		FUEL_PETROL,	3}, //Virgo
	{true,		4,		FUEL_PETROL,	3}, //Greenwood
	{false,		1,		FUEL_PETROL,	0}, //Jetmax
	{false,		2,		FUEL_PETROL,	2}, //Hotring Racer
	{true,		2,		FUEL_DIESEL,	4}, //Sandking
	{true,		2,		FUEL_PETROL,	3}, //Blista Compact
	{true,		4,		FUEL_PETROL,	5}, //Police Maverick
	{true,		4,		FUEL_DIESEL,	8}, //Boxville
	{true,		2,		FUEL_DIESEL,	8}, //Benson
	{true,		2,		FUEL_DIESEL,	2}, //Mesa
	{false,		1,		FUEL_PETROL,	0}, //RC Goblin
	{false,		2,		FUEL_PETROL,	2}, //Hotring Racer
	{false,		2,		FUEL_PETROL,	2}, //Hotring Racer
	{false,		2,		FUEL_PETROL,	3}, //Bloodring Banger
	{true,		2,		FUEL_DIESEL,	4}, //Rancher
	{true,		2,		FUEL_PETROL,	2}, //Super GT
	{true,		4,		FUEL_PETROL,	4}, //Elegant
	{true,		2,		FUEL_DIESEL,	10}, //Journey
	{false,		1,		FUEL_NONE,		0}, //Bike
	{false,		1,		FUEL_NONE,		0}, //Mountain Bike
	{true,		2,		FUEL_PETROL,	0}, //Beagle
	{true,		1,		FUEL_PETROL,	0}, //Cropduster
	{true,		1,		FUEL_PETROL,	0}, //Stuntplane
	{true,		2,		FUEL_DIESEL,	0}, //Tanker
	{true,		2,		FUEL_DIESEL,	0}, //Roadtrain
	{true,		4,		FUEL_PETROL,	3}, //Nebula
	{true,		2,		FUEL_PETROL,	3}, //Majestic
	{true,		2,		FUEL_PETROL,	3}, //Buccaneer
	{false,		1,		FUEL_PETROL,	0}, //Shamal
	{false,		1,		FUEL_PETROL,	0}, //Hydra
	{false,		2,		FUEL_PETROL,	1}, //FCR-900
	{false,		2,		FUEL_PETROL,	1}, //NRG-500
	{false,		2,		FUEL_PETROL,	1}, //Cop Bike HPV1000
	{true,		2,		FUEL_DIESEL,	0}, //Cement Truck
	{true,		2,		FUEL_DIESEL,	0}, //Towtruck
	{true,		2,		FUEL_PETROL,	2}, //Fortune
	{true,		2,		FUEL_PETROL,	2}, //Cadrona
	{true,		2,		FUEL_DIESEL,	6}, //FBI Truck
	{true,		4,		FUEL_PETROL,	3}, //Willard
	{false,		1,		FUEL_DIESEL,	0}, //Forklift
	{false,		1,		FUEL_DIESEL,	0}, //Tractor
	{true,		1,		FUEL_DIESEL,	0}, //Combine Harvester
	{true,		2,		FUEL_PETROL,	3}, //Feltzer
	{true,		2,		FUEL_PETROL,	4}, //Remington
	{true,		2,		FUEL_DIESEL,	4}, //Slamvan
	{true,		2,		FUEL_PETROL,	3}, //Blade
	{false,		1,		FUEL_DIESEL,	0}, //Freight (Train)
	{false,		1,		FUEL_DIESEL,	0}, //Brownstreak (Train)
	{false,		1,		FUEL_PETROL,	0}, //Vortex
	{true,		4,		FUEL_PETROL,	3}, //Vincent
	{true,		2,		FUEL_PETROL,	2}, //Bullet
	{true,		2,		FUEL_PETROL,	3}, //Clover
	{true,		2,		FUEL_DIESEL,	5}, //Sadler
	{true,		2,		FUEL_DIESEL,	10}, //Firetruck LA
	{true,		2,		FUEL_PETROL,	3}, //Hustler
	{true,		4,		FUEL_PETROL,	3}, //Intruder
	{true,		4,		FUEL_PETROL,	3}, //Primo
	{false,		2,		FUEL_PETROL,	10}, //Cargobob
	{true,		2,		FUEL_PETROL,	3}, //Tampa
	{true,		4,		FUEL_PETROL,	3}, //Sunrise
	{true,		4,		FUEL_PETROL,	3}, //Merit
	{true,		2,		FUEL_DIESEL,	6}, //Utility Van
	{false,		1,		FUEL_PETROL,	8}, //Nevada
	{true,		2,		FUEL_DIESEL,	6}, //Yosemite
	{true,		2,		FUEL_PETROL,	2}, //Windsor
	{true,		2,		FUEL_DIESEL,	5}, //Monster "A"
	{true,		2,		FUEL_DIESEL,	5}, //Monster "B"
	{true,		2,		FUEL_PETROL,	3}, //Uranus
	{true,		2,		FUEL_PETROL,	3}, //Jester
	{true,		4,		FUEL_PETROL,	4}, //Sultan
	{true,		4,		FUEL_PETROL,	4}, //Stratum
	{true,		2,		FUEL_PETROL,	3}, //Elegy
	{false,		2,		FUEL_PETROL,	10}, //Raindance
	{false,		1,		FUEL_PETROL,	0}, //RC Tiger
	{true,		2,		FUEL_PETROL,	3}, //Flash
	{true,		4,		FUEL_PETROL,	3}, //Tahoma
	{true,		4,		FUEL_PETROL,	3}, //Savanna
	{false,		1,		FUEL_PETROL,	0}, //Bandito
	{false,		1,		FUEL_NONE,		0}, //Freight Flat Trailer (Train)
	{false,		4,		FUEL_NONE,		0}, //Streak Trailer (Train)
	{false,		1,		FUEL_PETROL,	0}, //Kart
	{false,		1,		FUEL_DIESEL,	0}, //Mower
	{true,		2,		FUEL_DIESEL,	8}, //Dune
	{true,		1,		FUEL_DIESEL,	0}, //Sweeper
	{true,		2,		FUEL_PETROL,	3}, //Broadway
	{true,		2,		FUEL_PETROL,	3}, //Tornado
	{false,		1,		FUEL_PETROL,	8}, //AT400
	{true,		2,		FUEL_DIESEL,	0}, //DFT-30
	{true,		4,		FUEL_DIESEL,	5}, //Huntley
	{true,		4,		FUEL_PETROL,	4}, //Stafford
	{false,		1,		FUEL_PETROL,	1}, //BF-400
	{true,		4,		FUEL_DIESEL,	7}, //Newsvan
	{true,		1,		FUEL_PETROL,	0}, //Tug
	{false,		1,		FUEL_NONE,		0}, //Petrol Trailer
	{true,		4,		FUEL_PETROL,	3}, //Emperor
	{false,		2,		FUEL_PETROL,	1}, //Wayfarer
	{true,		2,		FUEL_PETROL,	2}, //Euros
	{true,		2,		FUEL_DIESEL,	5}, //Hotdog
	{true,		2,		FUEL_PETROL,	3}, //Club
	{false,		1,		FUEL_NONE,		0}, //Freight Box Trailer (Train)
	{false,		1,		FUEL_NONE,		10}, //Article Trailer 3
	{false,		1,		FUEL_PETROL,	10}, //Andromada
	{true,		2,		FUEL_PETROL,	2}, //Dodo
	{false,		1,		FUEL_PETROL,	0}, //RC Cam
	{false,		1,		FUEL_PETROL,	0}, //Launch
	{true,		4,		FUEL_PETROL,	4}, //Police Car (LSPD)
	{true,		4,		FUEL_PETROL,	4}, //Police Car (SFPD)
	{true,		4,		FUEL_PETROL,	4}, //Police Car (LVPD)
	{true,		2,		FUEL_DIESEL,	5}, //Police Ranger
	{true,		2,		FUEL_PETROL,	3}, //Picador
	{false,		2,		FUEL_DIESEL,	5}, //S.W.A.T.
	{true,		2,		FUEL_PETROL,	2}, //Alpha
	{true,		2,		FUEL_PETROL,	2}, //Phoenix
	{true,		4,		FUEL_PETROL,	3}, //Glendale Shit
	{true,		4,		FUEL_PETROL,	4}, //Sadler Shit
	{false,		1,		FUEL_NONE,		0}, //Baggage Trailer "A"
	{false,		1,		FUEL_NONE,		0}, //Baggage Trailer "B"
	{false,		1,		FUEL_NONE,		0}, //Tug Stairs Trailer
	{true,		4,		FUEL_DIESEL,	8}, //Boxville
	{false,		1,		FUEL_NONE,		0}, //Farm Trailer
	{false,		1,		FUEL_NONE,		0} //Utility Trailer
};
*/

IsStingerVehicle(vehicleid)
{
	if(IsAPlane(vehicleid) || IsAHelicopter(vehicleid) || IsABoat(vehicleid)) return false;
	return true;
}

IsABike(vehicleid)
{
    switch (GetVehicleModel(vehicleid)) 
	{
        case 448, 461..463, 468, 521..523, 581, 586, 481, 509, 510: return 1;
    }
    return 0;
}

IsVehicleEmpty(vehicleid)
{
	for(new i=0; i<MAX_PLAYERS; i++)
	{
		if(IsPlayerInVehicle(i, vehicleid)) return 0;
	}
	return 1;
}

IsABoat(vehicleid)
{
    switch (GetVehicleModel(vehicleid)) 
	{
        case 430, 446, 452, 453, 454, 472, 473, 484, 493, 595: return 1;
    }
    return 0;
}

/*  Cache kepemilikan kendaraan faction.

    Versi lama: tiap fungsi Is<Faction>Vehicle() meloop SELURUH player.
    Dipanggil dari task 160ms untuk setiap kendaraan, biayanya O(V*P),
    sekitar 2,5 juta operasi per detik pada 2000 kendaraan / 100 player.

    Sekarang satu array vehicleid -> faction, di-refresh berkala, dan
    seluruh pengecekan menjadi O(1).                                     */
new AC_VehFactionOwner[MAX_VEHICLES];

RefreshFactionVehicleCache()
{
	for(new v = 0; v < MAX_VEHICLES; v ++)
		AC_VehFactionOwner[v] = FACTION_NONE;

	foreach(new i : Player)
	{
		for(new f = 1; f < MAX_FACTIONS; f ++)
		{
			new vid = PlayerFactionVehicle[i][f];

			if(vid > 0 && vid < MAX_VEHICLES)
				AC_VehFactionOwner[vid] = f;
		}
	}
	return 1;
}

GetVehicleFactionOwner(vehicleid)
{
	if(vehicleid < 1 || vehicleid >= MAX_VEHICLES)
		return FACTION_NONE;

	return AC_VehFactionOwner[vehicleid];
}

stock SetVehicleFactionOwner(vehicleid, factionid)
{
	if(vehicleid > 0 && vehicleid < MAX_VEHICLES)
		AC_VehFactionOwner[vehicleid] = factionid;

	return 1;
}

IsLSPDVehicle(vehicleid)       return (GetVehicleFactionOwner(vehicleid) == FACTION_LSPD);
IsLSFDVehicle(vehicleid)       return (GetVehicleFactionOwner(vehicleid) == FACTION_LSFD);
IsSAGOVVehicle(vehicleid)      return (GetVehicleFactionOwner(vehicleid) == FACTION_SAGOV);
IsPringSewuVehicle(vehicleid)  return (GetVehicleFactionOwner(vehicleid) == FACTION_PRINGSEWU);
IsDinarbucksVehicle(vehicleid) return (GetVehicleFactionOwner(vehicleid) == FACTION_DINARBUCKS);
IsFOX11LAVehicle(vehicleid)    return (GetVehicleFactionOwner(vehicleid) == FACTION_FOX11);
IsUberVehicle(vehicleid)       return (GetVehicleFactionOwner(vehicleid) == FACTION_UBER);
IsBennysVehicle(vehicleid)     return (GetVehicleFactionOwner(vehicleid) == FACTION_BENNYS);
IsDriftKingVehicle(vehicleid)  return (GetVehicleFactionOwner(vehicleid) == FACTION_DRIFTKING);
IsJayaAbadiVehicle(vehicleid)  return (GetVehicleFactionOwner(vehicleid) == FACTION_JAYAABADI);

IsAPlane(vehicleid)
{
    switch (GetVehicleModel(vehicleid)) 
	{
        case 460, 464, 476, 511, 512, 513, 519, 520, 553, 577, 592, 593: return 1;
    }
    return 0;
}

IsAHelicopter(vehicleid)
{
    switch (GetVehicleModel(vehicleid)) 
	{
        case 417, 425, 447, 465, 469, 487, 488, 497, 501, 548, 563: return 1;
    }
    return 0;
}

IsAUnique(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 441, 449, 464, 465, 501, 537, 538: return 1;
	}
	return 0;
}

/*
IsAWheelArch(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 562, 565, 559, 561, 558, 560: return 1;
	}
	return 0;
}
*/

IsATruck(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
	    case 414, 455, 456, 498, 499, 609: return 1;
	    default: return 0;
	}

	return 0;
}

GetEmptyBackSeat(vehicleid)
{
	new bool:Taken[7], Seat, Seats;
	Seats = GetVehicleModelSeats(GetVehicleModel(vehicleid));
	for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInVehicle(i, vehicleid)) //jika ada player di dalam mobil tersebut
        {
            Seat = GetPlayerVehicleSeat(i); //maka kita ambil dia duduk di kursi mana
			Taken[(Seat > 3) ? 3 : Seat] = true;
        }
    }

	for(new d; d < Seats; d++)
	{
        if(!Taken[d] && d != 0 && d != 1)
		{
			return d;
		}
	}
    return INVALID_SEAT_ID;
}

GetEmptySeat(vehicleid)
{
    new bool:Taken[7],Seat,Seats; // [4] ?
    Seats = GetVehicleModelSeats(GetVehicleModel(vehicleid));
    for(new i=0; i < MAX_PLAYERS; i++)
    {
        if(IsPlayerInVehicle(i, vehicleid))
        {
            Seat = GetPlayerVehicleSeat(i);
			Taken[(Seat > 3) ? 3 : Seat] = true;
        }
    }

    for(new d; d < Seats; d++)
	{
        if(!Taken[d] && d != 0)
		{
			return d;
		}
	}
    return INVALID_SEAT_ID;
}

GetVehiclePrice(modelid)
{
	new price;
	switch(modelid)
	{
		//light truck
		case 543: price = 65000; //sadler
    	case 554: price = 145000; //yosemite
    	case 600: price = 85000; //picador

		//heavy truck
		case 414: price = 175000; //mule
    	case 455: price = 140000; //flatbed
    	case 456: price = 110000; //yankee
    	case 499: price = 75000; //benson

		//SUV Wagon
		case 459: price = 115000;  //Berkley's RC Van  //Berkley's RC Van
    	case 404: price = 90000; //perennial //perennial
    	case 400: price = 145000; //landstalker //landstalker

		//motorbike
		case 468: price = 35000; //sanchez
    	case 463: price = 55000; //freeway
    	case 586: price = 40000; //wayfarer
    	case 461: price = 85000; //PCJ-600
    	case 521: price = 125000; //FCR-900

		//lowrider
		case 536: price = 60000; //blade
    	case 567: price = 145000; //savanna
    	case 534: price = 85000; //remington
    	case 412: price = 155000; //voodoo

		//two door
		case 549: price = 85000; //tampa //tampa
    	case 545: price = 195000; //hustler //hustler
    	case 602: price = 155000;  //alpha  //alpha
    	case 496: price = 120000; //blista compact //blista compact
    	case 401: price = 115000; //bravura //bravura
    	case 533: price = 175000; //feltzer //feltzer
    	case 542: price = 105000; //clover //clover
    	case 474: price = 135000; //hermes  //hermes

		//four door
		case 445: price = 145000; //admiral //admiral
    	case 507: price = 135000; //elegant //elegant
    	case 492: price = 125000; //greenwood //greenwood
    	case 426: price = 165000; //premier //premier
    	case 405: price = 150000; //sentinel //sentinel
    	case 580: price = 149000; //stafford //stafford
    	case 560: price = 185000;  //sultan  //sultan
    	case 561: price = 199000;  //stratum  //stratum
    	case 421: price = 125000; //washington //washington
    	case 547: price = 105000; //primo //primo
    	case 540: price = 99000; //vincent //vincent
    	case 551: price = 109000; //merit //merit

		//sisa vehicle (jual/tax)
		case 422: price = 61500; //bobcat
    	case 478: price = 60000; //walton
    	case 579: price = 72000; //huntley
    	case 489: price = 120000;  //Rancher
    	case 479: price = 81000; //regina
    	case 458: price = 81000; //solair
    	case 418: price = 72000; //Moonbeam
    	case 482: price = 90000;  //Burrito
    	case 462: price = 36000; //Faggio
    	case 581: price = 60000; //BF-400
    	case 575: price = 45000; //broadway
    	case 576: price = 120000; //tornado
    	case 491: price = 90000; //virgo
    	case 442: price = 60000; //romero
    	case 439: price = 75000; //stallion
    	case 419: price = 90000; //esperanto
    	case 527: price = 90000; //cadrona
    	case 526: price = 90000; //fortune
    	case 410: price = 120000;  //manana
    	case 436: price = 90000; //previon
    	case 475: price = 75000; //sabre
    	case 555: price = 90000; //windsor
    	case 518: price = 60000; //buccaner
    	case 589: price = 150000;   //club
    	case 517: price = 60000; //majestic
    	case 500: price = 150000;  //mesa
    	case 480: price = 300000;  //comet
    	case 585: price = 120000; //emperor
    	case 546: price = 120000; //intruder
    	case 516: price = 120000; //nebula
    	case 550: price = 69000; //sunrise
    	case 566: price = 120000; //tahoma
    	case 529: price = 120000; //willard
    	case 467: price = 120000; //oceanic
    	case 466: price = 120000; //glendale
		default: price = 60000;
	}
	return price;
}

stock LockVehicle(vehicleid,status)
{
	new engine,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,engine,lights,alarm,status,bonnet,boot,objective);
}

GetValletPrice(modelid)
{
	new price;

	switch(modelid)
	{

		case 448, 461..463, 468, 521, 523, 586, 510: price = 5000;//motorcycle normal

		case 499, 609, 598, 524, 532, 578, 486, 406, 573, 455, 588, 403, 423, 414, 443, 515, 525: price = 15000;//truck

		case 429, 541, 415, 480, 562, 565, 434, 494, 502, 503, 411, 559, 561, 560, 506, 451, 558, 555, 477, 522: price = 10000;//sport vehicle

		case 581, 481, 509: price = 9910;//bicycle

		default: price = 11410;

	}
	return price;

}

#if !defined GetVehicleModelName
stock GetVehicleModelName(modelid)
{
	if(modelid < 400 || modelid > 611) return "Unknown";
	return g_arrVehicleNames[modelid - 400];
}
#endif
#pragma unused RefreshFactionVehicleCache
