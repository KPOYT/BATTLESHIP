#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

#ifndef CONFIG_H
#define CONFIG_H
#include "Config.h"
#endif

class Bot {
	public:
		const COORD findCellToStrike();

		Cell* grid[Config::FIELD_WIDTH][Config::FIELD_HEIGHT];
		Ship* ships[Config::MAX_SHIPS];
	private:
		void clearCells();
		const int checkCell(const int x, const int y);
		const bool checkKilledShip(Ship* const ship);
		const COORD findRandomPlace();
		Ship* const findShipByPosition(const int x, const int y);

		COORD cells_[Config::MAX_SHIP_SIZE];

		int size_;
		int type_;

		enum ShipLocation
		{
			Vertical = 0,
			Horizontal = 1,
			Unknown = -1
		};
};
