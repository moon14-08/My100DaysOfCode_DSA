#include <stdio.h>

#define MAX 100
#define INF 999999

int graph[MAX][MAX];
int selected[MAX];

int main()
{
    int n, m, i, j;

    scanf("%d %d", &n, &m);

    // Initialize graph
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Input edges
    for(i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--;   // Convert 1-based to 0-based
        v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    for(i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1;   // Start from vertex 1

    int edges = 0, total = 0;

    while(edges < n - 1)
    {
        int min = INF;
        int x = -1, y = -1;

        for(i = 0; i < n; i++)
        {
            if(selected[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!selected[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if(y != -1)
        {
            selected[y] = 1;
            total += min;
            edges++;
        }
    }

    printf("%d", total);

    return 0;
}