#include "TimerPanel.h"

TimerPanel::TimerPanel(const string desc):Panel(desc)
{
	isFinished = false;
};

TimerPanel::TimerPanel(const COORD pos, 
					const string desc):Panel(pos, desc)
{
	isFinished = false;
};

TimerPanel::TimerPanel(
	const int x, 
	const int y, 
	const string desc):Panel(x, y, desc)
{
	isFinished = false;
};

TimerPanel::~TimerPanel()
{
	console->fillLine(" ", timer_.length(), position.X, position.Y + 1, false);
};

const int TimerPanel::show()
{  
	int mode = 0;
	bool choise = false;
	
	console->drawText(position.X, position.Y, description);

	redrawTimer(mode);
	
	return mode;
}

void TimerPanel::redrawTimer(
	 const int time, 
	 const int textColor,
	 const int backgroundColor)
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