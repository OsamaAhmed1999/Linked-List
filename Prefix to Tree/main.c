#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct BTnode *value;
    struct node *next;
};

struct BTnode
{
	char data;
	struct BTnode *leftchild;
	struct BTnode *rightchild;
};

void enqueue(struct node **front , struct node **rear , struct BTnode *value)
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

struct BTnode* dequeue(struct node **front)
{
    struct node *temp = *front;
    *front = (*front)->next;
    free(front);
    return temp->value;
}

struct BTnode* create(char data)
{
    struct BTnode *ptr;
	ptr = (struct BTnode*)malloc(sizeof(struct BTnode));
	ptr->data = data;
	ptr->leftchild = NULL;
	ptr->rightchild = NULL;

	return ptr;
}

void push(struct node **top , struct BTnode *value)
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

struct BTnode* pop(struct node **top)
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

void print(struct BTnode *root)
{
    if(root != NULL)
    {
        print(root->leftchild);
        printf("%c" , root->data);
        print(root->rightchild);
    }
}

int main()
{
    struct node *top = NULL;
    struct BTnode *root = NULL;
    int size = 25;
    char prefix[size];
    int i , ascii;
    for(i = size-1; i >=0 ; i--)
    {
        prefix[i] = getche();
    }
    for(i = 0; i < size; i++)
    {
        ascii = prefix[i];
        if(ascii >= 97 && ascii <= 122)
        {
            struct BTnode *temp = create(prefix[i]);
            push(&top , temp);
        }
        else
        {
            struct BTnode *op = create(prefix[i]);
            op->leftchild = pop(&top);
            op->rightchild = pop(&top);
            push(&top , op);
        }
    }

    printf("\n\n");
    print(pop(&top));
}
