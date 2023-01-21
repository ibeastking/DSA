//! insertion sort of already filled data type

#include <stdio.h>

int main()
{
    int arr[5], i, j, val, tmp;
    printf("\nArray Data\n");

    for (i = 0; i < 5; i++)
    {
        printf("Enter Data: ");
        scanf("%d", &arr[i]);
    }

    printf("Array Data before Sorting\n");
    for (i = 0; i < 5; i++)
    {
        printf("%5d", arr[i]);
    }

    for (i = 1; i < 5; i++)
    {
        val = arr[i];
        for (j = i - 1; j >= 0 && val < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = val;
    }

    printf("\nArray Data after Sorting\n");
    for (i = 0; i < 5; i++)
    {
        printf("%5d", arr[i]);
    }

    return 0;
}