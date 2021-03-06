#include <stdio.h>
#include <stdlib.h>

struct edge
{
	int *add;
	struct edge *next;
};

struct vertex
{
	int data;
	struct vertex *next;
	struct edge *head;
};

void AddVertex(struct vertex **start , int data)
{
    struct vertex *ptr;
    ptr = (struct vertex*)malloc(sizeof(struct vertex));
    ptr->next = NULL;
    ptr->head = NULL;
    ptr->data = data;

    if(*start == NULL)
    {
        *start = ptr;
    }
    else
    {
        struct vertex *curr = *start;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = ptr;
    }
}

void AddEdge(struct vertex **start , int edg , int data)
{
    struct edge *ptr;
    ptr = (struct edge*)malloc(sizeof(struct edge));
    ptr->next = NULL;

    struct vertex *curr = *start;
    while(curr->data != edg)
    {
        curr = curr->next;
    }
    if(curr->head == NULL)
    {
        int *add = search(*start , data);
        ptr->add = add;
        curr->head = ptr;
    }
    else
    {
        int *add = search(*start , data);
        ptr->add = add;

        struct edge *cur = curr->head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = ptr;
    }
}

int search(struct vertex *curr , int data)
{
    while(curr != NULL)
    {
        if(curr->data == data)
        {
            break;
        }
        curr = curr->next;
    }
    return &(curr->data);
}

void InDegree(struct vertex *start , int data)
{
    if(start->data != data)
    {
        InDegree(start->next , data);
    }
    else
    {
        int count = 0;
        struct edge *curr = start->head;
        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }
        printf("InDegree of Vertex %d = %d\n" , start->data , count);
    }
}

void OutDegree(struct vertex *start , int data , int count)
{
    if(start != NULL)
    {
        if(start->data != data)
        {
            struct edge *curr = start->head;
            while(curr != NULL)
            {
                if(*curr->add == data)
                {
                    count++;
                }
                curr = curr->next;
            }
        }
        OutDegree(start->next , data , count);
        if(start->next == NULL)
        {
            printf("OutDegree of Vertex %d = %d\n" , data , count);
        }
    }
}

void print(struct vertex *start)
{
    if(start != NULL)
    {
        struct edge *curr = start->head;
        printf("Vertex %d\n" , start->data);
        while(curr != NULL)
        {
            printf("%d " , *(curr->add));
            curr = curr->next;
        }
        printf("\n\n");
        print(start->next);
    }
}

int main()
{
	struct vertex *start = NULL;
	int count = 0;
	AddVertex(&start , 1);
	AddVertex(&start , 2);
	AddVertex(&start , 3);
	AddVertex(&start , 4);
	AddVertex(&start , 5);
	AddEdge(&start , 1 , 4);
	//AddEdge(&start , 4 , 1);
	//AddEdge(&start , 2 , 3);
	AddEdge(&start , 3 , 2);
	//AddEdge(&start , 3 , 5);
	AddEdge(&start , 5 , 3);
	//AddEdge(&start , 2 , 5);
	AddEdge(&start , 5 , 2);
	AddEdge(&start , 4 , 5);
	//AddEdge(&start , 5 , 4);
	//AddEdge(&start , 5 , 1);
	AddEdge(&start , 1 , 5);

    InDegree(start , 2);
    OutDegree(start , 2 , count);
	//print(start);
}
