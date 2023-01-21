#include <stdio.h>
#include <stdlib.h>
#include "CSTK.h"

int main()
{
    char p[50], q[50];
    int i = 0;
    cstack s;
    init(&s);

    printf("Enter String: ");
    scanf("%s", p);

    while (p[i] != '\0')
    {
        push(&s, p[i]);
        i++;
    }

    i = 0;
    while (!empty(&s))
    {
        q[i] = pop(&s);
        i++;
    }

    q[i] = '\0';

    puts(p);
    puts(q);
    return 0;
}