#include "../../../../include/VirtualMachine/Parser/Values/LiteralTypes.h"

namespace GSVirtualMachine {

    std::vector<Literal> types = {
            Literal::LITERAL_INT,
    };

    std::string convertLiteralToString(Literal literal) {
        switch (literal) {
            case Literal::LITERAL_NULL:
                return "LITERAL_NULL";
            case Literal::LITERAL_INT:
                return "LITERAL_INT";
            default:
                return "!!ERROR!!";
        }
    }

}