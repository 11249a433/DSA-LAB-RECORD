#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int newData) {
    struct Node* newNode = malloc(sizeof(struct Node)), *last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if (!*head) {
        *head = newNode;
        return;
    }
    while (last->next) last = last->next;
    last->next = newNode;
}

void insertAtMiddle(struct Node** head, int newData, int pos) {
    if (pos < 0) return;
    struct Node* newNode = malloc(sizeof(struct Node)), *temp = *head;
    newNode->data = newData;
    if (pos == 0) { insertAtBeginning(head, newData); return; }
    for (int i = 0; temp && i < pos-1; i++) temp = temp->next;
    if (!temp) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;
    if (temp && temp->data == key) { *head = temp->next; free(temp); return; }
    while (temp && temp->data != key) { prev = temp; temp = temp->next; }
    if (!temp) return;
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 5);
    insertAtMiddle(&head, 15, 1);
    printList(head); 

    deleteNode(&head, 10);
    printList(head); 

    deleteNode(&head, 100);
    printList(head); 

    return 0;
}

