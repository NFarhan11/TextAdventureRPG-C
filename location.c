#include <stdio.h>
#include <string.h>
#include "location.h"
#include "object.h"
#include "inventory.h"
#include "unit.h"

// array of locations
location locations[] = {
    {"inventory", "void space.", {NULL}, 0},  // [0] not physical location
    {"room", "a dark room.", {NULL}, 0},      // [1]
    {"hall", "a majestic hall.", {NULL}, 0},  // [2]
    {"field", "a vast field.", {NULL}, 0},    // [3]
    {"forest", "a dense forest.", {NULL}, 0}, // [4]
    {"cave", "a deep cave.", {NULL}, 0},      // [5]
};

// Establish 2-way connection for 2 locations
void connectLocations(location *loc1, location *loc2)
{
    loc1->connection[loc1->connection_count++] = loc2;
    loc2->connection[loc2->connection_count++] = loc1;
}

// Initialize map
void initializeMap()
{
    connectLocations(&locations[1], &locations[2]); // room <-> hall
    connectLocations(&locations[2], &locations[3]); // hall <-> field
    connectLocations(&locations[3], &locations[4]); // field <-> forest
    connectLocations(&locations[4], &locations[5]); // forest <-> cave
}

void toLook(char *noun) // default: "look around"
{
    // noun
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("\nYou are currently in %s\n", player->current_location->description);
        printf("\nYou see: \n");
        // Print "object"
        for (int i = 0; i < object_count; i++)
        {
            if (objects[i].current_location == player->current_location)
            {
                printf("%s.\n", objects[i].description);
            }
        }
        // Print "passage"
        printf("\nPassage: \n");
        for (int i = 0; i < player->current_location->connection_count; i++)
        {
            printf("%s\n", player->current_location->connection[i]->tag);
        }
    }
    else
    {
        printf("\nLook what?\n");
    }
}

void toGo(char *noun)
{
    // if noun is not NULL
    if (noun != NULL)
    {
        for (int i = 0; i < player->current_location->connection_count; i++)
        {
            if (strcmp(noun, player->current_location->connection[i]->tag) == 0)
            {
                player->current_location = player->current_location->connection[i];
                return toLook("around");
            }
        }
        // if noun is not NULL but not in locations
        printf("\nYou can't go to the %s from here.\n", noun);
    }
    else
    {
        // if noun is NULL
        printf("\nGo where?\n");
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
        printf("\nThere is no %s here.\n", noun);
    }
    else
    {
        // if noun is NULL
        printf("\nPick what?\n");
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
                printf("\nThere are no %s in your inventory\n", noun);
            }
        }
    }
    else
    {
        printf("\nDrop what?\n");
    }
}