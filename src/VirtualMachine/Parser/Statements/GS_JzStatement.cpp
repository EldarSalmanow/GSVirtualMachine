#include "../../../../include/VirtualMachine/Parser/Statements/GS_JzStatement.h"

namespace GSVirtualMachine::Statements {

    GS_JzStatement::GS_JzStatement(std::string &address) {
        this->_addressForJump = address;
    }

    StatementType GS_JzStatement::getStatementType() {
        return StatementType::JZ_STATEMENT;
    }

    std::string GS_JzStatement::toStringForDebug() {
        return "[ jz "
        + this->_addressForJump
        + " ]";
    }

}