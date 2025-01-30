#include <stdio.h>
#include <string.h>
#include "location.h"
#include "object.h"

// array of locations
location locations[] = {
    {"room", "a dark room."},
    {"forest", "a dense forest."},
    {"cave", "a deep cave."},
    {"field", "a vast field."},
    {"hall", "a majestic hall."},
};

int current_location;

void toLook(char *noun) // default: "look around"
{
    // noun
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You see: \n");
        // if there are objects is in location, print "object."
        for (int i = 0; i < object_count; i++)
        {
            if (objects[i].current_location == &locations[current_location])
            {
                printf("%s.\n", objects[i].description);
            }
        }
    }
    else
    {
        printf("Look what?\n");
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
                printf("You are in %s\n", locations[i].description);
                current_location = i;
                // if there is any object in the current location
                return toLook("around");
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

void toPick(char *noun)
{
    // if noun is not NULL
    if (noun != NULL)
    {
        // the noun is in locations
        for (int i = 0; i < object_count; i++)
        {
            if (strcmp(noun, objects[i].tag) == 0)
            {
                printf("You pick up %s.\n", objects[i].description);
                // change the current location of the object
                objects[i].current_location = &locations[current_location];
                return;
            }
        }
        // if noun is not NULL but not in locations
        printf("You can't pick up the %s. \n", noun);
    }
    else
    {
        // if noun is NULL
        printf("Pick what?\n");
    }
}