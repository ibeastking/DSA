//! program to use the header file

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main()
{
    int opt;    //* enter the option you want
    int d;      //* enter the value you want to add
    SLIST p, q; //* initializing linked list
    int r;

    init(&p);

    while (1)
    {
        printf("\nMultiple Linked List\nMenu\n");
        printf("1. Add End\n2. Add Begin\n3. Display\n4. Node Count\n5. Sum of Node\n6. Odd Nodes Sum\n7. Even Nodes Sum");
        printf("\n8. Largest Node\n9. Smallest Node\n10. Search Number\n11. Find and replace");
        printf("\n12. Delete First link\n13. Delete Last Node\n14. Delete Full List\n15. Delete any node\n16. Reverse the List");
        printf("\n17. Display Reversed list\n18. Copy the List\n19. Copy the List in reverse order");
        printf("\n20. Create text File from List\n21. Create List from File\n22. Insert a Node\n23. Exit\nEnter option: ");
        scanf("%d", &opt);

        if (opt > 22)
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
                addend(&p, d);
                break;
            case 2:
                printf("\nEnter Data: ");
                scanf("%d", &d);
                addbeg(&p, d);
                break;
            case 3:
                display(&p);
                break;
            case 4:
                printf("\nNode Count: %d", count(&p));
                break;
            case 5:
                printf("\nNode Sum: %d", sum(&p));
                break;
            case 6:
                printf("\nOdd Nodes Sum: %d", osum(&p));
                break;
            case 7:
                printf("\nEven Nodes Sum: %d", esum(&p));
                break;
            case 8:
                printf("\nLargest Node: %d", findmax(&p));
                break;
            case 9:
                printf("\nSmallest Node: %d", findmin(&p));
                break;
            case 10:
                printf("\nEnter number to be searched: ");
                scanf("%d", &d);
                if (search(&p, d) == 0)
                    printf("\nNumber not found.");
                else
                    printf("\nNumber found.");
                break;
            case 11:
                printf("\nEnter the number: ");
                scanf("%d", &d);
                printf("Enter the number to be replaced: ");
                scanf("%d", &r);
                findrep(&p, d, r);
                break;
            case 12:
                delb(&p);
                break;
            case 13:
                dele(&p);
                break;
            case 14:
                del(&p);
                break;
            case 15:
                printf("\nEnter the node to delete: ");
                scanf("%d", &r);
                dela(&p, r);
                break;
            case 16:
                reverse(&p);
                break;
            case 17:
                disrev(p.head);
                break;
            case 18:
                q = copy(&p);
                //* we can also use q=p, which will transfer the head of p to q, therefore no new node is created
                display(&q);
                del(&q);
                break;
            case 19:
                q = copyrev(&p);
                display(&q);
                del(&q);
                break;
            case 20:
                list2file(&p);
                break;
            case 21:
                file2list(&q);
                break;
            case 22:
                printf("\nEnter the Node data: ");
                scanf("%d", &d);
                printf("Enter the Node Location: ");
                scanf("%d", &r);
                insert(&p, r, d);
                break;
            default:
                break;
            }
        }
    }

    return 0;
}