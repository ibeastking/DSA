//! implementation of
//! collision resolution using linear probing
#include <stdio.h>
#include <stdlib.h>

struct student
{
    int n;
    char nm[15];
} k[10];

void init()
{
    int i = 0;
    while (i < 10)
    {
        k[i].n = 0;
        i++;
    }
}

int hash(int n)
{
    return (n % 10);
}

void input(struct student *t, int n)
{
    t->n = n;
    printf("Name: ");
    scanf("%s", t->nm);
    return;
}

void display(struct student *t)
{
    printf("\n%5d %-15s", t->n, t->nm);
}

void insert()
{
    int n, hval, i = 0;

    printf("\nRoll Number: ");
    scanf("%d", &n);

    hval = hash(n);

    if (k[hval].n == 0)
    {
        input(k + hval, n);
        printf("\nInsertion at Home Area");
        return;
    }

    printf("\nCollision Occured\n");

    for (i = hval + 1; i < 10; i++)
    {
        if ((k + i)->n == 0)
        {
            input(k + i, n);
            printf("\nInsertion at Collision Path");
            break;
        }
    }

    if (i < 10)
    {
        return;
    }

    for (i = 0; i < hval; i++)
    {
        if ((k + i)->n == 0)
        {
            input(k + i, n);
            printf("\nInsertion at Collision Path");
            break;
        }
    }

    if (i == hval)
    {
        printf("\nOverflow");
    }
}

void search()
{
    int n, hval, i = 0;

    printf("\nRoll Number: ");
    scanf("%d", &n);

    hval = hash(n);

    if (k[hval].n == n)
    {
        display(k + hval);
        printf("\nFound at Home Area");
        return;
    }

    printf("\nSearching on Collision Path");

    for (i = hval + i; i < 10; i++)
    {
        if ((k + i)->n == n)
        {
            display(k + i);
            printf("\nFound on Collision Path");
            break;
        }
    }

    if (i < 10)
    {
        return;
    }

    for (i = 0; i < hval; i++)
    {
        if ((k + i)->n == n)
        {
            display(k + i);
            printf("\nSearch at Collision Path");
            break;
        }
    }

    if (i == hval)
    {
        printf("\nNot Found");
    }
}

int main()
{
    init();

    int opt;
    while (1)
    {
        printf("\nHashing Menu\n1. Insert\n2. Search\n3. Exit\nEnter Option: ");
        scanf("%d", &opt);

        if (opt > 2)
        {
            break;
        }
        if (opt == 1)
        {
            insert();
            printf("\nData has been inserted");
        }
        else
        {
            search();
        }
    }

    return 0;
}