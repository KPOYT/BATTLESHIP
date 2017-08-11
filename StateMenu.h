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
			const int playerShips,
			const int botShips,
			const int time);
	protected:
		Console* console;
};