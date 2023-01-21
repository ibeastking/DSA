#include <stdio.h>
#include <stdlib.h>
#include "mlist.h"

int main()
{
    MLIST p, q, r;
    init(&p);
    init(&q);
    init(&r);

    int opt; //* Enter the option you want

    while (1)
    {
        printf("\n1. Create List 1\n2. Create List 2\n3. Display List 1\n4. Display List 2\n5. Display List 3");
        printf("\n6. Sort List 1\n7. Sort List 2\n8. Delete List 1\n9. Delete List 2\n10. Delete List 3\n11. Merge List\n12. Copy\n13. Append");
        printf("\n14. Intersection\n15. Union\n16. Exit\nEnter the option: ");
        scanf("%d", &opt);

        if (opt > 15)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                createlist(&p);
                break;
            case 2:
                createlist(&q);
                break;
            case 3:
                display(&p);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                display(&r);
                break;
            case 6:
                sort(&p);
                break;
            case 7:
                sort(&q);
                break;
            case 8:
                del(&p);
                break;
            case 9:
                del(&q);
                break;
            case 10:
                del(&r);
                break;
            case 11:
                sort(&p);
                sort(&q);
                r = merge(&p, &q);
                break;
            case 12:
                r = copy(&p);
                display(&r);
                break;
            case 13:
                append(&q, &p);
                break;
            case 14:
                if (p.head == 0 || q.head == 0)
                {
                    continue;
                }
                else
                {
                    sort(&p);
                    sort(&q);
                    r = intersection(&p, &q);
                }
                break;
            case 15:
                sort(&p);
                sort(&q);
                r = unionlist(&p, &q);
                break;
            default:
                break;
            }
        }
    }

    return 0;
}