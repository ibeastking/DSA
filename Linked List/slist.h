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

//! Function to get last node

NODE *getlastnode(SLIST *t)
{
    NODE *a = t->head;

    while (a->next != NULL)
    {
        a = a->next;
    }
    return a;
}

//! Function to display linked list

void display(SLIST *t)
{
    NODE *a = t->head;

    if (t->head == NULL)
        printf("\nEmpty");
    else
    {
        printf("\nData: ");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}

//! Function to add new node at begin

void addbeg(SLIST *t, int d)
{
    NODE *a = createnode(d);
    a->next = t->head;
    t->head = a;
}

//! Function to add new node at end

void addend(SLIST *t, int d)
{
    NODE *a;
    NODE *b = createnode(d);

    if (t->head == NULL)
    {
        t->head = b;
    }
    else
    {
        a = getlastnode(t);
        a->next = b;
    }
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

//! Function to compute data sum of node

int sum(SLIST *t)
{
    int tot = 0;
    NODE *a = t->head;

    while (a != NULL)
    {
        tot = tot + a->data;
        a = a->next;
    }

    return tot;
}

//! Function to compute odd nodes sum

int osum(SLIST *t)
{
    int tot = 0;
    NODE *a = t->head;

    while (a != NULL)
    {
        if (a->data % 2 == 1)
        {
            tot = tot + a->data;
        }
        a = a->next;
    }

    return tot;
}

//! Function to compute even nodes sum

int esum(SLIST *t)
{
    int tot = 0;
    NODE *a = t->head;

    while (a != NULL)
    {
        if (a->data % 2 == 0)
        {
            tot = tot + a->data;
        }
        a = a->next;
    }

    return tot;
}

//! Function to find max element

int findmax(SLIST *t)
{
    NODE *a = t->head;
    int max = a->data;

    for (a = a->next; a != NULL; a = a->next)
    {
        if (a->data > max)
            max = a->data;
    }

    return max;
}

//! Function to find min element

int findmin(SLIST *t)
{
    NODE *a = t->head;
    int min = a->data;

    for (a = a->next; a != NULL; a = a->next)
    {
        if (a->data < min)
            min = a->data;
    }

    return min;
}

//! Function to implement search, return 1 if found otherwise 0

int search(SLIST *t, int d)
{
    NODE *a = t->head;

    while (a != NULL)
    {
        if (a->data == d)
        {
            break;
        }
        a = a->next;
    }

    if (a == NULL)
        return 0;
    else
        return 1;
}

//! Function to find and replace

void findrep(SLIST *t, int d, int r)
{
    NODE *a = t->head;

    while (a != NULL)
    {
        if (a->data == d)
        {
            a->data = r;
        }
        a = a->next;
    }
}

//! Function to delete first node from the list

void delb(SLIST *t)
{
    NODE *a = t->head;
    if (t->head == NULL)
        return;
    t->head = a->next;
    free(a);
}

//! Function to delete Last node from the list

void dele(SLIST *t)
{
    NODE *a = t->head;
    NODE *b;

    if (t->head == NULL)
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
    free(a);
}

//! Function to delete Linked List

void del(SLIST *t)
{
    NODE *a = t->head;

    while (t->head != NULL)
    {
        t->head = a->next;
        free(a);
        a = t->head;
    }
}

//! Function to delete any node

void dela(SLIST *t, int pos)
{
    NODE *a, *b, *c;
    int i = 1;

    if (t->head == NULL || pos < 1)
    {
        return;
    }

    if (pos == 1)
    {
        delb(t);
        return;
    }

    a = t->head;
    while (a != NULL && i < pos)
    {
        b = a;
        a = a->next;
        i++;
    }

    if (a == NULL)
    {
        printf("\nNo such Node Exist");
        return;
    }

    c = a->next;
    b->next = c;
    free(a);
    return;
}

//! Function to reverse the list

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

//! Function to reverse the list from specific points

NODE *reverseBetween(NODE *head, int left, int right)
{
    NODE *currentnode = head;
    NODE *prevnode = NULL;
    NODE *nextnode = NULL;
    NODE *tail = NULL;
    NODE *con = NULL;

    if (head == NULL)
    {
        return head;
    }

    while (left > 1)
    {
        prevnode = currentnode;
        currentnode = currentnode->next;
        left--;
        right--;
    }

    tail = currentnode;
    con = prevnode;

    while (right > 0)
    {
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
        right--;
    }

    if (con != NULL)
    {
        con->next = prevnode;
    }
    else
    {
        head = prevnode;
    }

    tail->next = currentnode;

    return head;
}

//! Function to display data in reverse order

void disrev(NODE *a)
{
    if (a == NULL)
    {
        return;
    }

    disrev(a->next);
    printf("%5d", a->data);
}

//! Function to copy

SLIST copy(SLIST *t)
{
    SLIST k;
    NODE *a, *b, *c;
    k.head = NULL;
    a = t->head;

    while (a != NULL)
    {
        b = createnode(a->data);

        if (k.head == NULL)
        {
            k.head = b;
        }
        else
        {
            c->next = b;
        }

        c = b;
        a = a->next;
    }
    return k;
}

//! Function copy list in reverse order

SLIST copyrev(SLIST *t)
{
    NODE *a = t->head;
    SLIST q;
    q.head = NULL;

    while (a != NULL)
    {
        addbeg(&q, a->data);
        a = a->next;
    }

    return q;
}

//! FUnction to write List data to file

void list2file(SLIST *t)
{
    NODE *a = t->head;
    int d;
    FILE *f1;

    f1 = fopen("List.txt", "w");

    while (a != NULL)
    {
        d = a->data;
        fprintf(f1, "%d\n", d);
        a = a->next;
    }
    fclose(f1);
}

//! Function to create list from file

void file2list(SLIST *t)
{
    int d;
    FILE *f1;

    f1 = fopen("List.txt", "r");

    if (f1 == NULL)
    {
        return;
    }
    del(t);

    while (1)
    {
        fscanf(f1, "%d", &d);

        if (feof(f1))
        {
            break;
        }
        addend(t, d);
    }

    fclose(f1);
}

//! Function to add node at any location

void insert(SLIST *t, int loc, int d)
{
    NODE *a = t->head;
    NODE *b;
    NODE *c = createnode(d);
    int i = 1;

    if (loc < 1)
    {
        return;
    }

    if (a == NULL)
    {
        addbeg(t, d);
        return;
    }

    while (i < loc)
    {
        b = a;
        a = a->next;
        i++;
    }

    b->next = c;
    c->next = a;
}
