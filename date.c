#include <time.h>
#include <stdio.h>

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
}