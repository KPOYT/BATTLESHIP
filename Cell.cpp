#include "Cell.h"

void Cell::draw() {
	setColor(textColor_, backgroundColor_);

	fillSquare(" ", width_, height_, x_, y_);

	setColor(15, 0);
}