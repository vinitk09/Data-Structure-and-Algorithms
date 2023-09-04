#include <stdio.h>
#include <stdlib.h>

struct valid_parenthesis
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct valid_parenthesis *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct valid_parenthesis *ptr)
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
void push(struct valid_parenthesis *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack is Full\n");
    }
    else
    {
        ptr->arr[ptr->top++] = val;
    }
}
char pop(struct valid_parenthesis *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isMatch(char *exp)
{
    struct valid_parenthesis *sp;
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "{{(*89))}}";
    if (isMatch(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}
