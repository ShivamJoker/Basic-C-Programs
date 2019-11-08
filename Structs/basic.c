#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int todosLength = 0;
FILE *fp;

struct Todo
{
    char title[50];
    _Bool completed;

} todos[20];

void AddTodo()
{
    char input[50];
    printf("Please type your todo \n");
    scanf("%[^\n]s", input);
    // fgets(input, sizeof(input), stdin);           //read the string from user
    strncpy(todos[todosLength].title, input, 50); // copy it to todos array
    todosLength++;                                // increment after every addition
}

void saveToFile()
{
    fp = fopen("todos", "w");

    // if file open is not succesful
    if (!fp)
    {
        printf("Sorry Unable to create file to save todos\n");

    }
    else
    {
        for (int i = 0; i < todosLength; i++)
        {
            fwrite(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

void getFileSize()
{
    // fseek will read the file size of structs stored
    fseek(fp, 0L, SEEK_END);
    unsigned int long sz = ftell(fp);
    // go back to first line
    fseek(fp, 0L, SEEK_SET);
    // change the Todo length from 0
    todosLength = sz / sizeof(struct Todo);
}
void readFromFile()
{
    fp = fopen("todos", "r");


    // if file open is not succesful
    if (!fp)
    {
        printf("Sorry there are no Todos saved \n");
    }
    else
    {

        for (int i = 0; i < todosLength; i++)
        {
            fread(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

void deleteTodo(int location)
{
    /* Invalid delete position */
    if (location < 0 || location > todosLength)
    {
        printf("Invalid todo! Please enter select todo between 1 to %d", todosLength);
    }
    else
    {
        /* Copy next element value to current element */
        for (int i = location - 1; i < todosLength - 1; i++)
        {
            todos[i] = todos[i + 1];
        }

        /* Decrement array todosLength by 1 */
        todosLength--;
    }
}
void isThisFirstLogin(){
    if (access("todos", "F_OK") != -1)
    {
        // file exists
    }
    else
    {
        // file doesn't exist
    }
}

int main()
{
    readFromFile();
    // AddTodo();
    // deleteTodo(10);
    saveToFile();
    // print all the todos
    printf("\033[32;1m");

    printf("+----+-------------------------------------------+-----------+ \n");
    printf("| ID |\t\t    Your Todos       \t\t | Completed |\n");
    printf("+----+-------------------------------------------+-----------+ \n");

    for (int i = 0; i < todosLength; i++)
    {

        printf("|%3d |  %-40s | ", i + 1, todos[i].title);
        // we will add one to to i because counting starts from 1
        if (i % 2 == 0)
        {
            // printf("\033[91;1m");
            printf(" ✅   Yes  |\n");
        }
        else
        {
            // printf("\033[36;1m");
            printf(" ❌   No   |\n");
        }
        printf("+----+-------------------------------------------+-----------+ \n");
    }

    // printf("Todo Name 💩 %s \n", todos[4].title);
    // if (todos[2].title[0] == '\0')
    // {
    //     printf("You dont exist \n");
    // }
}