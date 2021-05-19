set(LIBRARY_NAME GSVMStarterLibrary)

set(GS_VM_STARTER_SOURCE
        ../../src/Starter/GS_Starter.cpp
        )

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Starter source
        ${GS_VM_STARTER_SOURCE}
)