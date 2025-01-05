#include <stdio.h>
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"
#include "../boolean.h"
#include "../util/util.h"

void store_remove(ArrayDin *arr) {
    printf("Nama barang yang akan dihapus: ");
    startKataMajemuk(NULL); 

    int found = -1; // Indeks barang dalam array
    for (int i = 0; i < getArrayDinLength(*arr); i++) {
        Barang currentBarang = getArrayDinElmt(*arr, i);
        if (is_same_string(currentKata.buffer, currentBarang.name)) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        ArrayDinDeleteElem(arr, found);
        // PrintKata(currentKata);
        printf("%s telah berhasil dihapus.\n", currentKata.buffer);
    } else {
        printf("Toko tidak menjual %s.\n", currentKata.buffer);
        // PrintKata(currentKata);
        // printf(".\n");
    }
}
