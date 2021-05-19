#ifndef GSVIRTUALMACHINE_GS_COORDINATE_H
#define GSVIRTUALMACHINE_GS_COORDINATE_H

#include <ctype.h>

#include "../Util/GS_PlatformTypes.h"

namespace GSVirtualMachine::Lexer {

    /**
     * Class for representation position in source code
     */
    class GS_Coordinate {
    public:

        /**
         * Default constructor for GS_Coordinate
         */
        GS_Coordinate() = default;

        /**
         * Constructor for GS_Coordinate
         * @param line Line position
         * @param column Column position
         */
        GS_Coordinate(size_t line, size_t column);

    public:

        /**
         * Getter line position in source code
         * @return Line number
         */
        size_t getLine();

        /**
         * Getter column position in source code
         * @return Column number
         */
        size_t getColumn();

    private:

        /**
         * Position in source code from file
         */
        size_t _line = 0, _column = 0;
    };

}

#endif //GSVIRTUALMACHINE_GS_COORDINATE_H
