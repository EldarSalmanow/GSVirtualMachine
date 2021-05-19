#ifndef GSVIRTUALMACHINE_GS_TOKEN_H
#define GSVIRTUALMACHINE_GS_TOKEN_H

#include <vector>
#include <memory>

#include "GS_Keywords.h"
#include "GS_Position.h"

namespace GSVirtualMachine::Lexer {

    /**
     * Class for issuing information about the token
     */
    class GS_Token {
    public:

        /**
         * Default constructor for GS_Token
         */
        GS_Token() = default;

        /**
         *
         * @param type
         * @param position
         */
        GS_Token(TokenType type, GS_Position position);

        /**
         *
         * @param type
         * @param word
         * @param position
         */
        GS_Token(TokenType type, std::string &word, GS_Position position);

    public:

        /**
         * Getter for type
         * @return Token type
         */
        TokenType getType();

        /**
         * Getter for value
         * @return Token value
         */
        std::string getValue();

        /**
         * Getter for position in source file
         * @return Position in source file
         */
        GS_Position getPosition();

    private:

        /**
         * Type of token
         */
        TokenType _type;

        /**
         * String value or name
         */
        std::string _value;

        /**
         * Start and end token position
         */
        GS_Position _position;
    };

    typedef std::shared_ptr<GS_Token> GSTokenPointer;

    typedef std::vector<GS_Token> GSTokenArray;

}

#endif //GSVIRTUALMACHINE_GS_TOKEN_H
