#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    return m[1][n - 1];  // Minimum cost to multiply from A1 to An-1
}
int main() {
    int p[] = {1,4,5,2};
    int n = sizeof(p) / sizeof(p[0]);

    int minCost = matrixChainOrder(p, n);
    printf("Minimum number of multiplications: %d\n", minCost);
    return 0;
}
