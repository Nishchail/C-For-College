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

int getHeight(struct Node* root) {
    opCount++;
    if (root == NULL) {
        return -1; 
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct Node* root = NULL;
    int n, data;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of nodes in BST: ");
    scanf("%d", &n);

    printf("Enter the node values: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    start = clock();
    int height = getHeight(root);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Height of BST: %d\n", height);
    printf("Time taken to calculate height: %f seconds\n", cpu_time_used);
    printf("Opcount = " , &opCount);

    return 0;
}
