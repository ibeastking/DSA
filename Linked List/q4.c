//! Single Linked List implementation using local head pointer

#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct slist
{
    struct node *head;
} SLIST;

NODE *createnode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

void addbeg(NODE **t, int d)
{
    NODE *a = createnode(d);
    a->next = *t;
    *t = a;
}

void addend(NODE **t, int d)
{
    NODE *a, *b = createnode(d);

    if (*t == NULL)
    {
        *t = b;
    }
    else
    {
        a = *t;
        while (a->next != NULL)
        {
            a = a->next;
        }
        a->next = b;
    }
}

void display(NODE **t)
{
    NODE *a = *t;

    if (*t == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        while (a != NULL)
        {
            printf("%5d", a->data);
            a = a->next;
        }
    }
}

int main()
{
    NODE *head = NULL;

    addend(&head, 10);
    addend(&head, 20);
    addend(&head, 30);
    addbeg(&head, 40);

    display(&head);

    return 0;
}