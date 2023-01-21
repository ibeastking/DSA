//! Enter value is ascending order

#include <stdio.h>

int main()
{
    int x[10], sv;
    int i = 0, l, r, mid;

    while (i < 10)
    {
        printf("\nArray Data: ");
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
    scanf("%d", &sv);

    l = 0;
    r = 9;

    do
    {
        mid = (l + r) / 2;

        if (sv == x[mid])
        {
            break;
        }
        if (sv < x[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    } while (l <= r);

    if (l > r)
    {
        printf("\nNot Found");
    }
    else
    {
        printf("\nFound at %d", mid);
    }

    return 0;
}