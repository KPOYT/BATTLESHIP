#include <iostream>
#include <windows.h>
#include <array>

#ifndef BOT_H
#define BOT_H
#include "Bot.h"
#endif

#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Field {
	public:
		Field();
		Field(const int x,
			 const int y,
			 const int width = 22,
			 const int height = 22);
		~Field();
		
		void draw();
		void generate();
		const int walk();
		const int walkByBot();
		const int leftShips();
		const int checkCell(COORD const);
		const int checkCell(int const, int const);
		const bool isKilledShip(Ship* const);
		Ship* const findShipByPosition(COORD const);
		Ship* const findShipByPosition(int const, int const);

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
		static int const MAX_SIZE = 10;

		void drawField();
		void drawShips();
		void drawCell(
			const COORD position, 
			const int textColor = 15, 
			const int backgroundColor = 0);
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
		Ship* ships_[MAX_SIZE];
		int grid_[MAX_SIZE][MAX_SIZE];
		int x_;
		int y_;
		int width_;
		int height_;
		bool active_;

		enum CellState
		{
			Empty = 0,
			Full = 1,
			Hit = 2,
			Miss = 3
		};
};