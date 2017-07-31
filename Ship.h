#include <iostream>
#include <windows.h>

using namespace std;

class Ship {
	public:
		Ship(){
			size = 0;
			type = vertical;
		};
		Ship(int size_){
			size = size_;
		};

		void addCell(COORD const cell) {
			for(int i = 0; i < size; i++) {
				if(cells[i].X < 0 || cells[i].Y < 0){
					cells[i] = cell;
					break;
				}
			}
		};
		bool checkCell(COORD const cell) {
			for(int i = 0; i < size; i++) {
				if(cells[i].X == cell.X && cells[i].Y == cell.Y){
					return true;
				}
			}

			return false;
		}

		COORD cells[4];
		int size;
		int type;

		enum ShipState
		{
			vertical = 0,
			horizontal = 1
		};
};