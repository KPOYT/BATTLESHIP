#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class StatePanel : public Panel {
	public:
		StatePanel(
			const string desc = "Ships:"):Panel(desc) {};
		
		StatePanel(
			const COORD pos, 
			const string desc = "Ships:"):Panel(pos, desc){};
		
		StatePanel(
			const int x, 
			const int y, 
			const string desc = "Ships:"):Panel(x, y, desc) {};
		
		~StatePanel(){
			console->fillSquare(" ", 8, 2, position.X - 1, position.Y);
		};

		const int show();

		void redrawPanel(
			const int count, 
			const int textColor = Console::White,
			const int backgroundColor = Console::Black);

		void redrawPanel(
			const string count,
			const int textColor = Console::White,
			const int backgroundColor = Console::Black);
	private:
		string counter_;
};