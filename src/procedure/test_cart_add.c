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

void cartShow(Map *cart, ArrayDin *arr) {
    printf("Masukkan perintah CART SHOW: ");
    startKata(NULL); 

    if (is_same_string(currentKata.buffer, "CART")) {
        advKata();
        if (is_same_string(currentKata.buffer, "SHOW")) {
            advKata(); 

            if (cart->count == 0) {
                printf("Keranjang kamu kosong!\n");
            } else {
                printf("Berikut adalah isi keranjangmu.\n");
                printf("Kuantitas  Nama    Total\n");

                int total_biaya = 0;

                // print isi keranjang
                for (int i = 0; i < cart->count; i++) {
                    char nama_barang[100];
                    strcpyHomemade(nama_barang, cart->data[i].nama_barang);
                    int quantity = MapGetEl(*cart, nama_barang);

                    // int harga_barang = MapGetEl(store, nama_barang);
                    Barang currentBarang = getArrayDinElmtByName(*arr, nama_barang);
                    int harga_barang = currentBarang.price;
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

int main() {
    Map cart;
    MapCreateEmpty(&cart);

    ArrayDin arr;
    MakeEmptyArrayDin(&arr);

    Barang barang1 = {"Beras", 10000};
    Barang barang2 = {"Gula", 15000};
    Barang barang3 = {"MinyakGoreng", 20000};

    // Menambahkan barang ke dalam ArrayDin
    ArrayDinInsertEnd(&arr, barang1);
    ArrayDinInsertEnd(&arr, barang2);
    ArrayDinInsertEnd(&arr, barang3);

    cartShow(&cart, &arr);

    cartAdd(&cart, &arr);

    cartShow(&cart, &arr);
    
    cartRemove(&cart);

    cartShow(&cart, &arr);

    return 0;
}