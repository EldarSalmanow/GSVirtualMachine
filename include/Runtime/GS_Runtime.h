#ifndef GSVIRTUALMACHINE_GS_RUNTIME_H
#define GSVIRTUALMACHINE_GS_RUNTIME_H

#include <map>
#include <stack>
#include <iostream>

#include <asmjit/asmjit.h>

#include <CrossPlatform/GS_PlatformTypes.h>

#include <Exceptions/GS_Exception.h>

namespace GSVirtualMachine::Runtime {

    using namespace asmjit;
    using namespace x86;

    enum class Opcode {
        PUSH_I,
        POP,

        ADD,
        SUB,
        MUL,
        DIV,

        CALL,

        TO_REG,
        FROM_REG,

        DONE
    };

    extern std::map<GSByte, Opcode> byteToOpcode;

    /**
     *
     */
    class GS_Runtime {
    public:

        /**
         *
         * @param bytecode
         */
        static GSVoid run(GSByteCode &bytecode);

    private:

        /**
         *
         */
        inline static GSByteCode _bytecode;

        /**
         *
         */
        inline static GSByteCode::iterator _bytecodeIterator;
    };

}

#endif //GSVIRTUALMACHINE_GS_RUNTIME_H
