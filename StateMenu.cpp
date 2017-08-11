#ifndef STATEMENU_H
#define STATEMENU_H
#include "StateMenu.h"
#endif

StateMenu::StateMenu()
{
	console = Console::Instance();
};

void StateMenu::draw(
	 const int playerShips,
	 const int botShips,
	 const int time)
{
	console->setColor(console->Black, console->Black);
	system("cls");
			
	if(playerShips > botShips)
		console->drawText(15, 7, "You win!", console->Green, console->Black);
	else
		console->drawText(15, 7, "You lose!", console->Red, console->Black);

	console->drawText(10, 10, "Your ships left:");
	console->drawText(28, 10, to_string(playerShips));
	console->drawText(10, 12, "Bot ships left:");
	console->drawText(28, 12, to_string(botShips));
	console->drawText(10, 14, "Time:");
	console->drawText(28, 14, to_string(time));
};