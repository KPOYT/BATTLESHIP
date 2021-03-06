#ifndef MAINMENU_H
#define MAINMENU_H
#include "..\Menus\MainMenu.h"
#endif

#ifndef EXITMENU_H
#define EXITMENU_H
#include "..\Menus\ExitMenu.h"
#endif

#ifndef GAME_H
#define GAME_H
#include "Game.h"
#endif

class BattleShip {
	public:
		static BattleShip* Instance();

		const int startGame();
	protected:
		BattleShip();
		~BattleShip();
	private:
		static BattleShip* _instance;
};