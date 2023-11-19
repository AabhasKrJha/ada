// binary search using recustion

#include <stdio.h>

int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binary_search_recursive(arr, mid + 1, right, target);
        } else {
            return binary_search_recursive(arr, left, mid - 1, target);
        }
    }

    return -1;
}

int main() {
    printf("Aabhas Kumar Jha - A2305221279\n\n");

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to be found: ");
    scanf("%d", &target);

    int result = binary_search_recursive(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
