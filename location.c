#include <stdio.h>
#include <string.h>
#include "location.h"
#include "object.h"
#include "inventory.h"
#include "unit.h"

// array of locations
location locations[] = {
    {"inventory", "void space."}, // can refer to any unit inventory
    {"room", "a dark room."},
    {"forest", "a dense forest."},
    {"cave", "a deep cave."},
    {"field", "a vast field."},
    {"hall", "a majestic hall."},
};

void toLook(char *noun) // default: "look around"
{
    // noun
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are currently in %s\n", player->current_location->description);
        printf("You see: \n");
        // if there are objects is in location, print "object."
        for (int i = 0; i < object_count; i++)
        {
            if (objects[i].current_location == player->current_location)
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
                player->current_location = &locations[i];
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
        // the noun is an object & at current location
        for (int i = 0; i < object_count; i++)
        {
            if (strcmp(noun, objects[i].tag) == 0 && objects[i].current_location == player->current_location)
            {
                // change the current location of the object to player inventory
                toInventory(&player->inv, &objects[i]);
                return;
            }
        }
        // if noun is not NULL but not in locations
        printf("There is no %s here.\n", noun);
    }
    else
    {
        // if noun is NULL
        printf("Pick what?\n");
    }
}

void toDrop(char *noun)
{
    if (noun != NULL)
    {
        // noun is an object and in player inventory
        for (int i = 0; i < player->inv.object_count; i++)
        {
            if (strcmp(noun, player->inv.items[i]->tag) == 0)
            {
                // change current location of the object to current location of player
                dropFromInventory(&player->inv, player->inv.items[i]);
                return;
            }
            else
            {
                // object not in inventory
                printf("There are no %s in your inventory\n", noun);
            }
        }
    }
    else
    {
        printf("Drop what?\n");
    }
}