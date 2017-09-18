#include "Bot.h"

const COORD Bot::findCellToStrike(){
	COORD coord;

	srand(GetTickCount());

	int time = 500 + rand() % 5000;

	coord = findRandomPlace();

	Sleep(time);

	return coord;
};

void Bot::clearCells(){
	for(int i = 0; i < 4; i++){
		cells_[i].X = -1;
		cells_[i].Y = -1;
	}
};

const int Bot::checkCell(const int x, const int y){
	return grid[x][y]->getStatus();
}

const bool Bot::checkKilledShip(Ship* const ship) {
	for(int j = 0; j < ship->size(); j++){
		COORD cell = ship->getCell(j);

		if(cell.X < 0 
			|| cell.Y < 0 
			|| cell.X >= Config::FIELD_WIDTH 
			|| cell.Y >= Config::FIELD_HEIGHT) continue;

		//if(grid[cell.X][cell.Y]->getStatus() != Cell::Hit)
		if (grid[cell.X][cell.Y]->getStatus() == Cell::Full && grid[cell.X][cell.Y]->getState() == Cell::NotClicked)
			return false;
	}
			
	return true;
}

Ship* const Bot::findShipByPosition(const int x, const int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < Config::MAX_SHIPS; s++){
		if(ships[s]->checkCell(coord))
			return ships[s];
	}

	return NULL;
}

const COORD Bot::findRandomPlace() {
	COORD coord;

	srand(GetTickCount());

	bool isDone = false;
	do
	{
		int x = rand() % Config::FIELD_WIDTH;
		int y = rand() % Config::FIELD_HEIGHT;
		
		int c = checkCell(x, y);
		switch(c){
			case Cell::Empty:
				coord.X = x;
				coord.Y = y;
				isDone = true;
			break;
			case Cell::Full:
				Ship* ship = findShipByPosition(x, y);

				coord.X = x;
				coord.Y = y;

				if(!checkKilledShip(ship) && ship->size() > 1){
					size_ = ship->size();
					cells_[0] = coord;
					type_ = Unknown;
				} 
				else
					clearCells();

				isDone = true;
			break;
		}
	} while(!isDone);

	return coord;
};