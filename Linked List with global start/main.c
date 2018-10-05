#include <stdio.h>
#include <stdlib.h>
struct node *start = NULL;
struct node
{
	int value;
	struct node *next;
};

int main()
{

	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	print();
	printf("After Delete\n");
	del(50);
	del(10);
	print();
	//search(10);
	//search(90);
}

void insert(int value)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->value = value;
	ptr->next = NULL;
	if(start == NULL)
	{
		start = ptr;
	}
	else
	{
		struct node *curr = start;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
	}
}

void search(int value)
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

void del(int value)
{
	struct node *curr = start;
	struct node *prev;
	if(curr->value == value)
	{
		curr = start->next;
		free(start);
		start = curr;
	}
	else
	{
		curr = start->next;
		prev = start;
		while(curr->value != value)
		{
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void print()
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
