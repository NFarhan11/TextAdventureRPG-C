#include <stdio.h>
#include <string.h>
#include "object.h"

// array of objects
object objects[] = {
    {"dagger", "a sharp dagger", &locations[1]},
    {"sword", "a shining sword", &locations[1]},
    {"shield", "a sturdy shield", &locations[2]},
    {"potion", "a glowing potion", &locations[3]},
};

// object count
const int object_count = sizeof(objects) / sizeof(objects[0]);