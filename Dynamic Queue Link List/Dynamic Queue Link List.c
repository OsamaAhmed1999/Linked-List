#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};


int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    enqueue(&front , &rear , 1);
    enqueue(&front , &rear , 2);
    enqueue(&front , &rear , 3);
    enqueue(&front , &rear , 4);
    enqueue(&front , &rear , 5);
    print(front);
}

void enqueue(struct node **front , struct node **rear , int value)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->value = value;
    ptr->next = NULL;
    if(*front == NULL)
    {
        *front = ptr;
        *rear = ptr;
    }
    else
    {
        (*rear)->next = ptr;
        *rear = (*rear)->next;
    }
}

int dequeue(struct node **front)
{
    struct node *temp = *front;
    *front = (*front)->next;
    free(front);
    return temp->value;
}

void print(struct node *front)
{
    while(front != NULL)
    {
        printf("%d\n" , dequeue(&front));
    }
}
