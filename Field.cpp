#include <conio.h>
#include <time.h>
#include "ExitPanel.h"
#include "Field.h"
#include "Cell.h"

void Field::generate() {
	int sheeps[] = {4,3,3,2,2,2,1,1,1,1};

	clearField();

	for(int i = 0; i < MAX_SIZE; i++){
		findPlaceToSheep(sheeps[i], i);
	}
}

void Field::clearField(){
	for(int i = 0; i < MAX_SIZE; i++){
		for(int j = 0; j < MAX_SIZE; j++){
			grid_[i][j] = 0;
		}
	}
}

void Field::findPlaceToSheep(int const shipType, int const index){
	Ship* ship = new Ship(shipType);
	bool find = false;
	
	srand(GetTickCount());

	do
	{
		int x = 0 + rand() % MAX_SIZE;
		int y = 0 + rand() % MAX_SIZE;
		int rotate = 0 + rand() % MAX_SIZE;
		bool clear = true;

		for(int i = -1; i <= shipType; i++)
		{
			for(int j = -1; j <= 1; j++)
			{
				if(rotate < 5){
					if(x+i >= MAX_SIZE && i < shipType) {
						clear = false;
						break;
					}

					if(grid_[x+i][y+j] != empty)
						clear = false;
				}
				else
				{
					if(y+i >= MAX_SIZE && i < shipType) {
						clear = false;
						break;
					}

					if(grid_[x+j][y+i] != empty)
						clear = false;
				}
			}
		}

		if(clear)
		{
			for(int i = 0; i < shipType; i++){
				if(rotate < 5)
				{
					grid_[x+i][y] = full;
					COORD pos;
					pos.X = x+i;
					pos.Y = y;
					ship->addCell(pos);
					ship->type = ship->horizontal;
					ships_[index] = ship;
				}
				else
				{
					grid_[x][y+i] = full;
					COORD pos;
					pos.X = x;
					pos.Y = y+i;
					ship->addCell(pos);
					ship->type = ship->vertical;
					ships_[index] = ship;
				}
			}
			find = true;
		}
	} while (!find);
}

int const Field::walk() {
	active_ = true;

	drawCell(position_, Yellow, Yellow);

	bool isDone = false;
	do
	{
		int code = _getch();
		if(code == 224)
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
					switch(grid_[position_.X][position_.Y]){
						case empty: {
							grid_[position_.X][position_.Y] = miss;
							active_ = false;
							isDone = true;
							drawCell(position_);
							drawShips();

							return unsuccessful;
						}
						case full: {
							grid_[position_.X][position_.Y] = hit;
							active_ = false;
							isDone = true;
							fillCellsAroundKilledShip();
							drawCell(position_);
							drawShips();

							return successful;
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
	while(!isDone);

	return false;
}

int const Field::walkByBot() {
	updateBotGrid();
	updateBotShips();

	COORD coord = bot_.findCellToStrike();
	position_ = coord;

	switch(grid_[coord.X][coord.Y]){
		case empty: {
			grid_[coord.X][coord.Y] = miss;
			drawCell(coord);
			drawShips();

			return unsuccessful;
		}
		case full: {
			grid_[coord.X][coord.Y] = hit;
			fillCellsAroundKilledShip();
			drawCell(position_);
			drawShips();

			return successful;
		}
	}

	return unsuccessful;
}

void Field::updateBotGrid() {
	for(int i = 0; i < MAX_SIZE; i++){
		for(int j = 0; j < MAX_SIZE; j++){
			bot_.grid[i][j] = grid_[i][j];
		}
	}
}

void Field::updateBotShips() {
	for(int i = 0; i < MAX_SIZE; i++){
		bot_.ships[i] = ships_[i];
	}
}

void Field::fillCellsAroundKilledShip() {
	Ship* ship = getCurrentShip();
	
	if(!isKilledShip(ship))
		return;

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

			if(coord.X < 0 || coord.X >= MAX_SIZE)
				continue;

			if(coord.Y < 0 || coord.Y >= MAX_SIZE)
				continue;

			if(checkPositionAroundShip(ship, coord))
				grid_[coord.X][coord.Y] = miss;
		}
	}
}

int const Field::leftShips(){
	int max = MAX_SIZE;

	for(int s = 0; s < MAX_SIZE; s++){
		if(isKilledShip(ships_[s]))
			max--;
	};

	return max;
}

Ship* const Field::getCurrentShip(){
	for(int s = 0; s < MAX_SIZE; s++){
		if(ships_[s]->checkCell(position_))
			return ships_[s];
	}

	return NULL;
}

Ship* const Field::findShipByPosition(COORD coord){
	for(int s = 0; s < MAX_SIZE; s++){
		if(ships_[s]->checkCell(coord))
			return ships_[s];
	}

	return NULL;
}

Ship* const Field::findShipByPosition(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < MAX_SIZE; s++){
		if(ships_[s]->checkCell(coord))
			return ships_[s];
	}

	return NULL;
}

bool const Field::checkPositionAroundShip(Ship* ship, COORD position) {
	for(int i = 0; i < ship->size; i++)
	{
		if(ship->cells[i].X == position.X && ship->cells[i].Y == position.Y)
			return false;
	}

	return true;
}

bool const Field::isKilledShip(Ship* ship) {
	for(int j = 0; j < ship->size; j++){
		COORD cell = ship->cells[j];
		if(grid_[cell.X][cell.Y] != hit)
			return false;
	}

	return true;
}

void Field::draw() {
	drawField();

	drawShips();

	if(active_)
		drawCell(position_, Yellow, Yellow);
}

void Field::drawField(){
	setColor(White, Black);

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

			switch(grid_[i][j]){
				case full:{
					if(isOpenShips)
						drawCell(coords, Cyan, Cyan);
					break;
				}
				case miss:{
					drawCell(coords, Magenta, Magenta);
					break;
				}
				case hit:{
					drawCell(coords, Red, Red);
					break;
				}
			}
		}
	}
}

int const Field::checkCell(COORD position){
	return grid_[position.X][position.Y];
}

int const Field::checkCell(int x, int y){
	return grid_[x][y];
}

void Field::drawCell(COORD position, int textColor, int backgroundColor){
	setColor(White, Black);

	if(position.X < 0)
		position.X = 0;

	if(position.Y < 0)
		position.Y = 0;

	COORD coords;
	coords.X = x_ + 1;
	coords.Y = y_ + 1;

	Cell cell(coords.X + position.X * 2, coords.Y + position.Y * 2, textColor, backgroundColor);
	cell.draw();

	setColor(White, Black);
}