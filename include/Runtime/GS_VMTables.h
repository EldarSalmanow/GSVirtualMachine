#ifndef GSVIRTUALMACHINE_GS_VMTABLES_H
#define GSVIRTUALMACHINE_GS_VMTABLES_H

#include <map>
#include <any>

#include <CrossPlatform/GS_PlatformTypes.h>
#include <CrossPlatform/GS_ClassUtilities.h>

namespace GSVirtualMachine::Runtime {

    /**
     *
     */
    enum class ConstantType {
        NUMBER,
        STRING
    };

    class GS_Constant {
    public:

        /**
         *
         */
        GS_Constant();

        /**
         *
         * @param value
         */
        explicit GS_Constant(GSInt value);

        /**
         *
         * @param value
         */
        explicit GS_Constant(GSString value);

    public:

        /**
         *
         * @tparam T
         * @return
         */
        template<typename T>
        T getData() {
            return std::any_cast<T>(_value);
        }

        /**
         *
         * @return
         */
        GETTER(ConstantType, type, Type)

    private:

        /**
         *
         */
        std::any _value;

        /**
         *
         */
        ConstantType _type;
    };

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
        std::map<GSInt, GS_Constant> indexToConstant;
    };

    /**
     *
     */
    enum class VariableType {
        NUMBER,
        STRING
    };

    /**
     *
     */
    class GS_Variable {
    public:

        /**
         *
         */
        GS_Variable();

        /**
         *
         * @param type
         */
        explicit GS_Variable(VariableType type);

    public:

        /**
         *
         * @tparam T
         * @return
         */
        template<typename T>
        T getValue() {
            return std::any_cast<T>(_value);
        }

        /**
         *
         * @tparam T
         * @param value
         * @return
         */
        template<typename T>
        GSVoid setValue(T value) {
            _value.reset();

            _value = value;
        }

        /**
         *
         * @return
         */
        GETTER(VariableType, type, Type)

    private:

        /**
         *
         */
        std::any _value;

        /**
         *
         */
        VariableType _type;
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
        std::map<GSInt, GS_Variable> indexToVariable;

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
