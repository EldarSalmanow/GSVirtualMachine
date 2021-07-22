#ifndef GSVIRTUALMACHINE_GS_NEWLINEEXCEPTION_H
#define GSVIRTUALMACHINE_GS_NEWLINEEXCEPTION_H

namespace GSVirtualMachine::Exceptions {

    /**
     * Special class error for throwing a newline token to the parser at the moment of meeting
     */
    class GS_NewLineException {
    public:

        GS_NewLineException() = default;
    };

}

#endif //GSVIRTUALMACHINE_GS_NEWLINEEXCEPTION_H
