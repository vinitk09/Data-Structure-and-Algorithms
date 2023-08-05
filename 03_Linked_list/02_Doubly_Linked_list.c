#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
void Forwardtraversal(struct node *head)
{
    struct node *curr = head;
    printf("Forward Traversal\n");
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->next;
    }
}
void Backwardtraversal(struct node *head1)
{
    struct node *curr = head1;
    while (curr->next != NULL)
    {

        // printf("%d\t", curr->data);
        curr = curr->next;
    }
    printf("\nBAckward Traversal\n");
    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->prev;
    }
}
struct node *insertatbegin(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *curr = head;
    newnode->next = curr;
    newnode->data = value;
    curr->prev = newnode;
    newnode->prev = NULL;
    head = newnode;
    return head;
}
struct node *insertatlast(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *curr = head;
    // newnode->next = curr;
    newnode->data = value;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    newnode->prev = curr;
    newnode->next = NULL;

    return head;
}
struct node *insertatpos(struct node *head, int value, int pos)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (pos == 0)
    {
        newnode->next = head;
        if (head != NULL)
        {
            head->prev = newnode;
        }
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        int i = 0;
        while (temp != NULL && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            free(newnode);
            // return 1;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
    return head;
}
struct node *deleteatpos(struct node *head, int pos)
{
    // struct node *newnode = (struct node *)malloc(sizeof(struct node));
    // newnode->next = NULL;
    // newnode->prev = NULL;
    struct node *temp = head;
    if (pos == 1)
    {
        if (head != NULL)
        {
            head->next->prev = NULL;
            return head->next;
        }
    }
    else if (pos == 4)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        return head;
    }
    else
    {
        int i = 0;
        while (temp != NULL && i < pos - 1) // 0 1
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    return head;
}
// struct node *deletelast(struct node *head)
// {
// }
// struct node *reverse(struct node *head)
// {
// }
int main()
{
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    first->data = 1;
    first->next = second;
    first->prev = NULL;

    second->data = 4;
    second->next = third;
    second->prev = first;

    third->data = 6;
    third->next = fourth;
    third->prev = second;

    fourth->data = 2;
    fourth->prev = third;
    fourth->next = NULL;

    // Insert at first
    // first = insertatbegin(first, 10);

    // Insert at last
    // first = insertatlast(first, 12);

    // Insert at any index
    // first = insertatpos(first, 14, 1);

    // delete at any given index
    first = deleteatpos(first, 4);

    Forwardtraversal(first);

    Backwardtraversal(first);
}
