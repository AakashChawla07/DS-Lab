#include <iostream>
#define MAX 100

using namespace std;

struct Stack {
    char stack[MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

int isFull(Stack &s) {
    return (s.top == MAX - 1) ? 1 : 0;
}

int isEmpty(Stack &s) {
    return (s.top == -1) ? 1 : 0;
}

void push(Stack &s, char val) {
    if (isFull(s)) {
        cout << "Stack Overflow"<< endl;
    } else 
        s.stack[++s.top] = val;
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return '\0';
    } else
        return s.stack[s.top--];
}

char peek(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack is empty\n";
        return '\0';
    } else
        return s.stack[s.top];
}

void display(Stack &s) {
    if (isEmpty(s)) 
        cout << "Stack is empty.\n";
    else {
        cout << "Stack elements: ";
        for (int i = s.top; i >= 0; i--)
            cout << s.stack[i] << " ";
        cout << endl;
    }
}

int main() {
    Stack s;
    init(s);

    int choice;
    char val;

    do {
        cout << "Stack Operations Menu:\n1. Push\n2. Pop\n3. Peek (Top element)\n4. Check if Empty\n5. Check if Full\n6. Display stack\n7. Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> val;
                push(s, val);
                break;
            case 2:
                val = pop(s);
                if (val != '\0')
                    cout << "Popped element: " << val << "\n";
                break;
            case 3:
                val = peek(s);
                if (val != '\0')
                    cout << "Top element is: '" << val << "'\n";
                break;
            case 4:
                if (isEmpty(s))
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5:
                if (isFull(s))
                    cout << "Stack is full.\n";
                else
                    cout << "Stack is not full.\n";
                break;
            case 6:
                display(s);
                break;
            case 7:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
