#ifndef GSVIRTUALMACHINE_GS_NOTSUPPORTEDEXCEPTION_H
#define GSVIRTUALMACHINE_GS_NOTSUPPORTEDEXCEPTION_H

#include "GS_Exception.h"

namespace GSVirtualMachine::Exceptions {

    /**
     * Special error for throwing errors with not supporting possibilities
     */
    class GS_NotSupportedException : public _GS_Exception {
    public:

        GS_NotSupportedException(std::string errorMessage) {
            this->errorMessage = errorMessage;
        }

    public:

        std::string getErrorMessage() {
            return this->_getErrorMessage();
        }

        void printErrorMessage() {
            return this->_printErrorMessage();
        }

    };

}

#endif //GSVIRTUALMACHINE_GS_NOTSUPPORTEDEXCEPTION_H
