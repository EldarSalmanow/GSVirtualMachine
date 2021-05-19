set(LIBRARY_NAME GSVMLexerLibrary)

set(GS_VM_LEXER_SOURCE
        ../../../src/VirtualMachine/Lexer/GS_Lexer.cpp
        ../../../src/VirtualMachine/Lexer/GS_Keywords.cpp
        ../../../src/VirtualMachine/Lexer/GS_Regex.cpp
        ../../../src/VirtualMachine/Lexer/GS_Token.cpp
        ../../../src/VirtualMachine/Lexer/GS_Position.cpp
        ../../../src/VirtualMachine/Lexer/GS_Coordinate.cpp)

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Lexer source
        ${GS_VM_LEXER_SOURCE}
)