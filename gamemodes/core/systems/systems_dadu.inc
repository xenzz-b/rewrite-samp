//----- Dadu System -----
#include <YSI_Coding\y_hooks>

#if defined _systems_dadu_included_
    #endinput
#endif
#define _systems_dadu_included_

#define DIALOG_DADU_INVITE 5050

#define DADU_MIN_TARUHAN 100
#define DADU_MAX_TARUHAN 1000000

enum DADU_DATA
{
    bool:DaduOfferActive,
    DaduInviter,
    DaduTarget,
    DaduTaruhan,
    DaduTimer
}

static g_DaduData[MAX_PLAYERS][DADU_DATA];

forward OnDaduTimeout(playerid);
forward OnDaduPlay(playerid, targetid, taruhan, angka1, angka2);

hook OnPlayerConnect(playerid)
{
    ResetDaduOffer(playerid);
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if(g_DaduData[playerid][DaduOfferActive])
    {
        new target = g_DaduData[playerid][DaduTarget];
        if(IsPlayerConnected(target))
        {
            ShowTDN(target, NOTIFICATION_ERROR, "Lawan main anda disconnect, dadu dibatalkan");
            ResetDaduOffer(target);
        }
    }
    
    new inviter = g_DaduData[playerid][DaduInviter];
    if(IsPlayerConnected(inviter) && g_DaduData[inviter][DaduOfferActive])
    {
        ShowTDN(inviter, NOTIFICATION_ERROR, "Target disconnect, dadu dibatalkan");
        ResetDaduOffer(inviter);
    }
    
    ResetDaduOffer(playerid);
    return 1;
}

//----- Reset Dadu Offer -----
ResetDaduOffer(playerid)
{
    if(!IsPlayerConnected(playerid)) return;
    
    g_DaduData[playerid][DaduOfferActive] = false;
    g_DaduData[playerid][DaduInviter] = -1;
    g_DaduData[playerid][DaduTarget] = -1;
    g_DaduData[playerid][DaduTaruhan] = 0;
    
    if(g_DaduData[playerid][DaduTimer] != -1)
    {
        KillTimer(g_DaduData[playerid][DaduTimer]);
        g_DaduData[playerid][DaduTimer] = -1;
    }
}

//----- Kirim Notif ke Player Sekitar Kordinat Dadu -----
SendNearbyMessageDadu(Float:x, Float:y, Float:z, color, const message[])
{
    foreach(new i : Player)
    {
        if(IsPlayerInRangeOfPoint(i, 50.0, x, y, z))
        {
            SendClientMessage(i, color, message);
        }
    }
}

//----- Timeout Dadu -----
public OnDaduTimeout(playerid)
{
    if(!IsPlayerConnected(playerid)) return;
    
    if(g_DaduData[playerid][DaduOfferActive])
    {
        new target = g_DaduData[playerid][DaduTarget];
        if(IsPlayerConnected(target))
        {
            ShowTDN(target, NOTIFICATION_ERROR, "Ajakan dadu telah kadaluarsa");
            ResetDaduOffer(target);
        }
        ShowTDN(playerid, NOTIFICATION_ERROR, "Ajakan dadu anda telah kadaluarsa");
        ResetDaduOffer(playerid);
    }
}

//----- Eksekusi Main Dadu -----
public OnDaduPlay(playerid, targetid, taruhan, angka1, angka2)
{
    new msg[128];
    new Float:x, Float:y, Float:z;
    GetPlayerPos(playerid, x, y, z);
    
    if(angka1 > angka2)
    {
        GivePlayerMoneyEx(playerid, taruhan);
        GivePlayerMoneyEx(targetid, -taruhan);
        
        format(msg, sizeof(msg), ""YELLOW"%s "WHITE"menang dadu melawan "YELLOW"%s "WHITE"dengan taruhan "GREEN"%s", 
            ReturnName(playerid), ReturnName(targetid), FormatMoney(taruhan));
        SendNearbyMessageDadu(x, y, z, -1, msg);
    }
    else if(angka2 > angka1)
    {
        GivePlayerMoneyEx(targetid, taruhan);
        GivePlayerMoneyEx(playerid, -taruhan);
        
        format(msg, sizeof(msg), ""YELLOW"%s "WHITE"menang dadu melawan "YELLOW"%s "WHITE"dengan taruhan "GREEN"%s", 
            ReturnName(targetid), ReturnName(playerid), FormatMoney(taruhan));
        SendNearbyMessageDadu(x, y, z, -1, msg);
    }
    else
    {
        format(msg, sizeof(msg), ""YELLOW"%s "WHITE"dan "YELLOW"%s "WHITE"dadu seri, uang "GREEN"%s "WHITE"dikembalikan", 
            ReturnName(playerid), ReturnName(targetid), FormatMoney(taruhan));
        SendNearbyMessageDadu(x, y, z, -1, msg);
    }
    
    ResetDaduOffer(playerid);
    ResetDaduOffer(targetid);
}

