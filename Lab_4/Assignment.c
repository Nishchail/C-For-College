#include <stdio.h>
#include <limits.h>

#define MAX 10

int costMatrix[MAX][MAX];  // Cost matrix for assignment problem
int n;                     // Number of tasks/workers
int visited[MAX];          // Tracks visited workers
int minCost = INT_MAX;     // Stores the minimum assignment cost

// Recursive function to solve the Assignment Problem
void solveAssignment(int task, int currentCost) {
    // Base case: All tasks are assigned
    if (task == n) {
        if (currentCost < minCost) {
            minCost = currentCost;  // Update the minimum cost
        }
        return;
    }

    // Try assigning the current task to all available workers
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {  // Check if worker `i` is not already assigned
            visited[i] = 1; // Mark worker `i` as assigned
            solveAssignment(task + 1, currentCost + costMatrix[task][i]);
            visited[i] = 0; // Backtrack to try other assignments
        }
    }
}
int main() {
    // Input number of tasks/workers
    printf("Enter the number of tasks/workers: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Solve the problem starting with the first task
    solveAssignment(0, 0);

    // Output the minimum cost
    printf("The minimum assignment cost is: %d\n", minCost);

    return 0;
}
