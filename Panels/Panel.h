#include <conio.h>

/*#ifndef CONFIG_H
#define CONFIG_H
#include "..\Config.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "..\Console.h"
#endif*/

#ifndef OS_H
#define OS_H
#include "..\ApplicationOS\OS.h"
#endif

using namespace std;

class Panel {
	public:
		Panel(const string desc);

		Panel(const COORD pos, const string desc);
		
		Panel(const int x, const int y, const string desc);

		virtual const int show();

	protected:
		virtual void redrawMenu(
							int mode, 
							int textColor = OSConsole::White, 
							int backgroundColor = OSConsole::Black);

		OSConsole* console;
		COORD position;
		string description;
};