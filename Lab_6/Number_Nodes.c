#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opCount = 0 ;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}



int countNodes(struct Node* root) {
    opCount++;
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int data;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter node values (enter -1 to stop): \n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        root = insert(root, data);
    }

    start = clock();
    int totalNodes = countNodes(root);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total number of nodes in BST: %d\n", totalNodes);
    printf("Time taken to count nodes: %f seconds\n", cpu_time_used);
    printf("Opcount is : " , opCount);

    return 0;
}
