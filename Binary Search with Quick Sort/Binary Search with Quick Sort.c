#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    int array[10] = {90,1,4,200,8,3,6,7,10,0};
    int start = 0;
    int end = 9;
    Quicksort(array , start , end);

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

void Quicksort(int *array , int left , int right)
{
    int pi , pivot;
    pi = setpivot(left , right , array);
    if(left < right)
    {
        Quicksort(array , left , pi-1);
        Quicksort(array , pi+1 , right);
    }
}

int setpivot(int left , int right , int *array)
{
    int pivot;
    pivot = (left + right)/2;
    while(left < right)
    {
        if(array[pivot] >= array[right])
        {
            int temp = array[pivot];
            array[pivot] = array[right];
            array[right] = temp;
            pivot = right;

            if(array[pivot] <= array[left])
            {
                int temp = array[pivot];
                array[pivot] = array[left];
                array[left] = temp;
                pivot = left;
            }
            else
            {
                left++;
            }
        }
        else
        {
            right--;
        }
    }
    return pivot;
}
