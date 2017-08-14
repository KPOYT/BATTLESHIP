#include "Ship.h"

Ship::Ship() {
	type_ = Vertical;
};

const int Ship::size() {
	return cells.size();
};

const int Ship::type() {
	return type_;
};

void Ship::addCell(const COORD cell) {
	cells.push_back(cell);

	if(cells.size() > 0){
		if(cells[0].X == cell.X)
			type_ = Vertical;
		else
			type_ = Horizontal;
	}
};

const COORD Ship::getCell(const int index) {
	if(index >= size()) return COORD();

	return cells[index];
}

const bool Ship::checkCell(const COORD cell) {

	for(int i = 0; i < size(); i++) {
		if(cells[i].X == cell.X && cells[i].Y == cell.Y){
			return true;
		}
	}

	return false;
};