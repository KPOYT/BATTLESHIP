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

		int show()
		{  
			int mode = 10;
			bool choise = false;
	
			drawText(position.X, position.Y, description);

			redrawPanel(mode);
	
			return mode;
		}

		void redrawPanel(int count, int textColor = 15, int backgroundColor = 0){
			setColor(0,0);
			counter_.clear();

			counter_.push_back(0);
			counter_ += to_string(count);
			counter_.push_back(0);

			COORD centerPos;
			centerPos.X = position.X + (description.length() - counter_.length()) / 2;
			centerPos.Y = position.Y + 1;

			drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
			setColor(0,0);
		}

		void redrawPanel(string count, int textColor = 15, int backgroundColor = 0){
			setColor(0,0);
			counter_.clear();

			counter_.push_back(0);
			counter_ += count;
			counter_.push_back(0);

			COORD centerPos;
			centerPos.X = position.X + (description.length() - counter_.length()) / 2;
			centerPos.Y = position.Y + 1;

			drawText(centerPos.X, centerPos.Y, counter_, textColor, backgroundColor);
			setColor(0,0);
		}
	private:
		string counter_;
};