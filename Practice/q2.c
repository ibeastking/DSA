#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define m 50

typedef struct CSTK
{
    int top;
    char p[m];
} cstk;

void init(cstk *t)
{
    t->top = -1;
}

int isempty(cstk *t)
{
    if (t->top == -1)
    {
        return -1;
    }
    return 0;
}

int isfull(cstk *t)
{
    if (t->top == 49)
    {
        return 0;
    }
    return -1;
}
void push(cstk *t)
{
    if (isfull(t) == 0)
    {
        printf("the string is full can not push the element\n");
    }
    else
    {
        t->top++;
        printf("\nEnter character: ");
        scanf(" %c", &(t->p[t->top]));
    }
}
void pop(cstk *t)
{
    if (isempty(t) == -1)
    {
        printf("the string is empty u can't the pop element\n");
        return;
    }
    else
    {
        t->top--;
        return;
    }
}

void display(cstk *t)
{
    if (t->top == -1)
    {
        printf("the string is empty\n");
    }
    else
    {
        printf("the data in string is\n");
        while ((t->top) > -1)
        {
            printf("%c", t->p[t->top]);
            t->top--;
        }
    }
}

int main()
{
    cstk p;
    int o;
    char ch = 0;
    init(&p);
    while (1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\nenter a option=");
        scanf("%d", &o);
        if (o > 3)
        {
            break;
        }
        else
        {
            switch (o)
            {
            case 1:
                push(&p);
                break;

            case 2:
                pop(&p);
                break;

            case 3:
                display(&p);
                break;
            }
        }
    }
    return 0;
}