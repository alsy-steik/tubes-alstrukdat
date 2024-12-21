#include <stdio.h>
#include <string.h>
#include "../util/util.h"
#include "../adt/SetMap/setmap.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/Barang/barang.h"

void cartShow(Map *cart, Map store) {
    printf("Masukkan perintah: ");
    startKataMajemuk(NULL); 

    if (is_same_string(currentKata.buffer, "CART")) {
        advKata();
        if (is_same_string(currentKata.buffer, "SHOW")) {
            advKata(); 

            if (MapSize(*cart) == 0) {
                printf("Keranjang kamu kosong!\n");
            } else {
                printf("Berikut adalah isi keranjangmu.\n");
                printf("Kuantitas  Nama    Total\n");

                int total_biaya = 0;

                // print isi keranjang
                for (int i = 0; i < MapSize(*cart); i++) {
                    char nama_barang[100];
                    int quantity;
                    MapGet(*cart, i, nama_barang, &quantity);

                    int harga_barang = MapGetValue(store, nama_barang);
                    int total = quantity * harga_barang;

                    total_biaya += total;
                    printf("%d          %s    %d\n", quantity, nama_barang, total);
                }

                printf("Total biaya yang harus dikeluarkan adalah %d.\n", total_biaya);
            }
        } else {
            printf("Perintah invalid; kembali ke menu utama.\n");
        }
    } else {
        printf("Perintah invalid; kembali ke menu utama.\n");
    }
}
