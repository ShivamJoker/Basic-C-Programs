#include <stdio.h>
int *location;

int main()
{
    int value = 12;
    location = &value;
    changeValue();
    printf("Value is %d \n", value);
}

int changeValue()
{
    *location = 69;
}