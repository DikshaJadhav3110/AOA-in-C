#include <stdio.h>

#define MAX 20

int G[MAX][MAX]; // Graph (Adjacency Matrix)
int color[MAX];  // Colors assigned to vertices
int n = 5;       // Number of vertices
int m = 3;       // Number of colors

void printSolution() {
    printf("Coloring solution: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int isSafe(int v, int c) {
    for (int i = 1; i <= n; i++) {
        if (G[v][i] && color[i] == c) {
            return 0; // Adjacent vertex has same color
        }
    }
    return 1; // Safe to color
}

void NextColor(int k) {
    while (1) {
        color[k] = (color[k] + 1) % (m + 1);
        if (color[k] == 0)
            return; // Tried all colors

        if (isSafe(k, color[k]))
            return;
    }
}

void Coloring(int k) {
    while (1) {
        NextColor(k);
        if (color[k] == 0)
            return; // Backtrack

        if (k == n)
            printSolution();
        else
            Coloring(k + 1);
    }
}

int main() {

    // Static input (global G)
    int tempG[6][6] = {
        {0,0,0,0,0,0},
        {0,0,1,1,0,0},
        {0,1,0,1,1,1},
        {0,1,1,0,1,0},
        {0,0,1,1,0,1},
        {0,0,1,0,1,0}
    };

    // Copy to global G
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = tempG[i][j];

    // Initialize colors to 0 (no color)
    for (int i = 1; i <= n; i++)
        color[i] = 0;

    printf("Graph coloring solutions with %d colors:\n", m);
    Coloring(1);

    return 0;
}
