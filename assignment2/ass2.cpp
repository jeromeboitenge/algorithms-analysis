#include
#include
#include

std::string readInfix() {
    std::string infixExpression;
    std::cout << "Enter the infix expression: ";
    std::cin >> infixExpression;
    return infixExpression;
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '' || op == '/')
        return 2;
    return 0;
}

std::string convertToPostfix(std::string infix) {
    std::string postfix = "";
    std::stack operators;

    for (char& c : infix) {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int evaluate(std::string postfix) {
    std::stack operands;

    for (char& c : postfix) {
        if (isalnum(c))
            operands.push(c - '0');
        else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.top();
}

int main() {
    std::string infix = readInfix();
    std::string postfix = convertToPostfix(infix);
    
    std::cout << "Postfix expression: " << postfix << std::endl;

    int result = evaluate(postfix);

    std::cout << "Result: " << result << std::endl;

    return 0;
}