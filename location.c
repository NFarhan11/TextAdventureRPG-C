#include <stdio.h>
#include <string.h>
#include "location.h"

typedef struct location
{
    const char *description;
    const char *tag;
} location;

// array of locations
location locations[] = {
    {"You are in a dark room.", "room"},
    {"You are in a cave.", "cave"},
    {"You are in a field.", "field"},
    {"You are in a hall.", "hall"},
};

void toLook(char *noun)
{
    if (noun != NULL)
    {
        printf("You look at the %s.\n", noun);
    }
    else
    {
        printf("You look around and see many things.\n");
    }
}

void toGo(char *noun)
{
    // if noun is not NULL
    if (noun != NULL)
    {
        // the noun is in locations
        for (int i = 0; i < sizeof(locations) / sizeof(locations[0]); i++)
        {
            if (strcmp(noun, locations[i].tag) == 0)
            {
                printf("%s\n", locations[i].description);
                return;
            }
        }
        // if noun is not NULL but not in locations
        printf("You can't go to the %s. \n", noun);
    }
    else
    {
        // if noun is NULL
        printf("Go where?\n");
    }
}