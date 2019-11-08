#include <stdio.h>
#include <string.h>
int main()
{
    char s[10];
    int i;
    printf("Enter a string: ");
    // scanf("%s", s);
    fgets(s, sizeof(s), stdin);
    // i = strlen(s);
    printf("Length of string: ");

    for (i = 0; s[i] != '\n'; ++i)
    {
        // printf("%c", s[i]);
        // printf("%d", s[i]);
            printf("%d", i);
    }
}