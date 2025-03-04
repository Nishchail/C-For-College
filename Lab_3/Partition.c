#include <stdio.h>

// Function to check if a subset with given sum exists
int isSubsetSum(int arr[], int n, int sum) {
    // Base cases
    if (sum == 0) return 1; // Found a subset
    if (n == 0 && sum != 0) return 0; // No elements left

    // If the last element is greater than sum, ignore it
    if (arr[n - 1] > sum) 
        return isSubsetSum(arr, n - 1, sum);

    // Include or exclude the last element
    return isSubsetSum(arr, n - 1, sum) || 
           isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Function to check if the array can be partitioned into two equal subsets
int canPartition(int arr[], int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    // If total sum is odd, partition is not possible
    if (totalSum % 2 != 0)
        return 0;

    // Check if a subset with sum = totalSum / 2 exists
    return isSubsetSum(arr, n, totalSum / 2);
}

// Main function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (canPartition(arr, n))
        printf("Partition into two equal subsets is possible.\n");
    else
        printf("Partition is not possible.\n");

    return 0;
}
