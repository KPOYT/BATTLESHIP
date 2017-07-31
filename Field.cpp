#include <conio.h>
#include <time.h>
#include "ExitPanel.h"
#include "Field.h"
#include "Cell.h"
#include "Bot.h"

void Field::generate() {
	int const maxShips = 10;
	int sheeps[] = {4,3,3,2,2,2,1,1,1,1};

	clearField();

	for(int i = 0; i < maxShips; i++){
		findPlaceToSheep(sheeps[i], i);
	}
}

void Field::clearField(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			grid[i][j] = 0;
		}
	}
}

void Field::findPlaceToSheep(int const shipType, int const index){
	Ship ship(shipType);
	int const maxShips = 10;
	bool find = false;
	
	srand(GetTickCount());

	do
	{
		int x = 0 + rand() %10;
		int y = 0 + rand() %10;
		int rotate = 0 + rand() %10;
		bool clear = true;

		for(int i = -1; i <= shipType; i++)
		{
			for(int j = -1; j <= 1; j++)
			{
				if(rotate < 5){
					if(x+i >= maxShips && i<shipType) {
						clear = false;
						break;
					}

					if(grid[x+i][y+j] != empty)
						clear = false;
				}
				else
				{
					if(y+i >= maxShips && i < shipType) {
						clear = false;
						break;
					}

					if(grid[x+j][y+i] != empty)
						clear = false;
				}
			}
		}

		if(clear)
		{
			for(int i = 0; i < shipType; i++){
				if(rotate < 5)
				{
					grid[x+i][y] = full;
					COORD pos;
					pos.X = x+i;
					pos.Y = y;
					ship.addCell(pos);
					ship.type = ship.horizontal;
					ships[index] = ship;
				}
				else
				{
					grid[x][y+i] = full;
					COORD pos;
					pos.X = x;
					pos.Y = y+i;
					ship.addCell(pos);
					ship.type = ship.vertical;
					ships[index] = ship;
				}
			}
			find = true;
		}
	} while (!find);
}

int Field::walk() {
	bool makeChoise = false;

	active_ = true;

	drawCell(position_, 14, 14);

	do
	{
		int code = _getch();
		if (code == 224)
		{
			code = _getch();

			switch(code) 
			{
				case 72: {
					if(position_.Y <= 0){
						position_.Y = 0;
						break;
					}

					oldPosition_.X = position_.X;
					oldPosition_.Y = position_.Y;

					position_.Y--;
					break;
				}
				case 75: {
					if(position_.X <= 0){
						position_.X = 0;
						break;
					}

					oldPosition_.X = position_.X;
					oldPosition_.Y = position_.Y;

					position_.X--;
					break;
				}
				case 77: {
					if(position_.X >= 9){
						position_.X = 9;
						break;
					}

					oldPosition_.X = position_.X;
					oldPosition_.Y = position_.Y;

					position_.X++;
					break;
				}
				case 80: {
					if(position_.Y >= 9){
						position_.Y = 9;
						break;
					}

					oldPosition_.X = position_.X;
					oldPosition_.Y = position_.Y;

					position_.Y++;
					break;
				}
			}
			drawCell(position_, 14, 14);
			drawCell(oldPosition_);
			drawShips();
		}
		else 
		{
			switch(code)
			{
				case VK_RETURN:
					switch(grid[position_.X][position_.Y]){
						case empty: {
							grid[position_.X][position_.Y] = miss;
							active_ = false;
							makeChoise = true;
							drawCell(position_);
							drawShips();

							return unsuccess;
						}
						case full: {
							grid[position_.X][position_.Y] = hit;
							active_ = false;
							makeChoise = true;
							fillCellsAroundKilledShip();
							drawCell(position_);
							drawShips();

							return success;
						}
					}
				break;
				case VK_ESCAPE:
					COORD exitCoord;
					exitCoord.X = 30;
					exitCoord.Y = 23;

					ExitPanel exitPanel(exitCoord);
					int result = exitPanel.show();
					if(result == 1)
						return gameover;
				break;
			}	
		}
	}
	while(!makeChoise);

	return false;
}

