#include "Cell.h"

Cell::Cell(const int x,
			 const int y,
			 const int textColor,
			 const int backgroundColor,
			 const int width,
			 const int height,
			 const bool mode)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
	textColor_ = textColor;
	backgroundColor_ = backgroundColor;
	isClicked_ = NotClicked;
	mode_ = mode;
};

void Cell::draw() {
	Console* console = Console::Instance();
	
	console->setColor(getTextColor(), getBackgroundColor());

	console->fillSquare(" ", width_, height_, x_, y_);

	console->setColor(Console::White, Console::Black);
};

const bool Cell::getState() {
	return isClicked_;
};

void Cell::setState(const bool value) {
	isClicked_ = value;
};

const bool Cell::getStatus() {
	return Undefined;
};

void Cell::setMode(const bool value) {
	mode_ = value;
};

const bool Cell::getMode() {
	return mode_;
};

void Cell::openCell(const bool isOpenCell) {
	isOpenCell_ = isOpenCell;
};

const int Cell::getTextColor() {
	if(mode_ == Active)
		return Console::Yellow;
	else {
		return textColor_;
	}
}

const int Cell::getBackgroundColor() {
	if(mode_ == Active)
		return Console::Yellow;
	else {
		return backgroundColor_;
	}
}