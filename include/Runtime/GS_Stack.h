#ifndef GSVIRTUALMACHINE_GS_STACK_H
#define GSVIRTUALMACHINE_GS_STACK_H

#include <Exceptions/GS_Exception.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    const GSInt MAX_STACK_SIZE = 2048;

    /**
     *
     */
    class GS_Stack {
    public:

        /**
         *
         */
        GS_Stack();

    public:

        /**
         *
         * @param value
         * @return
         */
        GSVoid push(GSBytePtr value);

        /**
         *
         * @return
         */
        GSBytePtr pop();

        /**
         *
         * @return
         */
        GSBytePtr top();

    private:

        /**
         *
         * @return
         */
        GSVoid _incrCurrentSize();

        /**
         *
         * @return
         */
        GSVoid _decrCurrentSize();

    private:

        /**
         *
         */
        GSInt _currentSize;

        /**
         *
         */
        GSBytePtr _top;

        /**
         *
         */
        GSBytePtr _stack[MAX_STACK_SIZE];
    };

}

#endif //GSVIRTUALMACHINE_GS_STACK_H
