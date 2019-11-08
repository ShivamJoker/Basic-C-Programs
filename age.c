#include <stdio.h>

int main()
{
    int year;
    printf("Which year you were born ? \n");
    scanf("%d", &year);
    int age = 2019 - year;
    printf("You are %d years old \n", age);
}