//! Bubble sort

#include <stdio.h>
#include "sort.h"
#define M 5

int main()
{
    int k[M];

    input(k, M);
    display(k, 0, M);
    bubblesort(k, M);
    display(k, 1, M);

    return 0;
}