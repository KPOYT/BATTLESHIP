#include <windows.h>

using namespace std;

class Bot {
	public:
		Bot(Field* field_){
			field = field_;
		};
		
		COORD findCellToStrike();
	private:
		COORD findRandomPlace();
		void clearCells();

		Field* field;
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

COORD Bot::findCellToStrike(){
	COORD coord;

	srand(GetTickCount());

	int time = 500 + rand() % 5000;

	coord = findRandomPlace();

	Sleep(time);

	return coord;
}

COORD Bot::findRandomPlace() {
	bool find = false;
	COORD coord;

	srand(GetTickCount());

	do
	{
		int x = 0 + rand() %10;
		int y = 0 + rand() %10;

		int cell = field->checkCell(x, y);
		switch(cell){
			case empty:
				coord.X = x;
				coord.Y = y;
				find = true;
			break;
			case full:
				Ship* ship = field->getShipByPosition(x, y);

				coord.X = x;
				coord.Y = y;

				if(!field->checkKilledShip(ship) && ship->size > 1){
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
}

void Bot::clearCells(){
	for(int i = 0; i < 4; i++){
		cells[i].X = -1;
		cells[i].Y = -1;
	}
}