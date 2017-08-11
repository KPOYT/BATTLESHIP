#include <conio.h>

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Menu {
	public:
		Menu(const string desc = "Are you sure?");

		Menu(const COORD pos, 
			 const string desc = "Are you sure?");

		Menu(const int x,
			 const int y,
			 const string desc = "Are you sure?");

		virtual const int show();
	protected:
		virtual void redrawMenu(int){};
		virtual const int checkKeys(int mode){ return mode; };

		Console* console;

		COORD position;
		string description;
};