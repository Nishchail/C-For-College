#include <stdio.h>
#include <time.h>

int opcount = 0; // Operation count

void counting_sort(int A[], int n) {
    int i, j;
    int S[n], C[n];

    // Initialize count array
    for (i = 0; i < n; i++) {
        C[i] = 0;
        opcount++;
    }

    // Count occurrences
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            opcount++;
            if (A[i] < A[j])
                C[j]++;
            else
                C[i]++;
        }
    }

    // Build sorted array
    for (i = 0; i < n; i++) {
        S[C[i]] = A[i];
        opcount++;
    }

    // Print sorted array
    printf("The Sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", S[i]);
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the integers to be sorted:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    counting_sort(A, n);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total operations (Opcount): %d\n", opcount);
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
