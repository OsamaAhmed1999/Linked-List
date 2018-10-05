#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int array[20];
    char check = 'y';
    while(check == 'y' || check == 'Y')
    {
        system("cls");
        printf("Enter Number: ");
        scanf("%d" , &num);
        int i = 2 , j = 1 , cube = 1;
        while(num != 1)
        {
            if(num % i == 0)
            {
                num = num/i;
                printf("%d " , i);
                array[j] = i;
                j++;
            }
            else
            {
                i++;
            }
        }
        i = 1;
        while(i < j)
        {
            if(array[i] == array[i+1])
            {
                if(array[i+1] == array[i+2])
                {
                    cube = cube * array[i];
                }
            }
            else
            {
                printf("\nNot a Perfect Cube");
                break;
            }
            i = i+3;
        }
        if(cube > 1)
        {
            printf("\nCube: %d" , cube);
        }
        printf("\n\nContinue (Y/N):  ");
        check = getch();
    }
}

