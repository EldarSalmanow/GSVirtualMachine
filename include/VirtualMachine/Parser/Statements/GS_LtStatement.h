#ifndef GSVIRTUALMACHINE_GS_LTSTATEMENT_H
#define GSVIRTUALMACHINE_GS_LTSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_LtStatement : public GS_Statement {
    public:

        /**
         *
         */
        GS_LtStatement();

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

#endif //GSVIRTUALMACHINE_GS_LTSTATEMENT_H
