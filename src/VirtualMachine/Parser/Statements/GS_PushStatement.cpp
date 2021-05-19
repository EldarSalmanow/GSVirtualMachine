#include "../../../../include/VirtualMachine/Parser/Statements/GS_PushStatement.h"

namespace GSVirtualMachine::Statements {

    GS_PushStatement::GS_PushStatement(GSValuePointer &value) {
        this->_value = value;
    }

    GSValuePointer GS_PushStatement::getValue() {
        return _value;
    }

    StatementType GS_PushStatement::getStatementType() {
        return StatementType::PUSH_STATEMENT;
    }

    std::string GS_PushStatement::toStringForDebug() {
        return "[ push "
        + this->_value->getString()
        + " ]";
    }

}