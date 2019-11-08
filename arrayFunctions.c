#include <stdio.h>
int main()
{

    // binary format
    // 64 32 16 8 4 2 1
    int binary[64];
    int number = 5;
    printf("Type the number to convert it in binary: ");
    scanf("%d", &number);

    int arrayLocation = 0;
    while (number != 0)
    {
        binary[arrayLocation] = number % 2;
        number = number / 2;

        arrayLocation++;
    }
    // we will reverse the array
    for (int i = arrayLocation - 1; i >= 0; i--)
    {
        printf("%d ", binary[i]);
    }
    printf("\n");
}