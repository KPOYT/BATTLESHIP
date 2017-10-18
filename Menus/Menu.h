#include <conio.h>

#ifndef OS_H
#define OS_H
#include "..\ApplicationOS\OS.h"
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
		virtual void redrawMenu(const int);
		virtual const int checkKeys(int mode);

		OSConsole* console;

		COORD position;
		string description;
};