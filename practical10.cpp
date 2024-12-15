#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isWellParenthesized(const string &expression) {
    stack<char> s;  
    unordered_map<char, char> matchingParen = {
        {')', '('}, 
        {']', '['}, 
        {'}', '{'}
    };

    for (char ch : expression) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || s.top() != matchingParen[ch]) {
                return false;  
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string expression;
    
    cout << "Enter an expression: ";
    cin >> expression;

    if (isWellParenthesized(expression)) {
        cout << "The expression is well parenthesized." << endl;
    } else {
        cout << "The expression is not well parenthesized." << endl;
    }

    return 0;
}
