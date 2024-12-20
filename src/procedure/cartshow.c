#include <stdio.h>
#include "setmap.h"
#include "MesinKata.h"

void cartShow(Map *keranjang) {
    // cek keranjang kosong
    if (MapSize(*keranjang) == 0) {
        printf("Keranjang kamu kosong!\n");
        return;
    }

    printf("Berikut adalah isi keranjangmu.\n");
    printf("Kuantitas  Nama    Total\n");

    int totalBiaya = 0;
    MapIterator it = MapBegin(*keranjang);
    while (it != MapEnd(*keranjang)) {
        const char *namaBarang = it->key;
        int kuantitas = it->value;
        int hargaBarang = getHargaBarang(namaBarang); 
        int total = hargaBarang * kuantitas;
        totalBiaya += total;

        printf("%-10d %-7s %d\n", kuantitas, namaBarang, total);

        ++it;
    }

    printf("Total biaya yang harus dikeluarkan adalah %d.\n", totalBiaya);
    printf("// Command mati; Kembali ke menu utama\n");
}

int main() {
    Map keranjang;
    MapCreateEmpty(&keranjang);

    MapInsert(&keranjang, "AK47", 2);
    MapInsert(&keranjang, "Lalabu", 1);

    printf("Masukkan perintah (contoh: CART SHOW):\n");
    cartShow(&keranjang);

    return 0;
}
