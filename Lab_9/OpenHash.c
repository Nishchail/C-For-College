#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 200

// Structure for a node in the linked list
typedef struct Node {
    int key;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a key into the hash table
void insert(Node *hashTable[], int m, int key) {
    int index = key % m;
    Node *newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to search for a key in the hash table
int search(Node *hashTable[], int m, int key, int *comparisons) {
    int index = key % m;
    Node *current = hashTable[index];
    *comparisons = 0;
    while (current) {
        (*comparisons)++;
        if (current->key == key)
            return 1; // Successful search
        current = current->next;
    }
    return 0; // Unsuccessful search
}

// Function to initialize the hash table
void initializeTable(Node *hashTable[], int m) {
    for (int i = 0; i < m; i++)
        hashTable[i] = NULL;
}

// Function to print the hash table
void printTable(Node *hashTable[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%d: ", i);
        Node *current = hashTable[i];
        while (current) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int tableSizes[] = {10, 20, 50}; // Different hash table sizes
    int keyCounts[] = {50, 100, 200}; // Different key counts (load factor variation)
    
    for (int t = 0; t < 3; t++) { // Iterate through different table sizes
        int m = tableSizes[t];
        printf("\nHash Table Size: %d\n", m);
        
        for (int k = 0; k < 3; k++) { // Iterate through different key counts
            int n = keyCounts[k];
            printf("\nNumber of keys inserted: %d\n", n);
            
            Node *hashTable[m];
            initializeTable(hashTable, m);
            
            int keys[MAX_KEYS];
            for (int i = 0; i < n; i++)
                keys[i] = rand() % 1000; // Generate random keys
            
            for (int i = 0; i < n; i++)
                insert(hashTable, m, keys[i]);
            
            // Perform successful search
            int comparisons = 0;
            search(hashTable, m, keys[n / 2], &comparisons);
            printf("Successful search comparisons: %d\n", comparisons);
            
            // Perform unsuccessful search
            int unsuccessfulKey = 10000; // A key unlikely to be in the table
            search(hashTable, m, unsuccessfulKey, &comparisons);
            printf("Unsuccessful search comparisons: %d\n", comparisons);
        }
    }
    return 0;
}