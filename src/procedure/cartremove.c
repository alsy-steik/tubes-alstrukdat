#include <stdio.h>
#include "setmap.h"
#include "MesinKata.h"

void cartRemove(Map *keranjang) {
    startKata(NULL); // membaca kata pertama ("CART")
    advKata();       // kata kedua ("REMOVE")
    advKata();       // nama barang
    char namaBarang[100];
    strcpyHomemade(namaBarang, currentKata.buffer);

    advKata(); // jumlah barang
    int jumlahBarang = atoi(currentKata.buffer);

    if (MapContains(*keranjang, namaBarang)) {
        int jumlahakhir = MapGetEl(*keranjang, namaBarang);
        if (jumlahBarang <= jumlahakhir) {
            // kurangi jumlah barang
            MapInsert(keranjang, namaBarang, jumlahakhir - jumlahBarang);

            // hapus barang jika jumlahnya menjadi 0
            if (MapGetEl(*keranjang, namaBarang) == 0) {
                MapRemove(keranjang, namaBarang);
            }

            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n", jumlahBarang, namaBarang);
        } else {
            // jumlah barang di cart lebih sedikit dari yang diminta
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", jumlahakhir, namaBarang);
        }
    } else {
        printf("Barang tidak ada di keranjang belanja!\n");
    }
    printf("// Kembali ke menu utama\n");
}

int main() {
    Map keranjang;
    MapCreateEmpty(&keranjang);
    MapInsert(&keranjang, "AK47", 10);

    printf("Masukkan perintah (contoh: CART REMOVE AK47 10):\n");
    cartRemove(&keranjang);

    return 0;
}
