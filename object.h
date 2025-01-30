#ifndef OBJECT_H
#define OBJECT_H

#include "location.h"

typedef struct object
{
    const char *tag;
    const char *description;
    location *current_location;
} object;

// array of objects
extern object objects[];

// object count
extern const int object_count;

#endif