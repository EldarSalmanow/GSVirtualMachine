#ifndef GSVIRTUALMACHINE_GS_TABLEOFSYMBOLS_H
#define GSVIRTUALMACHINE_GS_TABLEOFSYMBOLS_H

#include <map>

#include "../Parser/Values/GS_Value.h"

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    class GS_TableOfSymbols {
    public:

        /**
         *
         * @param name
         * @return
         */
        static int get(std::string name);

        /**
         *
         * @param name
         * @param value
         */
        static void add(std::string name, int value);

        /**
         *
         * @param name
         * @param value
         */
        static void change(std::string name, int value);

    public:

        /**
         *
         * @return
         */
        static std::vector<std::string> getVariableNames();

    private:

        /**
         *
         */
        inline static std::vector<std::string> _variableNames;

        /**
         *
         */
        inline static std::map<std::string, int> _tableOfSymbols;
    };

}

#endif //GSVIRTUALMACHINE_GS_TABLEOFSYMBOLS_H
