#include "Bot.h"

COORD const Bot::findCellToStrike(){
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

int const Bot::checkCell(int const x, int const y){
	return grid[x][y];
}

bool const Bot::checkKilledShip(Ship* const ship) {
	for(int j = 0; j < ship->size; j++){
		COORD cell = ship->cells[j];
		if(grid[cell.X][cell.Y] != hit)
			return false;
	}
			
	return true;
}

Ship* const Bot::findShipByPosition(int const x, int const y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < 10; s++){
		if(ships[s]->checkCell(coord))
			return ships[s];
	}

	return NULL;
}

COORD const Bot::findRandomPlace() {
	COORD coord;

	srand(GetTickCount());

	bool isDone = false;
	do
	{
		int x = rand() %10;
		int y = rand() %10;
		
		int c = checkCell(x, y);
		switch(c){
			case empty:
				coord.X = x;
				coord.Y = y;
				isDone = true;
			break;
			case full:
				Ship* ship = findShipByPosition(x, y);

				coord.X = x;
				coord.Y = y;

				if(!checkKilledShip(ship) && ship->size > 1){
					size_ = ship->size;
					cells_[0] = coord;
					type_ = unknown;
				} 
				else
					clearCells();

				isDone = true;
			break;
		}
	} while(!isDone);

	return coord;
};