#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size = 5;
	int array[5] = {30, 50, 2, 40, 1000};
	int i , j;

	for(i = 1; i < size; i++)
	{
		int hold = array[i];
		j = i;
		while(hold < array[j-1])
		{
			array[j] = array[j-1];
			j--;
		}
		array[j] = hold;
	}

	for(i = 0; i<size; i++)
	{
		printf("%d\n" , array[i]);

	}
}
