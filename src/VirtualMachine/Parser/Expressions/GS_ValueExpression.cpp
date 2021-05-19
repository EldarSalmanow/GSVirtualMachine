#include "../../../../include/VirtualMachine/Parser/Expressions/GS_VaLueExpression.h"

namespace GSVirtualMachine::Expressions {

    GS_ValueExpression::GS_ValueExpression(GSValuePointer value) {
        this->_value = value;
        this->_type = value->getLiteralType();
    }

    GS_ValueExpression::GS_ValueExpression(GSValuePointer value, Literal type) {
        if (value->getLiteralType() != type) {
            this->_value = value->castTo(type);
            this->_type = type;
        } else {
            this->_value = value;
            this->_type = type;
        }
    }

    GSValuePointer GS_ValueExpression::getValue() {
        return this->_value;
    }

    Literal GS_ValueExpression::getType() {
        return this->_type;
    }

    GSValuePointer GS_ValueExpression::result() {
        return this->_value;
    }

    void GS_ValueExpression::run() {

    }

    std::string GS_ValueExpression::toStringForDebug() {
        return this->_value->getString();
    }

}
