//! Evaluation of postfix expression
//? In the below program you need to declare and initialize the stack and declare push,pop and isEmpty function. After that you need to declare a compute function which
//? performs the operations on given operand and return the result value.
//? In the main function we first initialize the stack and declare postfix string. Then we insert the postfix string. Firstly we start traversing the string with one
//? character at a time and when the ch matches any letter then we ask the value of the operand and push it in the stack.

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int arr[10];
} s;

//! Function to initialize the stack
void init()
{
    s.top = -1;
}

//! Function to push values in the stack
void push(int val)
{
    s.top++;
    s.arr[s.top] = val;
}

//! Function to pop the top value from stack
int pop()
{
    return s.arr[s.top--];
}

//! Function to check if the stack is empty or not
int isEmpty()
{
    return (s.top == -1);
}

//! Function to compute the operation
int compute(int a, int b, char opr)
{
    int res;
    switch (opr)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    case '*':
        res = a * b;
        break;
    case '/':
        res = a / b;
        break;
    }

    return res;
}

int main()
{
    char pstr[50], ch;
    int i = 0, p, q, res, index;
    static int arr[26];
    init();

    printf("Enter Postfix Expression: ");
    scanf("%s", pstr);

    while (pstr[i] != '\0')
    {
        if (pstr[i] >= 'A' && pstr[i] <= 'Z')
        {
            index = pstr[i] - 65;
            printf("Enter value for %c: ", pstr[i]);
            scanf("%d", &arr[index]);
        }
        i++;
    }

    for (i = 0; pstr[i] != '\0'; i++)
    {
        if (pstr[i] >= 'A' && pstr[i] <= 'Z')
        {
            index = pstr[i] - 65;
            push(arr[index]);
        }
        else
        {
            q = pop();
            p = pop();
            res = compute(p, q, pstr[i]);
            push(res);
        }
    }

    printf("\nResult: %d.", pop());
    return 0;
}