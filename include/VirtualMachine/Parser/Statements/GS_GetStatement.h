#ifndef GSVIRTUALMACHINE_GS_GETSTATEMENT_H
#define GSVIRTUALMACHINE_GS_GETSTATEMENT_H

#include "GS_Statement.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_GetStatement : public GS_Statement {
    public:

        /**
         *
         * @param variableName
         */
        GS_GetStatement(std::string &variableName);

    public:

        /**
         *
         * @return
         */
        std::string getVariableName();

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
        std::string _variableName;
    };

}

#endif //GSVIRTUALMACHINE_GS_GETSTATEMENT_H
