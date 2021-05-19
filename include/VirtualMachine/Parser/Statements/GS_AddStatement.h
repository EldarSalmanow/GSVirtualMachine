#ifndef GSVIRTUALMACHINE_GS_ADDSTATEMENT_H
#define GSVIRTUALMACHINE_GS_ADDSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_AddStatement : public GS_Statement {
    public:

        /**
         *
         */
        GS_AddStatement();

    public:

        /**
         *
         * @return
         */
        StatementType getStatementType() override;

        /**
         *
         * @return
         */
        std::string toStringForDebug() override;

    };

}

#endif //GSVIRTUALMACHINE_GS_ADDSTATEMENT_H
