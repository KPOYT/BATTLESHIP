#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class TimerPanel : public Panel {
	public:
		TimerPanel(const string desc = "Game time:");

		TimerPanel(
			const COORD pos, 
			const string desc = "Game time:");

		TimerPanel(
			const int x, 
			const int y, 
			const string desc = "Game time:");

		~TimerPanel();

		const int show();

		void redrawPanel(const int time, 
						const int textColor = OSConsole::White, 
						const int backgroundColor = OSConsole::Black);

		bool isFinished;
	private:
		string timer_;
};