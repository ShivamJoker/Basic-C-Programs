#include <stdio.h>
int main()
{
    float price, dPrice, rate;
    rate = 10;
    printf("Type the price to get a discounted price \n");
    scanf("%f", &price);
    dPrice = price - (rate / 100 * price);
    printf("Your discounted price  %f \n", dPrice);
}