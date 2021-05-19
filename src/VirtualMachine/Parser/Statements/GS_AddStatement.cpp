#include "../../../../include/VirtualMachine/Parser/Statements/GS_AddStatement.h"

namespace GSVirtualMachine::Statements {

    GS_AddStatement::GS_AddStatement() = default;

    StatementType GS_AddStatement::getStatementType() {
        return StatementType::ADD_STATEMENT;
    }

    std::string GS_AddStatement::toStringForDebug() {
        return "[ add ]";
    }

}