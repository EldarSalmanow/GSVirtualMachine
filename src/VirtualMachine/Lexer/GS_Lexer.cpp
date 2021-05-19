#include "../../../include/VirtualMachine/Lexer/GS_Lexer.h"

namespace GSVirtualMachine::Lexer {

    GS_Lexer::GS_Lexer(std::vector<std::string> &input) {
        this->_input = input;
    }

    std::vector<GS_Token> GS_Lexer::tokenize() {
        // setting the iterator to the beginning of the text
        _codeIterator = _input.begin();
        _line = 1;
        _column = 1;

        // text tokenization process
        while (!_isEndOfSource()) {
            // set line iterator to start current line in code iterator
            _lineIterator = _codeIterator[0].begin();

            _analyzeLine();

            _nextLine();
        }

        // putting a file end token
        _tokens.emplace_back(GS_Token(TokenType::END_OF_FILE, GS_Position(
                "",
                GS_Coordinate(_startLine, _startColumn),
                GS_Coordinate(_line, _column)
        )));

        return _tokens;
    }

    void GS_Lexer::_analyzeLine() {
        while (!_isEndOfLine()) {
            _symbol = _currentSymbol();

            // is whitespace
            if (_symbol == " ") {
                _nextSymbol();

                continue;
            }

                // is number (0..9)
            else if (_isValidRegexForSymbol(RegexType::NUMBER_SIMPLE)) {
                _tokenizeNumber();

                continue;
            }

                // is english alphabet (a-zA-Z)
            else if (_isValidRegexForSymbol(RegexType::ALPHABET_ENGLISH)) {
                _tokenizeWord();

                continue;
            }

//                // is string
//            else if (_symbol == "\"") {
//                _tokenizeString();
//
//                continue;
//            }

                // is special symbol
            else if (_isReservedWord(_symbol)) {
                _addToken(_analyzeReservedWord(_symbol));

                _nextSymbol();

                continue;
            }

            throw Exceptions::GS_LexerException("Unknown symbol \'" + _symbol + "\'!" + "\nCode: " + _codeIterator[0],
                                                _line, _column);
        }

        _addToken(TokenType::NEW_LINE);
    }

//---------------------------------------------------------

    void GS_Lexer::_tokenizeNumber() {
        std::string number;

        _setStartPositionOfToken();

        while (_isValidRegexForSymbol(RegexType::NUMBER_SIMPLE)) {
            number += _symbol;

            _nextSymbol();

            _symbol = _currentSymbol();
        }

        _setStartPositionOfToken();

        _addToken(TokenType::LITERAL_NUMBER, number);
    }

    void GS_Lexer::_tokenizeWord() {
        std::string word;

        _setStartPositionOfToken();

        while (_isValidRegexForSymbol(RegexType::ALPHABET_ENGLISH)) {
            word += _symbol;

            _nextSymbol();

            _symbol = _currentSymbol();
        }

        _setStartPositionOfToken();

        if (_isReservedWord(word)) {
            _addToken(_analyzeReservedWord(word));

            return;
        }

        _addToken(TokenType::WORD, word);
    }

//-----------------------------------------------------------------

    inline bool GS_Lexer::_isReservedWord(std::string &word) {
        return reserved.find(word) != reserved.end();
    }

    inline TokenType GS_Lexer::_analyzeReservedWord(std::string &word) {
        return reserved.at(word);
    }

    bool GS_Lexer::_isValidRegexForSymbol(RegexType type) {
        std::smatch match;
        std::vector<std::regex> regexps;

        switch (type) {
            case RegexType::NUMBER_SIMPLE:
                regexps = {
                        _numberExpression
                };

                break;
            case RegexType::ALPHABET_ENGLISH:
                regexps = {
                        _wordEnglishExpression
                };

                break;
            case RegexType::UNSUPPORTED:
                return false;
        }

        for (auto &regex : regexps) {
            if (std::regex_match(_symbol, match, regex)) {
                return true;
            }
        }

        return false;
    }

    inline void GS_Lexer::_setStartPositionOfToken() {
        _startLine = _line;
        _startColumn = _column;
    }

    inline void GS_Lexer::_addToken(TokenType type) {
        _tokens.emplace_back(GS_Token(type, GS_Position(
                _codeIterator[0],
                GS_Coordinate(_startLine, _startColumn),
                GS_Coordinate(_line, _column)
        )));
    }

    inline void GS_Lexer::_addToken(TokenType type, std::string value) {
        _tokens.emplace_back(GS_Token(type, value, GS_Position(
                _codeIterator[0],
                GS_Coordinate(_startLine, _startColumn),
                GS_Coordinate(_line, _column)
        )));
    }

    inline void GS_Lexer::_nextSymbol() {
        ++_lineIterator;

        ++_column;
    }

    inline void GS_Lexer::_nextLine() {
        ++_codeIterator;

        ++_line;

        _column = 1;
    }

    inline char GS_Lexer::_currentSymbol() {
        return _lineIterator[0];
    }

    inline bool GS_Lexer::_isEndOfLine() {
        return _lineIterator == _codeIterator[0].end();
    }

    inline bool GS_Lexer::_isEndOfSource() {
        return _codeIterator == _input.end();
    }

}