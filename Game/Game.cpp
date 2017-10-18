#include "Game.h"

Game::Game(){
	status_ = UserTurn;
	startTime_ = clock() / CLOCKS_PER_SEC;
};

Game::~Game(){
	delete timerPanel_;
	delete statePanel_;
	delete userStatePanel_;
	delete botStatePanel_;
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
	OSConsole* console = OS::GetOSFactory()->GetConsole();
	
	do {
		bool isBusy = console->status();
		if(!isBusy){
			int time = clock() / CLOCKS_PER_SEC - ptr->start;
			ptr->panel->redrawPanel(time);
			Sleep(1000);
		}
		else
			Sleep(30);

	} while(!ptr->panel->isFinished);
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
	statePanel_->redrawPanel("Your", OSConsole::Green);

	userStatePanel_ = new StatePanel(4, 5);
	userStatePanel_->show();

	botStatePanel_ = new StatePanel(70, 5);
	botStatePanel_->show();

	userField_ = new Field(14, 1);
	userField_->generate();
	userField_->isOpenShips = true;
	userField_->draw();

	botField_ = new Field(44, 1);
	botField_->generate();
	botField_->isOpenShips = false;
	botField_->draw();

	HANDLE hThr = CreateThread( NULL, 0,(LPTHREAD_START_ROUTINE) timerUpdate, (void*)&params, 0, NULL );
}

void Game::start() {
	do
	{
		int success;
		if(status_ == UserTurn)
		{
			statePanel_->redrawPanel("Your", OSConsole::Green);

			success = botField_->walk();

			if(success == botField_->Unsuccessful)
				status_ = BotTurn;
			else if(success == botField_->Gameover)
				status_ = Gameover;
			else {
				botStatePanel_->redrawPanel(botField_->leftShips());
				
				if (botField_->leftShips() == 0) {
					timerPanel_->isFinished = true;

					int time = clock() / CLOCKS_PER_SEC - startTime_;
					StateMenu menu;
					menu.show(userField_->leftShips(), botField_->leftShips(), time);
					botField_->draw();
					_getch();

					status_ = Gameover;
				}
			}
		}
		else if(status_ == BotTurn)
		{
			statePanel_->redrawPanel("Bot", OSConsole::Red);

			success = userField_->walkByBot();
			
			if(success == userField_->Unsuccessful)
				status_ = UserTurn;
			else if(success == userField_->Gameover)
				status_ = Gameover;
			else {
				userStatePanel_->redrawPanel(userField_->leftShips());

				if (userField_->leftShips() == 0) {
					timerPanel_->isFinished = true;

					int time = clock() / CLOCKS_PER_SEC - startTime_;
					StateMenu menu;
					menu.show(userField_->leftShips(), botField_->leftShips(), time);
					botField_->draw();
					_getch();
					
					status_ = Gameover;
				}
			}
		}
	}
	while (status_ != Gameover);
	timerPanel_->isFinished = true;
	status_ = UserTurn;
}
