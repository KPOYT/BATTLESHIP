#include "BattleShip.h"

BattleShip::BattleShip(){};
BattleShip::~BattleShip(){};

BattleShip* BattleShip::_instance = 0;

BattleShip* BattleShip::Instance(){
	if (_instance == 0) {
		_instance = new BattleShip();
	}
	return _instance;
}

const int BattleShip::startGame(){
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