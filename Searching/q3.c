//! Probability Search

#include <stdio.h>
#include "sort.h"

#define M 10

int main()
{
    int x[M], i = 0, j = 0, sv, tmp;

    printf("\nArray Data\n");
    input(x, M);

    while (1)
    {
        printf("\nSearch Value: ");
        scanf("%d", &sv);

        if (sv == 0)
        {
            break;
        }

        for (i = 0; i < M; i++)
        {
            if (x[i] == sv)
            {
                break;
            }
        }

        if (i == M)
        {
            printf("\nNot Found");
        }
        else
        {
            j = i - 1;

            if (j >= 0)
            {
                tmp = x[j];
                x[j] = x[i];
                x[i] = tmp;
            }
        }
    }

    return 0;
}