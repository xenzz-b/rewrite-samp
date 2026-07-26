@ECHO OFF
cls
.\pawno\pawncc.exe main.pwn -Dgamemodes -;+ -(+ -d1

:: Enable ANSI escape sequences for colored output
REG ADD HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1 /f >nul

:: Define colors
SET "GREEN=[32m"
SET "RED=[31m"
SET "YELLOW=[33m"
SET "RESET=[0m"
:: Define log file name with timestamp
SET "LOGFILE=compile_log_%DATE:~10,4%-%DATE:~4,2%-%DATE:~7,2%_%TIME:~0,2%%TIME:~3,2%%TIME:~6,2%.txt"
SET "LOGFILE=%LOGFILE: =0%"  :: Remove spaces (e.g., from hour " 8" to "08")

echo %YELLOW%Starting compilation of main.pwn...%RESET%
echo.
.\pawno\pawncc.exe main.pwn -d3 > logs\%LOGFILE% 2>&1

IF %ERRORLEVEL% NEQ 0 (
    echo.
    echo [%RED%ERROR%RESET%] Compilation failed! See logs\%LOGFILE%
) ELSE (
    echo.
    echo [%GREEN%SUCCESS%RESET%] Compilation completed successfully. See logs\%LOGFILE%
)

echo.
echo Press any key to exit...
pause >nul
