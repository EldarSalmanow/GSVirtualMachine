#include "../../../include/VirtualMachine/Lexer/GS_Keywords.h"

namespace GSVirtualMachine::Lexer {

    std::map<std::string, TokenType> reserved = {
            {"push",    TokenType::KEYWORD_PUSH},
            {"pop",     TokenType::KEYWORD_POP},

            {"add",     TokenType::KEYWORD_ADD},
            {"sub",     TokenType::KEYWORD_SUB},
            {"lt",      TokenType::KEYWORD_LT},

            {"get",     TokenType::KEYWORD_GET},
            {"save",    TokenType::KEYWORD_SAVE},
            {"reserve", TokenType::KEYWORD_RESERVE},

            {"jz",      TokenType::KEYWORD_JZ},
            {"jnz",     TokenType::KEYWORD_JNZ},

            {"jmp",     TokenType::KEYWORD_JMP},

            {":",       TokenType::SYMBOL_COLON},
    };

}