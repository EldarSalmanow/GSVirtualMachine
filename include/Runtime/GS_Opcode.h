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

        PUSH_CONSTANT,

        TO_REG,
        FROM_REG,

        ADD,
        SUB,
        MUL,
        DIV,

        CALL,

        CONSTANT_STRING,

        VARIABLE_NUMBER,

        SAVE,
        GET,

        DONE
    };

    extern std::map<GSByte, Opcode> byteToOpcode;

    extern std::map<Opcode, GSString> opcodeToString;

}

#endif //GSVIRTUALMACHINE_GS_OPCODE_H
