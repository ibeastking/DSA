//! Merge sort

#include <stdio.h>
#define M 10

void input(int *a)
{
    int i = 0;
    printf("\nData: ");
    while (i < M)
    {
        scanf("%d", (a + i));
        i++;
    }
}

void display(int *a, int flg)
{
    int i = 0;
    if (flg == 0)
    {
        printf("\nBefore Sorting\n");
    }
    else
    {
        printf("\nAfter Sorting\n");
    }

    while (i < M)
    {
        printf("%4d", a[i]);
        i++;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void merge(int *a)
{
    int size = 1, l1, u1, l2, u2;
    int i, j, k, tmp[M];

    while (size < M)
    {
        l1 = 0;
        k = 0;
        while (l1 + size < M)
        {
            l2 = l1 + size;
            u1 = l2 - 1;

            if (l2 + size < M)
            {
                u2 = l2 + size - 1;
            }
            else
            {
                u2 = M - 1;
            }

            for (i = l1, j = l2; i <= u1 && j <= u2; k++)
            {
                if (a[i] < a[j])
                {
                    tmp[k] = a[i++];
                }
                else
                {
                    tmp[k] = a[j++];
                }
            }

            for (; i <= u1; i++)
            {
                tmp[k++] = a[i];
            }
            for (; j <= u2; j++)
            {
                tmp[k++] = a[j];
            }
            l1 = u2 + 1;
        }

        for (i = l1; i < M; i++)
        {
            tmp[k++] = a[i];
        }
        for (i = 0; i < M; i++)
        {
            a[i] = tmp[i];
        }
        size = size * 2;
    }
}

int main()
{
    int x[M];
    input(x);
    display(x, 0);
    merge(x);
    display(x, 1);
    return 0;
}