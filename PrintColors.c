#include <stdio.h>
int main()
{
    printf("\n  --------------------------- \n");
    for (int i = 30; i < 38; i++)
    {
        printf("\033[0m");
        printf("\033[30;%dm Background %d ", i+10, i+10);
        printf("\033[30;%dm Bright BG %d ", i + 70, i + 70);
        printf("\033[0m");
        printf("\n");
        // printf("\n  --------------------------- \n");
    }
        printf("\n");

}