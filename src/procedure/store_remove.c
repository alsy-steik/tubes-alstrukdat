#include <stdio.h>
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/Barang/barang.h"
#include "../../boolean.h"

void store_remove(ArrayDin *arr) {
    printf("Nama barang yang akan dihapus: ");
    startKataMajemuk(NULL); 

    int found = -1; // Indeks barang dalam array
    for (int i = 0; i < getArrayDinLength(*arr); i++) {
        Barang currentBarang = getArrayDinElmt(*arr, i);
        if (BandingString(currentKata, currentBarang.name)) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        ArrayDinDeleteElem(arr, found);
        PrintKata(currentKata);
        printf(" telah berhasil dihapus.\n");
    } else {
        printf("Toko tidak menjual ");
        PrintKata(currentKata);
        printf(".\n");
    }
}