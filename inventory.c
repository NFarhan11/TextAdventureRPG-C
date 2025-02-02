#include <stdio.h>
#include <string.h>
#include "inventory.h"
#include "unit.h"

void toInventory(inventory *inv, object *item)
{
    // if the inventory is not full
    if (inv->object_count < MAX_OBJECTS)
    {
        // add the item to the inventory
        inv->items[inv->object_count] = item;
        inv->object_count++;
        item->current_location = NULL;
        printf("\nYou have picked up %s.\n", item->description);
    }
    else
    {
        printf("\nYour inventory is full.\n");
    }
}

void checkInventory(inventory *inv)
{
    // if the inventory is empty
    if (inv->object_count == 0)
    {
        printf("\nYour inventory is empty.\n");
    }
    else
    {
        printf("\nYour inventory contains:\n");
        for (int i = 0; i < inv->object_count; i++)
        {
            printf("%s\n", inv->items[i]->tag);
        }
    }
}

void dropFromInventory(inventory *inv, object *item)
{
    // find the item in inventory
    for (int i = 0; i < inv->object_count; i++)
    {
        if (inv->items[i] == item)
        {
            // change item location
            item->current_location = player->current_location;

            // MANAGE ARRAY
            for (int j = i; j < inv->object_count - 1; j++)
            {
                inv->items[j] = inv->items[j + 1];
            }
            inv->items[inv->object_count - 1] = NULL;
            inv->object_count--;

            // print drop
            printf("\nYou have dropped %s.\n", item->description);
            return;
        }
    }

    // no item in inventory
    if (inv->object_count == 0)
    {
        printf("\nYour inventory is empty\n");
    }
}