#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int visited[MAX];
int adj[MAX][MAX];
int adjSize[MAX];

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        adjSize[i] = 0;
    }

    // undirected graph input
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int components = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}