set(LIBRARY_NAME GSVMRuntimeLibrary)

set(GS_VM_RUNTIME_SOURCE
        ../../../src/VirtualMachine/Runtime/GS_Runtime.cpp
        ../../../src/VirtualMachine/Runtime/GS_Stack.cpp
        ../../../src/VirtualMachine/Runtime/GS_TableOfSymbols.cpp
        )

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Runtime source
        ${GS_VM_RUNTIME_SOURCE}
)