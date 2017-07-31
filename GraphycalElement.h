#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class GraphycalElement {
	protected:
		void drawText(int x, int y, string str, int textColor = 15, int backgroundColor = 0){
			gotoXY(x,y);
			setColor(textColor,backgroundColor);
			cout<<str;
		}

		void setColor(int textColor, int backgroundColor){
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
		}

		void gotoXY(int x, int y){
			COORD coord = { x, y };
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hStdOut, coord);
		}

		void fillLine(string mid, int width = 1, int x = 0, int y = 0, bool newline = true){
			if(width < 1) width = 1;
			
			if(x > 0 || y > 0)
				gotoXY(x, y);

			for(int i = 0; i < width; i++)
				cout<<mid;

			if(newline)
				cout<<"\n";
		}

		void fillLine(string begin, string mid, string end, int width = 3, int x = 0, int y = 0, bool newline = true){
			if(width < 3) width = 3;
			
			if(x > 0 || y > 0)
				gotoXY(x, y);

			cout<<begin;

			for(int i = 0; i < width - 2; i++)
				cout<<mid;

			cout<<end;

			if(newline)
				cout<<"\n";
		}

		void fillSquare(string mid, int width = 1, int height = 1, int x = 0, int y = 0){
			if(width < 1) width = 1;
			if(height < 1) height = 1;
			
			for(int i = 0; i < height; i++)
				fillLine(mid, width, x, y + i);
		}

		void fillSquare(string begin, string mid, string end, int width = 3, int height = 1, int x = 0, int y = 0){
			if(width < 3) width = 3;
			if(height < 1) height = 1;
			
			for(int i = 0; i < height; i++)
				fillLine(begin, mid, end, width, x, y + i);
		}
};