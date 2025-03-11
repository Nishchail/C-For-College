#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert_count = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftUp(int arr[], int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && arr[parent] < arr[index]) {
        swap(&arr[parent], &arr[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(int arr[], int *n, int value) {
    arr[*n] = value;
    siftUp(arr, *n);
    (*n)++;
    insert_count++;
}

void buildHeap(int arr[], int n) {
    int heapSize = 0;
    int *heap = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        insert(heap, &heapSize, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = heap[i];
    }
    free(heap);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    buildHeap(arr, n);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\nHeap constructed: ");
    printArray(arr, n);
    printf("Insert function called: %d time(s)\n", insert_count);
    printf("Time taken: %f seconds\n", time_taken);
    
    free(arr);
    return 0;
}
