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
	insert(&start , 1000);
	insert(&start , 100);
	insert(&start , 30);
	insert(&start , 10);

    insert(&start , 1000);
	insert(&start , 100);
	insert(&start , 30);
	insert(&start , 10);


	print(start);
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
	    struct node *prev = NULL;
		struct node *curr = *start;
		if(ptr->value > (*start)->value)
        {
            while(curr->value < ptr->value)
            {
                if(curr->next == NULL)
                {
                    curr->next = ptr;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if(curr == *start)
            {
                curr = curr->next;
                (*start)->next = curr;
            }
            else if(curr->value >= ptr->value)
            {
                prev->next = ptr;
                ptr->next = curr;
            }
        }
        else if(ptr->value <= (*start)->value)
        {
            *start = ptr;
            (*start)->next = curr;
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
	}
}
