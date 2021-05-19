#include "../../include/Debug/GS_Debug.h"

namespace Debug {

    void GS_Debug::printInput(GSVirtualMachine::Lexer::GSText &input) {
        std::cerr << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::RED);

        std::cerr << "\n----------READER OUT START----------\n" << std::endl;

        for (auto &line : input) {
            std::cerr << line << std::endl;
        }

        std::cerr << "\n----------READER OUT END----------\n" << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::LIGHT_GRAY);
    }

    void GS_Debug::printLexerOutput(GSVirtualMachine::Lexer::GSTokenArray &tokens) {
        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::RED);

        std::cerr << "\n----------LEXER OUT START----------\n" << std::endl;

        for (auto &token : tokens) {
            std::cerr << tokenTypeToString(token.getType()) << std::endl;
        }

        std::cerr << "\n----------LEXER OUT END----------\n" << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::LIGHT_GRAY);
    }

    void GS_Debug::printParserOutput(GSVirtualMachine::GSStatementPointerArray &statements) {
        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::RED);

        std::cerr << "\n----------PARSER OUT START----------\n" << std::endl;

        for (auto &statement : statements) {
            std::cerr << statement->toStringForDebug() << std::endl;
        }

        std::cerr << "\n----------PARSER OUT END----------\n" << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::LIGHT_GRAY);
    }

    void GS_Debug::printTableOfSymbols() {
        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::RED);

        std::cerr << "\n----------TABLE_OF_SYMBOLS START----------\n" << std::endl;

        for (auto &variableName : GSVirtualMachine::Runtime::GS_TableOfSymbols::getVariableNames()) {
            int value = GSVirtualMachine::Runtime::GS_TableOfSymbols::get(variableName);

            std::cerr
            << "Variable name: " << variableName
            << " Value: " << value
            << std::endl;
        }

        std::cerr << "\n----------TABLE_OF_SYMBOLS END----------\n" << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::LIGHT_GRAY);
    }

    void GS_Debug::printStack() {
        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::RED);

        std::cerr << "\n----------STACK START----------\n" << std::endl;

        while (!GSVirtualMachine::Runtime::GS_Stack::empty()) {
            std::cerr << "Value: " << GSVirtualMachine::Runtime::GS_Stack::top() << std::endl;

            GSVirtualMachine::Runtime::GS_Stack::pop();
        }

        std::cerr << "\n----------STACK END----------\n" << std::endl;

        GS_CrossPlatform::setConsoleColor(GS_CrossPlatform::BLACK, GS_CrossPlatform::LIGHT_GRAY);
    }

    std::string GS_Debug::tokenTypeToString(GSVirtualMachine::Lexer::TokenType type) {
        switch (type) {
            case GSVirtualMachine::Lexer::TokenType::WORD:
                return "WORD";

            case GSVirtualMachine::Lexer::TokenType::LITERAL_NUMBER:
                return "LITERAL_NUMBER";

            case GSVirtualMachine::Lexer::TokenType::KEYWORD_PUSH:
                return "KEYWORD_PUSH  :  \'push\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_POP:
                return "KEYWORD_POP  :  \'pop\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_ADD:
                return "KEYWORD_ADD  :  \'add\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_SUB:
                return "KEYWORD_SUB  :  \'sub\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_LT:
                return "KEYWORD_LT  :  \'lt\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_GET:
                return "KEYWORD_GET  :  \'get\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_SAVE:
                return "KEYWORD_SAVE  :  \'save\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_RESERVE:
                return "KEYWORD_RESERVE  :  \'reserve\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_JZ:
                return "KEYWORD_JZ  :  \'jz\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_JNZ:
                return "KEYWORD_JNZ  :  \'jnz\'";
            case GSVirtualMachine::Lexer::TokenType::KEYWORD_JMP:
                return "KEYWORD_JMP  :  \'jmp\'";

            case GSVirtualMachine::Lexer::TokenType::SYMBOL_COLON:
                return "SYMBOL_COLON  :  \':\'";

            case GSVirtualMachine::Lexer::TokenType::NEW_LINE:
                return "NEW_LINE";
            case GSVirtualMachine::Lexer::TokenType::END_OF_FILE:
                return "END_OF_FILE";
        }
        return "!!ERROR!!";
    }
}