#include "ExitMenu.h"

ExitMenu::ExitMenu(
	const string desc):Menu(desc){};

ExitMenu::ExitMenu(
	const COORD pos, 
	const string desc):Menu(pos, desc){};

ExitMenu::ExitMenu(
	const int x,
	const int y,
	const string desc):Menu(x, y, desc){};

void ExitMenu::redrawMenu(const int mode) {
	switch(mode)
	{
		case 0:
			console->drawText(35, 12, "Yes");
			console->drawText(42, 12, "No", console->Green, console->Black);
		break;
		case 1:
			console->drawText(35, 12, "Yes", console->Green, console->Black);
			console->drawText(42, 12, "No");
		break;
	}
}

const int ExitMenu::checkKeys(int mode){
	bool isDone = false;
	do 
	{
		int code = console->getCodeFromKeyboard();
		if (code == 224)
		{
			code = console->getCodeFromKeyboard();
			switch(code) 
			{
			case 77: {
				mode++;
				if(mode > 1)
					mode = 0;

				redrawMenu(mode);
				break;
			}	 
			case 75: {
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
					mode = 0;
					isDone = true;
				break;
			}	
		}
	} 
	while (!isDone);

	return mode;
};