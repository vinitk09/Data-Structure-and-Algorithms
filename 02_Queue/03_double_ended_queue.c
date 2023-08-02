#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create an empty deque
struct Deque *createDeque()
{
    struct Deque *deque = (struct Deque *)malloc(sizeof(struct Deque));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *deque)
{
    return (deque->front == -1);
}

// Function to check if the deque is full
int isFull(struct Deque *deque)
{
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) ||
            (deque->front == deque->rear + 1));
}

// Function to add an element to the front of the deque
void insertFront(struct Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }

    if (isEmpty(deque))
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->front == 0)
    {
        deque->front = MAX_SIZE - 1;
    }
    else
    {
        deque->front--;
    }

    deque->items[deque->front] = value;
}

// Function to add an element to the rear of the deque
void insertRear(struct Deque *deque, int value)
{
    if (isFull(deque))
    {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }

    if (isEmpty(deque))
    {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->rear == MAX_SIZE - 1)
    {
        deque->rear = 0;
    }
    else
    {
        deque->rear++;
    }

    deque->items[deque->rear] = value;
}

// Function to remove an element from the front of the deque
void deleteFront(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Cannot delete from front.\n");
        return;
    }

    if (deque->front == deque->rear)
    {
        // Deque has only one element, reset front and rear
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->front == MAX_SIZE - 1)
    {
        deque->front = 0;
    }
    else
    {
        deque->front++;
    }
}

// Function to remove an element from the rear of the deque
void deleteRear(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty. Cannot delete from rear.\n");
        return;
    }

    if (deque->front == deque->rear)
    {
        // Deque has only one element, reset front and rear
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->rear == 0)
    {
        deque->rear = MAX_SIZE - 1;
    }
    else
    {
        deque->rear--;
    }
}

// Function to get the front element of the deque
int getFront(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->items[deque->front];
}

// Function to get the rear element of the deque
int getRear(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty.\n");
        return -1;
    }
    return deque->items[deque->rear];
}

// Function to display the elements of the deque
void display(struct Deque *deque)
{
    if (isEmpty(deque))
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = deque->front;
    while (1)
    {
        printf("%d ", deque->items[i]);
        if (i == deque->rear)
        {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// Function to free the memory allocated for the deque
void freeDeque(struct Deque *deque)
{
    free(deque);
}

int main()
{
    struct Deque *deque = createDeque();

    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);

    display(deque);

    deleteFront(deque);
    display(deque);

    deleteRear(deque);
    display(deque);

    freeDeque(deque);
    return 0;
}
