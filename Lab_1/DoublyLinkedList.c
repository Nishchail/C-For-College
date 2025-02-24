#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node * createNode(int data) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void linkedListTraversal(struct Node * head) {
    struct Node * ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != NULL);
    printf("\n");
}

struct Node * insertAtFirst(struct Node * head, int data) {
    struct Node * newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;

    }
    return head;
}

struct Node * insertAtKey(struct Node * head, int data, int key) {
    struct Node * newNode = createNode(data);
    struct Node * ptr = head;
    while(ptr->data != key) {
        ptr = ptr->next;
        if(ptr == NULL) {
            printf("Key not found in the list\n");
            return head;
        }
    }
    // Link establishment ke lia rakhi gai hai yeh line
    newNode->next = ptr->next;
    // Final Insertion ke lia yeh line
    ptr->next = newNode;
    return head;
}

void search(struct Node * head, int key) {
    struct Node * ptr = head;
    int index = 0;
    while(ptr->data != key) {
        ptr = ptr->next;
        index++;
        if(ptr == NULL) {
            printf("Key not found in the list\n");
            return;
        }
    }
    printf("Key found at index %d\n", index);
}

void display (struct Node * head) {
    struct Node * ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != NULL);
    printf("\n");
}


void main(){
    struct Node * head = NULL;
    head = insertAtFirst(head, 10);
    head = insertAtFirst(head, 20);
    head = insertAtFirst(head, 30);
    head = insertAtFirst(head, 40);
    head = insertAtFirst(head, 50);
    head = insertAtFirst(head, 60);
    head = insertAtFirst(head, 70);
    head = insertAtFirst(head, 80);
    head = insertAtFirst(head, 90);
    head = insertAtFirst(head, 100);
    linkedListTraversal(head);
    head = insertAtKey(head, 25, 20);
    linkedListTraversal(head);
    search(head, 25);
    search(head, 1000);
    display(head);
}