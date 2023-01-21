//! Function to convert infix to postfix

#include <stdio.h>
#include <stdlib.h>

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

int isEmpty() //* It will return value 1 if it is empty else it will return 0
{
    return (s.top == -1);
}

int preced(char stop, char opr)
{
    if (stop != '(' && opr == ')')
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

    printf("\nEnter Infix Expression: ");
    //* we use scanf because the user is forced to input only one word
    //* please enter capital letters
    scanf("%s", istr);

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

            if (isEmpty() || istr[i] != ')')
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
    puts(pstr);
    return 0;
}