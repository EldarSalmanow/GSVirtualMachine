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

            if (_compilerData.argumentsOptions.getIsInvalidArguments()) {
                return 1;
            } else if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
                GS_Timer totalTimer;

                totalTimer.start();

                startCompiling();

                totalTimer.stop();

                _timer.addResult("Total time: \t\t\t\t\t" + std::to_string(totalTimer.result().count()) + " microseconds\n");

                _timer.printResults();
            } else {
                startCompiling();
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

    void GS_Starter::startReader() {
        auto reader = std::make_shared<GS_Reader>(_compilerData.argumentsOptions.getInputFilename());

        if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
            GS_Timer readerTimer;

            readerTimer.start();

            _compilerData.inputSource = reader->readFile();

            readerTimer.stop();

            _timer.addResult("Reading input time: \t\t\t\t" + std::to_string(readerTimer.result().count()) + " microseconds\n");
        } else {
            _compilerData.inputSource = reader->readFile();
        }
    }

    void GS_Starter::startRuntime() {
        if (_compilerData.argumentsOptions.getIsEnableProfiling()) {
            GS_Timer runtimeTimer;

            runtimeTimer.start();

            GS_Runtime::run(_compilerData.inputSource);

            runtimeTimer.stop();

            _timer.addResult("Running program time: \t\t\t\t" + std::to_string(runtimeTimer.result().count()) + " microseconds\n");
        } else {
            GS_Runtime::run(_compilerData.inputSource);
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
        GS_Timer debugTimer;

        debugTimer.start();

        GS_Debug::printDebugInformation("\n----------READER OUT START----------\n", "\n----------READER OUT END----------\n",
                                        &GS_DebugFunctions::printReaderDebugInfo, _compilerData.inputSource);

        debugTimer.stop();

        _timer.addResult("Printing debug info time: \t\t\t" + std::to_string(debugTimer.result().count()) + " microseconds\n");
    }

}