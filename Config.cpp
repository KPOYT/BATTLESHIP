#include "Config.h"

const int* Config::SHIPS_TYPE() {
	static const int ships_type[MAX_SHIPS] = { 4,3,3,2,2,2,1,1,1,1 };
	return ships_type;
};