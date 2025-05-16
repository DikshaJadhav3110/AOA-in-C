#include <stdio.h>

void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int sum, int target, int index) {
    if (sum == target) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    if (sum > target || index == n)
        return;

    // Include current element
    subset[subsetSize] = set[index];
    sumOfSubsets(set, subset, n, subsetSize + 1, sum + set[index], target, index + 1);

    // Exclude current element
    sumOfSubsets(set, subset, n, subsetSize, sum, target, index + 1);
}
    
int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 35;
    int subset[n];  // Temp array to store a subset

    printf("Subsets summing to %d:\n", target);
    sumOfSubsets(set, subset, n, 0, 0, target, 0);
    return 0;
}
