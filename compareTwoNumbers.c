// in this program we are going to compare two number
// we will use if else if else
#include <stdio.h>

int main()
{
    // define two variables for storing the two numbers
    int num1, num2;
    printf("Enter the two numbers seperated by a space => ");
    // get the input from user
    scanf("%d %d", &num1, &num2);

    if (num1 > num2)
    // if the num1 is greator than num2
    {
        printf("Number 1 is greator than number 2");
    }
    // if both are equal
    else if (num1 == num2)
    {
        printf("Both numbers are equal \n");
    }
    // if none of the condition is met
    else
    {
        printf("Number 2 is greator than number 1 \n");
    }
}