#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "parsexec.h"
#include "location.h"

bool parseAndExecute(char *input)
{
    char *verb = strtok(input, " \n");
    char *noun = strtok(NULL, " \n");

    if (verb != NULL)
    {
        if (strcmp(verb, "quit") == 0)
        {
            return false;
        }
        else if (strcmp(verb, "look") == 0)
        {
            toLook(noun);
        }
        else if (strcmp(verb, "go") == 0)
        {
            toGo(noun);
        }
        else if (strcmp(verb, "use") == 0)
        {
            printf("You use the object.\n");
        }
        else
        {
            printf("I don't know how to '%s'.\n", verb);
        }
    }

    return true;
}