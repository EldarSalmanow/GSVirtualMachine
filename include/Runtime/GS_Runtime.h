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
         * @param decoder
         * @param constantTable
         * @return
         */
        static GSVoid parseConstants(GS_VMImageDecoder &decoder, GS_VMConstTable &constantTable);

        /**
         *
         * @param decoder
         * @param variableTable
         * @return
         */
        static GSVoid parseVariables(GS_VMImageDecoder &decoder, GS_VMVariableTable &variableTable);

        /**
         *
         * @param decoder
         * @param functionTable
         * @return
         */
        static GSVoid parseFunctions(GS_VMImageDecoder &decoder, GS_VMFunctionTable &functionTable);
    };

}

#endif //GSVIRTUALMACHINE_GS_RUNTIME_H
