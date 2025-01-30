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
        // QUIT
        if (strcmp(verb, "quit") == 0)
        {
            return false;
        }
        // LOOK
        else if (strcmp(verb, "look") == 0)
        {
            // look around -> look at the objects in the current location
            toLook(noun);
        }
        // GO
        else if (strcmp(verb, "go") == 0)
        {
            // go to the location(noun)
            toGo(noun);
        }
        // PICK
        else if (strcmp(verb, "pick") == 0)
        {
            // pick up the object(noun) in the current location
            toPick(noun);
        }
        // USE
        else if (strcmp(verb, "use") == 0)
        {
            // use the object(noun)
            printf("You use a %s.\n", noun);
        }
        // UNKNOWN
        else
        {
            printf("I don't know how to '%s'.\n", verb);
        }
    }

    return true;
}