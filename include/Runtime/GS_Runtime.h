#ifndef GSVIRTUALMACHINE_GS_RUNTIME_H
#define GSVIRTUALMACHINE_GS_RUNTIME_H

#include <iostream>

//#include <asmjit/asmjit.h>

#include <Runtime/GS_Decoder.h>
#include <Runtime/GS_Stack.h>
#include <Runtime/GS_Register.h>
#include <Runtime/GS_TablesOfSymbols.h>

namespace GSVirtualMachine::Runtime {

//    using namespace asmjit;
//    using namespace x86;

    /**
     *
     */
    class GS_Runtime {
    public:

        /**
         *
         * @param bytecode
         */
        static GSVoid run(GSByteCode &bytecode);
    };

}

#endif //GSVIRTUALMACHINE_GS_RUNTIME_H
