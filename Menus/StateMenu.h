#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#endif

class StateMenu : public Menu {
	public:
		const int show(
			const int playerShips,
			const int botShips,
			const int time);
};