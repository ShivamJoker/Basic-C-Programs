#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

int todosLength = 0;
FILE *fp;

struct Todo
{
    char title[50];
    _Bool completed;

} todos[20];

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

void addTodo()
{
    char input[50];
    printf("Please type your todo \n");
    scanf("%[^\n]s", input);
    // fgets(input, sizeof(input), stdin);           //read the string from user
    strncpy(todos[todosLength].title, input, 50); // copy it to todos array
    todosLength++;                                // increment after every addition
    // whenever we will add a todo we will save it into the file
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
        printf("Sorry we are not able to find the todos \n");
    }
    else
    {
        getFileSize();
        for (int i = 0; i < todosLength; i++)
        {
            fread(&todos[i], sizeof(struct Todo), 1, fp);
        }
        fclose(fp);
    }
}

void deleteTodo()
{
    int location;
    printf("Enter the todo Id => ");
    scanf("%d", &location);
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

void printAllTodo()
{
    // print all the todos

    printf("+----+-------------------------------------------+-----------+ \n");
    printf("| ID |\t\t    Your Todos       \t\t | Completed |\n");
    printf("+----+-------------------------------------------+-----------+ \n");

    for (int i = 0; i < todosLength; i++)
    {

        // we will add one to to i because counting starts from 1
        // if its true we will print yes else no
        if (todos[i].completed)
        {
            printf("\033[0m");
            printf("\033[32;3m");
            printf("|%3d |  %-40s |  ✅   Yes  |\n", i + 1, todos[i].title);
        }
        else
        {
            printf("\033[0m");
            printf("\033[32;1m");
            printf("|%3d |  %-40s |  ❌   No   |\n", i + 1, todos[i].title);

        }
       printf("\033[0m");
        printf("\033[32;1m");
        printf("+----+-------------------------------------------+-----------+ \n");
    }
}

void markAsComplete()
{
    int todoId;
    printf("Enter the Todo id => ");
    scanf("%d", &todoId);
    // we will decrease one because the index starts from 0
    todoId--;
    // make the bool to true
    todos[todoId].completed = true;
}

// this function will show the actions which can be done on our todo app
void showOptions()
{
    printf("Type 'A' to add, 'M' to mark as complete and 'D' to delete a todo \nQ to exit from app \n>> ");
    char option;
    option = getchar();
    // we will again do a getchar to remove line break
    getchar();
    option = tolower(option);

    // we are going to use the switch condition
    switch (option)
    {
    case 'a':
        addTodo();
        break;

    case 'm':
        markAsComplete();
        break;

    case 'd':
        deleteTodo();
        break;

    case 'q':
        exit(0);
        break;

    default:
        printf("Invalid command \n");
        break;
    }

    saveToFile();
    printAllTodo();
    // this will remove any new line from previous options
    getchar();

    showOptions();
}

void isThisFirstLogin()
{
    if (access("todos", F_OK) != -1)
    {
        // file exists so we will read from it
        readFromFile();
        // now print the the todos
        printAllTodo();
        // show option menu now
        showOptions();
    }
    else
    {
        printf("Welcome to the Todo app \n");
        // file doesn't exist
        addTodo();
        saveToFile();
        printAllTodo();
        showOptions();
    }
}

int main()
{
    // change the color
    printf("\033[32;1m");

    isThisFirstLogin();

    // printf("Todo Name 💩 %s \n", todos[4].title);
    // if (todos[2].title[0] == '\0')
    // {
    //     printf("You dont exist \n");
    // }
}