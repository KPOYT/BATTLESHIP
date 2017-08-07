#include <conio.h>

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class StateMenu {
	public:
		StateMenu(){
			console = Console::Instance();
		};

		void draw(
			int const playerShips,
			int const botShips,
			int const time);
	protected:
		Console* console;
};