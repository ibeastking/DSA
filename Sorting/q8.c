//! Radix Sort data length must be same
//! Make sure that inputted number is three digit

#include <stdio.h>
#include "sort.h"

#define M 10

typedef struct q
{
    int front;
    int rear;
    int arr[M];
} queue;

queue a[M]; //* array of queue

void init()
{
    int i = 0;
    while (i < M)
    {
        a[i].front = 0;
        a[i].rear = -1;
        i++;
    }
}

int getindex(int val, int pos)
{
    int index;
    switch (pos)
    {
    case 1:
        index = val % 10;
        break;
    case 2:
        index = (val / 10) % 10;
        break;
    case 3:
        index = val / 100;
        break;
    }

    return index;
}

void insert(int *p, int pos)
{
    int i = 0, j, k;
    init();

    while (i < M)
    {
        j = getindex(p[i], pos);
        k = ++a[j].rear;
        a[j].arr[k] = p[i];
        i++;
    }
}

void remque(int *p)
{
    int i = 0, j = 0, k = 0;

    while (i < M)
    {
        j = 0;
        while (j <= a[i].rear)
        {
            p[k] = a[i].arr[j];
            j++;
            k++;
        }
        i++;
    }
}

void radix(int *p)
{
    int i = 1;
    while (i <= 3)
    {
        insert(p, i);
        remque(p);
        i++;
    }
}

int main()
{
    int y[M];
    input(y, M);
    display(y, 0, M);
    radix(y);
    display(y, 1, M);

    return 0;
}