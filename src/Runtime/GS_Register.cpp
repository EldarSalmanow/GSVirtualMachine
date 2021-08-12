#include <GS_Register.h>

namespace GSVirtualMachine::Runtime {

    GS_Register::GS_Register()
            : _value(nullptr) {}

    GSBytePtr GS_Register::getValue() {
        return _value;
    }

    GSVoid GS_Register::setValue(GSBytePtr value) {
        _value = value;
    }

}
