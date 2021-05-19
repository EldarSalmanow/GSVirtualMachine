#ifndef GSVIRTUALMACHINE_GS_KEYWORDS_H
#define GSVIRTUALMACHINE_GS_KEYWORDS_H

#include <map>
#include <string>

namespace GSVirtualMachine::Lexer {

    /**
     * Type of token
     */
    enum class TokenType {
        END_OF_FILE,
        NEW_LINE,

        WORD,                     // main

        LITERAL_NUMBER,           // 12

        KEYWORD_PUSH,             // push
        KEYWORD_POP,              // pop
        KEYWORD_ADD,              // add
        KEYWORD_SUB,              // sub
        KEYWORD_LT,               // lt
        KEYWORD_GET,              // get
        KEYWORD_SAVE,             // save
        KEYWORD_RESERVE,          // reserve
        KEYWORD_JZ,               // jz
        KEYWORD_JNZ,              // jnz
        KEYWORD_JMP,              // jmp

        SYMBOL_COLON,             // :
    };

    /**
     * Reserved letters and symbols
     */
    extern std::map<std::string, TokenType> reserved;

}

#endif //GSVIRTUALMACHINE_GS_KEYWORDS_H
