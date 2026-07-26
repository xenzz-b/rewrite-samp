#include <YSI_Coding\y_hooks>

enum E_CARGOSTUFF
{
    CargoType,
    CargoCountdown,
    CargoTargetBiz,
    CargoRestockAmount,
    CargoTruckVehicle,
    CargoEverAttached,
    bool:CargoStarted,
    bool:IsLoadingCargo,
    bool:CargoDetached,

    STREAMER_TAG_RACE_CP:CargoDestCP,
    STREAMER_TAG_RACE_CP:CargoReturnCP
};
new PlayerCargoVars[MAX_PLAYERS][E_CARGOSTUFF];

IsHaulingTruck(modelid)
{
    return (modelid == 514 || modelid == 403 || modelid == 515);
}

// ----- Lokasi depot spawn trailer -----
new Float:g_HaulingDepot[][4] = // x, y, z, angle
{
    {251.7326,1420.5673,10.5666,267.3700},
    {644.5520,1251.3062,11.5886,288.8569},
    {582.6589,1213.4221,11.9174,210.2995}
};

// ----- Helper hitung gaji -----
GetHaulingPay(amount)
{
    new pay = 5000 + ((amount - 500) * 3000 / 1500);
    if(pay < 5000) pay = 5000;
    if(pay > 8000) pay = 8000;
    return pay;
}

// ----- Helper hitung harga restock -----
GetRestockCost(amount)
{
    return 5000 + ((amount - 500) * 10000 / 1500);
}

// ----- Reset variabel hauling -----
ResetCargoVars(playerid)
{
    pLoadCargoTimer[playerid] = false;
    AccountData[playerid][pActivityTime] = 0;
    HideProgressBar(playerid);

    PlayerCargoVars[playerid][IsLoadingCargo] = false;
    PlayerCargoVars[playerid][CargoStarted] = false;
    PlayerCargoVars[playerid][CargoDetached] = false;
    PlayerCargoVars[playerid][CargoEverAttached] = false;
    PlayerCargoVars[playerid][CargoType] = 0;
    PlayerCargoVars[playerid][CargoTargetBiz] = -1;
    PlayerCargoVars[playerid][CargoRestockAmount] = 0;
    PlayerCargoVars[playerid][CargoTruckVehicle] = INVALID_VEHICLE_ID;

    ResetAllRaceCP(playerid);
    TogglePlayerControllable(playerid, true);
}

// ----- Destroy trailer hauling saja -----
DestroyHaulingTrailer(playerid)
{
    if(IsValidVehicle(TrailerVehicle[playerid]))
    {
        DestroyVehicle(TrailerVehicle[playerid]);
        TrailerVehicle[playerid] = INVALID_VEHICLE_ID;
    }
}

YCMD:misihauling(playerid, params[], help)
{
    if(AccountData[playerid][pJob] != JOB_CARGO)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda bukan pekerja hauling!");

    if(PlayerCargoVars[playerid][CargoStarted])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda sedang dalam misi hauling!");

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan trucker!");

    new vehicleid = GetPlayerVehicleID(playerid);
    new modelid = GetVehicleModel(vehicleid);

    if(!IsHaulingTruck(modelid))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus menggunakan kendaraan trucker (Tanker/Linerunner/Roadtrain)!");
    
    if(AccountData[playerid][pJobKargoBisnisTime] > 0)
        return Error(playerid, "Anda belum bisa bekerja Hauling saat ini "RED"%d menit", AccountData[playerid][pJobKargoBisnisTime]/60);

    new liststr[1024], count;
    format(liststr, sizeof(liststr), "");

    foreach(new bizid : Bizes)
    {
        if(BizData[bizid][bizType] != 6) continue;
        if(isnull(BizData[bizid][bizOwnerName])) continue;
        if(g_FuelRestockRequest[bizid] <= 0) continue;

        format(liststr, sizeof(liststr), "%s%d. %s - %s (%d liter)\n",
            liststr,
            count + 1,
            BizData[bizid][bizName],
            GetLocation(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]),
            g_FuelRestockRequest[bizid]);

        count++;
        if(count >= 20) break;
    }

    if(count == 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak ada pom bensin yang membutuhkan restock saat ini!");

    Dialog_Show(playerid, "HaulingMissionList", DIALOG_STYLE_LIST, ""Vertex"Vertex Roleplay "WHITE"- Misi Hauling", liststr, "Pilih", "Batal");
    return 1;
}

