#include <YSI_Coding\y_hooks>

#define MAX_BOMBOM_SLOTS 4

new bool:bombomSlotTaken[MAX_BOMBOM_SLOTS];
new bombomCars[MAX_BOMBOM_SLOTS] = {-1, ...};
new Float:SpawnBomBomCar[MAX_BOMBOM_SLOTS][4] = {
    {386.7448,-2018.1752,7.8359,178.2942},
    {393.6791,-2018.9294,7.8359,177.9182},
    {393.7465,-2041.3865,7.8359,1.1072},
    {386.6870,-2040.6362,7.8359,358.2495}
};

hook OnGameModeInit()
{
    for (new i = 0; i < MAX_BOMBOM_SLOTS; i++)
    {
        bombomCars[i] = INVALID_VEHICLE_ID;
        bombomSlotTaken[i] = false;
    }
    //mappingannya
    new STREAMER_TAG_OBJECT: bombomcar;
    bombomcar = CreateDynamicObject(18766, 394.916931, -2024.204711, 9.320084, 0.000007, 0.000000, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18766, 394.916931, -2034.194824, 9.320084, 0.000007, 0.000000, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(19379, 390.149688, -2037.966064, 6.765934, 0.000000, 90.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-90-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19379, 390.149688, -2028.357421, 6.765934, 0.000000, 90.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-90-percent", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 391.928833, -2043.182861, 7.340081, 0.000000, 90.000045, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 386.929016, -2043.182861, 7.340081, 0.000000, 90.000045, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(19379, 390.149688, -2018.725585, 6.765934, 0.000000, 90.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-90-percent", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2035.472412, 10.812399, 0.000044, 269.999938, 89.999855, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(18766, 394.916931, -2018.842285, 9.320084, 0.000007, 0.000000, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18766, 394.916931, -2038.682861, 9.320084, 0.000007, 0.000000, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 384.918670, -2035.203125, 7.340081, 0.000022, 90.000038, 89.999900, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 384.918670, -2040.182983, 7.340081, 0.000022, 90.000038, 89.999900, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 384.918670, -2030.233154, 7.340078, 0.000022, 90.000038, 89.999900, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 384.918670, -2025.263427, 7.340077, 0.000022, 90.000038, 89.999900, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 384.918670, -2020.281982, 7.340077, 0.000022, 90.000038, 89.999900, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 384.918670, -2016.341552, 7.340077, 0.000022, 90.000038, 89.999900, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 391.918853, -2014.340332, 7.340081, 0.000000, 90.000053, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(18762, 386.919006, -2014.340332, 7.340081, 0.000000, 90.000053, 0.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(19482, 394.399047, -2029.710815, 9.180071, 0.000000, -0.000022, 179.999862, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(bombomcar, 0, "{000000}BOMBOMCAR", 130, "Arial", 88, 1, 0x00000000, 0x00000000, 1);
    bombomcar = CreateDynamicObject(19482, 394.409057, -2029.840942, 9.180071, 0.000000, -0.000022, 179.999862, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(bombomcar, 0, "{ffffff}BOMBOMCAR", 130, "Arial", 88, 1, 0x00000000, 0x00000000, 1);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2035.472412, 10.807762, 89.999992, 538.299133, -88.299072, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2035.472412, 8.912388, 0.000051, 269.999938, 89.999832, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2035.472412, 8.907751, 89.999992, 539.149414, -89.149330, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2035.472412, 7.352400, 0.000067, 269.999938, 89.999786, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2035.472412, 7.347761, 89.999992, 539.787414, -89.787284, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(19482, 394.399047, -2029.710815, 10.090085, 0.000000, -0.000022, 179.999862, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(bombomcar, 0, "{000000}v", 130, "Webdings", 88, 1, 0x00000000, 0x00000000, 1);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2038.994506, 10.244544, 0.000103, 223.299957, 89.999877, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2038.991088, 10.241361, 43.300014, 629.999938, -179.999832, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2037.611694, 8.941480, 0.000119, 223.299957, 89.999877, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2037.608276, 8.938300, 43.299995, 629.999938, -179.999832, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2036.250732, 7.659006, 0.000136, 223.299957, 89.999862, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2036.247436, 7.655825, 43.299995, 630.000000, -179.999816, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2039.803588, 10.170626, 0.000029, 90.600387, 90.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2039.803344, 10.175295, -89.399635, 629.998962, 179.999130, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2039.803588, 10.790641, 0.000045, 90.600387, 89.999954, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2039.803344, 10.795310, -89.399635, 629.997497, 179.997604, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2039.823608, 8.290645, 0.000045, 90.600387, 89.999954, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2039.823364, 8.295314, -89.399635, 629.997497, 179.997604, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.418182, -2039.833618, 7.390632, 0.000098, 90.600387, 89.999794, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.395111, -2039.833374, 7.395313, -89.399635, 629.992370, 179.992263, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2018.536376, 10.812399, 0.000051, 269.999938, 89.999832, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2018.536376, 10.807762, 89.999992, 539.149414, -89.149330, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2018.536376, 8.912388, 0.000059, 269.999938, 89.999809, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2018.536376, 8.907751, 89.999992, 539.574707, -89.574623, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2018.536376, 7.342400, 0.000074, 269.999938, 89.999763, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2018.536376, 7.337761, 89.999992, 539.893798, -89.893623, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2022.058471, 10.244544, 0.000112, 223.299957, 89.999855, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2022.055053, 10.241361, 43.300014, 629.999938, -179.999786, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2020.675659, 8.941480, 0.000127, 223.299957, 89.999855, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2020.672241, 8.938300, 43.299995, 629.999938, -179.999786, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2019.314697, 7.659006, 0.000144, 223.299957, 89.999839, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2019.311401, 7.655825, 43.299995, 630.000000, -179.999771, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2022.867553, 10.170626, 0.000037, 90.600387, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2022.867309, 10.175295, -89.399635, 629.998229, 179.998367, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2022.867553, 10.800642, 0.000052, 90.600387, 89.999931, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2022.867309, 10.805311, -89.399635, 629.996765, 179.996841, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2022.887573, 8.290645, 0.000052, 90.600387, 89.999931, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2022.887329, 8.295314, -89.399635, 629.996765, 179.996841, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2659, 394.428192, -2022.907592, 7.360647, 0.000068, 90.600387, 89.999885, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 18646, "matcolours", "grey-93-percent", 0x00000000);
    bombomcar = CreateDynamicObject(19940, 394.405120, -2022.907348, 7.365316, -89.399635, 629.995300, 179.995315, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(1472, 384.132415, -2025.408813, 7.145937, 0.000000, 0.000000, 270.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 3922, "bistro", "Marble2", 0x00000000);
    bombomcar = CreateDynamicObject(2773, 383.080505, -2026.784790, 7.335931, 0.000000, 0.000000, 90.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2773, 383.080505, -2024.173461, 7.335931, 0.000000, 0.000000, 90.000000, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2037.334106, 6.881886, -89.999992, 89.999992, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2035.833984, 6.881886, -89.999992, 89.999992, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2032.371704, 6.881886, -89.999992, 89.999992, 89.999992, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2030.871582, 6.881886, -89.999992, 89.999992, 89.999992, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2027.149902, 6.881886, -89.999992, 89.999992, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2025.649780, 6.881886, -89.999992, 89.999992, 89.999977, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2022.377929, 6.881886, -89.999992, 90.000000, 89.999969, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2020.877807, 6.881886, -89.999992, 90.000000, 89.999969, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2017.466918, 6.881886, -89.999992, 90.000015, 89.999961, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2015.966796, 6.881886, -89.999992, 90.000015, 89.999961, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2042.187988, 6.881886, -89.999992, 90.000030, 89.999961, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(2656, 389.902221, -2040.687866, 6.881886, -89.999992, 90.000030, 89.999961, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, 19655, "mattubes", "yellowdirt1", 0x00000000);
    bombomcar = CreateDynamicObject(19482, 394.387908, -2029.464843, 11.366887, 0.000029, -0.000014, 179.999786, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(bombomcar, 0, "{F45B26}N", 130, "Arial", 100, 0, 0x00000000, 0x00000000, 1);
    bombomcar = CreateDynamicObject(19482, 394.387908, -2029.875244, 11.236886, 0.000029, -0.000014, 179.999786, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterialText(bombomcar, 0, "{F45B26}S", 130, "Arial", 85, 0, 0x00000000, 0x00000000, 1);
    bombomcar = CreateDynamicObject(2372, 394.522491, -2015.744384, 8.810928, 0.000029, 89.999992, 179.999832, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(2372, 394.522491, -2015.744384, 10.101574, 0.000036, 89.999992, 179.999816, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(2372, 394.522491, -2041.145874, 8.810928, 0.000029, 89.999984, 179.999786, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    bombomcar = CreateDynamicObject(2372, 394.522491, -2041.145874, 10.101574, 0.000036, 89.999984, 179.999771, 0, 0, -1, 300.00, 300.00); 
    SetDynamicObjectMaterial(bombomcar, 0, -1, "none", "none", 0xFFFFFFFF);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bombomcar = CreateDynamicObject(983, 391.269165, -2014.267089, 8.161874, 0.000000, 0.000000, 90.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 388.049072, -2014.267089, 8.161874, 0.000000, 0.000000, 90.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 384.879211, -2017.489990, 8.161874, 0.000007, -0.000014, 179.999862, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 384.879211, -2020.710205, 8.161874, 0.000007, -0.000014, 179.999862, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 384.879211, -2029.941894, 8.161874, 0.000007, -0.000022, 179.999816, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 384.879211, -2033.162109, 8.161874, 0.000007, -0.000022, 179.999816, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 384.879211, -2036.894531, 8.161874, 0.000007, -0.000029, 179.999771, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 384.879211, -2040.114746, 8.161874, 0.000007, -0.000029, 179.999771, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 391.269165, -2043.269775, 8.161874, 0.000007, 0.000000, 89.999977, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(983, 388.049072, -2043.269775, 8.161874, 0.000007, 0.000000, 89.999977, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 380.344573, -2023.189331, 7.360088, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 380.344573, -2026.629394, 7.360088, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 380.344573, -2030.089233, 7.360088, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 380.344573, -2033.549194, 7.360088, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 377.744445, -2023.189331, 7.360088, 0.000000, 0.000007, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 377.744445, -2026.629394, 7.360088, 0.000000, 0.000007, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 377.744445, -2030.089233, 7.360088, 0.000000, 0.000007, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 377.744445, -2033.549194, 7.360088, 0.000000, 0.000007, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 377.744445, -2037.009399, 7.360088, 0.000000, 0.000007, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 379.474456, -2038.690185, 7.360088, 0.000000, 0.000007, 90.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 382.924591, -2038.690185, 7.360088, 0.000000, 0.000007, 90.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2041.254028, 10.432021, 0.000029, -0.000000, 179.999801, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2041.254028, 9.141371, 0.000020, -0.000000, 179.999816, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2015.852539, 10.432021, 0.000029, 0.000006, 179.999847, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2015.852539, 9.141371, 0.000020, 0.000006, 179.999862, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2016.832275, 9.141371, 0.000020, 0.000006, 179.999862, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2016.832275, 10.432021, 0.000029, 0.000006, 179.999847, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2042.233764, 9.141371, 0.000020, -0.000000, 179.999816, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1074, 393.637847, -2042.233764, 10.432021, 0.000029, -0.000000, 179.999801, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(3850, 382.833435, -2019.475585, 7.190087, 0.000000, 0.000000, 113.400001, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1232, 394.905548, -2043.158203, 9.611872, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    bombomcar = CreateDynamicObject(1232, 394.905548, -2014.336669, 9.611872, 0.000000, 0.000000, 0.000000, 0, 0, -1, 300.00, 300.00); 
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if ((newkeys & KEY_YES) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
    {
        if (IsPlayerInRangeOfPoint(playerid, 3.5, 379.7550, -2020.6007, 7.8301))
        {
            new dialogStr[512];
            format(dialogStr, sizeof(dialogStr), "Slot\tStatus\tHarga\n");

            for (new i = 0; i < MAX_BOMBOM_SLOTS; i++)
            {
                format(dialogStr, sizeof(dialogStr), "%sSlot %d\t%s\t{16a621}$500\n", dialogStr, i + 1, bombomSlotTaken[i] ? "{ff0000}Dipakai" : "{00ff00}Tersedia"
                );
            }

            Dialog_Show(playerid, "bombomCars", DIALOG_STYLE_TABLIST_HEADERS, ""Nexston"Nexston Roleplay "WHITE"- Bombomcar", dialogStr, "Pilih", "Batal");
        }
    }
    return 1;
}


Dialog:bombomCars(playerid, response, listitem, inputtext[])
{
    if (!response) return 1;

    if (listitem >= 0 && listitem < MAX_BOMBOM_SLOTS)
    {
        if(AccountData[playerid][pMoney] < 500) 
            return ShowTDN(playerid, NOTIFICATION_ERROR, "Anda tidak memuliki cukup uang! ($500)");
        if (bombomSlotTaken[listitem])
        {
            ShowTDN(playerid, NOTIFICATION_ERROR, "Slot ini sedang dipakai!");
            return 1;
        }

        new Float:x = SpawnBomBomCar[listitem][0];
        new Float:y = SpawnBomBomCar[listitem][1];
        new Float:z = SpawnBomBomCar[listitem][2] + 0.3;
        new Float:a = SpawnBomBomCar[listitem][3];

        new vehicleid = CreateVehicle(571, x, y, z, a, 0, 0, 0);

        bombomCars[listitem] = vehicleid;
        bombomSlotTaken[listitem] = true;

        SetTimerEx("PutPlayerInBombomCar", 300, false, "ii", playerid, vehicleid);

        SetPVarInt(playerid, "BombomSlot", listitem);
        SetPVarInt(playerid, "BombomVehID", vehicleid);

        VehicleCore[vehicleid][vCoreFuel] = 100;
        VehicleCore[vehicleid][vMaxHealth] = 1000.0;
        VehicleCore[vehicleid][vIsBodyUpgraded] = false;
        VehicleCore[vehicleid][vIsBodyBroken] = false;
        VehicleCore[vehicleid][vCoreLocked] = false;
        SetValidVehicleHealth(vehicleid, 1000.0);

        SwitchVehicleEngine(vehicleid, true);
        SwitchVehicleDoors(vehicleid, false);
        TakePlayerMoneyEx(playerid, 500);
    }
    return 1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    for (new i = 0; i < MAX_BOMBOM_SLOTS; i++)
    {
        if (vehicleid == bombomCars[i])
        {
            DestroyVehicle(vehicleid);
            bombomCars[i] = INVALID_VEHICLE_ID;
            bombomSlotTaken[i] = false;

            DeletePVar(playerid, "BombomSlot");
            DeletePVar(playerid, "BombomVehID");

            ShowTDN(playerid, NOTIFICATION_INFO, "Kamu keluar dari Bombom Car. Kendaraan telah dihapus.");
            break;
        }
    }
    return 1;
}

forward PutPlayerInBombomCar(playerid, vehicleid);
public PutPlayerInBombomCar(playerid, vehicleid)
{
    PutPlayerInVehicleEx(playerid, vehicleid, 0);
    return 1;
}