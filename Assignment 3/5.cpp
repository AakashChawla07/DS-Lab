#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack {
    int stack[MAX];
    int top;

    Stack() { top = -1; }

    void push(int val) {
        if (top < MAX - 1) {
            stack[++top] = val;
        }
    }

    int pop() {
        if (top >= 0) {
            return stack[top--];
        }
        return 0;
    }
};

bool isCharDigit(char c) {
    return c >= '0' && c <= '9';
}

int charToInt(char c) {
    return c - '0';
}

int evaluatePostfix(const string& postfix) {
    Stack s;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isCharDigit(c)) {
            int num = charToInt(c);
            s.push(num);
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;

            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    cout << "Invalid operator: " << c << endl;
                    return 0;
            }

            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
