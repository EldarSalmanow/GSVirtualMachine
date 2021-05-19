#ifndef GSVIRTUALMACHINE_GS_PUSHSTATEMENT_H
#define GSVIRTUALMACHINE_GS_PUSHSTATEMENT_H

#include "GS_Statement.h"

#include "../Expressions/GS_VaLueExpression.h"

namespace GSVirtualMachine::Statements {

    /**
     *
     */
    class GS_PushStatement : public GS_Statement {
    public:

        /**
         *
         * @param value
         */
        GS_PushStatement(GSValuePointer &value);

    public:

        /**
         *
         * @return
         */
        GSValuePointer getValue();

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
        GSValuePointer _value;
    };

}

#endif //GSVIRTUALMACHINE_GS_PUSHSTATEMENT_H
