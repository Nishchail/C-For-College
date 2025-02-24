#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};

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

// Function to get maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the balance factor
int getBalancingFactor(struct Node *n) {
    if (n == NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Right rotation (corrected)
struct Node *rotateRight(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Left rotation (corrected)
struct Node *rotateLeft(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

// Function to insert a node into AVL tree
struct Node* insertIntoBST(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->key) {
        root->left = insertIntoBST(root->left, value);
    } else if (value > root->key) {
        root->right = insertIntoBST(root->right, value);
    } else {
        return root; // Duplicates not allowed
    }

    // Update height of this ancestor node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Get balance factor
    int balance = getBalancingFactor(root);

    // **Perform Rotations if Unbalanced**

    // Left-Left (LL) Case
    if (balance > 1 && value < root->left->key) {
        return rotateRight(root);
    }

    // Right-Right (RR) Case
    if (balance < -1 && value > root->right->key) {
        return rotateLeft(root);
    }

    // Left-Right (LR) Case
    if (balance > 1 && value > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right-Left (RL) Case
    if (balance < -1 && value < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Function to print preorder traversal
void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    // Insert elements into AVL Tree
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 25);

    // Preorder traversal
    printf("Preorder traversal of the AVL tree: ");
    preOrder(root);

    return 0;
}
