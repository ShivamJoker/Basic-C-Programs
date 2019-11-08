#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int randomNum = rand() % 5;
    const char *emojies[] = {u8"🙂", u8"😎", u8"🙁", u8"😡", u8"🥰"};
    printf("You are %s\n", emojies[randomNum]);
}