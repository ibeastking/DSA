#include <iostream>
#include <stdlib.h>

using namespace std;

//! Defining structure of node
struct node
{
    int data;
    struct node *next;
};

//! Defining structure of head list
struct slist
{
    node *head;
};

//! Initializing the header of linked list to null
void init(slist *t)
{
    t->head = NULL;
}

//! Function to create a node
node *createnode(int d)
{
    node *a;
    a = new node;
    a->data = d;
    a->next = NULL;
    return a;
}

//! Function to get last node
node *getlastnode(slist *t)
{
    node *a = t->head;

    while (a->next != NULL)
    {
        a = a->next;
    }

    return a;
}

//! Function to add node at begin
void addbeg(slist *t, int d)
{
    node *a;
    a = createnode(d);
    a->next = t->head;
    t->head = a;
}

//! Function to add node at end
void addend(slist *t, int d)
{
    node *a;
    node *b = createnode(d);

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

//! Function to display the linked list
void display(slist *t)
{
    node *a = t->head;

    if (t->head == NULL)
    {
        cout << "\nEmpty";
    }
    else
    {
        while (a != NULL)
        {
            cout << a->data << "   ";
            a = a->next;
        }
    }
}

//! Function to find number of nodes in linked list
int count(slist *t)
{
    node *a = t->head;
    int cnt = 0;

    while (a != NULL)
    {
        cnt++;
        a = a->next;
    }

    return cnt;
}

//! Function to find the sum of nodes
int sum(slist *t)
{
    node *a = t->head;
    int sum = 0;

    while (a != NULL)
    {
        sum = sum + a->data;
        a = a->next;
    }

    return sum;
}

//! Function to find the sum of odd nodes
int osum(slist *t)
{
    node *a = t->head;
    int sum = 0;

    while (a != NULL)
    {
        if (a->data % 2 == 1)
        {
            sum = sum + a->data;
        }
        a = a->next;
    }

    return sum;
}

//! Function to find the sum of even nodes
int esum(slist *t)
{
    node *a = t->head;
    int sum = 0;

    while (a != NULL)
    {
        if (a->data % 2 == 0)
        {
            sum = sum + a->data;
        }
        a = a->next;
    }

    return sum;
}

//! Function to find the largest element in the node
int findmax(slist *t)
{
    node *a = t->head;
    int max = a->data;

    while (a != NULL)
    {
        if (a->data > max)
        {
            max = a->data;
        }
        a = a->next;
    }

    return max;
}

//! Function to find the smallest element in the node
int findmin(slist *t)
{
    node *a = t->head;
    int min = a->data;

    while (a != NULL)
    {
        if (a->data < min)
        {
            min = a->data;
        }
        a = a->next;
    }

    return min;
}