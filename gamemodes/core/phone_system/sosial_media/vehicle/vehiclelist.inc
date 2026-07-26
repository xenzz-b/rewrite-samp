#include <YSI_Coding\y_hooks>

#define COLOR_RED 0xFF0000FF
#define COLOR_TOSKA 0x2ECC71FF
#define COLOR_WHITE 0xFFFFFFFF

new PlayerText:VehicleListTD[MAX_PLAYERS][4][18];
new listCar[MAX_PLAYERS][4];

HideVehicleListTD(playerid)
{
    for(new i = 0; i < 4; i++)
    {
        for(new x = 0; x < 18; x++)
        {
            PlayerTextDrawHide(playerid, VehicleListTD[playerid][i][x]);
        }
    }
}

ShowVehicleList(playerid, idx) 
{
    for(new j = 0; j < 18; j++) 
    {
        PlayerTextDrawShow(playerid, VehicleListTD[playerid][idx][j]);
    }
}

HideVehicleList(playerid, slot)
{
    for(new x = 0; x < 18; x++)
    {
        PlayerTextDrawHide(playerid, VehicleListTD[playerid][slot][x]);
    }
}

ShowBackroundVehicleList(playerid)
{
    for(new x = 0; x < 45; x++)
    {
        PlayerTextDrawShow(playerid, VehicleList[playerid][x]);
    }
}

HideBackroundVehicleList(playerid)
{
    for(new x = 0; x < 45; x++)
    {
        PlayerTextDrawHide(playerid, VehicleList[playerid][x]);
    }
}

UpdatePageDisplay(playerid)
{
    new page_text[8];
    format(page_text, sizeof(page_text), "%d/2", VehiclePage[playerid] + 1);
    PlayerTextDrawSetString(playerid, VehicleList[playerid][37], page_text);
}

ChangeVehiclePage(playerid, direction)
{
    if(direction == 0)
    {
        if(VehiclePage[playerid] > 0)
        {
            VehiclePage[playerid]--;
            SyncVehiclePage(playerid);
            UpdatePageDisplay(playerid);
            PlayerTextDrawColor(playerid, VehicleList[playerid][43], 981194239);
            PlayerTextDrawColor(playerid, VehicleList[playerid][44], 253636863);
        }
    }
    else if(direction == 1)
    {
        if(VehiclePage[playerid] < 1)
        {
            VehiclePage[playerid]++;
            SyncVehiclePage(playerid);
            UpdatePageDisplay(playerid);
            PlayerTextDrawColor(playerid, VehicleList[playerid][43], 253636863);
            PlayerTextDrawColor(playerid, VehicleList[playerid][44], 981194239);
        }
    }
}