Dialog:HaulingMissionList(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus berada di dalam kendaraan trucker!");

    new vehicleid = GetPlayerVehicleID(playerid);
    if(!IsHaulingTruck(GetVehicleModel(vehicleid)))
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda harus menggunakan kendaraan trucker!");

    new count = 0, targetBiz = -1;
    foreach(new bizid : Bizes)
    {
        if(BizData[bizid][bizType] != 6) continue;
        if(isnull(BizData[bizid][bizOwnerName])) continue;
        if(g_FuelRestockRequest[bizid] <= 0) continue;

        if(count == listitem)
        {
            targetBiz = bizid;
            break;
        }
        count++;
    }

    if(targetBiz == -1)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis tidak ditemukan, coba lagi.");

    ResetAllRaceCP(playerid);
    DestroyHaulingTrailer(playerid);

    // ----- Spawn trailer di depot random -----
    new depot = random(sizeof(g_HaulingDepot));

    TrailerVehicle[playerid] = CreateVehicle(584,
        g_HaulingDepot[depot][0], g_HaulingDepot[depot][1], g_HaulingDepot[depot][2],
        g_HaulingDepot[depot][3], -1, -1, 60000, false);
    SetValidVehicleHealth(TrailerVehicle[playerid], 1000.0);
    VehicleCore[TrailerVehicle[playerid]][vMaxHealth] = 1000.0;

    PlayerCargoVars[playerid][CargoType] = 1;
    PlayerCargoVars[playerid][CargoStarted] = true;
    PlayerCargoVars[playerid][IsLoadingCargo] = false;
    PlayerCargoVars[playerid][CargoDetached] = false;
    PlayerCargoVars[playerid][CargoEverAttached] = false;
    PlayerCargoVars[playerid][CargoTargetBiz] = targetBiz;
    PlayerCargoVars[playerid][CargoRestockAmount] = g_FuelRestockRequest[targetBiz];
    PlayerCargoVars[playerid][CargoTruckVehicle] = vehicleid;

    // ----- CP ke depot untuk ambil trailer & muat -----
    PlayerCargoVars[playerid][CargoDestCP] = CreateDynamicRaceCP(1,
        g_HaulingDepot[depot][0], g_HaulingDepot[depot][1], g_HaulingDepot[depot][2],
        g_HaulingDepot[depot][0], g_HaulingDepot[depot][1], g_HaulingDepot[depot][2],
        5.0, 0, 0, playerid, 6000.00, -1, 0);

    Info(playerid, "Misi hauling dimulai! Pergi ke depot, sambungkan trailer lalu muat BBM. Tujuan: "YELLOW"%s"WHITE" (%s).",BizData[targetBiz][bizName],GetLocation(BizData[targetBiz][bizExtPos][0], BizData[targetBiz][bizExtPos][1], BizData[targetBiz][bizExtPos][2]));

    return 1;
}

ShowFuelRestockRequestDialog(playerid, bizid)
{
    if(BizData[bizid][bizType] != 6)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bukan pom bensin!");

    if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

    if(g_FuelRestockRequest[bizid] > 0)
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Sudah ada request restock aktif sebesar %d liter.", g_FuelRestockRequest[bizid]));

    SetPVarInt(playerid, "HaulingRequestBiz", bizid);
    Dialog_Show(playerid, "HaulingRestockInput", DIALOG_STYLE_INPUT,""Vertex"Vertex Roleplay "WHITE"- Request Restock BBM",sprintf("Masukkan jumlah liter BBM yang ingin direstock (500 - 2000):\n"GRAY"Stok saat ini: %d liter\nHarga akan dipotong dari kas bisnis.", BizData[bizid][bizFuelStock]),"Request", "Batal");
    return 1;
}

