#ifndef GSVIRTUALMACHINE_GS_REGEX_H
#define GSVIRTUALMACHINE_GS_REGEX_H

#include <regex>

namespace GSVirtualMachine::Lexer {

    /**
     * Type of regular expression
     * UNSUPPORTED  - type for unsupported characters
     * ALPHABET_... - the alphabet of a language (includes large and small characters)
     * NUMBER_...   - any numeric representations
     */
    enum class RegexType {
        UNSUPPORTED,

        NUMBER_SIMPLE,      // 0..9

        ALPHABET_ENGLISH,   // a..z A..Z
    };

    extern std::regex _numberExpression;

    extern std::regex _wordEnglishExpression;

}

#endif //GSVIRTUALMACHINE_GS_REGEX_H
