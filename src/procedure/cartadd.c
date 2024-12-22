#include <stdio.h>
#include <string.h>
#include "../util/util.h"
#include "../adt/SetMap/setmap.h"
#include "../adt/ArrayDin/ArrayDin.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/Barang/barang.h"

void cartAdd(Map *cart, ArrayDin *arr) {
    printf("Masukkan perintah CART ADD: ");
    startKata(NULL); 

    if (is_same_string(currentKata.buffer, "CART")) {
        advKata();
        if (is_same_string(currentKata.buffer, "ADD")) {
            advKata(); 

            char nama_barang[100];
            strcpyHomemade(nama_barang, currentKata.buffer);

            advKata(); 

            int quantity = atoi(currentKata.buffer); 

            // Pencarian barang di toko
            int found = -1; // Indeks barang dalam array
            for (int i = 0; i < getArrayDinLength(*arr); i++) {
                Barang currentBarang = getArrayDinElmt(*arr, i);
                if (is_same_string(nama_barang, currentBarang.name)) {
                    found = i;
                    break;
                }
            }

            if (found != -1) {
                if (MapContains(*cart, nama_barang)) {
                    int current_quantity = MapGetEl(*cart, nama_barang);
                    MapInsert(cart, nama_barang, current_quantity + quantity);
                    printf("Jumlah barang %s di keranjang bertambah menjadi %d.\n", nama_barang, current_quantity + quantity);
                } else {
                    MapInsert(cart, nama_barang, quantity);
                    printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", quantity, nama_barang);
                }
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