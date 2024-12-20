
#include "setmap.h"
#include "../../util/util.h"
#include <stdlib.h>

void MapCreateEmpty(Map *map) {
    map->count = 0;
}

int MapIsEmpty(Map map) {
    return map.count == 0;
}

// `key` = `nama_barang`, `value`=`quantity`
void MapInsert(Map* map,const char* key, int value) {
    for(int i = 0; i < (map->count); ++i) {
        ElType data = (map->data)[i];
        if(isStringEqual(data.nama_barang, key)) {
            (map->data)[i].quantity = value;
            return;
        }
    }

    MapElement new_el;
    new_el.quantity = value;
    strcpyHomemade(new_el.nama_barang, key);
    (map->data)[(map->count)++] = new_el;
}



// `key` = nama barang
int MapGetEl(Map map,const char* key) {
    for(int i = 0; i < map.count; ++i) {
        ElType data = map.data[i];
        if(isStringEqual(data.nama_barang, key)) return data.quantity;
    }

    return -1;
}

void MapDelete(Map* map, const char* key) {
    for(int i = 0; i < (map->count); ++i) {
        ElType data = (map->data)[i];
        if(isStringEqual(data.nama_barang, key)) { 
            --(map->count);
            for(int j = i; j < (map->count); ++j) {
                (map->data)[j].quantity = (map->data)[j + 1].quantity;
                strcpyHomemade((map->data)[j].nama_barang, (map->data)[j+1].nama_barang);
            }
        }
    }
}

int MapContains(Map map, const char* key) {
    int res = MapGetEl(map, key);
    return res != -1;
}


