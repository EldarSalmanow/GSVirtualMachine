#include "../../../include/VirtualMachine/Runtime/GS_TableOfSymbols.h"

namespace GSVirtualMachine::Runtime {

    int GS_TableOfSymbols::get(std::string name) {
        int value;

        value = _tableOfSymbols.at(name);

        return value;
    }

    void GS_TableOfSymbols::change(std::string name, int value) {
        auto pair = _tableOfSymbols.find(name);

        pair->second = value;
    }

    void GS_TableOfSymbols::add(std::string name, int value) {
        _variableNames.emplace_back(name);
        _tableOfSymbols.emplace(std::make_pair(name, value));
    }

    std::vector<std::string> GS_TableOfSymbols::getVariableNames() {
        return _variableNames;
    }

}