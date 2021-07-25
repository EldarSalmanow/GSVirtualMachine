#include <GS_Opcode.h>

namespace GSVirtualMachine::Runtime {

    std::map<GSByte, Opcode> byteToOpcode = {
            {0x0,  Opcode::PUSH},
            {0x1,  Opcode::POP},

            {0x2,  Opcode::ADD},
            {0x3,  Opcode::SUB},
            {0x4,  Opcode::MUL},
            {0x5,  Opcode::DIV},

            {0x6,  Opcode::CALL},

            {0x7,  Opcode::TO_REG},
            {0x8,  Opcode::FROM_REG},

            {0x9,  Opcode::CONSTANT_NUMBER},
            {0xa,  Opcode::CONSTANT_STRING},

            {0xb,  Opcode::VARIABLE_NUMBER},
            {0xc,  Opcode::VARIABLE_STRING},

            {0xd,  Opcode::FUNCTION},

            {0xff, Opcode::DONE}
    };

    std::map<Opcode, GSString> opcodeToString = {
            {Opcode::PUSH,            "PUSH"},
            {Opcode::POP,             "POP"},

            {Opcode::ADD,             "ADD"},
            {Opcode::SUB,             "SUB"},
            {Opcode::MUL,             "MUL"},
            {Opcode::DIV,             "DIV"},

            {Opcode::CALL,            "CALL"},

            {Opcode::TO_REG,          "TO_REG"},
            {Opcode::FROM_REG,        "FROM_REG"},

            {Opcode::CONSTANT_NUMBER, "CONSTANT_NUMBER"},
            {Opcode::CONSTANT_STRING, "CONSTANT_STRING"},

            {Opcode::VARIABLE_NUMBER, "VARIABLE_NUMBER"},
            {Opcode::VARIABLE_STRING, "VARIABLE_STRING"},

            {Opcode::FUNCTION,        "FUNCTION"},

            {Opcode::DONE,            "DONE"}
    };

}