#include "StatePanel.h"

StatePanel::StatePanel(
	const string desc):Panel(desc) {};
		
StatePanel::StatePanel(
	const COORD pos, 
	const string desc):Panel(pos, desc){};
		
StatePanel::StatePanel(
	const int x, 
	const int y, 
	const string desc):Panel(x, y, desc) {};
		
StatePanel::~StatePanel(){
	console->fillSquare(" ", 8, 2, position.X - 1, position.Y);
};

int const StatePanel::show()
{  
	int mode = OSConfig::MAX_SHIPS;
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
	centerPos.X = position.X + static_cast<SHORT>(description.length() - counter_.length()) / 2;
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
	centerPos.X = position.X + static_cast<SHORT>(description.length() - counter_.length()) / 2;
	centerPos.Y = position.Y + 1;

	console->drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
	console->setColor(console->Black, console->Black);
}