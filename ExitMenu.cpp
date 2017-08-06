#include "ExitMenu.h"

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

int const ExitMenu::checkKeys(int mode){
	bool isDone = false;
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