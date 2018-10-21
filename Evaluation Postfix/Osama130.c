#include <stdio.h>
#include <stdlib.h>

struct node
{
    float value;
    struct node *next;
};

float peak(struct node *top)
{
    if(top == NULL)
    {
        return 0;
    }
    else
    {
        return top->value;
    }
}

void push(struct node **top , float value)
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

float pop(struct node **top)
{
    struct node *temp = *top;
    *top = (*top)->next;
    free(top);
    return temp->value;
}

int main()
{
    struct node *top = NULL;
    int size = 13 , i , ascii;
    float cal;
    char postfix[size];
    for(i = 0; i < size; i++)
    {
        postfix[i] = getche();
        ascii = postfix[i];
        if(ascii >= 96 && ascii <= 122)
        {
            if(postfix[i] == 'a')
            {
                push(&top , 7);
            }
            else if(postfix[i] == 'b')
            {
                push(&top , 2);
            }
            else if(postfix[i] == 'c')
            {
                push(&top , 3);
            }
            else if(postfix[i] == 'd')
            {
                push(&top , 1);
            }
            else if(postfix[i] == 'e')
            {
                push(&top , 2);
            }
        }
        else
        {
            if(postfix[i] == '*')
            {
                push(&top , pop(&top) * pop(&top));
            }
            else if(postfix[i] == '/')
            {
                cal = pop(&top);
                push(&top , pop(&top) / cal);
            }
            else if(postfix[i] == '+')
            {
                push(&top , pop(&top) + pop(&top));
            }
            else if(postfix[i] == '-')
            {
                cal = pop(&top);
                push(&top , pop(&top) - cal);
            }
        }
    }
    printf("\n\nAnswer: %.1f" , pop(&top));
}

