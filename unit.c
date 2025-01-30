#include <stdio.h>
#include <string.h>
#include "unit.h"
#include "inventory.h"

// array of units
unit units[] = {
    {"player", "The player", &locations[1], {{}, 0}},
    {"goblin", "a green cunning monster.", &locations[1], {NULL, 0}},
    {"guard", "a bulky guard.", &locations[2], {NULL, 0}},
};

// unit count
const int unit_count = sizeof(units) / sizeof(units[0]);

// player
unit *player = &units[0];