CreateListVehicleTD(playerid)
{
    for(new idx = 0; idx < 4; idx++)
    {
        new Float:y = (idx * 43.0);

        VehicleListTD[playerid][idx][0] = CreatePlayerTextDraw(playerid, 513.000, 155.500 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][0], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][0], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][0], 507139583);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][0], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][0], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][0], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][0], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][0], 1);

        VehicleListTD[playerid][idx][1] = CreatePlayerTextDraw(playerid, 521.500, 159.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][1], 85.000, 39.500);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][1], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][1], 507139583);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][1], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][1], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][1], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][1], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][1], 1);

        VehicleListTD[playerid][idx][2] = CreatePlayerTextDraw(playerid, 597.000, 155.500 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][2], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][2], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][2], 507139583);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][2], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][2], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][2], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][2], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][2], 1);

        VehicleListTD[playerid][idx][3] = CreatePlayerTextDraw(playerid, 513.000, 182.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][3], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][3], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][3], 507139583);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][3], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][3], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][3], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][3], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][3], 1);

        VehicleListTD[playerid][idx][4] = CreatePlayerTextDraw(playerid, 597.000, 182.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][4], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][4], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][4], 507139583);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][4], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][4], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][4], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][4], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][4], 1);

        VehicleListTD[playerid][idx][5] = CreatePlayerTextDraw(playerid, 515.500, 166.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][5], 96.500, 25.500);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][5], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][5], 507139583);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][5], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][5], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][5], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][5], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][5], 1);

        VehicleListTD[playerid][idx][6] = CreatePlayerTextDraw(playerid, 514.000, 156.500 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][6], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][6], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][6], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][6], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][6], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][6], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][6], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][6], 1);

        VehicleListTD[playerid][idx][7] = CreatePlayerTextDraw(playerid, 514.000, 181.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][7], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][7], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][7], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][7], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][7], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][7], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][7], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][7], 1);

        VehicleListTD[playerid][idx][8] = CreatePlayerTextDraw(playerid, 596.000, 181.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][8], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][8], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][8], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][8], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][8], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][8], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][8], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][8], 1);

        VehicleListTD[playerid][idx][9] = CreatePlayerTextDraw(playerid, 596.000, 157.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][9], 18.000, 20.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][9], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][9], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][9], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][9], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][9], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][9], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][9], 1);

        VehicleListTD[playerid][idx][10] = CreatePlayerTextDraw(playerid, 521.500, 160.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][10], 83.500, 37.500);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][10], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][10], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][10], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][10], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][10], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][10], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][10], 1);

        VehicleListTD[playerid][idx][11] = CreatePlayerTextDraw(playerid, 516.500, 166.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][11], 94.500, 24.500);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][11], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][11], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][11], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][11], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][11], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][11], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][11], 1);

        VehicleListTD[playerid][idx][12] = CreatePlayerTextDraw(playerid, 522.500, 163.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][12], 85.500, 31.500);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][12], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][12], 253636863);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][12], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][12], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][12], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][12], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][12], 1);
        PlayerTextDrawSetSelectable(playerid, VehicleListTD[playerid][idx][12], 1);

        VehicleListTD[playerid][idx][13] = CreatePlayerTextDraw(playerid, 522.500, 169.000 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][13], 18.500, 19.500);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][13], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][13], 219818239);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][13], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][13], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][13], 255);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][13], 4);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][13], 1);

        VehicleListTD[playerid][idx][14] = CreatePlayerTextDraw(playerid, 583.000, 174.000 + y, "Spawned");
        PlayerTextDrawLetterSize(playerid, VehicleListTD[playerid][idx][14], 0.12, 0.89);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][14], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][14], -427941121);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][14], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][14], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][14], 150);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][14], 1);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][14], 1);

        VehicleListTD[playerid][idx][15] = CreatePlayerTextDraw(playerid, 516.000, 159.000 + y, "_");
        PlayerTextDrawTextSize(playerid, VehicleListTD[playerid][idx][15], 29.000, 37.000);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][15], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][15], -1);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][15], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][15], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][15], 0);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][15], 5);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][15], 0);
        PlayerTextDrawSetPreviewModel(playerid, VehicleListTD[playerid][idx][15], 560);
        PlayerTextDrawSetPreviewRot(playerid, VehicleListTD[playerid][idx][15], 0.000, 0.000, 28.000, 1.000);
        PlayerTextDrawSetPreviewVehCol(playerid, VehicleListTD[playerid][idx][15], 0, 0);

        VehicleListTD[playerid][idx][16] = CreatePlayerTextDraw(playerid, 545.000, 168.000 + y, "Sultan");
        PlayerTextDrawLetterSize(playerid, VehicleListTD[playerid][idx][16], 0.200, 0.999);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][16], 1);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][16], -1059524353);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][16], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][16], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][16], 150);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][16], 1);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][16], 1);

        VehicleListTD[playerid][idx][17] = CreatePlayerTextDraw(playerid, 558.000, 177.000 + y, "Plate: B1212");
        PlayerTextDrawLetterSize(playerid, VehicleListTD[playerid][idx][17], 0.119, 0.799);
        PlayerTextDrawAlignment(playerid, VehicleListTD[playerid][idx][17], 2);
        PlayerTextDrawColor(playerid, VehicleListTD[playerid][idx][17], 1248495103);
        PlayerTextDrawSetShadow(playerid, VehicleListTD[playerid][idx][17], 0);
        PlayerTextDrawSetOutline(playerid, VehicleListTD[playerid][idx][17], 0);
        PlayerTextDrawBackgroundColor(playerid, VehicleListTD[playerid][idx][17], 150);
        PlayerTextDrawFont(playerid, VehicleListTD[playerid][idx][17], 1);
        PlayerTextDrawSetProportional(playerid, VehicleListTD[playerid][idx][17], 1);
    }
}

