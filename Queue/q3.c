//? Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct N
{
    int data;
    struct N *next;
} node;

typedef struct Q
{
    node *fr;
    node *rr;
} queue;

void init(queue *t)
{
    t->fr = t->rr = NULL;
}

node *createnode(int d)
{
    node *a;
    a = (node *)malloc(sizeof(node));
    a->data = d;
    a->next = NULL;
    return a;
}

void insert(queue *t, int d)
{
    node *a = createnode(d);

    if (t->fr == NULL)
    {
        t->fr = a;
    }
    else
    {
        (t->rr)->next = a;
    }
    t->rr = a;
}

void remque(queue *t)
{
    node *a = t->fr;

    if (t->fr == NULL)
    {
        printf("\nUnderflow");
        return;
    }

    if (t->fr == t->rr)
    {
        t->fr = t->rr = NULL;
    }
    else
    {
        t->fr = a->next;
    }
    free(a);
}

void display(queue *t)
{
    node *a = t->fr;

    if (t->fr == NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        printf("\nData: ");

        while (a != NULL)
        {
            printf("%5d", a->data);
            a = a->next;
        }
    }
}

int main()
{
    int opt, d;
    queue p;
    init(&p);

    while (1)
    {
        printf("\nQueue Menu\n1. Insert\n2. Remove\n3. Display\n4. Exit\nEnter Option: ");
        scanf("%d", &opt);

        if (opt > 4)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                printf("\nData: ");
                scanf("%d", &d);
                insert(&p, d);
                break;
            case 2:
                remque(&p);
                break;
            case 3:
                display(&p);
                break;
            }
        }
    }

    return 0;
}