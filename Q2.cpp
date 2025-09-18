#include <iostream>
#include <string>
using namespace std;

class Stack {
    char s[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(char ch) {
        top = top+1;
        s[top] = ch;
    }

    char pop() {
        top = top-1;
        return s[top];
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();
    Stack x;

    for (int i = 0; i < n; i++) {
        x.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!x.isEmpty()) {
        cout << x.pop();
    }
    cout << endl;

    return 0;
}
