#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};


struct BTnode
{
	int data;
	struct BTnode *leftchild;
	struct BTnode *rightchild;
};

void main()
{
	struct BTnode *root = NULL;
	//printf("%d\n\n" , &root);
	insert(&root , 135);
	insert(&root , 120);
	insert(&root , 30);
	/*insert(&root , 60);
	insert(&root , 20);
	insert(&root , 18);
	insert(&root , 75);
	insert(&root , 87);
	insert(&root , 56);
	insert(&root , 93);
    insert(&root , 150);
    insert(&root , 22);
    insert(&root , 69);*/

    printf("\n\n");
	print(root);
}

/*struct BTnode*/void checkheight(struct BTnode *root , struct node *top)
{
    if(root != NULL)
    {
        int height = -1;
        int lefthi8 = leftheight(root , height);
        int righthi8 = rightheight(root , height);

        checkheight(root->leftchild , top);
        if((lefthi8-righthi8) <= -2 || (lefthi8-righthi8) >=2)
        {
            //printf("%d %d %d\n" , lefthi8 , righthi8 , lefthi8-righthi8);
            push(*top , root);
        }
        checkheight(root->rightchild , top);
    }
}

void insert(struct BTnode **root , int data)
{
    struct node *top = NULL;
	struct BTnode *ptr;
	ptr = (struct BTnode*)malloc(sizeof(struct BTnode));
	ptr->data = data;
	ptr->leftchild = NULL;
	ptr->rightchild = NULL;

	if(*root == NULL)
	{
		*root = ptr;
	}
	else
	{
		struct BTnode *curr = *root;
		while(curr != NULL)
		{
			if(curr->data > ptr->data)
			{
				if(curr->leftchild == NULL)
				{
					curr->leftchild = ptr;
					break;
				}
				curr = curr->leftchild;
			}
			else
			{
				if(curr->rightchild == NULL)
				{
					curr->rightchild = ptr;
					break;
				}
				curr = curr->rightchild;
			}
		}
	}
        checkheight(*root , &top);
        struct BTnode *w_n = pop(&top);
        if(w_n != NULL)
        {
            printf("%d\n" , w_n->data);
            if(w_n->data == (*root)->data)
            {
                if(w_n->rightchild == NULL || (w_n->rightchild)->rightchild == NULL)
                {
                    struct BTnode *temp = ((*root)->leftchild)->rightchild;
                    struct BTnode *curr = *root;
                    *root = (*root)->leftchild;
                    (*root)->rightchild = curr;
                    curr->leftchild = temp;
                }
                else if(w_n->leftchild == NULL)
                {
                    struct BTnode *temp = ((*root)->rightchild)->leftchild;
                    struct BTnode *curr = *root;
                    *root = (*root)->rightchild;
                    (*root)->leftchild = curr;
                    curr->rightchild = temp;
                }
            }
            else
            {
                if(w_n->rightchild == NULL)
                {

                }
                else if(w_n->leftchild == NULL)
                {
                    struct BTnode *temp = w_n;
                }
            }
        }



        /*struct BTnode *r = *root;
        while(r->data != t)
        {
            if(r->leftchild != NULL)
            {
                r = r->leftchild;
            }
            else
            {
                r = r->rightchild;
            }
        }
        if(t == 1)
        {
        struct BTnode *temp = ((*root)->leftchild)->rightchild;
        struct BTnode *curr = *root;
        *root = (*root)->leftchild;
        (*root)->rightchild = curr;
        curr->leftchild = temp;
        }
        else if(t == 2)
        {
            struct BTnode *temp = ((*root)->rightchild)->leftchild;
        struct BTnode *curr = *root;
        *root = (*root)->rightchild;
        (*root)->leftchild = curr;
        curr->rightchild = temp;
        }

	if(te->data == (*root)->data)

    /*height = -1;
	int lefthi8 = leftheight(*root , height);
	int righthi8 = rightheight(*root , height);
	if((lefthi8-righthi8) >= 2)
    {
        struct BTnode *temp = ((*root)->leftchild)->rightchild;
        struct BTnode *curr = *root;
        *root = (*root)->leftchild;
        (*root)->rightchild = curr;
        curr->leftchild = temp;
    }
    else
    {
        int t;
        t = checkheight(*root);
        if(t == 1)
        {

        }
        else if(t == 2)
        {

        }
    }
    /*else if(lefthi8-righthi8 <= -2)
    {
        struct BTnode *temp = ((*root)->rightchild)->leftchild;
        struct BTnode *curr = *root;
        *root = (*root)->rightchild;
        (*root)->leftchild = curr;
        curr->rightchild = temp;
    }*/
}

int leftheight(struct BTnode *curr , int height)
{
    if(curr != NULL)
    {
        height++;
        leftheight(curr->leftchild , height);
    }
    if(curr == NULL)
    {
        return height;
    }
}

int rightheight(struct BTnode *curr , int height)
{
    if(curr != NULL)
    {
        height++;
        rightheight(curr->rightchild , height);
    }
    if(curr == NULL)
    {
        return height;
    }
}

struct BTnode* wrongnode(struct BTnode *curr , int data)
{
    if(curr != NULL)
    {
        if(data == curr->data)
        {
            return curr;
        }
        wrongnode(curr->leftchild , data);
        wrongnode(curr->rightchild , data);
    }
}

void ShiftRight(struct BTnode **root)
{
    printf("%d\n" , &root);
    struct BTnode *temp = ((*root)->leftchild)->rightchild;
    struct BTnode *curr = *root;
    *root = (*root)->leftchild;
    (*root)->rightchild = curr;
    curr->leftchild = temp;

}

void print(struct BTnode *curr)
{
    if(curr != NULL)
    {
        printf("%d\n" , curr->data);
        print(curr->leftchild);
        print(curr->rightchild);
    }
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


