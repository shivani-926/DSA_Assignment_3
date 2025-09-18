#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isop(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixtopostfix(string infix) {
    stack<char> x;
    string post;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            post += c;
        } else if (c == '(') {
            x.push(c);
        } else if (c == ')') {
            while (!x.empty() && x.top() != '(') {
                post += x.top();
                x.pop();
            }
            if (!x.empty()) x.pop();
        } else if (isop(c)) {
            while (!x.empty() && prec(c) <= prec(x.top())) {
                if (c == '^' && x.top() == '^') break;
                post += x.top();
                x.pop();
            }
            x.push(c);
        }
    }

    while (!x.empty()) {
        post += x.top();
        x.pop();
    }

    return post;
}

int main() {
    string infix;
    cin >> infix;
    cout << infixtopostfix(infix) << endl;
    return 0;
}
