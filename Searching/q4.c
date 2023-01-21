//! Ordered List Search

#include <stdio.h>
#include "sort.h"

#define M 11

int main()
{
    int x[M], i = 0;

    printf("\nArray Data\n");

    while (i < 11)
    {
        scanf("%d", &x[i]);
        if (i > 0)
        {
            if (x[i] < x[i - 1])
            {
                printf("\nInvalid Data");
                continue;
            }
        }
        i++;
    }

    printf("\nSearch Value: ");
    scanf("%d", &x[10]);

    for (i = 0; x[i] < x[10]; i++)
        ;

    if (x[i] == x[10] && i < 10)
    {
        printf("\nFound");
    }
    else
    {
        printf("\nNot Found");
    }

    return 0;
}