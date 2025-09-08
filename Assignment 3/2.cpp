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
        cout << "Stack Overflow\n";
    } else {
        s.top++;
        s.stack[s.top] = val;
    }
}

char pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return '\0';
    } else 
        return s.stack[s.top--];
}


int main() {
    Stack s;
    init(s);
    char str[MAX];

    cout << "Enter a string to reverse: ";
    cin.getline(str, MAX);

    int i = 0;
    while (str[i] != '\0') {
        push(s, str[i]);
        i++;
    }

    cout << "Reversed string: ";
    while (!isEmpty(s)) 
        cout << pop(s);
    cout << endl;

    return 0;
}
