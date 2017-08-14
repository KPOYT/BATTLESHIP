#include "StatePanel.h"

int const StatePanel::show()
{  
	int mode = 10;
	bool choise = false;
	
	console->drawText(position.X, position.Y, description);

	redrawPanel(mode);
	
	return mode;
}

void StatePanel::redrawPanel(
	 const int count, 
	 const int textColor, 
	 const int backgroundColor)
{
	console->setColor(console->Black, console->Black);
	counter_.clear();

	counter_.push_back(0);
	counter_ += to_string(count);
	counter_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + (description.length() - counter_.length()) / 2;
	centerPos.Y = position.Y + 1;

	console->drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
	console->setColor(console->Black, console->Black);
}

void StatePanel::redrawPanel(
	 const string count,
	 const int textColor,
	 const int backgroundColor)
{
	console->setColor(console->Black, console->Black);
	counter_.clear();

	counter_.push_back(0);
	counter_ += count;
	counter_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + (description.length() - counter_.length()) / 2;
	centerPos.Y = position.Y + 1;

	console->drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
	console->setColor(console->Black, console->Black);
}