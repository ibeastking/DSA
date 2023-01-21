#include <stdio.h>

#define M 5

//! structure to initialize queue
typedef struct Q
{
    int arr[M];
    int fr; //* fr stands for front end
    int rr; //* rr stands for rear end
} queue;

//! Function to initialize the queue
void init(queue *t)
{
    t->fr = 0;
    t->rr = -1;
}

//! Function to check if queue is empty
int isEmpty(queue *t)
{
    return (t->rr < t->fr);
}

//! Function to check if queue is full
int isFull(queue *t)
{
    return (t->rr == M - 1);
}

//! Function to insert data in the queue
void insert(queue *t, int d)
{
    t->rr++;
    t->arr[t->rr] = d;
}

//! Function to remove queue data
void remque(queue *t)
{
    t->fr++;
}

//! Function to display queue data
void display(queue *t)
{
    int i = t->fr;

    if (isEmpty(t))
    {
        printf("\nEmpty Queue");
    }
    else
    {
        printf("\nData: ");
        while (i <= t->rr)
        {
            printf("%5d", t->arr[i]);
            i++;
        }
    }
}

//! main function
int main()
{
    queue p;
    int opt, d;
    init(&p); //* call to initialize the queue

    while (1)
    {
        printf("\nQueue Menu\n1. Insert\n2. Remove\n3. Display\n4. Exit\nEnter option: ");
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
                if (isFull(&p))
                {
                    printf("\nOverflow");
                }
                else
                {
                    printf("\nEnter Data: ");
                    scanf("%d", &d);
                    insert(&p, d);
                }
                break;
            case 2:
                if (isEmpty(&p))
                {
                    printf("\nUnderflow");
                }
                else
                {
                    remque(&p);
                }
                break;
            case 3:
                display(&p);
            }
        }
    }
    return 0;
}