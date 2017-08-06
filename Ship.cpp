#include "Ship.h"

void Ship::addCell(COORD const cell) {
	for(int i = 0; i < size; i++) {
		if(cells[i].X < 0 || cells[i].Y < 0){
			cells[i] = cell;
			break;
		}
	}
};

bool const Ship::checkCell(COORD const cell) {
	for(int i = 0; i < size; i++) {
		if(cells[i].X == cell.X && cells[i].Y == cell.Y){
			return true;
		}
	}

	return false;
};