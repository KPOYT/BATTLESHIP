#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

class Bot {
	public:
		COORD const findCellToStrike();

		int grid[10][10];
		Ship* ships[10];
	private:
		void clearCells();
		int const checkCell(int const x, int const y);
		bool const checkKilledShip(Ship* const ship);
		COORD const findRandomPlace();
		Ship* const findShipByPosition(int const x, int const y);

		COORD cells_[4];

		int size_;
		int type_;

		enum ShipLocation
		{
			vertical = 0,
			horizontal = 1,
			unknown = -1
		};

		enum CellStatus
		{
			empty = 0,
			full = 1,
			hit = 2,
			miss = 3
		};
};