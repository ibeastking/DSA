//! Multiple Linked list programs
//! program to use the header file

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main()
{
    int opt; //* enter the option you want
    int d;   //* enter the value you want to add
    int n;
    printf("\nEnter the number of lists: ");
    scanf("%d", &n);

    SLIST p[n]; //* initializing linked list

    int i = 0;

    for (i = 0; i < n; i++)
    {
        init(&p[i]);
    }

    while (1)
    {
        int ln;
        printf("\nEnter the list number: ");
        scanf("%d", &ln);

        if (ln >= n)
        {
            break;
        }

        else
        {
            while (1)
            {
                printf("\nMultiple Linked List\nMenu\n");
                printf("1. Add End\n2. Add Begin\n3. Display\n4. Node Count\n5. Sum of Node\n6. Odd Nodes Sum\n7. Even Nodes Sum");
                printf("\n8. Largest Node\n9. Smallest Node");
                printf("\n10.Exit\nEnter option: ");
                scanf("%d", &opt);

                if (opt > 9)
                {
                    break;
                }
                else
                {
                    switch (opt)
                    {
                    case 1:
                        printf("\nEnter Data: ");
                        scanf("%d", &d);
                        addend(&p[ln], d);
                        break;
                    case 2:
                        printf("\nEnter Data: ");
                        scanf("%d", &d);
                        addbeg(&p[ln], d);
                        break;
                    case 3:
                        display(&p[ln]);
                    case 4:
                        printf("\nNode Count: %d", count(&p[ln]));
                        break;
                    case 5:
                        printf("\nNode Sum: %d", sum(&p[ln]));
                        break;
                    case 6:
                        printf("\nOdd Nodes Sum: %d", osum(&p[ln]));
                        break;
                    case 7:
                        printf("\nEven Nodes Sum: %d", esum(&p[ln]));
                        break;
                    case 8:
                        printf("\nLargest Node: %d", findmax(&p[ln]));
                        break;
                    case 9:
                        printf("\nSmallest Node: %d", findmin(&p[ln]));
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }

    return 0;
}