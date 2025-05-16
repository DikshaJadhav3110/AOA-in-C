#include <stdio.h>
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // element to insert
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        { // move elements right
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // insert key
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i< n ;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main()
{
    int arr[] = {15, 78, 1, 2, 3, 47, 9, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}