//----- Dialog Terima/Tolak -----
Dialog:DaduInvite(playerid, response, listitem, inputtext[])
{
    if(!response)
    {
        new inviter = g_DaduData[playerid][DaduInviter];
        if(IsPlayerConnected(inviter))
        {
            ShowTDN(inviter, NOTIFICATION_ERROR, "Target menolak ajakan dadu");
            ResetDaduOffer(inviter);
        }
        ResetDaduOffer(playerid);
        return 1;
    }
    
    new inviter = g_DaduData[playerid][DaduInviter];
    if(!IsPlayerConnected(inviter))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Pengundang sudah disconnect");
        ResetDaduOffer(playerid);
        return 1;
    }
    
    if(!IsPlayerNearPlayer(playerid, inviter, 5.0))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Jarak dengan pengundang terlalu jauh");
        ShowTDN(inviter, NOTIFICATION_ERROR, "Target terlalu jauh, dadu dibatalkan");
        ResetDaduOffer(inviter);
        ResetDaduOffer(playerid);
        return 1;
    }
    
    new taruhan = g_DaduData[inviter][DaduTaruhan];
    
    if(GetPlayerMoney(playerid) < taruhan)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Uang anda tidak cukup untuk taruhan ini");
        ShowTDN(inviter, NOTIFICATION_ERROR, "Target tidak memiliki cukup uang");
        ResetDaduOffer(inviter);
        ResetDaduOffer(playerid);
        return 1;
    }
    
    if(GetPlayerMoney(inviter) < taruhan)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Pengundang tidak memiliki cukup uang");
        ShowTDN(inviter, NOTIFICATION_ERROR, "Uang anda tidak cukup untuk taruhan ini");
        ResetDaduOffer(inviter);
        ResetDaduOffer(playerid);
        return 1;
    }
    new angkaInviter = random(6) + 1;
    new angkaTarget = random(6) + 1;
    
    new msg[128];
    new Float:x, Float:y, Float:z;
    GetPlayerPos(inviter, x, y, z);
    
    format(msg, sizeof(msg), ""YELLOW"%s "WHITE"mendapat angka "YELLOW"%d "WHITE"dan "YELLOW"%s "WHITE"mendapat angka "YELLOW"%d", ReturnName(inviter), angkaInviter, ReturnName(playerid), angkaTarget);
    SendNearbyMessageDadu(x, y, z, -1, msg);
    
    OnDaduPlay(inviter, playerid, taruhan, angkaInviter, angkaTarget);
    
    return 1;
}

//----- Command Dadu YCMD -----
YCMD:dadu(playerid, params[], help)
{
    if(help)
    {
        SUM(playerid, "/dadu [playerid] [taruhan]");
        return 1;
    }
    
    if(!IsPlayerInRangeOfPoint(playerid, 50.0, 380.7771, -2026.2224, 7.8359))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Kamu harus berada di area daduan");
        return 1;
    }
    
    new targetid, taruhan;
    if(sscanf(params, "ui", targetid, taruhan))
    {
        SUM(playerid, "/dadu [playerid] [taruhan]");
        return 1;
    }
    
    if(!IsPlayerConnected(targetid))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Player tidak ditemukan");
        return 1;
    }
    
    if(targetid == playerid)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Tidak bisa mengajak diri sendiri");
        return 1;
    }
    
    if(taruhan < DADU_MIN_TARUHAN || taruhan > DADU_MAX_TARUHAN)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Taruhan minimal 100 dan maksimal 1.000.000");
        return 1;
    }
    
    if(GetPlayerMoney(playerid) < taruhan)
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Uang kamu tidak cukup");
        return 1;
    }
    
    if(!IsPlayerNearPlayer(playerid, targetid, 5.0))
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Target terlalu jauh");
        return 1;
    }
    
    if(g_DaduData[targetid][DaduOfferActive])
    {
        ShowTDN(playerid, NOTIFICATION_ERROR, "Player sedang dalam ajakan dadu");
        return 1;
    }
    
    // Setup data
    g_DaduData[playerid][DaduOfferActive] = true;
    g_DaduData[playerid][DaduTarget] = targetid;
    g_DaduData[playerid][DaduTaruhan] = taruhan;
    g_DaduData[playerid][DaduTimer] = SetTimerEx("OnDaduTimeout", 30000, false, "i", playerid);
    
    g_DaduData[targetid][DaduOfferActive] = true;
    g_DaduData[targetid][DaduInviter] = playerid;
    g_DaduData[targetid][DaduTarget] = playerid;
    g_DaduData[targetid][DaduTaruhan] = taruhan;
    g_DaduData[targetid][DaduTimer] = SetTimerEx("OnDaduTimeout", 30000, false, "i", targetid);
    
    new msg[256];
    format(msg, sizeof(msg), "%s (%d) mengajak anda bermain dadu dengan taruhan %s\n\nTekan Terima untuk menerima atau Tolak untuk menolak", ReturnName(playerid), playerid, FormatMoney(taruhan));
    
    Dialog_Show(targetid, "DaduInvite", DIALOG_STYLE_MSGBOX, "Ajakan Bermain Dadu", msg, "Terima", "Tolak");
    
    ShowTDN(playerid, NOTIFICATION_SUCCESS, sprintf("Ajakan dadu ke %s (%d) dengan taruhan %s telah dikirim", ReturnName(targetid), targetid, FormatMoney(taruhan)));
    
    return 1;
}