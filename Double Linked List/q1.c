//! Program to implement double list
#include <stdio.h>
#include <stdlib.h>

//! defining structure of node

typedef struct NODE
{
    struct NODE *prev;
    int roll;
    struct NODE *next;
} node;

//! defining structure of dlist

typedef struct DLIST
{
    node *head;
    node *end;
} dlist;

//! Function to initialize dlist

void init(dlist *t)
{
    t->head = t->end = 0;
}

//! Function to create new node

node *createnode(int d)
{
    node *a = (node *)malloc(sizeof(node));
    a->roll = d;
    a->prev = a->next = 0;
    return a;
}

//! Function to add new node at end

void addend(dlist *t, int d)
{
    node *a, *b;
    a = createnode(d);

    if (t->head == 0)
    {
        t->head = a;
        t->end = a;
    }
    else
    {
        b = t->end;
        b->next = a;
        a->prev = b;
        t->end = a;
    }
}

//! Function to add new node at begin

void addbeg(dlist *t, int d)
{
    node *a, *b;

    a = createnode(d);

    if (t->end == 0)
    {
        t->end = a;
    }
    else
    {
        b = t->head;
        b->prev = a;
        a->next = b;
    }
    t->head = a;
}

//! Function to display list

void display(dlist *t)
{
    node *a;

    if (t->head == 0)
    {
        printf("\nEmpty list");
    }
    else
    {
        printf("\nData: ");
        while (a != 0)
        {
            printf("%5d", a->roll);
            a = a->next;
        }
    }
}

//! Function to display data in reverse order

void disrev(dlist *t)
{
    node *a = t->end;

    if (t->end == 0)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nData: ");
        while (a != 0)
        {
            printf("%5d", a->roll);
            a = a->prev;
        }
    }
}

//! Function to delete first node

void delf(dlist *t)
{
    node *a = t->head;
    node *b;

    if (t->head == 0)
    {
        printf("\nEmpty List");
        return;
    }

    if (t->head == t->end)
    {
        t->head = t->end = 0;
        free(a);
    }
    else
    {
        b = a->next;
        b->prev = 0;
        t->head = b;
    }
}

//! Function to delete last node

void dell(dlist *t)
{
    node *a = t->end;
    node *b;

    if (t->head == 0)
    {
        printf("\nEmpty List");
        free(a);
    }

    if (t->head == t->end)
    {
        t->head = t->end = 0;
        free(a);
    }
    else
    {
        b = a->prev;
        b->next = 0;
        t->end = b;
        free(a);
    }
}

//! Function to delete any node

void dela(dlist *t, int loc)
{
    node *a = t->head;
    node *b;
    node *c;
    int i = 1;

    if (loc < 1 || t->head == 0)
    {
        return;
    }
    if (loc == 1)
    {
        delf(t);
    }
    else
    {
        while (i < loc && a != 0)
        {
            b = a;
            a = a->next;
            i++;
        }

        if (a == 0)
        {
            return;
        }
        if (a->next == 0)
        {
            dell(t);
        }
        else
        {
            c = a->next;
            b->next = c;
            c->prev = b;
            free(a);
        }
    }
}

//! Function to count number of nodes

int count(dlist *t)
{
    node *a = t->head;
    int cnt = 0;

    while (a != 0)
    {
        cnt++;
        a = a->next;
    }

    return cnt;
}

//! Function to calculate sum of the list

int sum(dlist *t)
{
    node *a = t->head;
    int sum = 0;

    while (a != 0)
    {
        sum = sum + a->roll;
        a = a->next;
    }

    return sum;
}

//! Function to insert before i position

void insertb(dlist *t, int loc, int d)
{
    node *a = t->head;
    node *b, *c;
    int i = 1;

    if (t->head == 0)
    {
        return;
    }
    if (loc == 1)
    {
        addbeg(t, d);
    }
    else
    {
        a = t->head;
        i = 1;

        while (i < loc && a != 0)
        {
            b = a;
            a = a->next;
            i++;
        }

        if (a == 0)
        {
            printf("\nInvalid Position");
            return;
        }
        else
        {
            c = createnode(d);
            a->prev = c;
            c->prev = b;
            c->next = a;
            b->next = c;
        }
    }
}

//! Function to insert after i position

void inserta(dlist *t, int d, int loc)
{
    node *a, *b, *c;
    int i;

    if (t->head)
    {
        return;
    }
    if (loc < 1)
    {
        return;
    }

    a = t->head;
    i = 1;

    while (i < loc + 1 && a != 0)
    {
        b = a;
        a = a->next;
        i++;
    }

    if (i < loc)
    {
        printf("\nInvalid Input");
    }
    else
    {
        if (a == 0)
        {
            addend(t, d);
        }
        else
        {
            c = createnode(d);
            b->next = c;
            c->prev = b;
            c->next = a;
            b->prev = c;
        }
    }
}

int main()
{
    dlist p;
    int opt, d, loc, res;
    init(&p);

    while (1)
    {
        printf("\nMenu\n1. Add End\n2. Add Begin\n3. Display\n4. Display in reverse\n5. Count\n6. Sum\n7. Delete First\n8. Delete Last\n9. Delete any node");
        printf("\n10. Insert Before\n11. Insert After\n12. Exit\nEnter option: ");
        scanf("%d", &opt);

        if (opt > 11)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                printf("Enter node data: ");
                scanf("%d", &d);
                addend(&p, d);
                break;
            case 2:
                printf("Enter node data: ");
                scanf("%d", &d);
                addbeg(&p, d);
                break;
            case 3:
                display(&p);
                break;
            case 4:
                disrev(&p);
                break;
            case 5:
                printf("Number of Nodes: %d", count(&p));
                break;
            case 6:
                printf("\nSum of nodes: %d", sum(&p));
                break;
            case 7:
                delf(&p);
                break;
            case 8:
                dell(&p);
                break;
            case 9:
                printf("\nEnter the node number to delete: ");
                scanf("%d", &loc);
                dela(&p, loc);
                break;
            case 10:
                printf("Enter node data: ");
                scanf("%d", &d);
                printf("Enter position: ");
                scanf("%d", &loc);
                insertb(&p, loc, d);
                break;
            case 11:
                printf("Enter node data: ");
                scanf("%d", &d);
                printf("Enter position: ");
                scanf("%d", &loc);
                inserta(&p, loc, d);
                break;
            default:
                break;
            }
        }
    }
}