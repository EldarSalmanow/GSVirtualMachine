#include <Starter/GS_Starter.h>

namespace Starter {

    GSVoid GS_DebugFunctions::printReaderDebugInfo(GSByte &byte) {
        std::cerr
                << std::nouppercase
                << std::showbase
                << std::hex
                << static_cast<GSShort>(byte)
                << std::dec
                << std::endl;
    }

    GSVoid printException(Exceptions::GS_Exception &exception) {
        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::RED);

        std::cerr << exception.what() << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::WHITE);
    }

    GSInt GS_Starter::start(GSInt argc, GSChar **argv) {
        try {
            parseArguments(argc, argv);

            std::function<GSVoid()> function = [] () -> GSVoid {
                startCompiling();
            };

            if (_compilerData.argumentsOptions.getIsInvalidArguments()) {
                return 1;
            } else if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
                runWithTimer(function, "Total time: \t\t\t\t\t");

                _timer.printResults();
            } else {
                function();
            }

        } catch (Exceptions::GS_Exception &exception) {
            printException(exception);

            return 1;
        } catch (std::exception &exception) {
            std::cerr << "System error!\n" << exception.what() << std::endl;

            return 1;
        }

        return 0;
    }

    void GS_Starter::startCompiling() {
        // reading source from file
        startReader();

        // starting program and vm
        startRuntime();

        if (_compilerData.argumentsOptions.getIsEnableTesting()) {
            // start debug mode
            startDebugMode();
        }
    }

    GSVoid GS_Starter::runWithTimer(std::function<GSVoid()> &function, GSString messageForProfiling) {
        GS_Timer timer;

        timer.start();

        function();

        timer.stop();

        _timer.addResult(messageForProfiling + std::to_string(timer.result().count()) + " microseconds\n");
    }

    void GS_Starter::startReader() {
        auto reader = std::make_shared<GS_Reader>(_compilerData.argumentsOptions.getInputFilename());

        std::function<GSVoid()> function = [reader] () -> GSVoid {
            _compilerData.inputSource = reader->readFile();
        };

        if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
            runWithTimer(function, "Reading input time: \t\t\t\t");
        } else {
            function();
        }
    }

    void GS_Starter::startRuntime() {
        std::function<GSVoid()> function = [] () -> GSVoid {
            GS_Runtime::run(_compilerData.inputSource);
        };

        if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
            runWithTimer(function, "Running program time: \t\t\t\t");
        } else {
            function();
        }
    }

    GSVoid GS_Starter::parseArguments(GSInt argc, GSChar *argv[]) {
        auto argumentsParser = std::make_shared<GS_Arguments>(argc, argv);

        _compilerData.argumentsOptions = argumentsParser->parseArguments();

        if (argc < 3 || _compilerData.argumentsOptions.getInputFilename().empty()) {
            argumentsParser->printUsage();

            _compilerData.argumentsOptions.setIsInvalidArguments(true);
        }
    }

    void GS_Starter::startDebugMode() {
        std::function<GSVoid()> function = [] () -> GSVoid {
            GS_Debug::printDebugInformation("\n----------READER OUT START----------\n", "\n----------READER OUT END----------\n",
                                            &GS_DebugFunctions::printReaderDebugInfo, _compilerData.inputSource);
        };

        if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
            runWithTimer(function, "Printing debug info time: \t\t\t");
        } else {
            function();
        }
    }

}