#include <iostream>
using namespace std;

class Stack
{
    char arr[50];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char x)
    {
        arr[++top] = x;
    }

    char pop()
    {
        return arr[top--];
    }

    char peek()
    {
        return arr[top];
    }

    int empty()
    {
        return top == -1;
    }
};

int priority(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    return 1;
}

int main()
{
    string infix, postfix = "";

    cout << "Enter infix expression: ";
    cin >> infix;

    Stack exp;

    for (char x : infix)
    {
        if (x >= 'a' && x <= 'z')
            postfix += x;

        else if (x == '(')
            exp.push(x);

        else if (x == ')')
        {
            while (exp.peek() != '(')
                postfix += exp.pop();

            exp.pop();
        }

        else
        {
            while (!exp.empty() &&
                   priority(exp.peek()) >= priority(x))
                postfix += exp.pop();

            exp.push(x);
        }
    }

    while (!exp.empty())
        postfix += exp.pop();

    cout << "Postfix = " << postfix;

    return 0;
}
