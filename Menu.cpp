#include "Menu.h"

int const Menu::show()
{
	int mode = 0;
	bool choise = false;

	setColor(0,0);
    system("cls");
	
	drawText(position.X, position.Y, description);

	redrawMenu(mode);

	mode = checkKeys(mode);
	
	return mode;
}