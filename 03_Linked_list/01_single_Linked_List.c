#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *head)
{
    struct node *curr = head;
    while (curr->next != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
}

struct node *insertatbegin(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    // struct node *curr = head;
    newnode->next = head;
    head = newnode;
    // return newnode;
}
int main()
{
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 5;
    third->next = fourth;

    fourth->data = 6;
    fourth->next = NULL;

    // insertatbegin(first, 8);
    traversal(first);
}
