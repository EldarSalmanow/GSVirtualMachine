#include <GS_TablesOfSymbols.h>

namespace GSVirtualMachine::Runtime {

    GS_ConstantsTable::GS_ConstantsTable() = default;

    GSVoid GS_ConstantsTable::addConstant(GSString constant, GSInt id) {
        _idToString[id] = std::move(constant);
    }

    GSString GS_ConstantsTable::getConstantById(GSInt id) {
        return _idToString[id];
    }

    GS_VariablesTable::GS_VariablesTable() = default;

    GSVoid GS_VariablesTable::addVariable(GSInt id, GSString name) {
        _numberToName[id] = std::move(name);

        _numberToValue[id];
    }

    GSInt GS_VariablesTable::getValueById(GSInt id) {
        return _numberToValue[id];
    }

    GSVoid GS_VariablesTable::setValueById(GSInt id, GSInt value) {
        _numberToValue[id] = value;
    }

    GS_LabelsTable::GS_LabelsTable() = default;

    GSVoid GS_LabelsTable::addLabel(GSString name, GSBytePtr address) {
        _nameToLabel[std::move(name)] = address;
    }

    GSBytePtr GS_LabelsTable::getLabelByName(GSString name) {
        return _nameToLabel[std::move(name)];
    }

}
