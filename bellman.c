#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices
#define E 8  // Number of edges

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    printf("Bellman-Ford: Distance from source %d:\n", src);
    for (int i = 0; i < V; i++)
        printf("To %d: %d\n", i, dist[i]);
}

int main() {

    // Bellman-Ford Graph: edges list
    struct Edge edges[E] = {
        {0, 1, 6}, {0, 3, 1}, {1, 2, 5}, {1, 3, 2},
        {1, 4, 2}, {2, 4, 5}, {3, 4, 1}, {4, 2, -2}
    };
    bellmanFord(edges, 0);

    return 0;
}
