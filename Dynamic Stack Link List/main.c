#include <stdio.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *next;
};

int main()
{
    struct node *top = NULL;
    char v;
    int i;
    for(i = 0; i< 9; i++)
    {
        scanf("%c" , &v);
        push(&top , v);
    }
    //push(&top , 4);
    //push(&top , 3);
    //push(&top , 2);
    //push(&top , 1);
    print(top);
}

void push(struct node **top , char value)
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
        printf("%c\n" , pop(&top));
    }
}
