#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adjMatrix[MAX][MAX]; // Adjacency matrix
int visited[MAX];        // Visited array for DFS

// Function to perform DFS traversal
// Done via Recursion (Stack)
void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1; // Mark the vertex as visited

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, vertices);
        }
    }
}

// Function to perform BFS traversal
void BFS(int startVertex, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0}; // Reset visited array

    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    printf("%d ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

// Function to initialize adjacency matrix
void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0; // No edges initially
        }
    }
}

// Main function
int main() {
    int vertices, edges, startVertex;

    // User input: Number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    initializeGraph(vertices);

    // Taking user input for edges
    printf("Enter the edges (format: u v, where u and v are vertex indices starting from 0):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For an undirected graph
    }

    // User input: Start vertex for traversal
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    // DFS Traversal
    printf("DFS Traversal: ");
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0; // Reset visited array before DFS
    }
    DFS(startVertex, vertices);
    printf("\n");

    // BFS Traversal
    printf("BFS Traversal: ");
    BFS(startVertex, vertices);
    printf("\n");

    return 0;
}
