#include "../../../include/VirtualMachine/Parser/GS_Parser.h"

namespace GSVirtualMachine {

    GSStatementPointer GS_Parser::_parsingPushKeyword() {
        _nextToken();

        GSValuePointer value = _expression()->result();

        return GSStatementPointer(new GS_PushStatement(value));
    }

    GSStatementPointer GS_Parser::_parsingPopKeyword() {
        _nextToken();

        return GSStatementPointer(new GS_PopStatement());
    }

    GSStatementPointer GS_Parser::_parsingAddKeyword() {
        _nextToken();

        return GSStatementPointer(new GS_AddStatement());
    }

    GSStatementPointer GS_Parser::_parsingSubKeyword() {
        _nextToken();

        return GSStatementPointer(new GS_SubStatement());
    }

    GSStatementPointer GS_Parser::_parsingLtKeyword() {
        _nextToken();

        return GSStatementPointer(new GS_LtStatement());
    }

    GSStatementPointer GS_Parser::_parsingGetKeyword() {
        _nextToken();

        std::string variableName = _currentToken().getValue();

        _nextToken();

        return GSStatementPointer(new GS_GetStatement(variableName));
    }

    GSStatementPointer GS_Parser::_parsingSaveKeyword() {
        _nextToken();

        std::string variableName = _currentToken().getValue();

        _nextToken();

        return GSStatementPointer(new GS_SaveStatement(variableName));
    }

    GSStatementPointer GS_Parser::_parsingReserveKeyword() {
        _nextToken();

        std::string variableName = _currentToken().getValue();

        _nextToken();

        return GSStatementPointer(new GS_ReserveStatement(variableName));
    }

    GSStatementPointer GS_Parser::_parsingJzKeyword() {
        _nextToken();

        std::string address = _currentToken().getValue();

        _nextToken();

        return GSStatementPointer(new GS_JzStatement(address));
    }

    GSStatementPointer GS_Parser::_parsingJnzKeyword() {
        _nextToken();

        std::string address = _currentToken().getValue();

        _nextToken();

        return GSStatementPointer(new GS_JnzStatement(address));
    }

    GSStatementPointer GS_Parser::_parsingJmpKeyword() {
        _nextToken();

        std::string address = _currentToken().getValue();

        _nextToken();

        return GSStatementPointer(new GS_JmpStatement(address));
    }

}