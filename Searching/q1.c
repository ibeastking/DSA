#include <stdio.h>
#include "sort.h"

#define M 10

int main()
{
    int x[M], i = 0, sv;

    printf("\nArray Data\n");
    input(x, M);

    printf("\nEnter Value to be Searched: ");
    scanf("%d", &sv);

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
        printf("\nFound");
    }

    return 0;
}