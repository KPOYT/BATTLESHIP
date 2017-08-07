#include "Console.h"

Console* Console::_instance = 0;
bool Console::_status = free;

Console* Console::Instance(){
	if (_instance == 0) {
		_instance = new Console();
	}
	return _instance;
}

bool const Console::status(){
	return _status;
}

void Console::drawText(
	 int const x,
	 int const y,
	 string const str,
	 int const textColor,
	 int const backgroundColor)
{
	_status = busy;

	setColor(textColor,backgroundColor);
	gotoXY(x,y);
	cout<<str;

	_status = free;
}

void Console::setColor(
	 int const textColor, 
	 int const backgroundColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, static_cast<WORD>((backgroundColor << 4) | textColor));
}

void Console::gotoXY(
	 int const x,
	 int const y)
{
	COORD coord = { x, y };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}

void Console::fillLine(
	 string const mid,
	 int width,
	 int const x,
	 int const y,
	 bool const hasNewline,
	 bool const checkStatus)
{
	if(checkStatus)
		_status = busy;

	if(width < 1) width = 1;
			
	if(x > 0 || y > 0)
		gotoXY(x, y);

	for(int i = 0; i < width; i++)
		cout<<mid;

	if(hasNewline)
		cout<<"\n";
	
	if(checkStatus)
		_status = free;
}

void Console::fillLine(
	 string const begin,
	 string const mid,
	 string const end,
	 int width,
	 int const x,
	 int const y,
	 bool const hasNewline,
	 bool const checkStatus)
{
	if(checkStatus)
		_status = busy;

	if(width < 3) width = 3;
			
	if(x > 0 || y > 0)
		gotoXY(x, y);

	cout<<begin;

	for(int i = 0; i < width - 2; i++)
		cout<<mid;

	cout<<end;

	if(hasNewline)
		cout<<"\n";
	
	if(checkStatus)
		_status = free;
}

void Console::fillSquare(
	 string const mid,
	 int width,
	 int height,
	 int const x,
	 int const y,
	 bool const checkStatus)
{
	if(checkStatus)
		_status = busy;

	if(width < 1) width = 1;
	if(height < 1) height = 1;
			
	for(int i = 0; i < height; i++)
		fillLine(mid, width, x, y + i, true, false);
	
	if(checkStatus)
		_status = free;
}

void Console::fillSquare(
	 string const begin,
	 string const mid,
	 string const end,
	 int width,
	 int height,
	 int const x,
	 int const y,
	 bool const checkStatus)
{
	if(checkStatus)
		_status = busy;

	if(width < 3) width = 3;
	if(height < 1) height = 1;
			
	for(int i = 0; i < height; i++)
		fillLine(begin, mid, end, width, x, y + i, true, false);
	
	if(checkStatus)
		_status = free;
}