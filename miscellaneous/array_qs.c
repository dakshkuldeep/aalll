#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;   
}

void printarr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int part = partition(arr, low, high);
        quicksort(arr, low, part - 1);
        quicksort(arr, part + 1, high);
    }
}

int main() {

    int arr[] = {5,1,6,8,4,2,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("unsorted:\n");
    printarr(arr, size);

    quicksort(arr, 0, size-1); // 2nd and 3rd arguments are index values 

    printf("sorted:\n");
    printarr(arr, size);
    return 0;
}