#ifndef GSVIRTUALMACHINE_GS_VALUEEXPRESSION_H
#define GSVIRTUALMACHINE_GS_VALUEEXPRESSION_H

#include "GS_Expression.h"

namespace GSVirtualMachine::Expressions {

    /**
     *
     */
    class GS_ValueExpression : public GS_Expression {
    public:

        /**
         *
         */
        GS_ValueExpression() = default;

        /**
         *
         * @param value
         */
        GS_ValueExpression(GSValuePointer value);

        /**
         *
         * @param value
         * @param type
         */
        GS_ValueExpression(GSValuePointer value, Literal type);

    public:

        /**
         *
         * @return
         */
        GSValuePointer getValue();

        /**
         *
         * @return
         */
        Literal getType();

    public:

        /**
         *
         * @return
         */
        GSValuePointer result() override;

        /**
         *
         */
        void run() override;

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

        /**
         *
         */
        Literal _type;
    };

}

#endif //GSVIRTUALMACHINE_GS_VALUEEXPRESSION_H
