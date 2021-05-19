#include "../../../../include/VirtualMachine/Parser/Statements/GS_SaveStatement.h"

namespace GSVirtualMachine::Statements {

    GS_SaveStatement::GS_SaveStatement(std::string &variableName) {
        this->_variableName = variableName;
    }

    std::string GS_SaveStatement::getVariableName() {
        return _variableName;
    }

    StatementType GS_SaveStatement::getStatementType() {
        return StatementType::SAVE_STATEMENT;
    }

    std::string GS_SaveStatement::toStringForDebug() {
        return "[ save "
        + this->_variableName
        + " ]";
    }

}