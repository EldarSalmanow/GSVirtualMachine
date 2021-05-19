#ifndef GSVIRTUALMACHINE_GS_EXPRESSION_H
#define GSVIRTUALMACHINE_GS_EXPRESSION_H

#include "../Values/GS_Value.h"

#include "../../../Exceptions/GS_NotSupportedException.h"

namespace GSVirtualMachine {

    /**
     * Base class for expressions
     */
    class GS_Expression {
    public:

        /**
         * Get runtime result // TODO delete
         * @return Value result
         */
        virtual GSValuePointer result() = 0;

        /**
         * Run code
         */
        virtual void run() = 0;

        /**
         * Converting expression to string
         * @return Converted string
         */
        virtual std::string toStringForDebug() = 0;
    };

    typedef std::shared_ptr<GS_Expression> GSExpressionPointer;
    typedef std::vector<GSExpressionPointer> GSExpressionPointerArray;

}

#endif //GSVIRTUALMACHINE_GS_EXPRESSION_H
