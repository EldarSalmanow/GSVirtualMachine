#ifndef GSVIRTUALMACHINE_GS_OPCODE_H
#define GSVIRTUALMACHINE_GS_OPCODE_H

#include <map>

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    enum class Opcode {
        CONSTANT_STRING,

        VARIABLE_NUMBER,

        PUSH,
        POP,

        PUSH_CONSTANT_ADR,

        TO_REG,
        FROM_REG,

        SAVE,
        GET,

        LABEL,

        JMP,
        JIE,
        JINE,
        JIG,
        JIL,
        JIEG,
        JIEL,

        CALL,

        CMP,

        ADD,
        SUB,
        MUL,
        DIV,

        DONE
    };

    extern std::map<GSByte, Opcode> byteToOpcode;

    extern std::map<Opcode, GSString> opcodeToString;

}

#endif //GSVIRTUALMACHINE_GS_OPCODE_H
