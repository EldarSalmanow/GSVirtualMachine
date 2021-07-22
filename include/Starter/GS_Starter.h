#ifndef GSVIRTUALMACHINE_GS_STARTER_H
#define GSVIRTUALMACHINE_GS_STARTER_H

#include <ArgumentsParser/GS_Arguments.h>
#include <Reader/GS_Reader.h>
#include <Runtime/GS_Runtime.h>

#include <Debug/GS_Timer.h>

namespace Starter {

    using namespace GSVirtualMachine;

    using namespace Arguments;

    using namespace Runtime;

    using namespace Debug;

    /**
     *
     */
    class GS_DebugFunctions {
    public:

        /**
         *
         * @param byte
         * @return
         */
        static GSVoid printReaderDebugInfo(GSByte &byte);
    };

    /**
     *
     */
    class GS_CompilerData {
    public:

        /**
         *
         */
        GS_CompilerData() = default;

    public:

        /**
         * Command line arguments
         */
        GS_ArgumentsOptions argumentsOptions;

        /**
         * Source from file
         */
        GSByteCode inputSource;
    };

    /**
     * Class for starting GSVirtualMachine
     */
    class GS_Starter {
    public:

        /**
         * Starting compiler, error handlers and timers
         * @param argc Number of arguments
         * @param argv Array of arguments
         * @return Status number for operation system
         */
        static GSInt start(GSInt argc, GSChar **argv);

    private:

        /**
         *
         * @return
         */
        static GSVoid startCompiling();

        /**
         *
         * @param argc
         * @param argv
         * @return
         */
        static GSVoid parseArguments(GSInt argc, GSChar *argv[]);

        /**
         * Start reading source from file
         */
        static GSVoid startReader();

        /**
         * Start program and VM
         */
        static GSVoid startRuntime();

        /**
         * Start debug functions
         */
        static GSVoid startDebugMode();

    private:

        /**
         *
         */
        inline static GS_CompilerData _compilerData;

        /**
         *
         */
        inline static GS_Timer _timer;
    };

}

#endif //GSVIRTUALMACHINE_GS_STARTER_H
