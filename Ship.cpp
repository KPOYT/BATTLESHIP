#include "Ship.h"

int const Ship::size() {
	return cells.size();
};

int const Ship::type() {
	return type_;
};

void Ship::addCell(COORD const cell) {
	cells.push_back(cell);

	if(cells.size() > 0){
		if(cells[0].X == cell.X)
			type_ = vertical;
		else
			type_ = horizontal;
	}
};

COORD const Ship::getCell(int const index) {
	if(index >= size()) return COORD();

	return cells[index];
}

bool const Ship::checkCell(COORD const cell) {

	for(int i = 0; i < size(); i++) {
		if(cells[i].X == cell.X && cells[i].Y == cell.Y){
			return true;
		}
	}

	return false;
};