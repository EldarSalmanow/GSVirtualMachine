#include "../../../../include/VirtualMachine/Parser/Statements/GS_GetStatement.h"

namespace GSVirtualMachine::Statements {

    GS_GetStatement::GS_GetStatement(std::string &variableName) {
        this->_variableName = variableName;
    }

    std::string GS_GetStatement::getVariableName() {
        return _variableName;
    }

    StatementType GS_GetStatement::getStatementType() {
        return StatementType::GET_STATEMENT;
    }

    std::string GS_GetStatement::toStringForDebug() {
        return "[ get "
        + this->_variableName
        + " ]";
    }

}
