#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};
int opCount = 0;

// Function to get the height of a node
int getHeight(struct Node *n) {
    if (n == NULL) return 0;
    return n->height;
}

// Function to create a new node
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to get the balance factor
int getBalancingFactor(struct Node *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right rotation
struct Node *rotateRight(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Rotate
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation
struct Node *rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Rotate
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a node into AVL tree
struct Node* insertIntoAVL(struct Node* root, int value) {
    opCount++;
    if (root == NULL) return createNode(value);

    if (value < root->key) {
        root->left = insertIntoAVL(root->left, value);
    } else if (value > root->key) {
        root->right = insertIntoAVL(root->right, value);
    } else {
        return root; // No duplicates
    }

    // Update height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Get balance factor
    int balance = getBalancingFactor(root);

    // Perform rotations if unbalanced
    if (balance > 1 && value < root->left->key) {
        return rotateRight(root);
    }
    if (balance < -1 && value > root->right->key) {
        return rotateLeft(root);
    }
    if (balance > 1 && value > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && value < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Preorder traversal
void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start time measurement

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        root = insertIntoAVL(root, value);
    }

    end = clock(); // End time measurement

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nPreorder traversal of AVL tree: ");
    preOrder(root);

    printf("\nTime taken for insertion: %f seconds\n", cpu_time_used);
    printf("Total operations performed: %d\n", opCount);
    return 0;
}
