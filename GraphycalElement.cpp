#include "GraphycalElement.h"

void GraphycalElement::drawText(
	 int const x,
	 int const y,
	 string const str,
	 int const textColor,
	 int const backgroundColor)
{
	setColor(textColor,backgroundColor);
	gotoXY(x,y);
	cout<<str;
}

void GraphycalElement::setColor(
	 int const textColor, 
	 int const backgroundColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, static_cast<WORD>((backgroundColor << 4) | textColor));
}

void GraphycalElement::gotoXY(
	 int const x,
	 int const y)
{
	COORD coord = { x, y };
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}

void GraphycalElement::fillLine(
	 string const mid,
	 int width,
	 int const x,
	 int const y,
	 bool const hasNewline)
{
	if(width < 1) width = 1;
			
	if(x > 0 || y > 0)
		gotoXY(x, y);

	for(int i = 0; i < width; i++)
		cout<<mid;

	if(hasNewline)
		cout<<"\n";
}

void GraphycalElement::fillLine(
	 string const begin,
	 string const mid,
	 string const end,
	 int width,
	 int const x,
	 int const y,
	 bool const hasNewline)
{
	if(width < 3) width = 3;
			
	if(x > 0 || y > 0)
		gotoXY(x, y);

	cout<<begin;

	for(int i = 0; i < width - 2; i++)
		cout<<mid;

	cout<<end;

	if(hasNewline)
		cout<<"\n";
}

void GraphycalElement::fillSquare(
	 string const mid,
	 int width,
	 int height,
	 int const x,
	 int const y)
{
	if(width < 1) width = 1;
	if(height < 1) height = 1;
			
	for(int i = 0; i < height; i++)
		fillLine(mid, width, x, y + i);
}

void GraphycalElement::fillSquare(
	 string const begin,
	 string const mid,
	 string const end,
	 int width,
	 int height,
	 int const x,
	 int const y)
{
	if(width < 3) width = 3;
	if(height < 1) height = 1;
			
	for(int i = 0; i < height; i++)
		fillLine(begin, mid, end, width, x, y + i);
}