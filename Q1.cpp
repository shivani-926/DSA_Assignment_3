#include <iostream>
using namespace std;

class Stack {
    int s[100];
    int top;
    int m;

public:
    Stack(int size) {
        m = size;
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == m - 1);
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << x << endl;
        } else {
            top = top+1;
            s[top] = x;
            cout << x << " pushed to stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            top = top-1;
            cout << s[top] << " popped from stack." << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element: " << s[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int m;
    cout << "Enter size of stack: ";
    cin >> m;

    Stack st(m);
    int choice, value;

do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            st.push(value);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            cout << (st.isEmpty() ? "Stack is Empty" : "Stack is not Empty") << endl;
            break;
        case 5:
            cout << (st.isFull() ? "Stack is Full" : "Stack is not Full") << endl;
            break;
        case 6:
            st.display();
            break;
        case 7:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
