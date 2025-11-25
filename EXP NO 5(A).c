#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;
int isEmpty() 
{
    return size == 0;
}
int isFull() 
{
    return size == MAX;
}
void enqueue(int item) 
{
    if (isFull()) 
	{
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = item;
    size++;
    printf("Enqueued: %d\n", item);
}
int dequeue() 
{
    if (isEmpty()) 
	{
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  
    }
    int item = queue[front];
    front = (front + 1) % MAX;
    size--;
    printf("Dequeued: %d\n", item);
    return item;
}
int peek() {
    if (isEmpty()) {
        printf("Queue is empty! Nothing to peek.\n");
        return -1;
    }
    return queue[front];
}
void display() {
    if (isEmpty()) 
	{
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front,count;
    for (count = 0; count < size; count++)
	{
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    printf("Front element is: %d\n", peek());
    return 0;
}

