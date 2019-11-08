#include <stdio.h>
int main()
{
    // const char name[50];
    // printf("Type your name - ");
    // fgets(name, sizeof(name), stdin);  // read string
    // printf("Name: ");
    // puts(name);    // display string

    char name1[] = "Shiva";
    char name2[] = "Shivam";
    int result = strcmp(name1, name2);
    printf("%d \n", result);

}