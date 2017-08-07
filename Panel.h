#include <conio.h>

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Panel {
	public:
		Panel(string const desc = "Are you sure?") {
			position.X = 0; 
			position.Y = 0;
			description = desc;
			console = Console::Instance();
		};

		Panel(COORD const pos, string const desc){
			position = pos;
			description = desc;
			console = Console::Instance();
		};
		
		Panel(int const x, int const y, string const desc){
			position.X = x;
			position.Y = y;
			description = desc;
			console = Console::Instance();
		};
		
		~Panel(){};

		virtual const int show(){ return -1; };

	protected:
		virtual void redrawMenu(int mode, int textColor = 15, int backgroundColor = 0){};

		Console* console;
		COORD position;
		string description;
};