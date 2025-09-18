#include <iostream>
#include <string>
using namespace std;

class Stack {
    char s[100];
    int top;

public:
    Stack() { top = -1; }

    bool empty() { return top == -1; }

    void push(char ch) {
      top = top+1;
      s[top] = ch;
    }

    char pop() { 
      top = top-1;
      return s[top]; 
    }
};

bool isbalanced(string str) {
    Stack x;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            x.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (x.empty()) 
              return false;

            char open = x.pop();
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                return false;
            }
        }
    }
    return x.empty();
}

int main() {
    string e;
    cout << "Enter expression: ";
    cin >> e;

    if (isbalanced(e))
        cout << "Balanced expression\n";
    else
        cout << "Not balanced expression\n";

    return 0;
}
