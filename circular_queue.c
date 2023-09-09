#include <stdio.h>
#include <stdlib.h>
int front = -1;
int rear = -1;
#define n 5
void enqueue(int *circularqueue)
{
    if (front == -1 && rear == -1)
    {
        int item;
        front = rear = 0;
        printf("Enter item to be inserted1\n");
        scanf("%d", &item);
        circularqueue[rear] = item;
    }
    else if ((rear + 1) % n == front)
    {
        printf("Queue is full");
    }
    else
    {
        int item;
        rear = (rear + 1) % n;
        printf("Enter item to be inserted\n");
        scanf("%d", &item);
        circularqueue[rear] = item;
    }
}

void dequeue(int *circularqueue)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued item is %d\n", circularqueue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Dequeued item is %d\n", circularqueue[front]);
        printf("%d %d\n", front, rear);
        front = (front + 1) % n;
        printf("%d %d\n", front, rear);
    }
}
void peek(int *circularqueue)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {

        printf("The item at front is %d\n", circularqueue[front]);
    }
}

void display(int *circularqueue)
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("queue is empty.\n");
    }
    else
    {
        printf("The elements are :");
        while (i != rear)
        {
            printf("%d ,", circularqueue[i]);
            i =(i+1)%n;
        }
        printf("%d.\n",circularqueue[rear]);
    }
}

int main()
{
    // int n;
    int choise;
    //  printf("Enter the size of circlar queue \n");
    //  scanf("%d", &n);
    printf("Array impementation of circular queue___\n");
    printf("****Main menu****\n");
    int circluarque[n];
    while (choise != 5)
    {

        printf("Enter your choise \n1.Enqueue\n2.Dequeue\n3.peek\n4.display\n5.Exit\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
        {
            enqueue(circluarque);
            break;
        }
        case 2:

        {
            dequeue(circluarque);
            break;
        }
        case 3:
        {
            peek(circluarque);
            break;
        }

        case 4:
        {
            display(circluarque);
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
            printf("Enter a valid response .");
        }
    }
    return 0;
}