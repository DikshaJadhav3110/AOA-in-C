#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100
int x[MAX]; // x[k] stores the column position of queen in row k

int Place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0; // Not safe to place
    }
    return 1; // Safe to place
}

void printSolution(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;
            if (k == n)
                printSolution(n);
            else
                NQueens(k + 1, n);
        }
    }
}

int main()
{
    NQueens(1, 5); // (k->row,5->number of queens(n))
    return 0;
}