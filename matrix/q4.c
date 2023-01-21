#include <stdio.h>
#include <stdlib.h>
#define N 8

struct list
{
    int data;
    struct list *next;
} * k[N];

int visited[N];
int q[N];

int f = 0, r = -1;

//* function to createnode
struct list *createnode(int d)
{
    struct list *p;
    p = (struct list *)malloc(sizeof(struct list));
    p->data = d;
    p->next = NULL;
    return p;
}

void createlist()
{
    int i = 0, v;
    struct list *p, *q;

    while (i < N)
    {
        printf("\nVertex\n");
        scanf("%d", &v);
        k[i] = createnode(v);
        p = createnode(v);

        printf("\nEnter Adjacent Vertices: ");

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
        i++;
    }
}

void bfs(int v)
{
    struct list *a;
    visited[v - 1] = 1;
    printf("%5d", v);
    q[++r] = v;

    while (f <= r)
    {
        v = q[f++];
        a = k[v - 1];

        while (a != NULL)
        {
            if (visited[a->data - 1] == 0)
            {
                q[++r] = a->data;
                visited[a->data - 1] = 1;
                printf("%5d", a->data);
            }
            a = a->next;
        }
    }
}

int main()
{
    createlist();
    bfs(1);
    return 0;
}