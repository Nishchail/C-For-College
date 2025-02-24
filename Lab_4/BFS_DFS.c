#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

int adjMatrix[MAX][MAX]; 
int visited[MAX];        

// Function to perform DFS traversal
// Done via Recursion (Stack)
void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1; 

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && visited[i] == 0) {
            DFS(i, vertices);
        }
    }
}

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

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0; // No edges initially
        }
    }
}

int main() {
    int vertices, edges, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeGraph(vertices);

    printf("Enter the edges (format: u v, where u and v are vertex indices starting from 0):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For an undirected graph
    }

    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0; // Reset visited array before DFS
    }
    DFS(startVertex, vertices);
    printf("\n");

    printf("BFS Traversal: ");
    BFS(startVertex, vertices);
    printf("\n");

    return 0;
}
