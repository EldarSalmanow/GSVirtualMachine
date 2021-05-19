set(LIBRARY_NAME GSVMUtilLibrary)

set(GS_VM_UTIL_SOURCE
        ../../../src/VirtualMachine/Util/GS_Arguments.cpp
        ../../../src/VirtualMachine/Util/GS_CrossPlatform.cpp
        )

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Util source
        ${GS_VM_UTIL_SOURCE}
)