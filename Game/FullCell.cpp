#include "FullCell.h"

FullCell::FullCell(const int x,
	const int y,
	const bool mode) :Cell(x, y, mode) {};

const bool FullCell::getStatus() { return Full; };

const bool FullCell::getState() { return isClicked_; };

void FullCell::setState(const bool value) { isClicked_ = value; };

const int FullCell::getTextColor() {
	if (mode_ == Active)
		return Console::Yellow;
	else {
		switch (isClicked_) {
			case NotClicked: {
				if (isOpenCell_)
					return Console::Cyan;
					
				break;
			}
			case Clicked: {
				return Console::Red;
			}
		}

		return textColor_;
	}
}

const int FullCell::getBackgroundColor() {
	if (mode_ == Active)
		return Console::Yellow;
	else {
		switch (isClicked_) {
			case NotClicked: {
				if (isOpenCell_)
					return Console::Cyan;

				break;
			}
			case Clicked: {
				return Console::Red;
			}
		}

		return backgroundColor_;
	}
}