#include <stdio.h>
#include <stdlib.h>

struct slist
{
    int rno;
    char nm[15];
    struct slist *next;
} k[10];

void init()
{
    int i = 0;
    while (i < 10)
    {
        k[i].rno = 0;
        k[i].next = NULL;
        i++;
    }
}

int hash(int n)
{
    return (n % 10);
}

void insert()
{
    int n, hval;
    struct slist *p, *q;

    printf("\nRoll Number: ");
    scanf("%d", &n);

    hval = hash(n);

    if (k[hval].rno == 0)
    {
        //* available at home area
        k[hval].rno = n;
        printf("\nName: ");
        scanf("%s", k[hval].nm);
        return;
    }

    p = (struct slist *)malloc(sizeof(struct slist));
    p->rno = n;
    printf("\nName: ");
    scanf("%s", p->nm);
    p->next = k[hval].next;
    k[hval].next = p;
}

void search()
{
    int n, hval;
    struct slist *p, *q;

    printf("\nRoll Number: ");
    scanf("%d", &n);

    hval = hash(n);

    if (k[hval].rno == n)
    {
        //* Search in home area
        printf("\nRoll Number: %d\nName: %s", k[hval].rno, k[hval].nm);
        return;
    }

    printf("\nSearch in Overflow Area");
    p = k[hval].next;
    while (p != NULL)
    {
        if (p->rno == n)
        {
            break;
        }
        p = p->next;
    }

    if (p == NULL)
    {
        printf("\nNot Found");
    }
    else
    {
        printf("\nRoll Number: %d\nName: %s", p->rno, p->nm);
    }
    return;
}

int main()
{
    int opt;

    while (1)
    {
        printf("\nMenu\n1. Insert\n2. Search\n3. Exit\nEnter Option: ");
        scanf("%d", &opt);

        if (opt > 2)
        {
            return 0;
        }
        if (opt == 1)
        {
            insert();
        }
        else
        {
            search();
        }
    }

    return 0;
}
