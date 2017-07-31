#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class ExitMenu : public Menu {
	public:
		ExitMenu(
			string const desc = "Are you sure"):Menu(desc){};

		ExitMenu(
			COORD const pos, 
			string const desc = "Are you sure"):Menu(pos, desc){};

		ExitMenu(
			int const x,
			int const y,
			string const desc = "Are you sure"):Menu(x, y, desc){};
	private:
		void redrawMenu(int);
		int checkKeys(int);
};

void ExitMenu::redrawMenu(int mode) {
	switch(mode)
	{
		case 0:
			drawText(35, 12, "Yes");
			drawText(42, 12, "No", 2, 0);
		break;
		case 1:
			drawText(35, 12, "Yes", 2, 0);
			drawText(42, 12, "No");
		break;
	}
}

int ExitMenu::checkKeys(int mode){
	bool choise = false;

	do 
	{
		int code = _getch();
		if (code == 224)
		{
			code = _getch();
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
					choise = true; 
				break;
				case VK_ESCAPE:
					mode = 0;
					choise = true;
				break;
			}	
		}
	} 
	while (!choise);

	return mode;
};