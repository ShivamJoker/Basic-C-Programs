// we will calculate BMI (Body mass index)
// and we will also tell what you need to do
#include <stdio.h>
#include <my_global.h>
int main()
{
    // we will need two variables to store height and weight
    float height, weight, bmi;
    // we need decimal values
    // now we will take input from the user
    printf("What's your weight ? -> \n");
    scanf("%f", &weight);
    printf("What's your height ? -> \n");
    scanf("%f", &height);

    // we divide weight (in kg) by height (in meter)
    bmi = weight / height;
    printf("Your BMI is %f \n", bmi);
}