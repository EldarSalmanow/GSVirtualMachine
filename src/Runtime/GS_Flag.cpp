#include <GS_Flag.h>

namespace GSVirtualMachine::Runtime {

	GS_Flag::GS_Flag() 
			: _flag(false) {}

	GSBool GS_Flag::isTrue() {
		return _flag == true;
	} 

	GSBool GS_Flag::isFalse() {
		return _flag == false;
	}

	GSVoid GS_Flag::setFlag(GSBool value) {
		_flag = value;
	}

}
