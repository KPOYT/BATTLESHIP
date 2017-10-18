#include <string>

using namespace std;

#ifndef OSFACTORY_H
#define OSFACTORY_H
#include "OSFactory.h"
#endif // !OSFACTORY_H

#ifndef WINOSFACTORY_H
#define WINOSFACTORY_H
#include "WinOS/WinOSFactory.h"
#endif // !WINOSFACTORY_H

class OS {
	public:
		static OSFactory* GetOSFactory(const int type = WinOS);

		enum OSTypes{
			WinOS = 0
		};
	private:
		OS();
		~OS();

		static OSFactory* _instanceOSFactory;
};