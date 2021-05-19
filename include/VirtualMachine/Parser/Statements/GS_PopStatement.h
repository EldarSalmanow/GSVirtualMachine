#ifndef GSVIRTUALMACHINE_GS_POPSTATEMENT_H
#define GSVIRTUALMACHINE_GS_POPSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_PopStatement : public GS_Statement {
    public:

        /**
         *
         */
        GS_PopStatement();

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

#endif //GSVIRTUALMACHINE_GS_POPSTATEMENT_H
