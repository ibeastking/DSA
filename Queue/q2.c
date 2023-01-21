#include <stdio.h>
#define M 5

typedef struct C
{
    int fr, rr;
    int arr[M];
} cqueue;

//! Function to initialize cqueue
void init(cqueue *t)
{
    int i = 0;
    while (i < M)
    {
        t->arr[i] = -1;
        i++;
    }
    t->rr = t->fr = M - 1;
}

//! Function to count
int count(cqueue *t)
{
    int i = 0, cnt = 0;

    while (i < M)
    {
        if (t->arr[i] == -1)
        {
            cnt++;
        }
        i++;
    }

    return cnt;
}

//! Function to inset data in queue
void insert(cqueue *t, int d)
{
    if (count(t) == 0)
    {
        printf("\nOverflow");
        return;
    }

    if (t->rr == M - 1)
    {
        t->rr = 0;
    }
    else
    {
        t->rr++;
    }
    t->arr[t->rr] = d;
}

//! Function to remove queue
void remque(cqueue *t)
{
    if (count(t) == M)
    {
        printf("\nUnderflow");
        return;
    }

    if (t->fr == M - 1)
    {
        t->fr = 0;
    }
    else
    {
        t->fr++;
    }
    t->arr[t->fr] = -1;
}

//! Function to display
void display(cqueue *t)
{
    int i = 0;

    if (count(t) == M)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        if (t->fr < t->rr)
        {
            for (i = t->fr + 1; i <= t->rr; i++)
            {
                printf("%5d", t->arr[i]);
            }
        }
        else
        {
            for (i = t->fr + 1; i < M; i++)
            {
                printf("%5d", t->arr[i]);
            }
            for (i = 0; i <= t->rr; i++)
            {
                printf("%5d", t->arr[i]);
            }
        }
    }
}

int main()
{
    cqueue p;
    int opt, d;
    init(&p);

    while (1)
    {
        printf("\nCircular Queue\nMenu\n1. Insert\n2. Remove\n3. Display\n4. Exit\nEnter option: ");
        scanf("%d", &opt);

        if (opt > 3)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &d);
                insert(&p, d);
                break;
            case 2:
                remque(&p);
                break;
            case 3:
                display(&p);
                break;
            }
        }
    }

    return 0;
}