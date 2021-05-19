#ifndef GSVIRTUALMACHINE_GS_SUBSTATEMENT_H
#define GSVIRTUALMACHINE_GS_SUBSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_SubStatement : public GS_Statement {
    public:

        /**
         *
         */
        GS_SubStatement();

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

#endif //GSVIRTUALMACHINE_GS_SUBSTATEMENT_H
