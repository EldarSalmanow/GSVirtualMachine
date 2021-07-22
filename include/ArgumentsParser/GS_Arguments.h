#ifndef GSVIRTUALMACHINE_GS_ARGUMENTS_H
#define GSVIRTUALMACHINE_GS_ARGUMENTS_H

#include <memory>
#include <vector>

#include <Exceptions/GS_Exception.h>

namespace GSVirtualMachine::Arguments {

    /**
     *
     */
    class GS_ArgumentsOptions {
    public:

        /**
         *
         */
        GS_ArgumentsOptions() = default;

        /**
         *
         * @param inputFilename
         * @param isEnableTesting
         * @param isEnableProfiling
         */
        explicit GS_ArgumentsOptions(GSString inputFilename,
                            GSBool isEnableTesting = false,
                            GSBool isEnableProfiling = false,
                            GSBool isInvalidArguments = false);

    public:

        /**
         *
         * @return
         */
        GSString getInputFilename();

        /**
         *
         * @return
         */
        GSBool getIsEnableTesting();

        /**
         *
         * @return
         */
        GSBool getIsEnableProfiling();

        /**
         *
         * @return
         */
        GSBool getIsInvalidArguments();

    public:

        /**
         *
         * @param isInvalidArguments
         * @return
         */
        GSVoid setIsInvalidArguments(GSBool isInvalidArguments);

    private:

        /**
         *
         */
        GSString _inputFilename;

        /**
         *
         */
        GSBool _isEnableTesting;

        /**
         *
         */
        GSBool _isEnableProfiling;

        /**
         *
         */
        GSBool _isInvalidArguments;
    };

    /**
     * Class for parsing command line arguments and generate config of compiling
     */
    class GS_Arguments {
    public:

        /**
         * Constructor for GS_Arguments
         * @param argc Number of command line arguments
         * @param argv Array of command line arguments
         */
        GS_Arguments(GSInt argc, GSChar *argv[]);

    public:

        /**
         *
         * @return
         */
        GS_ArgumentsOptions parseArguments();

        /**
         * Function for print usage
         */
        GSVoid printUsage();

    private:

        /**
         * Number of command line arguments
         */
        GSInt _argc;

        /**
         * Array of command line arguments
         */
        GSChar **_argv;
    };

    typedef std::shared_ptr<GS_Arguments> GSArgumentsPointer;

}


#endif //GSVIRTUALMACHINE_GS_ARGUMENTS_H
