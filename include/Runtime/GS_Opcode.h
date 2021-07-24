#ifndef GSVIRTUALMACHINE_GS_OPCODE_H
#define GSVIRTUALMACHINE_GS_OPCODE_H

#include <map>

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    enum class Opcode {
        PUSH,
        POP,

        ADD,
        SUB,
        MUL,
        DIV,

        CALL,

        TO_REG,
        FROM_REG,

        CONSTANT,
        VARIABLE,
        FUNCTION,

        DONE
    };

    extern std::map<GSByte, Opcode> byteToOpcode;

    extern std::map<Opcode, GSString> opcodeToString;

}

#endif //GSVIRTUALMACHINE_GS_OPCODE_H
