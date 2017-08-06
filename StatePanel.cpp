#include "StatePanel.h"

int const StatePanel::show()
{  
	int mode = 10;
	bool choise = false;
	
	drawText(position.X, position.Y, description);

	redrawPanel(mode);
	
	return mode;
}

void StatePanel::redrawPanel(
	 int const count, 
	 int const textColor, 
	 int const backgroundColor)
{
	setColor(Black, Black);
	counter_.clear();

	counter_.push_back(0);
	counter_ += to_string(count);
	counter_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + (description.length() - counter_.length()) / 2;
	centerPos.Y = position.Y + 1;

	drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
	setColor(Black, Black);
}

void StatePanel::redrawPanel(
	 string const count,
	 int const textColor,
	 int const backgroundColor)
{
	setColor(Black, Black);
	counter_.clear();

	counter_.push_back(0);
	counter_ += count;
	counter_.push_back(0);

	COORD centerPos;
	centerPos.X = position.X + (description.length() - counter_.length()) / 2;
	centerPos.Y = position.Y + 1;

	drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
	setColor(Black, Black);
}