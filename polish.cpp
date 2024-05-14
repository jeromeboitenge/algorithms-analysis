#include "Polish.h"

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

std::string readInfix() {
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infix);
    std::cout << "Read: " << infix << std::endl;
    return infix;
}

std::string convertToPostfix(std::string infix) {
    std::stack<char> s;
    std::string postfix;
    
    for (char& c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            while (!s.empty() && s.top() != '(' && s.top() != '[' && s.top() != '{') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Discard the opening parenthesis
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

int evaluate(std::string postfix) {
    std::stack<int> s;
    
    for (char& c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            
            switch(c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    
    return s.top();
}
