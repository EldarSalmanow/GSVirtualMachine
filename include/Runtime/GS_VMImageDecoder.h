#ifndef GSVIRTUALMACHINE_GS_VMIMAGEDECODER_H
#define GSVIRTUALMACHINE_GS_VMIMAGEDECODER_H

#include <Runtime/GS_Opcode.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_VMImageDecoder {
    public:



        /**
         *
         * @param bytecode
         */
        explicit GS_VMImageDecoder(GSByteCode bytecode);

    public:

        /**
         *
         * @return
         */
        Opcode decodeByte();

        /**
         *
         * @return
         */
        GSByte getByte();

        /**
         *
         * @return
         */
        GSVoid nextByte();

    private:

        /**
         *
         */
        GSByteCode _bytecode;

        /**
         *
         */
        GSByteCode::iterator _bytecodeIterator;
    };

}

#endif //GSVIRTUALMACHINE_GS_VMIMAGEDECODER_H
