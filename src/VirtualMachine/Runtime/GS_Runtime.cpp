#include "../../../include/VirtualMachine/Runtime/GS_Runtime.h"

namespace GSVirtualMachine::Runtime {

    void GS_Runtime::run(Statements::GSStatementPointerArray &statements) {
        _statements = statements;

        _statementIterator = _statements.begin();

        Statements::GSStatementPointer statement;

        while (!_isEndOfStatements()) {
            Statements::StatementType statementType = _currentStatement()->getStatementType();

            switch (statementType) {
                case Statements::StatementType::PUSH_STATEMENT:
                    _runPushStatement();
                    break;
                case Statements::StatementType::POP_STATEMENT:
                    _runPopStatement();
                    break;
                case Statements::StatementType::ADD_STATEMENT:
                    _runAddStatement();
                    break;
                case Statements::StatementType::SUB_STATEMENT:
                    _runSubStatement();
                    break;
                case Statements::StatementType::LT_STATEMENT:
                    _runLtStatement();
                    break;
                case Statements::StatementType::GET_STATEMENT:
                    _runGetStatement();
                    break;
                case Statements::StatementType::SAVE_STATEMENT:
                    _runSaveStatement();
                    break;
                case Statements::StatementType::RESERVE_STATEMENT:
                    _runReserveStatement();
                    break;
                case Statements::StatementType::JZ_STATEMENT:
                    _runJzStatement();
                    break;
                case Statements::StatementType::JNZ_STATEMENT:
                    _runJnzStatement();
                    break;
                case Statements::StatementType::JMP_STATEMENT:
                    _runJmpStatement();
                    break;
            }

            ++_statementIterator;
        }
    }

    void GS_Runtime::_nextStatement() {
        ++_statementIterator;
    }

    Statements::GSStatementPointer GS_Runtime::_currentStatement() {
        return _statementIterator[0];
    }

    bool GS_Runtime::_isEndOfStatements() {
        return _statementIterator == _statements.end();
    }

    void GS_Runtime::_runPushStatement() {
        GS_Stack::push(((Statements::GS_PushStatement*) _currentStatement().get())->getValue()->getInt());
    }

    void GS_Runtime::_runPopStatement() {
        GS_Stack::pop();
    }

    void GS_Runtime::_runAddStatement() {
        int secondValue = GS_Stack::top();

        GS_Stack::pop();

        int firstValue = GS_Stack::top();

        GS_Stack::pop();

        GS_Stack::push(firstValue + secondValue);
    }

    void GS_Runtime::_runSubStatement() {
        int secondValue = GS_Stack::top();

        GS_Stack::pop();

        int firstValue = GS_Stack::top();

        GS_Stack::pop();

        GS_Stack::push(firstValue - secondValue);
    }

    void GS_Runtime::_runLtStatement() {
        int secondValue = GS_Stack::top();

        GS_Stack::pop();

        int firstValue = GS_Stack::top();

        GS_Stack::pop();

        GS_Stack::push(firstValue < secondValue ? 1 : 0);
    }

    void GS_Runtime::_runGetStatement() {
        GS_Stack::push(GS_TableOfSymbols::get(((Statements::GS_GetStatement*) _currentStatement().get())->getVariableName()));
    }

    void GS_Runtime::_runSaveStatement() {
        GS_TableOfSymbols::change(((Statements::GS_SaveStatement*) _currentStatement().get())->getVariableName(), GS_Stack::top());
    }

    void GS_Runtime::_runReserveStatement() {
        GS_TableOfSymbols::add(((Statements::GS_ReserveStatement*) _currentStatement().get())->getVariableName(), 0);
    }

    void GS_Runtime::_runJzStatement() {
        return;
    }

    void GS_Runtime::_runJnzStatement() {
        return;
    }

    void GS_Runtime::_runJmpStatement() {
        return;
    }

}