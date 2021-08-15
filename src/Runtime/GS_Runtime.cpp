#include <GS_Runtime.h>

namespace GSVirtualMachine::Runtime {

    namespace Native {

        GSVoid print(GSBytePtr string) {
            std::cout << string;
        }

        GSVoid println(GSBytePtr string) {
            std::cout << string << std::endl;
        }

        GSVoid input(GSString &string) {
            GSChar symbol = '\0';

            while (true) {
                std::cin.get(symbol);

                if (symbol == '\n') {
                    break;
                }

                string += symbol;
            }
        }

    }

    std::map<Opcode, GSByte> opcodeToByte = {
            {Opcode::CONSTANT_STRING,     0x0},

            {Opcode::VARIABLE_NUMBER,     0x1},

            {Opcode::PUSH,                0x2},
            {Opcode::POP,                 0x3},

            {Opcode::PUSH_CONSTANT_ADR,   0x4},

            {Opcode::TO_REG,              0x5},
            {Opcode::FROM_REG,            0x6},

            {Opcode::SAVE,                0x7},
            {Opcode::GET,                 0x8},

            {Opcode::LABEL,               0x9},

            {Opcode::JMP,                 0xa},
            {Opcode::JIE,                 0xb},
            {Opcode::JINE,                0xc},
            {Opcode::JIG,                 0xd},
            {Opcode::JIL,                 0xe},
            {Opcode::JIEG,                0xf},
            {Opcode::JIEL,                0xf1},

            {Opcode::CALL,                0xf2},

            {Opcode::CMP,                 0xf3},

            {Opcode::ADD,                 0xf4},
            {Opcode::SUB,                 0xf5},
            {Opcode::MUL,                 0xf6},
            {Opcode::DIV,                 0xf7},

            {Opcode::DONE,                0xff}
    };

    GSVoid GS_Runtime::run(GSByteCode &bytecode) {
        // if (1 < 2) {
        //     println("Hello!")
        // } else {
        //     println("World!")
        // }

        // == != > < >= <=
        // jie jine jig jil jieg jiel  jmp

        // constant_string _CS0 "Hello!"
        // constant_string _CS1 "World"
        //
        // push 1
        // push 2
        // cmp
        // jieg "CELSE0"
        //
        // push_addr "_CS0"
        // to_reg 0
        // call 1
        // jmp "CEND0"
        //
        // label "CELSE0"
        // push_addr _CS1
        // to_reg 0
        // call 1
        //
        // label CEND0"
        // done

        // for i: Int = 0; i < 3; ++i {
        //     println("Hello!")
        // }

        // constant_string 0 "Hello!"
        //
        // push 0
        // to_reg 7
        // label "LC0"
        // from_reg 7
        // push 3
        // cmp
        // jieg "LE0"
        // push_constant_adr 0
        // to_reg 0
        // call 1
        // from_reg 7
        // push 1
        // add
        // to_reg 7
        // jmp "LC0"
        // label "LE0"
        // done

        GSByteCode bytecod = {
                opcodeToByte[Opcode::CONSTANT_STRING], 0, 'H', 'e', 'l', 'l', 'o', '!', 0,

                opcodeToByte[Opcode::PUSH], 0,
                opcodeToByte[Opcode::TO_REG], 7,

                opcodeToByte[Opcode::LABEL], 'L', 'C', '0', 0,

                opcodeToByte[Opcode::FROM_REG], 7,
                opcodeToByte[Opcode::PUSH], 3,
                opcodeToByte[Opcode::CMP],
                opcodeToByte[Opcode::JIEG], 'L', 'E', '0', 0,

                opcodeToByte[Opcode::PUSH_CONSTANT_ADR], 0,
                opcodeToByte[Opcode::TO_REG], 0,
                opcodeToByte[Opcode::CALL], 1,

                opcodeToByte[Opcode::FROM_REG], 7,
                opcodeToByte[Opcode::PUSH], 1,
                opcodeToByte[Opcode::ADD],
                opcodeToByte[Opcode::TO_REG], 7,
                opcodeToByte[Opcode::JMP], 'L', 'C', '0', 0,

                opcodeToByte[Opcode::LABEL],  'L', 'E', '0', 0,

                opcodeToByte[Opcode::DONE]
        };

        GS_Decoder decoder(bytecod);

        GS_Stack stack;

        GS_Register registers[REGISTER_NUM];

        GS_Flag flags[FLAGS_NUM];

        GS_ConstantsTable constantsTable;

        GS_VariablesTable variablesTable;

        GS_LabelsTable labelsTable;

        while (decoder.opcode() != Opcode::DONE) {
            auto opcode = decoder.opcode();

            if (opcode == Opcode::LABEL) {
                _runLabelInstruction(decoder, labelsTable);

                continue;
            }

            decoder.nextByte();
        }

        decoder.setCursorToStart();

        while (decoder.opcode() != Opcode::DONE) {
            auto opcode = decoder.opcode();

            switch (opcode) {
                case Opcode::VARIABLE_NUMBER:
                    _runVariableNumberInstruction(decoder, variablesTable);

                    continue;
                case Opcode::CONSTANT_STRING:
                    _runConstantStringInstruction(decoder, constantsTable);

                    continue;
                case Opcode::PUSH:
                    _runPushInstruction(decoder, stack);

                    break;
                case Opcode::POP:
                    _runPopInstruction(stack);

                    break;
                case Opcode::PUSH_CONSTANT_ADR:
                    _runPushConstantAdrInstruction(decoder, stack, constantsTable);

                    break;
                case Opcode::TO_REG:
                    _runToRegInstruction(decoder, stack, registers);

                    break;
                case Opcode::FROM_REG:
                    _runFromRegInstruction(decoder, stack, registers);

                    break;
                case Opcode::SAVE:
                    _runSaveInstruction(decoder, stack, variablesTable);

                    break;
                case Opcode::GET:
                    _runGetInstruction(decoder, stack, variablesTable);

                    break;
                case Opcode::LABEL:
                    _runLabelInstruction(decoder, labelsTable);

                    continue;
                case Opcode::JMP:
                    _runJmpInstruction(decoder, labelsTable);

                    continue;
                case Opcode::JIE:
                    _runJieInstruction(decoder, labelsTable, flags);

                    continue;
                case Opcode::JINE:
                    _runJineInstruction(decoder, labelsTable, flags);

                    continue;
                case Opcode::JIG:
                    _runJigInstruction(decoder, labelsTable, flags);

                    continue;
                case Opcode::JIL:
                    _runJilInstruction(decoder, labelsTable, flags);

                    continue;
                case Opcode::JIEG:
                    _runJiegInstruction(decoder, labelsTable, flags);

                    continue;
                case Opcode::JIEL:
                    _runJielInstruction(decoder, labelsTable, flags);

                    continue;
                case Opcode::CMP:
                    _runCmpInstruction(decoder, stack, flags);

                    break;
                case Opcode::CALL:
                    _runCallInstruction(decoder, registers);

                    break;
                case Opcode::ADD:
                    _runAddInstruction(stack);

                    break;
                case Opcode::SUB:
                    _runSubInstruction(stack);

                    break;
                case Opcode::MUL:
                    _runMulInstruction(stack);

                    break;
                case Opcode::DIV:
                    _runDivInstruction(stack);

                    break;
                case Opcode::DONE:
                    return;
            }

            decoder.nextByte();
        }
    }

