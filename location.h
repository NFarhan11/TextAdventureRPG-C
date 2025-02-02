#ifndef LOCATION_H
#define LOCATION_H

typedef struct location
{
    const char *tag;
    const char *description;
    struct location *connection[10];
    int connection_count;
} location;

// array of locations
extern location locations[];

extern void initializeMap();
extern void toLook(char *noun);
extern void toGo(char *noun);
extern void toPick(char *noun);
extern void toDrop(char *noun);

#endif