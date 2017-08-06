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
		Game();
		~Game();

		void draw();
		void start();

		enum GameStatus
		{
			userTurn = 0,
			botTurn	 = 1,
			gameover = 2
		};
	private:
		TimerPanel* timerPanel_;
		StatePanel* statePanel_;
		StatePanel* userStatePanel_;
		StatePanel* botStatePanel_;
		Field* userField_;
		Field* botField_;
		int startTime_;
		int status_;
};