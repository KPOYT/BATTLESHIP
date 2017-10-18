#include "Bot.h"

const COORD Bot::findCellToStrike() {
	COORD coord;

	srand(GetTickCount());

	int time = OSConfig::MIN_BOT_WAITING + rand() % OSConfig::MAX_BOT_WAITING;

	coord = findRandomPlace();

	Sleep(time);

	return coord;
};

const int Bot::checkCell(const int x, const int y) { return grid[x][y]->getStatus(); }

const bool Bot::checkKilledShip(Ship* const ship) {
	for(int j = 0; j < ship->size(); j++){
		COORD cell = ship->getCell(j);

		if(cell.X < 0 
			|| cell.Y < 0 
			|| cell.X >= OSConfig::FIELD_WIDTH 
			|| cell.Y >= OSConfig::FIELD_HEIGHT) continue;

		if (grid[cell.X][cell.Y]->getStatus() == Cell::Full && grid[cell.X][cell.Y]->getState() == Cell::NotClicked)
			return false;
	}
			
	return true;
}

Ship* const Bot::findShipByPosition(const int x, const int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;

	for(int s = 0; s < OSConfig::MAX_SHIPS; s++){
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
		int x = rand() % OSConfig::FIELD_WIDTH;
		int y = rand() % OSConfig::FIELD_HEIGHT;
		
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

				isDone = true;
			break;
		}
	} while(!isDone);

	return coord;
};