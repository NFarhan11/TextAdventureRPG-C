#ifndef INVENTORY_H
#define INVENTORY_H

#include "object.h"

#define MAX_OBJECTS 10 // max inventory size

typedef struct inventory
{
    object *items[MAX_OBJECTS];
    int object_count;
} inventory;

// inventory functions
void toInventory(inventory *inv, object *item);
void checkInventory(inventory *inv);
void dropFromInventory(inventory *inv, object *item);

#endif