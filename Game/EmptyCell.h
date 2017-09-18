#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

class EmptyCell : public Cell {
	public:
		EmptyCell(const int x,
			const int y,
			const int textColor = Console::White,
			const int backgroundColor = Console::Black,
			const int width = Config::CELL_VIEW_WIDTH,
			const int height = Config::CELL_VIEW_HEIGHT,
			const bool mode = Cell::Inactive);

		const bool getStatus();

		const bool getState();
		void setState(const bool value);
	protected:
		virtual const int getTextColor();
		virtual const int getBackgroundColor();
};