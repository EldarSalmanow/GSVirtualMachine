#include <GS_Runtime.h>

namespace GSVirtualMachine::Runtime {

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

    GSVoid GS_Runtime::run(GSByteCode &bytecode) {
        GS_VMImageDecoder decoder(bytecode);

        VM<GSByte> vm;

        while (decoder.decodeByte() == Opcode::CONSTANT) {
            decoder.nextByte();

            auto index = decoder.getByte();

            decoder.nextByte();

            auto value = decoder.getByte();

            decoder.nextByte();

            _constantTable.indexToConstant[index] = value;
        }

        while (decoder.decodeByte() == Opcode::VARIABLE) {
            decoder.nextByte();

            auto index = decoder.getByte();

            decoder.nextByte();

            GSString variableName;

            while (decoder.getByte() != '\0') {
                variableName += static_cast<GSChar>(decoder.getByte());

                decoder.nextByte();
            }

            decoder.nextByte();

            _variableTable.indexToVariableName[index] = variableName;
        }

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

            _functionTable.indexToFunctionName[index] = functionName;
        }

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
                decoder.nextByte();

                auto secondValue = decoder.getByte();

                decoder.nextByte();

                auto firstValue = decoder.getByte();

                vm.stack.push(firstValue + secondValue);

                break;
            }
            case Opcode::SUB: {
                decoder.nextByte();

                auto secondValue = decoder.getByte();

                decoder.nextByte();

                auto firstValue = decoder.getByte();

                vm.stack.push(firstValue - secondValue);

                break;
            }
            case Opcode::MUL: {
                decoder.nextByte();

                auto secondValue = decoder.getByte();

                decoder.nextByte();

                auto firstValue = decoder.getByte();

                vm.stack.push(firstValue * secondValue);

                break;
            }
            case Opcode::DIV: {
                decoder.nextByte();

                auto secondValue = decoder.getByte();

                if (secondValue == 0) {
                    throw Exceptions::GS_Exception("Division by zero!");
                }

                decoder.nextByte();

                auto firstValue = decoder.getByte();

                vm.stack.push(firstValue / secondValue);

                break;
            }
            case Opcode::CALL: {
                decoder.nextByte();

                auto index = decoder.getByte();

                auto functionName = _functionTable.indexToFunctionName[index];

                if (functionName == "print") {
                    GSString message = "Hello, Print!";

                    print(message);
                } else if (functionName == "println") {
                    GSString message = "Hello, Println!";

                    println(message);
                } else if (functionName == "input") {
                    GSString variable;

                    input(variable);

                    print(variable);
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