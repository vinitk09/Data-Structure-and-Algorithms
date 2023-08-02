#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation error");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void push(struct node **top, int data)
{
    struct node *newnode = createnode(data);
    newnode->next = *top;
    *top = newnode;
}
int isEmpty(struct node *top)
{
    return (top == NULL);
}
void display(struct node *top)
{
    if (isEmpty(top))
    {
        return;
    }
    struct node *current = top;
    printf("The Elements in the stack are\n");
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
        printf("\n");
    }
}
int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        return -1;
    }
    int data = (*top)->data;
    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}
int peek(struct node *top)
{
    if (isEmpty(top))
    {
        return -1;
    }
    return top->data;
}
int main()
{
    struct node *top = NULL;
    printf("Enter the size of the element");
    int size;
    scanf("%d", &size);
    printf("Enter the elements in the stack");
    for (int i = 0; i < size; i++)
    {
        int ele;
        scanf("%d", &ele);
        push(&top, ele);
    }

    // push(&top, 10);
    // push(&top, 10);
    // push(&top, 10);

    // pop(&top);
    peek(top); // To display the top element in the stack.
    display(top);
}
