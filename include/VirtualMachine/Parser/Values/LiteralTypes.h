#ifndef GSVIRTUALMACHINE_LITERALTYPES_H
#define GSVIRTUALMACHINE_LITERALTYPES_H

#include <vector>
#include <string>

#include "../../Lexer/GS_Keywords.h"

namespace GSVirtualMachine {

    using namespace Lexer;

    /**
     *
     */
    enum class Literal {
        LITERAL_NULL,  // invalid type

        LITERAL_INT,   // 14
    };

    /**
     *
     */
    extern std::vector<Literal> types;

    /**
     *
     * @param literal
     * @return
     */
    extern std::string convertLiteralToString(Literal literal);

}

#endif //GSVIRTUALMACHINE_LITERALTYPES_H
