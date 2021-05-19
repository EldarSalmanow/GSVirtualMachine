#ifndef GSVIRTUALMACHINE_GS_RUNTIME_H
#define GSVIRTUALMACHINE_GS_RUNTIME_H

#include "../Parser/GS_IncludeStatements.h"

#include "GS_Stack.h"
#include "GS_TableOfSymbols.h"

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_Runtime {
    public:

        /**
         *
         * @param statements
         */
        static void run(Statements::GSStatementPointerArray &statements);

    private:

        /**
         *
         */
        static void _nextStatement();

        /**
         *
         * @return
         */
        static Statements::GSStatementPointer _currentStatement();

        /**
         *
         * @return
         */
        static bool _isEndOfStatements();

    private:

        /**
         *
         */
        inline static Statements::GSStatementPointerArray _statements;

        /**
         *
         */
        inline static Statements::GSStatementPointerArray::iterator _statementIterator;

        static void _runPushStatement();

        static void _runPopStatement();

        static void _runAddStatement();

        static void _runSubStatement();

        static void _runLtStatement();

        static void _runGetStatement();

        static void _runSaveStatement();

        static void _runReserveStatement();

        static void _runJzStatement();

        static void _runJnzStatement();

        static void _runJmpStatement();
    };

}

#endif //GSVIRTUALMACHINE_GS_RUNTIME_H
