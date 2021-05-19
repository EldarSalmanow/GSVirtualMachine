#include "include/Starter/GS_Starter.h"

/**
 * Main function in GSVirtualMachine
 * @param argc Arguments count
 * @param argv Arguments array
 * @return Status number for operation system
 */
int main(int argc, char *argv[]) {
    return Starter::GS_Starter::start(argc, argv);
}

//template<typename T>
//void printStack(std::stack<T> inputStack) {
//    while (!inputStack.empty()) {
//        std::cout << inputStack.top() << std::endl;
//
//        inputStack.pop();
//    }
//}
//
//template<typename T, typename R>
//void printMap(std::map<T, R> inputMap) {
//    typename std::map<T, R>::iterator mapIterator;
//    mapIterator = inputMap.begin();
//
//    while (mapIterator != inputMap.end()) {
//        std::cout << "Name: " << mapIterator->first << " Value: " << mapIterator->second << std::endl;
//
//        ++mapIterator;
//    }
//}
//
//enum TokenType {
//    COMMAND,
//    VALUE,
//    END_OF_FILE
//};
//
//class Token {
//public:
//
//    Token(TokenType type, std::string value) {
//        this->_type = type;
//        this->_value = std::move(value);
//    }
//
//public:
//
//    TokenType getType() {
//        return this->_type;
//    }
//
//    std::string getValue() {
//        return this->_value;
//    }
//
//private:
//
//    TokenType _type;
//
//    std::string _value;
//};

//std::stack<int> stack;

//std::map<std::string, int> vars;

//std::vector<Token> tokens = {
//        Token(COMMAND, "RESERVE"),
//        Token(VALUE, "test"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "83927"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "3841"),
//        Token(COMMAND, "ADD"),
//        Token(COMMAND, "SAVE"),
//        Token(VALUE, "test"),
//
//        Token(COMMAND, "RESERVE"),
//        Token(VALUE, "hello"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "13983"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "23847"),
//        Token(COMMAND, "ADD"),
//        Token(COMMAND, "SAVE"),
//        Token(VALUE, "hello"),
//
//        Token(COMMAND, "RESERVE"),
//        Token(VALUE, "t"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "1084"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "2"),
//        Token(COMMAND, "SUB"),
//        Token(COMMAND, "SAVE"),
//        Token(VALUE, "t"),
//
//        Token(COMMAND, "RESERVE"),
//        Token(VALUE, "h"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "3719"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "2"),
//        Token(COMMAND, "ADD"),
//        Token(COMMAND, "PUSH"),
//        Token(VALUE, "2948"),
//        Token(COMMAND, "SUB"),
//        Token(COMMAND, "SAVE"),
//        Token(VALUE, "h"),
//
//        Token(END_OF_FILE, "")
//};

/*
 * var test = 10
 * test = 13
 *
 * RESERVE test
 * PUSH 10
 * SAVE test
 *
 * PUSH 10
 * SAVE test
 * POP
 * PUSH 13
 * SAVE test
 */

/*
 * var test = 10
 * if (12 < 13) {
 *     test = 14
 * } else {
 *     test = 15
 * }
 *
 *
 * PUSH 10
 * SAVE test
 * PUSH 12
 * PUSH 13
 * LT
 * JZF 2
 * PUSH 14
 * SAVE test
 * FORWARD 2
 * PUSH 15
 * SAVE test
 */

/* var test = 12 + 23
 *
 * RESERVE test
 * PUSH 12
 * PUSH 23
 * ADD
 * SAVE test
 */

//std::vector<Token>::iterator tokenIterator;

//int main(int argc, char *argv[]) {
//    tokenIterator = tokens.begin();
//
//    Token token = tokenIterator[0];
//
//    while (token.getType() != END_OF_FILE) {
//        TokenType type = token.getType();
//
//        if (type == COMMAND) {
//            std::string command = token.getValue();
//
//            if (command == "PUSH") {
//                ++tokenIterator;
//
//                int value = std::stoi(tokenIterator[0].getValue());
//
//                stack.push(value);
//            } else if (command == "POP") {
//                stack.pop();
//            } else if (command == "ADD") {
//                int secondValue = stack.top();
//
//                stack.pop();
//
//                int firstValue = stack.top();
//
//                stack.pop();
//
//                stack.push(firstValue + secondValue);
//            } else if (command == "SUB") {
//                int secondValue = stack.top();
//
//                stack.pop();
//
//                int firstValue = stack.top();
//
//                stack.pop();
//
//                stack.push(firstValue - secondValue);
//            } else if (command == "LT") {
//                int secondValue = stack.top();
//
//                stack.pop();
//
//                int firstValue = stack.top();
//
//                stack.pop();
//
//                stack.push(firstValue < secondValue ? 1 : 0);
//            } else if (command == "GET") {
//                ++tokenIterator;
//
//                std::string variableName = tokenIterator[0].getValue();
//
//                stack.push(vars.at(variableName));
//            } else if (command == "SAVE") {
//                ++tokenIterator;
//
//                std::string variableName = tokenIterator[0].getValue();
//
//                auto pair = vars.find(variableName);
//
//                pair->second = stack.top();
//
//                stack.pop();
//            } else if (command == "RESERVE") {
//                ++tokenIterator;
//
//                std::string variableName = tokenIterator[0].getValue();
//
//                vars.insert(std::make_pair(variableName, 0));
//            } else if (command == "JZB") {
//                if (stack.top() == 0) {
//                    ++tokenIterator;
//
//                    int address = std::stoi(tokenIterator[0].getValue());
//
//                    tokenIterator -= address;
//
//                    --tokenIterator;
//                }
//            } else if (command == "JNZB") {
//                if (stack.top() != 0) {
//                    ++tokenIterator;
//
//                    int address = std::stoi(tokenIterator[0].getValue());
//
//                    tokenIterator -= address;
//
//                    --tokenIterator;
//                }
//            } else if (command == "JZF") {
//                if (stack.top() == 0) {
//                    ++tokenIterator;
//
//                    int address = std::stoi(tokenIterator[0].getValue());
//
//                    tokenIterator += address;
//
//                    --tokenIterator;
//                }
//            } else if (command == "JNZF") {
//                if (stack.top() != 0) {
//                    ++tokenIterator;
//
//                    int address = std::stoi(tokenIterator[0].getValue());
//
//                    tokenIterator += address;
//
//                    --tokenIterator;
//                }
//            } else if (command == "BACK") {
//                ++tokenIterator;
//
//                int address = std::stoi(tokenIterator[0].getValue());
//
//                tokenIterator -= address;
//
//                --tokenIterator;
//            } else if (command == "FORWARD") {
//                ++tokenIterator;
//
//                int address = std::stoi(tokenIterator[0].getValue());
//
//                tokenIterator += address;
//
//                --tokenIterator;
//            }
//        }
//
//        ++tokenIterator;
//
//        token = tokenIterator[0];
//    }
//
//    std::cout << "\n----------STACK START----------\n" << std::endl;
//
//    printStack(stack);
//
//    std::cout << "\n----------STACK END----------\n" << std::endl;
//
//    std::cout << "\n----------VARS START----------\n" << std::endl;
//
//    printMap(vars);
//
//    std::cout << "\n----------VARS END----------\n" << std::endl;

//    return 0;
//}
