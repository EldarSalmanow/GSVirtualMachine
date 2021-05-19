#include "../../../../include/VirtualMachine/Parser/Statements/GS_JmpStatement.h"

namespace GSVirtualMachine::Statements {

    GS_JmpStatement::GS_JmpStatement(std::string &address) {
        this->_addressForJump = address;
    }

    StatementType GS_JmpStatement::getStatementType() {
        return StatementType::JMP_STATEMENT;
    }

    std::string GS_JmpStatement::toStringForDebug() {
        return "[ jmp "
        + this->_addressForJump
        + " ]";
    }

}