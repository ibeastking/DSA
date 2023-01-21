#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int roll;
    struct NODE *next;
} node;

typedef struct MLIST
{
    node *head;
} mlist;

void init(mlist *t)
{
    t->head = NULL;
}

node *createnode(int d)
{
    node *a;
    a = (node *)malloc(sizeof(node));
    a->roll = d;
    a->next = NULL;
    return a;
}

void display(mlist *t)
{
    node *a = t->head;

    while (a != 0)
    {
        printf("%5d", a->roll);
        a = a->next;
    }
}

void createlist(mlist *t)
{
    node *a;
    node *b;
    int d;

    while (a != 0)
    {
        a = t->head;
        t->head = a->next;
        free(a);
    }

    while (1)
    {
        printf("Enter node data: ");
        scanf("%d", &d);

        if (d == 0)
        {
            break;
        }

        a = createnode(d);

        if (t->head == 0)
        {
            t->head = b;
        }
        else
        {
            b->next = a;
        }
        b = a;
    }
}

void del(mlist *t)
{
    node *a;

    while (t->head != NULL)
    {
        a = t->head;
        t->head = a->next;
        free(a);
    }
}

void sort(mlist *t)
{
    node *a = t->head;
    node *b;
}