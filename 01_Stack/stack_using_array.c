#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *item;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *pus, int data)
{
    if (isFull(pus))
    {
        printf("Stack Overflow");
    }
    else
    {
        pus->top++;
        pus->item[pus->top] = data;
    }
}
void pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack is Empty");
    }
    p->item[p->top--];
}
int peek(struct stack *p, int pos)
{
    if (isEmpty(p))
    {
        printf("Stack is Empty");
        return -1;
    }
    if (pos < 0)
    {
        return -1;
    }
    if (pos <= p->top)
        return p->item[pos];
}
void displaystack(struct stack *h)
{
    for (int i = h->top; i >= 0; i--)
    {
        printf("%d\n", h->item[h->top]);
        h->top--;
    }
}
int main()
{
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));

    head->size = 10;
    head->top = -1;
    head->item = (int *)malloc(head->size * sizeof(int));

    // To push the element in the stack

    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);

    // To pop the element from the stack and also it works on the LIFO (Last in First Out) principle.
    // The element 50 will be poped first and then 40 and rest.

    // pop(head);
    // pop(head);
    // pop(head);
    displaystack(head);
}
