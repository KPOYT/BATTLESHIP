#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class ExitPanel : public Panel {
	public:
		ExitPanel(
			string const desc = "Are you sure?"):Panel(desc) {};

		ExitPanel(
			COORD const pos, 
			string const desc = "Are you sure?"):Panel(pos, desc) {};
		
		ExitPanel(
			int const x, 
			int const y, 
			string const desc = "Are you sure?"):Panel(x, y, desc) {};
		
		~ExitPanel(){
			fillLine(" ", description.length() + 9, position.X, position.Y, false);
		};

		int show()
		{  
			int mode = 0;
	
			drawText(position.X, position.Y, description);

			redrawMenu(mode);

			mode = checkKeys(mode);
	
			return mode;
		}
	private:
		void redrawMenu(int mode) {
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

		int checkKeys(int mode);
};

int ExitPanel::checkKeys(int mode){
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