#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class ExitMenu : public Menu {
	public:
		ExitMenu(
			const string desc = "Are you sure");

		ExitMenu(
			const COORD pos, 
			const string desc = "Are you sure");

		ExitMenu(
			const int x,
			const int y,
			const string desc = "Are you sure");
	private:
		void redrawMenu(const int);
		const int checkKeys(int);
};