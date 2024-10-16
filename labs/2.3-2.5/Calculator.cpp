#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

string infixToPostfix(const string& expression) {
    stack<char> operators;
    string postfix;
    int i = 0;

    while (i < expression.length()) {
        char c = expression[i];

        if (isspace(c)) {
            i++;
            continue;
        }

        if (isdigit(c)) {
            while (i < expression.length() && isdigit(expression[i])) {
                postfix += expression[i];
                i++;
            }
            postfix += ' ';
        }
        else if (c == '(') {
            operators.push(c);
            i++;
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.pop();
            i++;
        }
        else if (precedence(c) > 0) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(c);
            i++;
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }

    return postfix;
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/':
        if (operand2 == 0) {
            throw runtime_error("Error: Division by zero");
        }
        return operand1 / operand2;
    default: throw runtime_error("Error: Unknown operation");
    }
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;
    int i = 0;

    while (i < expression.length()) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            operands.push(num);
        }
        else if (precedence(expression[i]) > 0) {
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            int result = performOperation(expression[i], operand1, operand2);
            operands.push(result);
            i++;
        }
    }

    return operands.top();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    try {
        string postfix = infixToPostfix(expression);
        cout << "Postfix expression: " << postfix << endl;

        int result = evaluatePostfix(postfix);
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
