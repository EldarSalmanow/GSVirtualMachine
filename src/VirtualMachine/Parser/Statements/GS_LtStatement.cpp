#include "../../../../include/VirtualMachine/Parser/Statements/GS_LtStatement.h"

namespace GSVirtualMachine::Statements {

    GS_LtStatement::GS_LtStatement() = default;

    StatementType GS_LtStatement::getStatementType() {
        return StatementType::LT_STATEMENT;
    }

    std::string GS_LtStatement::toStringForDebug() {
        return "[ lt ]";
    }

}