    GSVoid GS_Runtime::_runVariableNumberInstruction(GS_Decoder &decoder, GS_VariablesTable &variablesTable) {
        decoder.nextByte();

        auto variableId = *decoder.currentByte();

        decoder.nextByte();

        auto variableName = decoder.string();

        variablesTable.addVariable(variableId, variableName);
    }

    GSVoid GS_Runtime::_runConstantStringInstruction(GS_Decoder &decoder, GS_ConstantsTable &constantsTable) {
        decoder.nextByte();

        auto constantId = *decoder.currentByte();

        decoder.nextByte();

        auto string = decoder.string();

        constantsTable.addConstant(string, constantId);
    }

    GSVoid GS_Runtime::_runPushInstruction(GS_Decoder &decoder, GS_Stack &stack) {
        decoder.nextByte();

        auto value = decoder.currentByte();

        stack.push(value);
    }

    GSVoid GS_Runtime::_runPopInstruction(GS_Stack &stack) {
        stack.pop();
    }

    GSVoid GS_Runtime::_runPushConstantAdrInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_ConstantsTable &constantsTable) {
        decoder.nextByte();

        auto constantId = *decoder.currentByte();

        auto constant = constantsTable.getConstantById(constantId);

        auto value = (GSByte *) constant.c_str();

        stack.push(value);
    }

    GSVoid GS_Runtime::_runToRegInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_Register *registers) {
        decoder.nextByte();

        auto registerNum = *decoder.currentByte();

        if (registerNum >= REGISTER_NUM || registerNum < 0) {
            throw Exceptions::GS_Exception("Invalid register number!");
        }

        auto value = stack.pop();

        registers[registerNum].setValue(value);
    }

    GSVoid GS_Runtime::_runFromRegInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_Register *registers) {
        decoder.nextByte();

        auto registerNum = *decoder.currentByte();

        if (registerNum >= REGISTER_NUM || registerNum < 0) {
            throw Exceptions::GS_Exception("Invalid register number!");
        }

        stack.push(registers[registerNum].getValue());
    }

    GSVoid GS_Runtime::_runSaveInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_VariablesTable &variablesTable) {
        decoder.nextByte();

        auto variableId = *decoder.currentByte();

        auto value = stack.pop();

        variablesTable.setValueById(variableId, *value);
    }

    GSVoid GS_Runtime::_runGetInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_VariablesTable &variablesTable) {
        decoder.nextByte();

        auto variableId = *decoder.currentByte();

        auto value = variablesTable.getValueById(variableId);

        stack.push(reinterpret_cast<GSByte *>(&value));
    }

    GSVoid GS_Runtime::_runLabelInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable) {
        decoder.nextByte();

        auto name = decoder.string();

        labelsTable.addLabel(name, decoder.currentByte());
    }

    GSVoid GS_Runtime::_runJmpInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable) {
        decoder.nextByte();

        auto name = decoder.string();

        decoder.jmpTo(labelsTable.getLabelByName(name));
    }

    GSVoid GS_Runtime::_runJieInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags) {
        decoder.nextByte();

        auto name = decoder.string();

        if (flags[0].isTrue()) {
            decoder.jmpTo(labelsTable.getLabelByName(name));
        }
    }

    GSVoid GS_Runtime::_runJineInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags) {
        decoder.nextByte();

        auto name = decoder.string();

        if (flags[0].isFalse()) {
            decoder.jmpTo(labelsTable.getLabelByName(name));
        }
    }

    GSVoid GS_Runtime::_runJigInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags) {
        decoder.nextByte();

        auto name = decoder.string();

        if (flags[1].isTrue()) {
            decoder.jmpTo(labelsTable.getLabelByName(name));
        }
    }

    GSVoid GS_Runtime::_runJilInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags) {
        decoder.nextByte();

        auto name = decoder.string();

        if (flags[2].isTrue()) {
            decoder.jmpTo(labelsTable.getLabelByName(name));
        }
    }

    GSVoid GS_Runtime::_runJiegInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags) {
        decoder.nextByte();

        auto name = decoder.string();

        if (flags[0].isTrue() || flags[1].isTrue()) {
            decoder.jmpTo(labelsTable.getLabelByName(name));
        }
    }

    GSVoid GS_Runtime::_runJielInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags) {
        decoder.nextByte();

        auto name = decoder.string();

        if (flags[0].isTrue() || flags[2].isTrue()) {
            decoder.jmpTo(labelsTable.getLabelByName(name));
        }
    }

    GSVoid GS_Runtime::_runCmpInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_Flag *flags) {
        auto secondValue = *stack.pop();

        auto firstValue = *stack.pop();

        if (firstValue == secondValue) {
            flags[0].setFlag(true);
        } else {
            flags[0].setFlag(false);
        }

        if (firstValue > secondValue) {
            flags[1].setFlag(true);
        } else {
            flags[1].setFlag(false);
        }

        if (firstValue < secondValue) {
            flags[2].setFlag(true);
        } else {
            flags[2].setFlag(false);
        }
    }

    GSVoid GS_Runtime::_runCallInstruction(GS_Decoder &decoder, GS_Register *registers) {
        decoder.nextByte();

        auto functionNumber = *decoder.currentByte();

        auto argument = registers[0].getValue();

        if (functionNumber == 0) {
            Native::print(argument);
        } else if (functionNumber == 1) {
            Native::println(argument);
        }
    }

    GSVoid GS_Runtime::_runAddInstruction(GS_Stack &stack) {
        auto secondValue = stack.pop();

        auto firstValue = stack.pop();

        auto result = *firstValue + *secondValue;

        stack.push(reinterpret_cast<GSByte *>(&result));
    }

    GSVoid GS_Runtime::_runSubInstruction(GS_Stack &stack) {
        auto secondValue = stack.pop();

        auto firstValue = stack.pop();

        auto result = *firstValue - *secondValue;

        stack.push(reinterpret_cast<GSByte *>(&result));
    }

    GSVoid GS_Runtime::_runMulInstruction(GS_Stack &stack) {
        auto secondValue = stack.pop();

        auto firstValue = stack.pop();

        auto result = *firstValue * *secondValue;

        stack.push(reinterpret_cast<GSByte *>(&result));
    }

    GSVoid GS_Runtime::_runDivInstruction(GS_Stack &stack) {
        auto secondValue = stack.pop();

        if (*secondValue == 0) {
            throw Exceptions::GS_Exception("Division by zero!");
        }

        auto firstValue = stack.pop();

        auto result = *firstValue / *secondValue;

        stack.push(reinterpret_cast<GSByte *>(&result));
    }

}