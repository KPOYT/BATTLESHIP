#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class GraphycalElement {
	protected:
		void drawText(
			int const x, 
			int const y, 
			string const str, 
			int const textColor = White,
			int const backgroundColor = Black);

		void setColor(
			int const textColor, 
			int const backgroundColor);

		void gotoXY(
			int const x,
			int const y);

		void fillLine(
			string const mid,
			int width = 1,
			int const x = 0,
			int const y = 0,
			bool const hasNewLine = true);

		void fillLine(
			string const begin,
			string const mid,
			string const end,
			int width = 3,
			int const x = 0,
			int const y = 0,
			bool const hasNewline = true);

		void fillSquare(
			string const mid,
			int width = 1,
			int height = 1,
			int const x = 0,
			int const y = 0);

		void fillSquare(
			string const begin,
			string const mid,
			string const end,
			int width = 3,
			int height = 1,
			int const x = 0,
			int const y = 0);

		enum ConsoleColor
		{
			Black         = 0,
			Blue          = 1,
			Green         = 2,
			Cyan          = 3,
			Red           = 4,
			Magenta       = 5,
			Brown         = 6,
			LightGray     = 7,
			DarkGray      = 8,
			LightBlue     = 9,
			LightGreen    = 10,
			LightCyan     = 11,
			LightRed      = 12,
			LightMagenta  = 13,
			Yellow        = 14,
			White         = 15
		};
};