#include "OSConsole.h"

OSConsole::OSConsole() {};
OSConsole::~OSConsole() {};

OSConsole* OSConsole::_instance = 0;
bool OSConsole::_status = Free;

OSConsole* OSConsole::Instance() {
	if (_instance == 0) {
		_instance = new OSConsole();
	}
	return _instance;
}

const bool OSConsole::status() { return _status; }

int OSConsole::getCodeFromKeyboard() { return NULL; };

void OSConsole::drawText(
	const int x,
	const int y,
	const string str,
	const int textColor,
	const int backgroundColor,
	const bool checkStatus) {};

void OSConsole::setColor(
	const int textColor,
	const int backgroundColor,
	const bool checkStatus) {};

void OSConsole::gotoXY(
	const int x,
	const int y,
	const bool checkStatus) {};

void OSConsole::fillLine(
	const string mid,
	int width,
	const int x,
	const int y ,
	const bool hasNewLine,
	const bool checkStatus) {};

void OSConsole::fillLine(
	const string begin,
	const string mid,
	const string end,
	int width,
	const int x,
	const int y,
	const bool hasNewline,
	const bool checkStatus) {};

void OSConsole::fillSquare(
	const string mid,
	int width,
	int height,
	const int x,
	const int y,
	const bool checkStatus) {};

void OSConsole::fillSquare(
	const string begin,
	const string mid,
	const string end,
	int width,
	int height,
	const int x,
	const int y,
	const bool checkStatus) {};