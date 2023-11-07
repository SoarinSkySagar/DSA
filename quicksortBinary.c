#include <stdio.h>
#include <stdlib.h>

// Function to create an array dynamically and sort it using quicksort
int *createAndSortArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array immediately after creation
    quicksort(arr, 0, size - 1);

    return arr;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for quicksort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to implement quicksort
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

// Function to perform binary search
int binarySearch(int *arr, int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Element found
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = createAndSortArray(size);

    printf("Array created and sorted in ascending order.\n");
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element you want to search for: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    free(arr);

    return 0;
}
