//! MLIST to edit whole list instead of a single node

#include <stdio.h>
#include <stdlib.h>

//! Function to define data and next pointer

typedef struct node
{
    int data;
    struct node *next;
} NODE;

//! Function to define head pointer

typedef struct mlist
{
    NODE *head;
} MLIST;

void init(MLIST *t)
{
    t->head = NULL;
}

//! Function to create node

NODE *createnode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

//! Function to display new list

void display(MLIST *t)
{
    NODE *a = t->head;

    if (t->head == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        printf("\nData\n");

        while (a != NULL)
        {
            printf("%5d", a->data);
            a = a->next;
        }
    }
}

//! Function to create new list

void createlist(MLIST *t)
{
    NODE *a, *b;
    int d;

    while (t->head != NULL)
    {
        a = t->head;
        t->head = a->next;
        free(a);
    }
    printf("\nData: \n");
    while (1)
    {
        scanf("%d", &d);

        if (d == 0)
        {
            break;
        }
        a = createnode(d);

        if (t->head == NULL)
        {
            t->head = a;
        }
        else
        {
            b->next = a;
        }
        b = a;
    }
}

//! Function to make list empty

void del(MLIST *t)
{
    NODE *a;

    while (t->head != NULL)
    {
        a = t->head;
        t->head = a->next;
        free(a);
    }
}

//! Function to sort the list

void sort(MLIST *t)
{
    NODE *a, *b, *c;
    int temp;

    a = t->head;

    while (a->next != NULL)
    {
        c = a;
        b = a->next;
        while (b != NULL)
        {
            if (b->data < c->data)
            {
                c = b;
            }
            b = b->next;
        }

        if (a != c)
        {
            temp = a->data;
            a->data = c->data;
            c->data = temp;
        }

        a = a->next;
    }
}

//! Function to merge

MLIST merge(MLIST *s, MLIST *t)
{
    MLIST r;
    NODE *a = s->head;
    NODE *b = t->head;
    NODE *c, *d;
    init(&r);
    int val;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            val = a->data;
            a = a->next;
        }
        else
        {
            val = b->data;
            b = b->next;
        }

        c = createnode(val);

        if (r.head == NULL)
        {
            r.head = c;
        }
        else
        {
            d->next = c;
        }
        d = c;
    }

    while (a != NULL)
    {
        c = createnode(a->data);
        d->next = c;
        d = c;
        a = a->next;
    }

    while (b != NULL)
    {
        c = createnode(b->data);
        d->next = c;
        d = c;
        b = b->next;
    }

    return r;
}

//! Function to copy list

MLIST copy(MLIST *t)
{
    MLIST a;
    NODE *p = t->head, *q, *r;

    a.head = NULL;

    while (p != NULL)
    {
        q = createnode(p->data);
        if (a.head == NULL)
        {
            a.head = q;
        }
        else
        {
            r->next = q;
        }
        r = q;
        p = p->next;
    }
    return a;
}

//! Function to append list

void append(MLIST *d, MLIST *s)
{
    NODE *p = s->head;
    NODE *q = d->head;
    NODE *t;

    //* retrievel of last node from d

    while (q->next != 0)
    {
        q = q->next;
    }

    while (p != NULL)
    {
        t = createnode(p->data);
        q->next = t;
        q = t;
        p = p->next;
    }
}

//! Function to find intersection

MLIST intersection(MLIST *p, MLIST *q)
{
    MLIST r;
    NODE *a = p->head;
    NODE *b = q->head;
    NODE *c, *d;
    int data;

    init(&r);

    while (a != 0 && b != 0)
    {
        if (a->data < b->data)
        {
            a = a->next;
        }
        else
        {
            if (b->data < a->data)
            {
                b = b->next;
            }
            else
            {
                data = a->data;
                a = a->next;
                b = b->next;
                if (r.head == NULL)
                {
                    c = createnode(data);
                    r.head = d = c;
                }
                else
                {
                    if (data == d->data)
                    {
                        continue;
                    }
                    else
                    {
                        c = createnode(data);
                        d->next = c;
                        d = c;
                    }
                }
            }
        }
    }

    return r;
}

//! Function to combine two list

MLIST unionlist(MLIST *p, MLIST *q)
{
    MLIST r;
    NODE *a, *b, *c;

    r = merge(p, q);
    display(&r);
    a = r.head;

    while (a->next != NULL)
    {
        b = a->next;
        while (b->data == a->data)
        {
            c = b->next;
            a->next = c;
            free(b);
            b = c;
        }
        a = b;

        if (a == NULL)
        {
            break;
        }
    }

    return r;
}