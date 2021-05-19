#include "../../../include/VirtualMachine/Lexer/GS_Position.h"

namespace GSVirtualMachine::Lexer {

    GS_Position::GS_Position(std::string code, GS_Coordinate start, GS_Coordinate end) {
        this->_code = std::move(code);
        this->_startPosition = start;
        this->_endPosition = end;
    }

    GS_Coordinate GS_Position::getStartPosition() {
        return this->_startPosition;
    }

    GS_Coordinate GS_Position::getEndPosition() {
        return this->_endPosition;
    }

    std::string GS_Position::getCode() {
        return this->_code;
    }

}