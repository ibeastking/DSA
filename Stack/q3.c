#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

typedef struct NODE
{
    int roll;
    struct NODE *next;
} node;

typedef struct STK
{
    node *top;
} stack;

int main()
{
    SLIST s;
    init(&s);

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
                printf("\nEnter Stack Data: ");
                scanf("%d", &d);
                addbeg(&s, d);
                break;
            case 2:
                delb(&s);
                break;
            case 3:
                display(&s);
                break;
            }
        }
    }

    return 0;
}