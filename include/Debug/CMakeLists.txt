set(LIBRARY_NAME GSVMDebugLibrary)

set(GS_VM_DEBUG_SOURCE
        ../../src/Debug/GS_Debug.cpp)

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Debug source
        ${GS_VM_DEBUG_SOURCE}
)