#include "../../../../include/VirtualMachine/Parser/Statements/GS_JnzStatement.h"

namespace GSVirtualMachine::Statements {

    GS_JnzStatement::GS_JnzStatement(std::string &address) {
        this->_addressForJump = address;
    }

    StatementType GS_JnzStatement::getStatementType() {
        return StatementType::JNZ_STATEMENT;
    }

    std::string GS_JnzStatement::toStringForDebug() {
        return "[ jnz "
        + this->_addressForJump
        + " ]";
    }

}