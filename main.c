#include <stdio.h>
#include <stdbool.h>
#include "parsexec.h"

char input[30] = "go forward"; // string buffer

// Horizontal line
void printSeparator()
{
    printf("------------------------------------------------------------------------------------------------------------------------\n");
}

// Get Input
static bool getInput(void)
{
    printf("\n-->");
    return fgets(input, sizeof(input), stdin) != NULL;
}

int main()
{
    printSeparator();
    printf("Welcome to the Garrison Frontier.\n");
    printf("A battle frontier for the adventurer to explore the dungeon.\n");
    printf("You are one of the adventurers that yearn to explore the infamous dungeon.\n");
    printSeparator();

    // Game Loop
    bool run;
    do
    {
        run = parseAndExecute(input); // execute current command
        if (run)
        {
            run = getInput(); // get next input from user
        }
    } while (run);

    printSeparator();
    printf("Bye!\n");

    return 0;
}