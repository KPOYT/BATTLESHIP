#ifndef SHIP_H
#define SHIP_H
#include "Ship.h"
#endif

class Bot {
	public:
		Bot(){};
		
		COORD findCellToStrike(){
			COORD coord;

			srand(GetTickCount());

			int time = 500 + rand() % 5000;

			coord = findRandomPlace();

			Sleep(time);

			return coord;
		};

		int grid[10][10];
		Ship* ships[10];
	private:
		COORD findRandomPlace() {
			bool find = false;
			COORD coord;

			srand(GetTickCount());

			do
			{
				int x = 0 + rand() %10;
				int y = 0 + rand() %10;

				int cell = checkCell(x, y);
				switch(cell){
					case empty:
						coord.X = x;
						coord.Y = y;
						find = true;
					break;
					case full:
						Ship* ship = getShipByPosition(x, y);

						coord.X = x;
						coord.Y = y;

						if(!checkKilledShip(ship) && ship->size > 1){
							size = ship->size;
							cells[0] = coord;
							type = unknown;
						} else {
							clearCells();
						}

						find = true;
					break;
				}
			} while(!find);

			return coord;
		};
		void clearCells(){
			for(int i = 0; i < 4; i++){
				cells[i].X = -1;
				cells[i].Y = -1;
			}
		};
		int const checkCell(int x, int y){
			return grid[x][y];
		}
		bool checkKilledShip(Ship* ship) {
			for(int j = 0; j < ship->size; j++){
				COORD cell = ship->cells[j];
				if(grid[cell.X][cell.Y] != hit)
					return false;
			}
			
			return true;
		}

		Ship* getShipByPosition(int x, int y){
			COORD coord;
			coord.X = x;
			coord.Y = y;

			for(int s = 0; s < 10; s++){
				if(ships[s]->checkCell(coord))
				{
					return ships[s];
				}
			}

			return NULL;
		}

		COORD lastStrike;
		COORD cells[4];

		int size;
		int type;
		enum ShipState
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