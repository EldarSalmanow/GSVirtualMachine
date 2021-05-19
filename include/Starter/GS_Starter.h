#ifndef GSVIRTUALMACHINE_GS_STARTER_H
#define GSVIRTUALMACHINE_GS_STARTER_H

#include "../../include/Debug/GS_Timer.h"
#include "../../include/Debug/GS_Debug.h"

#include "../../include/VirtualMachine/Util/GS_Arguments.h"
#include "../../include/VirtualMachine/Reader/GS_Reader.h"
#include "../../include/VirtualMachine/Lexer/GS_Lexer.h"
#include "../../include/VirtualMachine/Parser/GS_Parser.h"
#include "../../include/VirtualMachine/Runtime/GS_Runtime.h"

namespace Starter {

    using namespace GSVirtualMachine;

    using namespace Lexer;
    using namespace Runtime;

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
        static int start(int argc, char **argv);

    private:

        /**
        * Start compiling function
        * @param arguments Command line arguments before argument analyzing
        */
        static void startCompiling();

        /**
        * Function for parsing command line arguments and generating config for compiling
        * @param argc Number of arguments
        * @param argv Array of arguments
        * @return Configs for compiling
        */
        static void parseArguments(int argc, char **argv);

        /**
         * Start reading source from file
         */
        static void startReader();

        /**
         * Start lexer analyzing source
         */
        static void startLexer();

        /**
         * Start parser analyzing tokens
         */
        static void startParser();

        /**
         * Start program and VM
         */
        static void startRuntime();

        /**
         * Start debug functions
         */
        static void startDebugMode();

    private:

        /**
         * Class for functions for timers and timers
         */
        class _Timers {
        private:

            /**
             * Initialized functions for timers
             */
            inline static std::function<void()> _startFunction = startCompiling;
            inline static std::function<GSText(GS_Reader&)> _readerFunction = &GS_Reader::readFile;
            inline static std::function<GSTokenArray(GS_Lexer&)> _lexerFunction = &GS_Lexer::tokenize;
            inline static std::function<GSStatementPointerArray(GS_Parser&)> _parserFunction = &GS_Parser::parse;
            inline static std::function<void(GSStatementPointerArray&)> _runtimeFunction = &GS_Runtime::run;

        public:

            /**
             * Timers for profiling compiler
             */
            inline static Debug::GS_Timer<void()> totalTimer = _startFunction;
            inline static Debug::GS_Timer<GSText(GS_Reader&)> readerTimer = _readerFunction;
            inline static Debug::GS_Timer<GSTokenArray(GS_Lexer&)> lexerTimer = _lexerFunction;
            inline static Debug::GS_Timer<GSStatementPointerArray(GS_Parser&)> parserTimer = _parserFunction;
            inline static Debug::GS_Timer<void(GSStatementPointerArray&)> runtimeTimer = _runtimeFunction;
        };

        class _CompilerData {
        public:

            /**
             * Command line arguments
             */
            inline static GSArgumentsPointer arguments;

            /**
             * Source from file
             */
            inline static GSText inputSource;

            /**
             * Tokens before lexer analyzing
             */
            inline static GSTokenArray tokens;

            /**
             * Statements before parser analyzing
             */
            inline static GSStatementPointerArray statements;
        };
    };

}

#endif //GSVIRTUALMACHINE_GS_STARTER_H
