#include <YSI_Coding\y_hooks>

FormatRibuan(output[], len, const input[])
{
    new num = strval(input);
    new str[32];
    format(str, sizeof(str), "%d", num);
    new slen = strlen(str);
    new pos = 0;
    new result[32];
    new mod = slen % 3;
    for (new i = 0; i < slen; i++)
    {
        if (i != 0 && (i % 3) == mod)
        {
            result[pos++] = '.';
        }
        result[pos++] = str[i];
    }
    result[pos] = '\0';
    format(output, len, "%s", result);
}

FormatHasil(output[], len, Float:result)
{
    new Float:frac = result - float(floatround(result, floatround_floor));
    if (frac == 0.0)
    {
        new str[32];
        format(str, sizeof(str), "%d", floatround(result, floatround_floor));
        FormatRibuan(output, len, str);
    }
    else
    {
        format(output, len, "%.2f", result);
    }
}

GetOperatorChar(playerid)
{
    new str[64];
    strcopy(str, CalcInput[playerid], sizeof(str));
    new len = strlen(str);
    for (new i = len - 1; i >= 0; i--)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            return str[i];
    }
    return 0;
}

Float:EvaluateExpression(const expression[])
{
    new Float:num1, Float:num2;
    new op;
    new index = 0;
    while (expression[index] >= '0' && expression[index] <= '9')
    {
        num1 = num1 * 10 + float(expression[index] - '0');
        index++;
    }
    op = expression[index];
    index++;
    while (expression[index] >= '0' && expression[index] <= '9')
    {
        num2 = num2 * 10 + float(expression[index] - '0');
        index++;
    }
    switch (op)
    {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/':
        {
            if (num2 == 0.0) return 0.0;
            return num1 / num2;
        }
    }
    return 0.0;
}

