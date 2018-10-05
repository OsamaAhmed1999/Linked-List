#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 7;
    int array[7] = {70 , 60 , 10 , 30 , 100 , 90 , 80};
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
        printf("a\n");
        sort(array , left , index);
        printf("b\n");
        sort(array , index+1 , right);
    }
    printf("c\n");
    mergee(array , left , right);
}

void mergee(int *array , int left , int right)
{
    printf("%d %d\n" , left , right);
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
