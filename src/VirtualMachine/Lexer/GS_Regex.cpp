#include "../../../include/VirtualMachine/Lexer/GS_Regex.h"

namespace GSVirtualMachine::Lexer {

    std::regex _numberExpression               = std::regex(R"(\d)");

    std::regex _wordEnglishExpression          = std::regex(R"([a-zA-Z])");

}