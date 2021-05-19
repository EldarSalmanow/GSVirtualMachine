set(LIBRARY_NAME GSVMParserLibrary)

set(GS_VM_PARSER_SOURCE
        ../../../src/VirtualMachine/Parser/GS_Parser.cpp
        ../../../src/VirtualMachine/Parser/GS_ExpressionParser.cpp
        ../../../src/VirtualMachine/Parser/GS_CommandParser.cpp
        ../../../src/VirtualMachine/Parser/Values/GS_LiteralTypes.cpp
        ../../../src/VirtualMachine/Parser/Values/GS_IntegerValue.cpp
        ../../../src/VirtualMachine/Parser/Expressions/GS_ValueExpression.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_PushStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_PopStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_AddStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_SubStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_GetStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_JnzStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_JzStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_JmpStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_LtStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_ReserveStatement.cpp
        ../../../src/VirtualMachine/Parser/Statements/GS_SaveStatement.cpp)

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Parser source
        ${GS_VM_PARSER_SOURCE}
)