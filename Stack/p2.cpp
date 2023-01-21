#include <iostream>

using namespace std;

struct stack
{
    int top;
    char opr[50];
} s;

void init()
{
    s.top = -1;
}

void push(char a)
{
    s.top++;
    s.opr[s.top] = a;
}

char pop()
{
    return s.opr[s.top--];
}

int isEmpty()
{
    return (s.top == -1);
}

int preced(char a, char b)
{
    if (a != '(' && b == ')')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char istr[50], pstr[50], ch;
    int i = 0, j = 0, count = 0;
    init();

    cout << "Enter Infix Expression: ";
    cin >> istr;
}