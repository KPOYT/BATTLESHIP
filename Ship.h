#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Ship {
	public:
		Ship(){
			type_ = vertical;
		};

		void addCell(COORD const cell);
		COORD const getCell(int const index);
		bool const checkCell(COORD const cell);

		int const size();
		int const type();

		enum ShipState
		{
			vertical = 0,
			horizontal = 1
		};
	private:
		int type_;
		vector<COORD> cells;
};