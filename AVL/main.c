#include <stdio.h>
#include <stdlib.h>

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
	insert(&root , 60);
	insert(&root , 20);
	insert(&root , 18);
	insert(&root , 75);
	insert(&root , 87);
	/*insert(&root , 56);
	insert(&root , 93);
    insert(&root , 150);
    insert(&root , 22);
    insert(&root , 69);*/

    printf("\n\n");
	print(root);
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

int checkheight(struct BTnode *root)
{
    if(root != NULL)
    {
        int height = -1;
        int lefthi8 = leftheight(root , height);
        int righthi8 = rightheight(root , height);

        checkheight(root->leftchild);
        if((lefthi8-righthi8) <= -2 || (lefthi8-righthi8) >=2)
        {
            printf("%d %d %d\n" , lefthi8 , righthi8 , lefthi8-righthi8);
            return root->data;
        }
        checkheight(root->rightchild);
    }
    if(root == NULL)
    {
        return root->data;
    }

}

void insert(struct BTnode **root , int data)
{
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

    int check = checkheight(*root);
    if(check != 0 )
    {
        printf("%d\n" , check);
        struct BTnode *w_n = wrongnode(*root , check);
        printf("%d" , w_n->data);
        if(w_n != NULL)
        {
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
    }
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
