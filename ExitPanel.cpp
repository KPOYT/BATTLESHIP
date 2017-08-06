#include "ExitPanel.h"

int const ExitPanel::show()
{  
	int mode = 0;
	
	drawText(position.X, position.Y, description);

	redrawMenu(mode);

	mode = checkKeys(mode);
	
	return mode;
}

void ExitPanel::redrawMenu(int const mode) {
	switch(mode)
	{
		case 0:
			drawText(position.X + 15, position.Y, "Yes");
			drawText(position.X + 20, position.Y, "No", 2, 0);
		break;
		case 1:
			drawText(position.X + 15, position.Y, "Yes", 2, 0);
			drawText(position.X + 20, position.Y, "No");
		break;
	}
}

int const ExitPanel::checkKeys(int mode){
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