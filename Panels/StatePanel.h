#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class StatePanel : public Panel {
	public:
		StatePanel(
			const string desc = "Ships:");
		
		StatePanel(
			const COORD pos, 
			const string desc = "Ships:");
		
		StatePanel(
			const int x, 
			const int y, 
			const string desc = "Ships:");
		
		~StatePanel();

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