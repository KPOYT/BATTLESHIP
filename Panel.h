#include <conio.h>

#ifndef CONFIG_H
#define CONFIG_H
#include "Config.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Panel {
	public:
		Panel(const string desc = "Are you sure?");

		Panel(const COORD pos, const string desc);
		
		Panel(const int x, const int y, const string desc);

		virtual const int show(){ return -1; };

	protected:
		virtual void redrawMenu(int mode, int textColor = 15, int backgroundColor = 0){};

		Console* console;
		COORD position;
		string description;
};