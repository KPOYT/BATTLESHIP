#include <conio.h>
#include <process.h>
#include "Game.h"

typedef struct
{
    TimerPanel* panel;
    int start;
} MsParams;

void timerUpdate(void* pParams){
	MsParams * ptr = (MsParams *)pParams;
	
	do {
		int time = clock() / CLOCKS_PER_SEC - ptr->start;
		ptr->panel->redrawTimer(time);
		Sleep(1000);
	}while(!ptr->panel->finished);
}

void Game::draw() {
	system("cls");

	timerPanel = new TimerPanel(35, 0);
	timerPanel->show();

	MsParams static params;
	params.panel = timerPanel;
	params.start = startTime_;
	
	state = new StatePanel(38, 10, "Turn:");
	state->show();
	state->redrawPanel("Your", 2);

	userState = new StatePanel(4, 5);
	userState->show();

	botState = new StatePanel(70, 5);
	botState->show();

	userField = new Field(14, 1, 22, 22);
	userField->generate();
	userField->type = userField->open;
	userField->draw();

	botField = new Field(44, 1, 22, 22);
	botField->generate();
	botField->type = botField->close;
	botField->draw();

	HANDLE hThr = CreateThread( NULL, 0,(LPTHREAD_START_ROUTINE) timerUpdate, (void*)&params, 0, NULL );
}

void Game::start() {
	do
	{
		int success;
		if(status == userWay)
		{
			state->redrawPanel("Your", 2);

			success = botField->walk();

			if(success == botField->unsuccess)
				status = botWay;
			else if(success == botField->gameover)
				status = gameover;
			else {
				botState->redrawPanel(botField->leftShips());
				
				if (botField->leftShips() == 0) {
					timerPanel->finished = true;

					int time = clock() / CLOCKS_PER_SEC - startTime_;
					StateMenu menu;
					menu.draw(userField->leftShips(), botField->leftShips(), time);
					botField->draw();
					_getch();

					status = gameover;
				}
			}
		}
		else if(status == botWay)
		{
			state->redrawPanel("Bot", 4);

			success = userField->walkByBot();
			
			if(success == userField->unsuccess)
				status = userWay;
			else if(success == userField->gameover)
				status = gameover;
			else {
				userState->redrawPanel(userField->leftShips());

				if (userField->leftShips() == 0) {
					timerPanel->finished = true;

					int time = clock() / CLOCKS_PER_SEC - startTime_;
					StateMenu menu;
					menu.draw(userField->leftShips(), botField->leftShips(), time);
					botField->draw();
					_getch();
					
					status = gameover;
				}
			}
		}
	}
	while (status != gameover);
	timerPanel->finished = true;
	status = userWay;
}