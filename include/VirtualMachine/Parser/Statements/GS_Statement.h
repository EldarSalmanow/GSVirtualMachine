#ifndef GSVIRTUALMACHINE_GS_STATEMENT_H
#define GSVIRTUALMACHINE_GS_STATEMENT_H

#include <string>
#include <memory>
#include <vector>

#include "GS_StatementTypes.h"

namespace GSVirtualMachine::Statements {

    /**
     * Base class for statements
     */
    class GS_Statement {
    public:

        /**
         *
         * @return
         */
        virtual StatementType getStatementType() = 0;

        /**
         *
         * @return
         */
        virtual std::string toStringForDebug() = 0;
    };

    typedef std::shared_ptr<GS_Statement> GSStatementPointer;
    typedef std::vector<GSStatementPointer> GSStatementPointerArray;

}

#endif //GSVIRTUALMACHINE_GS_STATEMENT_H
