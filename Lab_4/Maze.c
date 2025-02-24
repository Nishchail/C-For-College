#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

int adjMatrix[MAX][MAX];  
int visited[MAX];         
int n;                    

// Function to initialize adjacency matrix
void initializeMatrix(int vertices) {
    n = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;  
        }
        visited[i] = 0; 
    }
}
void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;  
}

void printMatrix() {
    printf("\nAdjacency Matrix Representation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void DFS(int current, int end) {
    printf("%d ", current);  
    visited[current] = 1;    

    if (current == end) {  
        printf("\nPath Found!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (adjMatrix[current][i] == 1 && !visited[i]) {  
            DFS(i, end);
            return;  
        }
    }
}

int main() {
    int vertices, edges, start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    initializeMatrix(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (format: src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("Enter start and end vertices: ");
    scanf("%d %d", &start, &end);

    printMatrix();

    printf("\nDFS Maze Path: ");
    DFS(start, end);

    return 0;
}