HandleKalkulatorInput(playerid, PlayerText:playertextid)
{
    new text[64];
    new displayBesar[32];
    new displayKecil[64];

    for (new i = 27; i <= 36; i++)
    {
        if (playertextid == KalkulatorVRP[playerid][i])
        {
            new digit = i - 27;

            if (!CalcHasOperator[playerid])
            {
                new curLen = strlen(CalcInput[playerid]);
                if (curLen >= 10) return; 

                format(text, sizeof(text), "%s%d", CalcInput[playerid], digit);
                strcopy(CalcInput[playerid], text, sizeof(CalcInput[]));

    
                FormatRibuan(displayBesar, sizeof(displayBesar), CalcInput[playerid]);
                PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], displayBesar);
                PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][57], "");
            }
            else
            {
                new curLen = strlen(CalcNum2[playerid]);
                if (curLen >= 10) return; 

                format(text, sizeof(text), "%s%d", CalcNum2[playerid], digit);
                strcopy(CalcNum2[playerid], text, sizeof(CalcNum2[]));

                FormatRibuan(displayBesar, sizeof(displayBesar), CalcNum2[playerid]);
                PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], displayBesar);

                new opChar = GetOperatorChar(playerid);
                new num1Formatted[32];
                FormatRibuan(num1Formatted, sizeof(num1Formatted), CalcInput[playerid]);
                format(displayKecil, sizeof(displayKecil), "%s %c", num1Formatted, opChar);
                PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][57], displayKecil);
            }

            PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][56]);
            PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][57]);
            return;
        }
    }
    if (playertextid == KalkulatorVRP[playerid][18])
    {
        CalcInput[playerid][0] = '\0';
        CalcNum2[playerid][0] = '\0';
        CalcHasOperator[playerid] = false;
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], "0");
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][57], "");
        PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][56]);
        PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][57]);
        return;
    }
    if (playertextid == KalkulatorVRP[playerid][19])
    {
        if (CalcHasOperator[playerid])
        {
            new len = strlen(CalcNum2[playerid]);
            if (len > 0)
            {
                CalcNum2[playerid][len - 1] = EOS;
                if (strlen(CalcNum2[playerid]) == 0)
                {
                    PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], "0");
                }
                else
                {
                    FormatRibuan(displayBesar, sizeof(displayBesar), CalcNum2[playerid]);
                    PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], displayBesar);
                }
                PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][56]);
            }
        }
        else
        {
            new len = strlen(CalcInput[playerid]);
            if (len > 0)
            {
                CalcInput[playerid][len - 1] = EOS;
                if (strlen(CalcInput[playerid]) == 0)
                    PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], "0");
                else
                {
                    FormatRibuan(displayBesar, sizeof(displayBesar), CalcInput[playerid]);
                    PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], displayBesar);
                }
                PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][56]);
            }
        }
        return;
    }
    new operatorIndex = -1;
    new operatorChar = 0;
    if(playertextid == KalkulatorVRP[playerid][20]) { operatorIndex = 20; operatorChar = '/'; }
    else if (playertextid == KalkulatorVRP[playerid][21]) { operatorIndex = 21; operatorChar = '*'; }
    else if (playertextid == KalkulatorVRP[playerid][22]) { operatorIndex = 22; operatorChar = '-'; }
    else if (playertextid == KalkulatorVRP[playerid][23]) { operatorIndex = 23; operatorChar = '+'; }

    if (operatorIndex != -1)
    {
        if (CalcInput[playerid][0] == '\0') return; 


        if (CalcHasOperator[playerid] && CalcNum2[playerid][0] != '\0')
        {
            new calcStr[64];
            format(calcStr, sizeof(calcStr), "%s%s", CalcInput[playerid], CalcNum2[playerid]);
            new Float:mid = EvaluateExpression(calcStr);
            new midStr[32];
            format(midStr, sizeof(midStr), "%d", floatround(mid, floatround_floor));
            strcopy(CalcInput[playerid], midStr, sizeof(CalcInput[]));
            CalcNum2[playerid][0] = '\0';
        }

        strcat(CalcInput[playerid], !""); 
        CalcHasOperator[playerid] = true;
        CalcNum2[playerid][0] = '\0';

        new baseLen = strlen(CalcInput[playerid]);
        CalcInput[playerid][baseLen] = operatorChar;
        CalcInput[playerid][baseLen + 1] = '\0';

        new num1Only[32];
        strcopy(num1Only, CalcInput[playerid], baseLen); 
        FormatRibuan(displayBesar, sizeof(displayBesar), num1Only);
        format(displayKecil, sizeof(displayKecil), "%s %c", displayBesar, operatorChar);
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][57], displayKecil);
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], "0");
        PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][56]);
        PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][57]);
        return;
    }

    // --- TOMBOL = ---
    if (playertextid == KalkulatorVRP[playerid][24])
    {
        if (CalcInput[playerid][0] == '\0') return;
        if (!CalcHasOperator[playerid]) return;
        if (CalcNum2[playerid][0] == '\0') return;

        new calcStr[64];
        format(calcStr, sizeof(calcStr), "%s%s", CalcInput[playerid], CalcNum2[playerid]);

        new Float:result = EvaluateExpression(calcStr);

        new opChar = GetOperatorChar(playerid);
        new num1Only[32];
        new num1Len = strlen(CalcInput[playerid]) - 1;
        strmid(num1Only, CalcInput[playerid], 0, num1Len, sizeof(num1Only));
        new num1F[32], num2F[32];
        FormatRibuan(num1F, sizeof(num1F), num1Only);
        FormatRibuan(num2F, sizeof(num2F), CalcNum2[playerid]);
        format(displayKecil, sizeof(displayKecil), "%s %c %s =", num1F, opChar, num2F);
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][57], displayKecil);
        PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][57]);

        FormatHasil(displayBesar, sizeof(displayBesar), result);
        PlayerTextDrawSetString(playerid, KalkulatorVRP[playerid][56], displayBesar);
        PlayerTextDrawShow(playerid, KalkulatorVRP[playerid][56]);

        CalcInput[playerid][0] = '\0';
        CalcNum2[playerid][0] = '\0';
        CalcHasOperator[playerid] = false;
        return;
    }
}

hook ClickDynPlayerTextdraw(playerid, PlayerText:playertextid)
{
    if(KalkulatorOpen[playerid])
        HandleKalkulatorInput(playerid, playertextid);
    
    if(playertextid == KalkulatorVRP[playerid][15]) //close
    {
        CalcInput[playerid][0] = '\0';
        CalcNum2[playerid][0] = '\0';
        CalcHasOperator[playerid] = false;
        KalkulatorOpen[playerid] = false;
        ShowKalkulatorTD(playerid, false);
        ShowPhoneVRP(playerid);
    }
    return 1;
}