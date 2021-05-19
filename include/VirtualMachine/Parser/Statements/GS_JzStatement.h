#ifndef GSVIRTUALMACHINE_GS_JZSTATEMENT_H
#define GSVIRTUALMACHINE_GS_JZSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_JzStatement : public GS_Statement {
    public:

        /**
         *
         * @param address
         */
        GS_JzStatement(std::string &address);

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

    private:

        /**
         *
         */
        std::string _addressForJump;
    };

}

#endif //GSVIRTUALMACHINE_GS_JZSTATEMENT_H
