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
	 int const count, 
	 int const textColor, 
	 int const backgroundColor)
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
	 string const count,
	 int const textColor,
	 int const backgroundColor)
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