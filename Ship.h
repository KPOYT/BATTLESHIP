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

		void addCell(COORD const cell);
		bool const checkCell(COORD const cell);
		
		int size;
		int type;
		COORD cells[4];

		enum ShipState
		{
			vertical = 0,
			horizontal = 1
		};
};