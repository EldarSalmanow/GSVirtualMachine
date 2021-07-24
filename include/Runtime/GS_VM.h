#ifndef GSVIRTUALMACHINE_GS_VM_H
#define GSVIRTUALMACHINE_GS_VM_H

#include <stack>

namespace GSVirtualMachine::Runtime {

    /**
     *
     * @tparam _ValueType
     */
    template<typename _ValueType>
    class VM {
    public:

        /**
         *
         */
        std::stack<_ValueType> stack;

        /**
         *
         */
        _ValueType registers[8];
    };

}

#endif //GSVIRTUALMACHINE_GS_VM_H
