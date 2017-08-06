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
		Field()
		{
			x_ = 0;
			y_ = 0;
			width_ = 22;
			height_ = 22;
			active_ = false;
			position_.X = 0;
			position_.Y = 0;
		};
		Field(
			 int const x,
			 int const y,
			 int const width = 22,
			 int const height = 22)
		{
			x_ = x;
			y_ = y;
			width_ = width;
			height_ = height;
			active_ = false;
			position_.X = 0;
			position_.Y = 0;
		};
		~Field()
		{
			int size = sizeof(ships_) / sizeof(Ship);
			for(int i = 0; i < size; i++)
				delete ships_[i];
		};
		
		void draw();
		void generate();
		int const walk();
		int const walkByBot();
		int const leftShips();
		int const checkCell(COORD const);
		int const checkCell(int const, int const);
		bool const isKilledShip(Ship* const);
		Ship* const findShipByPosition(COORD const);
		Ship* const findShipByPosition(int const, int const);

		bool isOpenShips;

		enum WalkStatus
		{
			successful = 101,
			unsuccessful = 102,
			gameover = 103
		};
	private:
		static int const MAX_SIZE = 10;

		void drawField();
		void drawShips();
		void drawCell(
			COORD const position, 
			int const textColor = White, 
			int const backgroundColor = Black);
		void clearField();
		void updateBotGrid();
		void updateBotShips();
		void fillCellsAroundKilledShip();
		void findPlaceToSheep(int const, int const);
		bool const checkPositionAroundShip(Ship* const, COORD const);
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

		enum CellStatus
		{
			empty = 0,
			full = 1,
			hit = 2,
			miss = 3
		};
};