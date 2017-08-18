#include <windows.h>
#include "BattleShip.h"

const BOOL ShowConsoleCursor(const BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if(hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;

    if(!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;

    cci.bVisible = bShow;

    if(!SetConsoleCursorInfo(hStdOut,&cci))
        return FALSE;

    return TRUE;
}

void main() {
	ShowConsoleCursor(FALSE);
	
	BattleShip* battleShip = BattleShip::Instance();
	battleShip->startGame();
}