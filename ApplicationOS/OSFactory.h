#ifndef OSCONSOLE_H
#define OSCONSOLE_H
#include "OSConsole.h"
#endif // !OSCONSOLE_H

#ifndef OSCONFIG_H
#define OSCONFIG_H
#include "OSConfig.h"
#endif // !OSCONFIG_H


class OSFactory {
	public:
		virtual OSConsole* GetConsole() = 0;
		virtual OSConfig* GetConfig() = 0;
};