#ifndef GSVIRTUALMACHINE_GS_LEXER_H
#define GSVIRTUALMACHINE_GS_LEXER_H

#include <vector>

#include "GS_Token.h"
#include "GS_Regex.h"

#include "../../Exceptions/GS_LexerException.h"

namespace GSVirtualMachine::Lexer {

    typedef std::vector<std::string> GSText;

    /**
     * Class for analyzing source code
     */
    class GS_Lexer {
    public:

        /**
         * Constructor for GS_Lexer
         * @param input Lines of code from input file
         */
        GS_Lexer(std::vector<std::string> &input);

    public:

        /**
         * Function for tokenize input code
         * @return Tokens for parser analyze
         */
        std::vector<GS_Token> tokenize();

    private:

        /**
         * Analysis of each line in turn
         */
        void _analyzeLine();

        /**
         * Tokenizing number
         */
        void _tokenizeNumber();

        /**
         * Tokenizing word
         */
        void _tokenizeWord();

        /**
         * Tokenizing string
         */
//        void _tokenizeString();

        /**
         * Analyzing reserved word or symbol
         * @param word Input word for analyzing
         * @return Type of reserved word or symbol
         */
        inline TokenType _analyzeReservedWord(std::string &word);

        /**
         * Search for a string in reserved words and symbols
         * @param word Input string to analyze
         * @return Is reserved word or symbol
         */
        inline bool _isReservedWord(std::string &word);

        /**
         * Function to check if a character is supported by the compiler
         * @param character Symbol to check
         * @param type Regular expression type
         * @return Is supported character
         */
        bool _isValidRegexForSymbol(RegexType type);

        /**
         * Setting start position of token value
         */
        inline void _setStartPositionOfToken();

        /**
         * Adding token
         * @param type Token type
         */
        inline void _addToken(TokenType type);

        /**
         * Adding token with value
         * @param type Token type
         * @param value Token value
         */
        inline void _addToken(TokenType type, std::string value);

        /**
         * Updating line iterator to next symbol in line
         */
        inline void _nextSymbol();

        /**
         * Updating code iterator to next line in source
         */
        inline void _nextLine();

        /**
         * Getting current symbol in line iterator
         * @return Current symbol in line iterator
         */
        inline char _currentSymbol();

        /**
         * Is end of line in line iterator
         * @return Is end of line
         */
        inline bool _isEndOfLine();

        /**
         * Is end of source in code iterator
         * @return Is end of source
         */
        inline bool _isEndOfSource();

    private:

        /**
         * Input code from reader
         */
        GSText _input;

        /**
         * Tokens before lexer analyzing
         */
        GSTokenArray _tokens;

        /**
         * Current position in lexer analyzing
         */
        size_t _line, _column;

        /**
         * Start token value position
         */
        size_t _startLine, _startColumn;

        /**
         * An iterator to read code from a file
         */
        GSText::iterator _codeIterator;

        /**
         * Iterator for reading a line of code
         */
        std::string::iterator _lineIterator;

        /**
         * Current symbol
         */
        std::string _symbol;
    };

    typedef std::shared_ptr<GS_Lexer> GSLexerPointer;

}

#endif //GSVIRTUALMACHINE_GS_LEXER_H