#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (visited[v] == 0 && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Dijkstra: Distance from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d: %d\n", i, dist[i]);
}

int main()
{
    // Dijkstra Graph: 5 nodes, adjacency matrix
    int graph[V][V] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}};
    dijkstra(graph, 0);

    return 0;
}
