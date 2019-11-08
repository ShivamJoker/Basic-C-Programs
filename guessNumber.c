#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
    srand(time(NULL));
    int randomNum = 1 + rand() % (10);
    int userInput;
    int isFinished = 0;
    printf("Welcome to random number guessing game 🥳\n");
    printf("Please guess a number between 1 - 10 \n");
    scanf("%d", &userInput);
    while (isFinished == 0)
    {

        if (userInput > randomNum)
        {
            printf("Your number is high 🙀\n");
            scanf("%d", &userInput);
        }
        else if (userInput < randomNum)
        {
            printf("Your number is low 😫\n");
            scanf("%d", &userInput);
        }
        else
        {
            printf("Your guessed it correct 👏\n");
            printf("The number was %d  🎉\n", randomNum);
            printf("Do you want to play again? (y/n) \n");
            char playAgain;
            scanf(" %c", &playAgain);
            if (playAgain == 'y')
            {
                randomNum = 1 + rand() % 10;
                /* n */
                printf("Please guess 👀  a number between 1 - 10 \n");
                scanf("%d", &userInput);
            }
            else
            {
                printf("Bye Bye! Thanks for playing 🖐\n");
                isFinished = 1;
                //end the game
            }
        }
    }
}