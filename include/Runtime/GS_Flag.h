#ifndef GS_TABLESOFSYMBOLS_H_GS_FLAG_H
#define GS_TABLESOFSYMBOLS_H_GS_FLAG_H

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_Flag {
    public:

        /**
         *
         */
        GS_Flag();

    public:

        /**
         *
         * @return
         */
        GSBool isTrue();

        /**
         *
         * @return
         */
        GSBool isFalse();

    public:

        /**
         *
         * @return
         */
        GSVoid setFlag(GSBool value);

    private:

        /**
         *
         */
        GSBool _flag;
    };

}

#endif //GS_TABLESOFSYMBOLS_H_GS_FLAG_H
