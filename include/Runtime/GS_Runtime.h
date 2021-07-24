#ifndef GSVIRTUALMACHINE_GS_RUNTIME_H
#define GSVIRTUALMACHINE_GS_RUNTIME_H

#include <iostream>

#include <asmjit/asmjit.h>

#include <Runtime/GS_VMImageDecoder.h>
#include <Runtime/GS_VM.h>
#include <Runtime/GS_VMTables.h>

#include <Exceptions/GS_Exception.h>

namespace GSVirtualMachine::Runtime {

    using namespace asmjit;
    using namespace x86;

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

    private:

        /**
         *
         */
        inline static GS_VMConstTable _constantTable;

        /**
         *
         */
        inline static GS_VMVariableTable _variableTable;

        /**
         *
         */
        inline static GS_VMFunctionTable _functionTable;
    };

}

#endif //GSVIRTUALMACHINE_GS_RUNTIME_H
