#ifndef BOT_H
#define BOT_H
#include "Bot.h"
#endif

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
	return grid[x][y];
}

const bool Bot::checkKilledShip(Ship* const ship) {
	for(int j = 0; j < ship->size(); j++){
		COORD cell = ship->getCell(j);
		if(grid[cell.X][cell.Y] != Hit)
			return false;
	}
			
	return true;
}

Ship* const Bot::findShipByPosition(const int x, const int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < 10; s++){
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
		int x = rand() %10;
		int y = rand() %10;
		
		int c = checkCell(x, y);
		switch(c){
			case Empty:
				coord.X = x;
				coord.Y = y;
				isDone = true;
			break;
			case Full:
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