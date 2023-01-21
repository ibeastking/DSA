#include <stdio.h>
#include <stdlib.h>
#define m 50

typedef struct CSTK
{
    int top;
    char arr[m];
} cstack;

void init(cstack *t)
{
    t->top = -1;
}

int empty(cstack *t)
{
    return (t->top == -1);
}

void push(cstack *t, char ch)
{
    t->top++;
    t->arr[t->top] = ch;
}

char pop(cstack *t)
{
    return t->arr[t->top--];
}