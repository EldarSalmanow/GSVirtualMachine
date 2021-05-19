#ifndef GSVIRTUALMACHINE_GS_JNZSTATEMENT_H
#define GSVIRTUALMACHINE_GS_JNZSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_JnzStatement : public GS_Statement {
    public:

        /**
         *
         * @param address
         */
        GS_JnzStatement(std::string &address);

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

#endif //GSVIRTUALMACHINE_GS_JNZSTATEMENT_H
