#include "Panel.h"

Panel::Panel(string const desc) {
	position.X = 0; 
	position.Y = 0;
	description = desc;
	console = Console::Instance();
};

Panel::Panel(const COORD pos, const string desc){
	position = pos;
	description = desc;
	console = Console::Instance();
};

Panel::Panel(const int x, const int y, const string desc){
	position.X = x;
	position.Y = y;
	description = desc;
	console = Console::Instance();
};

const int Panel::show(){ return -1; };

void Panel::redrawMenu(
			int mode, 
			int textColor, 
			int backgroundColor){};