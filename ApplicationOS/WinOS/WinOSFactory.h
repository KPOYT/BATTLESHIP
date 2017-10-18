#ifndef OSFACTORY_H
#define OSFACTORY_H
#include "../OSFactory.h"
#endif // !OSFACTORY_H

#ifndef WINOSCONSOLE_H
#define WINOSCONSOLE_H
#include "WinOSConsole.h"
#endif // !WINOSCONSOLE_H

#ifndef WINOSCONFIG_H
#define WINOSCONFIG_H
#include "WinOSConfig.h"
#endif // !WINOSCONFIG_H


class WinOSFactory : public OSFactory{
	public:
		virtual WinOSConsole* GetConsole();
		virtual WinOSConfig* GetConfig();
};