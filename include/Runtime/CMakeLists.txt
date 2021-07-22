project(GSVMRuntimeLibrary)

set(RUNTIME_DIR ${SOURCE_DIR}/Runtime)

set(GS_VM_RUNTIME_SOURCE
        ${RUNTIME_DIR}/GS_Runtime.cpp)

add_library(
#       Library name
        ${PROJECT_NAME}
#       Library type
        STATIC
#       Runtime source
        ${GS_VM_RUNTIME_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR}/Runtime)
