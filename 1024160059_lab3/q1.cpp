#include <iostream>
using namespace std;

int stackArr[100], top = -1, n;

void push(int x) {
    if (top == n - 1) {
        cout << "Stack Full\n";
        return;
    }
    stackArr[++top] = x;
}

int pop() {
    if (top == -1) {
        cout << "Stack Empty\n";
        return -1;
    }
    return stackArr[top--];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == n - 1;
}

int peek() {
    if (top == -1) {
        cout << "Stack Empty\n";
        return -1;
    }
    return stackArr[top];
}

void display() {
    if (top == -1) {
        cout << "Stack Empty\n";
        return;
    }
    for (int i = top; i >= 0; i--) cout << stackArr[i] << " ";
    cout << "\n";
}

int main() {
    int choice, x;
    cout << "Enter size of stack: ";
    cin >> n;

    while (1) {
        cout << "1 Push\n2 Pop\n3 isEmpty\n4 isFull\n5 Display\n6 Peek\n7 Exit\n";
        cin >> choice;

        if (choice == 1) {
            cin >> x;
            push(x);
        } else if (choice == 2) {
            cout << pop() << "\n";
        } else if (choice == 3) {
            cout << isEmpty() << "\n";
        } else if (choice == 4) {
            cout << isFull() << "\n";
        } else if (choice == 5) {
            display();
        } else if (choice == 6) {
            cout << peek() << "\n";
        } else break;
    }
}
