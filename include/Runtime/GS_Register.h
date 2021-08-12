#ifndef GSVIRTUALMACHINE_GS_REGISTER_H
#define GSVIRTUALMACHINE_GS_REGISTER_H

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_Register {
    public:

        /**
         *
         */
        GS_Register();

    public:

        /**
         *
         * @return
         */
        GSBytePtr getValue();

        /**
         *
         * @param value
         * @return
         */
        GSVoid setValue(GSBytePtr value);

    private:

        /**
         *
         */
        GSBytePtr _value;
    };

}

#endif //GSVIRTUALMACHINE_GS_REGISTER_H
