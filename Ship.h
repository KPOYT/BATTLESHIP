#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Ship {
	public:
		Ship();

		void addCell(const COORD cell);
		const COORD getCell(const int index);
		const bool checkCell(const COORD cell);

		const int size();
		const int type();

		enum ShipLocation
		{
			Vertical = 0,
			Horizontal = 1
		};
	private:
		int type_;
		vector<COORD> cells;
};