#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node *next;
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
	}
	else
	{
		struct node *curr = *start;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
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
	struct node *prev;
	if((*start)->value == value)
	{
		*start = (*start)->next;
		free(start);
	}
	else
	{
		curr = (*start)->next;
		prev = *start;
		while(curr->value != value)
		{
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = curr->next;
		free(curr);
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
	}
}
