#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

class Bot {
	public:
		const COORD findCellToStrike();

		int grid[10][10];
		Ship* ships[10];
	private:
		void clearCells();
		const int checkCell(const int x, const int y);
		const bool checkKilledShip(Ship* const ship);
		const COORD findRandomPlace();
		Ship* const findShipByPosition(const int x, const int y);

		COORD cells_[4];

		int size_;
		int type_;

		enum ShipLocation
		{
			Vertical = 0,
			Horizontal = 1,
			Unknown = -1
		};

		enum CellState
		{
			Empty = 0,
			Full = 1,
			Hit = 2,
			Miss = 3
		};
};