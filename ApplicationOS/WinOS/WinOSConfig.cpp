#include "WinOSConfig.h"

WinOSConfig::WinOSConfig() {};
WinOSConfig::~WinOSConfig() {};

WinOSConfig* WinOSConfig::_instance = 0;

WinOSConfig* WinOSConfig::Instance() {
	if (_instance == 0) {
		_instance = new WinOSConfig();
	}
	return _instance;
}

const int* WinOSConfig::SHIPS_TYPE() {
	static const int ships_type[MAX_SHIPS] = { 4,3,3,2,2,2,1,1,1,1 };
	return ships_type;
};