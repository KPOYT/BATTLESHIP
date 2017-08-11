#ifndef CELL_H
#define CELL_H
#include "Cell.h"
#endif

Cell::Cell(const int x,
			 const int y,
			 const int textColor,
			 const int backgroundColor,
			 const int width,
			 const int height)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
	textColor_ = textColor;
	backgroundColor_ = backgroundColor;
};

void Cell::draw() {
	Console* console = Console::Instance();

	console->setColor(textColor_, backgroundColor_);

	console->fillSquare(" ", width_, height_, x_, y_);

	console->setColor(console->White, console->Black);
};