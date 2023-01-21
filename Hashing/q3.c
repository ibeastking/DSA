#include <stdio.h>
#include <stdlib.h>
#define N 8

struct node
{
    int data;
    struct node *next;
} * k[N];

int visited[N];

struct node *createnode(int v)
{
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->data = v;
    a->next = NULL;
    return a;
}

void dft(int v)
{
    struct node *p;
    visited[v - 1] = 1;
    printf("%5d", v);

    p = k[v - 1];

    while (p != NULL)
    {
        if (visited[p->data - 1] == 1)
        {
            p = p->next;
        }
        else
        {
            dft(p->data);
        }
    }
}

int main()
{
    struct node *p, *q;
    int i, v;

    for (i = 0; i < N; i++)
    {
        printf("\nVertex: ");
        scanf("%d", &v);

        k[i] = p = createnode(v);
        printf("\nEnter Adjacency Verteices\n");

        while (1)
        {
            scanf("%d", &v);

            if (v == 0)
            {
                break;
            }
            q = createnode(v);
            p->next = q;
            p = q;
        }
    }

    dft(1);
}