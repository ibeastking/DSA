//! Selection sort

#include <stdio.h>
#include "sort.h"

#define M 5

int main()
{
    int x[M];

    input(x, M);
    display(x, 0, M);
    selectionsort(x, M);
    display(x, 1, M);

    return 0;
}