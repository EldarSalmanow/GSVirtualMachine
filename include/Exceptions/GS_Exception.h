#ifndef GSVIRTUALMACHINE_GS_EXCEPTION_H
#define GSVIRTUALMACHINE_GS_EXCEPTION_H

#include <iostream>

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Exceptions {

    /**
     *
     */
    class GS_Exception : std::exception {
    public:

        /**
         *
         * @param errorMessage
         */
        explicit GS_Exception(GSString errorMessage)
                : _errorMessage(std::move(errorMessage)) {}

    public:

        /**
         *
         * @return
         */
        const GSChar *what() {
            return _errorMessage.c_str();
        }

    private:

        /**
         *
         */
        GSString _errorMessage;
    };

}

#endif //GSVIRTUALMACHINE_GS_EXCEPTION_H
