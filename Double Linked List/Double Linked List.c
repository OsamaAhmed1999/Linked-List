#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node *next;
	struct node *prev;
};

int main()
{
	struct node *start = NULL;
	insert(&start , 10);
	insert(&start , 20);
	insert(&start , 30);
	insert(&start , 40);
	insert(&start , 50);
	print(start);

	printf("After Delete\n");
	del(&start , 40);
	del(&start , 50);
	print(start);

	//search(start , 10);
	//search(start , 90);
}

void insert(struct node **start , int value)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->value = value;
	ptr->next = NULL;

	if(*start == NULL)
	{
		*start = ptr;
         ptr->prev = NULL;
	}
	else
	{
		struct node *curr = *start;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
		ptr->prev = curr;
	}
}

void search(struct node *start , int value)
{
	if(start == NULL)
	{
		printf("Empty List");
	}
	else
	{
		struct node *curr = start;
		while(curr->value != NULL)
		{
			if(curr->value == value)
			{
				printf("\nFound");
				break;
			}
			curr = curr->next;
			if(curr == NULL)
			{
				printf("\nNot Found");
				break;
			}
		}
	}
}

void del(struct node **start , int value)
{
	struct node *curr = *start;
	if((*start)->value == value)
	{
		*start = (*start)->next;
		((*start)->next)->prev = NULL;
		free(start);
	}
	else
	{
		curr = (*start)->next;
		while(curr->value != value)
		{
			curr = curr->next;
		}
		if(curr->next == NULL)
        {
            (curr->prev)->next = NULL;
            free(curr);
        }
        else
        {
            (curr->prev)->next = curr->next;
            (curr->next)->prev = curr->prev;
            free(curr);
        }
	}
}

void print(struct node *start)
{
	if(start == NULL)
	{
		printf("Empty List");
	}
	else
	{
		struct node *curr = start;
		while(curr->value != NULL)
		{
			printf("%d\n" , curr->value);
			curr = curr->next;
			if(curr == NULL)
			{
				break;
			}
		}

        curr = start;
		while(curr->next != NULL)
        {
            curr = curr->next;
        }
		while(curr->value != NULL)
		{
			printf("%d\n" , curr->value);
			curr = curr->prev;
			if(curr == NULL)
			{
				break;
			}
		}
	}
}

