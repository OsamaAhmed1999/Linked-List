#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    int array[10] = {10005 , 30 , 50 , 30 , 30 , 1 , 80 , 5 , 3 , 1};
    int left = 0;
    int right = size-1;
    print(array , size);
    sort(array , left , right);
    printf("After Sorting\n");
    print(array , size);
}

void sort(int *array , int left , int right)
{
    int index;
    index = (left + right)/2;
    if(left < right)
    {
        sort(array , left , index);
        sort(array , index+1 , right);
    }
    merge(array , left , right);
}

void merge(int *array , int left , int right)
{
    while(left <= right)
    {
        int index = left;
        while(index <= right)
        {
            if(array[left] > array[index])
            {
                int temp;
                temp = array[left];
                array[left] = array[index];
                array[index] = temp;
            }
            else
            {
                index++;
            }
        }
        left++;
    }
}

void print(int *array , int size)
{
    int i;
    for(i = 0; i<size; i++)
    {
        printf("%d\n" , array[i]);
    }
}
