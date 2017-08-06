#include "TimerPanel.h"

int const TimerPanel::show()
{  
	int mode = 0;
	bool choise = false;
	
	drawText(position.X, position.Y, description);

	redrawTimer(mode);
	
	return mode;
}

void TimerPanel::redrawTimer(
	 int const time, 
	 int const textColor,
	 int const backgroundColor)
{
	setColor(Black, Black);
	timer_.clear();

	timer_.push_back(0);
	timer_ += to_string(time);
	timer_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + (description.length() - timer_.length()) / 2;
	centerPos.Y = position.Y + 1;
			
	drawText(centerPos.X, centerPos.Y, timer_, textColor, backgroundColor);
	setColor(Black, Black);
}