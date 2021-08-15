#ifndef GSVIRTUALMACHINE_GS_DECODER_H
#define GSVIRTUALMACHINE_GS_DECODER_H

#include <Runtime/GS_Opcode.h>

#include <Exceptions/GS_Exception.h>

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
        GSBytePtr currentByte();

        /**
         *
         * @return
         */
        GSVoid nextByte();

        /**
         *
         * @return
         */
        GSVoid prevByte();

        /**
         *
         * @param address
         * @return
         */
        GSVoid jmpTo(GSBytePtr address);

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

        /**
         *
         * @return
         */
        GSString string();

        /**
         *
         * @return
         */
        GSVoid setCursorToStart();

    private:

        /**
         *
         */
        GSByteCode _bytecode;

        /**
         *
         */
        GSBytePtr _bytecodePtr;

        /**
         *
         */
        GSInt _bytecodeIndex;
    };

}

#endif //GSVIRTUALMACHINE_GS_DECODER_H
