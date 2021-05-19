cmake_minimum_required(VERSION 3.17)
project(GSVirtualMachine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(include/Starter)
add_subdirectory(include/VirtualMachine/Reader)
add_subdirectory(include/VirtualMachine/Lexer)
add_subdirectory(include/VirtualMachine/Parser)
add_subdirectory(include/VirtualMachine/Runtime)
add_subdirectory(include/VirtualMachine/Util)
add_subdirectory(include/Debug)

add_executable(${PROJECT_NAME}
        main.cpp
        )

target_link_libraries(${PROJECT_NAME}
        GSVMStarterLibrary
        GSVMReaderLibrary
        GSVMLexerLibrary
        GSVMParserLibrary
        GSVMRuntimeLibrary
        GSVMUtilLibrary
        GSVMDebugLibrary
        )