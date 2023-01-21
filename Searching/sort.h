#include <stdio.h>

void input(int *a, int M)
{
    int i;
    for (i = 0; i < M; i++)
    {
        printf("Enter Data: ");
        scanf("%d", (a + i));
    }
}

void display(int *a, int flg, int M)
{
    int i;

    if (flg == 0)
    {
        printf("\nData before Sorting");
    }
    else
    {
        printf("\nData After Sorting");
    }

    for (i = 0; i < M; i++)
    {
        printf("%5d", a[i]);
    }
}

void bubblesort(int *k, int M)
{
    int i, j, flg, tmp;
    //* flg is used to check if the data is already sorted or not, if the flg=0, then the data is already is sorted

    for (i = 0; i < M - 1; i++)
    {
        flg = 0;

        for (j = 0; j < (M - i - 1); j++)
        {
            if (k[j] > k[j + 1])
            {
                flg = 1;
                tmp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = tmp;
            }
        }

        if (flg == 0)
        {
            break;
        }
    }
}

void selectionsort(int *x, int M)
{
    int i, j, pos, tmp;

    for (i = 0; i < M - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < M; j++)
        {
            if (x[j] < x[pos])
            {
                pos = j;
            }
        }

        if (i != pos)
        {
            tmp = x[i];
            x[i] = x[pos];
            x[pos] = tmp;
        }
    }
}

void shellsort(int *a, int M)
{
    int i, j, size = 5, tmp;

    while (size > 0)
    {
        for (i = size; i < 15; i++)
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
