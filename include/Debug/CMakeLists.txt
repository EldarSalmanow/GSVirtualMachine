project(GSVMDebugLibrary)

set(DEBUG_DIR ${SOURCE_DIR}/Debug)

set(GS_VM_DEBUG_SOURCE
        ${DEBUG_DIR}/GS_Timer.cpp)

add_library(
#       Library name
        ${PROJECT_NAME}
#       Library type
        STATIC
#       Debug source
        ${GS_VM_DEBUG_SOURCE}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR}/Debug)