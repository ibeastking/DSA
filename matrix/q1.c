//! use of adjaceny matrix to store graph (undirected graph)

#include <stdio.h>
#include <stdlib.h>
#define N 20

int adj[N][N]; //* adjacency matrix
int n;         //* number of vertices

void display()
{
    int i, j;
    printf("\nAdjacency Matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%5d", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j;

    printf("\nEnter Vertices Count: ");
    scanf("%d", &n);

    printf("Enter Adjacent Nodes: ");
    while (1)
    {
        printf("\nSource: ");
        scanf("%d", &i);

        printf("Destination: ");
        scanf("%d", &j);

        if (i == 0 && j == 0)
        {
            break;
        }
        if (i < 1 || i > n || j < 1 || j > n)
        {
            continue;
        }
        adj[i][j] = adj[j][i] = 1;
    }

    display();
    return 0;
}