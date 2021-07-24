project(GSVMRuntimeLibrary)

set(RUNTIME_DIR ${SOURCE_DIR}/Runtime)

set(GS_VM_RUNTIME_SOURCE
        ${RUNTIME_DIR}/GS_Runtime.cpp
        ${RUNTIME_DIR}/GS_Opcode.cpp ../../src/Runtime/GS_VMImageDecoder.cpp ../../src/Runtime/GS_VMTables.cpp)

add_library(
#       Library name
        ${PROJECT_NAME}
#       Library type
        STATIC
#       Runtime source
        ${GS_VM_RUNTIME_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR}/Runtime)
