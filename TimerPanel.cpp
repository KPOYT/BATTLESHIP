#include "TimerPanel.h"

int const TimerPanel::show()
{  
	int mode = 0;
	bool choise = false;
	
	console->drawText(position.X, position.Y, description);

	redrawTimer(mode);
	
	return mode;
}

void TimerPanel::redrawTimer(
	 int const time, 
	 int const textColor,
	 int const backgroundColor)
{
	console->setColor(console->Black, console->Black);
	timer_.clear();

	timer_.push_back(0);
	timer_ += to_string(time);
	timer_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + (description.length() - timer_.length()) / 2;
	centerPos.Y = position.Y + 1;
			
	console->drawText(centerPos.X, centerPos.Y, timer_, textColor, backgroundColor);
	console->setColor(console->Black, console->Black);
}