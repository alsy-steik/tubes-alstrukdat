#include "Barang.h"
#include "../../util/util.h"
void setBarangName(Barang* barang, const char* name) {
    int i = 0;
    strcpyHomemade(barang->name, name);
    // while(name[i] != '\0') {
    //     barang->name[i] = name[i];
    //     ++i;
    // }

    // barang->name[i] = '\0';
}

void setBarangPrice(Barang* barang, int price) {
    barang->price = price;
}

Barang createBarang(const char* name, int price) {
    Barang new_barang;
    setBarangName(&new_barang, name);
    setBarangPrice(&new_barang, price);
    return new_barang;
}


