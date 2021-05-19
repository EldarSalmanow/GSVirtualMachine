set(LIBRARY_NAME GSVMReaderLibrary)

set(GS_VM_READER_SOURCE
        ../../../src/VirtualMachine/Reader/GS_Reader.cpp
        )

add_library(
#       Library name
        ${LIBRARY_NAME}
#       Library type
        STATIC
#       Reader source
        ${GS_VM_READER_SOURCE}
)