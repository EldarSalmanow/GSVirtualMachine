#include "../../../../include/VirtualMachine/Parser/Statements/GS_SubStatement.h"

namespace GSVirtualMachine::Statements {

    GS_SubStatement::GS_SubStatement() = default;

    StatementType GS_SubStatement::getStatementType() {
        return StatementType::SUB_STATEMENT;
    }

    std::string GS_SubStatement::toStringForDebug() {
        return "[ sub ]";
    }

}