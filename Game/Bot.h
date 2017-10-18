#ifndef OS_H
#define OS_H
#include "../ApplicationOS/OS.h"
#endif

#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

class Bot {
	public:
		const COORD findCellToStrike();

		Cell* grid[OSConfig::FIELD_WIDTH][OSConfig::FIELD_HEIGHT];
		Ship* ships[OSConfig::MAX_SHIPS];
	private:
		const int checkCell(const int x, const int y);
		const bool checkKilledShip(Ship* const ship);
		const COORD findRandomPlace();
		Ship* const findShipByPosition(const int x, const int y);

		COORD cells_[OSConfig::MAX_SHIP_SIZE];

		int size_;
		int type_;

		enum ShipLocation
		{
			Vertical = 0,
			Horizontal = 1,
			Unknown = -1
		};
};
