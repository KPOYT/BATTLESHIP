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
	console->fillLine(" ", static_cast<int>(timer_.length()), position.X, position.Y + 1, false);
};

const int TimerPanel::show()
{
	bool choise = false;
	
	console->drawText(position.X, position.Y, description);

	redrawPanel(NULL);
	
	return NULL;
}

void TimerPanel::redrawPanel(
	 const int time, 
	 const int textColor,
	 const int backgroundColor)
{
	timer_.clear();

	timer_.push_back(0);
	timer_ += to_string(time);
	timer_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + static_cast<SHORT>(description.length() - timer_.length()) / 2;
	centerPos.Y = position.Y + 1;
			
	console->drawText(centerPos.X, centerPos.Y, timer_, textColor, backgroundColor);
}