hook OnPlayerConnect(playerid)
{
    CreateListVehicleTD(playerid);
    return 1;
}

stock SyncVehiclePage(playerid) 
{
    new query[156];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `player_vehicles` WHERE `PVeh_Owner` = '%d'", AccountData[playerid][pID]);
    mysql_tquery(g_SQL, query, "OnSyncVehiclePhone", "d", playerid);
}

forward OnSyncVehiclePhone(playerid);
public OnSyncVehiclePhone(playerid) 
{
    new Vehicle_Status[4][64],
        Vehicle_Name[4][64],
        Vehicle_Plate[4][64];

    ShowBackroundVehicleList(playerid);
    HideVehicleListTD(playerid);

    for(new i = 0; i < 4; i++) {
        listCar[playerid][i] = INVALID_VEHICLE_ID;
        Vehicle_Name[i][0] = '\0';
        Vehicle_Plate[i][0] = '\0';
        Vehicle_Status[i][0] = '\0';
    }

    new page = VehiclePage[playerid];
    new start_idx = page * 4;
    new slot = 0;
    
    for(new i = start_idx; i < cache_num_rows() && slot < 4; i++) 
    {
        new insurance, garage, rental, house, sqlid, vehicleid = INVALID_VEHICLE_ID, plate[16], modelid, status[128], impounded;
        
        cache_get_value_name_int(i, "id", sqlid);
        cache_get_value_name_int(i, "PVeh_Insuranced", insurance);
        cache_get_value_name_int(i, "PVeh_Impounded", impounded);
        cache_get_value_name_int(i, "PVeh_Housed", house);
        cache_get_value_name_int(i, "PVeh_Rental", rental);
        cache_get_value_name_int(i, "PVeh_Parked", garage);
        cache_get_value_name(i, "PVeh_Plate", plate);
        cache_get_value_name_int(i, "PVeh_ModelID", modelid);

        vehicleid = GetVehicleID(sqlid);
        listCar[playerid][slot] = vehicleid;

        if(PlayerVehicle[vehicleid][pVehPhysic] != INVALID_VEHICLE_ID) 
        {
            format(Vehicle_Name[slot], 64, " %s", GetVehicleModelName(modelid));
            format(Vehicle_Plate[slot], 64, "Plate: %s", plate);
            format(Vehicle_Status[slot], 64, "(Spawned)");
        } 
        else 
        {
            format(Vehicle_Name[slot], 64, "%s", GetVehicleModelName(modelid));
            format(Vehicle_Plate[slot], 64, "%s", plate);
            
            status[0] = '\0';
            if (PlayerVehicle[vehicleid][pVehInsuranced]) 
            {
                format(Vehicle_Status[slot], 64, "(Asuransi)");
            }
            if (PlayerVehicle[vehicleid][pVehParked] >= 0) 
            {
                format(Vehicle_Status[slot], 64, "Garasi ~n~(%s)", PublicGarage[garage][pgName]);
            }
            if (PlayerVehicle[vehicleid][pVehFamGarage] >= 0) 
            {
                format(Vehicle_Status[slot], 64, "Garasi ~n~(%s)", PlayerVehicle[vehicleid][pVehFamGarage]);
            }
            if (PlayerVehicle[vehicleid][pVehHouseGarage] >= 0) 
            {
                format(Vehicle_Status[slot], 64, "Rumah ~n~(%d)", PlayerVehicle[vehicleid][pVehHouseGarage]);
            }
            if (PlayerVehicle[vehicleid][pVehImpounded]) 
            {
                format(Vehicle_Status[slot], 64, "(Samsat)");
            }
        }
        
        PlayerTextDrawSetString(playerid, VehicleListTD[playerid][slot][14], Vehicle_Status[slot]);
        PlayerTextDrawSetString(playerid, VehicleListTD[playerid][slot][16], Vehicle_Name[slot]);
        PlayerTextDrawSetPreviewModel(playerid, VehicleListTD[playerid][slot][15], modelid);
        PlayerTextDrawSetPreviewVehCol(playerid, VehicleListTD[playerid][slot][15], PlayerVehicle[vehicleid][pVehColor1], PlayerVehicle[vehicleid][pVehColor2]);
        PlayerTextDrawSetString(playerid, VehicleListTD[playerid][slot][17], Vehicle_Plate[slot]);
        
        if(PlayerVehicle[vehicleid][pVehPhysic] != INVALID_VEHICLE_ID)
        {
            PlayerTextDrawColor(playerid, VehicleListTD[playerid][slot][14], COLOR_WHITE);
        }
        else
        {
            if (PlayerVehicle[vehicleid][pVehInsuranced] || PlayerVehicle[vehicleid][pVehImpounded])
            {
                PlayerTextDrawColor(playerid, VehicleListTD[playerid][slot][14], COLOR_RED);
            }
            else
            {
                PlayerTextDrawColor(playerid, VehicleListTD[playerid][slot][14], COLOR_TOSKA);
            }
        }
        ShowVehicleList(playerid, slot);
        
        slot++;
    }
    for(new i = slot; i < 4; i++) 
    {
        HideVehicleList(playerid, i);
    }
    return 1;
}
hook ClickDynPlayerTextdraw(playerid, PlayerText:textid)
{
    if(textid == VehicleList[playerid][39])
    {
        ChangeVehiclePage(playerid, 1);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    
    if(textid == VehicleList[playerid][40])
    {
        ChangeVehiclePage(playerid, 0);
        return Y_HOOKS_CONTINUE_RETURN_1;
    }
    if(textid == VehicleList[playerid][15])
    {
        HideBackroundVehicleList(playerid);
        HideVehicleListTD(playerid);
        ShowPhoneNSRP(playerid);
    }
    for(new i = 0; i < 4; i++)
    {
        if(listCar[playerid][i] != INVALID_VEHICLE_ID && textid == VehicleListTD[playerid][i][12]) 
        {
            new vehicleid = listCar[playerid][i];
            SetPVarInt(playerid, "ClickVehicle", vehicleid);
            new price = GetValletPrice(PlayerVehicle[vehicleid][pVehModelID]);
            Dialog_Show(playerid, "MyvMenuList", DIALOG_STYLE_LIST, ""Nexston"Nexston Roleplay "WHITE"- Kendaraan Saya", sprintf(""GREY"Cari Kendaraan\n"WHITE"Vallet "GREEN"(%s)\n"GRAY"Detail Kendaraan", FormatMoney(price)), "Pilih", "Batal");
            break;
        }
    }
    return Y_HOOKS_CONTINUE_RETURN_1;
}

Dialog:MyvMenuList(playerid, response, listitem, inputtext[])
{
	if(!response) return Info(playerid, "Anda telah membatalkan pilihan");
	switch(listitem)
	{
		case 0: // cari Kendaraan
		{

			if(!response) return Info(playerid, "Anda telah membatalkan pilihan!");

			Dialog_Show(playerid, "VehicleTrack", DIALOG_STYLE_INPUT, ""Nexston"Nexston Roleplay "WHITE"- Track Veh", ""WHITE"Pencarian kendaraan\n"YELLOW"(Masukkan VID kendaraan yang ingin dicari):", "Input", "Batal");
		}
		case 1: { // Vallet
			new vehid = GetPVarInt(playerid, "ClickVehicle");
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, z, z, z);
			GetXYInFrontOfPlayer(playerid, x, y, 3.0);
			new price = GetValletPrice(PlayerVehicle[vehid][pVehModelID]);
			if(AccountData[playerid][pMoney] < price)
				return Error(playerid, "Kamu membutuhkan $%s untuk vallet.", FormatMoney(price));

			if(GetPlayerInterior(playerid) != 0)
				return Error(playerid, "Kamu harus berada diluar ruangan.");

			TakePlayerMoneyEx(playerid, price);
			Info(playerid, "Kamu telah menggunakan vallet pada kendaraanmu.");
			if(!IsValidVehicle(PlayerVehicle[vehid][pVehPhysic]))
			{
				if(PlayerVehicle[vehid][pVehInsuranced])
				{
					PlayerVehicle[vehid][pVehInsuranced] = false;
				}
				if(PlayerVehicle[vehid][pVehImpounded])
				{
					PlayerVehicle[vehid][pVehImpounded] = false;
					PlayerVehicle[vehid][pVehImpoundDuration] = 0;
					PlayerVehicle[vehid][pVehImpoundFee] = 0;
					format(PlayerVehicle[vehid][pVehImpoundReason], 64, "N/A");
				}
				if(PlayerVehicle[vehid][pVehParked] >= 0)
				{
					PlayerVehicle[vehid][pVehParked] = -1;
				}
				if(PlayerVehicle[vehid][pVehFamGarage] >= 0) 
				{
					PlayerVehicle[vehid][pVehFamGarage] = -1;
				}
				if(PlayerVehicle[vehid][pVehJDMGarage] >= 0) 
				{
					PlayerVehicle[vehid][pVehJDMGarage] = -1;
				}
				if(PlayerVehicle[vehid][pVehHouseGarage] >= 0) 
				{
					PlayerVehicle[vehid][pVehHouseGarage] = -1;
				}
				PlayerVehicle[vehid][pVehWorld] = GetPlayerVirtualWorld(playerid);
				PlayerVehicle[vehid][pVehInterior] = GetPlayerInterior(playerid);
				PlayerVehicle[vehid][pVehPos][0] = x;
				PlayerVehicle[vehid][pVehPos][1] = y;
				PlayerVehicle[vehid][pVehPos][2] = z;
				OnPlayerVehicleRespawn(vehid);
			}
			else 
			{
				SetVehiclePos(PlayerVehicle[vehid][pVehPhysic], x, y, z);
				SetVehicleVirtualWorld(PlayerVehicle[vehid][pVehPhysic], GetPlayerVirtualWorld(playerid));
				LinkVehicleToInterior(PlayerVehicle[vehid][pVehPhysic], GetPlayerInterior(playerid));
			}
		}
		case 2:
		{
			static strings[1048], Float:vHealth;
			new vehid = GetPVarInt(playerid, "ClickVehicle");
			if(!IsValidVehicle(PlayerVehicle[vehid][pVehPhysic]))
				return Error(playerid, "Kendaraan tersebut belum spawn!");
			if(GetNearestVehicleToPlayer(playerid, 5.0, false) != PlayerVehicle[vehid][pVehPhysic])
				return Error(playerid, "Anda tidak didekat kendaraan yang ingin anda cek detailnya!");
			GetVehicleHealth(PlayerVehicle[vehid][pVehPhysic], vHealth);
			format(strings, sizeof(strings), ""Nexston"Utama\n\
			\n"WHITE"VID (Database):"YELLOW" %d\n\
			\n"WHITE"Kendaraan:"YELLOW" %s\n\
			\n"WHITE"Nomor Plat:"YELLOW" %s\n\
			\n\n"Nexston"Upgrade:\n\
			\n"WHITE"- Engine Upgrade: %s\n\
			\n"WHITE"- Body Upgrade: %s\n\
			\n\n"Nexston"Selebihnya\n\
			\n"WHITE"Fuel Capacity:"YELLOW" %d.0/100.0\n\
			\n"WHITE"Max Vehicle Health:"YELLOW" %.1f/%s\n\
			\n"WHITE"Vehicle Body Health:"YELLOW" %.1f/1000.0\n\
			\n\nMasukkan Player ID atau Nama Player untuk memperlihatkan informasi ini kepadanya"LIGHTGREEN" (Input)",
			PlayerVehicle[vehid][pVehID],
			GetVehicleName(PlayerVehicle[vehid][pVehPhysic]),
			PlayerVehicle[vehid][pVehPlate],
			PlayerVehicle[vehid][pVehMaxHealth] > 1000.0 ? ""GREEN"Upgrade" : ""RED"None",
			PlayerVehicle[vehid][pVehBodyUpgraded] ? ""GREEN"Upgrade" : ""RED"None",
			PlayerVehicle[vehid][pVehFuel],
			vHealth,
			PlayerVehicle[vehid][pVehMaxHealth] > 1000.0 ? "2000.0" : "1000.0",
			PlayerVehicle[vehid][pVehHealth]);
			Dialog_Show(playerid, "DetailVehinfo", DIALOG_STYLE_INPUT,
				sprintf(""Nexston"Nexston Roleplay "WHITE"- %s Vehicle Details", AccountData[playerid][pName]),
				strings, "Submit", "Batal");
		}
	}
	return 1;
}