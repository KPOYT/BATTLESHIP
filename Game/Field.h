#include <iostream>
#include <windows.h>
#include <array>

#ifndef EXITPANEL_H
#define EXITPANEL_H
#include "..\Panels\ExitPanel.h"
#endif

#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

#ifndef BOT_H
#define BOT_H
#include "Bot.h"
#endif

#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

#ifndef CONFIG_H
#define CONFIG_H
#include "..\Config.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "..\Console.h"
#endif

using namespace std;

class Field {
	public:
		Field();
		Field(const int x,
			 const int y,
			 const int width = Config::FIELD_VIEW_WIDTH,
			 const int height = Config::FIELD_VIEW_HEIGHT);
		~Field();
		
		void draw();
		void generate();
		const int walk();
		const int walkByBot();
		const int leftShips();
		const int checkCell(const COORD);
		const int checkCell(const int, const int);
		const bool isKilledShip(Ship* const);
		Ship* const findShipByPosition(const COORD);
		Ship* const findShipByPosition(const int, const int);

		bool isOpenShips;

		enum WalkState
		{
			Successful = 101,
			Unsuccessful = 102,
			Gameover = 103
		};
	protected:
		Console* console;
	private:
		void drawField();
		void drawShips();
		void drawCell(
			const COORD position, 
			const bool mode);
		void clearField();
		void updateBotGrid();
		void updateBotShips();
		void fillCellsAroundKilledShip();
		void findPlaceToSheep(const int, const int);
		const bool checkPositionAroundShip(Ship* const, const COORD);
		Ship* const getCurrentShip();

		Bot bot_;
		COORD position_;
		COORD oldPosition_;
		Ship* ships_[Config::MAX_SHIPS];
		Cell* grid_[Config::FIELD_WIDTH][Config::FIELD_HEIGHT];
		int x_;
		int y_;
		int width_;
		int height_;
		bool active_;
};
