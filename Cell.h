#include <iostream>
#include <windows.h>

#ifndef CONFIG_H
#define CONFIG_H
#include "Config.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Console.h"
#endif

using namespace std;

class Cell {
	public:
		Cell(const int x,
			 const int y,
			 const int textColor = Console::White,
			 const int backgroundColor = Console::Black,
			 const int width = Config::CELL_WIDTH,
			 const int height = Config::CELL_HEIGHT);

		void draw();
	private:
		int x_;
		int y_;
		int width_;
		int height_;
		int textColor_;
		int backgroundColor_;
};