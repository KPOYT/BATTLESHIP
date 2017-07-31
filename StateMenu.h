#include <conio.h>

#ifndef GRAPHYCALELEMENT_H
#define GRAPHYCALELEMENT_H
#include "GraphycalElement.h"
#endif

using namespace std;

class StateMenu : public GraphycalElement {
	public:
		StateMenu(){};
		~StateMenu(){};
		void draw(int const playerShips, int const botShips, int const time){
			setColor(0,0);
			system("cls");
			
			if(playerShips > botShips)
				drawText(15, 7, "You win!", 2, 0);
			else
				drawText(15, 7, "You lose!", 4, 0);

			drawText(10, 10, "Your ships left:");
			drawText(28, 10, to_string(playerShips));
			drawText(10, 12, "Bot ships left:");
			drawText(28, 12, to_string(botShips));
			drawText(10, 14, "Time:");
			drawText(28, 14, to_string(time));
		};
};