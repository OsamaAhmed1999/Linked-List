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
	insert(&root , 80);
	insert(&root , 70);
	insert(&root , 11);
	insert(&root , 36);
	insert(&root , 96);
	insert(&root , 119);
	insert(&root , 23);
	insert(&root , 15);
	insert(&root , 76);
	insert(&root , 230);
    insert(&root , 78);
    insert(&root , 75);

	print(root);
	deletee(&root , 70);
	printf("\n\n");
	print(root);
	//search(root , 70);
}


void deletee(struct BTnode **root , int data)
{
    struct BTnode *curr = *root;
    struct BTnode *prev;
    if(*root == NULL)
    {
        printf("Root Not Found");
    }
    else
    {
        while(curr->data != data)
        {
            if(curr->leftchild == NULL && curr->rightchild == NULL)
            {
                break;
            }
            if(curr->data < data)
            {
                prev = curr;
                curr = curr->rightchild;
            }
            else
            {
                prev = curr;
                curr = curr->leftchild;
            }
        }
        if(curr->data == data)
        {
            if(curr->leftchild == NULL && curr->rightchild == NULL)
            {
                if(prev->leftchild != NULL && (prev->leftchild)->data == data)
                {
                    prev->leftchild = NULL;
                    free(curr);
                }
                else
                {
                    prev->rightchild = NULL;
                    free(curr);
                }
            }
            else if(curr->leftchild != NULL && curr->rightchild == NULL)
            {
                prev->leftchild = curr->leftchild;
                free(curr);
            }
            else if(curr->leftchild == NULL && curr->rightchild != NULL)
            {
                prev->rightchild = curr->rightchild;
                free(curr);
            }
            else
            {
                struct BTnode *currr = curr->leftchild;
                struct BTnode *greater = currr;
                struct BTnode *prev_greater;
                prev = curr;
                while(currr != NULL)
                {
                    if(currr->data >= greater->data)
                    {
                        prev_greater = prev;
                        greater = currr;
                    }
                    if(currr->leftchild == NULL && currr->rightchild == NULL)
                    {
                        break;
                    }
                    if(currr->rightchild != NULL)
                    {
                        prev = currr;
                        currr = currr->rightchild;
                    }
                    else
                    {
                        prev = currr;
                        currr = currr->leftchild;
                    }
                }

                curr->data = greater->data;
                if(greater->leftchild != NULL)
                {
                    if((prev_greater->rightchild)->data == greater->data)
                    {
                        prev_greater->rightchild = greater->leftchild;
                        free(greater);
                    }
                    else
                    {
                        prev_greater->leftchild = greater->leftchild;
                        free(greater);
                    }
                }
                else
                {
                    if((prev_greater->rightchild)->data == greater->data)
                    {
                        prev_greater->rightchild = NULL;
                        free(greater);
                    }
                    else
                    {
                        prev_greater->leftchild = NULL;
                        free(greater);
                    }
                }
            }
        }
        else
        {
            printf("Value Not Found");
        }
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
}

void search(struct BTnode *root , int data)
{
	struct BTnode *curr = root;
	while(curr->data != data)
	{
		if(curr->data > data)
		{
			if(curr->leftchild == NULL)
			{
				break;
			}
			curr = curr->leftchild;
		}
		else
		{
			if(curr->rightchild == NULL)
			{
				break;
			}
			curr = curr->rightchild;
		}
	}
	if(curr->data == data)
	{
		printf("\nFound");
	}
	else
	{
		printf("\nNot Found");
	}
}

void print(struct BTnode *root)
{
    if(root != NULL)
    {
        print(root->leftchild);
        printf("%d\n" , root->data);
        print(root->rightchild);
    }
}

/**PRINT
    printf("root %d\n\n" , root->data);
	printf("L %d\n" , (root->leftchild)->data);
	printf("LR %d\n" , ((root->leftchild)->rightchild)->data);
	printf("LRR %d\n" , (((root->leftchild)->rightchild)->rightchild)->data);
	printf("LL %d\n" , ((root->leftchild)->leftchild)->data);
	printf("LLRL %d\n" , ((((root->leftchild)->leftchild)->rightchild)->leftchild)->data);
	printf("R %d\n" , (root->rightchild)->data);
	//printf("RR %d\n" , ((root->rightchild)->rightchild)->data);
	printf("RR %d\n" , ((root->rightchild)->rightchild)->data);
	printf("RRR %d\n" , (((root->rightchild)->rightchild)->rightchild)->data);**/

/**DELETE 1
if(curr->data < (*root)->data)
{
    struct BTnode *temp = curr->rightchild;
    while(temp->leftchild != NULL)
    {
        temp = temp->leftchild;
    }
    temp->leftchild = curr->leftchild;
    prev->leftchild = curr->rightchild;
    free(curr);
}
else
{
    struct BTnode *temp = curr->rightchild;
    while(temp->leftchild != NULL)
    {
        temp = temp->leftchild;
    }
    temp->leftchild = curr->leftchild;
    prev->rightchild = curr->rightchild;
    free(curr);
}*/
