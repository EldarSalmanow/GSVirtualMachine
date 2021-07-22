#include <GS_Runtime.h>

namespace GSVirtualMachine::Runtime {

    class VM {
    public:

        std::stack<GSByte> stack;

        GSByte registers[8] = {
                0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
        };
    };

    class ConstTable {
    public:

        std::map<GSInt, GSString> stringConstants;

        std::map<GSInt, GSString> functionConstants;
    };

    std::map<GSByte, Opcode> byteToOpcode = {
            {0x0,  Opcode::PUSH_I},
            {0x1,  Opcode::POP},

            {0x2,  Opcode::ADD},
            {0x3,  Opcode::SUB},
            {0x4,  Opcode::MUL},
            {0x5,  Opcode::DIV},

            {0x6,  Opcode::CALL},

            {0xf,  Opcode::TO_REG},
            {0xf1, Opcode::FROM_REG},

            {0xff, Opcode::DONE},
    };

    GSVoid print(GSString &string) {
        std::cout << string;
    }

    GSVoid println(GSString &string) {
        std::cout << string << std::endl;
    }

    GSVoid input(GSString &string) {
        GSChar symbol = '\0';

        while (symbol != '\n') {
            std::cin.get(symbol);

            string += symbol;
        }
    }

    GSVoid GS_Runtime::run(GSByteCode &bytecode) {
        auto constTable = new ConstTable;

        constTable->functionConstants[1] = "print";
        constTable->functionConstants[2] = "println";
        constTable->functionConstants[3] = "input";

        auto vm = new VM;

        _bytecode = bytecode;

        _bytecodeIterator = _bytecode.begin();

        while (_bytecodeIterator != bytecode.end()) {
            Opcode opcode = byteToOpcode[_bytecodeIterator[0]];

            switch (opcode) {
                case Opcode::PUSH_I: {
                    ++_bytecodeIterator;

                    auto value = _bytecodeIterator[0];

                    vm->stack.push(value);

                    break;
                }
                case Opcode::POP: {
                    vm->stack.pop();

                    break;
                }
                case Opcode::ADD: {
                    auto secondValue = vm->stack.top();

                    vm->stack.pop();

                    auto firstValue = vm->stack.top();

                    vm->stack.pop();

                    vm->stack.push(firstValue + secondValue);

                    break;
                }
                case Opcode::SUB: {
                    auto secondValue = vm->stack.top();

                    vm->stack.pop();

                    auto firstValue = vm->stack.top();

                    vm->stack.pop();

                    vm->stack.push(firstValue - secondValue);

                    break;
                }
                case Opcode::MUL: {
                    auto secondValue = vm->stack.top();

                    vm->stack.pop();

                    auto firstValue = vm->stack.top();

                    vm->stack.pop();

                    vm->stack.push(firstValue * secondValue);

                    break;
                }
                case Opcode::DIV: {
                    auto secondValue = vm->stack.top();

                    vm->stack.pop();

                    if (secondValue == 0) {
                        throw Exceptions::GS_Exception("Division by zero!");
                    }

                    auto firstValue = vm->stack.top();

                    vm->stack.pop();

                    vm->stack.push(firstValue / secondValue);

                    break;
                }
                case Opcode::CALL: {
                    ++_bytecodeIterator;

                    auto functionName = constTable->functionConstants[static_cast<GSInt>(_bytecodeIterator[0])];

                    ++_bytecodeIterator;

                    auto constantIndex = static_cast<GSInt>(_bytecodeIterator[0]);

                    if (functionName == "print") {
                        print(constTable->stringConstants[constantIndex]);
                    } else if (functionName == "println") {
                        println(constTable->stringConstants[constantIndex]);
                    } else if (functionName == "input") {
                        input(constTable->stringConstants[constantIndex]);
                    }

                    break;
                }
                case Opcode::TO_REG: {
                    ++_bytecodeIterator;

                    auto registerNumber = static_cast<GSInt>(_bytecodeIterator[0]);

                    vm->registers[registerNumber] = vm->stack.top();

                    vm->stack.pop();

                    break;
                }
                case Opcode::FROM_REG: {
                    ++_bytecodeIterator;

                    auto registerNumber = static_cast<GSInt>(_bytecodeIterator[0]);

                    vm->stack.push(vm->registers[registerNumber]);

                    break;
                }
                case Opcode::DONE: {
                    return;
                }
            }

            ++_bytecodeIterator;
        }
    }

}