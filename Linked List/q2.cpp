#include <iostream>
#include <stdlib.h>
#include "slistcpp.h"

using namespace std;

int main()
{
    int d;
    slist p;
    int opt;

    init(&p);

    while (1)
    {
        printf("\nMultiple Linked List\nMenu\n");
        printf("1. Add End\n2. Add Begin\n3. Display\n4. Node Count\n5. Sum of Node\n6. Odd Nodes Sum\n7. Even Nodes Sum");
        printf("\n8. Largest Node\n9. Smallest Node");
        printf("\n10.Exit\nEnter option: ");
        cin >> opt;

        if (opt > 9)
        {
            break;
        }
        else
        {
            switch (opt)
            {
            case 1:
                cout << "\nEnter the node data: ";
                cin >> d;
                addend(&p, d);
                break;
            case 2:
                cout << "\nEnter the node data: ";
                cin >> d;
                addbeg(&p, d);
                break;
            case 3:
                display(&p);
                break;
            case 4:
                cout << "\nThe number of nodes in the linked list is " << count(&p);
                break;
            case 5:
                cout << "\nThe Sum of the nodes is " << sum(&p);
                break;
            case 6:
                cout << "\nThe Sum of odd nodes is " << osum(&p);
                break;
            case 7:
                cout << "\nThe Sum of even nodes is " << esum(&p);
                break;
            case 8:
                cout << "\nThe Largest node is " << findmax(&p);
                break;
            case 9:
                cout << "\nThe Smallest node is " << findmin(&p);
                break;
            default:
                break;
            }
        }
    }

    return 0;
}