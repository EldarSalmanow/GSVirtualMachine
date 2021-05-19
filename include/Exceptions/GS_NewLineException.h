#ifndef GSVIRTUALMACHINE_GS_NEWLINEEXCEPTION_H
#define GSVIRTUALMACHINE_GS_NEWLINEEXCEPTION_H

#include "GS_Exception.h"

namespace GSVirtualMachine::Exceptions {

    /**
     * Special class error for throwing a newline token to the parser at the moment of meeting
     */
    class GS_NewLineException : public _GS_Exception {
    public:

        GS_NewLineException() = default;
    };

}

#endif //GSVIRTUALMACHINE_GS_NEWLINEEXCEPTION_H
