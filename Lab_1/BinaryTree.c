#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

// Function to search for a key in the BST and insert if not found
struct Node* searchAndInsert(struct Node* root, int key) {
    // If the tree is empty, create a new node as the root
    if (root == NULL) {
        printf("Key not found. Inserting %d into the BST.\n", key);
        return createNode(key);
    }

    // If the key is found, print message and return the root
    if (key == root->data) {
        printf("Key found\n");
        return root;
    }
    
    // If the key is smaller, search in the left subtree
    if (key < root->data)
        root->left = searchAndInsert(root->left, key);
    else // If the key is greater, search in the right subtree
        root->right = searchAndInsert(root->right, key);

    return root;
}

// Function to perform an inorder traversal (left-root-right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Driver Code
int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\n1. Search and Insert\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to search/insert: ");
                scanf("%d", &key);
                root = searchAndInsert(root, key);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
