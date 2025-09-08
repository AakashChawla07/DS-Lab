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
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int isBalanced(char expr[]) {
    Stack s;
    init(s);

    int i = 0;
    while (expr[i] != '\0') {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(s)) {
                return 0;
            } else {
                char topChar = pop(s);
                if (!isMatchingPair(topChar, ch)) {
                    return 0;
                }
            }
        }
        i++;
    }
    return isEmpty(s);
}

int main() {
    char expr[MAX];

    cout << "Enter expression to check for balanced parentheses: ";
    cin.getline(expr, MAX);

    if (isBalanced(expr))
        cout << "Expression is balanced.\n";
    else
        cout << "Expression is NOT balanced.\n";

    return 0;

}
