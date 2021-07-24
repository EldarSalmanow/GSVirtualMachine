#include <GS_VMImageDecoder.h>

namespace GSVirtualMachine::Runtime {

    GS_VMImageDecoder::GS_VMImageDecoder(GSByteCode bytecode)
            : _bytecode(std::move(bytecode)), _bytecodeIterator(_bytecode.begin()) {}

    Opcode GS_VMImageDecoder::decodeByte() {
        return byteToOpcode[_bytecodeIterator[0]];
    }

    GSByte GS_VMImageDecoder::getByte() {
        return _bytecodeIterator[0];
    }

    GSVoid GS_VMImageDecoder::nextByte() {
        ++_bytecodeIterator;
    }

}