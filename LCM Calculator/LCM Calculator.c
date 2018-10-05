#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    char check = 'y';
    while(check == 'y' || check == 'Y')
    {
        system("cls");
        printf("Enter Number: ");
        scanf("%d" , &num);
        int i = 2;
        while(num != 1)
        {
            if(num % i == 0)
            {
                num = num/i;
                printf("%d " , i);
            }
            else
            {
                i++;
            }
        }
        printf("\n\nContinue (Y/N):  ");
        check = getch();
    }
}
