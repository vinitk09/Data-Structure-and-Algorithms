#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
void traversal(struct node *head)
{
    struct node *curr = head;
    while (curr->next != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
    printf("%d\t", curr->data);
    curr->next = head;
}

struct node *insertatpos(struct node *head, int pos, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    struct node *temp = head;
    newnode->data = value;
    if (pos == 0)
    {
        newnode->next = temp;
        head = newnode;
        return head;
    }
    else
    {
        int i = 0;
        while (temp != NULL && i != pos - 1)
        {
            temp = temp->next;
            i++;
        }
        // newnode->data = value;
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }
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

    first = insertatpos(first, 3, 4);
    traversal(first);
}