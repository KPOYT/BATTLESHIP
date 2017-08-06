#include <conio.h>

#ifndef GRAPHYCALELEMENT_H
#define GRAPHYCALELEMENT_H
#include "GraphycalElement.h"
#endif

using namespace std;

class Panel : public GraphycalElement {
	public:
		Panel(string const desc = "Are you sure?") {
			position.X = 0; 
			position.Y = 0;
			description = desc;
		};

		Panel(COORD const pos, string const desc){
			position = pos;
			description = desc;
		};
		
		Panel(int const x, int const y, string const desc){
			position.X = x;
			position.Y = y;
			description = desc;
		};
		
		~Panel(){
		};

		virtual const int show(){ return -1; };

	protected:
		virtual void redrawMenu(int mode, int textColor = 15, int backgroundColor = 0){};

		COORD position;
		string description;
};