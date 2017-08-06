#include <conio.h>
#include <process.h>
#include "Game.h"

Game::Game(){
	status_ = userTurn;
	startTime_ = clock() / CLOCKS_PER_SEC;
};

Game::~Game(){
	delete timerPanel_;
	delete userField_;
	delete botField_;
};

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
	}while(!ptr->panel->isFinished);
}

void Game::draw() {
	system("cls");

	timerPanel_ = new TimerPanel(35, 0);
	timerPanel_->show();

	MsParams static params;
	params.panel = timerPanel_;
	params.start = startTime_;
	
	statePanel_ = new StatePanel(38, 10, "Turn:");
	statePanel_->show();
	statePanel_->redrawPanel("Your", 2);

	userStatePanel_ = new StatePanel(4, 5);
	userStatePanel_->show();

	botStatePanel_ = new StatePanel(70, 5);
	botStatePanel_->show();

	userField_ = new Field(14, 1, 22, 22);
	userField_->generate();
	userField_->isOpenShips = true;
	userField_->draw();

	botField_ = new Field(44, 1, 22, 22);
	botField_->generate();
	botField_->isOpenShips = false;
	botField_->draw();

	HANDLE hThr = CreateThread( NULL, 0,(LPTHREAD_START_ROUTINE) timerUpdate, (void*)&params, 0, NULL );
}

void Game::start() {
	do
	{
		int success;
		if(status_ == userTurn)
		{
			statePanel_->redrawPanel("Your", 2);

			success = botField_->walk();

			if(success == botField_->unsuccessful)
				status_ = botTurn;
			else if(success == botField_->gameover)
				status_ = gameover;
			else {
				botStatePanel_->redrawPanel(botField_->leftShips());
				
				if (botField_->leftShips() == 0) {
					timerPanel_->isFinished = true;

					int time = clock() / CLOCKS_PER_SEC - startTime_;
					StateMenu menu;
					menu.draw(userField_->leftShips(), botField_->leftShips(), time);
					botField_->draw();
					_getch();

					status_ = gameover;
				}
			}
		}
		else if(status_ == botTurn)
		{
			statePanel_->redrawPanel("Bot", 4);

			success = userField_->walkByBot();
			
			if(success == userField_->unsuccessful)
				status_ = userTurn;
			else if(success == userField_->gameover)
				status_ = gameover;
			else {
				userStatePanel_->redrawPanel(userField_->leftShips());

				if (userField_->leftShips() == 0) {
					timerPanel_->isFinished = true;

					int time = clock() / CLOCKS_PER_SEC - startTime_;
					StateMenu menu;
					menu.draw(userField_->leftShips(), botField_->leftShips(), time);
					botField_->draw();
					_getch();
					
					status_ = gameover;
				}
			}
		}
	}
	while (status_ != gameover);
	timerPanel_->isFinished = true;
	status_ = userTurn;
}