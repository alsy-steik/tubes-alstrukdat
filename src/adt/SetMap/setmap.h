#ifndef SETMAP_H
#define SETMAP_H

#define MAX_SIZE 100

typedef struct
{
    char nama_barang[100]; // key
    int quantity;          // value
} MapElement;

typedef MapElement ElType;

typedef struct map
{
    ElType data[MAX_SIZE];
    int count;
} Map;

void MapCreateEmpty(Map *map);
int MapIsEmpty(Map map);
void MapInsert(Map *map, const char *key, int value);
int MapGetEl(Map map, const char *key);
void MapDelete(Map *map, const char *key);
int MapContains(Map map, const char *key);

#endif
