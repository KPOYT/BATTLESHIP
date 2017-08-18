#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class ExitPanel : public Panel {
	public:
		ExitPanel(
			const string desc = "Are you sure?");

		ExitPanel(
			const COORD pos, 
			const string desc = "Are you sure?");
		
		ExitPanel(
			const int x, 
			const int y, 
			const string desc = "Are you sure?");
		
		~ExitPanel();

		const int show();
	private:
		void redrawMenu(const int mode);
		const int checkKeys(int mode);
};