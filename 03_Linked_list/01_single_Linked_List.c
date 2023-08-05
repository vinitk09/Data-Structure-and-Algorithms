#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// traversal of the Linked List
void traversal(struct node *head)
{
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
}

// Insert at Begining of the linked list
struct node *insertatbegin(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    // struct node *curr = head;
    newnode->next = head;
    head = newnode;
    return newnode;
}

// Insert at the end of the linked list
struct node *insertatend(struct node *head, int value)
{
    struct node *curr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    while (curr != NULL)
    {
        curr = curr->next;
        if (curr->next == NULL)
        {
            curr->next = newnode;
            // head = curr;
            return head;
        }
    }
}
// Insert at any given position of the linked list
struct node *insertatpos(struct node *head, int pos, int value)
{
    struct node *curr = head;
    struct node *temp = curr;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    // newnode->data = value;
    int i = 0;

    while (i != pos - 1)
    {
        // struct node *temp = curr;
        curr = curr->next;
        i++;
    }
    newnode->data = value;
    newnode->next = curr->next;
    curr->next = newnode;
    return head;
}
// void deletelinkedlist(struct node *head)
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
    // first = insertatbegin(first, 8);
    // first = insertatend(first, 10);
    first = insertatpos(first, 1, 4);
    traversal(first);
}
