#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

Menu::Menu(const string desc)
{
	position.X = 0;
	position.Y = 0;
	description = desc;
	console = Console::Instance();
};

Menu::Menu(const COORD pos, const string desc)
{
	position = pos;
	description = desc;
	console = Console::Instance();
};

Menu::Menu(const int x,
			const int y,
			const string desc)
{
	position.X = x;
	position.Y = y;
	description = desc;
	console = Console::Instance();
};

const int Menu::show()
{
	int mode = 0;
	bool choise = false;

	console->setColor(0,0);
    system("cls");
	
	console->drawText(position.X, position.Y, description);

	redrawMenu(mode);

	mode = checkKeys(mode);
	
	return mode;
}