#include <stdio.h>

int main()
{
    int num;
    printf("Type the number to check even or odd \n");
    scanf("%d", &num);
    if(num % 2 == 0){
        printf("It's even \n");
    } else {
        printf("It's odd \n");

    }
    

}