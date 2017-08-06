#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class ExitPanel : public Panel {
	public:
		ExitPanel(
			string const desc = "Are you sure?"):Panel(desc) {};

		ExitPanel(
			COORD const pos, 
			string const desc = "Are you sure?"):Panel(pos, desc) {};
		
		ExitPanel(
			int const x, 
			int const y, 
			string const desc = "Are you sure?"):Panel(x, y, desc) {};
		
		~ExitPanel(){
			fillLine(" ", description.length() + 9, position.X, position.Y, false);
		};

		int const show();
	private:
		void redrawMenu(int const mode);
		int const checkKeys(int mode);
};