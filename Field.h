#include <iostream>
#include <windows.h>
#include <array>
#include "Bot.h"

#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

#ifndef GRAPHYCALELEMENT_H
#define GRAPHYCALELEMENT_H
#include "GraphycalElement.h"
#endif

using namespace std;

class Field : public GraphycalElement {
	public:
		Field(){
			x_ = 0;
			y_ = 0;
			width_ = 22;
			height_ = 22;
			active_ = false;
			position_.X = 0;
			position_.Y = 0;
		};
		Field(int const x, int const y, int const width = 22, int const height = 22) {
			x_ = x;
			y_ = y;
			width_ = width;
			height_ = height;
			active_ = false;
			position_.X = 0;
			position_.Y = 0;
		};
		~Field(){};
		
		int walk();
		void draw();
		void generate();
		int walkByBot();
		int leftShips();
		int const checkCell(COORD);
		int const checkCell(int, int);
		Ship* const getShipByPosition(COORD);
		Ship* const getShipByPosition(int, int);
		bool checkKilledShip(Ship*);
		bool type;

		enum Types{
			open = true,
			close = false
		};

		enum WalkStatus
		{
			success = 101,
			unsuccess = 102,
			gameover = 103
		};
	private:
		void drawField();
		void drawShips();
		void drawCell(COORD position, int textColor = 15, int backgroundColor = 0);
		void fillCellsAroundKilledShip();
		bool checkPositionAroundShip(Ship*, COORD);
		void clearField();
		void findPlaceToSheep(int const, int const);
		void updateBotGrid();
		void updateBotShips();
		Ship* const getCurrentShip();

		Bot bot;
		COORD position_;
		COORD oldPosition_;
		Ship* ships[10];
		int grid[10][10];
		int x_;
		int y_;
		int width_;
		int height_;
		bool active_;

		enum CellStatus
		{
			empty = 0,
			full = 1,
			hit = 2,
			miss = 3
		};
};