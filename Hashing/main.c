#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size , value , i;
	printf("Size: ");
	scanf("%d" , &size);
	int array[size];
	for(i = 0; i<size; i++)
    {
        array[i] = -1;
    }
    printf("\nEnter Values\n");
    for(i = 0; i<size; i++)
    {
        scanf("%d" , &value);
        quadratic_insert(array , size , value);
        //linear_insert(array , size , value);
    }
    for(i = 0; i<size; i++)
    {
        printf("\n%d" , array[i]);
    }
    int search;
    printf("\nSearch: ");
    scanf("%d" , &search);
    quardratic_search(array , size , search);
    //linear_search(array , size , search);
}

int hash(int size , int value)
{
    return value % size;
}

void linear_insert(int *array , int size , int value)
{
    int index = hash(size , value);
	if(array[index] == -1)
	{
		array[index] = value;
	}
	else
	{
	    int temp = index;
		index++;
		while(array[index] != -1 && index != temp)
		{
			if(index == size)
			{
				index = 0;
			}
			else
            {
                index++;
            }
		}
		if(array[index] == -1)
        {
            array[index] = value;
        }
	}
}

void linear_search(int *array , int size , int value)
{
	int index = hash(size , value);
	if(array[index] == -1)
    {
        printf("\nValue Not Found\n");
    }
	else if(array[index] == value)
	{
		printf("\n%d is Found" , array[index]);
	}
	else
	{
	    int temp = index;
	    index++;
	    while (index != temp)
        {
            if(array[index] == value)
            {
                printf("\n%d is Found" , array[index]);
                break;
            }
            if(index == size)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
        if(array[index] != value)
        {
            printf("\nValue Not Found\n");
        }
	}
}

void quadratic_insert(int *array , int size , int value)
{
    int index = hash(size , value);
	if(array[index] == -1)
	{
		array[index] = value;
	}
	else
	{
	    int i = 1;
	    int temp = index;
		index = index + (i * i);
		while(array[index] != -1 && index != temp)
		{
            i++;
            index = index + (i * i);
            if(index >= size)
            {
                index = 0;
            }
		}
		if(array[index] == -1)
        {
            array[index] = value;
        }
	}
}

void quardratic_search(int *array , int size , int value)
{
	int index = hash(size , value);
	if(array[index] == -1)
    {
        printf("\nValue Not Found\n");
    }
	else if(array[index] == value)
	{
		printf("\n%d is Found" , array[index]);
	}
	else
	{
	    int i = 1;
	    int temp = index;
	    index = index + (i * i);
	    while (index != temp)
        {
            if(array[index] == value)
            {
                printf("\n%d is Found" , array[index]);
                break;
            }
            if(index >= size)
            {
                index = 0;
            }
            else
            {
                i++;
                index = index + (i * i);
            }
        }
        if(array[index] != value)
        {
            printf("\nValue Not Found\n");
        }
	}
}
