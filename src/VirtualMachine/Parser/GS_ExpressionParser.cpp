#include "../../../include/VirtualMachine/Parser/GS_Parser.h"

namespace GSVirtualMachine {

    GSExpressionPointer GS_Parser::_expression() {
        return _unary();
    }

    GSExpressionPointer GS_Parser::_unary() {
//        if (this->_checkTokenType(TokenType::SYMBOL_MINUS)) {
//            _nextToken();
//
//            return GSExpressionPointer(new Expressions::GS_UnaryExpression(
//                    Expressions::UnaryOperation::MINUS,
//                    _primary()));
//        } TODO add supporting unary minus

        return _primary();
    }

    GSExpressionPointer GS_Parser::_primary() {
        GSExpressionPointer expression = nullptr;

        if (_checkTokenType(TokenType::NEW_LINE)) {
            throw Exceptions::GS_NewLineException();
        }

        if (_checkTokenType(TokenType::LITERAL_NUMBER)) {
            expression = GSExpressionPointer(
                    new Expressions::GS_ValueExpression(
                            GSValuePointer(
                                    new Values::GS_IntegerValue(std::stoi(_currentToken().getValue()))),
                                    Literal::LITERAL_INT));

            _nextToken();
        }

        if (expression == nullptr) {
            throwException("Unknown expression!");
        }

        return expression;
    }

}