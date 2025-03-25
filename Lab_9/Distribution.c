#include <stdio.h>
#include <time.h>

int opcount = 0; // Operation count

void distributionCountingSort(int arr[], int n) {
    int i, max = arr[0], min = arr[0];

    // Find max and min element
    for (i = 1; i < n; i++) {
        opcount++; // Count comparison
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    int range = max - min + 1;
    int count[range], output[n];

    // Initialize count array
    for (i = 0; i < range; i++) {
        count[i] = 0;
        opcount++;
    }

    // Store count of each number
    for (i = 0; i < n; i++) {
        count[arr[i] - min]++;
        opcount++;
    }

    // Compute cumulative count
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
        opcount++;
    }

    // Place elements in sorted order
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
        opcount++;
    }

    // Copy sorted elements back to original array
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        opcount++;
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d positive integers: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    distributionCountingSort(arr, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Total operations (Opcount): %d\n", opcount);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
