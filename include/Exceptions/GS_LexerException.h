#ifndef GSVIRTUALMACHINE_GS_LEXEREXCEPTION_H
#define GSVIRTUALMACHINE_GS_LEXEREXCEPTION_H

#include "GS_CompilingException.h"

namespace GSVirtualMachine::Exceptions {

    /**
     * Class for throwing lexical parsing errors
     */
    class GS_LexerException : public GS_CompilingException {
    public:

        GS_LexerException(std::string errorMessage, size_t line = 0, size_t column = 0) {
            this->errorMessage = errorMessage;
            this->line = line;
            this->column = column;
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

#endif //GSVIRTUALMACHINE_GS_LEXEREXCEPTION_H
