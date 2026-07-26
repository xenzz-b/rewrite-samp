#include <YSI_Coding\y_hooks>

#define MAX_TWEET_SLOTS     5
#define TWEET_SLOT_HEIGHT   35.0   // jarak antar slot, sesuaikan kalau kurang pas
#define TWEET_MAX_CHARS     38     // max karakter per baris sebelum wrap

new PlayerText:TwitterUIList[MAX_PLAYERS][MAX_TWEET_SLOTS][7];

stock HideTwitterUIList(playerid)
{
    for(new i = 0; i < MAX_TWEET_SLOTS; i++)
        for(new j = 0; j < 7; j++)
            PlayerTextDrawHide(playerid, TwitterUIList[playerid][i][j]);
}

stock ShowTwitterList(playerid, i) {
    for(new j = 0; j < 5; j++) {
        PlayerTextDrawShow(playerid, TwitterUIList[playerid][i][j]);
    }
}

stock CreateTwitterUIList(playerid)
{
    for(new idx = 0; idx < MAX_TWEET_SLOTS; idx++)
    {
        new Float:y = (idx * TWEET_SLOT_HEIGHT);

        TwitterUIList[playerid][idx][0] = CreatePlayerTextDraw(playerid, 510.500, 149.500 + y, "LD_SPAC:white");
        PlayerTextDrawTextSize(playerid, TwitterUIList[playerid][idx][0], 107.000, 34.000);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][0], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][0], 960314879);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][0], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][0], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][0], 255);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][0], 4);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][0], 1);
        PlayerTextDrawSetSelectable(playerid, TwitterUIList[playerid][idx][0], 1);

        TwitterUIList[playerid][idx][1] = CreatePlayerTextDraw(playerid, 509.000, 148.000 + y, "LD_BEAT:chit");
        PlayerTextDrawTextSize(playerid, TwitterUIList[playerid][idx][1], 21.000, 24.000);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][1], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][1], 539305471);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][1], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][1], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][1], 255);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][1], 4);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][1], 1);

        TwitterUIList[playerid][idx][2] = CreatePlayerTextDraw(playerid, 515.000, 155.000 + y, "HUD:radar_gangB");
        PlayerTextDrawTextSize(playerid, TwitterUIList[playerid][idx][2], 8.000, 9.000);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][2], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][2], 255);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][2], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][2], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][2], 255);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][2], 4);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][2], 1);

        TwitterUIList[playerid][idx][3] = CreatePlayerTextDraw(playerid, 512.000, 176.000 + y, "Ronnie Varquez");
        PlayerTextDrawLetterSize(playerid, TwitterUIList[playerid][idx][3], 0.109, 0.598);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][3], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][3], -1448498689);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][3], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][3], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][3], 150);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][3], 1);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][3], 1);

        TwitterUIList[playerid][idx][4] = CreatePlayerTextDraw(playerid, 530.000, 153.000 + y, "biasa di sebut negara konoha");
        PlayerTextDrawLetterSize(playerid, TwitterUIList[playerid][idx][4], 0.119, 0.799);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][4], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][4], -1);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][4], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][4], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][4], 150);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][4], 1);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][4], 1);

        TwitterUIList[playerid][idx][5] = CreatePlayerTextDraw(playerid, 530.000, 159.000+ y, "aku ingin cerita ada sebuah negara yang");
        PlayerTextDrawLetterSize(playerid, TwitterUIList[playerid][idx][5], 0.119, 0.799);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][5], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][5], -1);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][5], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][5], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][5], 150);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][5], 1);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][5], 1);

        TwitterUIList[playerid][idx][6] = CreatePlayerTextDraw(playerid, 530.000, 165.000+ y, "gila akan kekuasaan, dan rakus sangat");
        PlayerTextDrawLetterSize(playerid, TwitterUIList[playerid][idx][6], 0.119, 0.799);
        PlayerTextDrawAlignment(playerid, TwitterUIList[playerid][idx][6], 1);
        PlayerTextDrawColor(playerid, TwitterUIList[playerid][idx][6], -1);
        PlayerTextDrawSetShadow(playerid, TwitterUIList[playerid][idx][6], 0);
        PlayerTextDrawSetOutline(playerid, TwitterUIList[playerid][idx][6], 0);
        PlayerTextDrawBackgroundColor(playerid, TwitterUIList[playerid][idx][6], 150);
        PlayerTextDrawFont(playerid, TwitterUIList[playerid][idx][6], 1);
        PlayerTextDrawSetProportional(playerid, TwitterUIList[playerid][idx][6], 1);
    }
}

stock PhoneSyncTwitterUI(playerid)
{
    mysql_tquery(g_SQL, "SELECT * FROM `tweets` ORDER BY `ID` DESC LIMIT 5;", "OnSyncTwitterUI", "d", playerid);
    return 1;
}

