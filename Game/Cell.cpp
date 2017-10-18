#include "Cell.h"

Cell::Cell(const int x,
			 const int y,
			 const bool mode)
{
	x_ = x;
	y_ = y;
	textColor_ = OSConsole::White;
	backgroundColor_ = OSConsole::Black;
	width_ = OSConfig::CELL_VIEW_WIDTH;
	height_ = OSConfig::CELL_VIEW_HEIGHT;
	isClicked_ = NotClicked;
	mode_ = mode;
};

void Cell::draw() {
	OSConsole* console = OS::GetOSFactory()->GetConsole();
	
	console->setColor(getTextColor(), getBackgroundColor());

	console->fillSquare(" ", width_, height_, x_, y_);

	console->setColor(OSConsole::White, OSConsole::Black);
};

const bool Cell::getState() { return isClicked_; };

void Cell::setState(const bool value) { isClicked_ = value; };

const bool Cell::getStatus() { return Undefined; };

void Cell::setMode(const bool value) { mode_ = value; };

const bool Cell::getMode() { return mode_; };

void Cell::openCell(const bool isOpenCell) { isOpenCell_ = isOpenCell; };

const int Cell::getTextColor() {
	if(mode_ == Active)
		return OSConsole::Yellow;
	else {
		return textColor_;
	}
}

const int Cell::getBackgroundColor() {
	if(mode_ == Active)
		return OSConsole::Yellow;
	else {
		return backgroundColor_;
	}
}