#include <stdio.h>
#include <string.h>
int main()
{
    char *str = "string";
    char **pstr = &str;
    puts(*pstr);
}