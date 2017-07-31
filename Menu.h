#include <conio.h>

#ifndef GRAPHYCALELEMENT_H
#define GRAPHYCALELEMENT_H
#include "GraphycalElement.h"
#endif

using namespace std;

class Menu : public GraphycalElement {
	public:
		Menu( 
			string const desc = "Are you sure?")
		{
			position.X = 0;
			position.Y = 0;
			description = desc;
		};

		Menu(
			COORD const pos, 
			string const desc = "Are you sure?")
		{
			position = pos;
			description = desc;
		};

		Menu(
			int const x,
			int const y,
			string const desc = "Are you sure?")
		{
			position.X = x;
			position.Y = y;
			description = desc;
		};

		virtual int show();
	protected:
		virtual void redrawMenu(int){};
		virtual int checkKeys(int mode){ return mode; };

		COORD position;
		string description;
};

int Menu::show()
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