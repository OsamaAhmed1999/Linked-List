#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9};
    int start = 0;
    int end = 9;
    int value;
    printf("Enter Number: ");
    scanf("%d",&value);
    search(array , start , end , value);
}

void search(int *array , int start , int end , int value)
{
    int mid;
    mid = (start + end)/2;
    if(start <= end)
    {
        if(array[mid] == value)
        {
            printf("Found");
        }
        else if(array[mid] < value)
        {
            start = mid + 1;
            search(array , start , end , value);
        }
        else if(array[mid] > value)
        {
            end = mid - 1;
            search(array , start , end , value);
        }
    }
    else
    {
        printf("Not Found");
    }
}
