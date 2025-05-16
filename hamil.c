#include <stdio.h>

#define MAX 20

int G[MAX][MAX]; // Global graph
int x[MAX];      // Stores path
int n = 5;       // Number of vertices

void printSolution()
{
    printf("Hamiltonian Cycle: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("%d\n", x[1]); // Complete the cycle
}

void NextVertex(int k)
{
    while (1)
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
            return;

        if (G[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 1; j < k; j++)
            {
                if (x[j] == x[k])
                    break;
            }
            if (j == k)
            {
                if (k < n || (k == n && G[x[n]][x[1]] != 0))
                    return;
            }
        }
    }
}

void Hamiltonian(int k)
{
    while (1)
    {
        NextVertex(k);
        if (x[k] == 0)
            return;

        if (k == n)
            printSolution();
        else
            Hamiltonian(k + 1);
    }
}

int main()
{
    int i;

    // Static input (global G)
    int tempG[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 1, 0}, 
    {0, 1, 1, 0, 1, 1}, 
    {0, 0, 1, 1, 0, 1}, 
    {0, 0, 0, 1, 1, 0} 
};

    // Copy to global G
    for (i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] = tempG[i][j];

    // Initialize path
    for (i = 1; i <= n; i++)
        x[i] = 0;
    x[1] = 1;

    printf("Hamiltonian cycles found:\n");
    Hamiltonian(2);

    return 0;
}
