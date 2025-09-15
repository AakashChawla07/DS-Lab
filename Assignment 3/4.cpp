#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack
{
    char arr[MAX];
    int top;

    Stack() { 
        top = -1; 
    }

    bool isEmpty() { 
        return top == -1; 
    }
    bool isFull() { 
        return top == MAX - 1; 
    }

    void push(char c)
    {
        if (!isFull())
        {
            arr[++top] = c;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            return arr[top--];
        }
        return '\0';
    }

    char peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        return '\0';
    }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/'|| op=='%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main()
{
    string infix, postfix;
    Stack s;

    cout << "Enter an infix expression: ";
    cin.ignore();
    getline(cin,infix);
    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
