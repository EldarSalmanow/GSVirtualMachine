#ifndef GSVIRTUALMACHINE_GS_ARGUMENTEXCEPTION_H
#define GSVIRTUALMACHINE_GS_ARGUMENTEXCEPTION_H

#include "GS_Exception.h"

namespace GSVirtualMachine::Exceptions {

    /**
     * Exception for throwing argument parsing error
     */
    class GS_ArgumentException : public _GS_Exception {
    public:

        GS_ArgumentException(std::string errorMessage) {
            this->errorMessage = errorMessage;
        }

    public:

        std::string getErrorMessage() {
            return this->_getErrorMessage();
        }

        void printErrorMessage() {
            this->_printErrorMessage();
        }
    };

}

#endif //GSVIRTUALMACHINE_GS_ARGUMENTEXCEPTION_H