Dialog:HaulingRestockInput(playerid, response, listitem, inputtext[])
{
    if(!response) return 1;

    new bizid = GetPVarInt(playerid, "HaulingRequestBiz");
    if(!Iter_Contains(Bizes, bizid) || BizData[bizid][bizType] != 6)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis tidak valid!");

    if(BizData[bizid][bizOwnerID] != AccountData[playerid][pID])
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Bisnis ini bukan milik anda!");

    if(isnull(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak dapat dibiarkan kosong!");
    if(!IsNumericEx(inputtext)) return ShowTDN(playerid, NOTIFICATION_ERROR, "Hanya dapat diisi angka!");

    new amount = strval(inputtext);

    if(amount < 500 || amount > 2000)
        return ShowTDN(playerid, NOTIFICATION_ERROR, "Jumlah restock harus antara 500 - 2000 liter!");

    new cost = GetRestockCost(amount);

    if(BizData[bizid][bizMoney] < cost)
        return ShowTDN(playerid, NOTIFICATION_ERROR, sprintf("Kas bisnis tidak cukup! Butuh $%s (Kas: $%s).", FormatMoney(cost), FormatMoney(BizData[bizid][bizMoney])));

    BizData[bizid][bizMoney] -= cost;
    g_FuelRestockRequest[bizid] = amount;
    g_FuelRestockAmount[bizid] = amount;

    Biz_Save(bizid);
    Biz_Refresh(bizid);

    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Request restock %d liter berhasil! Kas dipotong $%s. Menunggu hauler.", amount, FormatMoney(cost)));

    foreach(new i : Player)
    {
        if(AccountData[i][pJob] == JOB_CARGO && IsPlayerConnected(i))
        {
            Info(i, ""YELLOW"[HAULING] "WHITE"Pom bensin "YELLOW"%s "WHITE"membutuhkan restock "YELLOW"%d liter "WHITE"BBM!", BizData[bizid][bizName], amount);
            Info(i, "Ketik "GREEN"/misihauling "WHITE"untuk menerima misi.");
        }
    }

    return 1;
}

hook OnPlayerEnterDynRaceCP(playerid, STREAMER_TAG_RACE_CP:checkpointid)
{
    if(AccountData[playerid][pJob] != JOB_CARGO) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 1;

    new vehicleid = GetPlayerVehicleID(playerid);
    if(vehicleid != PlayerCargoVars[playerid][CargoTruckVehicle]) return 1;

    // ----- CP depot: muat BBM -----
    if(checkpointid == PlayerCargoVars[playerid][CargoDestCP] && IsPlayerInDynamicRaceCP(playerid, PlayerCargoVars[playerid][CargoDestCP]))
    {
        if(PlayerCargoVars[playerid][CargoStarted] && !PlayerCargoVars[playerid][IsLoadingCargo])
        {
            if(!IsTrailerAttachedToVehicle(vehicleid))
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Sambungkan trailer terlebih dahulu ke truk anda!");

            if(GetVehicleTrailer(vehicleid) != TrailerVehicle[playerid])
                return ShowTDN(playerid, NOTIFICATION_ERROR, "Trailer ini bukan milik anda!");

            PlayerCargoVars[playerid][IsLoadingCargo] = true;
            AccountData[playerid][pActivityTime] = 1;
            TogglePlayerControllable(playerid, false);
            pLoadCargoTimer[playerid] = true;
            Toggle_AllTextdraws(playerid, false);
            PlayerTextDrawSetString(playerid, ProgressBar[playerid][1], "MEMUAT BBM");
            ShowProgressBar(playerid);
        }
    }
    else if(checkpointid == PlayerCargoVars[playerid][CargoReturnCP] && IsPlayerInDynamicRaceCP(playerid, PlayerCargoVars[playerid][CargoReturnCP]))
    {
        new bizid = PlayerCargoVars[playerid][CargoTargetBiz];
        new amount = PlayerCargoVars[playerid][CargoRestockAmount];
        new pay = GetHaulingPay(amount);

        if(Iter_Contains(Bizes, bizid))
        {
            BizData[bizid][bizFuelStock] += amount;
            if(BizData[bizid][bizFuelStock] > 50000) BizData[bizid][bizFuelStock] = 50000;

            g_FuelRestockRequest[bizid] = 0;
            g_FuelRestockAmount[bizid] = 0;

            Biz_Save(bizid);
            Biz_Refresh(bizid);

            foreach(new i : Player)
            {
                if(IsPlayerConnected(i) && AccountData[i][pID] == BizData[bizid][bizOwnerID])
                {
                    Info(i, "Restock BBM "YELLOW"%s "WHITE"sebesar "YELLOW"%d liter "WHITE"telah selesai oleh "YELLOW"%s"WHITE".",BizData[bizid][bizName], amount, AccountData[playerid][pName]);
                }
            }
        }

        DestroyHaulingTrailer(playerid);
        GivePlayerMoneyEx(playerid, pay);
        ShowItemBox(playerid, "Cash", sprintf("Received $%s", FormatMoney(pay)), 1212, 5);
        ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Hauling selesai! Gaji: "GREEN"$%s"WHITE".", FormatMoney(pay)));
        ResetCargoVars(playerid);
        AccountData[playerid][pJobKargoBisnisTime] = 900;
    }

    return 1;
}

hook OnPlayerLeaveDynRaceCP(playerid, STREAMER_TAG_RACE_CP:checkpointid)
{
    if(AccountData[playerid][pJob] != JOB_CARGO) return 1;
    if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER) return 1;
    if(GetPlayerVehicleID(playerid) != PlayerCargoVars[playerid][CargoTruckVehicle]) return 1;

    if(checkpointid == PlayerCargoVars[playerid][CargoDestCP])
    {
        if(PlayerCargoVars[playerid][IsLoadingCargo])
        {
            PlayerCargoVars[playerid][IsLoadingCargo] = false;
            pLoadCargoTimer[playerid] = false;
            AccountData[playerid][pActivityTime] = 0;
            HideProgressBar(playerid);
            TogglePlayerControllable(playerid, true);
            ShowTDN(playerid, NOTIFICATION_WARNING, "Pemuatan BBM dibatalkan karena anda meninggalkan area depot.");
        }
    }

    return 1;
}

OnHaulingLoadComplete(playerid)
{
    PlayerCargoVars[playerid][IsLoadingCargo] = false;
    pLoadCargoTimer[playerid] = false;
    AccountData[playerid][pActivityTime] = 0;
    HideProgressBar(playerid);
    TogglePlayerControllable(playerid, true);
    Toggle_AllTextdraws(playerid, true);

    new bizid = PlayerCargoVars[playerid][CargoTargetBiz];
    if(!Iter_Contains(Bizes, bizid)) return;

    DestroyDynamicRaceCP(PlayerCargoVars[playerid][CargoDestCP]);
    PlayerCargoVars[playerid][CargoDestCP] = STREAMER_TAG_RACE_CP:INVALID_STREAMER_ID;

    PlayerCargoVars[playerid][CargoStarted] = false;

    PlayerCargoVars[playerid][CargoReturnCP] = CreateDynamicRaceCP(1,BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2],BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2],5.0, 0, 0, playerid, 6000.00, -1, 0);
    Info(playerid, "BBM berhasil dimuat! Antar ke "YELLOW"%s"WHITE" di %s.",BizData[bizid][bizName],GetLocation(BizData[bizid][bizExtPos][0], BizData[bizid][bizExtPos][1], BizData[bizid][bizExtPos][2]));
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if(newkeys & KEY_YES && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && AccountData[playerid][pJob] == JOB_CARGO)
    {
        if(IsPlayerInRangeOfPoint(playerid, 1.5, -1680.2018, 26.4608, 3.6853))
        {
            if(PlayerCargoVars[playerid][CargoStarted] || IsValidVehicle(TrailerVehicle[playerid]))
            {
                new bizid = PlayerCargoVars[playerid][CargoTargetBiz];
                if(Iter_Contains(Bizes, bizid))
                {
                    g_FuelRestockRequest[bizid] = 0;
                    g_FuelRestockAmount[bizid] = 0;
                }

                DestroyHaulingTrailer(playerid);
                ResetCargoVars(playerid);
                ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membatalkan misi hauling.");
            }
        }
    }
    return 1;
}

