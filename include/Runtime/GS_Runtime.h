#ifndef GSVIRTUALMACHINE_GS_RUNTIME_H
#define GSVIRTUALMACHINE_GS_RUNTIME_H

#include <iostream>

//#include <asmjit/asmjit.h>

#include <Runtime/GS_Decoder.h>
#include <Runtime/GS_Stack.h>
#include <Runtime/GS_Register.h>
#include <Runtime/GS_Flag.h>
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

    private:

        /**
         *
         * @param decoder
         * @param variablesTable
         * @return
         */
        static GSVoid _runVariableNumberInstruction(GS_Decoder &decoder, GS_VariablesTable &variablesTable);

        /**
         *
         * @param decoder
         * @param constantsTable
         * @return
         */
        static GSVoid _runConstantStringInstruction(GS_Decoder &decoder, GS_ConstantsTable &constantsTable);

        /**
         *
         * @param decoder
         * @param stack
         * @return
         */
        static GSVoid _runPushInstruction(GS_Decoder &decoder, GS_Stack &stack);

        /**
         *
         * @param stack
         * @return
         */
        static GSVoid _runPopInstruction(GS_Stack &stack);

        /**
         *
         * @param decoder
         * @param stack
         * @param constantsTable
         * @return
         */
        static GSVoid _runPushConstantAdrInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_ConstantsTable &constantsTable);

        /**
         *
         * @param decoder
         * @param stack
         * @param registers
         * @return
         */
        static GSVoid _runToRegInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_Register *registers);

        /**
         *
         * @param decoder
         * @param stack
         * @param registers
         * @return
         */
        static GSVoid _runFromRegInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_Register *registers);

        /**
         *
         * @param decoder
         * @param stack
         * @param variablesTable
         * @return
         */
        static GSVoid _runSaveInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_VariablesTable &variablesTable);

        /**
         *
         * @param decoder
         * @param stack
         * @param variablesTable
         * @return
         */
        static GSVoid _runGetInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_VariablesTable &variablesTable);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @return
         */
        static GSVoid _runLabelInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @return
         */
        static GSVoid _runJmpInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @param flags
         * @return
         */
        static GSVoid _runJieInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flag);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @param flags
         * @return
         */
        static GSVoid _runJineInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @param flags
         * @return
         */
        static GSVoid _runJigInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @param flags
         * @return
         */
        static GSVoid _runJilInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @param flags
         * @return
         */
        static GSVoid _runJiegInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags);

        /**
         *
         * @param decoder
         * @param labelsTable
         * @param flags
         * @return
         */
        static GSVoid _runJielInstruction(GS_Decoder &decoder, GS_LabelsTable &labelsTable, GS_Flag *flags);

        /**
         *
         * @param decoder
         * @param stack
         * @param flags
         * @return
         */
        static GSVoid _runCmpInstruction(GS_Decoder &decoder, GS_Stack &stack, GS_Flag *flags);

        /**
         *
         * @param decoder
         * @param registers
         * @return
         */
        static GSVoid _runCallInstruction(GS_Decoder &decoder, GS_Register *registers);

        /**
         *
         * @param stack
         * @return
         */
        static GSVoid _runAddInstruction(GS_Stack &stack);

        /**
         *
         * @param stack
         * @return
         */
        static GSVoid _runSubInstruction(GS_Stack &stack);

        /**
         *
         * @param stack
         * @return
         */
        static GSVoid _runMulInstruction(GS_Stack &stack);

        /**
         *
         * @param stack
         * @return
         */
        static GSVoid _runDivInstruction(GS_Stack &stack);

    private:

        /**
         *
         */
        static const GSInt REGISTER_NUM = 8;

        /**
         *
         */
        static const GSInt FLAGS_NUM = 3;
    };

}

#endif //GSVIRTUALMACHINE_GS_RUNTIME_H
