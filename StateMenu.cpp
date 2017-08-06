#include "StateMenu.h"

void StateMenu::draw(
	 int const playerShips,
	 int const botShips,
	 int const time)
{
	setColor(Black,Black);
	system("cls");
			
	if(playerShips > botShips)
		drawText(15, 7, "You win!", Green, Black);
	else
		drawText(15, 7, "You lose!", Red, Black);

	drawText(10, 10, "Your ships left:");
	drawText(28, 10, to_string(playerShips));
	drawText(10, 12, "Bot ships left:");
	drawText(28, 12, to_string(botShips));
	drawText(10, 14, "Time:");
	drawText(28, 14, to_string(time));
};