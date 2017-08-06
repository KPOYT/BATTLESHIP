#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class MainMenu : public Menu {
	public:
		MainMenu(
			string const desc = ""):Menu(desc){};

		MainMenu(
			COORD const pos, 
			string const desc = ""):Menu(pos, desc){};

		MainMenu(
			int const x,
			int const y,
			string const desc = ""):Menu(x, y, desc){};
	private:
		void redrawMenu(int);
		int const checkKeys(int);
};