#include <stdio.h>
#include <string.h>
#include "../util/util.h"
#include "../adt/SetMap/setmap.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/Barang/barang.h"

void cartRemove(Map *cart) {
    printf("Masukkan perintah CART REMOVE: ");
    startKata(NULL); 

    if (is_same_string(currentKata.buffer, "CART")) {
        advKata();
        if (is_same_string(currentKata.buffer, "REMOVE")) {
            advKata(); 

            char nama_barang[100];
            strcpyHomemade(nama_barang, currentKata.buffer);

            advKata(); 

            int quantity = atoi(currentKata.buffer); 

            if (MapContains(*cart, nama_barang)) {
                int current_quantity = MapGetEl(*cart, nama_barang);

                if (quantity <= current_quantity) {
                    MapInsert(cart, nama_barang, current_quantity - quantity);
                    // MapDelete(cart, nama_barang);
                    printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, nama_barang);
                } else {
                    printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", current_quantity, nama_barang);
                }
            } else {
                printf("Barang tidak ada di keranjang belanja!\n");
            }
        } else {
            printf("Perintah invalid; kembali ke menu utama.\n");
        }
    } else {
        printf("Perintah invalid; kembali ke menu utama.\n");
    }
}