#include <string>
#include <iostream>

using namespace std;

class OSConsole {
	public:
		static OSConsole* Instance();

		virtual int getCodeFromKeyboard();

		virtual void drawText(
			const int x,
			const int y,
			const string str,
			const int textColor = White,
			const int backgroundColor = Black,
			const bool checkStatus = true);

		virtual void setColor(
			const int textColor,
			const int backgroundColor,
			const bool checkStatus = true);

		virtual void gotoXY(
			const int x,
			const int y,
			const bool checkStatus = true);

		virtual void fillLine(
			const string mid,
			int width = 1,
			const int x = 0,
			const int y = 0,
			const bool hasNewLine = true,
			const bool checkStatus = true);

		virtual void fillLine(
			const string begin,
			const string mid,
			const string end,
			int width = 3,
			const int x = 0,
			const int y = 0,
			const bool hasNewline = true,
			const bool checkStatus = true);

		virtual void fillSquare(
			const string mid,
			int width = 1,
			int height = 1,
			const int x = 0,
			const int y = 0,
			const bool checkStatus = true);

		virtual void fillSquare(
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
		OSConsole();
		virtual ~OSConsole();

	private:
		static OSConsole* _instance;
		static bool _status;
};