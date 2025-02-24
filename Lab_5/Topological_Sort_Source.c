#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int vertices;
int adjMatrix[MAX][MAX];
int inDegree[MAX];
int topologicalOrder[MAX];

void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1; 
    inDegree[dest]++;      
}

// Function to perform Topological Sorting using Source Removal (Kahn's Algorithm)
// BFS WALA tarika
void topologicalSort() {
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    // Enqueue all nodes with in-degree 0
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process queue
    while (front < rear) {
        int node = queue[front++];
        topologicalOrder[count++] = node;

        // Reduce in-degree of adjacent nodes
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[node][i] == 1) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topologicalOrder[i]);
    }
    printf("\n");
}


int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
        inDegree[i] = 0;
    }

    printf("Enter edges (format: src dest, meaning src → dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    topologicalSort();

    return 0;
}
