#include "EmptyCell.h"

EmptyCell::EmptyCell(const int x,
	const int y,
	const bool mode):Cell(x, y, mode) {};

const bool EmptyCell::getStatus() { return Empty; };

const bool EmptyCell::getState() { return isClicked_; };

void EmptyCell::setState(const bool value) { isClicked_ = value; };

const int EmptyCell::getTextColor() {
	if (mode_ == Active)
		return Console::Yellow;
	else {
		switch (isClicked_) {
			case Clicked: {
				return Console::Magenta;
			}
		}

		return textColor_;
	}
}

const int EmptyCell::getBackgroundColor() {
	if (mode_ == Active)
		return Console::Yellow;
	else {
		switch (isClicked_) {
			case Clicked: {
				return Console::Magenta;
			}
		}

		return backgroundColor_;
	}
}