forward OnSyncTwitterUI(playerid);
public OnSyncTwitterUI(playerid)
{
    for(new i = 0; i < MAX_TWEET_SLOTS; i++) 
    {
        for(new j = 0; j < 7; j++) 
        {
            PlayerTextDrawHide(playerid, TwitterUIList[playerid][i][j]);
        }
    }
    
    new rows = cache_num_rows();
    if(rows == 0) return 1;
    
    new startIndex = (rows > MAX_TWEET_SLOTS) ? (rows - MAX_TWEET_SLOTS) : 0;
    new displayCount = (rows > MAX_TWEET_SLOTS) ? MAX_TWEET_SLOTS : rows;
    
    for(new slot = 0; slot < displayCount; slot++)
    {
        new dataIndex = startIndex + slot;
        new tweetName[24], tweetMsg[128], tweetID;
        
        cache_get_value_name_int(dataIndex, "ID", tweetID);
        cache_get_value_name(dataIndex, "TweetFrom", tweetName, sizeof(tweetName));
        cache_get_value_name(dataIndex, "TweetMessage", tweetMsg, sizeof(tweetMsg));
        
        if(tweetID == 0) continue;
        
        for(new j = 0; j < 5; j++) 
        {
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][j]);
        }
        
        PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][3], tweetName);
        
        new len = strlen(tweetMsg);
        if(len <= TWEET_MAX_CHARS)
        {
            PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][4], tweetMsg);
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][4]);
            PlayerTextDrawHide(playerid, TwitterUIList[playerid][slot][5]);
            PlayerTextDrawHide(playerid, TwitterUIList[playerid][slot][6]);
        }
        else if(len <= TWEET_MAX_CHARS * 2)
        {
            new b1[40], b2[40];
            strmid(b1, tweetMsg, 0, TWEET_MAX_CHARS, sizeof(b1));
            strmid(b2, tweetMsg, TWEET_MAX_CHARS, len, sizeof(b2));
            PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][4], b1);
            PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][5], b2);
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][4]);
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][5]);
            PlayerTextDrawHide(playerid, TwitterUIList[playerid][slot][6]);
        }
        else
        {
            new b1[40], b2[40], b3[50];
            strmid(b1, tweetMsg, 0, TWEET_MAX_CHARS, sizeof(b1));
            strmid(b2, tweetMsg, TWEET_MAX_CHARS, TWEET_MAX_CHARS * 2, sizeof(b2));
            strmid(b3, tweetMsg, TWEET_MAX_CHARS * 2, len, sizeof(b3));
            if(strlen(b3) > TWEET_MAX_CHARS)
            {
                strmid(b3, b3, 0, TWEET_MAX_CHARS - 3, sizeof(b3));
                strcat(b3, "...");
            }
            PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][4], b1);
            PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][5], b2);
            PlayerTextDrawSetString(playerid, TwitterUIList[playerid][slot][6], b3);
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][4]);
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][5]);
            PlayerTextDrawShow(playerid, TwitterUIList[playerid][slot][6]);
        }
    }
    
    for(new slot = displayCount; slot < MAX_TWEET_SLOTS; slot++)
    {
        for(new j = 0; j < 7; j++) 
        {
            PlayerTextDrawHide(playerid, TwitterUIList[playerid][slot][j]);
        }
    }
    
    return 1;
}

// ============================================================
//  HOOKS
// ============================================================

hook OnPlayerConnect(playerid)
{
    CreateTwitterUIList(playerid);
    pageTwitter[playerid] = 0;
}

hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(playertextid == LoginTwittVRP[playerid][23]) //login twitt
    {
        Dialog_Show(playerid, "TwitterRegister", DIALOG_STYLE_INPUT, 
        ""Vertex"Vertex Roleplay "WHITE"- Daftar Twitter", 
        "Hai, selamat datang di Twitter!\n\
        Silakan masukkan username Twitter kamu, ini akan ditampilkan pada setiap tweet yang kamu buat:\n\
        Ingat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!\n\
        Panjang username 7 - 24 karakter!", "Set", "Batal");
    }
    else if(playertextid == LoginTwittVRP[playerid][22]) //register twitt
    {
        Dialog_Show(playerid, "TwitterLogin", DIALOG_STYLE_INPUT, 
        ""Vertex"Vertex Roleplay "WHITE"- Login Twitter", 
        "Hai, selamat datang di Twitter!\n\
        Silakan masukkan username Twitter kamu yang telah terdaftar:", "Input", "Batal");
    }
    else if(playertextid == LoginTwittVRP[playerid][15]) //close 
    {
        HideTwitterTD(playerid);
        HideTwitterUIList(playerid);
        ShowPhoneVRP(playerid);
    }
    else if(playertextid == HomeTwittVRP[playerid][23]) //post tweet
    {
        Dialog_Show(playerid, "TwitterTweeting", DIALOG_STYLE_INPUT,
        ""Vertex"Vertex Roleplay "WHITE"- Twitter",
        "Silahkan masukkan tweet yang ingin kamu buat:", "Tweet", "Batal");
    }
    else if(playertextid == HomeTwittVRP[playerid][27]) //logout
    {
        new sqlfstr[128];
        PlayerPhoneData[playerid][IsTwitterLoggedIn] = 0;
        mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `TwitterLoggedIn`=0 WHERE `phoneOwner`=%d", AccountData[playerid][pID]);
        mysql_pquery(g_SQL, sqlfstr);
        PlayerPhoneData[playerid][CurrentlyReadTweet] = false;
        HideTwitterTD(playerid);
        HideTwitterUIList(playerid);
        ShowTwitterLoginTD(playerid);
    }
    else if(playertextid == HomeTwittVRP[playerid][15]) //close 
    {
        HideTwitterTD(playerid);
        HideTwitterUIList(playerid);
        ShowPhoneVRP(playerid);
    }   
    return 1;
}