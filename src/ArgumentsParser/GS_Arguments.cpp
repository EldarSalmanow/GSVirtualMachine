#include <GS_Arguments.h>

namespace GSVirtualMachine::Arguments {

    GS_ArgumentsOptions::GS_ArgumentsOptions(GSString inputFilename,
                                             GSBool isEnableTesting,
                                             GSBool isEnableProfiling,
                                             GSBool isInvalidArguments)
            : _inputFilename(std::move(inputFilename)),
              _isEnableTesting(isEnableTesting),
              _isEnableProfiling(isEnableProfiling),
              _isInvalidArguments(isInvalidArguments) {}

    GSString GS_ArgumentsOptions::getInputFilename() {
        return _inputFilename;
    }

    GSBool GS_ArgumentsOptions::getIsEnableTesting() {
        return _isEnableTesting;
    }

    GSBool GS_ArgumentsOptions::getIsEnableProfiling() {
        return _isEnableProfiling;
    }

    GSBool GS_ArgumentsOptions::getIsInvalidArguments() {
        return _isInvalidArguments;
    }

    GSVoid GS_ArgumentsOptions::setIsInvalidArguments(GSBool isInvalidArguments) {
        _isInvalidArguments = isInvalidArguments;
    }

    GS_Arguments::GS_Arguments(GSInt argc, GSChar *argv[])
            : _argc(argc), _argv(argv) {}

    GS_ArgumentsOptions GS_Arguments::parseArguments() {
        GSString inputFilename;
        GSBool isEnableTesting;
        GSBool isEnableProfiling;

        for (GSInt index = 1; index < _argc; ++index) {
            GSString argument = _argv[index];
            if (argument == "-f" || argument == "--file") {
                ++index;
                if (_argc < index) {
                    throw Exceptions::GS_Exception("Invalid argument \"" + argument + "\"!");
                }

                inputFilename = _argv[index];

                continue;
            } else if (argument == "-h" || argument == "--help") {
                printUsage();

                break;
            } else if (argument == "-t" || argument == "--test") {
                isEnableTesting = true;

                continue;
            } else if (argument == "-p" || argument == "--profiling") {
                isEnableProfiling = true;

                continue;
            } else {
                throw Exceptions::GS_Exception("Invalid arguments!");
            }
        }

        return GS_ArgumentsOptions(inputFilename, isEnableTesting, isEnableProfiling);
    }

    void GS_Arguments::printUsage() {
        std::cout
                << "Usage: \n"
                << "\t-f --file      \tMain filename to compiling\n"
                << "\t-t --test      \tPrinting information because compiling\n"
                << "\t-p --profiling \tPrinting profiling compilation information"
                << "\t-h --help      \tInformation about flags and compiler\n"
                << std::endl;
    }
}