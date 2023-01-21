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

    while (istr[i] != '\0')
    {
        ch = istr[i];

        if (ch >= 65 && ch <= 90)
        {
            pstr[j++] = ch;
            count++;

            if (count == 2)
            {
                pstr[j++] = pop();
                count = 0;
            }
        }
        else
        {
            while (!isEmpty() && preced(s.opr[s.top], ch))
            {
                pstr[j++] = pop();
            }

            if (isEmpty() || ch != ')')
            {
                push(ch);
            }
            else
            {
                ch = pop();
            }
        }
        i++;
    }

    while (!isEmpty())
    {
        pstr[j++] = pop();
    }

    pstr[j] = '\0';

    cout << pstr;

    return 0;
}