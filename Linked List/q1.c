#include <stdio.h>
#include <stdlib.h>

typedef struct node //* typedef is used to give alias to a variable like alias NODE is given to node
{
    int data;
    struct node *next;
} NODE;

//! head NODE ptr

NODE *head = NULL; //* st means head

//! Function to create NODE

NODE *createnode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;
    return a;
}

//! Function to retrieve last NODE address

NODE *getlastnode()
{
    NODE *a = head;

    while (a->next != NULL)
    {
        a = a->next;
    }

    return a;
}

//! Function to display list data

void display()
{
    NODE *a = head;

    if (head == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        printf("\nData");
        while (a != NULL) //* we used a instead of a->next because we need to print the last node and stop the loop after last node
        {
            printf("%5d", a->data);
            a = a->next;
        }
    }
}

//! Function to add new node at begin

void addbeg(int d)
{
    NODE *a = createnode(d);
    a->next = head;
    head = a;
}

//! Function to add new node at end

void addend(int d)
{
    NODE *a;
    NODE *b = createnode(d);

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

int main()
{
    int opt;

    int d;

    while (1)
    {
        printf("\nSingle Linked List\nMenu\n1. Add at Begin\n2. Add at End\n3. Display\n4. Exit\nOption: ");
        scanf("%d", &opt);

        if (opt > 3)
        {
            break;
        }

        switch (opt)
        {
        case 1:
            printf("\nData: ");
            scanf("%d", &d);
            addbeg(d);
            break;
        case 2:
            printf("\nData: ");
            scanf("%d", &d);
            addend(d);
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }

    return 0;
}