#include <stdio.h>
#include "setmap.h"
#include "MesinKata.h"
#include "util.h"

const char *barangToko[] = {"AK47", "Pistol", "Peluru", "Granat"};
const int jumlahBarangToko = 4;

int barangAda(const char *namaBarang) {
    for (int i = 0; i < jumlahBarangToko; ++i) {
        if (isStringEqual(barangToko[i], namaBarang)) {
            return 1;
        }
    }
    return 0;
}

void cartAdd(Map *keranjang) {
    startKata(NULL); // membaca kata pertama ("CART")
    advKata();       // kata kedua ("ADD")
    advKata();       // nama barang
    char namaBarang[100];
    strcpyHomemade(namaBarang, currentKata.buffer);

    advKata(); // jumlah barang
    int jumlahBarang = atoi(currentKata.buffer);

    if (barangAda(namaBarang)) {
        if (MapContains(*keranjang, namaBarang)) {
            // tambah jumlah barang jika sudah ada
            int jumlahSekarang = MapGetEl(*keranjang, namaBarang);
            MapInsert(keranjang, namaBarang, jumlahSekarang + jumlahBarang);
        } else {
            // input barang baru ke keranjang
            MapInsert(keranjang, namaBarang, jumlahBarang);
        }
        printf("Berhasil menambahkan %d %s ke keranjang belanja!\n", jumlahBarang, namaBarang);
    } else {
        printf("Barang tidak ada di toko!\n");
    }
    printf("// Kembali ke menu utama\n");
}

int main() {
    Map keranjang;
    MapCreateEmpty(&keranjang);

    printf("Masukkan perintah (contoh: CART ADD AK47 20):\n");
    cartAdd(&keranjang);

    return 0;
}
