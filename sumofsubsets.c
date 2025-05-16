#include <stdio.h>

int n = 5; // number of elements
int target = 7; // target sum
int set[20] = {2, 3, 5, 6, 1}; // static input set
int x[20]; // inclusion array

void printSubset() {
    printf("Subset: ");
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            printf("%d ", set[i]);
    }
    printf("\n");
}

void sumOfSubsets(int k, int currentSum) {
    if (currentSum == target) {
        printSubset();
        return;
    }

    if (k == n || currentSum > target)
        return;

    // Include element
    x[k] = 1;
    sumOfSubsets(k + 1, currentSum + set[k]);

    // Exclude element
    x[k] = 0;
    sumOfSubsets(k + 1, currentSum);
}

int main() {
    printf("Set: ");
    for (int i = 0; i < n; i++)
        printf("%d ", set[i]);
    printf("\nTarget sum: %d\n", target);
    printf("Subsets with sum = %d:\n", target);

    sumOfSubsets(0, 0);

    return 0;
}
