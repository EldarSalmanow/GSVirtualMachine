#ifndef GSVIRTUALMACHINE_GS_TABLESOFSYMBOLS_H
#define GSVIRTUALMACHINE_GS_TABLESOFSYMBOLS_H

#include <map>

#include <CrossPlatform/GS_PlatformTypes.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_ConstantsTable {
    public:

        /**
         *
         */
        GS_ConstantsTable();

    public:

        /**
         *
         * @param constant
         * @param id
         * @return
         */
        GSVoid addConstant(GSString constant, GSInt id);

        /**
         *
         * @param id
         * @return
         */
        GSString getConstantById(GSInt id);

    private:

        /**
         *
         */
        std::map<GSInt, GSString> _idToString;
    };

    /**
     *
     */
    class GS_VariablesTable {
    public:

        /**
         *
         */
        GS_VariablesTable();

    public:

        /**
         *
         * @param id
         * @param name
         * @return
         */
        GSVoid addVariable(GSInt id, GSString name);

        /**
         *
         * @param id
         * @return
         */
        GSInt getValueById(GSInt id);

        /**
         *
         * @param id
         * @param value
         * @return
         */
        GSVoid setValueById(GSInt id, GSInt value);

    private:

        /**
         *
         */
        std::map<GSInt, GSString> _numberToName;

        /**
         *
         */
        std::map<GSInt, GSInt> _numberToValue;
    };

}

#endif //GSVIRTUALMACHINE_GS_TABLESOFSYMBOLS_H
