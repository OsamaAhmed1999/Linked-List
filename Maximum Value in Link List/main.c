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
	insert(&start , 12000);
	insert(&start , 1010);
	insert(&start , 60);
	insert(&start , 100);
	insert(&start , 50);
	insert(&start , 5);
	insert(&start , 90);
	print(start);

    printf("\nMaximum Value is %d\n" , maximum(&start));
}

int maximum(struct node **start)
{
    int max = 0;
    struct node *curr = *start;
    struct node *tempr;
    while(curr != NULL)
    {
        tempr = curr->next;
        struct node *temp = curr->next;
        while(temp != NULL)
        {
            if(curr->value > temp->value)
            {
                swap(&start , curr->value , temp->value);
                max = curr->value;
            }
            else
            {
                max = temp->value;
            }
            temp = temp->next;
        }
        curr = tempr;
    }
    return max;
}

void swap(struct node ***start , int value1 , int value2)
{
    if((**start)->value == value1)
    {
        if((**start)->value == value1 && ((**start)->next)->value == value2)
        {
            struct node *curr = **start;
            struct node *end = (curr->next)->next;

            **start = (**start)->next;
            (**start)->next = curr;
            curr->next = end;
        }
        else if((**start)->value == value1 && ((**start)->next)->value != value2)
        {
            struct node *p1 , *p2 , *prev1 , *prev2 , *end;
            prev1 = NULL;
            p1 = **start;
            struct node *curr = (**start)->next;
            prev2 = **start;
            while(curr != NULL)
            {
                if(curr->value == value2)
                {
                    p2 = curr;
                    end = curr->next;
                    break;
                }
                curr = curr->next;
                prev2 = prev2->next;
            }
            **start = prev2->next;
            (**start)->next = p1->next;
            prev2->next = p1;
            p1->next = end;
        }
    }
    else
    {
        struct node *p1 , *p2 , *prev1 , *prev2 , *end;
        struct node *curr = (**start)->next;
        struct node *prev = **start;

        while(curr != NULL)
        {
            if(curr->value == value1 && (curr->next)->value == value2)
            {
                p1 = curr;
                p2 = curr->next;
                end = p2->next;

                p2->next = prev->next;
                prev->next = curr->next;
                p1->next = end;

                break;
            }
            else if(curr->value == value1)
            {
                prev1 = prev;
                p1 = curr;
            }
            else if(curr->value == value2)
            {
                prev2 = prev;
                p2 = curr;
                end = p2->next;

                p2->next = p1->next;
                prev2->next = prev1->next;
                prev1->next = p2;
                p1->next = end;

                break;
            }
            curr = curr->next;
            prev = prev->next;
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
                    printf("%d" , prev->value);
                    return &prev;
                }
                prev = prev->next;
                curr = curr->next;
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
	}
}
