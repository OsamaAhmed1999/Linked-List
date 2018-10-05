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
	insert(&start , 30);
	insert(&start , 50);
	insert(&start , 20);
	insert(&start , 40);
	insert(&start , 10);
	print(start);

	sort(&start);
	printf("After Sorting\n");
	print(start);

}

void sort(struct node **start)
{
	struct node *curr = (*start)->next;
	while(curr != NULL)
	{
		int hold = curr->value;
		struct node *temp = curr;
		while(hold < (temp->prev)->value)
		{
			temp->value = (temp->prev)->value;
			temp = temp->prev;
			if(temp->prev == NULL)
			{
				break;
			}
		}
		temp->value = hold;
		curr = curr->next;
	}
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

        /*curr = start;
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
		}*/
	}
}

