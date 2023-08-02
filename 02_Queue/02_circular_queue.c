#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rear;
    int *arr;
    int size;
};
void intialize(struct queue *top)
{
    top->front = -1;
    top->rear = -1;
}
int isEmpty(struct queue *top2)
{
    return top2->rear == -1 && top2->front == -1;
}
int isFull(struct queue *top1)
{
    return ((top1->rear + 1) % top1->size == top1->front);
}
void enqueue(struct queue *top, int data)
{
    if (isFull(top))
    {
        printf("Qeueu is Full");
        return;
    }
    if (isEmpty(top))
    {
        top->front = 0;
    }

    top->rear = (top->rear + 1) % top->size;
    top->arr[top->rear] = data;
}
void dequeue(struct queue *top)
{
    if (isEmpty(top))
    {
        printf("queue is empty");
        return;
    }
    if (top->front == top->rear)
    {
        top->front = -1;
        top->rear = -1;
    }
    else
    {
        top->front = (top->front + 1) % top->size;
    }
}
void display(struct queue *top)
{
    if (isEmpty(top))
    {
        return;
    }
    int i = top->front;
    while (1)
    {
        printf("%d\n", top->arr[i]);
        if (i == top->rear)
        {
            break;
        }
        i = (i + 1) % top->size;
    }
}
int main()
{
    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    head->size = 5;
    int *arr = (int *)malloc(sizeof(int));
    enqueue(head, 10);
    enqueue(head, 20);
    enqueue(head, 40);
    enqueue(head, 30);

    dequeue(head);

    // After removing the element from the queue
    display(head);
}