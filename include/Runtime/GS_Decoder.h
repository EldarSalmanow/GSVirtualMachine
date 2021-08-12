#ifndef GSVIRTUALMACHINE_GS_DECODER_H
#define GSVIRTUALMACHINE_GS_DECODER_H

#include <Runtime/GS_Opcode.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_Decoder {
    public:

        /**
         *
         * @param bytecode
         */
        explicit GS_Decoder(GSByteCode bytecode);

    public:

        /**
         *
         * @return
         */
        GSByte currentByte();

        /**
         *
         * @return
         */
        GSVoid nextByte();

        /**
         *
         * @return
         */
        GSBool end();

        /**
         *
         * @return
         */
        Opcode opcode();

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

#endif //GSVIRTUALMACHINE_GS_DECODER_H
