#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class MainMenu : public Menu {
	public:
		MainMenu(
			const string desc = "");

		MainMenu(
			const COORD pos, 
			const string desc = "");

		MainMenu(
			const int x,
			const int y,
			const string desc = "");
	private:
		void redrawMenu(const int);
		const int checkKeys(int);
};