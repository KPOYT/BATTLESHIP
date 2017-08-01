#include <iostream>
#include <windows.h>
#include <time.h>
#include "StateMenu.h"
#include "StatePanel.h"
#include "TimerPanel.h"
#include "Field.h"

using namespace std;

class Game {
	public:
		Game(){
			status = userWay;
			startTime_ = clock() / CLOCKS_PER_SEC;
			pauseTime_ = new int(0);
		};
		~Game(){
			delete timerPanel;
			delete userField;
			delete botField;
		};

		void draw();
		void start();

		enum GameStatus
		{
			userWay = 0,
			botWay = 1,
			gameover  = 2
		};
	private:
		TimerPanel* timerPanel;
		StatePanel* state;
		StatePanel* userState;
		StatePanel* botState;
		Field* userField;
		Field* botField;
		int startTime_;
		int* pauseTime_;
		int status;
};