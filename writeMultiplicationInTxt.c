#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("tables.txt", "a+");
    printf("Type the number of which you want to get multiplication table => ");
    int number;
    scanf("%d", &number);
    for (int i = 1; i <= 10; i++)
    {
        int result = number * i;
        fprintf(fp, "%d x %d = %d \n", number, i, result);
    }
}