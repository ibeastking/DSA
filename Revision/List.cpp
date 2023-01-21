#include <bits\stdc++.h>
using namespace std;

typedef struct NODE
{
    int data;
    struct NODE *next;
} node;

class List
{
    node *head;
    int c;
    int s;

public:
    List()
    {
        head = NULL;
        s = c = 0;
    }

    node *createnode()
    {
        int d;
        cout << "\nEnter Node Data: ";
        cin >> d;
        node *a;
        a->data = d;
        s = s + d;
        a->next = NULL;
        c++;
        return a;
    }

    node *getlastnode()
    {
        node *a = head;
        while (a->next != NULL)
        {
            a = a->next;
        }
        return a;
    }

    void display()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->next;
        }
    }

    void addbeg()
    {
        node *a = createnode();
        a->next = head;
        head = a;
    }

    void addend()
    {
        node *a;
        node *b = createnode();

        if (head == NULL)
        {
            head = b;
        }
        else
        {
            a = getlastnode();
            a->next = b;
        }
    }

    int count()
    {
        return c;
    }

    int sum()
    {
        return s;
    }

    void delb()
    {
        node *a = head;
        head = a->next;
        free(a);
    }
};