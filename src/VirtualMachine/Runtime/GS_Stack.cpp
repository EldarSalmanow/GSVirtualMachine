#include "../../../include/VirtualMachine/Runtime/GS_Stack.h"

namespace GSVirtualMachine::Runtime {

    void GS_Stack::push(int value) {
        _stack.push(value);
    }

    void GS_Stack::pop() {
        _stack.pop();
    }

    int GS_Stack::top() {
        return _stack.top();
    }

    bool GS_Stack::empty() {
        return _stack.empty();
    }

}