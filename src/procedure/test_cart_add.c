#include <stdio.h>
#include <string.h>
#include "../util/util.h"
#include "../adt/SetMap/setmap.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/Barang/barang.h"

void cartAdd(Map *cart, Map store) {
    printf("Masukkan perintah: ");
    startKataMajemuk(NULL); 

    if (is_same_string(currentKata.buffer, "CART")) {
        advKata();
        if (is_same_string(currentKata.buffer, "ADD")) {
            advKata(); 

            char nama_barang[100];
            strcpyHomemade(nama_barang, currentKata.buffer);

            advKata(); 

            int quantity = getNum(); 

            if (MapContains(store, nama_barang)) {
                MapInsert(cart, nama_barang, quantity);
                printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, nama_barang);
            } else {
                printf("Barang tidak ada di toko!\n");
            }
        } else {
            printf("Perintah invalid; kembali ke menu utama.\n");
        }
    } else {
        printf("Perintah invalid; kembali ke menu utama.\n");
    }
}

int test_cart() {
    Map keranjang;
    MapCreateEmpty(&keranjang);
    Map store;
    MapCreateEmpty(&store);
    MapInsert(&store, "AK47", 10);

    printf("Masukkan perintah (contoh: CART ADD AK47 10):\n");
    cartAdd(&keranjang, store);

    return 0;
}