#include <GS_Runtime.h>

namespace GSVirtualMachine::Runtime {

    namespace Native {
        GSVoid print(GSString &string) {
            std::cout << string;
        }

        GSVoid println(GSString &string) {
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
        GS_VMImageDecoder decoder(bytecode);

        VM<GSByte> vm;

        GS_VMConstTable constantTable;
        GS_VMVariableTable variableTable;
        GS_VMFunctionTable functionTable;

        parseConstants(decoder, constantTable);
        parseFunctions(decoder, functionTable);
        parseVariables(decoder, variableTable);

        while (true) {
            switch (decoder.decodeByte()) {
                case Opcode::PUSH: {
                    decoder.nextByte();

                    auto value = decoder.getByte();

                    vm.stack.push(value);

                    break;
                }
                case Opcode::POP: {
                    vm.stack.pop();

                    break;
                }
                case Opcode::ADD: {
                    auto secondValue = vm.stack.top();

                    vm.stack.pop();

                    auto firstValue = vm.stack.top();

                    vm.stack.pop();

                    vm.stack.push(firstValue + secondValue);

                    break;
                }
                case Opcode::SUB: {
                    auto secondValue = vm.stack.top();

                    vm.stack.pop();

                    auto firstValue = vm.stack.top();

                    vm.stack.pop();

                    vm.stack.push(firstValue - secondValue);

                    break;
                }
                case Opcode::MUL: {
                    auto secondValue = vm.stack.top();

                    vm.stack.pop();

                    auto firstValue = vm.stack.top();

                    vm.stack.pop();

                    vm.stack.push(firstValue * secondValue);

                    break;
                }
                case Opcode::DIV: {
                    auto secondValue = vm.stack.top();

                    if (secondValue == 0) {
                        throw Exceptions::GS_Exception("Division by zero!");
                    }

                    vm.stack.pop();

                    auto firstValue = vm.stack.top();

                    vm.stack.pop();

                    vm.stack.push(firstValue / secondValue);

                    break;
                }
                case Opcode::CALL: {
                    decoder.nextByte();

                    auto index = decoder.getByte();

                    auto functionName = functionTable.indexToFunctionName[index];

                    if (functionName == "print") {
                        auto message = constantTable.indexToConstant[vm.registers[0]].getData<GSString>();

                        Native::print(message);
                    } else if (functionName == "println") {
                        auto message = constantTable.indexToConstant[vm.registers[0]].getData<GSString>();

                        Native::println(message);
                    } else if (functionName == "input") {
                        GSString string;

                        Native::input(string);

                        variableTable.indexToVariable[vm.registers[0]].setValue(string);
                    }

                    break;
                }
                case Opcode::TO_REG: {
                    decoder.nextByte();

                    auto registerNumber = decoder.getByte();

                    vm.registers[registerNumber] = vm.stack.top();

                    break;
                }
                case Opcode::FROM_REG: {
                    decoder.nextByte();

                    auto registerNumber = decoder.getByte();

                    vm.stack.push(vm.registers[registerNumber]);

                    vm.registers[registerNumber] = 0;

                    break;
                }
                case Opcode::DONE: {
                    return;
                }
                default:
                    throw Exceptions::GS_Exception("Unknown opcode for VM!");
            }

            decoder.nextByte();
        }
    }

    GSVoid GS_Runtime::parseConstants(GS_VMImageDecoder &decoder, GS_VMConstTable &constantTable) {
        auto opcode = decoder.decodeByte();

        while (opcode == Opcode::CONSTANT_NUMBER || opcode == Opcode::CONSTANT_STRING) {
            decoder.nextByte();

            auto index = decoder.getByte();

            decoder.nextByte();

            if (opcode == Opcode::CONSTANT_NUMBER) {
                auto value = decoder.getByte();

                decoder.nextByte();

                opcode = decoder.decodeByte();

                constantTable.indexToConstant[index] = GS_Constant(value);
            } else if (opcode == Opcode::CONSTANT_STRING) {
                GSString stringConstant;

                while (decoder.getByte() != '\0') {
                    stringConstant += static_cast<GSChar>(decoder.getByte());

                    decoder.nextByte();
                }

                decoder.nextByte();

                opcode = decoder.decodeByte();

                constantTable.indexToConstant[index] = GS_Constant(stringConstant);
            } else {
                throw Exceptions::GS_Exception("Unknown constant type!");
            }
        }
    }

    GSVoid GS_Runtime::parseVariables(GS_VMImageDecoder &decoder, GS_VMVariableTable &variableTable) {
        auto opcode = decoder.decodeByte();

        while (opcode == Opcode::VARIABLE_NUMBER || opcode == Opcode::VARIABLE_STRING) {
            decoder.nextByte();

            auto index = decoder.getByte();

            decoder.nextByte();

            GSString variableName;

            while (decoder.getByte() != '\0') {
                variableName += static_cast<GSChar>(decoder.getByte());

                decoder.nextByte();
            }

            decoder.nextByte();

            if (opcode == Opcode::VARIABLE_NUMBER) {
                variableTable.indexToVariable[index] = GS_Variable(VariableType::NUMBER);
            } else if (opcode == Opcode::VARIABLE_STRING) {
                variableTable.indexToVariable[index] = GS_Variable(VariableType::STRING);
            } else {
                throw Exceptions::GS_Exception("Unknown variable type!");
            }

            opcode = decoder.decodeByte();
        }
    }

    GSVoid GS_Runtime::parseFunctions(GS_VMImageDecoder &decoder, GS_VMFunctionTable &functionTable) {
        while (decoder.decodeByte() == Opcode::FUNCTION) {
            decoder.nextByte();

            auto index = decoder.getByte();

            decoder.nextByte();

            GSString functionName;

            while (decoder.getByte() != '\0') {
                functionName += static_cast<GSChar>(decoder.getByte());

                decoder.nextByte();
            }

            decoder.nextByte();

            functionTable.indexToFunctionName[index] = functionName;
        }
    }

}