ptask CheckingTrailer[1000](playerid)
{
    if(AccountData[playerid][pJob] != JOB_CARGO || PlayerCargoVars[playerid][CargoType] <= 0) return 1;

    new truckveh = PlayerCargoVars[playerid][CargoTruckVehicle];

    // ----- Cek truk pribadi masih valid -----
    if(!IsValidVehicle(truckveh))
    {
        DestroyHaulingTrailer(playerid);
        ResetCargoVars(playerid);
        SendClientMessage(playerid, -1, "[i] Misi hauling anda dinyatakan gagal karena truk anda tidak valid.");
        return 1;
    }

    // ----- Cek trailer masih valid -----
    if(!IsValidVehicle(TrailerVehicle[playerid]))
    {
        TrailerVehicle[playerid] = INVALID_VEHICLE_ID;
        ResetCargoVars(playerid);
        SendClientMessage(playerid, -1, "[i] Misi hauling anda dinyatakan gagal karena kehilangan trailer.");
        return 1;
    }

    // ----- Trailer tersambung kembali -----
    if(IsTrailerAttachedToVehicle(truckveh) && GetVehicleTrailer(truckveh) == TrailerVehicle[playerid])
    {
        if(PlayerCargoVars[playerid][CargoDetached])
        {
            PlayerCargoVars[playerid][CargoDetached] = false;
            PlayerCargoVars[playerid][CargoCountdown] = 0;
        }

        // Tandai bahwa trailer sudah pernah tersambung
        if(!PlayerCargoVars[playerid][CargoEverAttached])
            PlayerCargoVars[playerid][CargoEverAttached] = true;

        return 1;
    }

    // ----- Belum pernah di-attach, skip pengecekan lepas -----
    if(!PlayerCargoVars[playerid][CargoEverAttached]) return 1;

    // ----- Trailer terlepas -----
    if(!PlayerCargoVars[playerid][CargoDetached])
    {
        if(!IsTrailerAttachedToVehicle(truckveh) && GetVehicleTrailer(truckveh) != TrailerVehicle[playerid])
        {
            PlayerCargoVars[playerid][CargoDetached] = true;
            PlayerCargoVars[playerid][CargoCountdown] = 30;
            SendClientMessage(playerid, -1, "[i] Trailer hauling terlepas! Anda memiliki "RED"30 detik "WHITE"untuk menyatukannya kembali!");
        }
    }
    else
    {
        if(PlayerCargoVars[playerid][CargoCountdown] > 0)
        {
            PlayerCargoVars[playerid][CargoCountdown]--;
            GameTextForPlayer(playerid, sprintf("%d", PlayerCargoVars[playerid][CargoCountdown]), 1000, 4);
        }
        else
        {
            if(!IsTrailerAttachedToVehicle(truckveh) && GetVehicleTrailer(truckveh) != TrailerVehicle[playerid])
            {
                new bizid = PlayerCargoVars[playerid][CargoTargetBiz];
                if(Iter_Contains(Bizes, bizid))
                {
                    g_FuelRestockRequest[bizid] = 0;
                    g_FuelRestockAmount[bizid] = 0;
                }

                DestroyHaulingTrailer(playerid);
                ResetCargoVars(playerid);
                SendClientMessage(playerid, -1, "[i] Misi hauling anda dinyatakan gagal karena kehilangan trailer.");
            }
            else
            {
                PlayerCargoVars[playerid][CargoDetached] = false;
            }
        }
    }

    return 1;
}

