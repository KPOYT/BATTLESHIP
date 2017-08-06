#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class ExitMenu : public Menu {
	public:
		ExitMenu(
			string const desc = "Are you sure"):Menu(desc){};

		ExitMenu(
			COORD const pos, 
			string const desc = "Are you sure"):Menu(pos, desc){};

		ExitMenu(
			int const x,
			int const y,
			string const desc = "Are you sure"):Menu(x, y, desc){};
	private:
		void redrawMenu(int);
		int const checkKeys(int);
};