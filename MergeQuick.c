#include <stdio.h>
#include <stdlib.h>

void mergeInPlace(int arr[], int s, int m, int e) {
    int size = e - s;
    int *mix = (int*) malloc(size * sizeof(int));

    int i = s;
    int j = m;
    int k = 0;

    while (i < m && j < e) {
        if (arr[i] < arr[j]) {
            mix[k++] = arr[i++];
        } else {
            mix[k++] = arr[j++];
        }
    }

    while (i < m) {
        mix[k++] = arr[i++];
    }

    while (j < e) {
        mix[k++] = arr[j++];
    }

    // Copy back to original array
    for (int l = 0; l < size; l++) {
        arr[s + l] = mix[l];
    }

    free(mix); // Free dynamically allocated memory
}

void mergeSortInPlace(int arr[], int s, int e) {
    if (e - s <= 1)
        return;

    int mid = (s + e) / 2;

    mergeSortInPlace(arr, s, mid);
    mergeSortInPlace(arr, mid, e);

    mergeInPlace(arr, s, mid, e);
}

// Helper function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



void quickSort(int nums[], int low, int hi) {
    if (low >= hi) {
        return;
    }

    int s = low;
    int e = hi;
    int m = s + (e - s) / 2;
    int pivot = nums[m];

    while (s <= e) {
        while (nums[s] < pivot) {
            s++;
        }
        while (nums[e] > pivot) {
            e--;
        }

        if (s <= e) {
            // Swap nums[s] and nums[e]
            int temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
            s++;
            e--;
        }
    }

    // Recursively sort two halves
    quickSort(nums, low, e);
    quickSort(nums, s, hi);
}




int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // mergeSortInPlace(arr, 0, n);

    // printf("Sorted array: ");
    // printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}






