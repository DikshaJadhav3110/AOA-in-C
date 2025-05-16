#include <stdio.h>

// ---------- Typedef for MinMax Struct ----------
typedef struct {
    int min;
    int max;
} MinMax;

// ---------- MinMax using Divide and Conquer ----------
MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;

    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

// ---------- Binary Search ----------
int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// ---------- Main Function ----------
int main() {
    int arr[] = {3, 7, 1, 9, 4, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // --- MinMax ---
    MinMax result = findMinMax(arr, 0, size - 1);
    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    // --- Binary Search ---
    // Binary Search needs sorted array
    int sorted[] = {1, 2, 3, 4, 7, 8, 9};
    int target = 4;
    int index = binarySearch(sorted, 0, size - 1, target);

    if (index != -1)
        printf("Element %d found at index %d (in sorted array)\n", target, index);
    else
        printf("Element %d not found\n", target);

    return 0;
}
