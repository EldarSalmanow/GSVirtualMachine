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

    GSVoid GS_Runtime::run(GSByteCode &bytecode) {
        GS_Decoder decoder(bytecode);

        GS_Stack stack;

        const GSInt REGISTER_NUM = 8;
        GS_Register registers[REGISTER_NUM];

        GS_ConstantsTable constantsTable;

        GS_VariablesTable variablesTable;

        while (decoder.opcode() != Opcode::DONE) {
            auto opcode = decoder.opcode();

            switch (opcode) {
                case Opcode::VARIABLE_NUMBER: {
                    decoder.nextByte();

                    auto variableId = decoder.currentByte();

                    decoder.nextByte();

                    GSString variableName;

                    while (decoder.currentByte() != 0) {
                        variableName += static_cast<GSChar>(decoder.currentByte());

                        decoder.nextByte();
                    }

                    variablesTable.addVariable(variableId, variableName);

                    break;
                }
                case Opcode::CONSTANT_STRING: {
                    decoder.nextByte();

                    auto constantId = decoder.currentByte();

                    decoder.nextByte();

                    GSString string;

                    while (true) {
                        auto symbol = decoder.currentByte();

                        string += static_cast<GSChar>(symbol);

                        if (symbol == 0) {
                            break;
                        }

                        decoder.nextByte();
                    }

                    constantsTable.addConstant(string, constantId);

                    break;
                }
                case Opcode::PUSH: {
                    decoder.nextByte();

                    auto value = decoder.currentByte();

                    stack.push(&value);

                    break;
                }
                case Opcode::POP: {
                    stack.pop();

                    break;
                }
                case Opcode::PUSH_CONSTANT: {
                    decoder.nextByte();

                    auto constantId = decoder.currentByte();

                    auto value = constantsTable.getConstantById(constantId).c_str();

                    stack.push((GSByte *) value);

                    break;
                }
                case Opcode::TO_REG: {
                    decoder.nextByte();

                    auto registerNum = decoder.currentByte();

                    if (registerNum >= REGISTER_NUM || registerNum < 0) {
                        throw std::runtime_error("Invalid register number!");
                    }

                    registers[registerNum].setValue(stack.pop());

                    break;
                }
                case Opcode::FROM_REG: {
                    decoder.nextByte();

                    auto registerNum = decoder.currentByte();

                    if (registerNum >= REGISTER_NUM || registerNum < 0) {
                        throw std::runtime_error("Invalid register number!");
                    }

                    stack.push(registers[registerNum].getValue());

                    break;
                }
                case Opcode::ADD: {
                    auto secondValue = stack.pop();

                    auto firstValue = stack.pop();

                    auto result = *firstValue + *secondValue;

                    stack.push(reinterpret_cast<GSByte*>(&result));

                    break;
                }
                case Opcode::SUB: {
                    auto secondValue = stack.pop();

                    auto firstValue = stack.pop();

                    auto result = *firstValue - *secondValue;

                    stack.push(reinterpret_cast<GSByte*>(&result));

                    break;
                }
                case Opcode::MUL: {
                    auto secondValue = stack.pop();

                    auto firstValue = stack.pop();

                    auto result = *firstValue * *secondValue;

                    stack.push(reinterpret_cast<GSByte*>(&result));

                    break;
                }
                case Opcode::DIV: {
                    auto secondValue = stack.pop();

                    if (*secondValue == 0) {
                        throw std::runtime_error("Division by zero!");
                    }

                    auto firstValue = stack.pop();

                    auto result = *firstValue / *secondValue;

                    stack.push(reinterpret_cast<GSByte*>(&result));

                    break;
                }
                case Opcode::CALL: {
                    auto functionNumber = *registers[0].getValue();

                    auto argument = registers[1].getValue();

                    if (functionNumber == 0) {
                        Native::print(argument);
                    }
                    else if (functionNumber == 1) {
                        Native::println(argument);
                    }

                    break;
                }
                case Opcode::SAVE: {
                    decoder.nextByte();

                    auto variableId = decoder.currentByte();

                    auto value = stack.pop();

                    variablesTable.setValueById(variableId, *value);

                    break;
                }
                case Opcode::GET: {
                    decoder.nextByte();

                    auto variableId = decoder.currentByte();

                    auto value = variablesTable.getValueById(variableId);

                    stack.push(reinterpret_cast<GSByte*>(&value));

                    break;
                }
                case Opcode::DONE: {
                    return;
                }
            }

            decoder.nextByte();
        }
    }

}