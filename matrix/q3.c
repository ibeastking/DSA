//! Use of adjacency list to store graph

#define N 20

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
} node;

node *p[N];
int n; //* node count

int main()
{
    node *a, *b;
    int val, i = 0;

    printf("\nEnter Node Count: ");
    scanf("%d", &n);

    while (i < n)
    {
        printf("\nEnter Vertex: ");
        scanf("%d", &val);

        a = (node *)malloc(sizeof(node));
        a->data = val;
        a->next = NULL;

        p[i] = a;

        printf("\nEnter Adjacent Vertices");

        //* single vertex
        while (1)
        {
            scanf("%d", &val);
            if (val == 0)
            {
                break;
            }
            b = (node *)malloc(sizeof(node));
            b->data = val;
            b->next = NULL;

            a->next = b;
            a = b;
        }
        i++;
    }

    printf("\nAdjacency List\n");

    for (i = 0; i < n; i++)
    {
        a = p[i];
        while (a != NULL)
        {
            printf("%5d", a->data);
            a = a->next;
        }
        printf("\n");
    }

    return 0;
}