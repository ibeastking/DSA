//! insertion sort

#include <stdio.h>

int main()
{
    int i = 0, j, val, arr[5];

    while (i < 5)
    {
        printf("\nValue: ");
        scanf("%d", &val);

        for (j = i - 1; j >= 0; j--)
        {
            if (val < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = val;
        i++;
    }

    printf("\nData: ");
    for (i = 0; i < 5; i++)
    {
        printf("%5d", arr[i]);
    }

    return 0;
}