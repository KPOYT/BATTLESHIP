#include <iostream>
#include <windows.h>

#ifndef OS_H
#define OS_H
#include "..\ApplicationOS\OS.h"
#endif

using namespace std;

class Cell {
	public:
		Cell(const int x,
			 const int y,
			 const bool mode = Cell::Inactive);

		virtual void draw();
		virtual const bool getState();
		virtual void setState(const bool);
		virtual const bool getStatus();
		virtual void setMode(const bool);
		virtual const bool getMode();
		virtual void openCell(const bool);

		enum CellState
		{
			Clicked = true,
			NotClicked = false
		};

		enum CellStatus
		{
			Empty = false,
			Full = true,
			Undefined = NULL
		};

		enum CellMode
		{
			Active = true,
			Inactive = false
		};
	protected:
		virtual const int getTextColor();
		virtual const int getBackgroundColor();

		int x_;
		int y_;
		int width_;
		int height_;
		int textColor_;
		int backgroundColor_;
		int status_;
		bool mode_;

		bool isClicked_;
		bool isOpenCell_;
};