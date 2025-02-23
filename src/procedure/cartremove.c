#include <stdio.h>
#include <string.h>
#include "../util/util.h"
#include "../adt/SetMap/setmap.h"
#include "../adt/MesinKata/MesinKata.h"
#include "../adt/MesinKarakter/MesinKarakter.h"
#include "../adt/Barang/barang.h"

void cartRemove(Map *cart, const char* nama_barang, int quantity) {
    if (MapContains(*cart, nama_barang)) {
        int current_quantity = MapGetEl(*cart, nama_barang);

        if (quantity <= current_quantity) {
            int new_quantity = current_quantity - quantity;
            if (new_quantity == 0) {
                MapDelete(cart, nama_barang); // Hapus barang jika kuantitas menjadi 0
                printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, nama_barang);
            } else {
                MapInsert(cart, nama_barang, new_quantity);
                printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", quantity, nama_barang);
            }
        } else {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", current_quantity, nama_barang);
        }
    } else {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
}
