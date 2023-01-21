//! shell short

#include <stdio.h>
#include "sort.h"
#define M 15

void sort(int *a)
{
    int i, j, size = M / 2, tmp;

    while (size > 0)
    {
        for (i = size; i < M; i++)
        {
            tmp = a[i];
            for (j = i; (j - size) >= 0; j -= size)
            {
                if (a[j] < a[j - size])
                {
                    tmp = a[j];
                    a[j] = a[j - size];
                    a[j - size] = tmp;
                }
            }
        }

        size = size / 2;
        display(a, 0, M);
    }
}

int main()
{
    int x[M];
    input(x, M);
    display(x, 0, M);
    sort(x);
    display(x, 1, M);

    return 0;
}