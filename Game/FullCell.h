#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

class FullCell : public Cell {
	public:
		FullCell(const int x,
			const int y,
			const bool mode = Cell::Inactive);

		const bool getStatus();

		const bool getState();
		void setState(const bool value);
	protected:
		virtual const int getTextColor();
		virtual const int getBackgroundColor();
};