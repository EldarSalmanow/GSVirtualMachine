#include "../../../include/VirtualMachine/Parser/GS_Parser.h"

namespace GSVirtualMachine {

    GSStatementPointerArray GS_Parser::parse() {
        _tokenIterator = _tokens.begin();

        while (!_checkTokenType(TokenType::END_OF_FILE)) {
            GSStatementPointer statement;

            try {
                statement = this->_statement();
            } catch (Exceptions::GS_NewLineException) {
                _nextToken();

                continue;
            }

            _addStatement(statement);
        }

        return _statements;
    }

//--------------------------------------------------------------------------

    GSStatementPointer GS_Parser::_statement() {
        if (_checkTokenType(TokenType::KEYWORD_PUSH)) {
            return _parsingPushKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_POP)) {
            return _parsingPopKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_ADD)) {
            return _parsingAddKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_SUB)) {
            return _parsingSubKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_LT)) {
            return _parsingLtKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_GET)) {
            return _parsingGetKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_SAVE)) {
            return _parsingSaveKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_RESERVE)) {
            return _parsingReserveKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_JZ)) {
            return _parsingJzKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_JNZ)) {
            return _parsingJnzKeyword();
        }
        else if (_checkTokenType(TokenType::KEYWORD_JMP)) {
            return _parsingJmpKeyword();
        }
        else if (_checkTokenType(TokenType::NEW_LINE)) {
            throw Exceptions::GS_NewLineException();
        }
        else {
            throwException("Unknown statement!");
        }
    }

//--------------------------------------------------------------------------------

    void GS_Parser::throwException(std::string errorMessage) {
        throw Exceptions::GS_ParserException(std::move(errorMessage),
                                             _currentToken().getPosition().getCode(),
                                             _currentToken().getPosition().getEndPosition().getLine(),
                                             _currentToken().getPosition().getEndPosition().getColumn());
    }

    bool GS_Parser::_checkTokenType(TokenType typeForCheck, int numberOfToken) {
        return _tokenIterator[numberOfToken].getType() == typeForCheck;
    }

    inline void GS_Parser::_addStatement(GSStatementPointer &statement) {
        _statements.emplace_back(statement);
    }

    GS_Token GS_Parser::_currentToken() {
        return _tokenIterator[0];
    }

    void GS_Parser::_nextToken() {
        ++_tokenIterator;
    }

}