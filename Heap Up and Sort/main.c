#include <stdio.h>
#include <stdlib.h>

int insert(int *array , int value , int i)
{
    if(array[i] == -1)
    {
        array[i] = value;
        return i;
    }
    else if(array[2*i+1] == -1)
    {
        array[2*i+1] = value;
        int ii = i;
        while(i >= 0)
        {
            if(array[2*i+1] > array[i] && array[2*i+1] > array[2*i+2])
            {
                int temp = array[i];
                array[i] = array[2*i+1];
                array[2*i+1] = temp;
            }
            i--;
        }
        return ii;
    }
    else if(array[2*i+2] == -1)
    {
        array[2*i+2] = value;
        int ii = i;
        while(i >= 0)
        {
            if(array[2*i+2] > array[i] && array[2*i+2] > array[2*i+1])
            {
                int temp = array[i];
                array[i] = array[2*i+2];
                array[2*i+2] = temp;
            }
            i--;
        }
        ii++;
        return ii;
    }
}

void sortt(int *array , int *sort , int size)
{
    int i , j;
    for(i = 0; i <= size; i++)
    {
        int temp = array[0];
        array[0] = array[size-i];
        array[size-i] = temp;

        sort[i] = array[size-i];
        array[size-i] = -1;
        j = 0;;
        while(j < size/2)
        {
            if(array[2*j+1] > array[j] && array[2*j+1] > array[2*j+2])
            {
                int temp = array[j];
                array[j] = array[2*j+1];
                array[2*j+1] = temp;
            }
            else if(array[2*j+2] > array[j] && array[2*j+2] > array[2*j+1])
            {
                int temp = array[j];
                array[j] = array[2*j+2];
                array[2*j+2] = temp;
            }
            j++;
        }
    }
}

int main()
{
    int size = 9 , i;
    int array[size];
    int sort[size];
    int value;
    for(i = 0; i < size; i++)
    {
        array[i] = -1;
    }
    i = 0;
    while(i < size/2)
    {
        scanf("%d" , &value);
        i = insert(array , value , i);
    }
    printf("\n\n");

    sortt(array , sort , size-1);
    for(i = 0; i < size; i++)
    {
        printf("%d\n" , sort[i]);
    }
}
