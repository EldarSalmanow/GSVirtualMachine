cmake_minimum_required(VERSION 3.17)
project(GSVirtualMachine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_DIR   ${PROJECT_SOURCE_DIR})
set(SOURCE_DIR    ${PROJECT_DIR}/src)
set(INCLUDE_DIR   ${PROJECT_DIR}/include)
set(EXTERNAL_DIR  ${PROJECT_DIR}/external)
set(BINARY_DIR    ${PROJECT_DIR}/bin)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

set(PROJECT_LIBRARIES
        GSVMStarterLibrary
        GSVMCrossPlatformLibrary
        GSVMArgumentsParserLibrary
        GSVMReaderLibrary
        GSVMRuntimeLibrary
        GSVMDebugLibrary)

add_executable(${PROJECT_NAME}
        ${PROJECT_DIR}/main.cpp)

set(ASMJIT_STATIC TRUE)

include(${EXTERNAL_DIR}/asmjit/CMakeLists.txt)

include_directories(${ASMJIT_INCLUDE_DIRS})

include_directories(${INCLUDE_DIR})

add_subdirectory(${INCLUDE_DIR}/Starter)
add_subdirectory(${INCLUDE_DIR}/CrossPlatform)
add_subdirectory(${INCLUDE_DIR}/ArgumentsParser)
add_subdirectory(${INCLUDE_DIR}/Reader)
add_subdirectory(${INCLUDE_DIR}/Runtime)
add_subdirectory(${INCLUDE_DIR}/Debug)

target_link_libraries(GSVMRuntimeLibrary PRIVATE ${ASMJIT_LIBS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION ${BINARY_DIR})