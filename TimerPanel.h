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

		void redrawTimer(const int time, 
						const int textColor = 15, 
						const int backgroundColor = 0);

		bool isFinished;
	private:
		string timer_;
};