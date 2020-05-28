#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdbool.h>
#include <conio.h> // getch()
#include <windows.h>

#define _WIN32_WINNT 0x0500

typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif
//the function declaration ends
int main()
{
    CONSOLE_FONT_INFOEX fontStructure={0};
    fontStructure.cbSize=sizeof(fontStructure);
    fontStructure.dwFontSize.X = 12;
    fontStructure.dwFontSize.Y = 16;
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetCurrentConsoleFontEx(hConsole, 0, &fontStructure);
    SMALL_RECT windowSize = {0, 0, 117, 52};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
    system("pause");
}