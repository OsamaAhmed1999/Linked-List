#include <stdio.h>
#include <stdlib.h>

struct node
{
    float data;
    struct node *next;
};

void push(struct node **stack , float data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(*stack == NULL)
    {
        *stack=temp;
    }
    else
    {
        temp->next=*stack;
        *stack=temp;
    }
}

float pop(struct node **stack)
{
    struct node *temp=*stack;
    *stack=(*stack)->next;
    free(stack);
    return temp->data;
}

int main()
{
    struct node *stack=NULL;
    int i , temp;
    float a,b, ans;
    char postfix[9];
    for(i = 0; i < 9; i++)
    {
        postfix[i]=getche();
        temp = postfix[i];
        if(temp >= 96 && temp <= 122)
        {
            if(postfix[i]=='a')
            {
                push(&stack,7);
            }
            else if(postfix[i]=='b')
            {
                push(&stack,2);
            }
            else if(postfix[i]=='c')
            {
                push(&stack,3);
            }
            else if(postfix[i]=='d')
            {
                push(&stack,1);
            }
            else if(postfix[i]=='e')
            {
                push(&stack,2);
            }
        }
        else
        {
            if(postfix[i] == '*')
            {
                a=pop(&stack);
                b=pop(&stack);
                push(&stack , b * a);
            }
            else if(postfix[i] == '/')
            {
                a = pop(&stack);
                b = pop(&stack);
                push(&stack , b / a);
            }
            else if(postfix[i] == '+')
            {
                a=pop(&stack);
                b=pop(&stack);
                push(&stack , b + a);
            }
            else if(postfix[i] == '-')
            {
                a=pop(&stack);
                b=pop(&stack);
                push(&stack , b - a);
            }
        }
    }
    printf("\n%f" , pop(&stack));
}

