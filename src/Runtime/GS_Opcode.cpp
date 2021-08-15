#include <GS_Opcode.h>

namespace GSVirtualMachine::Runtime {

    std::map<GSByte, Opcode> byteToOpcode = {
            {0x0,  Opcode::CONSTANT_STRING},

            {0x1,  Opcode::VARIABLE_NUMBER},

            {0x2,  Opcode::PUSH},
            {0x3,  Opcode::POP},

            {0x4,  Opcode::PUSH_CONSTANT_ADR},

            {0x5,  Opcode::TO_REG},
            {0x6,  Opcode::FROM_REG},

            {0x7,  Opcode::SAVE},
            {0x8,  Opcode::GET},

            {0x9,  Opcode::LABEL},

            {0xa,  Opcode::JMP},
            {0xb,  Opcode::JIE},
            {0xc,  Opcode::JINE},
            {0xd,  Opcode::JIG},
            {0xe,  Opcode::JIL},
            {0xf,  Opcode::JIEG},
            {0xf1, Opcode::JIEL},

            {0xf2, Opcode::CALL},

            {0xf3, Opcode::CMP},

            {0xf4, Opcode::ADD},
            {0xf5, Opcode::SUB},
            {0xf6, Opcode::MUL},
            {0xf7, Opcode::DIV},

            {0xff, Opcode::DONE}
    };

    std::map<Opcode, GSString> opcodeToString = {
            {Opcode::CONSTANT_STRING,   "CONSTANT_STRING"},

            {Opcode::VARIABLE_NUMBER,   "VARIABLE_NUMBER"},

            {Opcode::PUSH,              "PUSH"},
            {Opcode::POP,               "POP"},

            {Opcode::PUSH_CONSTANT_ADR, "PUSH_CONSTANT_ADR"},

            {Opcode::TO_REG,            "TO_REG"},
            {Opcode::FROM_REG,          "FROM_REG"},

            {Opcode::SAVE,              "SAVE"},
            {Opcode::GET,               "GET"},

            {Opcode::LABEL,             "LABEL"},

            {Opcode::JMP,               "JMP"},
            {Opcode::JIE,               "JIE"},
            {Opcode::JINE,              "JINE"},
            {Opcode::JIG,               "JIG"},
            {Opcode::JIL,               "JIL"},
            {Opcode::JIEG,              "JIEG"},
            {Opcode::JIEL,              "JIEL"},

            {Opcode::CALL,              "CALL"},

            {Opcode::CMP,               "CMP"},

            {Opcode::ADD,               "ADD"},
            {Opcode::SUB,               "SUB"},
            {Opcode::MUL,               "MUL"},
            {Opcode::DIV,               "DIV"},

            {Opcode::DONE,              "DONE"}
    };

}