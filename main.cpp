#include <windows.h>
#include "MainMenu.h"
#include "ExitMenu.h"
#include "Game.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

const BOOL ShowConsoleCursor(const BOOL bShow);
const int StartGame();

void main() {
	ShowConsoleCursor(FALSE);
	StartGame();
}

const BOOL ShowConsoleCursor(const BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;

    if(hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;

    if(!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;

    cci.bVisible = bShow;

    if(!SetConsoleCursorInfo(hStdOut,&cci))
        return FALSE;

    return TRUE;
}

const int StartGame()
{
	MainMenu* mainMenu = new MainMenu;
	ExitMenu* exitMenu = new ExitMenu(33, 10);
	Game* game;

	int mainMenuChoise;
	int exitMenuChoise = 0;

	do {
		mainMenuChoise = mainMenu->show();

		switch (mainMenuChoise) {
			case 0:
				game = new Game;
				game->draw();
				game->start();
				delete game;
			break;
			case 1:
				exitMenuChoise = exitMenu->show();
			break;
		}
	}
	while (exitMenuChoise != 1);

	return exitMenuChoise;
}
