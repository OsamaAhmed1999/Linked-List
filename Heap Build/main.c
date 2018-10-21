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
	insert(&root , 29);
	insert(&root , 100);
	insert(&root , 20);
	insert(&root , 30);
	/*insert(&root , 96);
	insert(&root , 119);
	insert(&root , 23);
	insert(&root , 15);
	insert(&root , 76);
	insert(&root , 230);
    insert(&root , 78);
    insert(&root , 75);*/

	printf("\n\n");
	print(root);
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
		    if(curr->leftchild != NULL && curr->rightchild != NULL)
            {
                curr = curr->leftchild;
            }
            else if(curr->leftchild != NULL && curr->rightchild == NULL)
            {
                curr->rightchild = ptr;
                break;
            }
            else if(curr->leftchild == NULL)
            {
                curr->leftchild = ptr;
                break;
            }
		}

		struct BTnode *r = *root;
		if(r->data < ptr->data)
        {
            int hold = r->data;
            r->data = ptr->data;
            ptr->data = hold;
        }
	}

}

void print(struct BTnode *root)
{
    if(root != NULL)
    {
        printf("%d\n" , root->data);

        print(root->leftchild);

        print(root->rightchild);
    }
}

