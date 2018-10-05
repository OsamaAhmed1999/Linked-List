#include <stdio.h>
#include <stdlib.h>

struct node
{
    char value;
    struct node *next;
};

char peak(struct node *top)
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

int precedence(char value)
{
    if(value == '|')
    {
        return 1;
    }
    else if(value == '&')
    {
        return 2;
    }
    else if(value == '=' || value == '!' || value == '<' || value == '>')
    {
        return 3;
    }
    else if(value == '+' || value == '-')
    {
        return 4;
    }
    else if(value == '/' || value == '*')
    {
        return 5;
    }
    else if(value == '(')
    {
        return 0;
    }
    else
    {
        return 0;
    }
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
    if((*top)->next != NULL)
    {
        *top = (*top)->next;
    }
    else
    {
        *top = NULL;
    }
    free(top);
    return temp->value;
}

void print(struct node *top)
{
    while(top != NULL)
    {
        printf("%c" , pop(&top));
    }
}

int main()
{
    struct node *top = NULL;
    int size = 9;
    char postfix[size];
    char infix[size];
    int i , j = 0 , ascii;
    for(i = 0; i < size; i++)
    {
        infix[i] = getche();
        ascii = infix[i];
        if(ascii >= 97 && ascii <= 122)
        {
            postfix[j] = infix[i];
            j++;

        }
        else
        {
            if(top == NULL)
            {
                push(&top , infix[i]);
            }
            else
            {
                if(infix[i] == '(')
                {
                    push(&top , infix[i]);
                }
                else if(infix[i] == ')')
                {
                    while(top->value != '(')
                    {
                        postfix[j] = pop(&top);
                        j++;
                    }
                    pop(&top);
                }
                else
                {
                    char temp_top = peak(top);
                    int pre_top = precedence(temp_top);
                    int pre_in = precedence(infix[i]);

                    while(pre_in <= pre_top && top != NULL)
                    {
                        if(pre_in <= pre_top)
                        {
                            postfix[j] = pop(&top);
                            j++;
                        }
                        temp_top = peak(top);
                        pre_top = precedence(temp_top);
                    }
                    push(&top , infix[i]);
                }
            }
        }
    }
    printf("\n\n");
    while(top != NULL)
    {
        postfix[j] = pop(&top);
        j++;
    }
    for(i = 0; i< size; i++)
    {
        printf("%c" , postfix[i]);
    }
}
