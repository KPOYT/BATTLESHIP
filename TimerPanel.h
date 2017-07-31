#ifndef PANEL_H
#define PANEL_H
#include "Panel.h"
#endif

class TimerPanel : public Panel {
	public:
		TimerPanel(
			string const desc = "Game time:"):Panel(desc)
		{
			finished = false;
		};

		TimerPanel(
			COORD const pos, 
			string const desc = "Game time:"):Panel(pos, desc)
		{
			finished = false;
		};

		TimerPanel(
			int const x, 
			int const y, 
			string const desc = "Game time:"):Panel(x, y, desc)
		{
			finished = false;
		};

		~TimerPanel(){
			fillLine(" ", timer_.length(), position.X, position.Y + 1, false);
		};

		int show()
		{  
			int mode = 0;
			bool choise = false;
	
			drawText(position.X, position.Y, description);

			redrawTimer(mode);
	
			return mode;
		}

		void redrawTimer(int time, int textColor = 15, int backgroundColor = 0) {
			setColor(0,0);
			timer_.clear();

			timer_.push_back(0);
			timer_ += to_string(time);
			timer_.push_back(0);

			COORD centerPos;
			centerPos.X = position.X + (description.length() - timer_.length()) / 2;
			centerPos.Y = position.Y + 1;
			
			drawText(centerPos.X, centerPos.Y, timer_, textColor, backgroundColor);
			setColor(0,0);
		}

		bool finished;
	private:
		string timer_;
};