//! Graph traversal using adjacency martix

#include <stdio.h>
#include <stdlib.h>

int n;           //* number of vertices
int visited[10]; //* visited array
int G[10][10];   //* adjacency matrix
int q[10];
int front = 0, rear = -1;

void init()
{
    int i = 0, j = 0;
    while (i < n)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
        {
            G[i][j] = 0;
            q[i] = 0;
        }
        i++;
    }
}

void dfs(int v)
{
    int i;
    printf("%5d", v);
    visited[v] = 1;
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0 && G[v][i] == 1)
        {
            dfs(i);
        }
    }
}

void bfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%5d", v);
    q[++rear] = v;

    while (front <= rear)
    {
        v = q[front++];
        for (i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && G[v][i] == 1)
            {
                q[++rear] = i;
                visited[i] = 1;
                printf("%5d", i);
            }
        }
    }
}

int main()
{
    init();
    int i, j, opt;
    printf("\nVertices Count: ");
    scanf("%d", &n);

    printf("\nAdjacency Matrix\n");
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

        if (i < 1 || j < 1 || i > n || j > n)
        {
            continue;
        }
        G[i][j] = G[j][i] = 1;
    }

    while (1)
    {
        printf("\nGraph Menu\n1. DFS\n2. BFS \n3.Exit\nEnter option: ");
        scanf("%d", &opt);

        if (opt == 3)
        {
            break;
        }
        if (opt == 1)
        {
            dfs(1);
        }
        else
        {
            bfs(1);
        }
    }

    return 0;
}