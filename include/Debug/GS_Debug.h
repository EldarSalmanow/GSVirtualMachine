#ifndef GSVIRTUALMACHINE_GS_DEBUG_H
#define GSVIRTUALMACHINE_GS_DEBUG_H

#include "../VirtualMachine/Lexer/GS_Lexer.h"
#include "../VirtualMachine/Parser/GS_Parser.h"
#include "../VirtualMachine/Reader/GS_Reader.h"
#include "../VirtualMachine/Runtime/GS_TableOfSymbols.h"
#include "../VirtualMachine/Runtime/GS_Stack.h"
#include "../VirtualMachine/Util/GS_CrossPlatform.h"

namespace Debug {

    using namespace Platform;

    /**
     * Class for debugging and testing input and output compilation parameters GSVirtualMachine
     */
    class GS_Debug {
    public:

        /**
         * Printing input code from file
         * @param input Container with std::string
         */
        static void printInput(GSVirtualMachine::Lexer::GSText &input);

        /**
         * Printing tokens before lexer analyzing
         * @param tokens Container with GS_Token
         */
        static void printLexerOutput(GSVirtualMachine::Lexer::GSTokenArray &tokens);

        /**
         * Printing statements before parsing analyzing
         * @param statements Container with GSStatementPointer
         */
        static void printParserOutput(GSVirtualMachine::GSStatementPointerArray &statements);

        /**
         * Printing table of symbols
         */
        static void printTableOfSymbols();

        /**
         * Printing stack data
         */
        static void printStack();

    private:

        /**
         * Converting TokenType to std::string
         * @param type Token type
         * @return Converted type
         */
        static std::string tokenTypeToString(GSVirtualMachine::Lexer::TokenType type);
    };

}

#endif //GSVIRTUALMACHINE_GS_DEBUG_H
