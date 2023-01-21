#include <stdio.h>
#include <stdlib.h>
#include "CSTK.h"

int main()
{
    char p[50], q[50], ch;
    int i = 0;
    int cnt = 0;
    cstack a;
    init(&a);

    printf("Enter String: ");
    scanf("%s", p);

    while (p[i] != '\0')
    {
        if (p[i] == '(')
        {
            push(&a, p[i]);
            cnt = 1;
        }
        else
        {
            if (p[i] == ')')
            {
                cnt = 1;
                if (empty(&a))
                {
                    break;
                }
                ch = pop(&a);
            }
        }
        i++;
    }

    if (cnt == 0)
    {
        printf("\nNo Parenthesis");
    }
    else
    {
        if (empty(&a))
        {
            if (p[i] == '\0')
            {
                printf("balanced");
            }
            else
            {
                printf("Unbalanced Right");
            }
        }
        else
        {
            printf("Unbalanced Left");
        }
    }
    return 0;
}