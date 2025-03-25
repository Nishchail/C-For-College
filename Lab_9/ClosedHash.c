#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Function to initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = EMPTY;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key using linear probing
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {
            printf("Hash table is full!\n");
            return;
        }
    }
    hashTable[index] = key;
}

// Function to search for a key and count key comparisons
int search(int key, int *comparisons) {
    int index = hashFunction(key);
    int originalIndex = index;
    *comparisons = 0;
    while (hashTable[index] != EMPTY) {
        (*comparisons)++;
        if (hashTable[index] == key)
            return index; // Key found
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex)
            break;
    }
    return -1; // Key not found
}

// Function to print the hash table
void printTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("%d: %d\n", i, hashTable[i]);
}

int main() {
    initializeTable();
    int keys[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    // Insert keys into the hash table
    for (int i = 0; i < n; i++)
        insert(keys[i]);
    
    printTable();
    
    // Perform successful search
    int comparisons = 0;
    int keyToSearch = keys[n / 2]; // Searching an existing key
    int result = search(keyToSearch, &comparisons);
    if (result != -1)
        printf("Successful search for key %d at index %d with %d comparisons\n", keyToSearch, result, comparisons);
    else
        printf("Key %d not found!\n", keyToSearch);
    
    // Perform unsuccessful search
    int unsuccessfulKey = 1000; // A key not in the table
    result = search(unsuccessfulKey, &comparisons);
    if (result == -1)
        printf("Unsuccessful search for key %d with %d comparisons\n", unsuccessfulKey, comparisons);
    
    return 0;
}
