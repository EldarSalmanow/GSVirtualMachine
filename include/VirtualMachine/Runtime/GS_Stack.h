#ifndef GSVIRTUALMACHINE_GS_STACK_H
#define GSVIRTUALMACHINE_GS_STACK_H

#include <stack>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_Stack {
    public:

        /**
         *
         * @param value
         */
        static void push(int value);

        /**
         *
         */
        static void pop();

        /**
         *
         * @return
         */
        static int top();

        /**
         *
         * @return
         */
        static bool empty();

    private:

        /**
         *
         */
        inline static std::stack<int> _stack;

    };

}

#endif //GSVIRTUALMACHINE_GS_STACK_H
