#ifndef UNIT_H
#define UNIT_H

#include "location.h"
#include "inventory.h"

typedef struct unit
{
    const char *tag;
    const char *description;
    location *current_location;
    inventory inv;
} unit;

// array of units
extern unit units[];

// unit count
extern const int unit_count;

// player
extern unit *player;

#endif