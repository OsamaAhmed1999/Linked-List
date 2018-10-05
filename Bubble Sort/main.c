#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 10;
	int array[10] = {5,40,7,2,66,8,1,9,3,10};
	int i , j;

	for(i = 0; i<size-1; i++)
	{
		for(j = 0; j<size-i-1; j++)
		{
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for(i = 0; i<size; i++ )
	{
		printf("%d\n" , array[i]);
	}
}
