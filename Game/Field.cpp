#include <conio.h>
#include <time.h>
#include "Field.h"

Field::Field()
{
	x_ = 0;
	y_ = 0;
	width_ = Config::FIELD_WIDTH;
	height_ = Config::FIELD_HEIGHT;
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
	for(int i = 0; i < Config::MAX_SHIPS; i++)
		delete ships_[i];

	for(int i = 0; i < Config::CELL_VIEW_WIDTH; i++){
		for(int j = 0; j < Config::CELL_VIEW_HEIGHT; j++)
			delete grid_[i][j];
	}
};

void Field::generate() {
	const int* sheeps = Config::SHIPS_TYPE();

	clearField();

	for(int i = 0; i < Config::MAX_SHIPS; i++){
		findPlaceToSheep(sheeps[i], i);
	}
}

void Field::clearField(){
	COORD coords;
	coords.X = x_ + 1;
	coords.Y = y_ + 1;

	for(int i = 0; i < Config::FIELD_WIDTH; i++){
		for(int j = 0; j < Config::FIELD_HEIGHT; j++){
			grid_[i][j] = new EmptyCell(coords.X + i * Config::CELL_VIEW_WIDTH,
				coords.Y + j * Config::CELL_VIEW_HEIGHT);
		}
	}
}

void Field::findPlaceToSheep(const int shipType, const int index){
	Ship* ship = new Ship();
	bool find = false;
	
	srand(GetTickCount());

	do
	{
		int x = 0 + rand() % Config::FIELD_WIDTH;
		int y = 0 + rand() % Config::FIELD_HEIGHT;
		int rotate = 0 + rand() % Config::MAX_SHIPS;
		bool clear = true;

		for(int i = -1; i <= shipType; i++)
		{
			for(int j = -1; j <= 1; j++)
			{
				if(rotate < 5){
					if(x+i >= Config::FIELD_WIDTH && i < shipType) {
						clear = false;
						break;
					}

					if(x+i < 0 
						|| y+j < 0 
						|| x+i >= Config::FIELD_WIDTH 
						|| y+j >= Config::FIELD_HEIGHT) continue;

					if(grid_[x+i][y+j]->getStatus() != Cell::Empty)
						clear = false;
				}
				else
				{
					if(y+i >= Config::FIELD_HEIGHT && i < shipType) {
						clear = false;
						break;
					}

					if(x+j < 0 
						|| y+i < 0 
						|| x+j >= Config::FIELD_WIDTH 
						|| y+i >= Config::FIELD_HEIGHT) continue;

					if(grid_[x+j][y+i]->getStatus() != Cell::Empty)
						clear = false;
				}
			}
		}

		if(clear)
		{
			COORD coords;
			coords.X = x_ + 1;
			coords.Y = y_ + 1;

			for(int i = 0; i < shipType; i++){
				if(rotate < 5)
				{
					delete grid_[x+i][y];
					grid_[x+i][y] = new FullCell(coords.X + (x+i) * Config::CELL_VIEW_WIDTH,
						coords.Y + y * Config::CELL_VIEW_HEIGHT);
					COORD pos;
					pos.X = x+i;
					pos.Y = y;
					ship->addCell(pos);
					ships_[index] = ship;
				}
				else
				{
					delete grid_[x][y+i];
					grid_[x][y+i] = new FullCell(coords.X + x * Config::CELL_VIEW_WIDTH,
						coords.Y + (y+i) * Config::CELL_VIEW_HEIGHT);
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

	drawCell(position_, Cell::Active);

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
			drawCell(position_, Cell::Active);
			drawCell(oldPosition_, Cell::Inactive);
			drawShips();
		}
		else 
		{
			switch(code)
			{
				case VK_RETURN:
					switch(grid_[position_.X][position_.Y]->getStatus()){
						case Cell::Empty: {
							grid_[position_.X][position_.Y]->setState(Cell::Clicked);
							active_ = false;
							isDone = true;
							drawCell(position_, Cell::Inactive);
							drawShips();

							return Unsuccessful;
						}
						case Cell::Full: {
							grid_[position_.X][position_.Y]->setState(Cell::Clicked);
							active_ = false;
							isDone = true;
							fillCellsAroundKilledShip();
							drawCell(position_, Cell::Inactive);
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

	switch(grid_[coord.X][coord.Y]->getStatus()){
		case Cell::Empty: {
			grid_[coord.X][coord.Y]->setState(Cell::Clicked);
			drawCell(coord, Cell::Inactive);
			drawShips();

			return Unsuccessful;
		}
		case Cell::Full: {
			grid_[coord.X][coord.Y]->setState(Cell::Clicked);
			fillCellsAroundKilledShip();
			drawCell(position_, Cell::Inactive);
			drawShips();

			return Successful;
		}
	}

	return Unsuccessful;
}

void Field::updateBotGrid() {
	for(int i = 0; i < Config::FIELD_WIDTH; i++){
		for(int j = 0; j < Config::FIELD_HEIGHT; j++){
			bot_.grid[i][j] = grid_[i][j];
		}
	}
}

void Field::updateBotShips() {
	for(int i = 0; i < Config::MAX_SHIPS; i++){
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

			if(coord.X < 0 || coord.X >= Config::FIELD_WIDTH)
				continue;

			if(coord.Y < 0 || coord.Y >= Config::FIELD_HEIGHT)
				continue;

			if(checkPositionAroundShip(ship, coord))
				grid_[coord.X][coord.Y]->setState(Cell::Clicked);
		}
	}
}

const int Field::leftShips(){
	int max = Config::MAX_SHIPS;

	for(int s = 0; s < Config::MAX_SHIPS; s++){
		if(isKilledShip(ships_[s]))
			max--;
	};

	return max;
}

Ship* const Field::getCurrentShip(){
	for(int s = 0; s < Config::MAX_SHIPS; s++){
		if(ships_[s]->checkCell(position_))
			return ships_[s];
	}

	return NULL;
}

Ship* const Field::findShipByPosition(const COORD coord){
	for(int s = 0; s < Config::MAX_SHIPS; s++){
		if(ships_[s]->checkCell(coord))
			return ships_[s];
	}

	return NULL;
}

Ship* const Field::findShipByPosition(const int x, const int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < Config::MAX_SHIPS; s++){
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
		if(grid_[cell.X][cell.Y]->getStatus() == Cell::Full && grid_[cell.X][cell.Y]->getState() == Cell::NotClicked)
			return false;
	}

	return true;
}

void Field::draw() {
	drawField();

	drawShips();

	if(active_)
		drawCell(position_, Cell::Active);
}

void Field::drawField(){
	console->setColor(console->White, console->Black);

	console->fillLine("\xc9", "\xcd", "\xBB", width_, x_, y_);
	console->fillSquare("\xba", " ", "\xba", width_, height_-2, x_, y_+1);
	console->fillLine("\xc8", "\xcd", "\xBC", width_, x_, y_ + height_ - 1);
}

void Field::drawShips(){
	COORD coords;
	
	for(int i = 0; i < Config::FIELD_WIDTH; i++){
		for(int j = 0; j < Config::FIELD_HEIGHT; j++){
			if(active_ && position_.X == i && position_.Y == j)
				continue;

			coords.X = i;
			coords.Y = j;

			drawCell(coords, Cell::Inactive);
		}
	}
}

const int Field::checkCell(const COORD position){
	return grid_[position.X][position.Y]->getStatus();
}

const int Field::checkCell(const int x, const int y){
	return grid_[x][y]->getStatus();
}

void Field::drawCell(COORD position, const bool mode){
	console->setColor(console->White, console->Black);

	if(position.X < 0)
		position.X = 0;

	if(position.Y < 0)
		position.Y = 0;

	grid_[position.X][position.Y]->setMode(mode);
	grid_[position.X][position.Y]->openCell(isOpenShips);
	grid_[position.X][position.Y]->draw();

	console->setColor(console->White, console->Black);
}