#include <iostream>
#include <windows.h>
#include <time.h>
#include <array>

#ifndef OS_H
#define OS_H
#include "..\ApplicationOS\OS.h"
#endif

#ifndef EXITPANEL_H
#define EXITPANEL_H
#include "..\Panels\ExitPanel.h"
#endif

#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include "EmptyCell.h"
#endif

#ifndef FULLCELL_H
#define FULLCELL_H
#include "FullCell.h"
#endif

#ifndef BOT_H
#define BOT_H
#include "Bot.h"
#endif

#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

using namespace std;

class Field {
	public:
		Field();
		Field(const int x,
			 const int y);
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
		OSConsole* console;
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
		Ship* ships_[OSConfig::MAX_SHIPS];
		Cell* grid_[OSConfig::FIELD_WIDTH][OSConfig::FIELD_HEIGHT];
		int x_;
		int y_;
		int width_;
		int height_;
		bool active_;
};
