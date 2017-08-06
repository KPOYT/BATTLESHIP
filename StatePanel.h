#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class StatePanel : public Panel {
	public:
		StatePanel(
			string const desc = "Ships:"):Panel(desc) {};
		
		StatePanel(
			COORD const pos, 
			string const desc = "Ships:"):Panel(pos, desc){};
		
		StatePanel(
			int const x, 
			int const y, 
			string const desc = "Ships:"):Panel(x, y, desc) {};
		
		~StatePanel(){
			fillSquare(" ", 8, 2, position.X - 1, position.Y);
		};

		int const show();

		void redrawPanel(
			int const count, 
			int const textColor = White,
			int const backgroundColor = Black);

		void redrawPanel(
			string const count,
			int const textColor = White,
			int const backgroundColor = Black);
	private:
		string counter_;
};