#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class TimerPanel : public Panel {
	public:
		TimerPanel(
			string const desc = "Game time:"):Panel(desc)
		{
			isFinished = false;
		};

		TimerPanel(
			COORD const pos, 
			string const desc = "Game time:"):Panel(pos, desc)
		{
			isFinished = false;
		};

		TimerPanel(
			int const x, 
			int const y, 
			string const desc = "Game time:"):Panel(x, y, desc)
		{
			isFinished = false;
		};

		~TimerPanel(){
			fillLine(" ", timer_.length(), position.X, position.Y + 1, false);
		};

		int const show();

		void redrawTimer(int const time, int const textColor = 15, int const backgroundColor = 0);

		bool isFinished;
	private:
		string timer_;
};