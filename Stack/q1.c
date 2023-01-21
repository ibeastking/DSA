#include <stdio.h>
#include <stdlib.h>

#define m 5

typedef struct STACK
{
    int top;
    int arr[m];
} stack;

void init(stack *t)
{
    t->top = -1;
}

//! Function to enter data in the stack

void push(stack *t, int d)
{
    if (t->top == m - 1)
    {
        printf("\nOverflow");
        return;
    }
    t->top++;
    t->arr[t->top] = d;
}

//! Function to remove data from the stack

void pop(stack *t)
{
    if (t->top == -1)
    {
        printf("\nUnderflow");
        return;
    }
    t->top--;
}

//! Function to display data from the stack

void display(stack *t)
{
    int i = t->top;

    if (t->top == -1)
    {
        printf("\nEmpty Stack");
        return;
    }
    printf("\nData: ");

    while (i >= 0)
    {
        printf("%5d", t->arr[i]);
        i--;
    }
}

void main()
{
    stack s;
    int d, opt;
    init(&s);

    while (1)
    {
        printf("\nMenu\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter Option: ");
        scanf("%d", &opt);

        if (opt > 3)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                printf("\nEnter Stack Data: ");
                scanf("%d", &d);
                push(&s, d);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            }
        }
    }
}