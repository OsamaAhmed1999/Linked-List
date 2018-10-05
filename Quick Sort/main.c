#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 10;
    int array[10] = {90,1,4,200,8,3,6,7,10,0};
    int left = 0;
    int right = 9;
    int i;
    Quicksort(array , left , right);
    for(i = 0; i<size; i++)
    {
        printf("%d\n" , array[i]);
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
