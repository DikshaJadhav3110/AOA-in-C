#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

void knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    // Build table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Print result
    printf("0/1 Knapsack: Max value = %d\n", dp[n][W]);

    // Trace selected items
    printf("Selected items (indexing from 0):\n");
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d (val=%d, wt=%d)\n", i - 1, val[i - 1], wt[i - 1]);
            w -= wt[i - 1];
        }
    }
}


int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    knapsack(W, wt, val, n);
    return 0;
}
