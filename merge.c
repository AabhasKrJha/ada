// merge sort

#include <stdio.h>

// Function to merge two sorted arrays
void merge(int arr[], int low, int mid, int high) {
    int left_size = mid - low + 1;
    int right_size = high - mid;

    int left_array[left_size], right_array[right_size];

    for (int i = 0; i < left_size; i++)
        left_array[i] = arr[low + i];
    for (int j = 0; j < right_size; j++)
        right_array[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < left_size && j < right_size) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Aabhas Kumar Jha - A2305221279\n\n");
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
