#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Opcount = 0;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot && i <= high)
        {
            i++;
        }
        while (A[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    Opcount++;
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    clock_t start, end;
    double cpu_time_used;

    printf("Original Array: ");
    printArray(A, n);

    start = clock();
    quickSort(A, 0, n - 1);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");
    printArray(A, n);
    printf("Opcount: %d\n", Opcount);
    printf("Time taken: %f seconds\n", cpu_time_used);

    free(A);
    return 0;
}