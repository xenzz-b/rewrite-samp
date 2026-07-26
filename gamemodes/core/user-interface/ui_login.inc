#include <YSI_Coding\y_hooks>

// Dialog login pengganti textdraw. err[] opsional untuk pesan kesalahan.
ShowLoginDialog(playerid, const err[] = "")
{
	static lgstr[512];

	if(err[0])
	{
		format(lgstr, sizeof(lgstr), "Username "Vertex"%s "WHITE"Terdaftar.\n"RED"%s\n\n"WHITE"Silakan masukkan kata sandi untuk login:", AccountData[playerid][pUCP], err);
	}
	else
	{
		format(lgstr, sizeof(lgstr), "Username "Vertex"%s "WHITE"Terdaftar.\n\nSilakan masukkan kata sandi untuk login:", AccountData[playerid][pUCP]);
	}

	Dialog_Show(playerid, "Login", DIALOG_STYLE_PASSWORD, "UCP - Login", lgstr, "Login", "Quit");
	return 1;
}
