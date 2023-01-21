//! Creating a Header File

#include <stdio.h>
#include <stdlib.h>

//! Defining structure of node

typedef struct node
{
    int data;
    struct node *next;
} NODE;

//! Defining structure of head

typedef struct slist
{
    NODE *head;
} SLIST;

void init(SLIST *t)
{
    t->head = NULL;
}

//! Function to create NODE

NODE *createnode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

//! Function to find of number of nodes of list

int count(SLIST *t)
{
    NODE *a = t->head;
    int cnt = 0;

    while (a != NULL)
    {
        cnt++;
        a = a->next;
    }

    return cnt;
}

//! Function to get any node

NODE *getnode(SLIST *t, int loc)
{
    NODE *a = t->head;
    int i = 0;
    while (i < loc - 1)
    {
        a = a->next;
        i++;
    }

    return a;
}

//! Function to display any node

int disnode(SLIST *t, int loc)
{
    NODE *a = t->head;
    int i = 0;

    while (i < loc - 1)
    {
        a = a->next;
        i++;
    }

    return a->data;
}

//! Function to insert node

void insert(SLIST *t, int loc, int d)
{
    NODE *a = getnode(t, loc - 1);
    NODE *b = createnode(d);
    NODE *c = getnode(t, loc);

    b->next = c;
    a->next = b;
}

//! Function to delete a node

//! Function to delete at begin

void delb(SLIST *t)
{
    NODE *a = t->head;
    if (t->head == NULL)
    {
        return;
    }

    t->head = a->next;
    free(a);
}

//! Function to delete at end

void dele(SLIST *t)
{
    NODE *a = t->head;
    NODE *b;

    if (a == NULL)
    {
        return;
    }
    if (a->next == NULL)
    {
        delb(t);
        return;
    }

    while (a->next != NULL)
    {
        b = a;
        a = a->next;
    }

    b->next = NULL;
    free(b);
}

//! Function to delete the list

void del(SLIST *t)
{
    NODE *a = t->head;

    while (a != NULL)
    {
        t->head = a->next;
        free(a);
        a = t->head;
    }
}

//! Function to delete any node

void dela(SLIST *t, int loc)
{
    NODE *a, *b, *c;
    a = t->head;
    int i = 1;

    if (a == NULL || loc < 1)
    {
        return;
    }
    if (a->next == NULL)
    {
        delb(t);
        return;
    }

    while (a != NULL && i < loc)
    {
        b = a;
        a = a->next;
        i++;
    }

    if (a == NULL)
    {
        printf("\nNo such node exist");
    }

    c = a->next;
    b->next = c;
    free(a);
}

void reverse(SLIST *t)
{
    NODE *a = t->head;
    NODE *b = NULL;
    NODE *c;

    while (a != NULL)
    {
        c = a->next;
        a->next = b;
        b = a;
        a = c;
    }

    t->head = b;
}

SLIST *copyrev(SLIST *t)
{
}