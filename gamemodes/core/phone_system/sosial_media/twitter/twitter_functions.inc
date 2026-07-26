#include <YSI_Coding\y_hooks>

forward OnTwitterRegister(playerid, const userinput[]);
public OnTwitterRegister(playerid, const userinput[])
{
    if(cache_num_rows() > 0)
    {
        Dialog_Show(playerid, "TwitterRegister", DIALOG_STYLE_INPUT, 
        ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", 
        "Mohon maaf, username tersebut sudah terdaftar!\n\
        Silakan masukkan username Twitter kamu, ini akan ditampilkan pada setiap tweet yang kamu buat:\n\
        Ingat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!", "Set", "Batal");
        return 1;
    }
    else
    {
        new strtwt[150];
        mysql_format(g_SQL, strtwt, sizeof(strtwt), "INSERT INTO `player_twitter` SET `OwnerID`=%d, `Username`='%e'", AccountData[playerid][pID], userinput);
        mysql_pquery(g_SQL, strtwt, "OnTwitterUsernameSuccess", "is", playerid, userinput);
    }
    return 1;
}

forward OnTwitterUsernameSuccess(playerid, const usersuccs[]);
public OnTwitterUsernameSuccess(playerid, const usersuccs[])
{
    new jjstr[250];
    format(jjstr, sizeof(jjstr), 
    "Hai, %s!\n\
    Silakan masukkan kata sandi untuk akun twitter kamu:\n\
    Ingat: Panjang kata sandi 7 - 32 karakter!\n\
    Tahap ini tidak dapat dibatalkan!", usersuccs);
    Dialog_Show(playerid, "TwitterRegPassword", DIALOG_STYLE_PASSWORD, ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", jjstr, "Set", "");
    return 1;
}

forward OnTwitterFinishRegister(playerid);
public OnTwitterFinishRegister(playerid)
{
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil mendaftarkan akun Twitter, silakan login!");
    return 1;
}

forward OnTwitterLogin(playerid, const checkuser[]);
public OnTwitterLogin(playerid, const checkuser[])
{
    if(cache_num_rows() > 0)
    {
        new ljstr[250];
        format(ljstr, sizeof(ljstr), "Hai, %s!\n\
        Silakan masukkan kata sandi akun Twitter kamu untuk masuk:", checkuser);
        Dialog_Show(playerid, "TwitterLoginPassword", DIALOG_STYLE_PASSWORD, 
        ""Nexston"Nexston Roleplay "WHITE"- Login Twitter", ljstr, "Login", "Batal");
        return 1;
    }
    else
    {
        Dialog_Show(playerid, "TwitterLogin", DIALOG_STYLE_INPUT, 
        ""Nexston"Nexston Roleplay "WHITE"- Login Twitter", 
        "Mohon maaf kami tidak dapat menemukan akun Twitter kamu!\n\
        Silakan masukkan username Twitter kamu yang telah terdaftar:", "Input", "Batal");
    }
    return 1;
}

Dialog:TwitterRegister(playerid, response, listitem, inputtext[])
{
    new sqlfstr[128];
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(isnull(inputtext))
    {
        Dialog_Show(playerid, "TwitterRegister", DIALOG_STYLE_INPUT, 
        ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", 
        "Username Tidak dapat dikosongkan!\n\
        Silakan masukkan username Twitter kamu, ini akan ditampilkan pada setiap tweet yang kamu buat:\n\
        Ingat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!\n\
        Panjang username 7 - 24 karakter!", "Set", "Batal");
        return 1;
    }

    if(strlen(inputtext) < 7 || strlen(inputtext) > 24)
    {
        Dialog_Show(playerid, "TwitterRegister", DIALOG_STYLE_INPUT, 
        ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", 
        "Username Tidak dapat dikosongkan!\n\
        Silakan masukkan username Twitter kamu, ini akan ditampilkan pada setiap tweet yang kamu buat:\n\
        Ingat: Username hanya dapat berupa huruf dan angka, tidak menggunakan simbol!\n\
        Panjang username 7 - 24 karakter!", "Set", "Batal");
        return 1;
    }

    strcopy(TwitterData[playerid][TempUsername], inputtext);
    mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "SELECT * FROM `player_twitter` WHERE `Username`='%e'", TwitterData[playerid][TempUsername]);
    mysql_pquery(g_SQL, sqlfstr, "OnTwitterRegister", "is", playerid, TwitterData[playerid][TempUsername]);
    return 1;
}
Dialog:TwitterRegPassword(playerid, response, listitem, inputtext[])
{
    new sqlfstr[250];
    if(!response)
    {
        format(sqlfstr, sizeof(sqlfstr), "Hai, %s!\n\
        Silakan masukkan kata sandi untuk akun twitter kamu:\n\
        Ingat: Panjang kata sandi 7 - 32 karakter!\n\
        Tahap ini tidak dapat dibatalkan!", TwitterData[playerid][TempUsername]);
        Dialog_Show(playerid, "TwitterRegPassword", DIALOG_STYLE_PASSWORD, 
        ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", sqlfstr, "Set", "");
        return 1;
    }

    if(isnull(inputtext))
    {
        Dialog_Show(playerid, "TwitterRegPassword", DIALOG_STYLE_PASSWORD, 
        ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", 
        "Kata sandi Tidak dapat dikosongkan!\n\
        Silakan masukkan kata sandi untuk akun twitter kamu:\n\
        Ingat: Panjang kata sandi 7 - 32 karakter!\n\
        Tahap ini tidak dapat dibatalkan!", "Set", "");
        return 1;
    }

    if(strlen(inputtext) < 7 || strlen(inputtext) > 32)
    {
        Dialog_Show(playerid, "TwitterRegPassword", DIALOG_STYLE_PASSWORD, 
        ""Nexston"Nexston Roleplay "WHITE"- Daftar Twitter", 
        "Panjang kata sandi kurang atau kelebihan!\n\
        Silakan masukkan kata sandi untuk akun twitter kamu:\n\
        Ingat: Panjang kata sandi 7 - 32 karakter!\n\
        Tahap ini tidak dapat dibatalkan!", "Set", "");
        return 1;
    }

    strcopy(TwitterData[playerid][TempPassword], inputtext);
    mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_twitter` SET `Password`='%e' WHERE `Username`='%e'", TwitterData[playerid][TempPassword], TwitterData[playerid][TempUsername]);
    mysql_pquery(g_SQL, sqlfstr, "OnTwitterFinishRegister", "i", playerid);
    return 1;
}
Dialog:TwitterLogin(playerid, response, listitem, inputtext[])
{
    new sqlfstr[128];
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");
    strcopy(TwitterData[playerid][TempUsername], inputtext);
    mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "SELECT * FROM `player_twitter` WHERE `Username`='%e'", TwitterData[playerid][TempUsername]);
    mysql_pquery(g_SQL, sqlfstr, "OnTwitterLogin", "is", playerid, TwitterData[playerid][TempUsername]);
    return 1;
}
Dialog:TwitterLoginPassword(playerid, response, listitem, inputtext[])
{
    new sqlfstr[128], twdbid;
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    strcopy(TwitterData[playerid][TempPassword], inputtext);
    mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "SELECT * FROM `player_twitter` WHERE `Username`='%e' AND `Password`='%e'", TwitterData[playerid][TempUsername], TwitterData[playerid][TempPassword]);
    mysql_query(g_SQL, sqlfstr);
    new rows = cache_num_rows();
    if(rows)
    {
        cache_get_value_name_int(0, "ID", twdbid);
        cache_get_value_name(0, "Username", TwitterData[playerid][Username]);
        PlayerPhoneData[playerid][IsTwitterLoggedIn] = twdbid;
        mysql_format(g_SQL, sqlfstr, sizeof(sqlfstr), "UPDATE `player_phones` SET `TwitterLoggedIn`=%d WHERE `phoneOwner`=%d", twdbid, AccountData[playerid][pID]);
        mysql_pquery(g_SQL, sqlfstr);
        HideTwitterTD(playerid);
        ShowTwitterMainTD(playerid);
    }
    else
    {
        new ljstr[250];
        format(ljstr, sizeof(ljstr), "Hai, %s!\n\
        Kata sandi yang kamu masukkan salah!\n\
        Silakan masukkan kata sandi akun Twitter kamu untuk masuk:", TwitterData[playerid][TempUsername]);
        Dialog_Show(playerid, "TwitterLoginPassword", DIALOG_STYLE_PASSWORD, 
        ""Nexston"Nexston Roleplay "WHITE"- Login Twitter", ljstr, "Login", "Batal");
    }
    return 1;
}
Dialog:TwitterTweeting(playerid, response, listitem, inputtext[])
{
    if(!response) return ShowTDN(playerid, NOTIFICATION_INFO, "Anda telah membatalkan pilihan!");

    if(isnull(inputtext))
        return Dialog_Show(playerid, "TwitterTweeting", DIALOG_STYLE_INPUT, ""Nexston"Nexston Roleplay "WHITE"- Twitter",
        "Tweet tidak boleh dikosongkan!\nSilahkan masukkan tweet yang ingin kamu buat:", "Tweet", "Batal");

    if(strlen(inputtext) > 128)
        return Dialog_Show(playerid, "TwitterTweeting", DIALOG_STYLE_INPUT, ""Nexston"Nexston Roleplay "WHITE"- Twitter",
        "Tweet maksimal 128 karakter!\nSilahkan masukkan tweet yang ingin kamu buat:", "Tweet", "Batal");

    if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "#", true) != -1)
        return Dialog_Show(playerid, "TwitterTweeting", DIALOG_STYLE_INPUT, ""Nexston"Nexston Roleplay "WHITE"- Twitter",
        "Tweet tidak boleh mengandung simbol % atau #!\nSilahkan masukkan tweet yang ingin kamu buat:", "Tweet", "Batal");

    strcopy(TwitterData[playerid][Tweet], inputtext);

    new biaya = strlen(TwitterData[playerid][Tweet]) * 2;
    AccountData[playerid][pBankMoney] -= biaya;

    new fhstr[250];
    mysql_format(g_SQL, fhstr, sizeof(fhstr),
        "INSERT INTO `tweets` SET `TweetFrom`='%e', `TweetMessage`='%e', `TweetDate`='%e'",
        TwitterData[playerid][Username], TwitterData[playerid][Tweet], GetSimpleTime());
    mysql_pquery(g_SQL, fhstr, "OnPlayerTweetUI", "i", playerid);
    return 1;
}

forward OnPlayerTweetUI(playerid);
public OnPlayerTweetUI(playerid)
{
    ShowTDN(playerid, NOTIFICATION_SUCCESS, "Anda berhasil membuat sebuah tweet!");
    PhoneSyncTwitterUI(playerid);
    
    foreach(new i : Player)
    {
        if(i != playerid && PlayerPhoneData[i][CurrentlyReadTweet])
        {
            pageTwitter[i] = 0;
            PhoneSyncTwitterUI(i);
        }
    }
    
    return 1;
}