#ifndef GSVIRTUALMACHINE_GS_IEXCEPTION_H
#define GSVIRTUALMACHINE_GS_IEXCEPTION_H

#include <iostream>

namespace GSVirtualMachine::Exceptions {

    /**
     * Interface for GSVirtualMachine errors
     */
    class GS_IException {
    public:

        /**
         * Getting an error message
         * @return Error message
         */
        virtual std::string _getErrorMessage() = 0;

        /**
         * Error message output
         */
        virtual void _printErrorMessage() = 0;
    };

}

#endif //GSVIRTUALMACHINE_GS_IEXCEPTION_H
