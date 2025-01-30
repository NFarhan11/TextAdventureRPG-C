#include <stdio.h>
#include <string.h>
#include "object.h"

// array of objects
object objects[] = {
    {"dagger", "A sharp dagger", &locations[0]},
    {"sword", "A shining sword", &locations[0]},
    {"shield", "A sturdy shield", &locations[2]},
    {"potion", "A glowing potion", &locations[3]},
};

// object count
const int object_count = sizeof(objects) / sizeof(objects[0]);