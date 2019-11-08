#include <stdio.h>

int main()
{
    printf("Type the number of which you want to get multiplication table => ");
    int number;
    scanf("%d", &number);
    for (int i = 1; i <= 10; i++)
    {
        int result = number * i;
        printf("%d x %d = %d \n", number, i, result);
    }
}