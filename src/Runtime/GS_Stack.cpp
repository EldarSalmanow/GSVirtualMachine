#include <GS_Stack.h>

namespace GSVirtualMachine::Runtime {

    GS_Stack::GS_Stack()
            : _currentSize(-1), _top(_stack[0]) {}

    GSVoid GS_Stack::push(GSBytePtr value) {
        _incrCurrentSize();

        _stack[_currentSize] = value;

        _top = _stack[_currentSize];
    }

    GSBytePtr GS_Stack::pop() {
        auto value = _stack[_currentSize];

        _decrCurrentSize();

        _top = _stack[_currentSize];

        return value;
    }

    GSBytePtr GS_Stack::top() {
        if (!_top) {
            throw std::runtime_error("Null pointer in top of stack!");
        }

        return _top;
    }

    GSVoid GS_Stack::_incrCurrentSize() {
        ++_currentSize;

        if (_currentSize >= MAX_STACK_SIZE) {
            throw Exceptions::GS_Exception("Stack overflow!");
        }
    }

    GSVoid GS_Stack::_decrCurrentSize() {
        --_currentSize;

        if (_currentSize < -1) {
            throw Exceptions::GS_Exception("Stack is empty!");
        }
    }

}
