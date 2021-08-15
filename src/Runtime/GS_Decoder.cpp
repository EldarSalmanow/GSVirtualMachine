#include <GS_Decoder.h>

namespace GSVirtualMachine::Runtime {

    GS_Decoder::GS_Decoder(GSByteCode bytecode)
            : _bytecode(std::move(bytecode)), _bytecodePtr(&_bytecode[0]), _bytecodeIndex(0) {}

    GSBytePtr GS_Decoder::currentByte() {
        if (!end()) {
            return _bytecodePtr;
        } else {
            throw Exceptions::GS_Exception("Bytecode has ended!");
        }
    }

    GSVoid GS_Decoder::nextByte() {
//        ++_bytecodeIndex;

        ++_bytecodePtr;

        if (end()) {
            throw Exceptions::GS_Exception("Bytecode is ended!");
        }
    }

    GSVoid GS_Decoder::prevByte() {
        --_bytecodePtr;
    }

    GSVoid GS_Decoder::jmpTo(GSBytePtr address) {
        _bytecodePtr = address;
    }

    GSBool GS_Decoder::end() {
        return _bytecodePtr == nullptr;
    }

    Opcode GS_Decoder::opcode() {
        return byteToOpcode[*currentByte()];
    }

    GSString GS_Decoder::string() {
        GSString value;

        while (true) {
            auto symbol = *currentByte();

            value += static_cast<GSChar>(symbol);

            if (symbol == 0) {
                break;
            }

            nextByte();
        }

        nextByte();

        return value;
    }

    GSVoid GS_Decoder::setCursorToStart() {
        _bytecodePtr = &_bytecode[0];
    }

}
