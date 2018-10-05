#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int main()
{
    struct node *top = NULL;
    push(&top , 4);
    push(&top , 3);
    push(&top , 2);
    push(&top , 1);
    print(top);
}

void push(struct node **top , int value)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->value = value;
    ptr->next = NULL;
    if(*top == NULL)
    {
        *top = ptr;
    }
    else
    {
        ptr->next = *top;
        *top = ptr;
    }
}

int pop(struct node **top)
{
    struct node *temp = *top;
    *top = (*top)->next;
    free(top);
    return temp->value;
}

void print(struct node *top)
{
    while(top != NULL)
    {
        printf("%d\n" , pop(&top));
    }
}
