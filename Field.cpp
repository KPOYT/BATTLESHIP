#include <conio.h>
#include <time.h>

#ifndef EXITPANEL_H
#define EXITPANEL_H
#include "ExitPanel.h"
#endif

#ifndef FIELD_H
#define FIELD_H
#include "Field.h"
#endif

#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

Field::Field()
{
	x_ = 0;
	y_ = 0;
	width_ = 22;
	height_ = 22;
	active_ = false;
	position_.X = 0;
	position_.Y = 0;
	console = Console::Instance();
};

Field::Field(const int x,
	const int y,
	const int width,
	const int height)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
	active_ = false;
	position_.X = 0;
	position_.Y = 0;
	console = Console::Instance();
};

Field::~Field()
{
	int size = sizeof(ships_) / sizeof(Ship);
	for(int i = 0; i < size; i++)
		delete ships_[i];
};

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

void Field::findPlaceToSheep(const int shipType, const int index){
	Ship* ship = new Ship();
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

					if(grid_[x+i][y+j] != Empty)
						clear = false;
				}
				else
				{
					if(y+i >= MAX_SIZE && i < shipType) {
						clear = false;
						break;
					}

					if(grid_[x+j][y+i] != Empty)
						clear = false;
				}
			}
		}

		if(clear)
		{
			for(int i = 0; i < shipType; i++){
				if(rotate < 5)
				{
					grid_[x+i][y] = Full;
					COORD pos;
					pos.X = x+i;
					pos.Y = y;
					ship->addCell(pos);
					ships_[index] = ship;
				}
				else
				{
					grid_[x][y+i] = Full;
					COORD pos;
					pos.X = x;
					pos.Y = y+i;
					ship->addCell(pos);
					ships_[index] = ship;
				}
			}
			find = true;
		}
	} while (!find);
}

const int Field::walk() {
	active_ = true;

	drawCell(position_, console->Yellow, console->Yellow);

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
			drawCell(position_, console->Yellow, console->Yellow);
			drawCell(oldPosition_);
			drawShips();
		}
		else 
		{
			switch(code)
			{
				case VK_RETURN:
					switch(grid_[position_.X][position_.Y]){
						case Empty: {
							grid_[position_.X][position_.Y] = Miss;
							active_ = false;
							isDone = true;
							drawCell(position_);
							drawShips();

							return Unsuccessful;
						}
						case Full: {
							grid_[position_.X][position_.Y] = Hit;
							active_ = false;
							isDone = true;
							fillCellsAroundKilledShip();
							drawCell(position_);
							drawShips();

							return Successful;
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
						return Gameover;
				break;
			}	
		}
	}
	while(!isDone);

	return false;
}

const int Field::walkByBot() {
	updateBotGrid();
	updateBotShips();

	COORD coord = bot_.findCellToStrike();
	position_ = coord;

	switch(grid_[coord.X][coord.Y]){
		case Empty: {
			grid_[coord.X][coord.Y] = Miss;
			drawCell(coord);
			drawShips();

			return Unsuccessful;
		}
		case Full: {
			grid_[coord.X][coord.Y] = Hit;
			fillCellsAroundKilledShip();
			drawCell(position_);
			drawShips();

			return Successful;
		}
	}

	return Unsuccessful;
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

	for(int i = -1; i <= ship->size(); i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			switch(ship->type()){
				case ship->Vertical:
					coord.X = ship->getCell(0).X + j;
					coord.Y = ship->getCell(0).Y + i;
					break;
				case ship->Horizontal:
					coord.X = ship->getCell(0).X + i;
					coord.Y = ship->getCell(0).Y + j;
					break;
			}

			if(coord.X < 0 || coord.X >= MAX_SIZE)
				continue;

			if(coord.Y < 0 || coord.Y >= MAX_SIZE)
				continue;

			if(checkPositionAroundShip(ship, coord))
				grid_[coord.X][coord.Y] = Miss;
		}
	}
}

const int Field::leftShips(){
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

Ship* const Field::findShipByPosition(const COORD coord){
	for(int s = 0; s < MAX_SIZE; s++){
		if(ships_[s]->checkCell(coord))
			return ships_[s];
	}

	return NULL;
}

Ship* const Field::findShipByPosition(const int x, const int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < MAX_SIZE; s++){
		if(ships_[s]->checkCell(coord))
			return ships_[s];
	}

	return NULL;
}

const bool Field::checkPositionAroundShip(Ship* const ship, const COORD position) {
	for(int i = 0; i < ship->size(); i++)
	{
		if(ship->getCell(i).X == position.X && ship->getCell(i).Y == position.Y)
			return false;
	}

	return true;
}

bool const Field::isKilledShip(Ship* const ship) {
	for(int j = 0; j < ship->size(); j++){
		COORD cell = ship->getCell(j);
		if(grid_[cell.X][cell.Y] != Hit)
			return false;
	}

	return true;
}

void Field::draw() {
	drawField();

	drawShips();

	if(active_)
		drawCell(position_, console->Yellow, console->Yellow);
}

void Field::drawField(){
	console->setColor(console->White, console->Black);

	console->fillLine("\xc9", "\xcd", "\xBB", width_, x_, y_);
	console->fillSquare("\xba", " ", "\xba", width_, height_-2, x_, y_+1);
	console->fillLine("\xc8", "\xcd", "\xBC", width_, x_, y_ + height_ - 1);
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
				case Full:{
					if(isOpenShips)
						drawCell(coords, console->Cyan, console->Cyan);
					break;
				}
				case Miss:{
					drawCell(coords, console->Magenta, console->Magenta);
					break;
				}
				case Hit:{
					drawCell(coords, console->Red, console->Red);
					break;
				}
			}
		}
	}
}

int const Field::checkCell(const COORD position){
	return grid_[position.X][position.Y];
}

int const Field::checkCell(const int x, const int y){
	return grid_[x][y];
}

void Field::drawCell(COORD position, const int textColor, const int backgroundColor){
	console->setColor(console->White, console->Black);

	if(position.X < 0)
		position.X = 0;

	if(position.Y < 0)
		position.Y = 0;

	COORD coords;
	coords.X = x_ + 1;
	coords.Y = y_ + 1;

	Cell cell(coords.X + position.X * 2, coords.Y + position.Y * 2, textColor, backgroundColor);
	cell.draw();

	console->setColor(console->White, console->Black);
}