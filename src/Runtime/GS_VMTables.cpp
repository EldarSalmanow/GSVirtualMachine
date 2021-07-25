#include <GS_VMTables.h>

namespace GSVirtualMachine::Runtime {

    GS_Constant::GS_Constant() = default;

    GS_Constant::GS_Constant(GSInt value)
            : _value(value), _type(ConstantType::NUMBER) {}

    GS_Constant::GS_Constant(GSString value)
            : _value(std::move(value)), _type(ConstantType::STRING) {}

    GS_VMConstTable::GS_VMConstTable() = default;

    GS_Variable::GS_Variable() = default;

    GS_Variable::GS_Variable(VariableType type)
            : _type(type) {}

    GS_VMVariableTable::GS_VMVariableTable() = default;

    GS_VMFunctionTable::GS_VMFunctionTable() = default;

}