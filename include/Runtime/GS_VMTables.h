#ifndef GSVIRTUALMACHINE_GS_VMTABLES_H
#define GSVIRTUALMACHINE_GS_VMTABLES_H

#include <map>

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_VMConstTable {
    public:

        /**
         *
         */
        GS_VMConstTable();

    public:

        /**
         *
         */
        std::map<GSInt, GSByte> indexToConstant;
    };

    /**
     *
     */
    class GS_VMVariableTable {
    public:

        /**
         *
         */
        GS_VMVariableTable();

    public:

        /**
         *
         */
        std::map<GSInt, GSString> indexToVariableName;

        /**
         *
         */
        std::map<GSString, GSByte> variableNameToValue;
    };

    /**
     *
     */
    class GS_VMFunctionTable {
    public:

        /**
         *
         */
        GS_VMFunctionTable();

    public:

        /**
         *
         */
        std::map<GSInt, GSString> indexToFunctionName;
    };

}

#endif //GSVIRTUALMACHINE_GS_VMTABLES_H
