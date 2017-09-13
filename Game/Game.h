#include <iostream>
#include <windows.h>
#include <time.h>

#ifndef STATEMENU_H
#define STATEMENU_H
#include "..\Menus\StateMenu.h"
#endif

#ifndef STATEPANEL_H
#define STATEPANEL_H
#include "..\Panels\StatePanel.h"
#endif
#ifndef TIMERPANEL_H
#define TIMERPANEL_H
#include "..\Panels\TimerPanel.h"
#endif
#ifndef FIELD_H
#define FIELD_H
#include "Field.h"
#endif

using namespace std;

class Game {
	public:
		Game();
		~Game();

		void draw();
		void start();

		enum GameState
		{
			UserTurn = 0,
			BotTurn	 = 1,
			Gameover = 2
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