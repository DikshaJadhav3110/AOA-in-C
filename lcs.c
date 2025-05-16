#include <stdio.h>
#define MAX 100

int main()
{
    char X[MAX], Y[MAX];
    int L[MAX][MAX];
    int m = 0, n = 0;

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    // Compute lengths
    while (X[m] != '\0')
    {
        m++;
    }

    while (Y[n] != '\0')
    {
        n++;
    }

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

// #include <stdio.h>
// #define MAX 100

// int main()
// {
//     char X[MAX], Y[MAX];
//     int L[MAX][MAX];
//     int m, n;

//     // Input strings
//     printf("Enter first string: ");
//     scanf("%s", X);
//     printf("Enter second string: ");
//     scanf("%s", Y);

//     // Compute lengths of the input strings
//     for (m = 0; X[m] != '\0'; m++)
//         ;
//     for (n = 0; Y[n] != '\0'; n++)
//         ;

//     // Fill the LCS table
//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if (i == 0 || j == 0)
//                 L[i][j] = 0;
//             else if (X[i - 1] == Y[j - 1])
//                 L[i][j] = L[i - 1][j - 1] + 1;
//             else
//                 L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
//         }
//     }

//     printf("Length of LCS: %d\n", L[m][n]);

//     // Reconstruct and print the LCS
//     int i = m, j = n;
//     char lcs[MAX];
//     int index = 0;

//     while (i > 0 && j > 0)
//     {
//         if (X[i - 1] == Y[j - 1])
//         {
//             lcs[index++] = X[i - 1];
//             i--;
//             j--;
//         }
//         else if (L[i - 1][j] > L[i][j - 1])
//             i--;
//         else
//             j--;
//     }

//     lcs[index] = '\0';

//     // Reverse the LCS string
//     for (int k = 0; k < index / 2; k++)
//     {
//         char temp = lcs[k];
//         lcs[k] = lcs[index - 1 - k];
//         lcs[index - 1 - k] = temp;
//     }

//     printf("LCS: %s\n", lcs);

//     return 0;
// }
