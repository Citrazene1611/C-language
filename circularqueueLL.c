#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if(front == NULL)
    {
        front = rear = newNode;
        newNode->next = front;
    }
    else
    {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    if(front == rear)
    {
        printf("%d deleted\n", front->data);
        free(front);

        front = rear = NULL;
    }
    else
    {
        temp = front;

        printf("%d deleted\n", front->data);

        front = front->next;
        rear->next = front;

        free(temp);
    }
}

void display()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != front);

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

    return 0;
}