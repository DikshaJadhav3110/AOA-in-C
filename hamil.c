#include <stdio.h>
#include <stdbool.h>

#define V 5

int path[V];  // Stores the current Hamiltonian path

// Check if vertex v can be added at index 'pos' in the path
bool isSafe(int v, int graph[V][V], int pos) {
    // Check if this vertex is adjacent to the previous vertex in the path
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive utility function to solve the Hamiltonian Cycle problem
bool hamCycleUtil(int graph[V][V], int pos) {
    if (pos == V) {
        // If there's an edge from the last to the first vertex
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, pos + 1))
                return true;

            path[pos] = -1;  // Backtrack
        }
    }
    return false;
}

bool hamCycle(int graph[V][V]) {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  // Start at vertex 0

    if (hamCycleUtil(graph, 1) == false) {
        printf("No Hamiltonian Cycle exists\n");
        return false;
    }

    printf("Hamiltonian Cycle found:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);  // To show cycle
    return true;
}


int main() {
    int graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamCycle(graph1);
    return 0;
}
