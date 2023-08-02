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
    return top2->rear == top2->front;
}
int isFull(struct queue *top1)
{
    return top1->rear == top1->size - 1;
}
void enqueue(struct queue *top, int data)
{
    if (isFull(top))
    {
        printf("Qeueu is Full");
    }
    else
    {
        top->arr[top->rear++] = data;
    }
}
void dequeue(struct queue *top)
{
    if (isEmpty(top))
    {
        printf("Queue is Empty");
    }
    else
    {
        int deq = top->arr[top->front];
        top->front++;
        printf("The Dequed element is :  %d \n", deq);
    }
}
void display(struct queue *top)
{
    if (isEmpty(top))
    {
        return;
    }
    for (int i = top->front; i < top->rear; i++)
    {
        printf("%d\n", top->arr[i]);
    }
}
int main()
{
    struct queue *head = (struct queue *)malloc(sizeof(struct queue));
    intialize(head);
    int *arr = (int *)malloc(sizeof(int));
    head->size = 5;
    enqueue(head, 10);
    enqueue(head, 20);
    enqueue(head, 30);
    enqueue(head, 40);
    enqueue(head, 50);
    dequeue(head);
    printf("The Elements in the queue are :\n");
    display(head);
}