#include "../../../../include/VirtualMachine/Parser/Statements/GS_ReserveStatement.h"

namespace GSVirtualMachine::Statements {

    GS_ReserveStatement::GS_ReserveStatement(std::string &variableName) {
        this->_variableName = variableName;
    }

    std::string GS_ReserveStatement::getVariableName() {
        return _variableName;
    }

    StatementType GS_ReserveStatement::getStatementType() {
        return StatementType::RESERVE_STATEMENT;
    }

    std::string GS_ReserveStatement::toStringForDebug() {
        return "[ reserve "
        + this->_variableName
        + " ]";
    }

}