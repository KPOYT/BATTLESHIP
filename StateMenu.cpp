#include "StateMenu.h"

void StateMenu::draw(
	 int const playerShips,
	 int const botShips,
	 int const time)
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