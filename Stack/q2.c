#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int roll;
    struct NODE *next;
} node;

node *top = 0;

//! Function to push a node in the stack

void push(int d)
{
    node *a;
    a = (node *)malloc(sizeof(node));
    a->roll = d;
    a->next = top;
    top = a;
}

//! Function to pop a node from the stack

void pop()
{
    node *a = top;
    if (top == 0)
    {
        printf("\nUnderflow");
    }
    else
    {
        top = a->next;
        free(a);
    }
}

//! Function to display data from the stack

void display()
{
    node *a = top;

    if (top == 0)
    {
        printf("\nEmpty Stack");
    }
    else
    {
        printf("Data: ");

        while (a != 0)
        {
            printf("%5d", a->roll);
            a = a->next;
        }
    }
}

int main()
{
    int opt, d;

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
                printf("Enter Stack Data: ");
                scanf("%d", &d);
                push(d);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            }
        }
    }

    return 0;
}