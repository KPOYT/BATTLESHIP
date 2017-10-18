#include "WinOSFactory.h"

WinOSConsole* WinOSFactory::GetConsole() {
	return WinOSConsole::Instance();
}

WinOSConfig* WinOSFactory::GetConfig() {
	return WinOSConfig::Instance();
}