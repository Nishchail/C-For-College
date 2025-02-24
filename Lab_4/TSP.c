#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX];  // Adjacency matrix for distances
int visited[MAX];     // Array to track visited cities
int n;                // Number of cities
int minCost = INT_MAX;

// Function to solve TSP using brute force
void tsp(int city, int count, int cost, int startCity) {
    // Base case: all cities have been visited
    if (count == n && graph[city][startCity] > 0) {
        int totalCost = cost + graph[city][startCity];  // Include return to start city
        if (totalCost < minCost) {
            minCost = totalCost;  // Update minimum cost
        }
        return;
    }

    // Visit all unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[city][i] > 0) { // Check for unvisited city and valid path
            visited[i] = 1;         // Mark city as visited
            tsp(i, count + 1, cost + graph[city][i], startCity);  // Recursive call
            visited[i] = 0;         // Backtrack (unmark the city)
        }
    }
}

int main() {
    // Input the number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    // Input the distance matrix
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Start the TSP from city 0
    visited[0] = 1;
    tsp(0, 1, 0, 0);

    // Print the result
    printf("The minimum cost of the TSP is: %d\n", minCost);

    return 0;
}
