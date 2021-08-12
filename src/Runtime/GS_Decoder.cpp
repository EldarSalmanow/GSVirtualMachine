#include <GS_Decoder.h>

namespace GSVirtualMachine::Runtime {

    GS_Decoder::GS_Decoder(GSByteCode bytecode)
            : _bytecode(std::move(bytecode)), _bytecodeIterator(_bytecode.begin()) {}

    GSByte GS_Decoder::currentByte() {
        if (!end()) {
            return _bytecodeIterator[0];
        } else {
            throw std::runtime_error("Bytecode has ended!");
        }
    }

    GSVoid GS_Decoder::nextByte() {
        ++_bytecodeIterator;
    }

    GSBool GS_Decoder::end() {
        return _bytecodeIterator == _bytecode.end();
    }

    Opcode GS_Decoder::opcode() {
        return byteToOpcode[currentByte()];
    }

}