ptask Hauling_Tick[1000](playerid)
{
    if(pLoadCargoTimer[playerid])
    {
        if(!IsPlayerConnected(playerid))
        {
            pLoadCargoTimer[playerid] = false;
            return 0;
        }

        if(!PlayerCargoVars[playerid][CargoStarted] && !PlayerCargoVars[playerid][IsLoadingCargo])
        {
            pLoadCargoTimer[playerid] = false;
            AccountData[playerid][pActivityTime] = 0;
            HideProgressBar(playerid);
            TogglePlayerControllable(playerid, true);
            Toggle_AllTextdraws(playerid, true);
            return 0;
        }

        if(!PlayerCargoVars[playerid][IsLoadingCargo])
        {
            pLoadCargoTimer[playerid] = false;
            AccountData[playerid][pActivityTime] = 0;
            HideProgressBar(playerid);
            TogglePlayerControllable(playerid, true);
            Toggle_AllTextdraws(playerid, true);
            return 0;
        }

        if(AccountData[playerid][pActivityTime] >= 66)
        {
            PlayerPlaySound(playerid, 12200, 0.0, 0.0, 0.0);
            OnHaulingLoadComplete(playerid);
        }
        else
        {
            AccountData[playerid][pActivityTime]++;

            static Float:progressvalue;
            progressvalue = AccountData[playerid][pActivityTime] * 102.0 / 66;
            PlayerTextDrawTextSize(playerid, ProgressBar[playerid][0], progressvalue, 20.0);
            PlayerTextDrawShow(playerid, ProgressBar[playerid][0]);

            PlayerPlaySound(playerid, 6002, 0.0, 0.0, 0.0);
        }
    }
    return 1;
}

hook OnPlayerConnect(playerid)
{
    ResetCargoVars(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(PlayerCargoVars[playerid][CargoStarted] || IsValidVehicle(TrailerVehicle[playerid]))
    {
        new bizid = PlayerCargoVars[playerid][CargoTargetBiz];
        if(Iter_Contains(Bizes, bizid))
        {
            g_FuelRestockRequest[bizid] = 0;
            g_FuelRestockAmount[bizid] = 0;
        }
        DestroyHaulingTrailer(playerid);
    }
    ResetCargoVars(playerid);
    return 1;
}