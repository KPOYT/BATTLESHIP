#include "MainMenu.h"

MainMenu::MainMenu(
	const string desc):Menu(desc){};

MainMenu::MainMenu(
	const COORD pos, 
	const string desc):Menu(pos, desc){};

MainMenu::MainMenu(
	const int x,
	const int y,
	const string desc):Menu(x, y, desc){};

void MainMenu::redrawMenu(const int mode) {
	switch(mode)
	{
		case 0:
			console->drawText(35, 10, "New game", console->Green, console->Black);
			console->drawText(37, 12, "Exit");
		break;
		case 1:
			console->drawText(35, 10, "New game");
			console->drawText(37, 12, "Exit", console->Green, console->Black);
		break;
	}
}

const int MainMenu::checkKeys(int mode){
	bool isDone = false;
	do 
	{
		int code = console->getCodeFromKeyboard();
		if (code == 224)
		{
			code = console->getCodeFromKeyboard();
			switch(code) 
			{
				case 80: {
					mode++;
					if(mode > 1)
						mode = 0;

					redrawMenu(mode);
					break;
				}	 
				case 72: {
					mode--;
					if(mode < 0)
						mode = 1;

					redrawMenu(mode);
					break;
				}
			}
		}
		else 
		{
			switch(code)
			{
				case VK_RETURN: 
					isDone = true;
				break;
				case VK_ESCAPE:
					mode = 1;
					isDone = true;
				break;
			}	
		}
	} 
	while (!isDone);

	return mode;
};