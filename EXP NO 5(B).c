#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Queue 
{
    struct Node* front;
    struct Node* rear;
};
struct Node* newNode(int value) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int value) 
{
    struct Node* temp = newNode(value);
    if (q->rear == NULL) 
	{
        q->front = q->rear = temp;
        printf("%d enqueued to queue\n", value);
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("%d enqueued to queue\n", value);
}
int dequeue(struct Queue* q) 
{
    if (q->front == NULL) 
	{
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    printf("%d dequeued from queue\n", value);
    return value;
}
int peek(struct Queue* q) 
{
    if (q->front == NULL) 
	{
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}
void display(struct Queue* q) 
{
    struct Node* temp = q->front;
    if (temp == NULL) 
	{
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
 {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Front element is %d\n", peek(q));
    dequeue(q);
    dequeue(q);
    display(q);
    dequeue(q);
    dequeue(q);
    return 0;
}

