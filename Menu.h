#include <conio.h>

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Menu {
	public:
		Menu( 
			string const desc = "Are you sure?")
		{
			position.X = 0;
			position.Y = 0;
			description = desc;
			console = Console::Instance();
		};

		Menu(
			 COORD const pos, 
			 string const desc = "Are you sure?")
		{
			position = pos;
			description = desc;
			console = Console::Instance();
		};

		Menu(
			 int const x,
			 int const y,
			 string const desc = "Are you sure?")
		{
			position.X = x;
			position.Y = y;
			description = desc;
			console = Console::Instance();
		};

		virtual int const show();
	protected:
		virtual void redrawMenu(int){};
		virtual int const checkKeys(int mode){ return mode; };

		Console* console;

		COORD position;
		string description;
};