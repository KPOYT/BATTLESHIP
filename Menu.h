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

		virtual int const show();
	protected:
		virtual void redrawMenu(int){};
		virtual int const checkKeys(int mode){ return mode; };

		COORD position;
		string description;
};