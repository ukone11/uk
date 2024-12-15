#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> ops;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        if (isalnum(infix[i])) {
            postfix += infix[i];  
        }
        else if (infix[i] == '(') {
            ops.push(infix[i]);  
        }
        else if (infix[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                ops.pop();
            }
            ops.pop();  // Pop '('
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(infix[i])) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(infix[i]);  
        }
    }

    
    while (!ops.empty()) {
        postfix += ops.top();
        ops.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> operands;

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            operands.push(postfix[i] - '0');  
        }
        else {
            int val2 = operands.top(); operands.pop();
            int val1 = operands.top(); operands.pop();

            operands.push(applyOp(val1, val2, postfix[i]));
        }
    }

    return operands.top();  
};

int main() {
    string infix, postfix;

    cout << "Enter infix expression (single character operands and operators only): ";
    cin >> infix;

    postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}
