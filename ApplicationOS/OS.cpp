#include "OS.h"

OS::OS() {};
OS::~OS() {};

OSFactory* OS::_instanceOSFactory = 0;

OSFactory* OS::GetOSFactory(const int type) {
	switch (type) {
		case WinOS:
			if (_instanceOSFactory == 0) {
				_instanceOSFactory = new WinOSFactory();
			}
		break;
	}
	return _instanceOSFactory;
}