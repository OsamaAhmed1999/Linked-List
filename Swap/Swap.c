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
	insert(&start , 60);
	insert(&start , 70);
	print(start);
	printf("After Swap\n");

	swap(&start , search(&start , 10) , search(&start , 20));
	print(start);

}

void swap(struct node **start , struct node *prev1 , struct node *prev2)
{
    if(prev1 == NULL)
    {
        struct node *p1 = *start;
        struct node *p2 = prev2->next;
        struct node *end = p2->next;

        if((*start)->value == p1->value && ((*start)->next)->value == p2->value)
        {
            *start = (*start)->next;
            (*start)->next = p1;
            p1->next = end;
        }
        else if((*start)->value == p1->value && ((*start)->next)->value != p2->value)
        {
            *start = prev2->next;
            (*start)->next = p1->next;
            prev2->next = p1;
            p1->next = end;
        }
    }
    else
    {
        struct node *p1 = prev1->next;
        struct node *p2 = prev2->next;
        struct node *end = p2->next;

        if((p1->next)->value == p2->value)
        {
            p2->next = prev1->next;
            prev1->next = prev2->next;
            p1->next = end;
        }
        else
        {
            p2->next = p1->next;
            prev2->next = prev1->next;
            prev1->next = p2;
            p1->next = end;
        }
    }
}

int search(struct node **start , int value)
{
	if(*start == NULL)
	{
		printf("Empty List");
	}
	else
	{
	    if((*start)->value == value)
        {
            return NULL;
        }
        else
        {
            struct node *curr = (*start)->next;
            struct node *prev = *start;

            while(curr != NULL)
            {
                if(curr->value == value)
                {
                    return prev;
                }
                prev = prev->next;
                curr = curr->next;
            }
        }
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

