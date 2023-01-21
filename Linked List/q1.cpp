#include <iostream>
#include <stdlib.h>

using namespace std;

//! Creating a structure for node
struct node
{
    int data;
    struct node *next;
};

//! Declaring a head node
struct node *head = NULL;

node *createnode(int d)
{
    node *a = new node;
    a->data = d;
    a->next = NULL;
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

void addend(int d)
{
    node *a;
    node *b = createnode(d);

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

void addbeg(int d)
{
    node *a = createnode(d);
    a->next = head;
    head = a;
}

void display()
{
    node *a = head;

    if (head == NULL)
    {
        cout << "\nEmpty";
    }
    else
    {
        while (a != NULL) //! we used a instead of a->next because we need to print the last node and stop the loop after last node
        {
            cout << a->data << " ";
            a = a->next;
        }
    }
}

int main()
{
    int arr[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the node data: ";
        cin >> arr[i];
        addbeg(arr[i]);
    }

    cout << endl;
    display();
    cout << endl;

    int arr1[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the node data: ";
        cin >> arr1[i];
        addend(arr1[i]);
    }

    cout << endl;
    display();

    return 0;
}