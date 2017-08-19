#include "Cell.h"

Cell::Cell(const int x,
			 const int y,
			 const int textColor,
			 const int backgroundColor,
			 const int width,
			 const int height,
			 const int status,
			 const bool mode)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
	textColor_ = textColor;
	backgroundColor_ = backgroundColor;
	status_ = status;
	mode_ = mode;
};

void Cell::draw() {
	Console* console = Console::Instance();
	
	console->setColor(getTextColor(), getBackgroundColor());

	console->fillSquare(" ", width_, height_, x_, y_);

	console->setColor(Console::White, Console::Black);
};

void Cell::setStatus(const int value) {
	status_ = value;
};

const int Cell::getStatus() {
	return status_;
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
		switch(status_){
			case Full:{
				if(isOpenCell_)
					return Console::Cyan;

				break;
			}
			case Miss:{
				return Console::Magenta;
			}
			case Hit:{
				return Console::Red;
			}
		}

		return textColor_;
	}
}

const int Cell::getBackgroundColor() {
	if(mode_ == Active)
		return Console::Yellow;
	else {
		switch(status_){
			case Full:{
				if(isOpenCell_)
					return Console::Cyan;

				break;
			}
			case Miss:{
				return Console::Magenta;
			}
			case Hit:{
				return Console::Red;
			}
		}

		return backgroundColor_;
	}
}