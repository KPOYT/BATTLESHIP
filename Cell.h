#include <iostream>
#include <windows.h>

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Cell {
	public:
		Cell(const int x,
			 const int y,
			 const int textColor = 15,
			 const int backgroundColor = 0,
			 const int width = 2,
			 const int height = 2);

		void draw();
	private:
		int x_;
		int y_;
		int width_;
		int height_;
		int textColor_;
		int backgroundColor_;
};