//! Sentinel Search

#include <stdio.h>
#include "sort.h"

#define M 10

int main()
{
    int x[M + 1], i = 0;

    printf("\nArray Data\n");
    input(x, M);

    printf("\nEnter Value to be Searched: ");
    scanf("%d", &x[M + 1]);

    for (i = 0; x[i] != x[10]; i++)
        ;

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
