#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node* tree) {
    if (tree == NULL)
        return 0;

    int lHeight = height(tree->left);
    int rHeight = height(tree->right);

    // level Order traversal ho raha hai yah tak toh 

    int lDiameter = diameter(tree->left);
    int rDiameter = diameter(tree->right);

    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of the tree is %d\n", diameter(root));

    return 0;
}