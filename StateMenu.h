#include <conio.h>

#ifndef GRAPHYCALELEMENT_H
#define GRAPHYCALELEMENT_H
#include "GraphycalElement.h"
#endif

using namespace std;

class StateMenu : public GraphycalElement {
	public:
		void draw(
			int const playerShips,
			int const botShips,
			int const time);
};