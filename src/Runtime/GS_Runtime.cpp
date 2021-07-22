#include <GS_Runtime.h>

namespace GSVirtualMachine::Runtime {

    class VM {
    public:

        std::stack<GSByte> stack;

        GSByte registers[8] = {
                0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
        };
    };

    std::map<GSByte, Opcode> byteToOpcode = {
            {0x0,  Opcode::PUSH_I},
            {0x1,  Opcode::POP},

            {0x2,  Opcode::ADD},
            {0x3,  Opcode::SUB},

            {0xf,  Opcode::TO_REG_1},
            {0xf1, Opcode::FROM_REG_1},

            {0xf2, Opcode::TO_REG_2},
            {0xf3, Opcode::FROM_REG_2},

            {0xf4, Opcode::TO_REG_3},
            {0xf5, Opcode::FROM_REG_3},

            {0xff, Opcode::DONE},
    };

    GSVoid GS_Runtime::run(GSByteCode &bytecode) {
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
                case Opcode::TO_REG_1: {
                    vm->registers[0] = vm->stack.top();

                    vm->stack.pop();

                    break;
                }
                case Opcode::FROM_REG_1: {
                    vm->stack.push(vm->registers[0]);

                    break;
                }
                case Opcode::TO_REG_2: {
                    vm->registers[1] = vm->stack.top();

                    vm->stack.pop();

                    break;
                }
                case Opcode::FROM_REG_2: {
                    vm->stack.push(vm->registers[1]);

                    break;
                }
                case Opcode::TO_REG_3: {
                    vm->registers[2] = vm->stack.top();

                    vm->stack.pop();

                    break;
                }
                case Opcode::FROM_REG_3: {
                    vm->stack.push(vm->registers[2]);

                    break;
                }
                case Opcode::DONE: {
//                    std::cerr << "STACK START\n" << std::endl;
//
//                    while (!vm->stack.empty()) {
//                        std::cerr
//                        << std::nouppercase
//                        << std::showbase
//                        << std::hex
//                        << static_cast<GSShort>(vm->stack.top())
//                        << std::dec
//                        << std::endl;
//
//                        vm->stack.pop();
//                    }
//
//                    std::cerr << "\nSTACK END\n" << std::endl;
//
//                    std::cerr << "REGISTERS START\n" << std::endl;
//
//                    for (auto &value : vm->registers) {
//                        static GSInt registerCount = 1;
//
//                        std::cerr
//                        << "Register number: "
//                        << registerCount
//                        << "  Value: "
//                        << std::nouppercase
//                        << std::showbase
//                        << std::hex
//                        << static_cast<GSShort>(value)
//                        << std::dec
//                        << std::endl;
//
//                        ++registerCount;
//                    }
//
//                    std::cerr << "\nREGISTERS END" << std::endl;

                    return;
                }
            }

            ++_bytecodeIterator;
        }
    }

}