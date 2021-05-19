#ifndef GSVIRTUALMACHINE_GS_JMPSTATEMENT_H
#define GSVIRTUALMACHINE_GS_JMPSTATEMENT_H

#include <string>

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_JmpStatement : public GS_Statement {
    public:

        /**
         *
         * @param address
         */
        GS_JmpStatement(std::string &address);

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

#endif //GSVIRTUALMACHINE_GS_JMPSTATEMENT_H
