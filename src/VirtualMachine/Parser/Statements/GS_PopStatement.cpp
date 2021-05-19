#include "../../../../include/VirtualMachine/Parser/Statements/GS_PopStatement.h"

namespace GSVirtualMachine::Statements {

    GS_PopStatement::GS_PopStatement() = default;

    StatementType GS_PopStatement::getStatementType() {
        return StatementType::POP_STATEMENT;
    }

    std::string GS_PopStatement::toStringForDebug() {
        return "[ pop ]";
    }

}