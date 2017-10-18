#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

#ifndef OSCONSOLE_H
#define OSCONSOLE_H
#include "..\OSConsole.h"
#endif // !OSCONSOLE_H

class WinOSConsole : public OSConsole {
	public:
		static WinOSConsole* Instance();

		virtual int getCodeFromKeyboard();

		void drawText(
			const int x,
			const int y,
			const string str,
			const int textColor = White,
			const int backgroundColor = Black,
			const bool checkStatus = true);

		void setColor(
			const int textColor,
			const int backgroundColor,
			const bool checkStatus = true);

		void gotoXY(
			const int x,
			const int y,
			const bool checkStatus = true);

		void fillLine(
			const string mid,
			int width = 1,
			const int x = 0,
			const int y = 0,
			const bool hasNewLine = true,
			const bool checkStatus = true);

		void fillLine(
			const string begin,
			const string mid,
			const string end,
			int width = 3,
			const int x = 0,
			const int y = 0,
			const bool hasNewline = true,
			const bool checkStatus = true);

		void fillSquare(
			const string mid,
			int width = 1,
			int height = 1,
			const int x = 0,
			const int y = 0,
			const bool checkStatus = true);

		void fillSquare(
			const string begin,
			const string mid,
			const string end,
			int width = 3,
			int height = 1,
			const int x = 0,
			const int y = 0,
			const bool checkStatus = true);

		const bool status();

		enum ConsoleColor
		{
			Black = 0,
			Blue = 1,
			Green = 2,
			Cyan = 3,
			Red = 4,
			Magenta = 5,
			Brown = 6,
			LightGray = 7,
			DarkGray = 8,
			LightBlue = 9,
			LightGreen = 10,
			LightCyan = 11,
			LightRed = 12,
			LightMagenta = 13,
			Yellow = 14,
			White = 15
		};

		enum StatusType
		{
			Free = false,
			Busy = true
		};
	protected:
		WinOSConsole();
		virtual ~WinOSConsole();

	private:
		static WinOSConsole* _instance;
		static bool _status;
};