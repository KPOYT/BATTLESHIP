#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class MainMenu : public Menu {
	public:
		MainMenu(
			string const desc = ""):Menu(desc){};

		MainMenu(
			COORD const pos, 
			string const desc = ""):Menu(pos, desc){};

		MainMenu(
			int const x,
			int const y,
			string const desc = ""):Menu(x, y, desc){};
	private:
		void redrawMenu(int);
		int checkKeys(int);
};

void MainMenu::redrawMenu(int mode) {
	switch(mode)
	{
		case 0:
			drawText(35, 10, "New game", 2, 0);
			drawText(37, 12, "Exit");
		break;
		case 1:
			drawText(35, 10, "New game");
			drawText(37, 12, "Exit", 2, 0);
		break;
	}
}

int MainMenu::checkKeys(int mode){
	bool choise = false;

	do 
	{
		int code = _getch();
		if (code == 224)
		{
			code = _getch();
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
					choise = true;
				break;
				case VK_ESCAPE:
					mode = 1;
					choise = true;
				break;
			}	
		}
	} 
	while (!choise);

	return mode;
};