int Field::walkByBot() {
	Bot bot(this);
	COORD coord = bot.findCellToStrike();
	position_ = coord;

	switch(grid[coord.X][coord.Y]){
		case empty: {
			grid[coord.X][coord.Y] = miss;
			drawCell(coord);
			drawShips();

			return unsuccess;
		}
		case full: {
			grid[coord.X][coord.Y] = hit;
			fillCellsAroundKilledShip();
			drawCell(position_);
			drawShips();

			return success;
		}
	}

	return unsuccess;
}

void Field::fillCellsAroundKilledShip() {
	Ship* ship = getCurrentShip();

	if(!checkKilledShip(ship)) return;
	COORD coord;

	for(int i = -1; i <= ship->size; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			switch(ship->type){
				case ship->vertical:
					coord.X = ship->cells[0].X + j;
					coord.Y = ship->cells[0].Y + i;
					break;
				case ship->horizontal:
					coord.X = ship->cells[0].X + i;
					coord.Y = ship->cells[0].Y + j;
					break;
			}

			if(coord.X < 0 || coord.X >= 10) continue;
			if(coord.Y < 0 || coord.Y >= 10) continue;

			if(checkPositionAroundShip(ship, coord))
				grid[coord.X][coord.Y] = miss;
		}
	}
}

int Field::leftShips(){
	int max = 10;

	for(int s = 0; s < 10; s++){
		if(checkKilledShip(&ships[s])){
			max--;
		}
	};

	return max;
}

Ship* Field::getCurrentShip(){
	for(int s = 0; s < 10; s++){
		if(ships[s].checkCell(position_))
		{
			return &ships[s];
		}
	}

	return NULL;
}

Ship* Field::getShipByPosition(COORD coord){
	for(int s = 0; s < 10; s++){
		if(ships[s].checkCell(coord))
		{
			return &ships[s];
		}
	}

	return NULL;
}

Ship* Field::getShipByPosition(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < 10; s++){
		if(ships[s].checkCell(coord))
		{
			return &ships[s];
		}
	}

	return NULL;
}

bool Field::checkPositionAroundShip(Ship* ship, COORD position) {
	for(int i = 0; i < ship->size; i++)
	{
		if(ship->cells[i].X == position.X && ship->cells[i].Y == position.Y)
		{
			return false;
		}
	}

	return true;
}

bool Field::checkKilledShip(Ship* ship) {
	for(int j = 0; j < ship->size; j++){
		COORD cell = ship->cells[j];
		if(grid[cell.X][cell.Y] != hit)
			return false;
	}

	return true;
}

void Field::draw() {
	drawField();

	drawShips();

	if(active_)
		drawCell(position_, 14, 14);
}

void Field::drawField(){
	setColor(15, 0);

	fillLine("\xc9", "\xcd", "\xBB", width_, x_, y_);
	fillSquare("\xba", " ", "\xba", width_, height_-2, x_, y_+1);
	fillLine("\xc8", "\xcd", "\xBC", width_, x_, y_ + height_ - 1);
}

void Field::drawShips(){
	COORD coords;
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(active_ && position_.X == i && position_.Y == j)
				continue;

			coords.X = i;
			coords.Y = j;

			switch(grid[i][j]){
				case full:{
					if(type == open)
						drawCell(coords, 3, 3);
					break;
				}
				case miss:{
					drawCell(coords, 5, 5);
					break;
				}
				case hit:{
					drawCell(coords, 4, 4);
					break;
				}
			}
		}
	}
}

int const Field::checkCell(COORD position){
	return grid[position.X][position.Y];
}

int const Field::checkCell(int x, int y){
	return grid[x][y];
}

void Field::drawCell(COORD position, int textColor, int backgroundColor){
	setColor(0, 5);

	if(position.X < 0)
		position.X = 0;

	if(position.Y < 0)
		position.Y = 0;

	COORD coords;
	coords.X = x_ + 1;
	coords.Y = y_ + 1;

	Cell cell(coords.X + position.X * 2, coords.Y + position.Y * 2, textColor, backgroundColor);
	cell.draw();

	setColor(0, 5);
}