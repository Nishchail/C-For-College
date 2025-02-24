#include <stdio.h>

#define MAX 100

// Global variables
int maxValue = 0;       // To store the maximum value
int bestSolutions[MAX][MAX]; // To store all best combinations
int bestSolutionCount = 0;   // To track the number of best solutions

// Recursive function to solve the knapsack problem
void knapsack(int capacity, int weights[], int values[], int n, int included[], int currentValue) {
    // Base case: no items or no capacity
    if (n == 0 || capacity == 0) {
        if (currentValue > maxValue) {
            // New maximum value found, reset solutions
            maxValue = currentValue;
            bestSolutionCount = 0;
            for (int i = 0; i < MAX; i++)
                bestSolutions[bestSolutionCount][i] = included[i];
            bestSolutionCount++;
        } else if (currentValue == maxValue) {
            // Another combination with the same maximum value
            for (int i = 0; i < MAX; i++)
                bestSolutions[bestSolutionCount][i] = included[i];
            bestSolutionCount++;
        }
        return;
    }

    // Exclude the current item
    included[n - 1] = 0;
    knapsack(capacity, weights, values, n - 1, included, currentValue);

    // Include the current item if it fits
    if (weights[n - 1] <= capacity) {
        included[n - 1] = 1;
        knapsack(capacity - weights[n - 1], weights, values, n - 1, included, currentValue + values[n - 1]);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[MAX], values[MAX], included[MAX] = {0};

    // Input weights
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    // Input values
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Input knapsack capacity
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Solve the knapsack problem
    knapsack(capacity, weights, values, n, included, 0);

    // Output results
    printf("Maximum value in the knapsack: %d\n", maxValue);
    printf("Knapsack contains the following combinations:\n");
    for (int i = 0; i < bestSolutionCount; i++) {
        printf("Combination %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            if (bestSolutions[i][j] == 1) {
                printf("Item %d (Value %d) ", j + 1, values[j]);
            }
        }
        printf("\n");
    }

    return 0;
}

