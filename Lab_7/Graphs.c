#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition of a BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

int opcount = 0; // Operation count

// Function to create a new node
struct Node* createNode(int value) {
    opcount++;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    opcount++;
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    opcount++;
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    opcount++;
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Main function to test the BST operations with user input
int main() {
    struct Node* root = NULL;
    int n, value;
    clock_t start, end;
    double time_taken;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements: ");
    start = clock();
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Displaying elements using inorder traversal
    printf("\nInorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    // Displaying elements using preorder traversal
    printf("\nPreorder traversal: ");
    preorderTraversal(root);
    printf("\n");
    
    printf("\nTotal operations performed: %d", opcount);
    printf("\nTime taken for insertion and traversal: %f seconds\n", time_taken);
    
    return 0;
}