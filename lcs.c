#include <stdio.h>
#define MAX 100

int main()
{
    char X[MAX], Y[MAX];
    int L[MAX][MAX];
    int m, n;

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    // Compute lengths
    for (m = 0; X[m] != '\0'; m++)
        ;
    for (n = 0; Y[n] != '\0'; n++)
        ;

    // Initialize table and compute LCS length
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    printf("Length of LCS: %d\n", L[m][n]);
    return 0;
}
