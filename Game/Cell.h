#include <iostream>
#include <windows.h>

#ifndef CONFIG_H
#define CONFIG_H
#include "..\Config.h"
#endif

#ifndef CONSOLE_H
#define CONSOLE_H
#include "..\Console.h"
#endif

using namespace std;

class Cell {
	public:
		Cell(const int x,
			 const int y,
			 const int textColor = Console::White,
			 const int backgroundColor = Console::Black,
			 const int width = Config::CELL_VIEW_WIDTH,
			 const int height = Config::CELL_VIEW_HEIGHT,
			 const int status = Cell::Empty,
			 const bool mode = Cell::Inactive);

		void draw();
		void setStatus(const int);
		const int getStatus();
		void setMode(const bool);
		const bool getMode();
		void openCell(const bool);

		enum CellStatus
		{
			Empty = 0,
			Full = 1,
			Hit = 2,
			Miss = 3
		};

		enum CellMode
		{
			Active = true,
			Inactive = false
		};
	private:
		const int getTextColor();
		const int getBackgroundColor();

		int x_;
		int y_;
		int width_;
		int height_;
		int textColor_;
		int backgroundColor_;
		int status_;
		bool mode_;

		bool isOpenCell_;
};